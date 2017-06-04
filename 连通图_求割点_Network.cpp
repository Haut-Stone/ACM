/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-02 22:40:35
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-03 22:39:13
*/

//POJ 1144
//

//代码来自aha算法
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
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;

const int N = 200;

int iMap[N][N];
int low[N];
int flag[N];
int timeStamp[N];
int times;

int vertexs;
int edges;
int u, v;
int ans;
int root;

void init()
{
	times = 0;
	ans = 0;
	memset(iMap, 0, sizeof(iMap));
	memset(flag, 0, sizeof(flag));
	memset(low, 0, sizeof(low));
	memset(timeStamp, 0, sizeof(timeStamp));
}

void read()
{	
	for(int i=1;i<=edges;i++){
		scanf("%d%d", &u, &v);
		iMap[u][v]  = iMap[v][u]  =1;
	}
}

void dfs(int cur, int father)
{	
	int childNum = 0;

	times++;
	low[cur] = times;
	timeStamp[cur] = times;

	//遍历所有的顶点
	for(int i=1;i<=vertexs;i++){
		//如果有边相连的话
		if(iMap[cur][i] == 1){
			if(timeStamp[i] == 0){
				childNum++;
				dfs(i, cur);
				low[cur] = min(low[cur], low[i]);
				//这里不是根，并且无法回到祖先节点的话。
				if(cur != root && low[i] >= timeStamp[cur]){
					flag[cur] = 1;
				}
				if(cur == root && childNum == 2){
					flag[cur] = 1;
				}
			}else if(i != father){//不经过父节点的情况下更新
				low[cur] = min(low[cur], timeStamp[i]);
			}
		}
	}
	return;
}

int main(void)
{
	INPUT_TEST;

	while(~scanf("%d%d", &vertexs, &edges)){
		init();
		read();
		root = 1;//开始构成生成树的起始点
		dfs(1, root);
		for(int i=1;i<=vertexs;i++){
			if(flag[i]) ans++;
		}
		printf("%d\n", ans);

	}
    return 0;
}