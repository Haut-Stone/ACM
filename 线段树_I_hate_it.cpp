/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-12 16:16:27
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-12 17:08:01
*/

//HDU 1754
//求区间最大值。同样是一道用来入门的水题。

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
using namespace std;

#define lid (id<<1)
#define rid (id<<1|1)

const int N = 200010;

struct Node
{
	int l;
	int r;
	int max;
}segTree[N*4];

int opNum;
int leafNum;
int a[N];
char option;


void push_up(int id)
{
	segTree[id].max = max(segTree[lid].max, segTree[rid].max);
}

void update(int id, int x, int val)
{
	if(segTree[id].l == segTree[id].r){
		segTree[id].max = val;
		return;
	}
	int mid = (segTree[id].l + segTree[id].r) >> 1;
	if(x <= mid){
		update(lid, x, val);
	}else{
		update(rid, x, val);
	}
	push_up(id);
}

void bulid(int id, int l, int r)
{
	segTree[id].l = l;
	segTree[id].r = r;
	if(l == r){
		segTree[id].max = a[l];
		return;
	}
	int mid = (segTree[id].l + segTree[id].r) >> 1;
	bulid(lid, l, mid);
	bulid(rid, mid+1, r);
	push_up(id);
}

int query(int id, int l, int r)
{
	if(segTree[id].l == l && segTree[id].r == r){
		return segTree[id].max;
	}
	int mid = (segTree[id].l + segTree[id].r) >> 1;
	if(r <= mid){
		return query(lid, l, r);
	}
	if(l > mid){
		return query(rid, l, r);
	}
	return max(query(lid, l, mid), query(rid, mid+1, r));
}

int main(void)
{
	while(~scanf("%d%d", &leafNum, &opNum)){
		for(int i=1;i<=leafNum;i++){
			scanf("%d", &a[i]);
		}
		bulid(1, 1, leafNum);
		for(int i=1;i<=opNum;i++){
			getchar();
			scanf("%c", &option);
			if(option == 'U'){
				int t1, t2;
				scanf("%d%d", &t1, &t2);
				update(1, t1, t2);
			}else if(option == 'Q'){
				int t1, t2;
				scanf("%d%d", &t1, &t2);
				printf("%d\n", query(1, t1, t2));
			}else{
				break;
			}
		}
	}
	return 0;
}