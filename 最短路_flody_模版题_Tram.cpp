/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-31 21:51:48
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-31 22:04:59
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
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;

const int N = 300;
const int INF = 99999999;

int iMap[N][N];//先组织好图再求最短路
int vertexs;
int beginX;
int endX;
int k;
int x;

void init()
{
	for(int i=1;i<=vertexs;i++){
		for(int j=1;j<=vertexs;j++){
			if(i == j){
				iMap[i][j] = 0;
			}else{
				iMap[i][j]= INF;
			}
		}
	}
}

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

int main(void)
{
	// INPUT_TEST;

	while(~scanf("%d%d%d", &vertexs, &beginX, &endX)){
		init();
		for(int i=1;i<=vertexs;i++){
			scanf("%d", &k);
			for(int j=1;j<=k;j++){
				scanf("%d", &x);
				iMap[i][x] = j == 1 ? 0:1;
			}
		}
		floyd();
		if(iMap[beginX][endX] == INF){
			printf("-1\n");
		}else{
			printf("%d\n", iMap[beginX][endX]);
		}
	}
    return 0;
}