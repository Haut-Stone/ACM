/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
*
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-22 11:12:17
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-29 15:51:43
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
#define lid (id<<1)
#define rid (id<<1|1)
using namespace std;

const int N = 20;
const int INF = 99999999;

struct Info
{
	char name[30];
	int value;
}children[N];

struct Node
{
	int l, r;
	int alive;
}segTree[N*4];

int n;
int startIndex;
int childrenPassed;
int pos;

void build(int id, int l, int r)
{
	segTree[id].l = l;
	segTree[id].r = r;
	segTree[id].alive = (r - l + 1);
	if(segTree[id].l == segTree[id].r){
		return;
	}
	int mid = (segTree[id].l + segTree[id].r) >> 1;
	build(lid, l, mid);
	build(rid, mid+1, r);
}

void update(int id, int target)
{
	if(segTree[id].l == segTree[id].r){
		segTree[id].alive--;
		childrenPassed++;
		return;
	}
	int mid = (segTree[id].l + segTree[id].r) >> 1;
	if(target <= mid){
		update(lid, target);
	}else{
		update(rid, target);
	}
	segTree[id].alive = segTree[lid].alive + segTree[rid].alive;
}

int main(void)
{
	while(~scanf("%d%d", &n, &startIndex)){
		for(int i=1;i<=n;i++){
			scanf("%s%d", children[i].name, &children[i].value);
		}
		build(1, 1, n);
		childrenPassed = 0;
		pos = startIndex;
		for(int i=1;i<=pos;i++){
			update(1, pos);
		}
	}
	return 0;
}
