/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-03 21:54:14
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-05 18:28:10
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N = 1005;
int Imap[N][N];//地图
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0 ,-1}};//方向
int flag;
int x1, yy1;
int x2, y2;
int n, m;

void dfs(int now, int step, int x, int y)	
{	
	if(flag == 1) return;
	if(step>2||(step==2&&(x-x2)&&(y-y2))) return;//关键
	if(x==x2 && y==y2){//如果走到终点，则返回
		flag = 1;
		return;
	}
	for(int i=0;i<4;i++){//四个方向搜索的过程
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		int step1 = step+1;
		if(now == i+1 || now == 0) step1--;
		if(dx >= 1 && dx<= n && dy >= 1 && dy <= m){//如果位置合法
			if(Imap[dx][dy] == 0){//如果是空地
				Imap[dx][dy] = 1;
				dfs(i+1, step1, dx, dy);
				Imap[dx][dy] = 0;
			}else if(dx == x2 && dy == y2){
				dfs(i+1, step1, dx, dy);
				if(flag == 1) return;
			}
		}
	}
}

int main(void)
{
	int askNumber;
	while(~scanf("%d%d", &n, &m)&&(m||n)){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d", &Imap[i][j]);
			}
		}
		cin>>askNumber;
		for(int i=0;i<askNumber;i++){
			cin>>x1>>yy1>>x2>>y2;
			if(Imap[x1][yy1] != Imap[x2][y2] || Imap[x1][yy1] == 0){
				printf("NO\n");
				continue;
			}
			flag = 0;//这个是干什么用的？
			dfs(0, 0, x1, yy1);
			if(flag){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
    return 0;
}