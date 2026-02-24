const int M = 1e3+5;
int val[M];
int dp[M][M]; // mem(dp, -1); // [M, target_sum]

// call with subset_sum(n, target_sum) 
// to get how many ways can we get the target sum
int subset_sum(int i, int bagCapacity) // O(n* target_sum)
{
    if (bagCapacity == 0 and i == 0) return 1;
    if (i== 0) return 0;
    

    if(dp[i][bagCapacity] != -1) return dp[i][bagCapacity];

    if (val[i] <= bagCapacity) // duita option
    {
        int cnt1 = subset_sum(i-1, bagCapacity-val[i]); // nibe
        int cnt2 = subset_sum(i-1, bagCapacity); // nibe na

        dp[i][bagCapacity]= cnt1+cnt2;
    }
    else // ekta option
    {
        dp[i][bagCapacity] = subset_sum(i-1, bagCapacity); // nibe na
    }

    return dp[i][bagCapacity];
}
