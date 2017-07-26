/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-18 22:55:57
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-19 20:45:40
*/

//http://acm.hdu.edu.cn/showproblem.php?pid=1874
//最短路的模版题

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

#define INPUT_TEST freopen("in.txt", "r", stdin)

const int N = 100;
const int INF = 99999999;

int iMap[N][N];
int n, m;
int beginX, endX;
int u, v, w;
int ans;

void init()
{
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i == j){
				iMap[i][j] = 0;
			}else{
				iMap[i][j] = INF;
			}
		}
	}
}

int floyd(int start, int target)
{	
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(iMap[i][j] > iMap[i][k] + iMap[k][j]){
					iMap[i][j] = iMap[i][k] + iMap[k][j];
				}
			}
		}
	}
	if(iMap[start][target] == INF){
		return -1;
	}else{
		return iMap[start][target];
	}
}

int main(void){

	INPUT_TEST;
	while(~scanf("%d %d", &n, &m)){
		init();
		while(m--){
			scanf("%d%d%d", &u, &v, &w);
			if(w < iMap[u][v]){
				iMap[u][v] = iMap[v][u] = w;//无向边
			}
		}
		scanf("%d%d", &beginX, &endX);
		ans = floyd(beginX, endX);
		printf("%d\n", ans);
	}
    return 0;
}