action a[4]={{"+", &myadd},{"-", &mymin},{"*", &mymul},{"/", &mydiv}};

int infix_cal(string s){
    size_t f1=s.find(' ');
    size_t f2=s.find(' ',f1+1);
    int aa=stoi(s.substr(0,f1));
    int bb=stoi(s.substr(f2+1,s.size()-f2-1));
    for (int i=0;i<4;i++){
        if (s[f1+1] == a[i].op[0])
            return (a+i) ->func(aa,bb);
    }
    return 0;
}