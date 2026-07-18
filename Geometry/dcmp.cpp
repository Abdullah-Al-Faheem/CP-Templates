const double EPS = 1e-9;
int dcmp(double x) // -ve or +ve or 0
{
    if (fabs(x) < EPS) return 0;   // x ≈ 0
    return (x < 0) ? -1 : 1;      
}
