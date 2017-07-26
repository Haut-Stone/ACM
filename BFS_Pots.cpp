/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-05 12:27:02
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-24 21:08:51
*/

//http://vj.sdutacm.org/contest/view.action?cid=62898#problem/F
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

const int N = 110;
int a, b, aimWater;
int vis[N][N];
int step[N*N];
int myLeft, myRight;
string op[7]={" ","FILL(1)","FILL(2)","DROP(1)","DROP(2)","POUR(2,1)","POUR(1,2)"};//所有可能的输出选项。

struct Node
{
	int a;
	int b;
	int operation;//操作方式
	int previous;
}info[N*N];

void print()
{
	int ans = 0;
	while(myLeft != 0){
		step[ans++] = info[myLeft].operation;
		myLeft = info[myLeft].previous;
	}
	printf("%d\n", ans);
	for(int i=ans-1;i>=0;i--){
		cout<<op[step[i]]<<endl;
	}
}

void solve(int a, int b, int operation)
{
	if(vis[a][b]) return;
	vis[a][b] = 1;
	info[myRight].a = a;
	info[myRight].b = b;
	info[myRight].operation = operation;
	info[myRight].previous = myLeft;
	myRight++;
}

void bfs()
{
	//初始状态下
	info[0].a = 0;
	info[0].b = 0;
	vis[0][0] = 1;
	myLeft = 0;
	myRight = 1;//用的数组模拟队列。。。。好吧。。
	while(myLeft != myRight)
	{
		if(info[myLeft].b == aimWater || info[myLeft].a == aimWater){
			print();
			return;
		}
		int tx, ty;
		
		tx = a;//倒满1
		ty = info[myLeft].b;
		solve(tx, ty, 1);

		tx = info[myLeft].a;
		ty = b;//倒满2
		solve(tx, ty, 2);

		tx = 0;//倒空1
		ty =info[myLeft].b;
		solve(tx, ty, 3);

		tx = info[myLeft].a;
		ty = 0;//倒空2
		solve(tx, ty, 4);

		tx = info[myLeft].a + min(a-info[myLeft].a, info[myLeft].b);
		ty = info[myLeft].b - min(a-info[myLeft].a, info[myLeft].b);
		solve(tx ,ty, 5);//b->a

		tx = info[myLeft].a - min(b-info[myLeft].b, info[myLeft].a);
		ty = info[myLeft].b + min(b-info[myLeft].b, info[myLeft].a);
		solve(tx, ty, 6);
		myLeft++;//a->b
	}
	if(myLeft >= myRight){
		printf("impossible\n");
	}
}

int main(void)
{
	while(~scanf("%d%d%d", &a, &b, &aimWater)){
		memset(vis, 0, sizeof(vis));
		memset(step, 0, sizeof(step));
		bfs();
	}
	return 0;
}