/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-18 10:57:19
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-18 11:00:15
*/

//枚举两个数的和，并存为新序列。然后再用双指针来判断所有可以存在的和的情况
//https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1267


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

bool flag = false;

struct Node
{
	int x;
	int y;
	int sum;
}node[N*N];

int num[N];

bool cmp(Node a, Node b)
{
	return a.sum < b.sum;
}

int main(void)
{
	int n;
	int cnt = 0;
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &num[i]);
		for(int j=1;j<i;j++){
			node[cnt].x = i;
			node[cnt].y = j;
			node[cnt++].sum = num[i] + num[j];
		}
	}
	sort(node, node+cnt, cmp);

	//node中存的是所有的2个数相加的和，再通过前后两个指针枚举4个数的和
	int i = 0;
	int j = cnt-1;
	while(i < cnt){
		if(node[i].sum + node[j].sum == 0){
			if(node[i].x != node[j].x && node[i].x != node[j].y && node[i].y != node[j].x && node[i].y != node[j].y){
				flag = true;
				break;
			}
			if(node[i].sum == node[i+1].sum){
				i++;
			}else if(node[j].sum == node[j-1].sum){
				j--;
			}else{
				i++;
				j--;
			}
		}else{
			if(node[i].sum + node[j].sum < 0){
				i++;
			}else{
				j--;
			}
		}
	}
	if(flag){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return 0;
}
