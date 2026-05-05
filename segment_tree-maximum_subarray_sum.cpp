// Maximum Subarray Sum in a given Range
// example problem: https://codeforces.com/problemset/problem/1691/D

struct Node
{
    int preMax, postMax, total, max;
};

const int N = 2e5+3; // change here
vector<int> num(N);
vector<Node> tree(4*N);

//call with build(1,1,n)
void build(int at, int L, int R)
{
    if(L == R) 
    {
        tree[at].total = tree[at].max= tree[at].postMax = tree[at].preMax = num[L]; // change here
        return;
    }

    int mid = (L+R)/2;
    build(at*2, L, mid);
    build(at*2 +1, mid+1, R);

    tree[at].total = tree[at*2].total + tree[at*2+1].total; // change here
    tree[at].preMax = max(tree[at*2].total + tree[at*2+1].preMax, tree[at*2].preMax); // change here
    tree[at].postMax = max(tree[at*2].postMax + tree[at*2+1].total, tree[at*2+1].postMax); // change here
    tree[at].max= max({tree[at*2].postMax + tree[at*2+1].preMax, tree[at*2].max, tree[at*2+1].max}); // change here
}


// call with query(1,1,n, lft, rgt)
Node query(int at, int L , int R,const int &lft,const int &rgt)
{
    Node tmp;

    // change here
    tmp.max=tmp.postMax=tmp.preMax=-1e18;
    tmp.total=0;

    if ( rgt < L or lft > R ) return tmp; // change here
    if( L >= lft and R <= rgt) return tree[at]; 
    
    int mid = (L+R)/2;

    Node val1 = query(at*2, L, mid, lft, rgt);
    Node val2 = query(at*2+1, mid+1, R, lft, rgt);
    
    tmp.total = val1.total + val2.total; // change here
    tmp.preMax = max(val1.total + val2.preMax, val1.preMax); // change here
    tmp.postMax = max(val1.postMax + val2.total, val2.postMax); // change here
    tmp.max= max({val1.postMax + val2.preMax, val1.max, val2.max}); // change here

    return tmp; // change here
}
