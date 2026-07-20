// points must be given in clockwise or counterclockwise order.
int polArea(vector<pair<int,int>> &points) // returns 2*area
{
    int n = points.size();

    int a, b; a= b= 0;
    
    for (int i = 1; i <= n; i++)
    {
        a+= points[i].second * points[i-1].first;
        b+= points[i].first* points[i-1].second;
    }
    
    return abs(a-b);
}
