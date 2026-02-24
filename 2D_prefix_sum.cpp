const int M = 1e3+9; // change here
int num[M][M];
int pref[M][M];

void build(int row, int col) // 1 indexed   
{
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            pref[i][j]= num[i][j] +( pref[i-1][j] +pref[i][j-1] -pref[i-1][j-1] )  ;
        }
    }
}

// left-upper corner, right-lower corner
int query(int r1, int c1, int r2, int c2) 
{
    return (pref[r2][c2] - pref[r1-1][c2] - pref[r2][c1-1] + pref[r1-1][c1-1]);
}
