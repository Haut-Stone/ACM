/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-12 19:51:53
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-12 19:52:45
*/

//一道简单单类似于哈夫曼树的题，用优先队列可解
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

const int N = 110;

int a[N];
int n;

int main(void)
{
	priority_queue<int, vector<int>, greater<int> > Q;
	int solo;
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &solo);
		Q.push(solo);
	}
	
	int a, b;
	int sum = 0;
	while(Q.size() > 1){
		a = Q.top();
		Q.pop();
		b = Q.top();
		Q.pop();
		sum += a + b;
		Q.push(a+b);
	}
	printf("%d\n", sum);
}