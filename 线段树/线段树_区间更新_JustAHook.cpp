/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-13 14:07:18
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-13 14:35:51
*/

//HDU 1698
//线段树区间更新的基础题
//http://blog.csdn.net/libin56842/article/details/13511181

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

const int maxn = 100000 + 10;

int n, sum;

struct node
{
	int l, r, n;
}a[maxn<<2];

void init(int l, int r, int i)
{
	a[i].l = l;
	a[i].r = r;
	a[i].n = 1;
	if(l != r){
		int mid = (l+r) >> 1;
		init(l, mid, 2*i);
		init(mid+1, r, 2*i+1);
	}
}

void insert(int i, int x, int y, int m)
{
	if(a[i].n == m)
		return;
	if(a[i].l == x && a[i].r == y){
		a[i].n = m;
		return;
	}

	if(a[i].n != -1){
		a[2*i].n = a[2*i+1].n = a[i].n;
		a[i].n = -1;
	}

	int mid = (a[i].l + a[i].r) >> 1;
	if(x > mid){
		insert(2*i+1, x, y, m);
	}else if(y <= mid){
		insert(2*i, x, y, m);
	}else{
		insert(2*i, x, mid, m);
		insert(2*i+1, mid+1, y, m);
	}
}


int find(int i)
{
	if(a[i].n != -1)
		return (a[i].r - a[i].l + 1)*a[i].n;
	else
		return find(i*2) + find(i*2+1);
}


int main(void)
{
	int t, k, x, y, m;
	int cas = 1;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		init(1, n, 1);
		while(k--){
			scanf("%d%d%d", &x, &y, &m);
			insert(1, x, y, m);
		}
		printf("Case %d: The total value of the hook is %d.\n", cas++, find(1));
	}
	return 0;
}