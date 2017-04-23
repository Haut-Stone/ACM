/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-20 00:55:07
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-20 14:54:19
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

#define INPUT_TEST freopen("in.txt", "r", stdin)

typedef long long int64;//这道题最主要的就是要用64位
const int64 INF = 1e18;
const int N = 600;


int64 iMap[N][N];//先组织好图再求最短路
int64 vertexs;
int64 c[10];
int64 l[10];
int64 x[N];
int64 call;
int64 beginX, endX;

inline int64 Ab(int64 x){return x<0?-x:x;} 

//求任意两个顶点之间的最短
void floyd()
{
	for(int k=1;k<=vertexs;k++){
		for(int i=1;i<=vertexs;i++){
			for(int j=1;j<=vertexs;j++){
				if(iMap[i][j] > iMap[i][k] + iMap[k][j]){//这就是floyd唯一的判断条件。
					iMap[i][j] = iMap[i][k] + iMap[k][j];
				}
			}
		}
	}
	return;
}

void init()
{
	for(int i=1;i<=vertexs;i++){
		for(int j=1;j<=vertexs;j++){
			if(i == j){
				iMap[i][j] = 0;
			}else{
				iMap[i][j] = INF;
			}
		}
	}
}

int64 getCost(int64 dis)
{
	if(0 < dis && dis <= l[1]) return c[1];
	if(l[1] < dis && dis <= l[2]) return c[2];
	if(l[2] < dis && dis <= l[3]) return c[3];
	if(l[3] < dis && dis <= l[4]) return c[4];
	return INF;
}

void read()
{
	for(int i=1;i<=4;i++){
		scanf("%lld", &l[i]);
	}
	for(int i=1;i<=4;i++){
		scanf("%lld", &c[i]);
	}
	scanf("%lld%lld", &vertexs, &call);
	for(int i=1;i<=vertexs;i++){
		scanf("%lld", &x[i]);
	}
}

int main(void)
{
	// INPUT_TEST;
	int T;
	int cas = 1;
	scanf("%d", &T);
	while(T--){
		init();
		read();
		
		for(int i=1;i<=vertexs;i++){
			for(int j=i+1;j<=vertexs;j++){
				iMap[i][j] = iMap[j][i] = getCost(Ab(x[i]-x[j]));//计算边的权值
			}
		}

		floyd();
		printf("Case %d:\n", cas);
		cas++;
		for(int i=1;i<=call;i++){
			scanf("%lld%lld", &beginX, &endX);
			if(iMap[beginX][endX] == INF){
				printf("Station %lld and station %lld are not attainable.\n", beginX, endX);
			}else{
				printf("The minimum cost between station %lld and station %lld is %lld.\n", beginX, endX, iMap[beginX][endX]);
			}
		}
	}
    return 0;
}