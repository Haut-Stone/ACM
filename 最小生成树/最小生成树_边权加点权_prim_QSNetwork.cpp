/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-24 17:47:55
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-24 17:56:36
*/

//这次在构图时， 只不过是要把起点和终点的点权都加上而已。
//并没有什么不同。。

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

const int N = 100;
const int INF = (1<<20);

int Imap[N][N];//第一个点的编号从零开始！！
int minCost[N];
bool vis[N];
int vertexValue[N];
int vertexNumber;
int T;


int prim()
{
	for(int i=0;i<vertexNumber;i++){
		minCost[i] = Imap[0][i];
		vis[i] = false;//初始话顶点为未被访问。
	}

	minCost[0] = 0;//第一个点到自己的距离为0.
	int ans = 0;
	
	while(true){

		int minDis = INF;
		int minPos = 0;

		for(int j=0;j<vertexNumber;j++){
			if(minCost[j] < minDis && !vis[j]){//搜索到当前点的最短距离
				minDis = minCost[j];
				minPos = j;
			}
		}

		if(minDis == INF) break;//如果所有的点都被找过

		vis[minPos] = 1;
		ans += minDis;
		for(int j=0;j<vertexNumber;j++){
			//将已搜索过的点视为一个整体,更新整体的值。
			if(!vis[j] && minCost[j] > Imap[minPos][j]){
				minCost[j] = Imap[minPos][j];
			}
		}
	}
	return ans;
}

void read()
{
	cin>>vertexNumber;
	for(int i=0;i<vertexNumber;i++){
		scanf("%d", &vertexValue[i]);
	}
	for(int i=0;i<vertexNumber;i++){
		for(int j=0;j<vertexNumber;j++){
			scanf("%d", &Imap[i][j]);
			Imap[i][j] = Imap[i][j] + vertexValue[i] + vertexValue[j];
		}
	}
}

void init()
{
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i == j){
				Imap[i][j] = 0;
			}else{
				Imap[i][j] = INF;
			}
		}
	}
}

int main(void)
{
	// INPUT_TEST;

	cin>>T;
	while(T--){
		init();
		read();
		printf("%d\n", prim());
	}
    return 0;
}