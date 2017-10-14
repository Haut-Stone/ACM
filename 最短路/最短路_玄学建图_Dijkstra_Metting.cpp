/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-14 16:13:46
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-14 16:13:56
*/

//https://cn.vjudge.net/contest/191131#problem/M

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

const int N = 1e6 + 10;
const long long INF = 1e17+10;

struct Node
{
	int next;
	int to;
	long long w;//有权值的话，这一句启用
}edge[N*4];

int vis[N];
long long book[N];
long long dis[2][N];
int head[N];

int vertexs;
int n, m;
int iTime, number, soloPoint;
int cnt;

void add(int u, int v, long long w)//存一条以u为起点,v为终点,w为边权值的有向边。
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


long long dijkstraListHeap(int beginX, int endX, int index)
{
	int minVertex;
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > heap;//一个最小堆
	
	//初始化
	for(int i=1;i<=vertexs;i++){
		dis[index][i] = INF;//起始距离初始化为INF
		vis[i] = 0;
	}
	
	dis[index][beginX] = 0;
	heap.push(make_pair(dis[index][beginX], beginX));//开始的点入队
	
	while(!heap.empty()){
		minVertex = heap.top().second;
		heap.pop();
		
		if(vis[minVertex]) continue;//如果这个点之前没有被访问过
		vis[minVertex] = 1;
		
		int u = minVertex;
		for(int i=head[u];~i;i=edge[i].next){//遍历最小点所连的所有边
			int v = edge[i].to;
			long long w = edge[i].w;
			if(!vis[v]){//如果这个点未被访问过
				if(dis[index][v] > dis[index][u] + w){
					dis[index][v] = dis[index][u] + w;
					heap.push(make_pair(dis[index][v], v));//如果路径可以变小则压进去
				}
			}
		}
	}
	return dis[index][endX];
}

int main(void)
{
	int T;
	scanf("%d", &T);
	for(int cas=1;cas<=T;cas++){
		init();
		scanf("%d%d", &n, &m);
		for(int i=1;i<=m;i++){
			scanf("%d%d", &iTime, &number);
			for(int j=1;j<=number;j++){
				scanf("%d", &soloPoint);
				int temp = n + i;
				add(temp, soloPoint, iTime);
				add(soloPoint, temp, iTime);
			}
		}
		vertexs = m+n;
		dijkstraListHeap(1, vertexs, 0);
		dijkstraListHeap(n, vertexs, 1);
		long long iMin = INF;
		int flag = 0;
		for(int i=1;i<=n;i++){
			if(iMin > max(dis[0][i]/2, dis[1][i]/2)){
				flag = 1;
				iMin = max(dis[0][i]/2, dis[1][i]/2);
				book[i] = iMin;
			}else if(iMin == max(dis[0][i]/2, dis[1][i]/2)) {
				book[i] = iMin;
				flag++;
			}
		}
		if(iMin >= INF/2){
			printf("Case #%d: Evil John\n", cas);
		}else{
			printf("Case #%d: %lld\n", cas, iMin);
			for(int i=1;i<=n;i++){
				if(book[i] == iMin){
					if(flag != 1){
						printf("%d ", i);
						flag--;
					}else{
						printf("%d\n", i);
						flag--;
					}
				}
			}
		}
	}
	return 0;
}
