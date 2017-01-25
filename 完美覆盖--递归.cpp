/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-25 14:19:25
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-25 14:32:13
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int horizontal(int n);
int vertical(int n);

int vertical(int n)
{
	if(n==0) return 0;
	if(n==1) return 1;
	return horizontal(n-1) + vertical(n-2);
}

int horizontal(int n)
{
	if(n == 0) return 1;
	if(n == 1) return 0;
	return 2 * vertical(n-1) + horizontal(n-2);
}

int count(int n)
{
	if(n==0) return 1;
	if(n%2) return 0;
	return horizontal(n) + vertical(n);
}

int main(void)
{
	int n;
	while(scanf("%d", &n) , n!=-1){
		printf("%d\n", count(n));
	}
    return 0;
}