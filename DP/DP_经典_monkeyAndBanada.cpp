/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-11 23:31:43
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-12 16:43:34
*/

//题目:http://acm.hdu.edu.cn/showproblem.php?pid=1069
//
//题意:一堆科学家研究猩猩的智商，给他M种长方体，每种N个。
//然后，将一个香蕉挂在屋顶，让猩猩通过 叠长方体来够到香蕉。
//现在给你M种长方体，计算，最高能堆多高。
//要求位于上面的长方体的长要大于（注意不是大于等于）下面长方体的长，上面长方体的宽大于下面长方体的宽。

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

const int N = 200;

int n;
int cas;
int ans;
int len;
int a,b,c;
int dp[N];

struct Node
{
	int length;
	int weight;
	int height;
}block[N];

void read()
{
	for(int i=0;i<n;i++){
		scanf("%d%d%d", &a, &b, &c);//分别存入6种储存方式
		block[len].length = a,block[len].weight = b,block[len++].height = c;
		block[len].length = a,block[len].weight = c,block[len++].height = b;
		block[len].length = b,block[len].weight = a,block[len++].height = c;
		block[len].length = b,block[len].weight = c,block[len++].height = a;
		block[len].length = c,block[len].weight = b,block[len++].height = a;
		block[len].length = c,block[len].weight = a,block[len++].height = b;
	}
}

//面积大的放在最下面
bool cmp(Node a, Node b)
{
	if(a.length == b.length) return a.weight < b.weight;
	return a.length < b.length;
}

//终于明白了，不是要按面积算。
void solve()
{
	sort(block, block + len, cmp);//按面积大小排序
	dp[0] = block[0].height;
	for(int i=1;i<len;i++){//到第i个方块，最多可以累多高
		ans = 0;
		for(int j=0;j<i;j++){
			if(block[j].length < block[i].length && block[j].weight < block[i].weight){
				ans = max(ans, dp[j]);
			}	
		}
		dp[i] = block[i].height + ans;
	}

	//再次搜索DP中的最大值
	ans = 0;
	for(int i=0;i<len;i++){
		ans = max(ans, dp[i]);
	}
}

void init()
{
	ans = 0;
	len = 0;
}

int main(void)
{
	// INPUT_TEST;

	cas = 1;
	while(scanf("%d", &n), n != 0){
		init();
		read();
		solve();
		printf("Case %d: maximum height = %d\n", cas, ans);
		cas++;
	}
	return 0;
}