/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-26 22:07:24
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-26 22:07:52
*/

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#define INPUT_TEST freopen("/home/parallels/Desktop/INPUT", "r", stdin)
using namespace std;

const int N = 55;
const int INF = 0x3f3f3f3f;

char rawMap[N][N];
int iMap[N][N];
int vis[N][N];
int dic[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int beginX, beginY;
int flag;
int n, m;
int colorNow;

void dfs(int x, int y, int dep, int prex, int prey)
{
    if(x == beginX && y == beginY && dep >= 4){
        flag = true;
        return;
    }
    if(flag == true) return;
    for(int i=0;i<4;i++){
        int dx = x + dic[i][0];
        int dy = y + dic[i][1];
        if(dx >= 1 && dx <= n && dy >= 1 && dy <= m && iMap[dx][dy] == colorNow){
            if(dx == beginX && dy == beginY  && (dx != prex || dy != prey)){
                // cout<<x<<' '<<y<<endl;
                dfs(dx, dy, dep+1, x, y);
            }else if(!vis[dx][dy] && (dx != prex || dy != prey)){
                vis[dx][dy] = 1;
                // cout<<x<<' '<<y<<endl;
                dfs(dx, dy, dep+1, x, y);
                vis[dx][dy] = 0;
            }
        }
    }
}

int main(void)
{
    // INPUT_TEST;
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i=0;i<n;i++){
            scanf("%s", rawMap[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                iMap[i+1][j+1] = rawMap[i][j] - 'A' + 1;
            }
        }
        flag = false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                memset(vis, 0, sizeof(vis));
                beginX = i;
                beginY = j;
                colorNow = iMap[i][j];
                vis[i][j] = 1;
                dfs(i, j, 0, -1, -1);
                if(flag) break;
            }
            if(flag) break;
        }
        if(flag){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
}