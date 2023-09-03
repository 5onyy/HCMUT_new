void normalizePolynomial(ptr& first) {
    //ptr tail = first;
    for (ptr itr=first; itr!=nullptr; itr=itr->next){
        ptr prev=itr;
        for (ptr itr2=itr->next;itr2!=NULL; itr2=itr2->next){
            if (itr==itr2)  continue;
            if (itr->exp == itr2->exp){
                prev->next=itr2->next;
                itr->coef += itr2->coef;
                delete itr2;
            }
            prev=itr2;
        }
    }
    ptr head=nullptr;
    ptr tail=nullptr;
    for (ptr itr=first; itr !=NULL;itr=itr->next){
        if (itr->coef == 0) continue;
        if (head==nullptr)   {head=new Item({itr->coef,itr->exp,NULL}); tail=head;}
        else {
        tail->next= new Item({itr->coef,itr->exp,NULL});
        tail=tail->next;}
    }
    first = head;
    return;
 }