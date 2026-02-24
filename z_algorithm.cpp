vector<int> z_fun(string str) 
{
    int n = str.size();
    vector<int> Z(n,0);
    int l = 0, r = 0;

    for(int i = 1; i < n; i++) 
    {
        if(i < r) Z[i] = min(r - i, Z[i - l]);

        while(i+Z[i] < n and str[Z[i]] == str[i +Z[i]]) Z[i]++;
            
        if(i + Z[i] > r) // update box
        {
            l = i;
            r = i + Z[i];
        }
    }
    return Z;
}
