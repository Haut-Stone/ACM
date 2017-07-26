/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-25 22:33:43
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-25 22:59:37
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
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;

const int N = 2020;
const int INF = 1<<29;

struct Node
{
	int u;
	int v;
	int w;
}edge[N*N];

int dis[N];
int vertexs;
int edges;
int u, v, w;
int cnt;

int bellman(int beginX,int endX)
{
	for(int i=1;i<=vertexs;i++){
		dis[i] = INF;
	}
	dis[beginX] = 0;
	for(int k=1;k<=vertexs;k++){
		for(int i=1;i<=cnt;i++){
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

	while(cin>>edges>>vertexs){	
		cnt = 1;
		//因为是无向边所以要存两遍，有向边的话只需要存一遍
		for(int i=1;i<=edges;i++){
			scanf("%d%d%d", &u, &v, &w);
			edge[cnt].u = u;
			edge[cnt].v = v;
			edge[cnt++].w = w;
			edge[cnt].u = v;
			edge[cnt].v = u;
			edge[cnt++].w = w;
		}	
		printf("%d\n", bellman(1, vertexs));
	}
    return 0;
}