/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-06 22:11:26
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-08 22:32:06
*/

//https://acm.zzuli.edu.cn/zzuliacm/problem.php?id=1726
//这道题的坑还是蛮多的
//1.不能先踩到之后的目标点，因为目标点是自动触发的
//2.如果出发点就是后面的目标点的话，直接返回-1.

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

const int N = 110;

int row, col;
int numberOfK;

int beginX, beginY;
int tempX, tempY;

int ans;
int flag;

char Imap[N][N];
int vis[N][N];
int endPos[N][2];
int direction[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1},{1, 0}, {1, -1}, {0, -1}, {-1, -1}};//一共八个方向

struct Node
{
	int x;
	int y;
	int steps;
};


void init()
{
	memset(vis, 0, sizeof(vis));
	memset(endPos, 0, sizeof(endPos));
	flag = 1;
}


void read()
{
	cin>>row>>col>>numberOfK;
	for(int i=0;i<row;i++){
		scanf("%s", Imap[i]);
	}
	cin>>beginX>>beginY;
	for(int i=1;i<=numberOfK;i++){
		cin>>tempX>>tempY;//用来记录结束的地点
		endPos[i][0] = tempX - 1;
		endPos[i][1] = tempY - 1;
		Imap[tempX-1][tempY-1] = '@';//用@来表示为被踩过的机关
	}
}


int bfs(int x, int y)
{	
	queue<Node> Q;
	Node beginPos, solo, in;

	beginPos.x = x;//初始化起点
	beginPos.y = y;
	beginPos.steps = 0;
	vis[x][y] = 1;
	Imap[endPos[flag][0]][endPos[flag][1]] = '.';//恢复第一个终点

	for(int i=2;i<=numberOfK;i++){
		if(x == endPos[i][0] && y == endPos[i][1]) return -1;//当起点也为终点时，直接返回-1
	}

	Q.push(beginPos);
	while(!Q.empty()){
		solo = Q.front();
		Q.pop();

		if(solo.x == endPos[flag][0] && solo.y == endPos[flag][1]){//如果到达终点
			if(flag == numberOfK){//到达最后终点则返回
				return solo.steps;
			}else{
				flag++;//不是最后终点的话，寻找下一个终点
				// printf("%d %d %d\n", solo.x, solo.y, solo.steps);
				memset(vis, 0, sizeof(vis));//重新确定点的访问状态
				Imap[endPos[flag][0]][endPos[flag][1]] = '.';//将下一个要寻找终点恢复
				vis[solo.x][solo.y] = 1;
				while(!Q.empty()){
					Node temp;
					temp = Q.front();
					// printf("x=%d y=%d steps=%d被弹出\n", temp.x, temp.y, temp.steps);
					Q.pop();
				}
			}
		}

		for(int i=0;i<8;i++){
			int dx = solo.x + direction[i][0];
			int dy = solo.y + direction[i][1];
			// if(flag == 2 && i == 6){
			// 	for(int i=0;i<row;i++){
			// 		for(int j=0;j<col;j++){
			// 			printf("%d ", vis[i][j]);
			// 		}
			// 		printf("\n");
			// 	}
			// 	printf("此时的x=%d 此时的y=%d\n", dx, dy);
			// }
			if(dx >= 0 && dx < row && dy >= 0 && dy < col && Imap[dx][dy] != '#' && !vis[dx][dy] && Imap[dx][dy] != '@'){//如果新的点可以被访问
				if(i % 2 == 0){//一般情况下的四个方向	
					in.x = dx;
					in.y = dy;
					in.steps = solo.steps + 1;
					vis[dx][dy] = 1;
					// printf("i=%d x=%d y=%d steps=%d入栈\n", i, in.x, in.y, in.steps);
					Q.push(in);
				}else if(i % 2 == 1){
					if(Imap[dx - direction[i][0]][dy] == '#' && Imap[dx][dy - direction[i][1]] == '#'){
						//无法前进的情况
					}else{
						in.x = dx;
						in.y = dy;
						in.steps = solo.steps + 1;
						vis[dx][dy] = 1;
						// printf("i=%d x=%d y=%d steps=%d入栈\n",i, in.x, in.y, in.steps);
						Q.push(in);
					}
				}
			}
		}
	}	
	return -1;
}

int main(void)
{
	int T;
	cin>>T;
	while(T--){
		init();
		read();
		ans = bfs(beginX-1, beginY-1);
		printf("%d\n", ans);
	}
    return 0;
}