/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-06-03 12:15:58
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-08-09 17:39:48
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
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;

const int N = 100010;

struct Node
{
	int l;
	int r;
}line[N];

bool cmp(Node a, Node b)
{
	if(a.l == b.l) return a.r > b.r;
	return a.l < b.l;
}

int main(void)
{
	int n;
	while(~scanf("%d", &n)){
		for(int i=0;i<n;i++){
			scanf("%d%d", &line[i].l, &line[i].r);
		}
		sort(line, line+n, cmp);
		int lastPos = line[0].r;
		int ans = 0;
		for(int i=1;i<n;i++){
			ans = max(ans, min(lastPos, line[i].r) - line[i].l);
			lastPos = max(lastPos, line[i].r);
		}
		printf("%d\n", ans);
	}
	return 0;
}