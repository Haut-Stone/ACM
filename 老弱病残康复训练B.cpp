/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-02-21 19:42:13
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-02-21 20:07:08
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

//POJ 2965 The Pilots Brothers' refrigerator 
//和之前的那道题，是一个尿性。

const int N = 10;
const int INF = 999999;

int maps[N][N];
int ans = INF;

int ansx[INF],ansy[INF],zx[INF],zy[INF];

int judge()
{
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(maps[i][j] != 0) return 0;
		}
	}
	return 1;
}

void exchange(int x, int y)
{
	for(int i=0;i<4;i++){
		maps[x][i] = !maps[x][i];
		maps[i][y] = !maps[i][y];
	}
	maps[x][y] = !maps[x][y];
}

int dfs(int x, int y, int t)
{
	if(judge()){
		if(ans > t){
			ans = t;
			for(int i=0;i<ans;i++){
				ansx[i] = zx[i];
				ansy[i] = zy[i];
			}
		}
		return 0;
	}

	if(x >= 4 || y >= 4){
		return 0;
	}

	int nx ,ny;
	nx = (x+1)%4;
	ny = y + (x+1)/4;

	dfs(nx ,ny, t);
	exchange(x, y);
	zx[t] = x + 1;
	zy[t] = y + 1;
	dfs(nx, ny ,t+1);
	exchange(x, y);
	return 0;
}

int main(void)
{
	char temp;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			scanf("%c", &temp);
			if(temp == '-'){
				maps[i][j] = 0;
			}else{
				maps[i][j] = 1;
			}
		}
		getchar();
	}

	dfs(0, 0, 0);
	printf("%d\n", ans);
	for(int i=0;i<ans;i++){
		printf("%d %d\n", ansx[i], ansy[i]);
	}
    return 0;
}