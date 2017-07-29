/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-28 18:55:53
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-28 18:56:56
*/

//http://codeforces.com/contest/758/problem/D
//CF的一道题，注意前缀0的处理

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

const int N = 1100;

long long base;
long long baseWithBase;
char rawNum[N];
long long ans;
long long maxNum = 0;
long long maxPos = 0;
long long tempNum;

int cntWei(long long n)
{
	int ans = 0;
	int temp = n;
	while(temp){
		temp /= 10;
		ans++;
	}
	return ans;
}

void init()
{
	baseWithBase = 0;
	ans = 0;
	maxNum = 0;
	maxPos = 0;
	tempNum = 0;
}

int main(void)
{
	while(~scanf("%lld%s", &base, rawNum)){
		init();
		int cnt = (int)cntWei(base);
		int len = (int)strlen(rawNum);
		baseWithBase = 1;
		for(int i=len-1;i>=0;i-=maxPos){
			
			maxNum = 0;
			maxPos = 0;
			tempNum = 0;
			for(int k=cnt;k>=1;k--){
				tempNum = 0;
				if(i-k+1 < 0) continue;
				for(int j=i-k+1;j<=i;j++){
					tempNum += rawNum[j] - '0';
					tempNum *= 10;
				}
				tempNum /= 10;
				if(tempNum >= base){
					if(k == 1){
						ans += tempNum * (baseWithBase);
						maxPos = 1;
						break;
					}else{
						continue;
					}
				}
				if(tempNum >= maxNum){
					maxNum = tempNum;
					maxPos = k;
				}
			}
			ans += maxNum * (baseWithBase);
			baseWithBase *= base;
		}
		printf("%lld\n", ans);
	}
}