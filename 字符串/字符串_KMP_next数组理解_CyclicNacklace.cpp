/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-31 19:29:54
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-31 19:33:44
*/

//HDU 3746
//这题要求对next数组深入的了解。next数组表示前后缀的最大匹配长度

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

const int N = 100100;
int iNext[N];

void getNext(char pattern[], int m)
{
	int j = -1;
	iNext[0] = -1;
	for(int i=1;i<m;i++){
		while(j != -1 && pattern[i] != pattern[j+1]){
			j = iNext[j];
		}
		if(pattern[i] == pattern[j+1]){
			j++;
		}
		iNext[i] = j;
	}
}

int main(void)
{
	char str[N];
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%s", str);
		int len = (int)strlen(str);
		getNext(str, len);
		int ans = 0;
		int cir = len - (iNext[len-1] + 1);
		if(len % cir == 0 && cir != len){
			printf("0\n");
		}else{
			ans = cir - (len - (len / cir) * cir);
			printf("%d\n", ans);
		}
	}
	return 0;
}
