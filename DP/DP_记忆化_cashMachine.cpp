/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-26 14:26:44
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-26 15:46:07
*/

//POJ 1276 
//（这不是多重背包！！！）这东西是多重背包？只是记录了一下这个和有没有出现过而已吧

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

struct Node
{
	int n;
	int v;
}a[30];

int dp[100010];
int sum, n;

int main(void)
{	
	while(~scanf("%d%d", &sum, &n)){
		for(int i=1;i<=n;i++){
			scanf("%d%d", &a[i].n, &a[i].v);
		}
		if(!sum || !n){
			printf("0\n");
			continue;
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;//0本来就出现过

		int iMax = 0;

		//依次放入所有的物品
		for(int i=1;i<=n;i++){
			for(int j=iMax;j>=0;j--){
				if(dp[j]){
					for(int k=1;k<=a[i].n;k++){
						int temp = j + k*a[i].v;
						if(temp > sum) continue;
						dp[temp] = 1;
						iMax = max(iMax, temp);
					}
				}
			}
		}
		printf("%d\n", iMax);
	}
	return 0;
}