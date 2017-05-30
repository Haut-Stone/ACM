/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-25 19:15:13
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-25 20:24:24
*/

//POJ 1751  这道题居然是单实例，多实例居然是超时。。。
//题意:给出n个城市的坐标，以及几个想通了的城市的编号，表示这两个城市之间的高速公路还是通着的，问将所有城市都连通可以怎样来构建剩下需要构建的路。使得花费尽可能的小，输出可以构建并达到目的的任何一个结果

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

const int N = 1010;
const int LEN = 10000;

int parents[LEN];
int x[N];
int y[N];
int edgeNumber;
int vertexNumber;
int hadEdgeNumber;

struct Edge
{
	int u;
	int v;
	int w;
}edge[N*N];

//比较函数
bool cmp(Edge a, Edge b)
{	
	return a.w < b.w;
}

//并查集的查找
int find(int x)
{
	if(parents[x] == x){//到达根结点的时候
		return x;
	}else{
		return parents[x] = find(parents[x]);
	}	
}

bool hadUnite(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x == y){
		return true;
	}else{
		parents[y] = x;//如果不是同一个集合的，则将两个点连起来。
	}
	return false;
}

void kruskal()
{
	sort(edge, edge+edgeNumber, cmp);
	for(int i=0;i<edgeNumber;i++){
		if(hadUnite(edge[i].u, edge[i].v)){
			continue;
		}else{
			printf("%d %d\n", edge[i].u, edge[i].v);
		}
	}
}

void read()
{
	cin>>vertexNumber;
	for(int i=1;i<=vertexNumber;i++){
		scanf("%d%d", &x[i], &y[i]);
		parents[i] = i;
	}
	cin>>hadEdgeNumber;
	while(hadEdgeNumber--){
		int a, b;
		scanf("%d%d", &a, &b);
		hadUnite(a,b);
	}
}

int getDis(int x1, int x2, int y1, int y2)
{
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main(void)
{
	// INPUT_TEST;

	read();

	edgeNumber = 0;
	for(int i=1;i<=vertexNumber;i++){
		for(int j=1;j<=vertexNumber;j++){//构造所有的边，无向边
			edge[edgeNumber].u = i;
			edge[edgeNumber].v = j;
			edge[edgeNumber++].w = getDis(x[i], x[j], y[i], y[j]);
		}
	}
	kruskal();
    return 0;
}