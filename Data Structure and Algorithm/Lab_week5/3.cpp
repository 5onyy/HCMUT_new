int jumpSearch(int arr[], int k, int n) {
    int i, j = sqrt(n);
    for (i = 0; i <= n; i+=j) {cout<<i<<' '; if (i == n)    break;    if (arr[i] >= k)    break;}
    if (i < n && arr[i] == k)    return i;
    int ii = i;
    i -= j - 1;
    if (i < 0)  return 0;
    for (; i <= min (n,ii) ; i++)  {
        if (i == ii)    break;
        cout<<i<<" ";
        if (i == n) break;
        if (arr[i] == k)    return i;
        if (arr[i] > k) break;
    }
    return -1;
}
