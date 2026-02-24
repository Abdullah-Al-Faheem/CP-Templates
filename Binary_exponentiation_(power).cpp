const int MOD = 1e9+7;

// call by power(x, n) to calculate (x^n)%MOD
int power (int x, int n)
{
    if(n==0) return 1; // base case

    int res = power(x, n/2);
    
    // odd power
    if(n&1) return ( (res*res)%MOD * (x%MOD) ) % MOD;    
    // even power
    else return (res* res)% MOD;   
}
