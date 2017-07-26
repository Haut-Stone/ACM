/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-26 17:08:16
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-28 12:37:24
*/

//POJ 1860 判断正向回路,如果有正向回路的话，那么钱的数量就一定会增加。
//bellman原用来找负环，这里逆向应用，用来找正环，求最长路。

//!!-----这题不知道哪里的bug(因为在edges前多加了一个int导致变成局部变量)一直不对--------
//!
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

const int N = 2010;

struct Node
{
	int u;
	int v;
	double rate;
	double fee;
}edge[N*2];//如果是无向边的话，这里的空间要双倍

double dis[N];
int vertexs;//货币种数
int edges;//兑换点数量
int u, v;
double rateAToB, rateBToA;
double feeAToB, feeBToA;
int rowMoneyKind;//持有第s种货币
double rowMoneyValue;//持有的s货币的本金

bool bellman(void)
{
	memset(dis, 0, sizeof(dis));
	dis[rowMoneyKind] = rowMoneyValue;

	bool flag;

	for(int k=1;k<=vertexs-1;k++){
		flag = false;
		for(int i=0;i<edges;i++){
			if(dis[edge[i].v] < (dis[edge[i].u] - edge[i].fee) * edge[i].rate){
				dis[edge[i].v] = (dis[edge[i].u] - edge[i].fee) * edge[i].rate;
				flag = true;
			}
		}
		if(!flag){
			break;
		}
	}
	
	for(int k=0;k<edges;k++){
		if(dis[edge[k].v] < (dis[edge[k].u]  - edge[k].fee) * edge[k].rate){
			return true;
		}
	}
	return false;
}	

int main(void)
{
	// INPUT_TEST;
	
	int temp;

	while(cin>>vertexs>>temp>>rowMoneyKind>>rowMoneyValue){
		edges = 0;
		for(int i=0;i<temp;i++){
			cin>>u>>v>>rateAToB>>feeAToB>>rateBToA>>feeBToA;
			edge[edges].u = u;
			edge[edges].v = v;
			edge[edges].rate = rateAToB;
			edge[edges++].fee = feeAToB;
			edge[edges].u = v;
			edge[edges].v = u;
			edge[edges].rate = rateBToA;
			edge[edges++].fee = feeBToA;
		}

		if(bellman()){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}