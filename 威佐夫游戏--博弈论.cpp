/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2016 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-22 10:54:09
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-22 11:12:19
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;


int main(void)
{
	int a, b;
	int m, k;

	while(scanf("%d%d", &a, &b) != EOF){	
		if(a>b){
			a^=b;
			b^=a;
			a^=b;
		}
		//核心代码
		//黄金分割原理
		m = b - a;
    	k = (int)(m * (1 + sqrt(5)) / 2.0);
    	//核心代码
    	printf("%c\n", a == k ? '0':'1');
	}
    return 0;
}