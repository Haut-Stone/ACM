/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-16 15:18:31
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-16 15:19:41
*/

//这题好难啊。。。dinic算法还是不太懂
//POJ 2112
//http://blog.csdn.net/morgan_xww/article/details/6651368

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
const int INF = 0x3f3f3f3f;

int k, c, m;
int iMap[N][N];
bool vis[N];
int links[N];
bool path[N][N];

void buildGraph(int tmp)
{
	memset(path, false, sizeof(path));
	for(int i=1;i<=c;i++){
		for(int j=1;j<=k;j++){
			if(iMap[k+i][j] <= tmp){
				for(int t=1;t<=m;t++){
					path[i][(j-1)*m+t] = true;
				}
			}
		}
	}
}

bool dfs(int i)
{
	for(int j=1;j<=k*m;j++){
		if(path[i][j] && !vis[j]){
			vis[j] = true;
			if(links[j] == 0 || dfs(links[j])){
				links[j] = i;
				return true;
			}
		}
	}
	return false;
}

bool maxMatch()
{
	memset(links, 0, sizeof(links));
	for(int i=1;i<=c;i++){
		memset(vis, false, sizeof(vis));
		if(!dfs(i)){
			return false;
		}
	}
	return true;
}

void solve()
{
	int low = 1;
	int high = 200*(k+c);
	while(low < high){
		int mid = (low + high) / 2;
		buildGraph(mid);
		if(maxMatch()){
			high = mid;
		}else{
			low = mid + 1;
		}
	}
	printf("%d\n", low);
}

void floyd()
{
	int t = k+c;
	for(int h=1;h<=t;h++){
		for(int i=1;i<=t;i++){
			for(int j=1;j<=t;j++){
				if(iMap[i][j] > iMap[i][h] + iMap[h][j]){
					iMap[i][j] = iMap[i][h] + iMap[h][j];
				}
			}
		}
	}
}

int main(void)
{
	while(~scanf("%d%d%d", &k, &c, &m)){
		for(int i=1;i<=k+c;i++){
			for(int j=1;j<=k+c;j++){
				scanf("%d", &iMap[i][j]);
				if(iMap[i][j] == 0){
					iMap[i][j] = INF;
				}
			}
		}
		floyd();
		solve();
	}
	return 0;
}