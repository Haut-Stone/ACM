/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-28 15:45:11
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-30 10:31:33
*/

//POJ 3159
//这题数据过于庞大不能用队列，要用手工写栈才不会超时， but...why?
//同样这道题要用链式前向星，而不能用vector

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

const int N = 50005;
const long long INF = 1000000007;

//标准的链式前向星实现
struct Node
{
	int to;
	int next;
	int w;
}edge[N*3];

int vertexs;
int edges;

int dis[N];
int head[N];
int vis[N];
int cnt;
int u, v, w;

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
	memset(head, -1, sizeof(head));
	memset(edge, 0, sizeof(edge));
}

int spfa(int beginX, int endX)
{
	int u;
	int S[N];
	int top = 0;

	for(int i=1;i<=vertexs;i++){
		dis[i] = INF;
		vis[i] = 0;
	}

	
	vis[beginX] = 1;
	dis[beginX] = 0;
	
	S[++top] = beginX;
	while(top){
		u = S[top--];
		vis[u] = 0;

		for(int i=head[u];~i;i=edge[i].next){
			int v = edge[i].to;
			if(dis[v] > dis[u] + edge[i].w){
				dis[v] = dis[u] + edge[i].w;
				if(!vis[v]){
					vis[v] = 1;
					S[++top] = v;
				}
			}
		}
	}
	return dis[endX];
}

int main(void)
{	
	// INPUT_TEST;

	cin>>vertexs>>edges;
	init();
	while(edges--){
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
	}
	printf("%d\n", spfa(1, vertexs));
    return 0;
}