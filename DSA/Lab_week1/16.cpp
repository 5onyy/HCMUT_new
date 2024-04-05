int longestSublist(vector<string>& words) {
    int ans=0;
    if (words.size() == 1)  return 1;
    for (int i=0;i<(int)words.size()-1;i++){
        if (words[i][0] == words[i+1][0]){
            int tmp=1;
            for (int j=i+1;j<(int)words.size() && words[j][0]==words[j-1][0];j++)  tmp++;
            ans=max(ans,tmp);
        }
    }
    return ans;
}