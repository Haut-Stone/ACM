/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-15 17:02:54
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-15 17:04:25
*/

//HDU 4185
//这道题的构图，先给所有的#标号，然后相4个方向上相连的#在二分图上连一条线

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
const int DIC[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

char charMap[N][N];
int iMap[N][N];
int book[N][N];
int numx, numy;
int links[N];
int vis[N];

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

int search()
{
	int ans = 0;
	memset(links, 0, sizeof(links));
	for(int x=1;x<=numx;x++){
		memset(vis, 0, sizeof(vis));
		if(dfs(x)){
			ans++;
		}
	}
	return ans;
}

bool isSafePos(int x, int y, int n)
{
	return (x >= 1 && x <= n && y >= 1 && y <= n);
}

int main(void)
{
	int T;
	int n;
	int posNum;
	int cas = 1;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		posNum = 1;
		for(int i=1;i<=n;i++){
			scanf("%s", charMap[i]+1);
			for(int j=1;j<=n;j++){
				if(charMap[i][j] == '#') book[i][j] = posNum++;
			}
		}
		memset(iMap, 0, sizeof(iMap));
		numx = numy = posNum;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(charMap[i][j] == '#'){
					for(int k=0;k<4;k++){
						int dx = i + DIC[k][0];
						int dy = j + DIC[k][1];
						if(isSafePos(dx, dy, n)){
							if(charMap[dx][dy] == '#'){
								iMap[book[i][j]][book[dx][dy]] = 1;
							}
						}
					}
				}
			}
		}
		int ans = search();
		printf("Case %d: %d\n", cas++, ans/2);
	}
	return 0;
}