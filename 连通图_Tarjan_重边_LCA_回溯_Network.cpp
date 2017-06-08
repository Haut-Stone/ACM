/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-06-04 10:37:56
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-06-07 16:20:50
 */

//POJ 3694
//有了之前的基础，今天这道题应该好做一点了。

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

const int N = 200010;

struct Node
{
	int next;
	int to;
	int isCut;
	int f;
}edge[N*10];

int vertexs, edges;

int dfn[N], low[N];
int inStack[N], iStack[N], top;
int father[N];
int belong[N];
int isbridge[N];
int head[N];
int edgeCnt, timeCnt, bridgeCnt, blockCnt;

void add(int u, int v)//存一条以u为起点,v为终点,w为边权值的有向边。
{
	edge[edgeCnt].to = v;
	edge[edgeCnt].next = head[u];
	head[u] = edgeCnt++;
}

void init()
{
	top = 0;
	edgeCnt = timeCnt = bridgeCnt = blockCnt = 0;
	memset(head, -1, sizeof(head));
	memset(inStack, 0, sizeof(inStack));
	memset(iStack, 0, sizeof(iStack));
	memset(edge, 0, sizeof(edge));
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(father, 0, sizeof(father));
	memset(belong, 0, sizeof(belong));
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

void tarjan(int u)
{
	iStack[top++] = u;
	inStack[u] = 1;
	dfn[u] = low[u] = ++timeCnt;

	for(int i=head[u];~i;i=edge[i].next){//依次访问相连的点
		int v = edge[i].to;

		if(edge[i].f) continue;
		edge[i].f = edge[i^1].f = 1;//这里来标记一条边是不是通往父亲点的边。

		if(!dfn[v]){
			father[v] = u;
			tarjan(v);
			low[u] = min(low[u], low[v]);//更新一下最小值
			if(low[v] > dfn[u]){//如果回不到原来，说明这条边是一个割边
				bridgeCnt++;
				isbridge[v] = true;
			}
		}else if(inStack[v] && dfn[v] < low[u]){//装在一个栈中的就说明都是同一个联通分量里面的。
			low[u] = dfn[v];
		}
	}

	if(dfn[u] == low[u]){
		blockCnt += 1;
		int t;
		do{
			t = iStack[--top];//把和该点相关的节点全部弹出。
			inStack[t] = 0;
			belong[t] = blockCnt;
		}while(t != u);
	}
}

void LCA(int u, int v)
{
	if(dfn[u] < dfn[v]) swap(u, v);
	while(dfn[u] > dfn[v]){
		if(isbridge[u]) bridgeCnt--;
		isbridge[u] = false;
		u = father[u];
	}
	while(u != v){
		if(isbridge[u]) bridgeCnt--;
		if(isbridge[v]) bridgeCnt--;
		isbridge[u] = isbridge[v] = false;
		u = father[u];
		v = father[v];
	}
}

int main(void)
{
	// INPUT_TEST;
	
	int cas = 1;

	while(~scanf("%d%d", &vertexs, &edges) && (vertexs || edges)){
		init();
		read();
		int root = 1;
		father[root] = 1;
		tarjan(root);
		int questNum;
		scanf("%d", &questNum);
		printf("Case %d:\n", cas++);
		while(questNum--){
			int u, v;
			scanf("%d%d", &u, &v);
			LCA(u,v);
			printf("%d\n", bridgeCnt);
		}
	}
	return 0;
}
