/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-06 15:14:16
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-06 19:11:47
*/

//HDU 4612
//这题交了N次了，就是不对。。找了半天，一直以为是算法错了，结果实际上是建树的时候读错节点了，。。没救了。。
//双连通分量缩点 + 树的直径

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
const int M = 2000100;

struct Node
{
	int next;
	int to;
	int f;
}edge[M];

int head[N];//邻接表
int dfn[N], low[N];//时间戳
int iStack[N], top, vis[N];//手写栈
int belong[N];//染色
int inStack[N];
int edges, vertexs;
int edgeCnt, blockCnt, timeCnt;//邻接表计数器，强连通图个数计数器，点的访问次序计数器。
int bridgeNumber;

vector<int> TreeEdge[N];
int farthest;//最远的叶子节点
int ans;	

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
	memset(iStack, 0, sizeof(iStack));
	memset(low, 0, sizeof(low));
	memset(dfn, 0, sizeof(dfn));
	memset(belong, 0, sizeof(belong));
	memset(inStack, 0, sizeof(inStack));
	memset(edge, 0, sizeof(edge));
	for(int i=0;i<N;i++){
		TreeEdge[i].clear();
	}
}

void dfs(int k,int pre,int dep)
{
    vis[k]=1;
    if(dep>ans)
    {
        ans=dep;
        farthest=k;
    }
    for(int i=0; i<TreeEdge[k].size(); i++)
    {
        int v=TreeEdge[k][i];
        if(!vis[v])  dfs(v,k,dep+1);
    }
}

void tarjan(int u, int father)
{
	iStack[top++] = u;
	inStack[u] = 1;
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

int main(void)
{	
	while(~scanf("%d%d", &vertexs, &edges) && (vertexs || edges)){
		init();
		for(int i=0;i<edges;i++){
			int u, v;
			scanf("%d%d", &u, &v);
			add(u, v);
			add(v, u);
		}
		for(int i=1;i<=vertexs;i++){
			if(!dfn[i]) tarjan(i, i);//这里主要的目的是用Tarjan算法进行缩点。并求出桥的数量
		}
		for(int u=1;u<=vertexs;u++){
			for(int j=head[u];j!=-1;j=edge[j].next){
				int v = edge[j].to;
				int s = belong[u];
				int t = belong[v];
				if(s != t){
					TreeEdge[s].push_back(t);
					TreeEdge[t].push_back(s);
				}
			}
		}

		ans = farthest = 0;
		memset(vis, 0, sizeof(vis));
		vis[1] = 1;
		dfs(1, 1, 0);

		ans = 0;
		memset(vis, 0, sizeof(vis));
		vis[farthest] = 1;
		dfs(farthest, farthest, 0);

		printf("%d\n", bridgeNumber - ans);
	}
    return 0;
}