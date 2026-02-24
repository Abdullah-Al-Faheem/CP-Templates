int lastSetBit(int n)
{
    if(n == 0) return 0;
    int k = __builtin_clzll(n);
    return (64-k);
}
