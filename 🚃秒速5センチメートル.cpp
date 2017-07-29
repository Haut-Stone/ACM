/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-28 11:10:13
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-28 23:01:33
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
#define rid (id<<1|1)
#define lid (id<<1)
using namespace std;

const int N = 100010;
struct Node
{
	int l, r;
	int color;
}segTree[N*4];

struct Post
{
	int l;
	int r;
}posts[N];

int n, cnt;
int book[10000010];
int a[N];
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

	

}

int main(void)
{
	int T;
	scanf("%d", &T);
	while(T--){
		memset(book, 0, sizeof(book));
		cnt = 1;
		scanf("%d", &n);
		for(int i=1;i<=n;i++){
			scanf("%d%d", &posts[i].l, &posts[i].r);
			if(!book[posts[i].l]){
				a[cnt++] = posts[i].l;
				book[posts[i].l] = 1;
			}
			if(!book[posts[i].r]){
				a[cnt++] = posts[i].r;
				book[posts[i].r] = 1;
			}
		}
		sort(a+1, a+cnt);
		build(1, 1, cnt-1);
		for(int i=1;i<cnt;i++){
			mapping[a[i]] = i;
		}
		for(int i=1;i<=n;i++){
			update(1, mapping[posts[i].l], mapping[posts[i].r], i);
		}
	}
	return 0;
}
