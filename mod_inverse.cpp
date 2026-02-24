const int mod = 1e9+7;

int power(int a, int b) 
{
    if (b==0) return 1;
    if (b&1) return a *power(a, b-1) % mod;
    return power(a*a %mod , b/2);
}

int modInverse(int A) {return power(A, mod - 2);}
