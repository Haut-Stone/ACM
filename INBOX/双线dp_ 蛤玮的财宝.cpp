/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-08 22:31:31
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-08 22:36:10
*/

//https://acm.zzuli.edu.cn/zzuliacm/problem.php?id=1875
//这不是一道单纯的搜索题，而是双线dp或者记忆化搜索
//dp与普通的搜索不同，dp主要是数组来存储状态，而不是来存储地图。只不过用数组的形式来表示状态互相之间的转移关系。

#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

#define INPUT_TEST freopen("in.txt", "r", stdin)
#define max4(a,b,c,d) max(max(a,b),max(c,d))

const int N = 110;

int row, col;
int ans;
int Imap[N][N];
int dp[2*N][N][N];

void read()
{
    cin>>row>>col;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            scanf("%d", &Imap[i][j]);
        }
    }
    memset(dp, 0, sizeof(dp));
}

int main()
{   
    INPUT_TEST; 

    int T;
    cin>>T;
    while(T--){
        read();
        dp[0][1][1] = Imap[1][1];
        //这里的k的目的是用来算y，而不是表示步数！！
        for(int k=1; k<=row+col-2; k++){
            for(int i=1; i<=k+1; i++){
                for(int j=1; j<=k+1; j++){
                    dp[k][i][j] = max4(dp[k-1][i][j], dp[k-1][i-1][j], dp[k-1][i][j-1], dp[k-1][i-1][j-1]);//找出4种状态中，最好的。步数是用来算y的
                    if(i!=j){//如果走到了同一个格子
                        dp[k][i][j]+=Imap[i][k+2-i]+Imap[j][k+2-j];
                    }else{
                        dp[k][i][j]+=Imap[i][k+2-i];//被走过一次后，第二次就没有金子了
                    }
                }
            }
        }
        printf("%d\n", dp[row+col-2][row][row]);
    }
    return 0;
}