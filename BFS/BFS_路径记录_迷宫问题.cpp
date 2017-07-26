/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-09 08:58:26
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-09 09:19:37
*/

//经典的迷宫问题。
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

const int N = 5;

int iMap[N][N];
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Node
{
	int x;
	int y;
	int id;
	int pre;
	Node(){};
	Node(int X, int Y, int PRE){
		x = X;
		y = Y;
		pre = PRE;
	}
}Q[1000];

void iOut(int x)
{
	if(Q[x].pre == -1){
		return;
	}
	iOut(Q[x].pre);
	printf("(%d, %d)\n", Q[x].x, Q[x].y);
	return;
}

void bfs(int x, int y)
{
	Node solo(x, y, -1);
	Q[0] = solo;
	int front = 0;
	int rear = 1;
	while(front < rear){
		for(int i=0;i<4;i++){
			int dx = Q[front].x + direction[i][0];
			int dy = Q[front].y + direction[i][1];
			if(dx >= 0 && dx < 5 && dy >= 0 && dy < 5 && iMap[dx][dy] == 0){
				iMap[dx][dy] = 1;
				Node newPos(dx, dy, front);
				Q[rear] = newPos;
				rear++;
			}

			if(dx == 4 && dy == 4){
				iOut(front);
				return;
			}
		}
		front++;
	}
}

int main(void)
{
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin>>iMap[i][j];
		}
	}
	printf("(0, 0)\n");
	bfs(0, 0);
	printf("(4, 4)\n");
	return 0;
}