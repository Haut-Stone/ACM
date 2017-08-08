/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-05 17:52:37
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-05 17:53:25
*/

//手撸二分水过
//原题链接：https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1001

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

const int N = 50010;
int a[N];
int n, targetNumber;
bool flag;

void search(int x, int l, int r)
{
	if(x == a[l]){
		flag = true;
		return;
	}
	if(l == r){
		return;
	}
	if(l < r){
		int mid = (l + r) >> 1;
		if(x <= a[mid]){
			search(x, l, mid);
		}else{
			search(x, mid+1, r);
		}
	}
}

int main(void)
{
	
	while(~scanf("%d%d", &targetNumber, &n)){
		int flag2 = 0;
		for(int i=0;i<n;i++){
			scanf("%d", &a[i]);
		}
		sort(a, a+n);
		for(int i=0;i<n;i++){
			flag = false;
			int temp = targetNumber - a[i];
			search(temp, i+1, n-1);
			if(flag){
				printf("%d %d\n", a[i], temp);
			}
			if(flag){
				flag2 = 1;
			}
		}
		if(!flag2){
			printf("No Solution");
		}
	}
	return 0;
}