/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-28 11:10:13
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-16 16:58:47
*/

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

const int N = 1100;

struct Node
{
	int k;
	int a[N];
}links[N];

int bullPenNum, cowNum;
int vis[N];
int iMap[N][N];
int bullPenCapacity[N];

bool dfs(int x, int l, int r)
{
	for(int y=1;y<=bullPenNum;y++){
		if(!vis[y] && iMap[x][y] >= l && iMap[x][y] <= r){
			vis[y] = 1;
			if(links[y].k < bullPenCapacity[y]){
				links[y].a[links[y].k++] = x;
				return true;
			}
			for(int i=0;i<links[y].k;i++){
				if(dfs(links[y].a[i], l, r)){
					links[y].a[i] = x;
					return true;
				}
			}
		}
	}
	return false;
}

bool Hungary(int l, int r)
{
	memset(links, 0, sizeof(links));
	for(int x=1;x<=cowNum;x++){
		memset(vis, 0, sizeof(vis));
		if(!dfs(x, l, r)){
			return false;
		}
	}
	return true;
}

int main(void)
{
	while(~scanf("%d%d", &cowNum, &bullPenNum)){
		memset(iMap, 0, sizeof(iMap));
		for(int i=1;i<=cowNum;i++){
			for(int j=1;j<=bullPenNum;j++){
				int x;
				scanf("%d", &x);
				iMap[i][x] = j;
			}
		}
		for(int i=1;i<=bullPenNum;i++){
			scanf("%d", &bullPenCapacity[i]);
		}
		int l = 0, r = bullPenNum, ans = r;
		while(l <= r){
			int i, mid = (l + r) / 2;
			for(i=1;i<=bullPenNum;i++){
				if(Hungary(i, mid+i)){
					break;
				}
			}
			if(i == bullPenNum + 1){
				l = mid + 1;
			}else{
				r = mid - 1;
				ans = mid + 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}