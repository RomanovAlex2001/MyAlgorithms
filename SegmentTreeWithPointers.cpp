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
