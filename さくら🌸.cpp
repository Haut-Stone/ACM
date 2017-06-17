/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-01-22 11:12:17
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-06-12 15:39:24
 */

//CF

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

const int N = 110;

int n;
int a[N];
int zeroCnt;
int zeroPos;

int main(void)
{
	// INPUT_TEST;
	while(cin>>n>>zeroCnt){
		memset(a, 0, sizeof(a));
		for(int i=0;i<n;i++){
			scanf("%d", &a[i]);
			if(a[i] == 0){
				zeroPos = i;
			}
		}
		if(zeroCnt == 1){
			scanf("%d", &a[zeroPos]);
			int isIncrease = true;
			for(int i=0;i<n-1;i++){
				if(a[i] >= a[i+1]) isIncrease = false;
			}
			if(isIncrease){
				printf("No\n");
			}else{
				printf("Yes\n");
			}
		}else{
			for(int i=0;i<zeroCnt;i++){
				int solo;
				scanf("%d", &solo);
			}
			printf("Yes\n");
		}
	}
	return 0;
}