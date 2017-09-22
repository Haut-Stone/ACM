/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-09-21 19:25:39
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-09-21 19:26:05
*/

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


const int N = 50010;

int a[N];
int dp[N];
int sum;
int v;

void zeroOnePack(int c, int w)
{
	for(int j=v;j>=c;j--){
		dp[j] = max(dp[j], dp[j-c] + w);
	}
}

void complatePack(int c, int w)
{
	for(int j=c;j<=v;j++){
		dp[j] = max(dp[j], dp[j-c]+w);
	}
}

void multipiePack(int c, int w, int n)
{
	if(c*n >= v){
		complatePack(c, w);
	}else{
		int k=1;
		while(k < n){
			zeroOnePack(c*k, w*k);
			n -= k;
			k *= 2;
		}
		zeroOnePack(c*n, w*n);
	}
}

int main(void)
{
	int count = 0;
	while(~scanf("%d%d%d%d%d%d%d%d%d%d", &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &a[9], &a[10])){
		count++;
		sum = 0;
		int allZero = true;
		for(int i=1;i<=10;i++){
			sum += a[i]*i;
			if(a[i] != 0){
				allZero = false;
			}
		}
		if(allZero) break;
		printf("#%d:", count);
		if(sum % 2 != 0){
			printf("Can't be divided.\n\n");
		}else{
			v = sum / 2;
			memset(dp, 0, sizeof(dp));
			for(int i=1;i<=10;i++){
				multipiePack(i, i, a[i]);
			}
			if(dp[v] == v){
				printf("Can be divided.\n\n");
			}else{
				printf("Can't be divided.\n\n");
			}
		}
	}
	return 0;
}