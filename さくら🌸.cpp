/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-01-22 11:12:17
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-05-20 12:40:49
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

const int N = 1010;

int dp[N][N];
char str[N][N];
int n;

int main(void)
{
	while(scanf("%d", &n), n != 0){
		for(int i=0;i<n;i++){
			scanf("%s", str[i]);
		}
		int ans = 1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i == 0 || j == n-1){
					dp[i][j] = 1;
					continue;
				}
				int t1 = i;
				int t2 = j;
				while(t1 >= 0 && t2 < n && str[t1][j] == str[i][t2]){
					t1--;
					t2++;
				}
				int t = i - t1;
				if(t > dp[i-1][j+1] + 1){
					dp[i][j] = dp[i-1][j+1] + 1;
				}else{
					dp[i][j] = t;
				}
				ans = max(ans, dp[i][j]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


