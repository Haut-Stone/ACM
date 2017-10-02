/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-01 13:21:47
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-01 13:22:22
*/

//很有意思的有道题，因为数据特别的，很明显就是规律题，运用了3的倍数的性质

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <stack>
#include <vector>
using namespace std;

const int N = 1010;
const int MOD = 2;

char str[N];

int main(void)
{
	while(~scanf("%s", str)){
		int sum = 0;
		int len = strlen(str);
		for(int i=0;i<len;i++){
			sum += str[i] - '0';
		}
		if(sum % 3 == 0){
			printf("%d\n", 0);
		}else{
			printf("%d\n", 1);
		}
	}
	return 0;
}
