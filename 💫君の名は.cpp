/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
*
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-03 12:15:58
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-09-01 14:25:59
*/

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#include <cmath>
#include <queue>
#include <map>
using namespace std;

const int N = 11000;

char str[N];
int book[N];

int main(void)
{
	while(~scanf("%s", str)){
		int len = (int)strlen(str);
		int sum = 1;
		int mod = 0;
		int max = 0;
		memset(book, 0, sizeof(book));
		for(int i=0;i<len;i++){
			book[(int)str[i]]++;
		}
		for(int i=0;i<300;i++){
			if(book[i] > max){
				max = book[i];
				mod = i;
			}
		}
		for(int i=1;i<len;i++){
			int temp = ((int)str[i])^((int)str[i-1]);
			sum *= temp;
			sum %= mod;
		}
		printf("%d\n", sum);
	}
	return 0;
}
