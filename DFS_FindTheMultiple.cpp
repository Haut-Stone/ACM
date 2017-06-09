/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-08 18:56:18
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-08 19:13:26
*/

//POJ 1426
//很简单的一个深搜找数字的过程。
//但是注意，搜到第19层就要返回了，不然数据类型装不下。

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

bool found;

void dfs(unsigned long long t, int n, int k)
{
	if(found) return;
	if(t%n == 0){
		printf("%llu\n", t);
		found = true;
		return;
	}
	if(k == 19) return;
	dfs(t*10, n, k+1);
	dfs(t*10+1, n, k+1);
}


int main(void)
{
	int n;
	while(cin>>n, n){
		found = false;
		dfs(1, n ,0);
	}
    return 0;
}