int findMax(int* arr, int length)
{
    if (length==1)  return arr[0];
    return max(arr[length-1],findMax(arr,length-1));
}