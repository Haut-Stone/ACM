/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-23 10:12:57
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-23 10:14:00
*/

//虽是模版题，但是初次写其实还是觉得不是很简单啊

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

const int N = 110;
const int INF = 0x3f3f3f3f;

struct Node
{
	int x;
	int y;
};

Node man[N], home[N];
int numMan, numHome, minCost;
int cost[N][N];
int res[N][N];
int source, sink;
int dis[N], parent[N];

void spfa()
{
	queue<int> Q;
	int v;
	bool vis[N];

	memset(vis, false, sizeof(vis));
	memset(parent, -1, sizeof(parent));
	for(int i=source;i<=sink;i++){
		dis[i] = INF;
	}

	Q.push(source);
	dis[source] = 0;
	vis[source] = true;

	while(!Q.empty()){
		v = Q.front();
		Q.pop();
		vis[v] = false;

		for(int i=source;i<=sink;i++){
			if(res[v][i] && dis[v] + cost[v][i] < dis[i]){
				dis[i] = dis[v] + cost[v][i];
				parent[i] = v;
				if(!vis[i]){
					Q.push(i);
					vis[i] = true;
				}	
			}
		}
	}
}

void MCMF()
{
	int v;
	minCost = 0;

	while(1){
		spfa();
		if(parent[sink] == -1) break;
		v = sink;
		while(parent[v] != -1){
			res[parent[v]][v] -= 1;
			res[v][parent[v]] += 1;
			v = parent[v];
		}
		minCost += dis[sink];
	}
}

int main(void)
{
	int n, m;
	char s[N];

	while(~scanf("%d%d", &n, &m)){
		if(n == 0 || m == 0) break;
		getchar();
		numHome = numMan = 0;
		for(int i=1;i<=n;i++){
			gets(s);
			for(int j=0;j<m;j++){
				if(s[j] == 'm'){
					man[numMan].x = i;
					man[numMan++].y = j+1;
				}else if(s[j] == 'H'){
					home[numHome].x = i;
					home[numHome++].y = j+1;
				}
			}
		}
		memset(cost, 0, sizeof(cost));
		memset(res, 0, sizeof(res));

		source = 0;
		sink = numHome + numMan + 1;

		//连源点和人
		for(int i=0;i<numMan;i++){
			res[source][i+1] = 1;
		}

		//连人和房子
		for(int i=0;i<numMan;i++){
			for(int j=0;j<numHome;j++){
				res[i+1][numMan+j+1] = 1;
				cost[i+1][numMan+j+1] = abs(man[i].x - home[j].x)+abs(man[i].y - home[j].y);
				cost[numMan+j+1][i+1] = -cost[i+1][numMan+j+1];
			}
		}

		//连汇点和房子
		for(int i=0;i<numHome;i++){
			res[i+1+numMan][sink] = 1;
		}

		//最小费用最大流
		MCMF();
		printf("%d\n", minCost);
	}
	return 0;
}