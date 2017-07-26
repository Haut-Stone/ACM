/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-07 16:25:17
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-07 18:30:05
*/

//HDU 4635
//给你一个有向图，问你最多能添加多少条边，使得这个图依然不是强连通的。注意这次是有向图
//正向思考的话，比较的困难，那么就逆向考虑，最少去掉几条边，使这个图不是强连通的。
//感觉这部分的题真的是好难啊。。。还是去写搜索比较简单一点。

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

const int N = 100010;
const int INF = 99999999;

struct Node
{
	int to;
	int next;
}edge[N*10];

int vertexs, edges;
int in[N], out[N];
int pointSum[N];
int dfn[N], low[N];
int iStack[N], inStack[N], top;
int belong[N];
int head[N];
int blockCnt, timeCnt, bridgeCnt, edgeCnt;

void add(int u, int v)
{
	edge[edgeCnt].to = v;
	edge[edgeCnt].next = head[u];
	head[u] = edgeCnt++;
}

void tarjan(int u)
{
	low[u] = dfn[u] = ++timeCnt;
	iStack[top++] = u;
	inStack[u] = 1;

	for(int i=head[u];i!=-1;i=edge[i].next){
		int v = edge[i].to;
		if(!dfn[v]){
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}else if(inStack[v]){
			low[u] = min(low[u], dfn[v]);
		}
	}

	if(dfn[u] == low[u]){
		int temp = -1;
		blockCnt++;
		while(temp != u){
			temp = iStack[--top];
			inStack[temp] = 0;
			belong[temp] = blockCnt;
			pointSum[blockCnt]++;
		}
	}
}

void init()
{
	memset(in, 0, sizeof(in));
	memset(out, 0, sizeof(out));
	memset(pointSum, 0, sizeof(pointSum));
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(iStack, 0, sizeof(iStack));
	memset(inStack, 0, sizeof(inStack));
	memset(belong, 0, sizeof(belong));
	memset(head, -1, sizeof(head));
	top = 0;
	blockCnt = timeCnt = bridgeCnt = edgeCnt = 0;
}

int main(void)
{
	int T;
	cin>>T;
	for(int cas=1;cas<=T;cas++){
		init();
		scanf("%d%d", &vertexs, &edges);
		for(int i=0;i<edges;i++){
			int u, v;
			scanf("%d%d", &u, &v);
			add(u, v);
		}

		for(int i=1;i<=vertexs;i++){
			if(!dfn[i]) tarjan(i);//缩点
		}

		if(blockCnt == 1){//如果是强连通图的话就直接输出
			printf("Case %d: -1\n", cas);
			continue;
		}

		//遍历求度
		for(int u=1;u<=vertexs;u++){
			for(int j=head[u];~j;j=edge[j].next){
				int v = edge[j].to;
				if(belong[u] != belong[v]){
					out[belong[u]]++;
					in[belong[v]]++;
				}
			}
		}

		int temp = INF;
		for(int i=1;i<=blockCnt;i++){
			if(in[i] == 0 || out[i] == 0){
				temp = min(temp, pointSum[i]);
			} 
		}

		int ans = vertexs * (vertexs - 1);
		ans -= edges;
		ans -= temp * (vertexs - temp);
		printf("Case %d: %d\n", cas, ans);
	}
    return 0;
}