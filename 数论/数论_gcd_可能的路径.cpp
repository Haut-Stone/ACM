/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-18 10:12:51
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-18 10:14:34
*/

//找到规律之后可以发现，只要求俩个点的最大公约数是否一样就行了
//https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1247

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

long long  x_1, x_2, y_1, y_2;

long long igcd(long long a, long long b){
	if(b == 0) return a;
	return igcd(b, a%b);
}

int main(void){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%lld%lld%lld%lld", &x_1, &y_1, &x_2, &y_2);
		long long temp1;
		long long temp2;
		temp1 = igcd(x_1, y_1);
		temp2 = igcd(x_2, y_2);
		if(temp2 == temp1){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
}
