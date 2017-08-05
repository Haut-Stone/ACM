/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-05 17:05:45
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-05 17:06:47
*/

//https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1256
//给出2个数M和N(M < N)，且M与N互质，找出一个数K满足0 < K < N且K * M % N = 1，如果有多个满足条件的，输出最小的。

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

//这里仍然返回的是最大公约数，但是通过中间的处理将x, y都算了出来。
int exGcd(int a, int b, int &x, int &y)
{
	if(b == 0){//开始反推的起点
		x = 1;
		y = 0;
		return a;
	}
	int gcd = exGcd(b, a%b, x, y);
	int temp = x;
	x = y;
	y = temp - (a/b)*y;
	return gcd;
}

int modInv(int a, int m)
{
	int x, y;
	exGcd(a, m, x, y);
	return (m+x%m)%m;
}

int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d\n", modInv(n, m));
	return 0;
}