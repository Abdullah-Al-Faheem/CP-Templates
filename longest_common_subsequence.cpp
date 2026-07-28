// longest common subsuquence
// O(n^2)
// size and print

const int M =5e3+3; // change here // max string size

string aa, bb;
int sz1, sz2; // calculate their size in main()

int dp[M][M];
// memset(dp, -1, sizeof dp); -> in every testcase

// call with calc(0,0) for lcs SIZE
int calc(int l, int r)
{
    if(l== sz1 or r == sz2) return 0;

    if(dp[l][r] != -1) return dp[l][r];

    int &cnt = dp[l][r];

    if(aa[l] == bb[r]) cnt = 1+ calc(l+1, r+1);
    else cnt = max(calc(l+1, r), calc(l, r+1));

    return cnt;
}

// call with print(0,0) to PRINT the lcs
void print(int l, int r)    
{
    if(l== sz1 or r == sz2) return;
    
    if(aa[l] == bb[r]) 
    {
        cout << aa[l];
        print(l+1, r+1);
    }
    else if( calc(l+1,r) >= calc(l,r+1)) print(l+1, r);
    else print(l, r+1);
}
