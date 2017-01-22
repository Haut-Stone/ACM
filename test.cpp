/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-22 11:12:17
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-22 19:21:13
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;


int main(void)
{
	int n;
	int ans = 0;
	int passLine;
	int a[10010];
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &passLine);
	for(int i=0;i<n;i++){
		if(a[i] >= passLine) ans++;
	}
	printf("%d\n", ans);
	return 0;
}