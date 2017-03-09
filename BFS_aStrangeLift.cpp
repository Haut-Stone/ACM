/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-09 20:42:06
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-09 21:23:59
*/

//http://vj.sdutacm.org/contest/view.action?cid=62917#problem/E
//最简单的bfs模版题，但是你不看题解会做吗？？？
//不要自欺欺人

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
using namespace std;

const int LEN  = 210;
bool vis[LEN];
int K[LEN];
int ans;
int N, A, B;
bool flag;


struct Node
{
	int x;
	int steps;
};


int bfs(int x, int steps)
{
	queue<Node>Q;
	Node n1, n2, solo;
	solo.x = x;
	solo.steps = steps;
	Q.push(solo);
	vis[solo.x] = true;
	while(!Q.empty()){
		solo = Q.front();
		Q.pop();

		if(solo.x == B){
			flag = true;
			return solo.steps;
		}

		n1.x = solo.x + K[solo.x];
		n2.x = solo.x - K[solo.x];

		if(n1.x > 0 && n1.x <= N && !vis[n1.x]){
			vis[n1.x] = true;
			n1.steps = solo.steps + 1;
			Q.push(n1);
		}

		if(n2.x > 0 && n2.x	<= N && !vis[n2.x]){
			vis[n2.x] = true;
			n2.steps = solo.steps + 1;
			Q.push(n2);
		}
	}
	return 0;
}

int main(void)
{
	while(~scanf("%d", &N)){
		if(N == 0) return 0;
		scanf("%d%d", &A, &B);
		for(int i=1;i<=N;i++){
			scanf("%d", &K[i]);
		}
		memset(vis, 0, sizeof(vis));
		flag = false;
		ans = bfs(A, 0);
		if(flag){
			printf("%d\n", ans);
		}else{
			printf("-1\n");
		}
	}
    return 0;
}