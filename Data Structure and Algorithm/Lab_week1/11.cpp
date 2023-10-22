template<class T>
void ArrayList<T>::ensureCapacity(int cap){
    /* 
        if cap == capacity: 
            new_capacity = capacity * 1.5;
            create new array with new_capacity
        else: do nothing
    */
    if (cap == capacity){
        size_t new_cap = capacity*1.5;
        T* newArr = new T[new_cap];
        for (int i=0;i<capacity;i++)    newArr[i] = data[i]; 
        capacity = new_cap;
        delete [] data;
        data = newArr;
    }
}

template <class T>
void ArrayList<T>::add(T e) {
    /* Insert an element into the end of the array. */
    if (count == capacity)  ensureCapacity(count);
    data[count] = e;
    count++;
}

template<class T>
void ArrayList<T>::add(int index, T e) {
    /* 
        Insert an element into the array at given index.
        if index is invalid:
            throw std::out_of_range("the input index is out of range!");
    */ 
    if (!(index>=0 && index<=capacity)) throw std::out_of_range("the input index is out of range!");
    if (count == capacity)  ensureCapacity(count);
    for (int i=count;i>index;i--)   data[i] = data[i-1];
    data[index] = e;
    count++;
    return;
}

template<class T>
int ArrayList<T>::size() {
    /* Return the length (size) of the array */ 
    return count;
    return 0;
}
