/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-14 19:22:27
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-14 19:26:00
*/

//HDU 1045
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

const int N = 30;

char iMap[N][N];
int markRow[N][N];
int markCol[N][N];
int g[N][N];

bool vis[N];
int links[N];
int numx, numy;
int ans;

bool dfs(int x)
{
	for(int y=1;y<=numy;y++){
		if(g[x][y] && !vis[y]){
			vis[y] = true;
			if(links[y] == 0 || dfs(links[y])){
				links[y] = x;
				return true;
			}
		}
	}
	return false;
}

void search()
{
	memset(links, 0, sizeof(links));
	ans = 0;
	for(int x=1;x<=numx;x++){
		memset(vis, 0, sizeof(vis));
		if(dfs(x)){
			ans++;
		}
	}
}

int main(void)
{
	int n;
	while(scanf("%d" ,&n), n){
		memset(markRow, 0, sizeof(markRow));
		memset(markCol, 0, sizeof(markCol));
		memset(g, 0, sizeof(g));

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>iMap[i][j];
				if(iMap[i][j] == 'X'){
					markCol[i][j] = markRow[i][j] = -1;
				}
			}
		}
		// printf("YR\n");
		int posNum1 = 0;
		int posNum2 = 0;
		numy = numx = 0;

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				while(markRow[i][j] == -1 && j <= n){
					j++;
				}
				posNum1++;
				while(markRow[i][j] != -1 && j <= n){
					markRow[i][j] = posNum1;
					numx = max(numx, posNum1);
					j++;
				}
			}
		}

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				while(markCol[j][i] == -1 && j <= n){
					j++;
				}
				posNum2++;
				while(markCol[j][i] != -1 && j <= n){
					markCol[j][i] = posNum2;
					numy = max(numy, posNum2);
					j++;
				}
			}
		}

		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(markRow[i][j] != -1 && markCol[i][j] != -1){
					g[markRow[i][j]][markCol[i][j]] = 1;
				}
			}
		}
		search();
		printf("%d\n", ans);
	}
	return 0;
}