/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-08 13:38:25
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-08 14:14:26
*/

//https://acm.zzuli.edu.cn/zzuliacm/problem.php?id=1734
//这里就是一个简单的dfs

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

const int N = 110;
int numberOfNode;
int value[N];
int vis[N];
int cnt;

vector<int> Imap[N];

void dfs(int now)
{
	for(int i=0;i<Imap[now].size();i++){
		int next = Imap[now][i];
		if(!vis[next] && value[now] <= value[next]){
			vis[next] = 1;
			cnt++;
			dfs(next);
		}
	}
	return;
}

void init()
{
	memset(vis, 0, sizeof(vis));
	memset(value, 0, sizeof(value));
	for(int i=1;i<=N;i++){
		Imap[i].clear();
	}
	cnt = 1;
}

void read()
{
	cin>>numberOfNode;
	for(int i=1;i<=numberOfNode;i++){
		cin>>value[i];
	}

	int x, y;	
	//处理点与点之间的边的关系
	for(int i=1;i<numberOfNode;i++){
		cin>>x>>y;
		int a = min(x, y);
		int b = max(x, y);
		Imap[a].push_back(b);
	}
}

int main(void)
{
	// INPUT_TEST;

	int T;
	cin>>T;
	while(T--){
		init();
		read();
		dfs(1);
		if(cnt == numberOfNode){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
    return 0;
}	