/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-12 18:12:57
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-12 20:03:49
*/

//思考一下可以知道，只有两个点是相邻的时候才会有最大的斜率
//https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1100

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

const int N = 10100;

struct Node{
	int x;
	int y;
	int id;
}node[N];

int n;

bool cmp(Node a, Node b){
	return a.x < b.x;
}

int main(void)
{
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d%d", &node[i].x, &node[i].y);
		node[i].id = i;
	}
	sort(node+1, node+n+1, cmp);
	
	double ans = -1;
	
	
	for(int i=1;i<n;i++){
		ans = max(ans, (double)(node[i+1].y - node[i].y) / (double)(node[i+1].x - node[i].x));
	}
	for(int i=1;i<n;i++){
		if((double)(node[i+1].y - node[i].y) / (double)(node[i+1].x - node[i].x) == ans){
			printf("%d %d", node[i].id, node[i+1].id);
		}
	}
	return 0;
}
