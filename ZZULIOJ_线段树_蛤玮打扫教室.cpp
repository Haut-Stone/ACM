/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-09 11:11:36
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-09 16:07:00
*/

//https://acm.zzuli.edu.cn/zzuliacm/problem.php?id=1877
//线段树的基础题。
//在纸上推演一遍就可以明白过程究竟是什么样子的了
//这道题比较坑的地方在于，数据量很大，要用位运算代替乘法优化，切忌使用cin用cin会使时间增长大约0.5s...Σ（・□・；）
//其实中间的递归过程，先不看返回条件，先专注于递下去的过程，更好理解。
//注释的详细版本看印象笔记。。。。

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

const int N = 100005;

int n, m;

struct Node
{	
	int left;
	int right;
	int callNum;//当前区间被覆盖次数，视题目要求而定。
}Tree[N<<2];//建树,所需空间是标准的4倍，这里的四倍是固定的

struct Noden
{
	int leftNum;
	int rightNum;
}Num[N];


int res[N];//表示符合要求的签的下标

//建树，传入根节点及根节点区间
void build(int root, int left, int right)
{
	Tree[root].left = left;//记录当前区间左右端点值
	Tree[root].right = right;
	Tree[root].callNum = 0;

	if(left == right){//递归构造终止条件
		return;
	}

	int mid = (left + right)>>1;
	build(root<<1, left, mid);
	build(root<<1|1, mid+1, right);
}

void update(int root, int left, int right)//更新树，传入根节点及待更新区间，（这里是单点更新）
{
	if(Tree[root].left == left &&  Tree[root].right == right){//达到区间结点
		Tree[root].callNum++;
		return;//待更新区间与当前区间完全重合，则计数数据加1并终止更新
	}

	int mid = (Tree[root].left + Tree[root].right)>>1;

	if(right <= mid){//待更新区间完全在当前区间左半部分
		update(root<<1, left, right);
	}else if(left > mid){//待更新区间完全在当前区间右半部分
		update(root<<1|1, left, right);
	}else{//待更新区间横跨当前区间
		update(root<<1, left, mid);//左右部分分别更新
		update(root<<1|1, mid+1, right);
	}
}

void init()
{
	memset(Tree, 0, sizeof(Tree));
	memset(Num, 0, sizeof(Num));
	memset(res, 0, sizeof(res));
	build(1,1,n);
}

void read()
{
	cin>>n>>m;

	init();
	for(int i=1;i<=m;i++){
		scanf("%d%d", &Num[i].leftNum, &Num[i].rightNum);
		update(1, Num[i].leftNum, Num[i].rightNum);
	}
}


void up(int root, int left, int right)
{
	if(left == right) return;

	Tree[root<<1].callNum += Tree[root].callNum;
	Tree[root<<1|1].callNum += Tree[root].callNum;

	int mid = (Tree[root].left + Tree[root].right)>>1;

	up(root<<1, left, mid);
	up(root<<1|1, mid+1, right);

	Tree[root].callNum = min(Tree[root<<1].callNum, Tree[root<<1|1].callNum);//这段区间被访问的次数
}

int Query(int root, int left, int right)//查询树，传入根节点及查询区间，返回查询区间计数
{
	if(Tree[root].left ==left && Tree[root].right == right){
		return Tree[root].callNum;
	}

	int mid = (Tree[root].left + Tree[root].right)>>1;

	if(right <= mid){
		return Query(root<<1, left, right);
	}else if(left > mid){
		return Query(root<<1|1, left, right);
	}else{
		return min(Query(root<<1, left, mid), Query(root<<1|1, mid+1, right));
	}
}

int main(void)
{
	// INPUT_TEST;

	int T;
	cin>>T;
	while(T--){
		read();
		up(1,1,n);//将叶子结点的值，全部更新到根上。
		int sum = 0;
		for(int i=1;i<=m;i++){
			if(Query(1, Num[i].leftNum, Num[i].rightNum) >= 2){//这里的2是因为，至少要两次询问，2减去男主的询问，就剩1次，说明教室至少已经被打扫过一次。
				res[sum++] = i;
			}
		}
		if(sum == 0){
			printf("0\n");
		}else{
			printf("%d\n%d", sum, res[0]);
			for(int i=1;i<sum;i++){
				printf(" %d", res[i]);
			}
			printf("\n");
		}
	}
    return 0;
}