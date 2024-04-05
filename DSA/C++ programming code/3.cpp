string many_infix_cal (string s){
    string ans="";
    int tmp=0;
    size_t f1=s.find(' ');
    size_t f2=s.find(' ',f1+1);
    size_t f3=s.find('\n',f2+1);
    if (f3==string::npos)   f3=s.size();
    int a=stoi(s.substr(0,f1));
    int b=stoi(s.substr(f2+1,f3-f2));
    char op=s[f1+1];
    if (op=='+')    tmp=a+b;
    if (op=='-')    tmp=a-b;
    if (op=='*')    tmp=a*b;
    if (op=='/')    tmp=a/b;
    ans+= to_string(tmp);
    tmp=0;
    while (f3 != s.size()){
        f1=s.find(' ',f3+1);
        f2=s.find(' ',f1+1);
        op=s[f1+1];
        a=stoi(s.substr(f3+1,f1-f3));
        f3=s.find('\n',f2+1);
        if (f3==string::npos)    f3=s.size();
        b=stoi(s.substr(f2+1,f3-f2));
        if (op=='+')    tmp=a+b;
        if (op=='-')    tmp=a-b;
        if (op=='*')    tmp=a*b;
        if (op=='/')    tmp=a/b;
        ans+=" " + to_string(tmp);
        tmp=0;
    }
    return ans;
}