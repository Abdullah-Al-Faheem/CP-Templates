// returns longest increasing subsequence size 
// using binary search
int LIS(const vector<int> &arr, int n) // O(nlogn)
{
    int cnt = 0;

    vector<int> temp; // fake LIS

    for (int i = 1; i <= n; i++)
    {
        if(temp.empty() or arr[i]> temp.back()) {temp.push_back(arr[i]); cnt++;}
        else 
        {
            auto it = lower_bound(all(temp), arr[i]);
            *it = arr[i];
        }
    }

    return cnt; 
}
