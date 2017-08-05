/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-05 09:12:38
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-05 09:13:19
*/

//http://172.18.66.54:50015/JudgeOnline/problem.php?id=1286
//这他妈就是个公式题，我有什么办法？我也很绝望啊。

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
int fibonacci[N];
int n;

int main(void)
{
	fibonacci[0] = 0;
	fibonacci[1] = fibonacci[2] = 1;
	for(int i=3;i<=30;i++){
		fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
	}
	while(~scanf("%d", &n)){
		if(n <= 25){
			printf("%d\n", fibonacci[n]);
		}else{
			double tmp;
			double s = (sqrt(5.0)+1.0)/2.0;
			tmp = -0.5*log(5.0)/log(10.0)+((double)n)*log(s)/log(10.0);
			tmp -= floor(tmp);
			tmp = pow(10.0,tmp);
			while(tmp < 10000){
				tmp *= 10;
			}
			printf("%05lld\n",(long long)tmp);
		}
	}
	return 0;
}