//=======Includes=======||
#include <iostream>     //
#include <cmath>        //
#include <cstdio>       //
#include <cstring>      //
#include <utility>      //
#include <cstdlib>      //
#include <cassert>      //
#include <ctime>        //
#include <sstream>      //
#include <algorithm>    //
#include <functional>   //
#include <numeric>      //
#include <string>       //
#include <vector>       //
#include <queue>        //
#include <stack>        //
#include <map>          //
#include <set>          //
#include <iomanip>      //
//======================||

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define fastio() ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);srand(time(NULL));
#define ll long long
#define ld long double

const int INF=1e9+7;

struct node
{
    int maxi;
    int left,right;
    node *LeftSon,*RightSon;
};

node* build(vector<int> &A,int left,int right)
{
    if (left>right)
    {
        return nullptr;
    }
    node* tree=new node;
    tree->right=right;
    tree->left=left;
    if (left==right)
    {
        tree->LeftSon=nullptr;
        tree->RightSon=nullptr;
        tree->maxi=A[left];
    }
    else
    {
        int mid=(left+right)/2;
        tree->LeftSon=build(A,left,mid);
        tree->RightSon=build(A,mid+1,right);
        tree->maxi=max(tree->LeftSon->maxi,tree->RightSon->maxi);
    }
    return tree;
}

int query(node* root,int left,int right)
{
    if (left>right)
    {
        return -INF;
    }
    if (root->left>=left && root->right<=right)
    {
        return root->maxi;
    }
    int mid=(root->left+root->right)/2;
    return max(query(root->LeftSon,left,min(right,mid)),query(root->RightSon,max(left,mid+1),right));
}

int main()
{
    setlocale(LC_ALL, "Russian");
    fastio();
    int n;
    cin>>n;
    vector<int> A(n);
    for (int i=0;i<n;i++)
    {
        cin>>A[i];
    }
	node * root = build(A, 0, n - 1);
    cout<<"Введите количество запросов"<<endl;
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int l, r;
		cin >> l >> r;
		l--; r--;
		cout << query(root, l, r) << endl;
	}
    return 0;
}
