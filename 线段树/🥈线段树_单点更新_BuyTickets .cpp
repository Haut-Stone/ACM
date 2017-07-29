/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-29 11:32:04
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-29 13:20:57
*/

//POJ 2828
//这道题主要的思考在于要从后面开始向前update

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

const int N = 200005;

struct Info
{
	int pos;//pos代表应该插到当前区间的第几个空位中
	int value;
}a[N];

struct Node
{
	int l, r;
	int capacity;
}segTree[N*10];

int n;
int ans[N];

void build(int id, int l ,int r)
{
	segTree[id].l = l;
	segTree[id].r = r;
	segTree[id].capacity = (r - l + 1);
	if(l == r){
		return;
	}
	int mid = (segTree[id].l + segTree[id].r) >> 1;
	build(lid, l, mid);
	build(rid, mid+1, r);
}

void pushUp(int id)
{
	segTree[id].capacity = segTree[lid].capacity + segTree[rid].capacity;
}

void update(int id, int pos, int value)
{
	if(segTree[id].l == segTree[id].r){
		ans[segTree[id].l] = value;
		segTree[id].capacity = 0;
		return;
	}
	if(segTree[lid].capacity >= pos){
		update(lid, pos, value);
	}else{
		update(rid, pos - segTree[lid].capacity, value);
	}
	pushUp(id);
}

int main(void)
{
	while(~scanf("%d", &n)){
		for(int i=1;i<=n;i++){
			scanf("%d%d", &a[i].pos, &a[i].value);
			a[i].pos++;
		}
		build(1, 1, n);
		for(int i=n;i>=1;i--){
			update(1, a[i].pos, a[i].value);
		}
		for(int i=1;i<=n;i++){
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}