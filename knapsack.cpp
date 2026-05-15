int n, w;
vector<int> val,  wt;

const int mxA = 1000, mxW = 1000;
int dp[mxA][mxW];
int knapsack(int indx, int w)
{
    // base case
    if (indx < 0 or w == 0) return 0; 

    if (dp[indx][w] != -1) return dp[indx][w];


    if (w >= wt[indx])// duita option
    {
        int tmp1 = val[indx] + knapsack(indx-1, w-wt[indx]); // nibe
        int tmp2 = knapsack(indx-1, w); // nibe na

        dp[indx][w] = max(tmp1, tmp2);  
    }
    else // ekta option
    {
        dp[indx][w] = knapsack(indx-1, w); // nibe na
    }

    return dp[indx][w];
}
