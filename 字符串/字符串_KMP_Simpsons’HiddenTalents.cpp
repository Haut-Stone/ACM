/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-31 21:14:06
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-31 21:17:23
*/

//HDU 2594
//这题就是吧两个字符串连在一起，然后生成一遍next数组，运用next数组的性质就可以解决问题了，正好
//就是串1的前缀和串2的后缀所共同匹配的数量。
//需要注意的是，最后结果不可能大于任意串1和串2原来的长度。

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

const int N = 100;

int iNext[N];

void getNext(char pattarn[])
{
	int len = strlen(pattarn);
	int j = -1;
	iNext[0] = -1;

	for(int i=1;i<len;i++){
		while(j != -1 && pattarn[i] != pattarn[j+1]){
			j = iNext[j];
		}
		if(pattarn[i] == pattarn[j+1]){
			j++;
		}
		iNext[i] = j;
	}
}

int main(void)
{
	char str1[N];
	char str2[N];

	while(~scanf("%s%s", str1, str2)){
		strcat(str1, str2);
		int len = strlen(str1);
		getNext(str1);
		if(iNext[len-1]+1 == 0){
			printf("0\n");
		}else{
			for(int i=0;i<iNext[len-1]+1;i++){
				printf("%c", str1[i]);
			}
			printf(" %d\n", iNext[len-1]+1);
		}
	}
	return 0;
}