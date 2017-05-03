/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-01 16:46:31
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-02 12:49:49
*/

//http://poj.org/problem?id=3190
//题意：一些🐄，要在指定的时间内挤牛奶，而一个机器同时只能对一个奶牛工作，给你每头奶牛的指定时间，问你最少需要多少机器。

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

const int N = 60000;

int n;
int use[N];

struct Node
{
	int l;
	int r;
	int pos;
	bool  operator < (const Node &a)const{
		if(r == a.r){
			return l > a.l;
		}
		return r > a.r;
	}
}a[N];

priority_queue<Node > q;

bool cmp(Node a, Node b)
{
	if(a.l == b.l){
		return a.r  < b.r;
	}
	return a.l < b.l;
}

int main(void)
{
	// INPUT_TEST;

	while(~scanf("%d", &n)){
		for(int i=0;i<n;i++){
			scanf("%d%d", &a[i].l, &a[i].r);
			a[i].pos = i;
		}
		
		sort(a, a+n, cmp);
		q.push(a[0]);

		int ans = 1;
		use[a[0].pos] = 1;
		for(int i=1;i<n;i++){
			if(!q.empty() && q.top().r < a[i].l){
				use[a[i].pos] = use[q.top().pos];
				q.pop();
			}else{
				ans++;
				use[a[i].pos] = ans;
			}
			q.push(a[i]);
		}
		printf("%d\n", ans);
		for(int i=0;i<n;i++){
			printf("%d\n", use[i]);
		}
		while(!q.empty()){
			q.pop();
		}
	}
    return 0;
}