/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-25 11:01:31
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-25 11:17:16
*/

//POJ 2533
//MD这题用lower_bound调了半天也跳调不好，还是手写二分吧
//好。。。。吧，数组搞错了b写成了a ，怪不得总有错误数据

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

const int N = 1100;

int n;
int a[N];
int b[N];

// int findPos(int size, int k)
// {
// 	int l = 1;
// 	int r = size;
// 	while(l <= r){
// 		int mid = (l + r) >> 1;
// 		if(k > b[mid] && k <= b[mid+1]){
// 			return mid+1;
// 		}else if(k < b[mid]){
// 			r = mid - 1;
// 		}else{
// 			l = mid + 1;
// 		}
// 	}
// 	return 0;
// }

int LIS()
{
	int ans = 1;
	int posUpdate;

	b[1] = a[1];
	for(int i=2;i<=n;i++){
		if(a[i] <= b[1]){
			posUpdate = 1;
		}else if(a[i] > b[ans]){
			posUpdate = ++ans;
		}else{
			// posUpdate = findPos(ans, a[i]);
			posUpdate = lower_bound(b, b+ans, a[i]) - b;
		}
		b[posUpdate] = a[i];
		//不理解的话就把这几行注释去掉看看数据
		// for(int i=1;i<=n;i++){
		// 	printf("%d ", a[i]);
		// }
		// printf("\n");
		// for(int i=1;i<=n;i++){
		// 	printf("%d ", b[i]);
		// }
		// printf("\n\n");
	}
	return ans;
}

int main(void)
{
	
	while(~scanf("%d", &n)){
		for(int i=1;i<=n;i++){
			scanf("%d", &a[i]);
		}
		printf("%d\n", LIS());
	}
	return 0;
}