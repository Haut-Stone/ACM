/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-14 16:06:03
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-14 21:13:23
*/

//POJ 2289
//第一次做多重匹配，不是很懂。参考下学长的博客吧。
//好像是要求右边满足左边多个的情况下，让所有人都有匹配是的最小单人匹配数目
//http://blog.csdn.net/ssimple_y/article/details/52098981

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

int friends, groups;
int iMap[N][N];
bool vis[N];
int links[N];
char useless[N];
char uselessChar;
int numx, numy;
int ans;

struct Node
{
	int l;
	int s[N];
}a[N];

bool dfs(int x, int mid)
{
	for(int y=1;y<=numy;y++){
		if(iMap[x][y] && !vis[y]){
			vis[y] = 1;
			if(a[y].l < mid){
				a[y].s[a[y].l++] = x;
				return false;
			}
			for(int i=0;i<a[y].l;i++){
				if(!dfs(a[y].s[i], mid)){
					a[y].s[i] = x;
					return false;
				}
			}
		}
	}
	return true;
}

//返回，该二分图是否可以在一mid为上限时完成匹配
bool search(int mid)
{
	ans = 0;
	memset(a, 0, sizeof(a));
	for(int x=1;x<=numx;x++){
		memset(vis, 0, sizeof(vis));
		if(dfs(x, mid)){
			return false;
		}
	}
	return true;
}

int main(void)
{
	while(scanf("%d%d", &friends, &groups)){
		if(friends == 0 && groups == 0) break;
		memset(iMap, 0, sizeof(iMap));
		for(int i=1;i<=friends;i++){
			scanf("%s", useless);
			int group;
			while(scanf("%d%c", &group, &uselessChar)){
				iMap[i][group+1] = 1;
				if(uselessChar == '\n'){
					break;
				}
			}
		}
		int l = 0, r = friends, ans = friends;
		numx = friends;
		numy = groups;
		while(l <= r){//二分来找所求的数字
			int mid = (l + r) >> 1;
			if(search(mid)){
				ans = mid;
				r = mid - 1;
			}else{
				l = mid + 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}