/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-31 16:49:49
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-31 22:08:27
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
using namespace std;

const int N = 110;

int parents[N];
int pointsNumber;
int edgeNumber;
double ans;

struct Node
{
	double x;
	double y;
	double z;
	double r;
}points[N];

struct Edge
{
	int begin;
	int end;
	double distance;
}edges[N*N];

bool cmp(Edge a, Edge b)
{
	return a.distance < b.distance;
}

double computingDistance(Node v1, Node v2)
{
	double temp;
	temp = sqrt((v1.x-v2.x)*(v1.x-v2.x) + (v1.y-v2.y)*(v1.y-v2.y) + (v1.z-v2.z)*(v1.z-v2.z)) - v1.r - v2.r; 
	if(temp < 0){
		return 0;
	}else{
		return temp;//算出两点间的距离。
	}
}

int find(int x)
{
	if(parents[x] == x){
		return x;
	}else{
		return parents[x] = find(parents[x]);
	}
}

void read()
{
	edgeNumber = 0;
	for(int i=1;i<=pointsNumber;i++){
		scanf("%lf%lf%lf%lf", &points[i].x, &points[i].y, &points[i].z, &points[i].r);
		for(int j=1;j<i;j++){//将点的数据加工成边的数据。
			edges[++edgeNumber].begin = j;
			edges[edgeNumber].end = i;
			edges[edgeNumber].distance = computingDistance(points[i], points[j]);
		}
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

void init()
{
	for(int i=1;i<=pointsNumber;i++){
		parents[i] = i;
	}
}

void kruskal()
{
	sort(edges+1, edges+1+edgeNumber, cmp);
	init();
	ans = 0;
	for(int i=1;i<=edgeNumber;i++){
		if(hadUnite(edges[i].begin, edges[i].end)){
			continue;
		}else{
			ans += edges[i].distance;//这里在hadUnite函数里已经合并过了。这里不用再合并。
		}
	}
}

int main(void)
{
	while(cin>>pointsNumber, pointsNumber){
		read();
		kruskal();
		printf("%.3f\n", ans);
	}
	return 0;
}

