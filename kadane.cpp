int kadane(const vector<int> &arr)
{
    int currSum, maxSum, n = arr.size();
    currSum = maxSum = arr.front();

    for (int i = 1; i < n; i++)
    {
        if( arr[i] > (arr[i]+currSum) ) currSum = arr[i];
        else currSum+= arr[i];

        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}
