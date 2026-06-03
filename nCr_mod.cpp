const int mod = 998244353;
const int M = 2e5+5;
int fact[M];

// call with precalc() at the start of the main()
void precalc(void) 
{
    fact[0]=1;
    
    for (int i = 1; i <M; i++) fact[i]=fact[i-1]*i%mod;
}

int power(int a, int b) 
{
    if (b==0) return 1;
    if (b&1) return a *power(a, b-1) % mod;
    return power(a*a %mod , b/2);
}
int modInverse(int A) {return power(A, mod - 2);}

int ncr(int n, int r)
{
    return fact[n]*modInverse(fact[n-r]*fact[r]%mod)%mod;
}
