/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-08 16:59:46
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-08 17:01:40
*/

//这题的最短路部分是自己写的，dp部分实在是理解不了了。
//说实话很无奈。去你妈的，直接拍题解吧
//http://blog.csdn.net/libin56842/article/details/24533599


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

const int N = 20;
const int INF = 99999999;

int dp[1<<11][N];//表示情况i时目标为j的最短路
int iMap[N][N];
int dis[N][N];
int vertex;

void init()
{
	for(int i=1;i<=vertex;i++){
		for(int j=1;j<=vertex;j++){
			if(i == j){
				iMap[i][j] = 0;
			}else{
				iMap[i][j] = INF;
			}
		}
	}
}

int main(void)
{
	while(~scanf("%d", &vertex) && vertex){
		init();
		vertex++;
		for(int i=1;i<=vertex;i++){
			for(int j=1;j<=vertex;j++){
				scanf("%d", &iMap[i][j]);
			}
		}
		for(int i=1;i<=vertex;i++){
			for(int j=1;j<=vertex;j++){
				for(int k=1;k<=vertex;k++){
					if(iMap[i][j] > iMap[i][k] + iMap[k][j]){
						iMap[i][j] = iMap[i][k] + iMap[k][j];
					}
				}
			}
		}
		
		for(int i=1;i<=vertex;i++){
			for(int j=1;j<=vertex;j++){
				dis[i-1][j-1] = iMap[i][j];
			}
		}
		
		memset(dp, -1, sizeof(dp));
		vertex--;
		dp[1][0] = 0;
		for(int i=1;i<(1<<(vertex+1));i++){
			i = i|1;
			for(int j=0;j<=vertex;j++){
				if(dp[i][j] != -1){
					for(int k=0;k<=vertex;k++){
						if(j != k && (dp[(1<<k)|i][k] == -1 || dp[(1<<k)|i][k] > dp[i][j] + dis[j][k])){
							dp[(1<<k)|i][k] = dp[i][j] + dis[j][k];
						}
					}
				}
			}
		}
		printf("%d\n", dp[(1<<(vertex+1)) - 1][0]);
	}
	return 0;
}