/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-12 15:43:35
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-12 16:02:25
*/

//POJ 3281
//这是我做的第一道网络流的题，可以说是一道模版题吧。先随便来一发KB的代码熟悉一下

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

const int MAXN = 500;
const int INF = 0x3fffffff;

int g[MAXN][MAXN];//边的容量，没有边的初始为0
int path[MAXN], flow[MAXN], start, iEnd;
int n;//点的个数，编号0-n.n包括了源点和汇点

queue<int>q;

int bfs()
{
	int i, t;
	while(!q.empty()) q.pop();//清空队列
	memset(path, -1, sizeof(path));
	path[start] = 0;
	flow[start] = INF;//源点可以有无穷的流进去
	q.push(start);
	while(!q.empty()){
		t = q.front();
		q.pop();
		if(t == iEnd) break;
		//枚举所有的点，如果点的编号起始点有变化，可以改这里
		for(i=0;i<=n;i++){
			if(i != start && path[i] == -1 && g[t][i]){
				flow[i] = flow[t] < g[t][i] ? flow[t]:g[t][i];
				q.push(i);
				path[i] = t;
			}
		}
	}
	if(path[iEnd] == -1) return -1;
	return flow[iEnd];
}

int Edmonds_Karp()
{
	int max_flow = 0;
	int step, now, pre;
	while((step = bfs()) != -1){
		max_flow += step;
		now = iEnd;
		while(now != start){
			pre = path[now];
			g[pre][now] -= step;
			g[now][pre] += step;
			now = pre;
		}
	}
	return max_flow;
}

int main(void)
{
	int N, F, D;
	while(scanf("%d%d%d", &N, &F, &D) != EOF){
		memset(g, 0, sizeof(g));
		n = F + D + 2*N + 1;
		start = 0;
		iEnd = n;
		for(int i=1;i<=F;i++){
			g[0][i] = 1;
		}
		for(int i=F+2*N+1;i<=F+2*N+D;i++){
			g[i][n] = 1;
		}
		for(int i=1;i<=N;i++){
			g[F+2*i-1][F+2*i] = 1;
		}
		int k1, k2;
		int u;
		for(int i=1;i<=N;i++){
			scanf("%d%d", &k1, &k2);
			while(k1--){
				scanf("%d", &u);
				g[u][F+2*i-1] = 1;
			}
			while(k2--){
				scanf("%d", &u);
				g[F+2*i][F+2*N+u] = 1;
			}
		}
		printf("%d\n", Edmonds_Karp());
	}
	return 0;
}