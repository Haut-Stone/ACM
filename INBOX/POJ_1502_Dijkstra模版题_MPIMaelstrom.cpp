/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-18 20:49:12
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-18 21:36:39
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

const int INF = 99999999;
const int N = 110;

int iMap[N][N];
int vertexs;
char temp[N];
int dis[N];
int vis[N];
int beginX = 1;

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

void dijkstra()
{	
	int min;
	int minVertex;
	int ans = -1;

	for(int i=1;i<=vertexs;i++){
		dis[i] = iMap[beginX][i];
		vis[i] = 0;
	}

	vis[beginX] = 1;

	for(int i=1;i<=vertexs-1;i++){//搜遍所有的点
		min = INF;
		for(int j=1;j<=vertexs;j++){//找距出发点距离最近的点
			if(dis[j] < min && vis[j] == 0){
				min = dis[j];
				minVertex = j;
			}
		}
		vis[minVertex]  = 1;
		for(int j=1;j<=vertexs;j++){
			if(iMap[minVertex][j] < INF){
				if(dis[minVertex] + iMap[minVertex][j] < dis[j]) dis[j] = dis[minVertex] + iMap[minVertex][j];
			}
		}
	}

	for(int i=2;i<=vertexs;i++){
		if(dis[i] > ans) ans = dis[i];
	}
	
	printf("%d\n", ans);
}

int main(void)
{
	// INPUT_TEST;
	while(~scanf("%d", &vertexs)){
		init();
		for(int i=2;i<=vertexs;i++){//因为第一行的0并没有给出
			for(int j=1;j<i;j++){
				scanf("%s", temp);
				if(temp[0] != 'x'){
					iMap[i][j] = iMap[j][i] = atoi(temp);//这个函数直接把字符串变成函数值，很方便。
				}
			}	
		}
	}
	dijkstra();
    return 0;
}