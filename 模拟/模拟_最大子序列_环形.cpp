/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-05 10:59:54
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-05 11:01:01
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

const long long N=100005;
long long arr[N], t, n;
long long solve()
{
	long long cnt=0, sum=0;
	for(int i=0; i<n; i++){
		sum+=arr[i];
		if(sum>cnt) cnt=sum;
		if(sum<0) sum=0;
	}
	long long cnt1=0, sum1=0, all=0;
	for(int i=0; i<n; i++){
		all+=arr[i];
		sum1+=-arr[i];
		if(sum1>cnt1) cnt1=sum1;
		if(sum1<0) sum1=0;
	}
	return cnt>(all+cnt1)?cnt:all+cnt1;
}

int main()
{
	while(~scanf("%lld", &n)){
		for(long long i=0;i<n;i++){
			scanf("%lld", &arr[i]);
		}
		printf("%lld\n",solve());
	}
	return 0;
}
