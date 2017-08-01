/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-01 09:25:35
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-01 09:26:30
*/

//HDU 3336
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

const int N = 200100;
const int MOD = 10007;

int iNext[N];
int d[N];

void getNext(char str[], int n)
{
	int j = -1;
	iNext[0] = -1;
	for(int i=1;i<n;i++){
		while(j != -1 && str[i] != str[j+1]){
			j = iNext[j];
		}
		if(str[i] == str[j+1]){
			j++;
		}
		iNext[i] = j;
	}
}

int main(void)
{
	int T;
	int n;
	char str[N];
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		scanf("%s", str);
		getNext(str, n);
		int ans = 0;
		for(int i=0;i<n;i++){
			if(iNext[i] == -1){
				d[i] = 1;
			}else{
				d[i] = d[iNext[i]] + 1;
			}
			ans += d[i];
			ans %= MOD;
		}
		printf("%d\n", ans);
	}
	return 0;
}