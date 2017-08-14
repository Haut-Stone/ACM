/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-14 10:17:22
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-14 14:09:22
*/

//POJ 3041
//第一次做二分图匹配的题，这里这个博客讲的十分通俗易懂
//http://blog.csdn.net/dark_scope/article/details/8880547

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

const int N = 550;

bool vis[N];
int links[N];
int iMap[N][N];
int rowAndCol;
int numAsteroids;
int numx, numy;
int ans;

bool dfs(int x)
{
	for(int y=1;y<=numy;y++){
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
	while(~scanf("%d%d", &rowAndCol, &numAsteroids)){
		memset(links, 0, sizeof(links));
		memset(iMap, 0, sizeof(iMap));
		numx = numy = rowAndCol;
		int x, y;
		for(int i=0;i<numAsteroids;i++){
			scanf("%d%d", &x, &y);
			iMap[x][y] = 1;
		}
		search();
		printf("%d\n", ans);
	}
	return 0;
}