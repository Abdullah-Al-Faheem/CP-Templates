const int M = 1e5+9;

vector<int> adj[M], adj2[M]; // edges and reverse edges
vector<int> finish; // finishing order of first dfs
bool status[M], status2[M];

void dfs(int src)
{
    status[src] = true;  

    for (int child : adj[src])
        if (status[child] == 0) dfs(child);

    finish.push_back(src);
}

void dfs2(int src)
{
    cerr<<src<<" ";

    status2[src] = true;    

    for (int child : adj2[src])
    {
        if (status2[child] == false) dfs2(child);
    }
}

void scc(void)
{
    int n, edge, a, b; 

    cin>> n>>edge;

    for (int i = 1; i <= edge; i++)
    {
        cin>> a>> b;
        adj[a].push_back(b); // for first dfs
        adj2[b].push_back(a); // for second dfs
    }
    
    for (int i = 1; i <= n; i++)
       if(status[i]!=true) dfs(i); // first dfs status


    while(!finish.empty())
    {
        if(status2[finish.back()]) {finish.pop_back(); continue;} // second dfs status

        dfs2(finish.back());
        cerr<<nl;

        finish.pop_back();
    }
}
