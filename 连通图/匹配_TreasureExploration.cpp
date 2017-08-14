/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-14 14:09:13
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-14 14:10:44
*/

//POJ 2594
//这题也是求匹配，但是在此之前要用floyd传递一次闭包

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

const int N = 1010;

int iMap[N][N];
int links[N];
bool vis[N];
int numx, numy;
int vertexs;
int edges;
int ans;

void floyd()
{
	for(int i=1;i<=vertexs;i++){
		for(int j=1;j<=vertexs;j++){
			for(int k=1;k<=vertexs;k++){
				if(iMap[i][k] && iMap[k][j]){
					iMap[i][j] = 1;
				}
			}
		}
	}
}

bool dfs(int x)
{
	for(int y=1;y<=numy;y++){
		if(iMap[x][y] && !vis[y]){
			vis[y] = 1;
			if(links[y] == 0 || dfs(links[y])){
				links[y] = x;
				return true;
			}
		}
	}
	return false;
}

void search()
{
	ans = 0;
	for(int x=1;x<=numx;x++){
		memset(vis, 0, sizeof(vis));
		if(dfs(x)){
			ans++;
		}
	}
}

int main(void)
{
	while(scanf("%d%d", &vertexs, &edges)){
		if(vertexs == 0 && edges == 0) break;
		memset(iMap, 0, sizeof(iMap));
		int u, v;
		for(int i=0;i<edges;i++){
			scanf("%d%d", &u, &v);
			iMap[u][v] = 1;
		}
		floyd();

		memset(links, 0, sizeof(links));
		numx = numy = vertexs;
		search();
		printf("%d\n", vertexs - ans);
	}
	return 0;
}