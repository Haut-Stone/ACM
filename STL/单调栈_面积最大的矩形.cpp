/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-12 19:59:31
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-12 20:04:17
*/

//数据结构的灵活运用，单调栈，最后栈中保存一个长度递增的单调序列。
//重点在于当下一个块的长度比之前的小的时候，将之前完好的单调序列弹出求最大值。
//https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1102
//http://blog.csdn.net/woshinannan741/article/details/52374489

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

typedef long long LL;
const int N = 10100;

LL n;
LL height;
LL a[N];
stack<pair<LL, LL> > S;

int main(void)
{
	scanf("%lld", &n);
	
	LL ans = 0;

	for(LL i=1;i<=n;i++){
		scanf("%lld", &height);
		LL width = 0;
		while(!S.empty() && S.top().first >= height){
			LL a = S.top().first;
			LL b = S.top().second;
			S.pop();
			width += b;
			ans = max(ans, a*width);
		}
		S.push(make_pair(height, width+1));
	}

	//解决最后剩余在栈中的单调元素
	LL temp = 0;
	while(!S.empty()){
		ans = max(ans, S.top().first * (temp + S.top().second));
		temp += S.top().second;
		S.pop();
	}

	printf("%lld\n", ans);
	return 0;
}

