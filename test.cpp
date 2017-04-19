/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-22 11:12:17
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-19 21:03:26
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

const int N = 1000;
const int INF = 99999999;

struct Node
{
	int u;
	int v;
	int w;
}edge[N];

int dis[N];
int vertexs;
int edges;
int u, v, w;
int beginX, endX;

void init()
{
	memset(edge, 0, sizeof(edge));

}

int bellman(int beginX,int endX)
{
	for(int i=0;i<vertexs;i++){
		dis[i] = INF;
	}

	dis[beginX] = 0;
	for(int k=0;k<vertexs;k++){
		for(int i=0;i<edges;i++){
			if(dis[edge[i].u] != INF && dis[edge[i].v] > dis[edge[i].u] + edge[i].w){
				dis[edge[i].v] = dis[edge[i].u] + edge[i].w;
			}
		}
	}
	return dis[endX];
}
int main(void)
{	
	// INPUT_TEST;
	while(~scanf("%d%d", &vertexs, &edges)){
		int cnt = 0;

		init();
		
		for(int i=0;i<edges;i++){
			scanf("%d%d%d", &u, &v, &w);
			edge[cnt].u = u;
			edge[cnt].v = v;
			edge[cnt].w = w;
			cnt++;
			edge[cnt].u = v;
			edge[cnt].v = u;
			edge[cnt].w = w;
			cnt++;
		}
		edges = cnt;
		scanf("%d%d", &beginX, &endX);
		int ans = bellman(beginX, endX);
		if(ans == INF){
			printf("-1\n");
		}else{
			printf("%d\n", ans);
		}
	}
	return 0;
}