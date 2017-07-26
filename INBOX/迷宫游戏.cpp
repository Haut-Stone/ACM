/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2016 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-17 13:58:07
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-17 21:38:52
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int N = 10010;
int value[N];
int timeUse[N][N];
int dis[N];//用于存储开始点到其他点的初始路程

int dijkstra();
//迷宫游戏，用了迪杰斯特拉算法。
//单元最短路问题
int main(void)
{
	int n, m;
	int x, y, z;
	int start, end;

	scanf("%d %d %d %d", &n, &m, &start, &end);
	for(int i=0;i<n;i++){
		scanf("%d", &value[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d %d %d", &x, &y, &z);
		timeUse[x][y] = z;
		if(x == start){//储存初始路程的估计值。
			dis[y] = z;
		}else if(y == start){
			dis[x] = z;
		}
	}
	dijkstra();
    return 0;
}
//TODO
int dijkstra()
{

	return 0;
}