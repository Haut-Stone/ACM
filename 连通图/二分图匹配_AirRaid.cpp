/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-15 19:48:48
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-21 11:16:28
*/

//POJ 1422
//http://blog.csdn.net/u011345461/article/details/40921345

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
int links[N];
bool vis[N];
int n, m;

bool dfs(int x)
{
	for(int y=1;y<=n;y++){
		if(iMap[x][y] && !vis[y]){
			vis[y] = true;
			if(links[y] == 0 || dfs(links[y])){
				links[y] = x;
				return true;
			}
		}
	}
	return false;
}

int search()
{
	int ans = 0;
	memset(links, 0, sizeof(links));
	for(int x=1;x<=n;x++){
		memset(vis, 0, sizeof(vis));
		if(dfs(x)){
			ans++;
		}
	}
	return ans;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while(T--){
		memset(iMap, 0, sizeof(iMap));
		scanf("%d%d", &n, &m);
		int u, v;
		for(int i=1;i<=m;i++){
			scanf("%d%d", &u, &v);
			iMap[u][v] = 1;
		}
		int ans = search();
		printf("%d\n", n - ans);
	}
	return 0;
}