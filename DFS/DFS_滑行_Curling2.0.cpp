/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-30 16:41:44
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-24 11:41:14
*/

//http://poj.org/problem?id=3009
//这道题，与普通的替代区别，不需要标记走了那些格子，因为每一步他会走好几个格子

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
using namespace std;

#define INPUT_TEST freopen("in.txt", "r", stdin)

const int N = 100;
const int INF = 99999999;

int row;
int col;
int beginX;
int beginY;
int ans;

int iMap[N][N];
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void read()
{
	for(int i=1;i<=row;i++){
		for(int j=1;j<=col;j++){
			scanf("%d", &iMap[i][j]);
			if(iMap[i][j] == 2){
				beginX = i;
				beginY = j;
			}
		}
	}
	return;	
}

void init()
{
	memset(iMap, -1, sizeof(iMap));
	ans = INF;
}

void dfs(int x, int y, int cnt)
{
	cnt++;//超过10次直接退出

	if(cnt > 10 ){
		return;
	}

	for(int i=0;i<4;i++){
		int dx = x + direction[i][0];
		int dy = y + direction[i][1];

		if(iMap[dx][dy] == 1) continue;//撞墙跳过

		//这道题的核心代码
		while(iMap[dx][dy] == 0 || iMap[dx][dy] == 2){
			dx += direction[i][0];
			dy += direction[i][1];
		}

		if(iMap[dx][dy] < 0) continue;//出界的话，这个方向跳过

		if(iMap[dx][dy] == 1){//撞墙后更新状态
			iMap[dx][dy] = 0;
			dfs(dx - direction[i][0], dy - direction[i][1], cnt);
			iMap[dx][dy] = 1;
		}

		if(iMap[dx][dy] == 3){//到达终点更新最小值
			if(cnt < ans) ans = cnt;
			continue;
		}
	}
	return;
}

int main(void)
{
	// INPUT_TEST;

	while(~scanf("%d %d", &col, &row) && (col || row)){
		init();
		read();
		dfs(beginX, beginY, 0);
		if(ans < INF){
			printf("%d\n", ans);
		}else{
			printf("-1\n");
		}
	}
    return 0;
}