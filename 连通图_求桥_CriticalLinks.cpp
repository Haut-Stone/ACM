/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-03 21:32:17
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-03 22:41:51
*/

//light OJ 1026
//模版题，代码主要来自--->aha

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

const int N = 10010;

int vertexs, edges;
int dfn[N], low[N];
vector<int> iMap[N];
vector<pair<int , int> > output;
int tcnt, scnt;

void dfs(int u, int father)
{
	dfn[u] = low[u] = ++tcnt;
	for(int i=0;i<iMap[u].size();i++){
		int v = iMap[u][i];
		if(!dfn[v]){
			dfs(v, u);
			low[u] = min(low[v], low[u]);
			if(low[v] > dfn[u]){
				if(u < v){//就这么一个输出的交换，让我WA了好几发ಠ_ಠ
					output.push_back(make_pair(u, v));
				}else{
					output.push_back(make_pair(v, u));
				}
				scnt++;
			}
		}else if(v != father){
			low[u] = min(low[u], dfn[v]);
		}
	}
}

void init()
{
	tcnt = scnt = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));	
	for(int i=0;i<=vertexs;i++){
		iMap[i].clear();
	}
	output.clear();
}

int main(void)
{
	// INPUT_TEST;

	int T;
	int cas = 1;

	cin>>T;
	while(T--){
		scanf("%d", &vertexs);
		init();
		for(int i=0;i<vertexs;i++){
			int u, v;
			scanf("%d (%d)", &u, &edges);
			while(edges--){
				scanf("%d", &v);
				iMap[u].push_back(v);
			}
		}
		for(int i=0;i<vertexs;i++){
			if(!dfn[i]) dfs(i, -1);
		}
		sort(output.begin(), output.end());
		printf("Case %d:\n%d critical links\n", cas++, scnt);
		for(int i=0;i<scnt;i++){
			printf("%d - %d\n", output[i].first, output[i].second);
		}
	}		
    return 0;
}