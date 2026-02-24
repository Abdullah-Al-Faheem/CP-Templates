void zMatch(string str)
{
    int n = str.size();

    vector<int>Z(n+3,0);

    int l, r, i, cnt;
    l = r = 1;

    while(l<n)
    {
        r=  max(r,l);
        i = r-l;
        
        while(r<n and str[r]==str[i])
        {
            r++, i++;
        }

        cnt= r-l;
        Z[l]= cnt;

        l++; i = 1;
        while(l<r and Z[i]+l<r)
        {
            Z[l]=Z[i];
            l++, i++;
        }
    }

    for (i = 0; i < n; i++)
    {
        cout<<Z[i]<<" ";
    } cout<<nl;
}
