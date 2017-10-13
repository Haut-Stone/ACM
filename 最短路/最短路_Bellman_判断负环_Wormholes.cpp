/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-27 12:30:07
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-12 21:41:16
*/

//POJ 3259 能回到过去的条件就是找到一个负环就好了。
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

const int N = 2050;
const int INF = 99999999;

struct Node
{
	int u;
	int v;
	int w;
}edge[N*3];

int T;
int edges;
int vertexs;
int dis[N];
int holeNumber;
int roadNumber;
int u, v, w;


bool bellman(void)
{
	bool flag;

	for(int i=1;i<=vertexs;i++){
		dis[i] = INF;
	}

	for(int k=1;k<=vertexs-1;k++){
		flag = false;
		for(int i=1;i<=edges;i++){
			if(dis[edge[i].v] > dis[edge[i].u] + edge[i].w){
				dis[edge[i].v] = dis[edge[i].u] + edge[i].w;
				flag = true;
			}
		}
		if(!flag) break;//没有更新的话就及时跳出。
	}

	for(int k=1;k<=edges;k++){
		if(dis[edge[k].v] > dis[edge[k].u] + edge[k].w) return true;
	}
	return false;
}

void read()
{
	cin>>vertexs>>roadNumber>>holeNumber;
	edges = 1;
	for(int i=0;i<roadNumber;i++){
		scanf("%d%d%d", &u, &v, &w);
		edge[edges].u = u;
		edge[edges].v = v;
		edge[edges++].w = w;
		edge[edges].u = v;
		edge[edges].v = u;
		edge[edges++].w = w;
	}
	for(int i=0;i<holeNumber;i++){
		scanf("%d%d%d", &u, &v, &w);
		edge[edges].u = u;
		edge[edges].v = v;
		edge[edges++].w = -w;
	}
}

int main(void)
{
	// INPUT_TEST;

	cin>>T;
	while(T--){
		read();
		if(bellman()){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
    return 0;
}