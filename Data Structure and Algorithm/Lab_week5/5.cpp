template<class T>
int Heap<T>::size(){
    return count;
}

template<class T>
bool Heap<T>::isEmpty(){
    return count == 0;
}

template<class T>
T Heap<T>::peek(){
    return elements[0];
}

template<class T>
bool Heap<T>::contains(T item){
    for (int i = 0; i < count; i++) if (elements[i] == item)    return 1;
    return 0;
}

template<class T>
bool Heap<T>::pop(){
    if (count == 0) return 0;
     swap(elements[0], elements[count - 1]);
    count--;
        reheapDown(0);

    return 1;
}