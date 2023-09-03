int infix_cal(string input){
    size_t f1=input.find(' ');
    size_t f2=input.find(' ',f1+1);
    int a=stoi(input.substr(0,f1));
    int b=stoi(input.substr(f2+1,input.size()-f2-1));
    char op=input[f1+1];
    if (op == '+')  return a+b;
    if (op == '-')  return a-b;
    if (op == '*')  return a*b;
    if (op == '/')  return a/b;
    return 0;
}