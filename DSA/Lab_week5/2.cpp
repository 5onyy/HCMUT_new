int interpolationSearch(int arr[], int lo, int hi, int x)
{
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        int pos = lo
              + (((double)(hi - lo) / (arr[hi] - arr[lo]))
                 * (x - arr[lo]));
        cout << "We traverse on index: " << pos << endl;
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, hi, x);
        if (arr[pos] > x)
            return interpolationSearch(arr, lo, pos - 1, x);
    }
    return -1;
}