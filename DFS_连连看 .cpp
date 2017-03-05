/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-03 21:54:14
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-04 18:40:42
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N = 80;
int Imap[N][N];
int vis[N][N];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0 ,-1}};



int dfs(int x, int y, int step, int changeNumber, int endX, int endY)	
{	
	if(changeNumber>2) return 0;
	if(x == endX && y == endY) return 1;
	for(int i=0;i<4;i++){
		int dx = x+dir[i][0];
		int dy = y+dir[i][1];
		
	}
	return 0;
}


int main(void)
{
	int n, m;
	int askNumber;
	int x1, y1;
	int x2, y2;
	while(~scanf("%d%d", &n, &m)){
		if(n == 0 && m == 0) break;//退出条件
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d", &Imap[i][j]);
			}
		}
		cin>>askNumber;
		for(int i=0;i<askNumber;i++){
			cin>>x1>>y1>>x2>>y2;
			if(Imap[x1][y1] != Imap[x2][y2] || Imap[x1][y1] == 0 || Imap[x2][y2] == 0){
				printf("NO\n");
			}else if(dfs(x1, y1, 0, 0, x2, y2)){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
    return 0;
}