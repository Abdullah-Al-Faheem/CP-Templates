//--------------------------------------------------
const int M = 1e6+9;
int num[M], tree[M];
//--------------------------------------------------
void Add(int at, int val, int _n) // update operation
{
    while(at<= _n) 
    {
        tree[at] += val;
        at += (at& -at); 
    }
    
}
//--------------------------------------------------
int pref_sum(int at) // prefix sum 
{
    int Sum = 0;
    while(at>=1) 
    {
        Sum+= tree[at];

        at-= (at& -at); // previous node of the tree
        // erase right most set bit
    }
    return Sum;
}
//--------------------------------------------------
int query(int l, int r) // [right ,left] inclusive sum
{
    return pref_sum(r)-pref_sum(l-1);
}
//--------------------------------------------------
void input_fenwick(void)
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        cin>>num[i];
        Add(i, num[i], n);
    }
}
//--------------------------------------------------
