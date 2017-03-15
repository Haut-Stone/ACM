/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-09 17:31:07
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-15 13:14:20
*/

//http://vj.sdutacm.org/contest/view.action?cid=62917#problem/A
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
using namespace std;


const int N = 50;
char Imap[N][N];
bool vis[N][N];
int row ,col;
int ans;
int beginX, beginY;
int endX, endY;
int direction[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Node
{
	int x;
	int y;
	int steps;
	//优先队列处理结构体优先级关系时的模版。。注意无法重载大于号。
	//优先队列里自带的排序，和sort里的自带排序效果是相反的。
	//用来定义优先级,按步数的多少来确定优先级。
	//优先队列的本质时heap.
	friend bool operator < (Node a, Node b)//括号内用(const Node &a, const Node &b)在处理大数据是时可以提高效率。
    {  
        return a.steps > b.steps;  
    }
};

int check(int x, int y)
{
	if(x>=0 && x<row && y>=0 && y<col && vis[x][y] == 0 && Imap[x][y] != '*'){//检查格子是否可以走
		return 1;
	}
	return 0;
}

int bfs(int x, int y)
{	
	priority_queue <Node> Q;//新建优先队列
	Node start;
	start.x = x;
	start.y = y;
	start.steps = 0;
	Q.push(start);
	vis[start.x][start.y] = 1;
	while(!Q.empty()){
		Node solo;
		solo = Q.top();
		Q.pop();
		for(int i=0;i<4;i++){
			Node temp;
			temp.x = solo.x + direction[i][0];
			temp.y = solo.y + direction[i][1];
			temp.steps = solo.steps+1;//这是标准模版，如果有楼梯的话，将下面的注释还原。

			// if(check(temp.x, temp.y) && (Imap[temp.x][temp.y] == '-' || Imap[temp.x][temp.y] == '|')){
			// 	char now;
			// 	if(temp.steps % 2 == 1){//记录楼梯变换后的状态
			// 		if(Imap[temp.x][temp.y] == '-'){
			// 			now = '|'; 
			// 		}else{
			// 			now = '-';
			// 		}
			// 	}else{
			// 		now = Imap[temp.x][temp.y];
			// 	}
			// 	temp.x += direction[i][0];//temp成为下一个点
			// 	temp.y += direction[i][1];
			// 	if((now == '-' && (direction[i][1] == 1 || direction[i][1] == -1)) || (now == '|' && (direction[i][0] == 1 || direction[i][0] == -1))){//检查楼梯和来的方向
			// 		temp.steps++;
			// 	}
			// }

			if(check(temp.x, temp.y)){
				if(Imap[temp.x][temp.y] == 'T') return temp.steps;
				vis[temp.x][temp.y] = 1;
				Q.push(temp);
			}
		}

	}
	return 0;
}

int main(void)
{
	while(~scanf("%d%d", &row, &col)){//数据的读入
		for(int i=0;i<row;i++){
			scanf("%s", Imap[i]);
		}
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				if(Imap[i][j] == 'S'){
					beginX = i;
					beginY = j;
				}else if(Imap[i][j] == 'T'){
					endX = i;
					endY = j;
				}
			}
		}
		memset(vis, 0, sizeof(vis));//路径标记重置
		ans = bfs(beginX, beginY);
		cout<<ans<<endl;
	}
    return 0;
}