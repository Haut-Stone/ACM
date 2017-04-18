/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-15 13:28:14
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-15 14:34:29
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
using namespace std;

#define INPUT_TEST freopen("in.txt", "r", stdin)

long long L, R;
int ans;
int temp;

void dfs(int L, int R,int index)
{
	if(L == R){
		return;
	}

	if(temp <= L && temp >= R) ans++;

	for(int i=0;i<=9;i++){
		
	}
}

int main(void)
{
	INPUT_TEST;
	int T;
	cin>>T;
	while(T--){
		scanf("%lld%lld", &L, &R);
		dfs(L, R, 0);
	}
    return 0;
}