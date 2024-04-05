static void merge(T* left, T* middle, T* right){
        int n1 = middle - left + 1;
        int n2 = right - middle;

        // Create temporary arrays
        T* L = new T[n1];
        T* R = new T[n2];

        // Copy data to temporary arrays L[] and R[]
        for (int i = 0; i < n1; i++)
            L[i] = left[i];
        for (int j = 0; j < n2; j++)
            R[j] = *(middle + 1 + j);

        // Merge the temporary arrays back into arr[left..right]
        int i = 0;
        int j = 0;
        int k = 0;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                left[k] = L[i];
                i++;
            } else {
                left[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of L[], if there are any
        while (i < n1) {
            left[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[], if there are any
        while (j < n2) {
            left[k] = R[j];
            j++;
            k++;
        }

        // Free the temporary arrays
        delete[] L;
        delete[] R;
        printArray(left,right);
    }
static void mergeSort(T* start, T* end){
    /*TODO*/
    if (start == end)   return;
    T* mid = start + (end - start) / 2;
    mergeSort(start,mid);
    mergeSort(mid + 1, end);
    merge(start,mid,end);
}