/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-02 19:30:23
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-02 19:31:29
*/


//这题要是分析清楚了就算是蛮好写的了，2堆石头的时候是裸的威左夫，其他情况是裸的nim
//http://blog.csdn.net/bless924295/article/details/71435496

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <stack>
#include <vector>
using namespace std;

const int N = 100;

int a[N];
int n;

int main(void)
{
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%d", &a[i]);//读入每堆石子的个数
		}
		if(n == 2){//两堆石子的话特判
			//裸的威左夫
			if(a[0] < a[1]){
				swap(a[0], a[1]);
			}
			//？？
			if(floor((a[0] - a[1])*((sqrt(5.0)+1.0)/2.0)) != a[1]){
				printf("Sherlock\n");
			}else{
				printf("Watson\n");
			}
		}else{
			//裸的nim
			int k = a[0];
			for(int i=1;i<n;i++){
				k ^= a[i];//异或掉所有石子的值
			}
			if(k == 0){
				printf("Watson\n");
			}else{
				printf("Sherlock\n");
			}
		}
	}
	return 0;
}
