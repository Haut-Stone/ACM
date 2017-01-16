/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2016 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-16 18:14:18
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-16 21:33:29
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn = 3e5;

char Str[maxn];
char test[maxn];
int len1;
int len2;
int p[maxn];

int manacher();
int init();

int main(void)
{
	int ans = 0;
	scanf("%s", Str);
	len1 = strlen(Str);
	init();
	ans = manacher();
	printf("%d\n", ans);
    return 0;
}

int init()
{	
	//初始化字符串
	test[0] = '$';
	test[1] = '#';
	for(int i=0;i<len1;i++){
		test[2*i+2] = Str[i];
		test[2*i+3] = '#';
	}
	len2 = len1*2 + 2;
	test[len2] = '*';
	return 0;
}

int manacher()
{
	//核心算法
	int id = 0;
	int ans = 0;
	int max = 0;
	for(int i=1;i<len2;i++){
		if(max > i){	
			p[i] = min(p[2*id - i], max - i);
		}else{
			p[i] = 1;
		}
		for(;test[i+p[i]] == test[i-p[i]];p[i]++);
		if(p[i] + i > max){
			max = p[i]+i;
			id = i;
		}
	}
	for(int i=0;i<len2;i++){
		if(ans < p[i]) ans = p[i];
	}
	return ans-1;//减一之后才是实际值
}