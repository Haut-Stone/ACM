#include <cstdio>
#define MAX 100000000
int main()
{
    int n, i, j, m;
    long long a[10000], c;//c是进位!!
    scanf("%d",&n);
    
    m = 0;
    a[0] = 1;
    for(i = 1; i <= n; i++)
    {
        c = 0;
        for(j = 0; j <= m; j++)
        {
            a[j] = a[j] * i + c;
            c = a[j] / MAX;
            a[j] %= MAX;
        }
        if(c > 0)
        {
            m++;
            a[m] = c;
        }
    }
    printf("%lld", a[m]);
    for(i = m - 1; i >= 0; i--)
        printf("%0.8lld", a[i]);
    printf("\n");
    return 0;
}