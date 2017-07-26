/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-24 13:39:06
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-24 14:00:54
*/

//建图建好了，之后的就是自然而然的打模版了。
//https://vjudge.net/contest/162382#problem/N

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

const int N = 300;
const int INF = 99999999;

int T;
double Imap[N][N];//第一个点的编号从零开始！！
double minCost[N];
bool vis[N];
int vertexNumber;

struct Node
{
	int x;
	int y;
}vertex[N];

double prim()
{
	for(int i=0;i<vertexNumber;i++){
		minCost[i] = Imap[0][i];
		vis[i] = false;//初始话顶点为未被访问。
	}

	minCost[0] = 0;//第一个点到自己的距离为0.
	double ans = 0;
	
	while(true){

		double minDis = INF;
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
	return ans * 100;
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

void read()
{
	cin>>vertexNumber;
	for(int i=0;i<vertexNumber;i++){
		scanf("%d%d", &vertex[i].x, &vertex[i].y);
	}
	for(int i=0;i<vertexNumber;i++){
		for(int j=i;j<vertexNumber;j++){
			double temp = (vertex[i].x - vertex[j].x) * (vertex[i].x - vertex[j].x) + (vertex[i].y - vertex[j].y) * (vertex[i].y - vertex[j].y);
			if(temp >= 100 && temp <= 1000000){
				Imap[i][j] = Imap[j][i] = sqrt(temp);
			}else{
				Imap[i][j] = Imap[j][i] = INF;
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
		double ans = prim();
		int flag = 0;
		for(int i=0;i<vertexNumber;i++){
			if(minCost[i] == INF) flag = 1;
		}
		if(flag){
			printf("oh!\n");
		}else{
			printf("%.1f\n", ans);
		}
	}
    return 0;
}