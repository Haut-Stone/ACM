/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-15 21:19:11
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-15 23:07:01
*/

//HDU 1160
//需要在求最长上升子序列的同时记录子序列元素的下标

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

#define INPUT_TEST freopen("in.txt", "r", stdin)

const int N = 3000;

int cnt;

struct Node
{
	int id;
	int size;
	int speed;
	int len;
	int pre;
}mouse[N];

bool cmp(const Node &a, const Node &b)
{
	if(a.size != b.size){
		return a.size < b.size;
	}
	return a.speed < b.speed;
}

void output(int index)
{	
	if(mouse[index].len == 1){
		printf("%d\n", mouse[index].id);
	}else{
		output(mouse[index].pre);
		printf("%d\n", mouse[index].id);
	}
}

int main(void)
{
	// INPUT_TEST;
	
	cnt = 0;
	while(~scanf("%d%d", &mouse[cnt].size, &mouse[cnt].speed)){
		mouse[cnt].id = cnt + 1;
		mouse[cnt].len = 1;
		cnt++;
	}
	sort(mouse, mouse + cnt, cmp);

	for(int i=0;i<cnt;i++){
		for(int j=0;j<i;j++){
			if(mouse[i].size > mouse[j].size && mouse[i].speed < mouse[j].speed){
				if(mouse[i].len < mouse[j].len + 1){
					mouse[i].len = mouse[j].len + 1;
					mouse[i].pre = j;
				}
			}
		}
	}

	int max = 0;
	for(int i=0;i<cnt;i++){
		if(mouse[max].len < mouse[i].len){
			max = i;
		}
	}
	printf("%d\n", mouse[max].len);
	output(max);
	return 0;
}