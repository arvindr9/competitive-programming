//Source: rkm0959
long long int r[111111]; // remainders
long long int m[111111]; // modulars
long long int M=1; // product
int n; // number of equation
int res(void)
{
    int i;
    for(i=1 ; i<=n ; i++)
    {
        M=M*m[i];
    }
    long long int ret=0;
    for(i=1 ; i<=n ; i++)
    {
        ret+=r[i]*inv(M/m[i],m[i])*(M/m[i]);
        ret=ret%M;
    }
    return ret;
}
