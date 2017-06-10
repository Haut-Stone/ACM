/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-09 19:24:09
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-06-09 21:24:54
*/

//POJ 1077 想当初自己刚入门的时候，在广东工业大学的OJ上遇到过这样的题目，当时就直接懵逼了，现在应该有能力做了吧。
//这道题可以算得上是非常经典的一道题了。
//奇怪的是这题POJ可以过，KBin过不了，估计有是KBin的判题系统出问题了。

//在开始写这道题之前，我要先发个牢骚（其实是凑个行数）学了这么长时的C语言了，但是我发现，其实除了写题，别的什么的我会的还是蛮少的，看看大作业都感觉的比较厉害。
//我感觉还是读项目的源码太少了，不，实际上是根本就没有读过好吗。。而且自己实际上连题目也不会写几道。感觉自己真的是好菜啊。
//这次写大作业的机会一定要把握好，切记，大作业不是让你炫技的，游戏你也写过，你明白，其实那也是在借鉴别人的代码而已。这些华而不实的东西，等到以后再学也不急。
//至少现在来看的话，走ACM这条路是正确的，因为别的道路，现在来看还是不明朗的。

//这次看来是一个全新的搜索课题了。包括IDA* A* 什么的就都会出现了。

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

const int N = 1000100;

struct Node
{
	int iMap[9];
	int xPos;
	int status;
	string path;
};

int fac[] = {1,1,2,6,24,120,720,5040,40320,362880};//康托展开相关。
int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};//udlr

bool vis[N];
string path;
char indexs[5] = "udlr";
Node raw;
int aim = 46234;

int cantor(int s[])
{
	int sum = 0;
	for(int i=0;i<9;i++){
		int num = 0;
		for(int j=i+1;j<9;j++){
			if(s[j] < s[i]) num++;
		}
		sum += (num * fac[9-i-1]);
	}
	return sum+1;
}

bool bfs()
{
	memset(vis, false, sizeof(vis));
	Node cur, next;
	queue<Node> Q;
	Q.push(raw);
	while(!Q.empty()){
		cur = Q.front();
		Q.pop();

		if(cur.status == aim){
			path = cur.path;
			return true;
		}

		int x = cur.xPos / 3;
		int y = cur.xPos % 3;

		for(int i=0;i<4;i++){
			int dx = x + direction[i][0];
			int dy = y + direction[i][1];
			if(dx < 0 || dx > 2 || dy < 0 || dy > 2) continue;
			next = cur;
			next.xPos = dx*3 + dy;
			next.iMap[cur.xPos] = next.iMap[next.xPos];
			next.iMap[next.xPos] = 0;
			next.status = cantor(next.iMap);
			if(!vis[next.status]){
				vis[next.status] = true;
				next.path = next.path + indexs[i];
				if(next.status == aim){
					path = next.path;
					return true;
				}
				Q.push(next);
			}
		}
	}
	return false;
}


int main(void)
{
	char inChar;
	while(cin>>inChar){

		//读取数据的部分
		if(inChar == 'x'){
			raw.iMap[0] = 0;
			raw.xPos = 0;
		}else{
			raw.iMap[0] = inChar - '0';
		}
		for(int i=1;i<9;i++){
			cin>>inChar;
			if(inChar == 'x'){
				raw.iMap[i] = 0;
				raw.xPos = i;
			}else{
				raw.iMap[i] = inChar - '0';
			}
		}

		//处理数据的部分
		raw.status = cantor(raw.iMap);
		if(bfs()){
			cout<<path<<endl;
		}else{
			cout<<"unsolvable"<<endl;
		}
	}
	return 0;
}