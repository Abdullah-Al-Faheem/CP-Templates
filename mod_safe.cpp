int64_t mul(int64_t a, int64_t b) 
{
    return (__int128)a * b % mod;
}
int64_t add(int64_t a, int64_t b) 
{
    return ((__int128)a + b )% mod;
}
