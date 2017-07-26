/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-09 15:50:05
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-09 16:04:36
*/

//HDU 1241
//貌似是一个十分朴素的dfs,也许是最最最朴素的dfs了，就是求连通块而已，只不过有8个方向
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

const int N = 110;

char iMap[N][N];
bool vis[N][N];
int direction[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1} ,{1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int row, col;
int ans;

void dfs(int x, int y)
{
	vis[x][y] = 1;
	for(int i=0;i<8;i++){
		int dx = x + direction[i][0];
		int dy = y + direction[i][1];
		if(dx >= 0 && dx < row && dy >= 0 && dy < col && iMap[dx][dy] == '@' && !vis[dx][dy]){
			dfs(dx, dy);
		}
	}
}

void init()
{
	ans = 0;
	memset(vis, 0, sizeof(vis));
}

int main(void)
{
	while(~scanf("%d%d", &row, &col) && (row || col)){
		init();
		for(int i=0;i<row;i++){
			scanf("%s", iMap[i]);
		}
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				if(iMap[i][j] == '@' && !vis[i][j]){
					dfs(i, j);
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}