template<class T>
T ArrayList<T>::removeAt(int index){
    /*
    Remove element at index and return removed value 
    if index is invalid:
        throw std::out_of_range("index is out of range");
    */
    T x = data[index];
    for (int i=index;i<count;i++)   data[i] = data[i+1];
    count--;
    return x;
}

template<class T>
bool ArrayList<T>::removeItem(T item){
     /* Remove the first apperance of item in array and return true, otherwise return false */
    for (int i=0;i<count;i++){
        if (data[i] == item){
            for (int j=i;j<count;j++)   data[j] = data[j+1];
            count--;
            return 1;
        }
    }
    return 0;
}

template<class T>
void ArrayList<T>::clear(){
    /* 
        Delete array if array is not NULL
        Create new array with: size = 0, capacity = 5
    */
    delete [] data;
    count = 0;   capacity = 5;
}
