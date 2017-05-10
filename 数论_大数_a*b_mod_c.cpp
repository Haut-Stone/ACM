/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-09 18:29:20
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-10 14:01:29
*/

//处理大数情况下的问题，1e18的情况下有效。
//运用了二进制，说明点击下方的链接。a*b mod c = a*(2*b0 + 2*b2 + ... + 2*bn) mod c
//每次乘以2的话就不会爆long long 了。
//然后还有另外一种处理大大数的方法也在链接里面。
//http://www.360doc.com/content/14/0308/22/3520047_358892807.shtml

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

long long mul(long long a, long long b, long long c)
{
	long long result = 0;
	long long tmp;
	tmp = a%c;
	while(b){
		if(b&1){//如果最后一位是1
			result += tmp;
			if(result >= c){
				result -= c;
			}
		}
		tmp<<=1;
		if(tmp >= c){//计算a*2^n的
			tmp-=c;
		}
		b>>=1;
	}
	return result;
}


int main(void)
{
	INPUT_TEST;
	long long a;
	long long b;
	long long p;
	while(~scanf("%lld%lld%lld", &a, &b, &p)){
		printf("%lld\n",mul(a,b,p));
	}	
	return 0;
}