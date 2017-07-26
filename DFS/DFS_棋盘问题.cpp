/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-29 17:10:06
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-24 11:47:09
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <ctime> 
using namespace std;

const int N = 10;
char myMap[N][N];
int cluUsed[100];
int ans;
int n;
int k;

//读错题意了，只有#的地方可以放棋子。

void dfs(int row, int k)//逐行搜索。。
{
	if(k==0){//符合条件的填满所有棋子
		ans++;
		return;
	}

	for(int i=row;i<n;i++){
		for(int j=0;j<n;j++){
			if(myMap[i][j] == '.' || cluUsed[j] == 1){
				continue;//剪枝
			}
			cluUsed[j] = 1;//标记该列是否已经被占用。
			dfs(i+1, k-1);
			cluUsed[j] = 0;
		}
	}
}

int main(void)
{
	while(scanf("%d%d", &n, &k), n!=-1 && k!=-1){
		getchar();
		ans = 0;
		memset(myMap, '\0', sizeof(myMap));
        memset(cluUsed, 0, sizeof(cluUsed));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%c", &myMap[i][j]);//载入地图，没有留边界空余部分
			}
			getchar();
		}
		dfs(0, k);//从0开始搜索
		printf("%d\n", ans);
	}
    return 0;
}