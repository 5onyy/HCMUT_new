template<class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    for(int i = 0; i < count; i++){
        if (elements[i] == item){
            return i;
        }
    }
    return -1;
}

template<class T>code 
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    int index = getItem(item);
    
    if (index == -1){
        return;
    }
    
    swap(elements[index], elements[count - 1]);
    
    count--;
    
    if (index > 0 && elements[index] > elements[(index -1) / 2]){
        reheapUp(index);
    } else {
        reheapDown(index);
    }
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    //    then reallocate memory as initial state
    delete[] elements;
    
    this->capacity = 10;
    this->count = 0;
    this->elements = new T[capacity];
}