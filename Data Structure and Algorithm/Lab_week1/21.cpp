
LLNode* addLinkedList(LLNode* l0, LLNode* l1) {
    LLNode* ans = NULL;
    LLNode* head = NULL;
    LLNode* cur1= l0;
    LLNode* cur2= l1;
    int carry = 0;
    int res = 0;
    while (cur1!=NULL && cur2!=NULL){
        res = (cur1->val + cur2->val + carry);
        carry = res / 10;
        res%=10;
        if (head == NULL)    {head = ans = new LLNode(res,NULL);}
        else        ans->next = new LLNode(res,NULL), ans = ans->next;
        //cout<<ans->val<<' ';
        cur1=cur1->next;    cur2=cur2->next;
    }
    while (cur1!=NULL){
        res = (cur1->val + carry);
        carry = res/10;
        res%=10;
        ans->next = new LLNode(res,NULL);
        cur1=cur1->next;
        ans = ans -> next;
    }
    while (cur2!=NULL){
        res = (cur2->val + carry);
        carry = res/10;
        res%=10;
        ans->next = new LLNode(res,NULL);
        cur2=cur2->next;
        ans = ans -> next;
    }
    if (carry == 1) ans->next= new LLNode(1,NULL);
    return head;
}