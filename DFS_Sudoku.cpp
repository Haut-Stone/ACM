#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 12
using namespace std;
int num[MAXN][MAXN];
int row[MAXN][MAXN];//用来标记每一行九个数是否已被使用，使用记为1
int col[MAXN][MAXN];//列
int mar[MAXN][MAXN];//用0-8标识9个小数独矩阵
char chr[MAXN][MAXN];
bool flag=false;
void dfs(int m,int n)
{
    int s,i,j;
    
    if(m==9&&n==0)
    {
        for(i=0;i<=8;i++)
        {
            for(j=0;j<=8;j++)
            {
                cout<<num[i][j];
            }
            cout<<endl;
        }
        flag=true;
    }
    else
    {
        if(num[m][n]!=0)
        {
            if(n<=7)
                dfs(m,n+1);
            else
                dfs(m+1,0);
        }
        else
        {
            for(i=1;i<=9;i++)
            {
                if(row[m][i]==0&&col[n][i]==0&&mar[m/3*3+n/3][i]==0)//根据i,j标定它所属的行，列，和所在的小矩阵
                {
                    s=m/3*3+n/3;
                    num[m][n]=i;
                    row[m][i]=1;
                    col[n][i]=1;
                    mar[s][i]=1;
                    if(n<=7)
                        dfs(m,n+1);
                    else
                        dfs(m+1,0);
                    if(flag)
                        return ;
                    num[m][n]=0;//一旦回溯过来，必须重新置0，因为说明此数字对于后面的搜索产生了不满足，故将其置0.
                    row[m][i]=0;
                    col[n][i]=0;
                    mar[s][i]=0;
                }
            }
        }
    }
}
int main()
{
    int i,j,s,t;
    cin>>t;
    while(t--)
    {
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        memset(mar,0,sizeof(mar));
        for(i=0;i<9;i++)
            scanf("%s",chr[i]);
        for(i=0;i<9;i++)
            for(j=0;j<9;j++)
            {
                num[i][j]=chr[i][j]-'0';
                s=num[i][j];
                if(s!=0)
                {
                    row[i][s]=1;
                    col[j][s]=1;
                    mar[i/3*3+j/3][s]=1;//初始，一旦有数字，则要将它所在的行列及小矩阵标为1
                }
            }
        flag=false;
        dfs(0,0);
    }
    return 0;
}
}