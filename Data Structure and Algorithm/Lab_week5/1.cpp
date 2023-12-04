int binarySearch(int arr[], int left, int right, int x)
{
    //if (left == right && arr[left] != x)    return -1;
    if (left > right)   return -1;
    int mid = (right + left) / 2;
    cout << "We traverse on index: " << mid << endl;
    if (arr[mid] == x)      return mid;
    if (arr[mid] < x)       return binarySearch(arr, mid + 1, right, x);
    else return binarySearch(arr,left, mid - 1, x);
}