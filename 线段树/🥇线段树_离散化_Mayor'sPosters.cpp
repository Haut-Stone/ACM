/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-12 19:50:59
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-29 11:13:02
*/

//POJ 2528
//通过这道题，第一次接触离散化，还是蛮有意义的一道题
//题意：不断的往区间上面贴海报，问到最后能看见的海报有几张？
//这道题一定会印象深刻的

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
#define INPUT_TEST freopen("/Users/li/GitHub/ACM/线段树/data/线段树_离散化_Mayor'sPosters.1.dat", "r", stdin)
#define rid (id<<1|1)
#define lid (id<<1)
using namespace std;

const int N = 60000;
struct Node
{
	int l, r;
	int color;
}segTree[N*12];

struct Post
{
	int l;
	int r;
}posts[N];

int n, cnt;
int a[N];
int b[N];
int c[N];
int cnt2;
map<int, int> mapping;

void build(int id, int l, int r)
{
	segTree[id].l = l;
	segTree[id].r = r;
	segTree[id].color = 0;
	if(l == r){
		return;
	}else{
		int mid = (segTree[id].l + segTree[id].r) >> 1;
		build(lid, l, mid);
		build(rid, mid+1, r);
	}
}

void update(int id, int l, int r, int color)
{
	if(segTree[id].l == l && segTree[id].r == r){
		segTree[id].color = color;
		return;
	}
	int mid = (segTree[id].l + segTree[id].r) >> 1;
	//之前有颜色的话就把颜色向下传递
	if(segTree[id].color != 0){
		segTree[lid].color = segTree[rid].color = segTree[id].color;
		segTree[id].color = 0;
	}
	
	if(r <= mid){
		update(lid, l, r, color);
	}else if(l > mid){
		update(rid, l, r, color);
	}else{
		update(lid, l, mid, color);
		update(rid, mid+1, r, color);
	}
}

void query(int id, int l, int r)
{
	if(segTree[id].l == segTree[id].r){
		b[cnt2++] = segTree[id].color;
		return;
	}else if(segTree[id].color != 0){
		segTree[lid].color = segTree[rid].color = segTree[id].color;
		segTree[id].color = 0;
	}
	int mid = (segTree[id].l + segTree[id].r) >> 1;
	if(r <= mid){
		query(lid, l, r);
	}else if(l > mid){
		query(rid, l, r);
	}else{
		query(lid, l, mid);
		query(rid, mid+1, r);
	}
}

int main(void)
{
//	auto start = clock();
	int T;
	INPUT_TEST;
	scanf("%d", &T);
	while(T--){
		memset(b, 0, sizeof(b));
		int cnt3 = 1;
		scanf("%d", &n);
		for(int i=1;i<=n;i++){
			scanf("%d%d", &posts[i].l, &posts[i].r);
			c[cnt3++] = posts[i].l;
			c[cnt3++] = posts[i].r;
		}
		sort(c+1, c+cnt3);
		cnt = 1;
		for(int i=1;i<cnt3;i++){
			if(c[i] != c[i+1]){
				a[cnt++] = c[i];
			}
		}
		build(1, 1, cnt-1);
		for(int i=1;i<cnt;i++){
			mapping[a[i]] = i;
		}
		for(int i=1;i<=n;i++){
			update(1, mapping[posts[i].l], mapping[posts[i].r], i);
		}
		cnt2 = 0;
		int ans = 0;
		query(1, 1, cnt-1);
		sort(b, b+cnt2);
		for(int i=0;i<cnt2;i++){
			if(b[i] != b[i+1]){
				ans++;
			}
		}
		printf("%d\n", ans);
	}
//	cout << (clock() - start) / (double)CLOCKS_PER_SEC;
	return 0;
}
