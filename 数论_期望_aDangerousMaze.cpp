/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-21 13:10:59
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-21 13:11:14
*/

//LightOJ 1027
//求期望值，具体的题解见印象笔记。

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

const int N = 10100;

int n;
int a[N];
int numerator;
int denominator;
int door1;
int door2;
int sum1;
int sum2;

void init()
{
	door1 = 0;
	door2 = 0;
	sum1 = 0;
	sum2 = 0;
}

int gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x%y);
}

int main(void)
{
	// INPUT_TEST;
	int T;
	int cas = 1;

	cin>>T;
	while(T--){
		init();
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d", &a[i]);
			if(a[i] > 0){
				sum1 += a[i];
				door1++;
			}else{
				sum2 += abs(a[i]);
				door2++;
			}
		}
		numerator = sum1 + sum2;
		denominator = n  - door2;
		int temp = gcd(numerator, denominator);
		if(door2 == n){
			printf("Case %d: inf\n", cas);
		}else{
			printf("Case %d: %d/%d\n", cas, numerator/temp, denominator/temp);
		}
		cas++;
	}
	return 0;
}