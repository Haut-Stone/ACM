/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-05 10:57:52
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-05 10:58:28
*/

//http://172.18.66.54:50015/JudgeOnline/problem.php?id=1285
//这题居然他不超时。。。

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

const int N = 400005;

int vertexs, edges;
vector<int> edge[N];
int boomNumber;
int willBeBoom[N];
int boomPoint[N];
int sum[N];
int vis[N];
int par[N];

void init()
{
	for(int i=0;i<=vertexs;i++){
		par[i] = i;
	}
	memset(vis, 0, sizeof(vis));
	memset(willBeBoom, 0, sizeof(willBeBoom));
}

int find(int x)
{
	if(x == par[x]){
		return x;
	}else{
		return par[x] = find(par[x]);
	}
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x != y){
		par[x] = y;
	}
}

void unite2(int x, int y, int mark)
{
	x = find(x);
	y = find(y);
	if(x != y){
		if(x != boomPoint[mark]){
			sum[mark]--;
		}
		par[x] = y;
	}
}

int main(void)
{
	while(~scanf("%d%d", &vertexs, &edges)){
		init();
		for(int i=1;i<=edges;i++){
			int u, v;
			scanf("%d%d", &u, &v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		scanf("%d", &boomNumber);
		for(int i=0;i<boomNumber;i++){
			scanf("%d", &boomPoint[i]);
			willBeBoom[boomPoint[i]] = 1;
		}
		for(int i=1;i<=vertexs;i++){
			if(!willBeBoom[i]){
				for(int j=0;j<edge[i].size();j++){
					if(!willBeBoom[edge[i][j]]){
						unite(i, edge[i][j]);
					}
				}
			}
		}
		for(int i=1;i<=vertexs;i++){
			if(!willBeBoom[i]){
				int xx = find(i);
				if(!vis[xx]){
					sum[boomNumber]++;
					vis[xx] = 1;
				}
			}
		}
		int rev;
		for(int i=boomNumber-1;i>=0;i--){
			willBeBoom[boomPoint[i]] = 0;
			sum[i] = sum[i+1];
			rev = 0;
			for(int j=0;j<edge[boomPoint[i]].size();j++){
				if(!willBeBoom[edge[boomPoint[i]][j]]){
					rev++;
					unite2(boomPoint[i], edge[boomPoint[i]][j], i);
				}
			}
			if(rev == 0) sum[i]++;
		}
		for(int i=0;i<=boomNumber;i++){
			printf("%d\n", sum[i]);
		}
		printf("YES\n");
	}
	return 0;
}