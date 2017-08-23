/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-31 22:10:50
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-21 20:39:18
*/

//好难啊。。这题。。
//

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

const int N = 210;
const int INF = 99999999;

//标准的链式前向星实现
struct Node
{
	int u;
	int v;
	int w;
	int next;
}edge[N*N];

int vertexs;
int edges;

int dis[N];
int head[N];
int vis[N];
int value[N];
int c[N];
int cnt;
int u, v;
int T;

void add(int u, int v, int w)//存一条以u为起点,v为终点,w为边权值的有向边。
{
	edge[cnt].u = u;
	edge[cnt].v = v;
	edge[cnt].w = w;
	edge[cnt].next = head[u];
	head[u] = cnt;
	cnt++;
}

void init()
{
	cnt = 0;
	memset(head, -1, sizeof(head));
	memset(edge, 0, sizeof(edge));
}

int spfa(int beginX, int endX)
{
	queue <int> Q;
	int u;

	for(int i=1;i<=vertexs;i++){
		dis[i] = INF;
		vis[i] = 0;
	}
	vis[beginX] = 1;
	dis[beginX] = 0;
	
	Q.push(beginX);
	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		vis[u] = 0;

		for(int i=head[u];~i;i=edge[i].next){
			int v = edge[i].v;
			if(dis[v] > dis[u] + edge[i].w){
				dis[v] = dis[u] + edge[i].w;
				if(!vis[v]){
					vis[v] = 1;
					Q.push(v);
				}
			}
		}
	}
	return dis[endX];
}

int main(void)
{
	cin>>T;
	for(int cas=1;cas<=T;cas++){
		init();
		cin>>vertexs;
		for(int i=1;i<=vertexs;i++){
			scanf("%d", &value[i]);
		}
		cin>>edges;
		cnt = 0;
		for(int i=0;i<edges;i++){
			scanf("%d%d", &u, &v);
			int w = (value[v] - value[u])*(value[v] - value[u])*(value[v] - value[u]);
			add(u, v, w);
		}

		int Q;
		cin>>Q;
		for(int i=0;i<Q;i++){
			scanf("%d", &c[i]);
		}
		printf("%d\n", cas);
		spfa(vertexs, Q);
	}
	return 0;
}