int leastAfter(vector<int>& nums, int k) {
    multiset<int> s(nums.begin(), nums.end());
    while (k --){
        int k = *s.begin();
        s.erase(s.begin());
        k *= 2;
        s.insert(k);
    }
    return *s.begin();
}