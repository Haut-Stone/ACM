/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-03 21:53:33
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-27 10:51:11
*/

//POJ 3616
//时间为判断条件，且必然由小到大。以开始时间为条件对时间段进行排序，求最大递增子序列。

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
using namespace std;

const int N = 10050;

int dp[N];//以第i段为开始段获得的最大值
int maxTime;
int maxChance;
int restTime;

struct Node
{
	int b;
	int e;
	int value;
}timeSeg[N];

bool cmp(Node a, Node b)
{
	if(a.b == b.b){
		//时间早的在前
		return a.e < b.e;
	}else{
		return a.b < b.b;
	}
}

int main(void)
{
	while(~scanf("%d %d %d", &maxTime, &maxChance, &restTime)){
		for(int i=0;i<maxChance;i++){
			scanf("%d%d%d", &timeSeg[i].b, &timeSeg[i].e, &timeSeg[i].value);
			timeSeg[i].e += restTime;
		}
		sort(timeSeg, timeSeg+maxChance, cmp);
		// printf("dbg\n");
		for(int i=maxChance-1;i>=0;i--){
			dp[i] = timeSeg[i].value;
			for(int j=i+1;j<maxChance;j++){
				if(timeSeg[j].b >= timeSeg[i].e){
					dp[i] = max(dp[i], dp[j] + timeSeg[i].value);
				}
			}
		}
		int ans = 0;
		for(int i=0;i<maxChance;i++){
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}