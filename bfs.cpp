void bfs(int src)
{
    queue<int> q;
    q.push(src);
    status[src] = 1;

    // level[src] = 1; // can vary

    while(!q.empty())
    {
        int parent = q.front(); // ber kore ana
        q.pop();

        // processing
        for (int child : adj[parent])
        {
            if (!status[child]) // set e na thakle
            {
                q.push(child);
                status[child] = 1;
                // level[child] = level[parent]+1; 
            }
        }

        // after work
        // cout << parent<<endl;
    }

}
