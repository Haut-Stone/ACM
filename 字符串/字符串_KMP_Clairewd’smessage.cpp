/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-01 10:27:30
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-01 10:28:28
*/

//HUD 4300
//这题还是考察队next数组的理解
//http://www.cnblogs.com/liuxin13/p/4732661.html

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
map<char, char> keyToAlpha;

void getNext(char pattern[])
{
	int len = (int)strlen(pattern);
	int j = -1;
	iNext[0] = -1;
	for(int i=1;i<len;i++){
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
	char keys[N];
	char waitToTran[N];
	
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%s%s", keys, waitToTran);
		//加工字符串的过程没有可读性，直接运行看结果就好了
		int keysLen = (int)strlen(keys);
		int waitToTranLen = (int)strlen(waitToTran);
		char raw[N];
		strcpy(raw, waitToTran);
		for(int i=0;i<keysLen;i++){
			keyToAlpha[keys[i]] = (char)(97+i);
		}
		int mid = (waitToTranLen+1)/2;
		for(int i=0;i<mid;i++){
			waitToTran[i] = keyToAlpha[waitToTran[i]];
		}
		char temp[N];
		strcpy(temp, waitToTran+mid);
		waitToTran[mid] = '*';
		waitToTran[mid+1] = '\0';
		strcat(waitToTran, temp);
		getNext(waitToTran);
		int len = (int)strlen(waitToTran);
		int res = len - 1 - (iNext[len-1] + 1);
		for(int j=0;j<res;j++){
			printf("%c", raw[j]);
		}
		for(int j=0;j<res;j++){
			printf("%c", keyToAlpha[raw[j]]);
		}
		printf("\n");
	}
	return 0;
}