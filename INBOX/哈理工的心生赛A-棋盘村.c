#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
int main(int argc, char const *argv[])
{
    int i,j;
    int x,y,m,n;
    int f[N][N];
    long long ans[N][N];
    int t;
    
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d%d" , &n, &m, &x, &y);
        memset(f, 1,sizeof(f));//Init array；
        memset(ans, 0, sizeof(ans));
        ans[0][0] = 1;
        f[x][y]=0,f[x+1][y+2]=0,f[x-1][y+2]=0;//逗号运算符，连接多个表达式；
        f[x+1][y-2]=0,f[x-1][y-2]=0,f[x+2][y+1]=0;
        f[x-2][y+1]=0,f[x+2][y-1]=0,f[x-2][y-1]=0;
        for(i=1;i<=n;i++){
            if(f[i][0]){
                ans[i][0] = 1;//初始化
            }else{
                break;
            }
        }
        for(i=1;i<=m;i++){
            if(f[0][i]){
                ans[0][i] = 1;//初始化
            }else{
                break;
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(f[i][j]){
                    ans[i][j] = ans[i-1][j] + ans[i][j-1];//将从上面的可能性和左面的相加
                }
            }
        }
        printf("%lld\n", ans[n][m]);//输出结果
    }
    return 0;
}