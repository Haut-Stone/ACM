#include <stdio.h>

int main(void)
{
    int T,i;
    scanf("%d",&T);
    while(T--)
    {
        int x;
        char ch;
        scanf("%d%c",&x,&ch);
        int sum = x;
        int f;
        if(ch == '\0')//单行字符后面是‘\0’
        {
            printf("%d\n",sum);
            continue;
        }
        if(ch == '+')
            f = 1;
        else
            f = -1;
        while(scanf("%d%c",&x,&ch))
        {
            sum += f*x;
            if(ch == '\n')//多行最后是‘\n’
                break;
            if(ch == '+')
                f = 1;
            else
                f = -1;
        }
        printf("%d\n",sum);
    }

    return 0;
}