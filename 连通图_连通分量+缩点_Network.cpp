/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-04 10:37:56
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-04 12:48:17
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

const int N = 100;
const int INF  = 99999999;

struct Node
{
	int next;
	int to;
}edge[N*N];

int vertexs, edges;
int dfn[N], low[N];
bool isBridge[N];
int par[N];

int head[N];
int edgeCnt, timeCnt, bridgeCnt;

void add(int u, int v)//存一条以u为起点,v为终点,w为边权值的有向边。
{
	edge[edgeCnt].to = v;
	edge[edgeCnt].next = head[u];
	head[u] = edgeCnt;
	edgeCnt++;
}

void init()
{
	edgeCnt = timeCnt = bridgeCnt = 0;
	memset(head, -1, sizeof(head));
	memset(edge, 0, sizeof(edge));
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(isBridge, false, sizeof(isBridge));
}

int LCA(int u, int v)//这里还是不理解
{
	int cnt = 0;
	while(dfn[u] > dfn[v]){
		if(isBridge[u]){
			cnt++;
			isBridge[u] = false;
		}
		u = par[u];
	}
	while(dfn[u] < dfn[v]){
		if(isBridge[v]){
			cnt++;
			isBridge[v] = false;
		}
		v = par[v];
	}
	while(u != v){
		if(isBridge[u]){
			isBridge[u] = false;
			cnt++;
		}
		if(isBridge[v]){
			isBridge[v] = false;
			cnt++;
		}
		u = par[u];
		v = par[v];
	}
	return cnt;
}

void read()
{
	for(int i=0;i<edges;i++){
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}	
}

void dfs(int u, int father)
{
	dfn[u] = low[u] = ++timeCnt;
	for(int i=head[u];~i;i=edge[i].next){
		int v = edge[i].to;
		if(!dfn[v]){
			dfs(v, u);
			par[v] = u;
			low[u] = min(low[u], low[v]);
			if(low[v] > dfn[u]){
				isBridge[v] = true;//记录桥的位置
				bridgeCnt++;
			}
		}else if(v != father){
			low[u] = min(low[u], dfn[v]);
		}
	}
}

int main(void)
{
	while(~scanf("%d%d", &vertexs, &edges)){
		init();
		read();
		dfs(1, 1);
		int questNum;
		scanf("%d", &questNum);
		while(questNum--){
			int u, v;
			scanf("%d%d", &u, &v);
			bridgeCnt -= LCA(u, v);
			printf("%d\n", bridgeCnt);
		}
	}
    return 0;
}