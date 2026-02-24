// call with big_divisible(a, x) to divide a by x
bool big_divisible(string str, int x)
{
    int rem = 0;

    int i;
    if (str[0] == '-') i= 1; // if the number is negative
    else i = 0;

    if (x<0) x = abs(x); // if n is negative

    for (  ; i< str.size() ; i++)
    {
        int d = str[i] - '0'; // extracting digits

        rem = (rem*10 + d) %x;
    }

    if (rem == 0)	cout << "divisible"<<endl;
    else		cout << "rem is :"<< rem<< endl;

    return (rem == 0)? true : false;
}
