/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-24 14:51:33
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-24 15:12:51
*/

//这道貌似是省赛题？
//这道题的关键在于，先求出这个店到E的话费，作为商店的单价。（想到这一点十分的重要）
//这样，在买的时候，就不用担心距离了，直接贪心选择价格小的就可以了。

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

struct Node
{
	int pos;//商店的位置
	int f;//最多卖的数量
	int c;//处理前的单价
	int s;//处理后的单价
}a[120];

int k, L, n;

bool cmp(Node a1, Node a2)
{
	return a1.s < a2.s;//优先选择单价小的
}

int main(void)
{
	// INPUT_TEST;
	int T;
	cin>>T;
	while(T--){
		cin>>k>>L>>n;
		for(int i=0;i<n;i++){
			scanf("%d%d%d", &a[i].pos, &a[i].f, &a[i].c);
			a[i].s = L-a[i].pos + a[i].c;
		}
		sort(a, a+n, cmp);
		int sum = 0;
		int cnt = 0;
		for(int i=0;i<n;i++){
			if(cnt < k){
				if(cnt + a[i].f <= k){
					sum += a[i].f * a[i].s;
					cnt += a[i].f;
					if(cnt == k){
						break;
					}
 				}else{
 					sum += (k - cnt) * a[i].s;
 					break;
 				}
			}
		}
		printf("%d\n", sum);
	}
    return 0;
}