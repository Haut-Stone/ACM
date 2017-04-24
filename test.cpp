/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-01-22 11:12:17
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-04-24 22:58:46
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

const int N = 110;

int main(void)
{
	INPUT_TEST;
	int T;
	char a[N];
	cin>>T;
	while(T--){
		cin>>a;
		int len = (int)strlen(a);
		int n = atoi(a);
		int temp = 1;
		for(int i=1;i<len;i++){
			temp *= 10;
		}
		n = n % temp;
		printf("%d\n", n);
	}
	return 0;
}