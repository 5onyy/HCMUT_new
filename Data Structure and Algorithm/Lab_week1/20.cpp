template<class T>
T SLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    if (index >= count) return 0;
    Node *cur = head;
    for (int i=0;i<index;i++)   cur = cur->next;
    return cur->data;
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    Node * cur = head;
    if (index > count)  return;
    for (int i=0;i<index;i++)   cur = cur->next;
    cur->data = e;
    return;
}

template<class T>
bool SLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return (count == 0);
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    int idx = 0;
    Node *tmp = head;
    for (;idx<count && tmp->data!=item && tmp!=NULL;idx++,tmp=tmp->next);
    if (idx == count)   return -1;
    return idx;
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    Node * cur = head;
    while (cur!=NULL){
        if (cur->data == item)  return 1;
        cur = cur -> next;
    }
    return 0;
}