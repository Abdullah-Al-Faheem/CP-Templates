const int base1 = 337, base2 = 277; 
const int mod1 =100000000000031, mod2 = 72727272727231;
const int N= 1e5+7; // power size (max string size)

pair<int,int> pw[N]; // power array of base

void preCalc(void)
{
    pw[0].first = pw[0].second = 1; // base1^0 = 1 // base2^0 = 1

    for (int i = 1; i <= N; i++)
    {
        pw[i].first = ( pw[i-1].first* (base1%mod1) )%mod1; //pw[i].first = base1^i 
        pw[i].second = ( pw[i-1].second* (base2%mod2) )%mod2; //pw[i].second = base2^i 
    }
}

// call preCalc(N) at the starting of main function ***
// call by hash_val(str) to get the hash value of string str
pair<int,int> hash_val(string str)
{
    int hs1, hs2;
    hs1 = hs2 = 0; // hash value

    for (int i = 0; i < str.size(); i++)
    {
        hs1 += ((ll)str[i] *pw[i].first) %mod1 ;
        hs1 %= mod1;

        hs2 += ((ll)str[i] *pw[i].second) %mod2 ;
        hs2 %= mod2;
    }

    return {hs1,hs2};
}
