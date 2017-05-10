/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-10 18:14:04
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-10 18:19:11
*/

//这道题其实就是求树的直径，只要想到就好做了，两次dfs就好了。
//题目:http://qscoj.cn/problem/129/
//题解:http://www.cnblogs.com/qscqesze/p/6831153.html

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

#define INPUT_TEST freopen("in.txt", "r", stdin)

struct edge
{
	int to;
	int cost;
};

vector<edge> e[201000];
int farthest;
int ans;

void dfs(int x, int pre, int dis)
{
	for(int i=0;i<e[x].size();i++){
		int xx = e[x][i].to;
		if(xx == pre){
			continue;
		}
		dfs(xx, x, dis+e[x][i].cost);
	}
	if(dis > ans){
		ans = dis;
		farthest = x;
	}
}

int main(void)
{
	// INPUT_TEST;
	int n;
	while(~scanf("%d",&n)){
		
		for(int i=0;i<n;i++){
			e[i].clear();
		}
		for(int i=0;i<n-1;i++){
			int x;
			int y;
			edge t;
			cin>>x>>y>>t.cost;
			t.to = y-1;
			e[x-1].push_back(t);
			t.to = x-1;
			e[y-1].push_back(t);
		}
		ans = 0;
		dfs(0, -1, 0);
		dfs(farthest, -1, 0);
		printf("%.1f\n", (double)ans/2);
	}
	return 0;
}