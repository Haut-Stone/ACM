/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-24 18:00:15
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-24 21:58:10
*/

//POJ 2349
//注意节点的序号从1开始
//建完边后每次新加入边时， 记录改变的长度，因为本来就是按顺序加入的，所以直接输出相应位置的结果就好了。
//这题错了好几次，因为存边的数组从1开始所以错的，但是不明白是为什么。。。

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
using namespace std;

#define INPUT_TEST freopen("in.txt", "r", stdin)

const int N = 550;

int parents[N];
int edgeNumber;
int SNumber;
int PNumber;
int T;

double x, y;
double dis[N];

struct Edge
{
	int begin;
	int end;
	double distance;
}edge[500005];

struct Node
{
	double x;
	double y;
}station[N];

//比较函数
bool cmp(Edge a, Edge b)
{	
	return a.distance < b.distance;
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

//初始化并查集
void init()
{
	for(int i=1;i<=PNumber;i++){//相当于声明了27个没有叶子的树。
		parents[i] = i;
	}
}

bool hadUnite(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x == y){
		return true;
	}else{
		parents[x] = y;//如果不是同一个集合的，则将两个点连起来。
	}
	return false;
}

void kruskal()
{
	int k = 0;
	sort(edge, edge+edgeNumber, cmp);//序号从1开始
	init();
	for(int i=0;i<edgeNumber;i++){
		if(hadUnite(edge[i].begin, edge[i].end)){
			continue;
		}else{
			dis[k++] = edge[i].distance;
		}
	}
}

double getDis(double x1, double x2, double y1, double y2)
{
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

void read()
{
	cin>>SNumber>>PNumber;
	for(int i=1;i<=PNumber;i++){
		scanf("%lf %lf", &station[i].x, &station[i].y);
	}
}

int main(void)
{
	// INPUT_TEST;

	cin>>T;
	while(T--){
		read();
		edgeNumber = 0;
		//建边，注意是无向边，边的序号从一开始。
		for(int i=1;i<=PNumber;i++){
			for(int j=i+1;j<=PNumber;j++){
				double w = getDis(station[i].x, station[j].x, station[i].y, station[j].y);
				edge[edgeNumber].begin = i;
				edge[edgeNumber].end = j;
				edge[edgeNumber++].distance = w;
				edge[edgeNumber].begin = j;
				edge[edgeNumber].end = i;
				edge[edgeNumber++].distance = w;
			}
		}
		kruskal();//开始生成树。
		printf("%.2f\n", dis[PNumber - SNumber - 1]);
	}
    return 0;
}