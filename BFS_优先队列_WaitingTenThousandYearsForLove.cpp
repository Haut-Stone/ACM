/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-15 12:56:31
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-15 14:06:27
*/

//http://vj.sdutacm.org/contest/view.action?cid=62917#problem/B
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <queue>
#include <vector>
using namespace std;

const int N = 100;
int caseNumber;
int row,col;
int maxTime;
int magic;
char Imap[N][N];
bool visted[N][N][N];//在该点，该魔力值是是否出现过
int direction[4][2] = {{-1,0}, {0, 1}, {1, 0}, {0, -1}};

struct Node
{
	int x;
	int y;
	int steps;
	int magic;
	friend bool operator < (Node a, Node b)
	{
		return a.steps > b.steps;
	}
}start;

int bfs(int x, int y)
{
	priority_queue<Node>Q;
	Node solo, next;

	solo.x = x;
	solo.y = y;
	solo.steps = 0;
	solo.magic = magic;
	visted[solo.x][solo.y][solo.magic] = 1;

	Q.push(solo);

	while(!Q.empty()){
		solo = Q.top();
		Q.pop();
		//可能开始写的是结束条件判断，是一个套路吧。
		if(solo.steps > maxTime) return -1;
		if(Imap[solo.x][solo.y] == 'L') return solo.steps;

		//然后是开始四向搜索的过程
		for(int i=0;i<4;i++){
			next.x = solo.x + direction[i][0];
			next.y = solo.y + direction[i][1];

			//改变完状态之后再开始判断。
			//其中超出地图边界，撞墙肯定是一种情况
			if(next.x < 0 || next.x >= row || next.y < 0 || next.y >= col || Imap[next.x][next.y] == '#') continue;

			//飞
			if(solo.magic > 0 && !visted[next.x][next.y][solo.magic-1]){
				visted[next.x][next.y][solo.magic-1] = 1;
				next.magic = solo.magic - 1;
				next.steps = solo.steps + 1;
				Q.push(next);
			}
			
			//一般情况
			if(Imap[next.x][next.y] != '@' && !visted[next.x][next.y][solo.magic] && Imap[solo.x][solo.y] != '@'){
				visted[next.x][next.y][solo.magic] = 1;
				next.steps = solo.steps + 2;
				next.magic = solo.magic;
				Q.push(next);
			}
		}
	}
	return -1;
}

int main(void)
{
	caseNumber = 1;
	while(~scanf("%d%d%d%d", &row, &col, &maxTime, &magic)){
		int flag = 0;
		memset(Imap, '0', sizeof(Imap));
		for(int i=0;i<row;i++){
			scanf("%s", Imap[i]);
		}
		//用来寻找开始点的循环
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				if(Imap[i][j] == 'Y'){
					start.x = i;
					start.y = j;
					flag = 1;
					break;
				}
			}
			if(flag) break;
		}
		memset(visted, false, sizeof(visted));
		int num = bfs(start.x, start.y);//开始搜索
		printf("Case %d:\n", caseNumber++);
		if(num == -1){
			printf("Poor Yifenfei, he has to wait another ten thousand years.\n");
		}else{
			printf("Yes, Yifenfei will kill Lemon at %d sec.\n", num);
		}
	}
    return 0;
}