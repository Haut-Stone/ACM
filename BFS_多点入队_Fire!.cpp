/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-08 21:50:48
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-09 08:49:21
*/

//UVA 11624
//这么简单的一道题，网上的题解居然都是要2次bfs，真是服了。

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

const int N = 1010;

struct Node
{
	int x;
	int y;
	int isHuman;
	int steps;
	Node(){}
	Node(int X, int Y, int ISHUMAN, int STEPS){
		x = X;
		y = Y;
		isHuman = ISHUMAN;
		steps = STEPS;
	}
};

int row, col;
int beginX, beingY;
int fireX, fireY;
char iMap[N][N];
int vis[N][N];
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int bfs(int x1, int y1)
{
	queue<Node> Q;

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(iMap[i][j] == 'F'){
				Node fire(i, j, 0, 0);
				vis[fire.x][fire.y] = 1;
				Q.push(fire);
			}
		}
	}
	Node human(x1, y1, 1, 0);
	vis[human.x][human.y] = 1;
	Q.push(human);

	while(!Q.empty()){
		Node solo;
		solo = Q.front();
		Q.pop();

		if((solo.x == 0 || solo.x == row-1 || solo.y == 0 || solo.y == col-1) && solo.isHuman == 1){//如果人走到了边界的话
			return solo.steps + 1;
		}

		for(int i=0;i<4;i++){
			int dx = solo.x + direction[i][0];
			int dy = solo.y + direction[i][1];
			Node newPos(dx, dy, solo.isHuman, solo.steps + 1);
			if(dx >= 0 && dx < row && dy >= 0 && dy < col && iMap[dx][dy] == '.' && !vis[dx][dy]){
				vis[dx][dy] = 1;
				Q.push(newPos);
			}
		}
	}
	return -1;
}

int main(void)
{
	int T;
	cin>>T;
	for(int cas=1;cas<=T;cas++){
		memset(vis, 0, sizeof(vis));
		cin>>row>>col;
		for(int i=0;i<row;i++){
			scanf("%s", iMap[i]);
		}

		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				if(iMap[i][j] == 'J'){
					beginX = i;
					beingY = j;
				}
			}
		}
		int ans = bfs(beginX, beingY);
		if(ans == -1){
			printf("IMPOSSIBLE\n");
		}else{
			printf("%d\n", ans);
		}
	}
    return 0;
}