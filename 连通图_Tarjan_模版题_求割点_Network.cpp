/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-02 22:40:35
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-07 16:23:51
*/

//POJ 1144
//最简单的模版题，这题的数据比较小，直接用vector就好了。


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

int vertexs, edges;
int u, v;
int low[N];
int dfn[N];
int inStack[N];
int cutPoint[N];
int cnt;
int ans;
int root;

vector<int> iMap[N];
stack<int> S;
 
void tarjan(int u, int father)
{
	int child = 0;
	low[u] = dfn[u] = ++cnt;
	S.push(u);
	inStack[u] = 1;
	
	for(int i=0;i<iMap[u].size();i++){
		int v = iMap[u][i];
		if(!dfn[v]){
			child++;
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] >= dfn[u] && u != root){
				cutPoint[u] = 1;
			}else if(low[v] >= dfn[u] && u == root && child >= 2){
				cutPoint[u] = 1;
			}
		}else if(v != father){
			low[u] = min(low[u], dfn[v]);
		}
		
	}
	if(dfn[u] == low[u]){
		while(1){
			int temp = S.top();
			S.pop();
			inStack[temp] = 0;
			if(temp == u) break;
		}
	}
}

void init()
{
	cnt = ans = 0;
	memset(low, 0, sizeof(low));
	memset(dfn, 0, sizeof(dfn));
	memset(inStack, 0, sizeof(inStack));
	memset(cutPoint, 0, sizeof(cutPoint));
	for(int i=1;i<=vertexs;i++){
		iMap[i].clear();
	}
}

int main(void)
{
	while(scanf("%d", &vertexs) && vertexs){
		init();
		while(scanf("%d", &u) && u){
			while(getchar() != '\n'){
				cin>>v;
				iMap[u].push_back(v);
				iMap[v].push_back(u);
			}
		}
		root = 1;
		tarjan(root, -1);
		int ans = 0;
		for(int i=1;i<=vertexs;i++){
			if(cutPoint[i]) ans++;
		}
		printf("%d\n", ans);
	}
}