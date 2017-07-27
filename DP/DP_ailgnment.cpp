/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-26 20:29:06
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-26 20:36:36
*/

//POJ 1836
//

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

double high[N];
int fromLeft[N];
int fromRight[N];
int n;

int main(void)
{
	while(~scanf("%d", &n)){
		for(int i=0;i<n;i++){
			scanf("%lf", &high[i]);
		}
		fromLeft[0] = fromRight[n-1] = 1;

		//分别向左和向右进行LIS
		for(int i=1;i<n;i++){
			fromLeft[i] = 1;
			for(int j=0;j<i;j++){
				if(high[j] < high[i]){
					fromLeft[i] = max(fromLeft[i], fromLeft[j]+1);
				}
			}
		}

		for(int i=n-2;i>=0;i--){
			fromRight[i] = 1;
			for(int j=n-1;j>i;j--){
				if(high[j] < high[i]){
					fromRight[i] = max(fromRight[i], fromRight[j]+1);
				}
			}
		}

		int ans = 0;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				//枚举两个顶峰的位置
				ans = max(ans, (fromLeft[i] + fromRight[j]));
			}
		}

		printf("%d\n", n-ans);
	}
	return 0;
}