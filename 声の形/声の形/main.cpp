/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-08-04 20:46:48
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-09-24 13:04:30
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

