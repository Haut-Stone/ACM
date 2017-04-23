/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-22 11:12:17
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-23 14:50:56
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

#define INPUT_TEST freopen("in.txt", "r", stdin)

const int N = 550;
const int INF = 99999999;

//仅dijkstra中用到的
int vis[N];
int dis[N];
int pre[N];

int iMap[N][N];
int vertexs;
int edges;//这里有个玄学问题，如果edges 放在vis[N],之前的话程序无法运行。。
int u, v;
int beginX;
int endX;

void init()
{
	for(int i=1;i<=vertexs;i++){
		for(int j=1;j<=vertexs;j++){
			if(i == j){
				iMap[i][j] = 0;
			}else{
				iMap[i][j] = INF;
			}
		}
	}
}


int dijkstra(int beginX, int endX)
{	
	int min;
	int minVertex = 0;

	//初始化
	for(int i=1;i<=vertexs;i++){
		dis[i] = iMap[beginX][i];
		vis[i] = 0;
		pre[i] = dis[i] != INF && i != beginX ? beginX : -1;//想将所有有链接的点的前一个点，设为出发点
	}

	dis[beginX] = 0;
	vis[beginX] = 1;

	for(int i=1;i<=vertexs-1;i++){//搜遍所有的点
		min = INF;
		for(int j=1;j<=vertexs;j++){//找距出发点距离最近的点
			if(dis[j] < min && !vis[j]){
				min = dis[j];
				minVertex = j;
			}
		}
		if(min == INF) break;//如果没有更小的点了，直接退出。
		vis[minVertex]  = 1;

		int u = minVertex;
		for(int v=1;v<=vertexs;v++){
			if(iMap[u][v] < INF){
				if(dis[u] + iMap[u][v] < dis[v]){
					 dis[v] = dis[u] + iMap[u][v];
					 pre[v] = u;
				}
			}
		}
	}
	return dis[endX];
}


void read()
{
	for(int i=1;i<=edges;i++){
		cin>>u>>v;
		iMap[u][v] = iMap[v][u] = 1;
	}
}

int main(void)
{
	// INPUT_TEST;
	int T;
	cin>>T;
	while(T--){
		cin>>vertexs>>edges>>beginX>>endX;
		init();
		read();
		while(1){
			if(beginX == endX){
				cout<<"chhappy"<<endl;
				break;
			}
			int ans = dijkstra(beginX, endX);
			if(ans == INF){
				cout<<"chsad"<<endl;
				break;
			}
			int now = pre[endX];
			iMap[now][endX] = INF;//切断路径
			if(now == beginX){
				beginX = endX;
				continue;
			}
			while(1){
				if(pre[now] == beginX) break;
				now = pre[now];
			}
			beginX = now;//更换起点
		}
	}
	return 0;
}