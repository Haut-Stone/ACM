/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-05 15:35:28
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-05 15:54:00
*/

//这题，在交换的时候，记录经过的数字的位数就行了
//http://cxsjsxmooc.openjudge.cn/2017t2summerw4/2/

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

const int N = 100010;
long long a[N];
long long temp[N];
long long ans;

void merge(int la, int ra, int lb, int rb)
{
	int index = 0;
	int i = la;
	int j = lb;
	int wl = 0;
	while(i <= ra && j <= rb){
		if(a[i] <= a[j]){
			temp[index++] = a[i++];
		}else{
			ans += j-i-wl;
			wl++;
			temp[index++] = a[j++];
		}
	}
	while(i <= ra){
		temp[index++] = a[i++];
	}
	while(j <= rb){
		temp[index++] = a[j++];
	}
	for(int i=0;i<index;i++){
		a[la+i] = temp[i];
	}
}

void mergeSort(int l, int r)
{
	if(l < r){
		int mid = (l + r) >> 1;
		mergeSort(l, mid);
		mergeSort(mid+1, r);
		merge(l, mid, mid+1, r);
	}
}

int main(void)
{
	int n;
//	INPUT_TEST;
	while(~scanf("%d", &n)){
		ans = 0;
		for(int i=0;i<n;i++){
			scanf("%lld", &a[i]);
		}
		mergeSort(0, n-1);
		printf("%lld\n", ans);
	}
	return 0;
}