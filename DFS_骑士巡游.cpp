/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-29 21:31:01
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-21 19:15:23
*/
//dfs基础题，其实还是蛮简单的。
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <ctime> 
using namespace std;

const int N = 100;
int path[N][N];//记录走过的路径
int vis[N][N];//标记格子是否被走过
int r, c;//行列
bool flag;//判断标志

int changeX[8] = {-1, 1, -2, 2 ,-2, 2, -1, 1};
int changeY[8] = {-2, -2, -1, -1, 1, 1, 2, 2};

//判断一个跳到的格子是否合法
bool judges(int x, int y)
{
	if(x>=1 && x<=r && y>=1 && y<=c && !vis[x][y] && !flag) return true; 
	return false;
}

//深度优先搜索格子
void dfs(int rom, int col, int step)
{
	path[step][0] = rom;
	path[step][1] = col;

	if(step == r*c){//走完所有格子之后返回
		flag = true;
		return;
	}
	for(int i=0;i<8;i++){//按照字典序遍历格子
		int nx = rom + changeX[i];
		int ny = col + changeY[i];
		if(judges(nx, ny)){
			//最基本的深搜历程
			vis[nx][ny] = 1;
			dfs(nx, ny, step+1);
			vis[nx][ny] = 0;
		}
	}
}

int main(void)
{
	int n;
	int mark = 0;
	scanf("%d", &n);
	while(n--){
		//数据读入与输出部分
		flag = false;
		scanf("%d%d", &r, &c);
		memset(vis, 0, sizeof(vis));
		printf("Scenario #%d:\n", ++mark);
		vis[1][1] = 1;
		dfs(1, 1, 1);
		if(flag){
			for(int i=1;i<=r*c;i++){
				printf("%c%d", path[i][1] - 1 + 'A', path[i][0]);
			}
		}else{
			printf("impossible");
		}
		printf("\n");
		if(n != 0){
			printf("\n");
		}
	}
    return 0;
}