bool consecutiveOnes(vector<int>& nums) {
    int idx = -1;
    for (int i=0;i<nums.size();i++){
        if (nums[i] == 1 && i!=idx+1 && idx!=-1)    return 0;   
        if (nums[i] == 1)   idx = i;
    }
    return 1;
}