int equalSumIndex(vector<int>& nums) {
    vector<int> pref(nums.size()+1,0);
    for (int i=1;i<=nums.size();i++) pref[i] = pref[i-1] + nums[i-1];
    for (int i=1;i<=nums.size();i++) if (pref[i-1] == pref[nums.size()] - pref[i])    return i-1;
    return -1;
}