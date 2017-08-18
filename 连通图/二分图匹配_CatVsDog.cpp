/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-16 10:33:01
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-16 10:39:28
*/

//POJ 3829
//根据关系建图，然后来一遍匈牙利算法就行了。但是建图的时候要注意方法，建立矛盾图

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

std::vector<int> vec[N];
char like[N][10];
char dislike[N][N];
int links[N];
bool vis[N];

bool dfs(int x)
{
	for(int i=0;i<vec[x].size();i++){
		int y = vec[x][i];
		if(!vis[y]){
			vis[y] = 1;
			if(links[y] == 0 || dfs(links[y])){
				links[y] = x;
				return true;
			}
		}
	}
	return false;
}

int search(int n)
{
	int ans = 0;
	memset(links, 0, sizeof(links));
	for(int x=0;x<n;x++){
		memset(vis, 0, sizeof(vis));
		if(dfs(x)){
			ans++;
		}
	}
	return ans;
}

int main(void)
{
	int n, m, p;
	while(~scanf("%d%d%d", &n, &m, &p)){
		memset(vec, 0, sizeof(vec));
		for(int i=0;i<p;i++){
			scanf("%s%s", like[i], dislike[i]);
		}
		for(int i=0;i<p;i++){
			for(int j=i+1;j<p;j++){
				if(!strcmp(like[i], dislike[j]) || !strcmp(like[j], dislike[i])){
					vec[i].push_back(j);
					vec[j].push_back(i);
				}
			}
		}
		int ans = search(p);
		printf("%d\n", p - ans/2);
	}
	return 0;
}