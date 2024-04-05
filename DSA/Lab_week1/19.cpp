template <class T>
T SLinkedList<T>::removeAt(int index)
{
    if (index == 0){
        Node *tmp = head;
        T x = head->data;
        head = head -> next;    delete tmp;
        count--;
        return x;
    }
    Node *cur = head;
    for (int i=1;i<index;i++) {cur = cur -> next;}
    if (index == count-1) tail = cur;
    Node *tmp = cur->next;
    T x = tmp->data;
    cur -> next = cur -> next -> next;
    delete tmp;
    count--;
    return x;
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    if (head->data == item) {Node* tmp = head; head = head->next; count--;  delete tmp; return 1;}
    Node *cur = head;
    while (cur->next!=NULL){
        if (cur->next->data == item){
            if (cur->next == tail)  tail = cur;
            Node *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
            count--;
            return 1;
        }
        cur = cur -> next;
    }
    return 0;
}

template<class T>
void SLinkedList<T>::clear(){
    Node *tmp = head;
    while (tmp!=NULL){
        Node *del = tmp;
        tmp=tmp->next;
        delete del;
    }
    count = 0;
    head = tail = NULL;
    return;
}

