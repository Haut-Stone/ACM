/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-04 18:59:01
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-06 19:12:27
*/

//POJ 3177
//这道题集，判断割边， 缩点，计算顶点的度为一体，是一道很好的模版题。

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

const int N = 10010;
const int M = 100010;

struct Node
{
	int next;
	int to;
	bool isCut;
	int f;
}edge[M];

int dfn[N], low[N];//时间戳
int iStack[N], top, instack[N];//手写栈
int belong[N];//染色
int head[N];//邻接表
int edges, vertexs;
int edgeCnt, blockCnt, timeCnt;//邻接表计数器，强连通图个数计数器，点的访问次序计数器。
int bridgeNumber;
int degree[N];//顶点的度

void add(int u, int v)//存一条以u为起点,v为终点,w为边权值的有向边。
{
	edge[edgeCnt].to = v;
	edge[edgeCnt].next = head[u];
	head[u] = edgeCnt;
	edgeCnt++;
}

void init()
{
	top = 0;
	bridgeNumber = 0;
	timeCnt = edgeCnt = blockCnt = 0;
	memset(head, -1, sizeof(head));
	memset(edge, 0, sizeof(edge));
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(instack, 0, sizeof(instack));
	memset(belong, 0, sizeof(belong));
	memset(degree, 0, sizeof(degree));
}

void tarjan(int u, int father)
{
	iStack[top++] = u;
	instack[u] = 1;
	dfn[u] = low[u] = ++timeCnt;

	for(int i=head[u];~i;i=edge[i].next){//依次访问相连的点
		int v = edge[i].to;

		if(edge[i].f) continue;
		edge[i].f = edge[i^1].f = 1;

		if(!dfn[v]){
			tarjan(v, u);
			low[u] = min(low[u], low[v]);//更新一下最小值
			if(low[v] > dfn[u]){//如果回不到原来，说明这条边是一个割边
				bridgeNumber++;
				edge[i].isCut = true;
				edge[i^1].isCut = true;//不过这里的异或不是很懂啊。。。。。
			}
		}else if(instack[v] && dfn[v] < low[u]){//装在一个栈中的就说明都是同一个联通分量里面的。
			low[u] = dfn[v];
		}
	}

	if(dfn[u] == low[u]){
		blockCnt += 1;
		int t;
		do{
			t = iStack[--top];//把和该点相关的节点全部弹出。
			instack[t] = 0;
			belong[t] = blockCnt;
		}while(t != u);
	}
}


int main(void)
{
	// INPUT_TEST;

	while(~scanf("%d%d", &vertexs, &edges)){
		init();
		for(int i=0;i<edges;i++){
			int u, v;
			scanf("%d%d", &u, &v);
			add(u, v);
			add(v, u);
		}
		tarjan(1, -1);

		//缩点，计算度，简直妙啊！
		for(int i=1;i<=vertexs;i++){
			for(int j=head[i];j!=-1;j=edge[j].next){
				if(edge[j].isCut) degree[belong[i]]++;//这里成功的用belong数组，将一堆连通的点，缩成了一个点。
			}
		}
		int ans = 0;
		for(int i=1;i<=blockCnt;i++){
			if(degree[i] == 1) ans++;
		}
		printf("%d\n", (ans + 1)/2);
	}
    return 0;
}