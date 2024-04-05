string reverseSentence(string s) {
    size_t f = s.find(' ');
    if (f==string::npos)    return s;
    string tmp = s.substr(0,f);
    return reverseSentence(s.substr(f+1,s.size()-f))+ " " + tmp;
}