const int N = 1e7+9;
bitset <N> mark;
vector<int> primes;
void sieve(void)
{
    int n = N - 9;
    mark[1] = true;

    for (int i = 2; i * i <= n; i++) 
    {
        if (!mark[i]) 
        {
            for (int j = i * i; j <= n; j += i) mark[j] = true;
        }
    }

    for (int i = 2; i <= n; i++) 
    {
        if (!mark[i]) primes.push_back(i);
    }
}
bool isPrime(int n)
{
    for (int i =0; primes[i]*primes[i] <= n; i++)
    {
        if(n%primes[i] == 0) return false;
    }
    return true;
}
