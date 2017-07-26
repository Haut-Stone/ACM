/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-24 17:51:06
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-24 17:52:11
*/

//这题是沿墙走和最短路。沿墙走的部分比较困难。
//233333我居然把这道题写出来了。。


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

const int N = 110;
char iMap[N][N];
int vis[N][N];
int row, col;
int ansOfL, ansOfR, ansOfM;
int beginX, beginY;
int dic[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int flag;
int lBook[4] = {3, 0, 1, 2};
int rBook[4] = {1, 2, 3, 0};
int backBook[4] = {2, 3, 0, 1};

struct Node
{
	int x;
	int y;
	int steps;
};

int bfs(int x, int y)
{
	queue<Node> Q;
	Node solo;

	solo.x = x;
	solo.y = y;
	solo.steps = 1;
	vis[x][y] = 1;

	Q.push(solo);
	while(!Q.empty()){
		solo = Q.front();
		Q.pop();

		if(iMap[solo.x][solo.y] == 'E'){
			return solo.steps;
		}

		for(int i=0;i<4;i++){
			int dx = solo.x + dic[i][0];
			int dy = solo.y + dic[i][1];
			if(dx>=0 && dx<row && dy>=0 && dy<col && iMap[dx][dy] != '#'){
				if(vis[dx][dy] == 1){
					continue;
				}else{
					Node temp;
					vis[dx][dy] = 1;
					temp.x = dx;
					temp.y = dy;
					temp.steps = solo.steps + 1;
					Q.push(temp);
				}
			}
		}
	}
	return 0;
}

void dfsL(int x, int y, int steps, int dicNow)
{	
	if(iMap[x][y] == 'E'){
		ansOfL = steps;
		return;
	}

	int leftHand = lBook[dicNow];
	int rightHand = rBook[dicNow];
	int backHand = backBook[dicNow];
	int dx = x + dic[leftHand][0];
	int dy = y + dic[leftHand][1];
	if(iMap[dx][dy] != '#'){//如果左手边不是墙的话
		dfsL(dx, dy, steps + 1, leftHand);
	}else{
		int dx = x + dic[dicNow][0];
		int dy = y + dic[dicNow][1];
		if(iMap[dx][dy] != '#'){
			dfsL(dx, dy, steps + 1, dicNow);
		}else{
			int dx = x + dic[rightHand][0];
			int dy = y + dic[rightHand][1];
			if(iMap[dx][dy] != '#'){
				dfsL(dx, dy, steps + 1, rightHand);
			}else{
				int dx = x + dic[backHand][0];
				int dy = y + dic[backHand][1];
				if(iMap[dx][dy] != '#'){
					dfsL(dx, dy, steps + 1, backHand);
				}
			}
		}
	}
	return;
}

void dfsR(int x, int y, int steps, int dicNow)
{
	if(iMap[x][y] == 'E'){
		ansOfR = steps;
		return;
	}

	int leftHand = lBook[dicNow];
	int rightHand = rBook[dicNow];
	int backHand = backBook[dicNow];

	int dx = x + dic[rightHand][0];
	int dy = y + dic[rightHand][1];
	if(iMap[dx][dy] != '#'){//如果右手边不是墙的话
		dfsR(dx, dy, steps + 1, rightHand);
	}else{
		int dx = x + dic[dicNow][0];
		int dy = y + dic[dicNow][1];
		if(iMap[dx][dy] != '#'){
			dfsR(dx, dy, steps + 1, dicNow);
		}else{
			int dx = x + dic[leftHand][0];
			int dy = y + dic[leftHand][1];
			if(iMap[dx][dy] != '#'){
				dfsR(dx, dy, steps + 1, leftHand);
			}else{
				int dx = x + dic[backHand][0];
				int dy = y + dic[backHand][1];
				if(iMap[dx][dy] != '#'){
					dfsR(dx, dy, steps + 1, backHand);
				}
			}
		}
	}
	return;
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &col, &row);
		for(int i=0;i<row;i++){
			scanf("%s", iMap[i]);
		}
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				if(iMap[i][j] == 'S'){
					beginX = i;
					beginY = j;
				}
			}
		}
		ansOfR = ansOfL = 0;

		memset(vis, 0, sizeof(vis));
		ansOfM = bfs(beginX, beginY);
		int dicNow = 0;
		for(int i=0;i<4;i++){
			int dx = beginX + dic[i][0];
			int dy = beginY + dic[i][1];
			if(dx >= 0 && dx < row && dy >= 0 && dy < col && iMap[dx][dy] == '.'){
				dicNow = i;
				break;
			}
		}
		dfsL(beginX, beginY, 1, dicNow);
		dfsR(beginX, beginY, 1, dicNow);
		printf("%d %d %d\n", ansOfL, ansOfR, ansOfM);
	}
	return 0;
}