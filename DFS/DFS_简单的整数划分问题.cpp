/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-30 14:37:47
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-30 14:38:08
*/

//
//

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

int n;
int ans;
void dfs(int l, int r, int sum, int first)
{
	if(l > first){
		return;
	}else{
		first = l;
	}
	if(sum+r == n && l >= r && first >= l && first >= r){
		ans++;
	}
	if(r == 1){
		return;
	}
	for(int i=1;i<r;i++){
		dfs(r-i, i, sum+(r-i), first);
	}
}

int main(void)
{
	while(~scanf("%d", &n)){
		ans = 0;
		dfs(n, n, 0, n);
		printf("%d\n", ans);
	}
	return 0;
}