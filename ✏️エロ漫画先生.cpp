/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-04 20:46:48
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-09-24 13:04:30
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

int n,m,k,ans,power;
int r[105],c[105],dp[1005][505];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;++i){
		scanf("%d%d",&r[i],&c[i]);
	}
	for(int i=1;i<=k;++i){
		for(int p=n;p>=r[i];--p){
			for(int q=m;q>=c[i];--q){
				dp[p][q]=max(dp[p][q],dp[p-r[i]][q-c[i]]+1);
			}
		}
	}
	ans=0;
	power=m;
	for(int i=1;i<=m;++i){
		if (dp[n][i]>ans){
			ans=dp[n][i]; power=m-i;
		}
	}
	printf("%d %d",ans,power);
}
