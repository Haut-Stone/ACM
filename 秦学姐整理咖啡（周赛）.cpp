#include <stdio.h>
#include <string.h>

int main(void)
{
    int T,n,i,j;
    int a[1100];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);//依次读入数据 
        int ans = 0;//初始化答案
        while(n > 1)
        {
            int min1 = 0,min2 = 1;//
            if(a[min1] > a[min2])
            {
                int t = min1;
                min1 = min2;
                min2 = t;
            }//如果第一个大于第二个，交换“指针”
            for(i=2;i<n;i++)
            {
                if(a[i] < a[min1])
                {
                    min2 = min1;
                    min1 = i;
                }
                else if(a[i] < a[min2])
                    min2 = i;
            }
            int t = a[min1] + a[min2];
            ans += t;
            if(min1 == n - 1)
            {
                int t = min1;
                min1 = min2;
                min2 = t;
            }
            a[min1] = t;
            a[min2] = a[n-1];//没处理完一位，就从数组尾部踢出去一位。
            n--;
        }
        printf("%d\n",ans);
    }
    return 0;
}
