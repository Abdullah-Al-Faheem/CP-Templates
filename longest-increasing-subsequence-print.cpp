// longest increasing subsequence of an array O(n^2)
vector<int> dp(n+3,0);
int lisCnt = 1;
for (int i = 1; i <= n; i++)
{
    dp[i] = 1;

    for (int j = 1; j < i; j++)
    {
        if(arr[j]< arr[i])    
            dp[i] = max(dp[i], dp[j]+1);
    }
    lisCnt = max(lisCnt, dp[i]);
}
cout << lisCnt <<nl;
