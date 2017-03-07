/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-02 13:40:21
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-07 16:52:31
*/

//http://vj.sdutacm.org/contest/view.action?cid=62898#problem/A
//一维的简单搜索
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
using namespace std;
	
const int N = 100000;

typedef struct Node
{	
	int x;
	int step;
}Node;


int Ibegin, Iend;

int bfs(int b, int e)
{
	queue <Node> rom;
	Node solo;
	int vis[N+10] = {0};//用来消除重复项。

	solo.x = b;
	solo.step = 0;

	rom.push(solo);
	while(!rom.empty()){
		solo = rom.front();
		rom.pop();
		if(solo.x == e){
			return solo.step;
		}

		solo.step++;
		solo.x++;//上一个
		if(solo.x >= 0 && solo.x <= N){
			if(!vis[solo.x]){
				vis[solo.x] = 1;
				rom.push(solo);
			}	
		}
		
		solo.x -= 2;//下一个
		if(solo.x >= 0 && solo.x <= N){
			if(!vis[solo.x]){
				vis[solo.x] = 1;
				rom.push(solo);
			}
		}
		
		solo.x++;
		solo.x = 2*solo.x;//二倍位置
		if(solo.x >= 0 && solo.x <= N){
			if(!vis[solo.x]){
				vis[solo.x] = 1;
				rom.push(solo);
			}
		}
	}
	return 0;
}

int main(void)
{
	while(~scanf("%d%d", &Ibegin, &Iend)){
		int ans = 0;
		ans = bfs(Ibegin, Iend);
		printf("%d\n", ans);
	}
    return 0;
}