ptr inputPolynomial() {
    ptr head=nullptr;
    ptr tail=nullptr;
    double x;
    int y;
    while (cin>>x >> y){
        if (x==0)   break;
        else{
            if (head==NULL) head=new Item({x,y,NULL}), tail=head;
            else {
                tail -> next = new Item({x,y,NULL});
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