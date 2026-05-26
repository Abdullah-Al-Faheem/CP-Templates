struct DSU 
{
    vector<int> parent, Size;

    DSU(int n)
    {
        parent.resize(n + 1); // 1 based
        Size.resize(n + 1, 1);

        for (int i = 1; i <= n; i++) parent[i]=i;
    }

    int find_par(int node)
    {
        if(parent[node] == node) return node;

        return parent[node] = find_par(parent[node]);
    }

    void union_size(int u, int v) // union by size
    {
        int pu = find_par(u);
        int pv = find_par(v);

        if(pu == pv) return;

        if(Size[pu] < Size[pv]) swap(pu, pv);

        parent[pv] = pu;
        Size[pu] += Size[pv];
    }

    int size(int node)
    {
        return Size[find_par(node)];
    }
};
