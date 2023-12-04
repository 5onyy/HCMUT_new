static void heapify(T arr[], int n, int i) {
    int largest = i;        
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2; 
    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;
    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;
    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

static void heapSort(T *start, T *end) {
    int n = end - start;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(start, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(start[0], start[i]);
        heapify(start, i, 0);
    }
    Sorting<T>::printArray(start,end);
}