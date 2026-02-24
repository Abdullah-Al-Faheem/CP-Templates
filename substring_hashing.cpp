/*---------------------------------------------------------------------*/
#define ll long long
/*---------------------------------------------------------------------*/
const int base1 = 337, base2 = 277; // base for hashing
const int mod1 = 1e9+7, mod2 = 987654319; // mod for hashing
const int N= 1e6+7; // power size (max string size)

/*---------------------------------------------------------------------*/
int binaryExponentiation (int x, int n,int Mod)
{
    if(n==0) return 1; // base case
    int Half = binaryExponentiation(x, n/2, Mod);
    if(n%2==0) return (Half* Half)% Mod;  // even power 
    else return ( (Half*Half)%Mod * (x%Mod) ) % Mod;  // odd power 
}
int modInverse(int x, int M)
{
    int g = __gcd(x, M);
    if (g != 1) {cout << "Inverse doesn't exist"; return -1;}
    else return binaryExponentiation(x, M - 2, M);
}
/*---------------------------------------------------------------------*/
pair<int,int> pw[N]; // power array of base
pair<int,int> ipw[N]; //(mod inverse of powers) array of base [for subarray hashing]

// O(N)
void preCalc(void)
{
    pw[0].first = pw[0].second = 1; // base1^0 = 1 // base2^0 = 1
    
    for (int i = 1; i < N; i++)
    {
        pw[i].first = ( pw[i-1].first* base1 )%mod1; //pw[i].first = base1^i 
        pw[i].second = ( pw[i-1].second* base2 )%mod2; //pw[i].second = base2^i 
    }
    
    // mod inverse power calculation for subarray hashing:
    int ibase1 = modInverse(base1, mod1); // mod inverse of base1
    int ibase2 = modInverse(base2, mod2); // mod inverse of base2
    
    ipw[0] = {1,1}; // base^-0 = 1 
    for (int i = 1; i < N; i++)
    {
        ipw[i].first = (ipw[i-1].first *ibase1)%mod1; //ipw[i].first = (base1)^-i
        ipw[i].second = (ipw[i-1].second *ibase2)%mod2; // ipw[i].second = (base2)^-i
    }
}
/*---------------------------------------------------------------------*/
// O(str.size())
pair<int,int> pref[N];
// calculates prefix sum for substring hashing
void build(const string &str)
{
    int hs1, hs2; hs1 = hs2 = 0; // hash value
    int sz = str.size();
    
    for (int i = 0; i < sz; i++)
    {
        hs1 += ((ll)str[i] *pw[i].first) %mod1 ;
        hs1 %= mod1;
        pref[i].first = hs1;
        
        hs2 += ((ll)str[i] *pw[i].second) %mod2 ;
        hs2 %= mod2;
        pref[i].second = hs2;
    }   
}
/*---------------------------------------------------------------------*/

// O(str.size())
// call by hash_val(str) to get the hash value of string str
pair<int,int> hash_val(const string &str)
{
    int hs1, hs2; hs1 = hs2 = 0; // hash value
    int sz = str.size();
    
    for (int i = 0; i < sz; i++)
    {
        hs1 += ((ll)str[i] *pw[i].first) %mod1 ;
        hs1 %= mod1;
        
        hs2 += ((ll)str[i] *pw[i].second) %mod2 ;
        hs2 %= mod2;
    }
    return {hs1,hs2};
}
/*---------------------------------------------------------------------*/

pair<int,int> get_hash(int lft, int rgt) // O(1)
{
    if(lft==0) return pref[rgt];
    
    pair<int,int> hs;
    hs.first = (pref[rgt].first - pref[lft-1].first + mod1) %mod1; // prefix sum from lft->rgt
    hs.second = (pref[rgt].second - pref[lft-1].second +mod2) %mod2;
    
    hs.first = (hs.first* ipw[lft].first)%mod1; 
    hs.second = (hs.second* ipw[lft].second)%mod2;
    // dividing by base^lft to get the hash value
    //ipw[i] = mod inverse of base^lft
    
    return hs;
}
/*---------------------------------------------------------------------*/
// call preCalc(N) at the starting of main()
// call build_hash(str) at main() to build 
// then call by get_hash(l,r) to get hash val of [l,r] interval
// call by hash_val(str) to get the hash value of string str
/*---------------------------------------------------------------------*/
