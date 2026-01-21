#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5+3; // change here
vector<int> num(N);
vector<int> tree(4*N);

//call with build(1,1,n)
void build(int at, int L, int R)
{
    if(L == R) 
    {
        tree[at] = num[L];
        return;
    }
    int mid = (L+R)/2;
    build(at*2, L, mid);
    build(at*2 +1, mid+1, R);

    tree[at] = tree[at*2] + tree[at*2+1]; // change here

}

// call with update(1,1,n, pos, X)
void update(int at, int L, int R,const int &pos,const int &X)
{
    if(L == R) 
    {
        tree[at] = X;
        return;
    }
    int mid = (L+R)/2;

    if(pos <= mid ) update(at*2, L, mid, pos, X);
    else            update(at*2 +1, mid+1, R, pos, X);

    tree[at] = tree[at*2] + tree[at*2+1]; // change here
}

// call with query(1,1,n, lft, rgt)
int query(int at, int L , int R,const int &lft,const int &rgt)
{
    if ( rgt < L or lft > R ) return 0; // change here
    if( L >= lft and R <= rgt) return tree[at]; 
    
    int mid = (L+R)/2;

    int val1 = query(at*2, L, mid, lft, rgt);
    int val2 = query(at*2+1, mid+1, R, lft, rgt);

    return val1+val2; // change here
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

}