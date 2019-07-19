void insertionsort(vector<int> &A) {
    int n = A.size();
    for (int i = 1; i < n; ++i) {
        int now = A[i];
        int j = i - 1;
        while (j >= 0 && now < A[j]) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = now;
    }
}
