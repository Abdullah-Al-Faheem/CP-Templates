const int N = 1e7+3;
vector<int> num(N), temp(N);

//call merge_sort(low, high) to sort in range low->high
void merge_sort(int lo, int hi)
{
    if(lo == hi) return;
    int mid = (lo+hi)/2;

    merge_sort(lo, mid);
    merge_sort(mid+1, hi);

    int i, j, k;

    i = lo; // first index of first half
    j= mid+1; // first index of second half
    

    for (k = lo; k<= hi; k++)
    {
        if(i == mid+1) temp[k] = num[j++]; // if first half ends then temp takes form second half
        else if(j == hi+1) temp[k] = num[i++]; // if second half ends then temp takes form first half
        
        // temp takes the smallest one
        else if(num[i] < num[j]) temp[k] = num[i++]; 
        else /* if( num[i] > num[j] ) */ temp[k] = num[j++];
    }

    for (k = lo ; k<= hi; k++) num[k] = temp[k]; 
    // temp has the sorted part and it transfers the sorted part to main array
}
