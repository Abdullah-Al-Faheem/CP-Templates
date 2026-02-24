// time complexity -> O(n* target_sum)
// space complexity -> O(target_sum)
bool subsetSum(vector<int>& arr, int target) 
{
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (auto val : arr) 
    {
        for (int t = target; val<= t; t--) 
        {
            if (dp[t - val]) dp[t] = true;
        }
    }
    
    return dp[target];
}
