/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-13 17:13:12
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-24 10:35:04
*/

//HDU 4027
//可是Re不懂为什么
//http://blog.csdn.net/kirito_acmer/article/details/46239925
//题意：给你N个数，有M个操作，操作有两类，（1）"0 l r"，表示将区间[l,r]里的每个数都开根号。
//（2）"1 l r"，表示查询区间[l,r]里所有数的和。

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
#define lid (id<<1)
#define rid (id<<1|1)
using namespace std;

const int N = 100010;
int leafNum;
int opNum;
long long a[N];

struct Node
{
	int l;
	int r;
	long long sum;
}segTree[N*16];

void push_up(int id)
{
	segTree[id].sum = segTree[lid].sum + segTree[rid].sum;
}

void build(int id, int l, int r)
{	
	segTree[id].l = l;
	segTree[id].r = r;
	if(l == r){
		segTree[id].sum = a[l];//到达叶子时直接返回
		return;
	}
	int mid = (segTree[id].l + segTree[id].r) >> 1;
	build(lid, l, mid);
	build(rid, mid+1, r);
	push_up(id);//对节点求和
}

long long querySum(int id, int l, int r)
{
	if(segTree[id].l == l && segTree[id].r == r){
		return segTree[id].sum;//单个区间的话，直接返回
	}
	int mid = (segTree[id].l + segTree[id].r) >> 1;
	if(r <= mid){
		return querySum(lid, l, r);
	}
	if(l > mid){
		return querySum(rid, l, r);
	}
	return querySum(lid, l, mid) + querySum(rid, mid+1, r);
}

void sqrtNum(int id, int j)
{
	//更新到底了
	if(segTree[id].l == segTree[id].r){
		segTree[id].sum = a[segTree[id].l] = (int)(sqrt(1.0*a[segTree[id].l]));
        return;  
	}
	int mid = (segTree[id].l + segTree[id].r) >> 1;
	if(j > mid){
		sqrtNum(rid, j);
	}else{
		sqrtNum(lid, j);
	}
	push_up(id);
}

void update(int id, int l, int r)
{
	if(segTree[id].l == l && segTree[id].r == r){
		if(segTree[id].sum == segTree[id].r - segTree[id].l + 1){
			return;//全部都是1的话就直接返回,没有必要再开根号了
		}else{
			for(int j=segTree[id].l;j<=segTree[id].r;j++){
				if(a[j] == 1) continue;
				sqrtNum(1, j);
			}
		}
		return;
	}	
	int mid = (segTree[id].l + segTree[id].r) >> 1;
	if(r <= mid){
		update(lid, l, r);
	}else if(l > mid){
		update(rid, l, r);
	}else{
		update(lid, l, mid);
		update(rid, mid+1, r);
	}
}

int main(void)
{
	int cas = 1;
	while(~scanf("%d", &leafNum)){
		for(int i=1;i<=leafNum;i++){
			scanf("%lld", &a[i]);
		}
		build(1, 1, leafNum);//建树
		scanf("%d", &opNum);
		int op, l, r;
		printf("Case #%d:\n", cas++);
		for(int i=0;i<opNum;i++){
			scanf("%d%d%d", &op, &l, &r);
			if(op == 1){
				long long ans = querySum(1, l, r);//求和
				printf("%lld\n", ans);
			}else{
				update(1, l, r);//开方
			}
		}
	}
	return 0;
}