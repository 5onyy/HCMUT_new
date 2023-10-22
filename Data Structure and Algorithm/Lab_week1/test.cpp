#include<bits/stdc++.h>

using namespace std;

bool palin(string s){
    if (s.size()<=0)   return true;
    if (s[0] == ' ' && s[s.size()-1]!=' ')  return (palin(s.substr(1,s.size()-1)));
    if (s[0] != ' ' && s[s.size()-1]==' ')  return (palin(s.substr(0,s.size()-1)));
    if (s[0] != ' ' && s[s.size()-1]!=' '){
        if (s[0] == s[s.size()-1])  return palin(s.substr(1,s.size()-2));
        else return false;
    }
}

int main(){
    string s = "cbb a a b b c";
    if (palin(s) != 0)  cout<<1;
    else cout<<0;
}
/*g++ -std=c++17 -O2 -Wall ".cpp" -o main.exe 
./main.exe*/