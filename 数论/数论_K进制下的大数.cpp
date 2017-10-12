/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-12 20:39:50
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-12 20:41:07
*/

//这道题还是主要依靠数的性质，将各位的数字加起来求和。对可能出现的数字取余
//https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1116

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

const int N = 100000 + 10;
const int MAXK = 36;

char a[N];

int main(void)
{
	scanf("%s", a);
	int len = (int)strlen(a);
	int sum = 0;
	int MINK = 2;
	
	for(int i=0;i<len;i++){
		if(isdigit(a[i])){
			MINK = max(MINK, a[i] - '0' + 1);
			sum += a[i] - '0';
		}else{
			MINK = max(MINK, a[i] - 'A' + 11);
			sum += a[i] - 'A' + 10;
		}
	}
	
	bool flag = false;
	for(int i=MINK;i<=MAXK;i++){
		if(sum % (i-1) == 0){
			flag = true;
			printf("%d\n", i);
			break;
		}
	}
	if(!flag){
		printf("No Solution\n");
	}
	return 0;
}

