/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-01 10:52:59
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-01 10:54:01
*/

//POJ 2406
//这题和下边那道金牌题CyclicNacklace基本一样

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

const int N = 2001000;

int iNext[N];

void getNext(char pattern[], int n)
{
	int j = -1;
	iNext[0] = -1;
	for(int i=1;i<n;i++){
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
	char text[N];
	
	while(~scanf("%s", text)){
		if(text[0] == '.') break;
		int len = (int)strlen(text);
		getNext(text, len);
		int cir = len - (iNext[len-1] + 1);
		if(len % cir == 0){
			printf("%d\n", len/cir);
		}else{
			printf("1\n");
		}
	}
	return 0;
}