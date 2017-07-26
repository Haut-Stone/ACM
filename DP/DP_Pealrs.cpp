/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-26 18:02:27
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-26 18:04:21
*/

//POJ 1260
//http://blog.csdn.net/sdutyangkun/article/details/52225285
//这题不难但是还是想的很巧妙的

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

int sum[1100];
int num[1100];
int price[1100];
int dp[1100];
int n;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(num,0,sizeof(num));//珍珠数目
		memset(sum,0,sizeof(sum));//前i种珍珠的数量的和，用来求差
		memset(price,0,sizeof(price));//珍珠的价格
		memset(dp,0,sizeof(dp));//表示前i种珍珠的最优解，即支付的最低价格
		scanf("%d",&n);
		sum[0]=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d",&num[i],&price[i]);
			sum[i]=sum[i-1]+num[i];
		}
		dp[0]=0;//dp的初始化
		for(int i=1;i<=n;i++){//一共有n种珍珠
			dp[i]=(num[i]+10)*price[i]+dp[i-1];//当第i种珍珠出现 未求最优解的情况
			for(int j=0;j<i;j++){//枚举第i种前的所有珍珠 被i所替代的情况寻找最优解
				dp[i]=min(dp[i],(sum[i]-sum[j]+10)*price[i]+dp[j]);//(sum[i]-sum[j]+10)*price[i]+dp[j]表示j+1到第i种被i取代的价格
			}
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}