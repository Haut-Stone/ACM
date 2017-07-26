/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-28 14:47:34
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-28 15:25:23
*/

//POJ 1511
//题意:给出n个点和n条有向边，求所有点到原点1的来回最短路之和。
//当数据量太大的时候，其他算法都用不了了，只剩Spfa了

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

const int N = 1000010;
const long long INF = 0xFFFFFFFF;

//标准的链式前向星实现
struct Node
{
	int to;
	int next;
	int w;
}edge[2][N];//这里的第一维表示来和去的两种不同的状态

int T;
long long dis[N];
long long ans;
int vertexs;
int edges;
int head[2][N];
int vis[N];
int u, v, w;

void spfa(int status, int beginX)
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

		for(int i=head[status][u];~i;i=edge[status][i].next){
			int v = edge[status][i].to;
			if(dis[v] > dis[u] + edge[status][i].w){
				dis[v] = dis[u] + edge[status][i].w;
				if(!vis[v]){
					vis[v] = 1;
					Q.push(v);
				}
			}
		}
	}
}

int main(void)
{
	// INPUT_TEST;

	cin>>T;
	while(T--){
		scanf("%d%d", &vertexs, &edges);
		for(int i=1;i<=vertexs;i++){
			head[0][i] = -1;
			head[1][i] = -1;
		}

		for(int i=0;i<edges;i++){
			scanf("%d%d%d", &u, &v, &w);
			edge[0][i].w = w;
			edge[0][i].to = v;
			edge[0][i].next = head[0][u];
			head[0][u] = i;
			edge[1][i].w = w;
			edge[1][i].to = u;
			edge[1][i].next = head[1][v];
			head[1][v] = i;
		}

		ans = 0;
		//一个来回
		for(int status=0;status<=1;status++){
			spfa(status, 1);
			for(int i=1;i<=vertexs;i++){
				ans += dis[i];
			}
		}
		printf("%lld\n", ans);
	}
    return 0;
}