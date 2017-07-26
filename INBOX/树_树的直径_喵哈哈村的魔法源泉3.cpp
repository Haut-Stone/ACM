/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-10 18:14:04
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-10 21:39:22
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

const int N = 201000;

struct Node
{
	int to;
	int dis;
};

vector<Node> edge[N];
int farthest;//最远的叶子节点
int ans;
int n;

void init()
{
	for(int i=0;i<N;i++){
		edge[i].clear();
	}
	ans = 0;
}

//好简单的一个dfs啊
//

void dfs(int x, int preX, int dis)
{
	for(int i=0;i<edge[x].size();i++){
		int nextX = edge[x][i].to;//将要去往的点
		if(nextX == preX){//跳过来时的节点
			continue;
		}
		dfs(nextX, x, dis + edge[x][i].dis);
	}
	if(dis > ans){
		ans = dis;
		farthest = x;
	}
}

void read()
{
	for(int i=0;i<n-1;i++){
		int u;
		int v;
		Node temp; 
		scanf("%d%d%d", &u, &v, &temp.dis);
		temp.to = v;
		edge[u].push_back(temp);
		temp.to = u;
		edge[v].push_back(temp);
	}
}

int main(void)
{
	INPUT_TEST;
	while(~scanf("%d", &n)){
		init();
		read();
		dfs(1, -1, 0);
		dfs(farthest, -1, 0);
		printf("%.1f\n", (double)ans / 2);
	}
	return 0;
}