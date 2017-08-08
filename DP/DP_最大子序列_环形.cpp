/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-05 10:59:54
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-07 15:13:44
*/

//http://172.18.66.54:50015/JudgeOnline/problem.php?id=1286
//变个型就不会了。艹

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

const long long N = 100010;
long long a[N];

long long solve(long long n, long long all)
{
	long long thisSum = 0;
	long long maxSum = 0;
	for(int i=0;i<n;i++){
		thisSum += a[i];
		if(thisSum > maxSum) maxSum = thisSum;
		if(thisSum < 0) thisSum = 0;
	}
	
	thisSum = 0;
	long long maxSum2 = 0;
	for(int i=0;i<n;i++){
		thisSum -= a[i];
		if(thisSum > maxSum2) maxSum2 = thisSum;
		if(thisSum < 0) thisSum = 0;
	}
	
	return max(maxSum, all + maxSum2);
}

int main(void)
{
	long long n;
	while(~scanf("%lld", &n)){
		long long sum = 0;
		for(int i=0;i<n;i++){
			scanf("%lld", &a[i]);
			sum += a[i];
		}
		long long ans = solve(n, sum);
		printf("%lld\n", ans);
	}
	return 0;
}