/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-10 17:54:24
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-10 18:08:05
*/

//HDU 2181
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

const int N = 100;
int iMap[N][N];
bool vis[N];
int ans[N];
int num;
int n;

void init()
{
	memset(vis, 0, sizeof(vis));
	memset(ans, 0, sizeof(ans));
	num = 0;
}	

void dfs(int dep, int count)
{
	ans[count] = dep;
	if(count == 19){
		if(iMap[dep][n]){
			printf("%d:  ", ++num);
			for(int i=0;i<20;i++){
				printf("%d ", ans[i]);
			}
			printf("%d\n", ans[0]);
		}
		return;
	}
	for(int i=1;i<=20;i++){
		if(iMap[dep][i] && !vis[i]){
			vis[i] = true;
			dfs(i, count+1);
			vis[i] = false;
		}
	}
}

int main(void)
{
	memset(iMap, 0, sizeof(vis));
	for(int i=1;i<=20;i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b ,&c);
		iMap[i][a] = 1;
		iMap[i][b] = 1;
		iMap[i][c] = 1;
	}
	while(scanf("%d", &n) && n){
		init();
		vis[n] = true;
		dfs(n, 0);
	}
	return 0;
}