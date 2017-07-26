/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-30 19:02:02
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-24 11:03:04
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
int minCost[N];
int vis[N];
int n;
int ans;

//读取地图
void read()
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>Imap[i][j];
		}
	}
}

void Prim()
{
	for(int i=0;i<n;i++){//从第一个点搜起。
		minCost[i] = Imap[0][i];
		vis[i] = 0;
	}
	ans = 0;
	vis[0] = 1;//第一个点已经被检查过。
	while(true){
		int minDis = INF;
		int minPos = 0;
		for(int j=0;j<n;j++){
			if(minCost[j] < minDis && !vis[j]){//搜索到当前点的最短距离
				minDis = minCost[j];
				minPos = j;
			}
		}
		if(minDis == INF) break;//如果所有的点都被找过
		vis[minPos] = 1;
		ans += minDis;
		for(int j=0;j<n;j++){
			if(!vis[j] && minCost[j] > Imap[minPos][j]){//将已搜索过的点视为一个整体。
				minCost[j] = Imap[minPos][j];
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