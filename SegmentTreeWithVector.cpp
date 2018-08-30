const int INF = 1e9 + 7;
const int maxn = 1e5;
int tree[4 * maxn];

void build(vector<int> &A, int tree_left, int tree_right, int root)
{
	if (tree_left == tree_right)
	{
		tree[root] = A[tree_left];
	}
	else
	{
		int mid = (tree_left + tree_right) / 2;
		build(A, tree_left, mid, root * 2);
		build(A, mid + 1, tree_right, root * 2 + 1);
		tree[root] = max(tree[2 * root], tree[2 * root + 1]);
	}
}

int query_max(int root, int tree_left, int tree_right, int left, int right)
{
	if (left > right)
	{
		return -INF;
	}
	if (left == tree_left && right == tree_right)
	{
		return tree[root];
	}
	int mid = (tree_left + tree_right) / 2;
	int one = query_max(root * 2, tree_left, mid, left, min(right, mid));
	int two = query_max(root * 2 + 1, mid + 1, tree_right, max(left, mid + 1), right);
	return max(one, two);
}
