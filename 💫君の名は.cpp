/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-06-03 12:15:58
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-08-07 21:46:29
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

const int N = 6;
const int M = 6;
const int MAX = 110;
const int MOD = 1e9;

int row, col;
int dp[N][M];
int iMap[N];
char rawMap[N][N];
int status[MAX];


bool statusOK(int n)
{
	if(n&(n<<1)) return false;
	if(n&(n<<2)) return false;
	return true;
}

bool fitWithMap(int a, int b)
{
	if(iMap[a]&status[b]) return false;
	return true;
}

int main(void)
{
	while(~scanf("%d%d", &row, &col)){
		for(int i=0;i<row;i++){
			scanf("%s", rawMap[i]);
		}
		for(int i=1;i<=row;i++){
			for(int j=1;j<=col;j++){
				if(rawMap[i-1][j-1] == 'H'){
					iMap[i] += (1<<(j-1));
				}
			}
		}
		int all = 0;
		for(int i=0;i<(1<<col);i++){
			if(statusOK(i)){
				status[all++] = i;
			}
		}
		
		for(int i=0;i<all;i++){
			if(fitWithMap(1, i)){
				int sum = 0;
				int temp = status[i];
				while(temp){
					sum += (temp&1);
					temp = (temp>>1);
				}
				dp[1][i] = sum;
			}
		}
		
		for(int i=2;i<=row;i++){
			for(int j=0;j<all;j++){
				if(fitWithMap(i, j)){
					for(int k=0;k<all;k++){
						if(fitWithMap(i-1, k)){
							if(!(status[j]&status[k])){
								dp[i][j] += dp[i-1][k];
							}
						}
					}
				}
			}
		}
		
		int ans = 0;
		for(int i=0;i<all;i++){
			ans += dp[row][i];
			ans %= MOD;
		}
		printf("%d\n", ans);
	}
	return 0;
}