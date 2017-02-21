/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-02-21 18:40:38
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-02-21 19:41:20
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

//POJ1753 Flip Game
//枚举+dfs
const int N = 10;
const int INF = 9999999;

int maps[N][N];
int ans = INF;

//判断是否全同色
int judge()
{
	int x = maps[0][0];
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			if(maps[i][j] != x){
				return 0;
			}
		}
	}
	return 1;
}

//01变换
void exchange(int x, int y)
{

	maps[x][y]=!maps[x][y];
	if (x - 1 >= 0) maps[x-1][y]=!maps[x-1][y];  
    if (x + 1 < 4) maps[x+1][y]=!maps[x+1][y];  
    if (y - 1 >= 0) maps[x][y-1]=!maps[x][y-1];  
    if (y + 1 < 4) maps[x][y+1]=!maps[x][y+1];
}

//深搜
int dfs(int x, int y, int t)
{
	//最小步数
	if(judge()){
		if(ans > t){
			ans = t;
		}
		return 0;
	}
	//出界返回
	if(x >= 4 || y >= 4){
		return 0;
	}
	//一一枚举
	int nx, ny;
	//先列后行搜索
	nx = (x+1)%4;
	ny = y + (x+1)/4;

	dfs(nx, ny, t);
	exchange(x,y);
	dfs(nx, ny ,t+1);
	exchange(x, y);
	return 0;
}
int main(void)
{
	char temp;
	//读取
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			scanf("%c", &temp);
			if(temp == 'b'){
				maps[i][j] = 0;
			}else{
				maps[i][j] = 1;
			}
		}
		getchar();
	}
	//深搜过程
	dfs(0, 0, 0);
	if(ans == INF){
		printf("Impossible\n");
	}else{
		printf("%d\n", ans);
	}
    return 0;
}