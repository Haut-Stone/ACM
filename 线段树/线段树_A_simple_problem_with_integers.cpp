/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-12 18:09:05
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-12 19:14:09
*/

//POJ 3468
//比起模版题稍微有些难度。逐个更新到叶子结点的话，是一定会超时的。
//可以给一个区间同时加一个数，或者查询一个区间中所有数的和

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
#define lid (id<<1)
#define rid (id<<1|1)
using namespace std;


const int MAXN = 100010;

struct Node
{
	int l;
	int r;
	long long nSum;
	long long Inc;
}segTree[4*MAXN];

int num[MAXN];
int leafNum;
int opNum;
char option;

void push_up(int id)
{
	segTree[id].nSum = segTree[lid].nSum + segTree[rid].nSum;
}

void build(int id, int l, int r)
{
	segTree[id].l = l;
	segTree[id].r = r;
	segTree[id].Inc = 0;
	if(l == r){
		segTree[id].nSum = num[l];
		return;
	}
	int mid = (segTree[id].l + segTree[id].r) >> 1;
	build(lid, l, mid);
	build(rid, mid+1, r);
	push_up(id);
}

void update(int id, int l, int r, long long val)
{
	if(segTree[id].r == r && segTree[id].l == l){
		segTree[id].Inc += val;
		return;
	}
	segTree[id].nSum += val*(r-l+1);
	int mid = (segTree[id].r + segTree[id].l) >> 1;
	if(r <= mid){
		update(lid, l, r, val);
	}else if(l > mid){
		update(rid, l, r, val);
	}else{
		update(lid, l, mid, val);
		update(rid, mid+1, r, val);
	}
}


long long query(int id, int l, int r)
{
	if(segTree[id].l == l && segTree[id].r == r){
		return segTree[id].nSum + (r-l+1) * segTree[id].Inc;
	}
	segTree[id].nSum += (segTree[id].r - segTree[id].l + 1)*segTree[id].Inc;
	int mid = (segTree[id].r + segTree[id].l) >> 1;
	update(lid, segTree[id].l, mid, segTree[id].Inc);
	update(rid, mid+1, segTree[id].r, segTree[id].Inc);
	segTree[id].Inc = 0;
	if(r <= mid){
		return query(lid, l, r);
	}
	if(l > mid){
		return query(rid, l, r);
	}
	return query(lid, l, mid) + query(rid, mid+1, r); 
}


int main(void)
{
	while(~scanf("%d%d", &leafNum, &opNum)){
		for(int i=1;i<=leafNum;i++){
			scanf("%d", &num[i]);
		}
		build(1, 1, leafNum);
		for(int i=1;i<=opNum;i++){
			cin>>option;
			if(option == 'Q'){
				int t1, t2;
				scanf("%d%d", &t1, &t2);
				printf("%lld\n", query(1, t1, t2));
			}else if(option == 'C'){
				int t1, t2, t3;
				scanf("%d%d%d", &t1, &t2, &t3);
				update(1, t1, t2, t3);
			}else{
				break;
			}
		}
	}
	return 0;
}