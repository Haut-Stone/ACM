/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-30 10:32:22
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-30 11:05:41
*/

//POJ 2502
//

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
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;

const int N = 110;
const int INF = 99999999;

struct Node
{
	double x;
	double y;
}vertex[N], beingPos, endPos;

int vis[N];
int dis[N];
int pre[N];//记录路径的数组
int iMap[N][N];
int vertexs;
int edges;
int cnt;

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

double getDis(double x1, double x2, double y1, double y2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
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

	for(int i=1;i<=vertexs;i++){//搜遍所有的点，每次确定到一个点的最短距离。
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
		//松弛
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

int main(void)
{
	cnt = 0;
	while(cin>>beingPos.x>>beingPos.y>>endPos.x>>endPos.y){

	}
    return 0;
}