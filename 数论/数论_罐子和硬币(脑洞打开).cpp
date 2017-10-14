/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-13 22:49:10
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-13 22:49:45
*/

//https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1246
//http://blog.csdn.net/qingshui23/article/details/51853530

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

int main(void)
{
	long long n, k, c;
	while(cin>>n>>k>>c){
		long long ans = k/n*n;
		if(ans >= c){
			printf("%lld\n", c);
		}else{
			ans = (n - k/(k/n+1)) + c;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
