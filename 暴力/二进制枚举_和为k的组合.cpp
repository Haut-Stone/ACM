/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-18 11:24:04
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-18 11:24:51
*/

//en, 直接二进制暴力枚举就可以了，数据有点弱了，被水过去了
//https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1268

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

const int N = 30;

int n, k;
int a[N];
int num[N];
bool flag = false;


int main(void)
{
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++){
		scanf("%d", &num[i]);
	}
	//简单形式的二进制枚举方式
	for(int i=0;i< 1<<n;i++){
		for(int j=0;j<n;j++){
			a[n-j-1] = i>>j&1;//这里从右向左，依次填充a[i]的状态
		}
		int sum = 0;
		for(int j=0;j<n;j++){
			if(a[j]){
				sum += num[j];
			}
		}
		if(sum == k){
			flag = true;
			break;
		}
	}
	if(flag){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return 0;
}
