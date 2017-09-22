/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-09-22 19:30:11
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-09-22 19:44:27
*/

//多校脸萌,其实是一个简单的深搜
//http://blog.csdn.net/liu940204/article/details/51934369

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

const int N = 1100;

struct Node
{
	int x, y, r;
	double w;
	int mark;
}s[N];

int startPos, endPos;
int flag, n;

void dfs(int k, double sum)
{
	if(flag == 1) return;
	if(k == endPos){
		printf("%d\n", (int)sum);
		flag = 1;
		return;
	}
	for(int i=0;i<n;i++){
		if((s[i].x == s[k].x && s[i].y == s[k].y) || s[i].mark == 1){
			continue;
		}
		double r2 = pow((s[i].x-s[k].x), 2) + pow((s[i].y - s[k].y), 2);
		if(r2 == pow((s[i].r+s[k].r), 2) && s[i].mark == 0){
			s[i].mark = 1;
			s[i].w = s[k].w * s[k].r / s[i].r;
			sum += s[i].w;
			dfs(i, sum);
			s[i].mark = 0;
			sum -= s[i].w;
		}
	}
}

int main(void)
{
	int T, x0, y0;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &n, &x0, &y0);
		for(int i=0;i<n;i++){
			scanf("%d%d%d", &s[i].x, &s[i].y, &s[i].r);
			s[i].mark = 0;
			if(s[i].x == 0 && s[i].y == 0){
				startPos = i;
				s[startPos].w = 10000;
			}
			if(s[i].x == x0 && s[i].y == y0){
				endPos = i;
			}
		}
		s[startPos].mark = 1;
		flag = 0;
		dfs(startPos, s[startPos].w);
	}
	return 0;
}
