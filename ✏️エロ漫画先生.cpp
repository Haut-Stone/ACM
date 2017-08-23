/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-04 20:46:48
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-21 17:38:10
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

const int M = 20;
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
	printf("bfs : : begin\n");
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
	printf("bfs : : end\n");
}

int dfs(int v, int t, int f)
{
	if(v == t) return f;
	for(int i=0;i<iMap[v].size();i++){
		Edge &e = iMap[v][i];
		if(e.cap > 0 && level[v] < level[e.to]){
			printf("dfs(%d %d %d)\n", e.to, t, min(f, e.cap));
			int d = dfs(e.to, t, min(f, e.cap));
			if(d > 0){
				e.cap -= d;
				iMap[e.to][e.rev].cap += d;
				printf("out : : dfs(%d %d %d)\n", e.to, t, min(f, e.cap));
				return d;
			}
		}
	}
	printf("out\n");
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
		int s = 0;
		int t = 4;
		addEdge(0, 1, 10);
		addEdge(0, 2, 2);
		addEdge(1, 2, 6);
		addEdge(1, 3, 6);
		addEdge(3, 2, 3);
		addEdge(3, 4, 8);
		addEdge(2, 4, 5);
		printf("%d\n", maxFlow(s, t));
	
	return 0;
}