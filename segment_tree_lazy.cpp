#include<bits/stdc++.h>
using namespace std;


const int N = 2e5 +9;
int num[N];
struct ST 
{
    #define lc (at << 1) // lft child n*2
    #define rc ((at << 1) | 1) // rgt child n*2+1

    long long tree[4*N], lazy[4*N];

    ST() {memset(tree, 0, sizeof tree); memset(lazy, 0, sizeof lazy);}

    // for upd() and query()
    // change this whole function
    inline void push(int at, int b, int e) // pushing lazy to childs 
    {
        if (lazy[at]== 0) return; 
        tree[at] = tree[at] + lazy[at] *(e-b+1); // ( range sum + lazy*range)

        if (b != e) // pushing lazy
        {
            lazy[lc] = lazy[lc] + lazy[at]; 
            lazy[rc] = lazy[rc] + lazy[at]; 
        }
        lazy[at] = 0; // reset
    }

    // call by build(1,1,n)
    void build(int at, int b, int e) // node, begin, end
    {
        lazy[at] = 0; // change this
        if (b == e) 
        {
            tree[at] = num[b]; 
            return;
        }

        int mid = (b + e) >>1;

        build(lc, b, mid);
        build(rc, mid + 1, e);

        tree[at] = tree[lc] + tree[rc]; // change this
    }

    // call by upd(1,1,n, lft, rgt, val)
    void upd(int at, int b, int e, int lft, int rgt, long long v) // node, begin, end, [lft, rgt], val
    {
        push(at, b, e);

        if (b >rgt or e <lft) return; 
        if (b >= lft and e <= rgt) 
        {
            lazy[at] = v; //set lazy
            push(at, b, e);
            return;
        }

        int mid = (b + e)>>1;
        upd(lc, b, mid, lft, rgt, v);
        upd(rc, mid + 1, e, lft, rgt, v);

        tree[at] = tree[lc] + tree[rc]; // change this
    }

    // call by query(1,1,n, lft, rgt)
    long long query(int at, int b, int e, int lft, int rgt) // node, begin, end, [lft, rgt]
    {
        push(at, b, e);

        if (b > rgt or e < lft) return 0; // change this
        if (b>= lft and e<= rgt) return tree[at];

        int mid = (b + e) >> 1;
        
        long long val1 = query(lc, b, mid, lft, rgt);
        long long val2 = query(rc, mid+1, e, lft, rgt);

        return val1+val2; // change this
    }
};

int32_t main()
{

}