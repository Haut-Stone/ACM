/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-10 17:09:56
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-10 17:10:22
*/

//https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1024
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

set<double> iSet;

int main(void)
{
	int n, m, a, b;
	scanf("%d%d%d%d", &m, &n, &a, &b);
	for(int i=a;i<n+a;i++){
		for(int j=b;j<m+b;j++){
			double sum = (double)j*log2(1.0*i);
			iSet.insert(sum);
		}
	}
	printf("%lu\n", iSet.size());
}
