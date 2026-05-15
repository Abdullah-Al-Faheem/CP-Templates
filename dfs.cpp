void dfs(int src)
{
    cout << src<<endl; 
    status[src] = 1; 

    for (int child : adj[src])
    {
        if (status[child] == 0) dfs(child);
    }
}
