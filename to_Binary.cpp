int lastSetBit(int n)
{
	if(n == 0) return 0;
	int k = __builtin_clzll(n);
	return (64-k);
}
string toBinary(int n)
{
	if(n==0) return "0";
	int sz = lastSetBit(n);
	string str;

	for (int i =sz-1; i>=0; i--)
	{
		if((1LL<<i)&n)str.push_back('1');
		else str.push_back('0');
	}
	return str;
}
