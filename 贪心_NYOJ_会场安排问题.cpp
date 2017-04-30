/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-25 17:13:48
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-25 17:27:29
*/

//经典的问题，按右端点从小到大的顺序排列即可。
//算法正确性分析见：http://blog.csdn.net/luoweifu/article/details/18195607

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

const int N = 10100;

struct Node
{
	int l;
	int r;
}activity[N];

bool cmp(Node a, Node b)
{	
	return a.r < b.r;
}

int main(void)
{
	// INPUT_TEST;
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			scanf("%d%d", &activity[i].l, &activity[i].r);
		}
		sort(activity, activity + n, cmp);
		int ans = 0;
		int pos = -1;
		for(int i=0;i<n;i++){
			if(pos < activity[i].l){
				ans++;
				pos = activity[i].r;
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}