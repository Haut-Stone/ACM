/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-19 21:34:41
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-19 22:40:46
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

const int N = 200;//根据题目要求更该合适的数值
const int INF = 99999999;

//需要在main中读取的值
int iMap[N][N];//先组织好图再求最短路
int vertexs;

//仅dijkstra中用到的

int vis[N];
int dis[N];
int edges;//这里有个玄学问题，如果edges 放在vis[N],之前的话程序无法运行。。


int dijkstra(int beginX, int endX)
{	
	int min;
	int minVertex = 0;

	//初始化
	for(int i=1;i<=vertexs;i++){
		dis[i] = iMap[beginX][i];
		vis[i] = 0;
	}

	dis[beginX] = 0;
	vis[beginX] = 1;

	for(int i=1;i<=vertexs-1;i++){//搜遍所有的点
		min = INF;
		for(int j=1;j<=vertexs;j++){//找距出发点距离最近的点
			if(dis[j] < min && !vis[j]){
				min = dis[j];
				minVertex = j;
			}
		}
		if(min == INF) break;//如果没有更小的点了，直接退出。
		vis[minVertex]  = 1;
		for(int j=1;j<=vertexs;j++){
			if(iMap[minVertex][j] < INF){
				if(dis[minVertex] + iMap[minVertex][j] < dis[j]) dis[j] = dis[minVertex] + iMap[minVertex][j];
			}
		}
	}
	return dis[endX];
}

void init()
{
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(i == j){
				iMap[i][j] = 0;
			}else{
				iMap[i][j] = INF;
			}
		}
	}
}

int main(void)
{
	// INPUT_TEST;
	map<string, int> exc;
	char s1[35];
	char s2[35];
	char beginX[35];
	char endX[35];

	int w;
	while(~scanf("%d", &edges)){
		if(edges == -1) return 0;
		init();
		exc.clear();//这一句一定要有.
		scanf("%s%s", beginX, endX);
		exc[beginX] = 1;
		exc[endX] = 2;

		int cnt = 3;
		for(int i=1;i<=edges;i++){
			scanf("%s%s%d", s1, s2, &w);
			if(!exc[s1]) exc[s1] = cnt++;
			if(!exc[s2]) exc[s2] = cnt++;
			iMap[exc[s1]][exc[s2]] = iMap[exc[s2]][exc[s1]] = w;
		}

		vertexs = cnt-1;
		int ans = dijkstra(exc[beginX], exc[endX]);
		if(ans == INF){
			printf("-1\n");
		}else{
			printf("%d\n", ans);
		}
	}
    return 0;
}