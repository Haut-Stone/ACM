/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2016 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-16 22:17:04
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-16 22:18:58
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

//公式题
int main(void)
{
	long long n;
	scanf("%lld", &n);
	long long ans = log10((long double)(sqrt(2*M_PI*n)))+n*log10((long double)n/M_E);//只有靠公式了。
	cout<<ans+1<<endl;
    return 0;
}