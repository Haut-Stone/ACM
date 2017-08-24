/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
*
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-22 11:12:17
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-24 13:08:15
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

const int N = 100010;
const int INF = 0x3f3f3f3f;

int vertexs, edges;
int minEdge = INF;

struct Node
{
	int next;
	int to;
	int w;//有权值的话，这一句启用
}edge[N*6];

int vis[N];
int dis[N];
int head[N];
int pre[N];//记录路径的数组
int cnt;

void add(int u, int v, int w)//存一条以u为起点,v为终点,w为边权值的有向边。
{
	edge[cnt].w = w;
	edge[cnt].to = v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

void init()
{
	cnt = 0;
	memset(head, -1, sizeof(head));
	memset(edge, 0, sizeof(edge));
}


int dijkstraListHeap(int beginX, int endX)
{	
	int minVertex;
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > heap;//一个最小堆

	//初始化
	for(int i=1;i<=vertexs;i++){
		dis[i] = INF;//起始距离初始化为INF
		vis[i] = 0;
		pre[i] = dis[i] != INF && i != beginX ? beginX : -1;//想将所有有链接的点的前一个点，设为出发点
	}

	dis[beginX] = 0;
	heap.push(make_pair(dis[beginX], beginX));//开始的点入队

	while(!heap.empty()){
		minVertex = heap.top().second;
		heap.pop();

		if(vis[minVertex]) continue;//如果这个点之前没有被访问过
		vis[minVertex] = 1;

		int u = minVertex;
		for(int i=head[u];~i;i=edge[i].next){//遍历最小点所连的所有边
			int v = edge[i].to;
			int w = edge[i].w;
			if(!vis[v]){//如果这个点未被访问过
				if(dis[v] > dis[u] + w){
					dis[v] = dis[u] + w;
					pre[v] = u;
					heap.push(make_pair(dis[v], v));//如果路径可以变小则压进去
				}
			}
		}
	}
	return dis[endX];
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while(T--){
		init();
		scanf("%d%d", &vertexs, &edges);
		int u, v, w;
		for(int i=1;i<=edges;i++){
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
			add(v, u, w);
		}
		int ansA = dijkstraListHeap(1, vertexs);
		int now = vertexs;
		while(pre[now] != -1){
			for(int i=head[now];~i;i=edge[i].to){
				int v = edge[i].to;
				int w = edge[i].w;
				if(v == pre[now]){
					minEdge = min(w, minEdge);
					break;
				}
			}
			now = pre[now];
		}
		int ansB = dijkstraListHeap(1, vertexs);
		printf("%d\n", min(ansB, ansA+2*minEdge));
	}
	return 0;
}