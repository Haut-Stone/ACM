/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-08 12:32:12
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-08 13:52:47
*/

//POJ 3279 
//coursera 上面北大算法课程的经典题。算是熄灯问题的翻版吧。

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
const int INF = 999999999;

int row, col;
int iMap[N][N];
int raw[N][N];
int filp[N][N];
int ans[N][N];
int ansNum;
int direcion[5][2] = {{0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int solve()
{
	int num = 0;
	for(int i=0;i<col;i++){
		if(filp[0][i]){
			for(int k=0;k<5;k++){
				int dx = 0 + direcion[k][0];
				int dy = i + direcion[k][1];
				if(dy >= 0 && dy < col && dx >= 0 && dx < row){
					if(iMap[dx][dy] == 1){
						iMap[dx][dy] = 0;
					}else{
						iMap[dx][dy] = 1;
					}
				}
			}
		}
	}

	for(int i=0;i<row-1;i++){
		for(int j=0;j<col;j++){

			if(iMap[i][j] == 1){
				filp[i+1][j] = 1;//反转

				for(int k=0;k<5;k++){
					int dx = i+1 + direcion[k][0];
					int dy = j + direcion[k][1];
					if(dy >= 0 && dy < col && dx >= 0 && dx < row){
						if(iMap[dx][dy] == 1){
							iMap[dx][dy] = 0;
						}else{
							iMap[dx][dy] = 1;
						}
					}
				}
			}
		}
	}

	int isAllBlack = true;
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(iMap[i][j] == 1){
				isAllBlack = false;
				break;
			}
		}
	}

	if(isAllBlack){
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				if(filp[i][j]) num++;
			}
		}
		return num;
	}else{
		return -1;
	}

	
}

void init()
{
	memset(filp, 0, sizeof(filp));
	memset(iMap, 0, sizeof(iMap));
	memset(raw, 0, sizeof(raw));
	memset(ans, 0 ,sizeof(ans));
	ansNum = INF;
}

int main(void)
{
	while(~scanf("%d%d", &row, &col)){
		init();
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				scanf("%d", &raw[i][j]);
			}
		}

		//先枚举一遍第一排的状态，再解决。
		for(int i=0;i< 1<<col;i++){
			memset(filp, 0, sizeof(filp));
			for(int j=0;j<col;j++){
				filp[0][col-j-1] = i>>j&1;
			}
			memcpy(iMap, raw, sizeof(raw));

			int flipNum = solve();
			if(flipNum >= 0 && ansNum > flipNum){
				ansNum = flipNum;
				memcpy(ans, filp, sizeof(filp));
			}
		}

		if(ansNum == INF){
			printf("IMPOSSIBLE\n");
		}else{
			for(int i=0;i<row;i++){
				printf("%d", ans[i][0]);
				for(int j=1;j<col;j++){
					printf(" %d", ans[i][j]);
				}
				printf("\n");
			}
		}


	}
    return 0;
}