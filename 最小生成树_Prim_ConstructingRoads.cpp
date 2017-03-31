/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-30 20:51:41
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-30 21:16:55
*/
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

const int N = 110;
const int INF = 1e8;
int Imap[N][N];
int lowCost[N];
int vis[N];
int n;
int ans;

void read()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>Imap[i][j];
        }
    }
    int m;
    int a, b;
    cin>>m;
    for(int i=0;i<m;i++){//将已有道路的地方视为距离为0.
        cin>>a>>b;
        Imap[a-1][b-1] = Imap[b-1][a-1] = 0;
    }
}

void Prim()
{
    for(int i=0;i<n;i++){//从第一个点搜起。
        lowCost[i] = Imap[0][i];
        vis[i] = 0;
    }
    ans = 0;
    vis[0] = 1;//第一个点已经被检查过。
    while(true){
        int minDis = INF;
        int minPos = 0;
        for(int j=0;j<n;j++){
            if(lowCost[j] < minDis && !vis[j]){
                minDis = lowCost[j];
                minPos = j;
            }
        }
        if(minDis == INF) break;
        vis[minPos] = 1;
        ans += minDis;
        for(int j=0;j<n;j++){
            if(!vis[j] && lowCost[j] > Imap[minPos][j]){
                lowCost[j] = Imap[minPos][j];//将已搜索过的点视为一个整体。
            }
        }
    }

}

int main(void)
{   
    while(cin>>n){
        read();
        Prim();
        cout<<ans<<endl;
    }
    return 0;
}