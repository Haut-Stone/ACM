/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-21 11:17:12
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-21 16:52:45
*/

//dinic的模版题，就是建图的时候会有一点小技巧
//或者说可以理解成这题是一道特殊的网络流，相当于寻找多条不重复的最短路径。
//http://blog.csdn.net/huangshuai147/article/details/51354673
//具体的可以看白书(白书上有不少错的)

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

const int M = 100010;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int to;
	int cap;
	int rev;
	Edge();
	Edge(int T, int C, int R){
		to = T;
		cap = C;
		rev = R;
	}
};

vector<Edge> iMap[M];
int level[M];
int iter[M];
int N, F, D;

void addEdge(int from, int to, int cap)
{
	iMap[from].push_back(Edge(to, cap, (int)iMap[to].size()));
	iMap[to].push_back(Edge(from, 0, (int)iMap[from].size() - 1));
}

void bfs(int s)
{
	memset(level, -1, sizeof(level));
	queue<int> Q;
	level[s] = 0;
	Q.push(s);
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		for(int i=0;i<iMap[v].size();i++){
			Edge &solo = iMap[v][i];
			if(solo.cap > 0 && level[solo.to] < 0){
				level[solo.to] = level[v] + 1;
				Q.push(solo.to);
			}
		}
	}
}

int dfs(int v, int t, int f)
{
	if(v == t) return f;
	for(int i=0;i<iMap[v].size();i++){
		Edge &e = iMap[v][i];
		if(e.cap > 0 && level[v] < level[e.to]){
			int d = dfs(e.to, t, min(f, e.cap));
			if(d > 0){
				e.cap -= d;
				iMap[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

int maxFlow(int s, int t)
{
	int flow = 0;
	while(1){
		bfs(s);//分层
		if(level[t] < 0){
			return flow;
		}
		int f;
		while((f = dfs(s, t, INF)) > 0){//增广
			flow += f;
		}
	}
}

int main(void)
{
	while(~scanf("%d%d%d", &N, &F, &D)){
		int food, drink, v;
		for(int i=0;i<M;i++){
			iMap[i].clear();
		}
		for(int i=1;i<=N;i++){
			scanf("%d%d", &food, &drink);
			for(int j=1;j<=food;j++){
				scanf("%d", &v);
				addEdge(v, F+i, 1);//建左边的交叉边
			}
			for(int j=1;j<=drink;j++){
				scanf("%d", &v);
				addEdge(F+N+i, F+N+N+v, 1);//建右边的交叉边
			}
		}
		int s = 0;
		int t = N+N+F+D+1;

		for(int i=1;i<=F;i++){
			addEdge(s, i, 1);//源点和所有的食物
		}
		for(int i=1;i<=N;i++){
			addEdge(F+i, F+i+N, 1);//左边的牛和右边的牛
		}
		for(int i=1;i<=D;i++){
			addEdge(F+N+N+i, t, 1);//所有饮料和汇点
		}
		printf("%d\n", maxFlow(s, t));
	}
	return 0;
}