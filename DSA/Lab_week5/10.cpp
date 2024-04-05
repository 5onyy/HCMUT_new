#include<bits/stdc++.h>

class PrinterQueue
{
public:
    string a[1001][1001];
    int cnt[1101];
    multiset<pair<int,int>> s;
    int sze = 0;
    // your methods

    void addNewRequest(int priority, string fileName)
    {
        sze++;
        a[priority][cnt[priority]] = fileName; 
        s.insert({priority,cnt[priority]});
        cnt[priority]++;
        return;
    }

    void print()
    {
        if (!sze) {cout<<"No file to print\n";
                return;
        }
        auto x = s.rbegin();
        auto x2 = s.lower_bound(pair<int,int>(x->first, 0));
        int p1 = x2 -> first;
        int p2 = x2 -> second;
        s.erase(s.find({p1,p2}));
        cout<<a[p1][p2]<<'\n';
        a[p1][p2] = "";
        sze--;
        return;
    }
};