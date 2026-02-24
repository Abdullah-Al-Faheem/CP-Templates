// time complexity -> O(n* target_sum)
// space complexity -> O(target_sum)
// works for positive integer array only
// number of subsets can grow very fast, may need to use boolean dp or mod
int subsetSum(vector<int>& arr, int target) 
{
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (auto val : arr) 
    {
        for (int t = target; t-val >= 0; t--) 
        {
            dp[t] += dp[t-val];
        }
    }
    
    return dp[target];
}
