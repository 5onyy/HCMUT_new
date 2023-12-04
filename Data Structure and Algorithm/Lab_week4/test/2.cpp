template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    T* lo = start;  
    T* hi = end;
    for (; start < end - 1; start++){
        T* low_index = start;
        for (T* j = end - 1; j > start; j--){
            if (*j <= *low_index)    low_index = j;
        }
        swap(*start, *low_index);
        printArray(lo, hi);
    }      
}