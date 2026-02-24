vector<int> pattern_process(string &str) 
{
    int n = str.size();
    vector<int>lps(n);
    lps[0]=0;

    int r = 0;

    while(1)
    {
        r++; if(r==n) break;

        int l = lps[r-1];

        while(l>0 and str[r]!= str[l]) l = lps[l-1];

        if(str[r]==str[l]) l++;

        lps[r]= l;
    }
    return lps;
}

int KMP(string &txt, string &pat)
{
    vector<int> lps = pattern_process(pat);

    int n = (int)txt.size();
    int m = (int)pat.size();

    vector<int>found;

    int i = 0;
    int j = 0;

    while(i<n)
    {
        if(txt[i]== pat[j]) // matching character
        {
            i++;
            j++;

            if(j==m) 
            {
                found.push_back(i-j);
                j= lps[j-1];
            }
        }
        else // mismatch character
        {
            if (j > 0) j= lps[j-1];
            else i++;
        }
    }

    return (int)found.size();
}
// call by KMP(text, pattern)
