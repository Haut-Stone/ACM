/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-14 20:24:53
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-14 20:41:40
*/

//HDU 2444
//http://www.cnblogs.com/syhandll/p/4721270.html
//这道题多了一步看能不能构成二分图，然后就是正常的求最大匹配了

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

const int N = 110;

int iMap[N][N];
int vis[N];
int book[N];
int links[N];
bool canNotBeSolve;
int vertexs;
int edges;
int ans;

void bfs(int beginx)
{
	queue<int> Q;
	Q.push(beginx);
	vis[beginx] = 1;
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		for(int v=1;v<=vertexs;v++){
			if(u == v) continue;
			if(iMap[u][v] && book[v] == 0 && !vis[v]){
				vis[v] = 1;
				book[v] = -1;
				Q.push(v);
			}else if(iMap[u][v] && book[u] == book[v]){
				canNotBeSolve = true;
			}
		}
	}
}

bool dfs(int x)
{
	for(int y=1;y<=vertexs;y++){
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
	memset(links, 0, sizeof(links));
	for(int x=1;x<=vertexs;x++){
		memset(vis, 0, sizeof(vis));
		if(dfs(x)){
			ans++;
		}
	}
}

int main(void)
{
	while(~scanf("%d%d", &vertexs, &edges)){
		memset(iMap, 0, sizeof(iMap));
		memset(book, 0, sizeof(book));
		memset(vis, 0, sizeof(vis));

		int u, v;
		for(int i=1;i<=edges;i++){
			scanf("%d%d", &u, &v);
			iMap[u][v] = 1;
		}

		book[1] = 1;
		canNotBeSolve = false;
		bfs(1);
		if(canNotBeSolve){
			printf("No\n");
		}else{
			search();
			printf("%d\n", ans);
		}
	}
	return 0;
}