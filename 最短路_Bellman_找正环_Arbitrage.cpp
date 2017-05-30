/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-28 12:27:51
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-28 12:47:09
*/

//POJ 2240 同样是汇率转换的问题，就是求正环。
//

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
double rateAToB;
string str, tempStr1, tempStr2;

map<string, double> book;

bool bellman(void)
{
	memset(dis, 0, sizeof(dis));
	dis[1] = 1;

	bool flag;

	for(int k=1;k<=vertexs-1;k++){
		flag = false;
		for(int i=0;i<edges;i++){
			if(dis[edge[i].v] < dis[edge[i].u] * edge[i].rate){
				dis[edge[i].v] = dis[edge[i].u] * edge[i].rate;
				flag = true;
			}
		}
		if(!flag){
			break;
		}
	}
	
	for(int k=0;k<edges;k++){
		if(dis[edge[k].v] < dis[edge[k].u] * edge[k].rate){
			return true;
		}
	}
	return false;
}	

int main(void)
{
	// INPUT_TEST;
	
	int cas = 1;

	while(cin>>vertexs){
		if(vertexs == 0) break;
		for(int i=1;i<=vertexs;i++){
			cin>>str;
			book[str] = i;
		}
		cin>>edges;
		for(int i=0;i<edges;i++){
			cin>>tempStr1>>rateAToB>>tempStr2;
			edge[i].u = book[tempStr1];
			edge[i].v = book[tempStr2];
			edge[i].rate = rateAToB;
		}

		printf("Case %d: ", cas++);
		if(bellman()){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}