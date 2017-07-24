/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-02 20:30:06
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-24 15:45:19
*/


//https://vjudge.net/contest/156294?#problem/H
//这道题，只要读懂题意，就是一个求最小生成树的模版题。

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

const int N = 2000+17;
const int INF = (1<<20);

char cars[N][N];
int Imap[N][N];
int minCost[N];
bool vis[N];
int vertexNumber;
int n;
int ans;

int process(int car1, int car2)
{
	int ans = 0;
	for(int i=0;i<7;i++){
		if(cars[car1][i] != cars[car2][i]){
			ans++;
		}
	}
	return ans;
}

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
	
int main(void)
{
	int n;
	while(cin>>n, n){
		for(int i=0;i<n;i++){
			scanf("%s", cars[i]);
		}
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				Imap[i][j] = Imap[j][i] = process(i, j);
			}
		}	
		vertexNumber = n;
		ans = prim();
		printf("The highest possible quality is 1/%d.\n",ans);
	}
    return 0;
}