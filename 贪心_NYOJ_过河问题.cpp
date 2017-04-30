/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-25 17:27:04
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-25 18:39:08
*/
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

const int N = 1010;

int iTime[N];

int main(void)
{
	// INPUT_TEST;
	int T;
	int n;
	cin>>T;
	while(T--){
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%d", &iTime[i]);
		}
		sort(iTime, iTime+n);
		int sum = 0;
		while(n > 3){
			if(2*iTime[1] + iTime[0] > 2*iTime[0] + iTime[n-2]){
				sum += 2*iTime[0] + iTime[n-2] + iTime[n-1];
			}else{
				sum += 2*iTime[1] + iTime[0] + iTime[n-1];
			}
			n -= 2;
		}
		if(n == 3) sum += iTime[1] + iTime[0] + iTime[2];
		if(n == 2) sum += iTime[1];
		if(n == 1) sum += iTime[0];
		printf("%d\n", sum);
	}
    return 0;
}