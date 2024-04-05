template<class T>
void Heap<T>::ensureCapacity(int minCapacity) {
    if (minCapacity > capacity) {
        int newCapacity = max(2 * capacity, minCapacity);
        T* newElements = new T[newCapacity];
        copy(elements, elements + count, newElements);
        delete[] elements;
        elements = newElements;
        capacity = newCapacity;
    }
}

template<class T>
void Heap<T>::reheapUp(int position) {
    int parent = (position - 1) / 2;
    while (position > 0 && elements[position] > elements[parent]) {
        swap(elements[position], elements[parent]);
        position = parent;
        parent = (position - 1) / 2;
    }
}

template<class T>
void Heap<T>::push(T item) {
    ensureCapacity(count + 1);
    elements[count] = item;
    count++;
    reheapUp(count - 1);
}
