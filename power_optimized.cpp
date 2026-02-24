const int MOD = 1e9+7;

int power(int a, int b) 
{
    if (b==0) return 1;
    if (b&1) return a *power(a, b-1) % MOD;
    return power(a*a %MOD , b/2);
}
