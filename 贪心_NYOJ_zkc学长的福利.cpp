/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-23 11:38:42
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-23 12:27:56
*/

//http://acm.nyist.net/JudgeOnline/problem.php?pid=1218
//贪心加高精

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
const int N = 1010;
struct Node
{
	int l;
	int r;
}people[N];

//交换规则
bool cmp(Node a, Node b)
{
	return a.l * a.r < b.l * b.r;
}

int main(void)
{
	// INPUT_TEST;
	int n;
	double ans;

	while(scanf("%d", &n) != EOF){
		ans = 1.0;
		cin>>people[0].l>>people[0].r;
		for(int i=1;i<=n;i++){
			cin>>people[i].l>>people[i].r;
		}
		sort(people+1, people+n+1, cmp);
		for(int i=0;i<n;i++){
			ans *= people[i].l;//最大的一定在最后一个
		}
		int temp = people[n].r;
		ans = ans / temp;
		temp = ans;//temp是ans的4舍五入。
		if(temp > ans){
			ans = temp - 1;
		}else{
			ans = temp;
		}
		printf("%.0f\n", ans);
	}
    return 0;
}