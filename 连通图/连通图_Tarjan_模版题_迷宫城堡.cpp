/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-03 16:45:48
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-06 16:12:52
*/

//HDU 1269
//模版题

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
	int w;//有权值的话，这一句启用
}edge[M];


int dfn[N], low[N];//时间戳
int iStack[N], top, instack[N];//手写栈
int belong[N];//染色
int head[N];//邻接表
int edges, vertexs;
int cnt, scnt, tcnt;//邻接表计数器，强连通图个数计数器，点的访问次序计数器。
void add(int u, int v, int w)//存一条以u为起点,v为终点,w为边权值的有向边。
{
	edge[cnt].w = w;
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
	cnt++;
}

void init()
{
	cnt = 0;
	scnt = 0;
	top = 0;
	tcnt = 0;
	memset(head, -1, sizeof(head));
	memset(edge, 0, sizeof(edge));
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(instack, 0, sizeof(instack));
	memset(belong, 0, sizeof(belong));
}

void tarjan(int u)
{
	iStack[top++] = u;
	instack[u] = 1;
	dfn[u] = low[u] = ++tcnt;

	for(int i=head[u];~i;i=edge[i].next){//依次访问相连的点
		int v = edge[i].to;

		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[u], low[v]);//更新一下最小值
		}else if(instack[v] && dfn[v] < low[u]){//装在一个栈中的就说明都是同一个联通分量里面的。
			low[u] = dfn[v];
		}
	}

	if(dfn[u] == low[u]){
		scnt += 1;
		int t;
		do{
			t = iStack[--top];//把和该点相关的节点全部弹出。
			instack[t] = 0;
			belong[t] = scnt;
		}while(t != u);
	}
}

void solve()
{
	for(int i=1;i<=vertexs;i++){//遍历所有的点
		if(!dfn[i]) tarjan(i);
	}
}

int main(void)
{
	while(~scanf("%d%d", &vertexs, &edges) && (vertexs || edges)){
		init();
		for(int i=0;i<edges;i++){
			int u, v;
			scanf("%d%d", &u, &v);
			add(u, v, 1);
			add(v, u, 1);
		}
		solve();
		if(scnt == 1){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
    return 0;
}