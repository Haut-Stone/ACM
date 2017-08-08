/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-08 10:18:10
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-08 10:28:33
*/

//
//

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

const int N = 110;
int num[N];
int iMap[N];
int row, col;
int status[N];
char rawMap[N][N];
int dp[N][N][N];

bool statusOk(int x)
{
	if(x&(x<<1)) return false;
	if(x&(x<<2)) return false;
	return true;
}

int counting(int x)
{
	int temp = x;
	int ans = 0;
	while(temp){
		if(temp&1) ans++;
		temp >>= 1;
	}
	return ans;
}

bool fitWithMap(int a, int b)
{
	if(iMap[a]&status[b]) return false;
	return true;
}

bool fitWithStatus(int a,int b)
{
	if(status[a]&status[b]) return false;
	return true;
}

void init()
{
	memset(dp, 0, sizeof(dp));
	memset(status, 0, sizeof(status));
	memset(num, 0, sizeof(num));
	memset(rawMap, 0, sizeof(rawMap));
	memset(iMap, 0, sizeof(iMap));
}

int main(void)
{
	while(~scanf("%d%d", &row, &col)){
		init();
		for(int i=0;i<row;i++){
			scanf("%s", rawMap[i]);
		}
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				if(rawMap[i][j] == 'H'){
					iMap[i] += (1<<(col - j - 1));
				}
			}
		}
		
		int all = 0;
		for(int i=0;i<(1<<col);i++){
			if(statusOk(i)){
				status[all] = i;
				num[all++] = counting(i);
			}
		}
		
		for(int i=0;i<all;i++){
			if(fitWithMap(0, i)){
				dp[0][i][0] = num[i];
			}
		}
		
		for(int i=0;i<all;i++){
			if(fitWithMap(1, i)){
				for(int j=0;j<all;j++){
					if(fitWithStatus(i, j)){
						dp[1][i][j] = max(dp[1][i][j], dp[0][j][0] + num[i]);
					}
				}
			}
		}
		
		for(int r=2;r<row;r++){
			for(int i=0;i<all;i++){
				if(fitWithMap(r, i)){
					for(int j=0;j<all;j++){
						if(fitWithMap(r-1, j)){
							if(fitWithStatus(i, j)){
								for(int k=0;k<all;k++){
									if(fitWithMap(r-2, k)){
										if(fitWithStatus(i, k)){
											if(fitWithStatus(j, k)){
												dp[r][i][j] = max(dp[r][i][j], dp[r-1][j][k] + num[i]);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		int ans = 0;
		for(int i=0;i<all;i++){
			for(int j=0;j<all;j++){
				ans = max(ans, dp[row-1][i][j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}