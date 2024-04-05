int pairMatching(vector<int>& nums, int target) {
	int n = nums.size(), cnt = 0;
	unordered_map<int, int> mp;
	for (int i = 0; i < n; i++) {
		mp[nums[i]]++;
		if (2 * nums[i] == target) { if (mp[nums[i]] <= 1) continue; cnt++;  mp[nums[i]] -= 2; continue;}
		if (mp[target - nums[i]])   {cnt++;  mp[nums[i]]--;  mp[target - nums[i]]--;}
	}
	return cnt;
}
