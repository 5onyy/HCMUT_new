template <class T>
class Sorting {
private:
    
    
static T* Partition(T* start, T* end) {
    // The 'end' pointer points one past the last element, so we adjust for that
    T* left = start;
    T* right = end ;

    T pivot = *left; // Using the first element as the pivot
    int count=0;

    for (size_t i = left; i <= right; i++)
    {
      if (arr[i]<=pivot)
      {
        count++;
      }
      int pivotIndex = start + count;
      swap(arr[pivotIndex],arr[start])
      int i =start, j=end;
      while (i<pivotIndex&& j>pivotIndex)
      {
        while (arr[i]<=pivot)
        {
          i++
        }
        while (arr[j]>pivot
        )
        {
          j--;
        }
        if (i<pivotIndex&&j > pivotIndex)
        {
          swap(arr[i++],arr[j--])
        }
        
        
      }
      return pivotIndex;
      
    }
    
    
    return right; // According to the provided pseudocode, 'j' (equivalent to 'right' here) is returned
}
public:
    static void QuickSort(T* start, T* end) ;
};
