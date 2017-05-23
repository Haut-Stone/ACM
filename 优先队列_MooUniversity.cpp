/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-06 17:31:31
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-20 13:02:38
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

#define INPUT_TEST freopen("in.txt", "r", stdin)

const int MAXN = 100010;

int N;
int C;
int F;
int f1[MAXN];
int f2[MAXN];

struct Node
{
	int s;
	int c;
	bool operator < (const Node &a ) const{
		return c < a.c;
	}
}p[MAXN];

bool cmp(const Node &a, const Node &b)
{
	return a.s < b.s;
}

priority_queue<Node> q1, q2;

void solve()
{

	sort(p, p+C, cmp);//按成绩排序,成绩高的同学在前
	int sum1 = 0;
	int sum2 = 0;
	int ans = -1;
	memset(f1, 0, sizeof(f1));
	memset(f2, 0, sizeof(f2));
	for(int i=0;i<C;i++){
		if(i < N/2){
			q1.push(p[i]);
			sum1 += p[i].c;
			continue;
		}
		f1[i]=sum1;   //i之前的n/2的最小值
		if(p[i].c>=q1.top().c) continue;
		sum1-=q1.top().c;  //如果i比当前堆中最大元素小，需要更新
		q1.pop();
		sum1+=p[i].c;
		q1.push(p[i]);
	}
	for(int i=C-1;i>=0;i--){
		if(i>C-1-N/2){
			q2.push(p[i]);
			sum2+=p[i].c;
			continue;
		}
		f2[i]=sum2;
		if(p[i].c>=q2.top().c) continue;
		sum2-=q2.top().c;
		q2.pop();
		sum2+=p[i].c;
		q2.push(p[i]);
	}
	for(int i=C-1-N/2;i>=N/2;i--){
		if(f1[i]+f2[i]+p[i].c<=F){
			ans=p[i].s;break;
		}
	}
	printf("%d\n",ans);
}

int main(void)
{
	// INPUT_TEST;
	while(~scanf("%d%d%d", &N, &C, &F)){
		for(int i=0;i<C;i++){
			scanf("%d%d", &p[i].s, &p[i].c);
		}
		solve();
	}
	return 0;
}