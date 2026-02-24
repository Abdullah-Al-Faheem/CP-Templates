int gcdExtended(int a, int b, int* x, int* y)
{
	if (a == 0) {*x = 0, *y = 1; return b;}
	// Base Case

	int x1, y1; // To store results of recursive call
	int gcd = gcdExtended(b % a, a, &x1, &y1);

	*x = y1 - (b / a) * x1; *y = x1; // Update x and y using results of recursive call
	return gcd;
}

// when M and A are coprime or gcd(A, M)==1:
int modInverse(int A, int M) 
{
	int x, y;
	int g = gcdExtended(A, M, &x, &y);

	if (g != 1) {cout << "Inverse doesn't exist\n"; return -1;}
	else return ((x % M + M) % M); // m is added to handle negative x
}
