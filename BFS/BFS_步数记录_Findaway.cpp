/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-09 16:13:48
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-09 17:09:05
*/

//HDU 2612
//做两次广搜的同时，记录到达肯德基的时间，随后求和，求和的最小值。

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

const int N = 250;
const int INF = 99999999;

struct Node
{
	int x;
	int y;
	Node(){}
	Node(int X, int Y){
		x = X;
		y = Y;
	}
};

int row, col;
char iMap[N][N];
int vis1[N][N];
int vis2[N][N];
int ans1[N][N];
int ans2[N][N];
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void bfs(int x, int y, int visit[N][N], int ans[N][N])
{
	queue<Node> Q;
	visit[x][y] = 1;
	ans[x][y] = 0;
	Node raw(x, y);
	Q.push(raw);

	while(!Q.empty()){
		Node solo = Q.front();
		Q.pop();

		for(int i=0;i<4;i++){
			int dx = solo.x + direction[i][0];
			int dy = solo.y + direction[i][1];
			Node newPos(dx, dy);
			if(dx >= 0 && dx < row && dy >= 0 && dy < col && !visit[dx][dy] && iMap[dx][dy] != '#'){
				ans[dx][dy] = ans[solo.x][solo.y] + 1;
				visit[dx][dy] = 1;
				Q.push(newPos);
			}
		}
	}
}

int main(void)
{
	int x1, x2, y1, y2;
	while(~scanf("%d%d", &row, &col)){
		for(int i=0;i<row;i++){
			scanf("%s", iMap[i]);
		}
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				if(iMap[i][j] == 'Y'){
					x1 = i;
					y1 = j;
				}else if(iMap[i][j] == 'M'){
					x2 = i;
					y2 = j;
				}
			}
		}

		memset(vis1, 0, sizeof(vis1));
		memset(ans1, 0, sizeof(ans1));
		bfs(x1, y1, vis1, ans1);
		memset(vis2, 0, sizeof(vis2));
		memset(ans2, 0, sizeof(ans2));
		bfs(x2, y2, vis2, ans2);

		int min = INF;
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				if(iMap[i][j] == '@' && vis1[i][j] && vis2[i][j]){
					if(min > ans1[i][j] + ans2[i][j]){
						min = ans1[i][j] + ans2[i][j];
					}
				}
			}
		}
		printf("%d\n", min*11);
	}
	return 0;
}