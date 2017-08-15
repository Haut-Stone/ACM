/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-15 09:54:08
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-15 09:56:09
*/

//HDU 1281
//匈牙利算法，但是要再一个个去掉点，如果最大匹配减少的话，说明这个点就是关键点。
//http://acm.hdu.edu.cn/showproblem.php?pid=1281
//http://blog.csdn.net/qq_21899803/article/details/52075899

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

const int N = 1100;

int iMap[N][N];
int links[N];
int vis[N];
int row, col;
int posNum;

struct Node
{
	int x;
	int y;
}legalPos[N];

bool dfs(int x)
{
	for(int y=1;y<=col;y++){
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
	for(int x=1;x<=row;x++){
		memset(vis, 0, sizeof(vis));
		if(dfs(x)){
			ans++;
		}
	}
	return ans;
}

int main(void)
{
	int cas = 1;
	while(~scanf("%d%d%d", &row, &col, &posNum)){
		memset(iMap, 0, sizeof(iMap));
		
		for(int i=1;i<=posNum;i++){
			scanf("%d%d", &legalPos[i].x, &legalPos[i].y);
			iMap[legalPos[i].x][legalPos[i].y] = 1;
		}
		int ans = search();
		int sum = 0;
		for(int i=1;i<=posNum;i++){
			iMap[legalPos[i].x][legalPos[i].y] = 0;
			int res = search();
			iMap[legalPos[i].x][legalPos[i].y] = 1;
			if(res < ans) sum++;
		}
		printf("Board %d have %d important blanks for %d chessmen.\n", cas++, sum, ans);
	}
	return 0;
}