// angle of the line (0,0)---(x,y)
double theta(double x, double y)
{
    double th;
    if(x==0)
    {
        th= pi/2;
        if(y>=0) return th;
        else return pi+th;
    }
    if(y==0)
    {
        if(x>=0) return 0;
        else return pi;
    }

    th= atanl(abs(y/x));

    if(x>0 and y>0) return th;
    if(y>0 and x<0) return pi-th;
    if(x<0 and y<0) return pi+th;
    if(x>0 and y<0) return 2*pi-th;
}