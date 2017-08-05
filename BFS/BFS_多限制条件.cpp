/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-05 13:49:08
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-05 13:50:13
*/

//不看题解谁知道题意这么多要求啊
//http://172.18.66.54:50015/JudgeOnline/problem.php?id=1280

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
int rowAndCol;
char iMap[N][N];
int vis[N][N];
int alphaNumber;
int portalNumber;
int dic[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Node
{
	int x;
	int y;
	int steps;
	char wanted;
	bool find;
	Node(){
		x = 0;
		y = 0;
		steps = 0;
		wanted = 'A';
		find = false;
	}
	Node(int X, int Y, int STEPS, char WANTED, bool FIND){
		x = X;
		y = Y;
		steps = STEPS;
		wanted = WANTED;
		find = FIND;
	}
}portalList[N];

bool check(int x, int y)
{
	return (x >= 0 && y >= 0 && x < rowAndCol && y < rowAndCol && iMap[x][y] != '#' && vis[x][y] == 0);
}

Node bfs(Node beginNode)
{
	memset(vis, 0, sizeof(vis));
	queue<Node> Q;
	Q.push(beginNode);
	iMap[beginNode.x][beginNode.y] = '.';
	vis[beginNode.x][beginNode.y] = 1;
	while(!Q.empty()){
		Node solo = Q.front();
		Q.pop();
		for(int i=0;i<4;i++){
			int dx = solo.x + dic[i][0];
			int dy = solo.y + dic[i][1];
			if(check(dx, dy)){
				if(iMap[dx][dy] == solo.wanted){
					iMap[dx][dy] = '.';
					Node returnNode(dx, dy, solo.steps+1, solo.wanted+1, false);
					return returnNode;
				}else if(iMap[dx][dy] == '$' || iMap[dx][dy] == '.'){
					if(iMap[dx][dy] == '$'){
						for(int i=0;i<portalNumber;i++){
							if(portalList[i].x == dx && portalList[i].y == dy) continue;
							if(vis[portalList[i].x][portalList[i].y]) continue;
							Node next(portalList[i].x, portalList[i].y, solo.steps+1, solo.wanted, false);
							Q.push(next);
							vis[portalList[i].x][portalList[i].y] = 1;
						}
					}else{
						Node next(dx, dy, solo.steps+1, solo.wanted, false);
						Q.push(next);
						vis[dx][dy] = 1;
					}
				}
			}
		}
	}
	Node defalutNode(0, 0, 0, '#', 0);
	return defalutNode;
}

void init()
{
	memset(vis, 0, sizeof(vis));
	memset(portalList, 0, sizeof(portalList));
	memset(iMap, 0, sizeof(iMap));
	alphaNumber = 0;
	portalNumber = 0;
}

int main(void)
{
	while(~scanf("%d", &rowAndCol)){
		init();//初始化
		int beginX = 0;
		int beginY = 0;
		for(int i=0;i<rowAndCol;i++){
			scanf("%s", iMap[i]);
		}
		for(int i=0;i<rowAndCol;i++){
			for(int j=0;j<rowAndCol;j++){
				if(iMap[i][j] >= 'A' && iMap[i][j] <= 'Z'){
					alphaNumber++;
					if(iMap[i][j] == 'A'){
						beginX = i;
						beginY = j;
					}
				}else if(iMap[i][j] == '$'){
					portalList[portalNumber].x = i;
					portalList[portalNumber++].y = j;
				}
			}
		}
		Node resultNode(beginX, beginY, 0, 'B', false);
		while(resultNode.wanted != 'A' + alphaNumber){
			if(resultNode.wanted == '#') break;
			resultNode.find = false;
			resultNode = bfs(resultNode);
		}
		if(resultNode.wanted == '#'){
			printf("Impossible\n");
		}else{
			printf("%d\n", resultNode.steps);
		}
	}
	return 0;
}