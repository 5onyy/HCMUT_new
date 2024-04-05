vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations) {
    for (int i=0;i<(int)operations.size();i++){
        int l = operations[i][0];
        int r = operations[i][1];
        int x = operations[i][2];
        for (int i=l;i<=r;i++)  nums[i] += x;
    }
    return nums;
}