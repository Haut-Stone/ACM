/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-12 21:49:18
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-12 21:49:59
*/

//http://acm.ecnu.edu.cn/contest/11/problem/F/
//第一次明白区间贪心的妙处。。

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

const int N = 4000;

int n;
int m;
int k;
int ans;
int road[N];
int flag;

struct Node
{
	int l;
	int r;
	int need;
}interval[N];

bool cmp(const Node &a, const Node &b)
{
	if(a.r == b.r) return a.l < b.l;
	return a.r < b.r;
}

void init()
{
	memset(road, 0, sizeof(road));
	memset(interval, 0, sizeof(interval));
	ans = 0;
	flag = 0;
}

void read()
{
	cin>>n>>m>>k;
	int temp;
	
	for(int i=0;i<k;i++){
		scanf("%d", &temp);
		road[temp] = 1;//初始化路灯的位置
	}

	for(int i=0;i<m;i++){
		scanf("%d%d%d", &interval[i].l, &interval[i].r, &interval[i].need);
	}
}

int main(void)
{
	// INPUT_TEST;

	int T;
	int cas = 1;
	cin>>T;
	while(T--){
		init();
		read();
		sort(interval, interval+m, cmp);

		for(int i=0;i<m;i++){

			int have = 0;//已有的路灯数量
			for(int j=interval[i].l;j<=interval[i].r;j++){
				if(road[j] == 1) have++;
			}

			int temp = interval[i].r;

			while(temp >= interval[i].l && have < interval[i].need){
				if(road[temp] == 0){//如果这个地方之前没有路灯的话
					ans++;
					have++;
					road[temp] = 1;
				}
				temp--;
			}

			if(have < interval[i].need){
				flag = 1;
			}
		}
		if(flag){
			printf("Case %d: -1\n", cas);
		}else{
			printf("Case %d: %d\n", cas, ans);
		}
		cas++;
	}
	return 0;
}