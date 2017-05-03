/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-30 21:19:44
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-30 21:35:26
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
using namespace std;

#define INPUT_TEST freopen("in.txt", "r", stdin)

const int N = 100;

int iMap[N][N];
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0,-1}};

set<int> digit;

void dfs(int x, int y, int step, int num)
{
	if(step == 5){
		digit.insert(num);
		return;
	}
	for(int i=0;i<4;i++){
		int dx = x + direction[i][0];
		int dy = y + direction[i][1];
		if(dx >= 0 && dx < 5 && dy >= 0 && dy < 5){
			dfs(dx, dy, step+1, num*10 + iMap[dx][dy]);
		}
	}
}	

void read()
{
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			scanf("%d", &iMap[i][j]);
		}
	}

}

int main(void)
{
	// INPUT_TEST;

	read();

	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			dfs(i, j, 0, iMap[i][j]);
		}
	}

	printf("%lu\n", digit.size());
    return 0;
}