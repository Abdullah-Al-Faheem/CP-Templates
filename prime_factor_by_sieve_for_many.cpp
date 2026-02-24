const int N = 1e7+9;
bitset <N> mark;
vector<int> primes;

void sieve(void)
{
    int n = N-9; // focus here
    for (int i = 2; i*i<n; i++)    
    {
        if(!mark[i])
        {
            for (int j = i+i; j<n; j+= i) mark[j] = 1;
        }
    }
    for (int i = 2; i<n; i++) if(!mark[i]) primes.push_back(i);
}

// call with primeFactor(n)
void primeFactor(int n)
{
    map<int,int> factor;
    for (int i =0; primes[i]*primes[i] <= n; i++)
    {
        while(n%primes[i] == 0)
        {
            n= n/primes[i];
            factor[primes[i]]++;
        }
    }
    if(n!=1) factor[n]++;
    for (auto it: factor) cout << it.first<<"^"<<it.second<<nl;
}
