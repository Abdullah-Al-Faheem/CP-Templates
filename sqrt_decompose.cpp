void sqrt_Decompose(void)
{
    // input data
    int n; cin>>n;
    vector<int> arr(n); 
    for (int i = 0; i < n; i++) cin>>arr[i];

    int len = (int) sqrt (n + .0) + 1; // size of the block and the number of blocks

    vector<int> b(len);

    // build
    for (int i=0; i<n; ++i) 
        b[i/len] += arr[i]; 
        

    // answering the queries
    int q; cin>>q;
    while(q--)
    {
        int l, r; cin>>l>>r;
        int sum = 0;

        for (int i=l;i<=r; )
        {
            if (i %len ==0 and i +len -1 <= r) // if the whole block starting at i belongs to [l, r]
            {
                sum += b[i/len];
                i += len;
            }
            else 
            {
                sum += arr[i];
                ++i;
            }
        }
    }
}
