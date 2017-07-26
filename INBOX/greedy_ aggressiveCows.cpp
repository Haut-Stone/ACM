/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-02-02 18:20:26
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-02-07 15:58:30
*/

//总之，贪心是一种策略吧。。
//这道题主要是先用二分来缩小可能的范围，在用贪心来判断正在考虑的这个项是否成立。
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

int position[200000];
int n, m;

bool greed(int k)
{
	int max = position[0];
	int sum = 0;
	for(int i=1;i<n;i++){
		if(position[i] - max >= k){
			sum++;
			max = position[i];
		}
		if(sum >= m-1){
			return true;
		}
	}
	return false;
}

void binarySearch()
{
	int left = 0;
	int right = position[n-1] - position[0];
	int mid;
	while(left <= right){
		mid = (left+right)/2;
		if(greed(mid)){
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}
	printf("%d\n", left-1);
}

int main(void)
{
	while(scanf("%d%d", &n, &m) != EOF){
		for(int i=0;i<n;i++){
			scanf("%d", &position[i]);
		}
		sort(position, position+n);
		binarySearch();
	}
    return 0;
}