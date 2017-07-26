/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2016 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2016-12-26 12:52:30
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-02-08 23:15:12
*/
//这原来是一个背包啊。。。！！！
//厉害了，这道题里面有模版....
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

struct Node
{
	int left;
	int right;
	int value;
};


bool cmp(Node x, Node y)
{
	if(x.right != y.right){
		return x.right < y.right;
	}else{
		return x.left < y.left;
	}
}

int main(void)
{
	int T;
	int n;
	int ans;
	int temp;
	Node solo[100];
	scanf("%d", &T);
	while(T--){
		int dp[100];
		memset(dp, 0, sizeof(dp));
		temp = 0;
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%d %d %d", &solo[i].left, &solo[i].right, &solo[i].value);
		}
		sort(solo, solo+n, cmp);
		for(int i=0;i<n;i++){
			ans = 0;
			dp[i] = solo[i].value;
			for(int j=0;j<i;j++){
				if(solo[i].left > solo[j].right){
					temp = max(temp, dp[j]);
				}
			}
			dp[i] += temp;
			ans = max(ans, dp[i]);
		}
		printf("%d\n", ans);
	}
    return 0;
}