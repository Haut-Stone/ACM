/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-02 19:44:22
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-02 20:09:46
*/

//http://vj.sdutacm.org/contest/view.action?cid=62898#problem/E

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N = 40;
int row, col;
int cnt;
char Imap[N][N];
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void dfs(int i, int j)
{
	cnt++;
	Imap[i][j] = '#';
	for(int k=0;k<4;k++){
		int x = i + direction[k][0];
		int y = j + direction[k][1];
		if(x<row && y<col && x>=0 && y>=0 && Imap[x][y] == '.')
			dfs(x, y);
	}
	return;
}
int main(void)
{
	int beginX, beginY;
	while(~scanf("%d%d", &col, &row)){
		getchar();
		if(col == 0 && row == 0) break;
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				scanf("%c", &Imap[i][j]);
				if(Imap[i][j] == '@'){
					beginX = i;
					beginY = j;
				}
			}
			getchar();
		}
		cnt = 0;
		dfs(beginX, beginY);
		printf("%d\n", cnt);
	}
    return 0;
}