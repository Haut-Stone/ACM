/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-22 11:12:17
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-31 19:46:17
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

const int N  = 110;
const int INF = 1e8;
int Imap[N][N];
int lowCost[N];
int n;
int ans;


void Prim()
{
    for(int i=0;i<n;i++){
        lowCost[i] = Imap[0][i];//以第一个点为原点，初始化
    }
    ans = 0;
    for(int i=0;i<n-1;i++){//搜索所有的点。
        int minone;
        int mindis = INF;
        for(int j=0;j<n;j++){//找到所有点中，距离最近的
            if(lowCost[j] && lowCost[j] < mindis){
                mindis = lowCost[j];
                minone = j;
            }
        }
        if(mindis == INF) break;
        ans += mindis;
        lowCost[minone] = 0;//将已经加过的距离归零
        for(int j=0;j<n;j++){
            if(lowCost[j] > Imap[minone][j]){
                lowCost[j] = Imap[minone][j];//将已搜过的点视为一个联通分量，更新之后，是剩余点到该联通分量的最短距离。
            }
        }
    }
}

void read()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &Imap[i][j]);
        }
    }
    int m;
    int a, b;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        Imap[a-1][b-1] = Imap[b-1][a-1] = 0;
    }
}

int main(void)
{
    while(~scanf("%d", &n)){
        read();
        Prim();
        cout<<ans<<endl;
    }
    return 0;
}