/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-12 14:22:49
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-12 14:23:29
*/

//这个也是一个看不懂的区间DP感觉自己没救了。。。
//http://blog.csdn.net/wiking__acm/article/details/8362562

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

const int N = 105;

int dp[N][N];
int ans[N];

int main(void)
{
	char text[N];
	char target[N];

	while(~scanf("%s%s",text, target)){
		int len = (int)strlen(text);

		for(int k=1;k<=len;k++){
			for(int i=0, j=i+k-1;j<len;i++, j++){
				if(k == 1){
					dp[i][j] = 1;
				}else{
					dp[i][j] = dp[i+1][j] + (target[i] == target[j] ? 0:1);
				}
				for(int k=i+1;k<j;k++){
					if(target[i] == target[k]){
						dp[i][j] = min(dp[i][j], dp[i+1][k] + dp[k+1][j]);
					}
				}
			}
		}
		for(int i=0;i<len;i++){
			ans[i] = dp[0][i];
			if(text[i] == target[i]){
				ans[i] = ans[i-1];
			}
			for(int k=0;k<i;k++){
				ans[i] = min(ans[i], ans[k] + dp[k+1][i]);
			}
		}
		printf("%d\n", ans[len-1]);
	}
	return 0;
}