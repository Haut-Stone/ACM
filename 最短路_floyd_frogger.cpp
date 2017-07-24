/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-24 14:21:16
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-24 15:09:48
*/

//POJ 2253
//求所有通路中的最长边的最小值

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

int stoneNum;
double iMap[N][N];

struct Node
{
	int x;
	int y;
}stone[N];

double dis(int x1, int y1, int x2, int y2)
{
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void floyd()
{
	for(int k=0;k<stoneNum;k++){
		for(int i=0;i<stoneNum;i++){
			for(int j=0;j<stoneNum;j++){
				//这里感觉好神奇啊，不是很理解
				//许多通路中最长边中的最小边
				iMap[i][j] = min(max(iMap[i][k], iMap[k][j]), iMap[i][j]);
			}
		}
	}
}

int main(void)
{
	int cas = 1;
	while(scanf("%d", &stoneNum)){
		if(stoneNum == 0) break;
		for(int i=0;i<stoneNum;i++){
			scanf("%d%d", &stone[i].x, &stone[i].y);
		}
		for(int i=0;i<stoneNum;i++){
			for(int j=i+1;j<stoneNum;j++){
				iMap[i][j] = iMap[j][i] = dis(stone[i].x, stone[i].y, stone[j].x
											  , stone[j].y);
			}
		}
		floyd();
		printf("Scenario #%d\n", cas++);
		printf("Frog Distance = %.3f\n", iMap[0][1]);
	}
	return 0;
}