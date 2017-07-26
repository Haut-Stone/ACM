/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-01 20:41:26
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-03 16:38:50
*/

//POJ 1236
//第一次写连通图的题，练习一下算法。Tarjan算法基于dfs

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

const int N  = 200;

int n;
int iMap[N][N];
int outdegree[N];
int indegree[N];

int dfn[N];//时间戳
int low[N];//子树中最早的步数

int stap[N];//模拟栈
int stop;

bool instack[N];//记录是否在栈中
int iCount;//记录联通分量的个数
int cnt;//记录搜索的步数
int belong[N];//记录属于哪一个联通分量

void init()
{
	cnt = iCount = stop = 0;
	memset(instack, 0, sizeof(instack));
	memset(iMap, 0, sizeof(iMap));
	memset(dfn, 0, sizeof(dfn));
}

void output()
{
	int inZero = 0;
	int outZero = 0;
	for(int i=1;i<=n;i++){
		indegree[i] = outdegree[i] = 0;
	}
	//搜索出度和入度
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(iMap[i][j] && belong[i] != belong[j]){
				indegree[belong[j]]++;
				outdegree[belong[i]]++;
			}
		}
	}
	//找入度出度为0的点
	for(int i=1;i<=iCount;i++){
		if(!indegree[i]) inZero++;
		if(!outdegree[i]) outZero++;
	}
	//为零的时候要特判
	if(iCount == 1){
		printf("1\n0\n");
	}else{
		printf("%d\n%d\n", inZero, max(inZero, outZero));
	}
}

void tarjan(int x)
{
	dfn[x] = low[x] = ++cnt;
	stap[stop++] = x;
	instack[x] = true;
	for(int i=1;i<=n;i++){
		if(!iMap[x][i]) continue;
		if(!dfn[i]){
			tarjan(i);
			low[x] = min(low[i], low[x]);
		}else if(instack[i]){
			low[x] = min(dfn[i], low[x]);
		}
	}

	if(low[x] == dfn[x]){
		iCount++;
		while(1){
			int temp = stap[--stop];
			belong[temp] = iCount;
			instack[temp] = false;
			if(temp == x) break;
		}
	}
}

int main(void)
{
	// INPUT_TEST;

	int solo;
	while(~scanf("%d", &n)){
		init();
		//建图
		for(int i=1;i<=n;i++){
			while(scanf("%d", &solo) && solo) iMap[i][solo] = 1;
		}
		//判断
		for(int i=1;i<=n;i++){
			if(!dfn[i]) tarjan(i);
		}
		output();
	}
    return 0;
}