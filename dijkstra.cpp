const int N = 1e5+5;
// vector< pair<int,int> > adjacecyList[N];
unordered_map<int, vector<pair<int,int> > > adjacecyList;
vector<int> cost(N, LLONG_MAX);

void dijkstra(int source)
{
    cost[source] =0;

    // queue<pair<int,int> > q;// naive version
    priority_queue< pair<int,int> , vector<pair<int,int> > , greater<pair<int,int>> > pq; // optimized version
    pq.push({0, source}); // (cost, parent)

    while(!pq.empty())
    {
        auto pr1 = pq.top(); pq.pop();
        int parent = pr1.second;
        int parentCost = pr1.first;

        for (int i =0; i<adjacecyList[parent].size(); i++)
        {
            auto pr2 = adjacecyList[parent][i];
            int child = pr2.second;
            int parentToChildCost = pr2.first;

            if (cost[child] > parentCost+ parentToChildCost)
            {
                //path relaxation
                cost[child] = parentCost+ parentToChildCost;
                pq.push({cost[child], child});
            }
        }
    }
}

void inputDijkstra(void)
{
    int nodes, edges;
    cin >> nodes>> edges;

    int a, b, edgeCost;
    while(edges--)
    {
        cin >> a>> b>> edgeCost; //input edges
        adjacecyList[a].push_back({edgeCost, b});
        adjacecyList[b].push_back({edgeCost, a});
    }

    dijkstra(0); // calling main dijkstra

    for (int i =0; i<nodes; i++) cout << i<<"-> "<< cost[i]<<nl; // output ans
}
