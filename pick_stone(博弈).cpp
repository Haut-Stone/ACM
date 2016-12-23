/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2016 SJH. All rights reserved.
*
* @Author: li
* @Date:   2016-12-23 21:12:29
* @Last Modified by:   li
* @Last Modified time: 2016-12-23 21:28:24
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;


int main(void)
{
	int t, n, k;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &k);
		if(n%(k+1) == 0){
			printf("B\n");
		}else{
			printf("A\n");
		}
	}
    return 0;
}