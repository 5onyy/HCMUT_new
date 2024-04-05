ptr inputList() {
    ptr head=nullptr;
    ptr tail=nullptr;
    int x;
    while (cin>>x){
        if (x < 0)  {
            /*(head==NULL) return head;
            ptr tmp=head;
            head=head->next;
            delete tmp;*/
            break;
        }
        else{
            if (head==NULL) head=new Item({x,NULL}), tail=head;
            else {
                tail -> next = new Item({x,NULL});
                tail=tail->next;
            }
        }
    }
    ptr ans=nullptr;
    ptr itr=head;
    while(itr!=nullptr)
    {
        ptr fwd=itr->next;
        itr->next=ans;
        ans=itr;
        itr=fwd;
    }
    return ans;
}