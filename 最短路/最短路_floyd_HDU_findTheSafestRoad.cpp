/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-19 23:16:29
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-19 23:28:06
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

const int N = 1010;

double iMap[N][N];//先组织好图再求最短路
int vertexs;
int beginX;
int endX;
//求任意两个顶点之间的最短
void floyd()
{
	for(int k=1;k<=vertexs;k++){
		for(int i=1;i<=vertexs;i++){
			for(int j=1;j<=vertexs;j++){
				if(iMap[i][j] < iMap[i][k] * iMap[k][j]){//这就是floyd唯一的判断条件。
					iMap[i][j] = iMap[i][k] * iMap[k][j];
				}
			}
		}
	}
	return;
}


int main(void)
{
	// INPUT_TEST;
	while(scanf("%d", &vertexs) != EOF){
		for(int i=1;i<=vertexs;i++){
			for(int j=1;j<=vertexs;j++){
				scanf("%lf", &iMap[i][j]);
			}
		}
		floyd();
		int cas;
		scanf("%d", &cas);
		while(cas--){
			scanf("%d%d", &beginX, &endX);
			if(iMap[beginX][endX] == 0){
				printf("What a pity!\n");
			}else{
				printf("%.3f\n", iMap[beginX][endX]);
			}
		}
	}
    return 0;
}