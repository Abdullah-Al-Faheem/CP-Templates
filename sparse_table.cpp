const int M = 1e5+5; // change here
int num[M];
int sparse[M][24]; // change here

//call with build(n)
void build(int n)
{
    int m = log2l(n); // may give precision error

    for (int i = 1; i <= n; i++) sparse[i][0]=num[i];

    for (int j = 1; j <= m; j++)
    {  
        // segment starts at index i ,has length 2^j; end = i + length - 1
        for (int i = 1; i +(1<<j) -1 <= n; i++) 
        {
            // min from index i over a segment of length 2^j
            sparse[i][j]= min  // change here
            ( 
                sparse[i][j-1], sparse[i+(1<<(j-1))][j-1] // overlapping segments
            ); 
        }
    }
}

// call with query(L,R)
int query(const int &L, const int &R)
{
    int len = R-L+1;
    int j = log2l(len); // may give precision error

    return min(sparse[L][j], sparse[R -(1<<j) +1][j]) ; // change here
}
