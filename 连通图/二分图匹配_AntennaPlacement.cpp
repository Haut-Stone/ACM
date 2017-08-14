/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-14 11:45:58
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-14 11:47:51
*/

//POJ 3020
//这题就是建图比较的麻烦，其他的话就和POJ3041基本上一样了。
//http://blog.csdn.net/lyy289065406/article/details/6647040

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
const int DIC[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int iMap[N][N];
bool city[N][N];
bool vis[N];
int link[N];
int numx, numy;
int row, col;
int ans;

bool dfs(int x)
{
	for(int y=1;y<=numy;y++){
		if(city[x][y] && !vis[y]){
			vis[y] = true;
			if(link[y] == 0 || dfs(link[y])){
				link[y] = x;
				return true;
			}
		}
	}
	return false;
}

void search()
{
	ans = 0;
	for(int x=1;x<=numx;x++){
		memset(vis, 0, sizeof(vis));
		if(dfs(x)){
			ans++;
		}
	}
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while(T--){

		memset(iMap, 0, sizeof(iMap));
		memset(link, 0, sizeof(link));
		memset(city, 0, sizeof(city));

		scanf("%d%d", &row, &col);
		char soloChar;
		int cityNumber = 0;
		for(int i=1;i<=row;i++){
			for(int j=1;j<=col;j++){
				cin>>soloChar;
				if(soloChar == '*'){
					iMap[i][j] = ++cityNumber;
				}
			}
		}

		for(int i=1;i<=row;i++){
			for(int j=1;j<=col;j++){
				if(iMap[i][j]){
					for(int k=0;k<4;k++){
						int dx = i + DIC[k][0];
						int dy = j + DIC[k][1];
						if(iMap[dx][dy]){
							city[iMap[i][j]][iMap[dx][dy]] = true;
						}
					}
				}
			}
		}

		numy = numx = cityNumber;
		search();
		printf("%d\n", cityNumber - ans/2);
	}
	return 0;
}