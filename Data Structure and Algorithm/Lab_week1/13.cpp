int buyCar(int* nums, int length, int k) {
    sort(nums,nums+length);
    int ans=0;
    for (int i=0;i<length;i++){
        if (k-nums[i]<0)    return ans;
        k-=nums[i];
        ans++;
    }
    return ans;
}