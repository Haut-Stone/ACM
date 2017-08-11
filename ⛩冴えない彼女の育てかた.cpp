/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-28 19:01:10
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-11 20:41:14
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

const int N = 110;

bool bc(long long n)
{
	for(long long i=2;i*i<=n;i++){
		if(n % i == 0){
			return false;
		}
	}
	return true;
}

int main(void)
{
	int n;
	while(~scanf("%d", &n)){
		if(n % 2 == 0){
			printf("2\n");
			continue;
		}
	}
	return 0;
}