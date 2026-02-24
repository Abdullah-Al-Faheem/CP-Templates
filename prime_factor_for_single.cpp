void pf(int n) 
{
    map<int,int>factor;
    for (int i = 2; i*i <= n ; i++)
    {
        while(n%i == 0)
        {
            n = n/i;
            factor[i]++;
        }
    }   
    if(n!= 1) factor[n]++;
    
    for (auto it: factor) cout << it.first<<"^"<< it.second<<nl;
    cout <<nl;
}
