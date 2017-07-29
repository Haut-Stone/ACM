/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-01-22 11:12:17
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-07-29 20:35:19
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

int n = 8;
int num[20] = {0,5,3,7,9,6,4,1,2};
int tree[20];

int lowBit(int x)
{
	return x&(-x);
}

void add(int x, int val)
{
	for(;x<=n;x+=lowBit(x)){
		tree[x] += val;
	}
}

int query(int x)
{
	int ans = 0;
	for(;x>0;x-=lowBit(x)){
		ans += tree[x];
	}
	return ans;
}

int main(void)
{
	for(int i=1;i<=n;i++){
		add(i, num[i]);
	}
	for(int i=1;i<=n;i++){
		int ans = query(i);
		printf("%d\n", ans);
	}
	return 0;
}