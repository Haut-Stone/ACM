/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-10 16:33:59
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-10 16:34:37
*/

//给定一个十进制正整数N，写下从1开始，到N的所有正数，计算出其中出现所有1的个数。
//例如：n = 12，包含了5个1。1,10,12共包含3个1，11包含2个1，总共5个1
//https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1009

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

const int N = 10;

int s;
int dp[N];

void init()
{
	memset(dp, 0, sizeof(dp));
	for(int i=1;i<=9;i++){
		dp[i] = dp[i - 1] * 10 + pow(10, i - 1);
	}
}

int counting(int x)
{
	int ans = 0;
	int len = 0;
	int digit = 0;
	int radix = 1;
	int tail = 0;
	while(x){
		digit = x % 10;
		x /= 10;
		len++;
		if(digit > 1){
			ans += radix + digit * dp[len-1];
		}else if(digit == 1){
			ans += tail + 1 + dp[len-1];
		}
		tail = tail + digit * radix;
		radix *= 10;
	}
	return ans;
}

int main(void)
{
	init();
	cin>>s;
	cout<<counting(s)<<endl;
	return 0;
}