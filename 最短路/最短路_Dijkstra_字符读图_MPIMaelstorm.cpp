/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-28 10:08:57
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-28 10:49:36
*/

//POJ 1502
//图的读取稍微麻烦了一点，其余的话就是一发裸的DIJ

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

const int N = 1010;
const int INF = 999999999;

int vis[N];
int dis[N];
int pre[N];
int iMap[N][N];
int vertexs;
int edges;

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

	for(int i=1;i<=vertexs;i++){
		dis[i] = iMap[beginX][i];
		vis[i] = 0;
		pre[i] = dis[i] != INF && i != beginX ? beginX : -1;
	}

	dis[beginX] = 0;
	vis[beginX] = 1;

	for(int i=1;i<=vertexs;i++){
		min = INF;
		for(int j=1;j<=vertexs;j++){
			if(dis[j] < min && !vis[j]){
				min = dis[j];
				minVertex = j;
			}
		}
		if(min == INF) break;
		vis[minVertex] = 1;

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

int strToInt()
{
	char str[N];
	scanf("%s", str);
	if(strcmp(str, "x") == 0){
		return INF;
	}else{
		int ans = 0;
		int len  = strlen(str);
		for(int i=0;i<len;i++){
			ans = ans * 10 + str[i] - '0';
		}
		return ans;
	}
}

void read()
{
	for(int i=1;i<=vertexs;i++){
		for(int j=1;j<=i;j++){
			if(i != j){
				iMap[i][j] = iMap[j][i] = strToInt();
			}
		}
	}
}

int main(void)
{
	// INPUT_TEST;

	while(cin>>vertexs){
		init();
		read();
		dijkstra(1, vertexs);

		int ans = -INF;
		for(int i=1;i<=vertexs;i++){
			ans = max(ans, dis[i]);
		}
		printf("%d\n", ans);
	}
    return 0;
}