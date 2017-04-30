/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-02 19:44:22
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-30 17:07:58
*/

//http://poj.org/problem?id=1979
//最简单的深搜，搜到头直接返回，没有特殊情况。

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N  = 40;
int col , row;
int cnt;
int Imap[N][N];
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(int x, int y)
{
	cnt++;//每展开一个dfs相当于多走一步。
	Imap[x][y] = 1;//走过的地方不能再走，标记为墙
	for(int i=0;i<4;i++){//按方向逐个搜索
		int dx = x + direction[i][0];
		int dy = y + direction[i][1];
		if(dx>=1 && dx<=row && dy>=1 && dy<=col && Imap[dx][dy] == 0){
			dfs(dx, dy);//深搜时注意参数不要写错。
		}
	}
	return;
}


int main(void)
{
	
	int beginX = 0, beginY = 0;
	char temp;
	while(scanf("%d%d", &col, &row), row != 0 && col != 0){
		getchar();
		memset(Imap, 0, sizeof(Imap));
		for(int i=1;i<=row;i++){
			for(int j=1;j<=col;j++){
				scanf("%c", &temp);
				if(temp == '#') Imap[i][j] = 1;
				if(temp == '@'){
					beginX = i;
					beginY = j;
				}
			}
			getchar();
		}
		cnt = 0;
		dfs(beginX, beginY);//从某一特定位置开始dfs
		printf("%d\n", cnt);
	}
    return 0;
}