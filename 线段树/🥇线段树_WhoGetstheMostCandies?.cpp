/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-29 15:50:09
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-29 15:52:31
*/

//POJ 2886
//这题和BuyTickets有异曲同工之妙。

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
#define lid (id<<1)
#define rid (id<<1|1)
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;

const int N = 500005;

struct Info
{
	char name[30];
	int value;
}children[N];

struct Node
{
	int l, r;
	int alive;
}segTree[N*4];

int n;
int startIndex;
int pos;
int leftAlive;
int rightAlive;
int now;
int candys[N];

void candy()
{
	memset(candys, 0, sizeof(candys));
	for(int i=1;i<N;i++){
		candys[i]++;
		for(int j=i+i;j<=N;j+=i){
			candys[j]++;
		}
	}
}
void build(int id, int l, int r)
{
	segTree[id].l = l;
	segTree[id].r = r;
	segTree[id].alive = (r - l + 1);
	if(segTree[id].l == segTree[id].r){
		return;
	}
	int mid = (segTree[id].l + segTree[id].r) >> 1;
	build(lid, l, mid);
	build(rid, mid+1, r);
}

void update(int id, int target)
{
	if(segTree[id].l == segTree[id].r){
		segTree[id].alive--;
		now = segTree[id].l;
		return;
	}
	if(target <= segTree[lid].alive){
		rightAlive += segTree[rid].alive;
		update(lid, target);
	}else{
		leftAlive += segTree[lid].alive;
		update(rid, target - segTree[lid].alive);
	}
	segTree[id].alive = segTree[lid].alive + segTree[rid].alive;
}

int main(void)
{
	candy();
	int maxChildren = 1;
	while(~scanf("%d%d", &n, &startIndex)){
		for(int i=1;i<=n;i++){
			scanf("%s%d", children[i].name, &children[i].value);
			if(candys[maxChildren] < candys[i]) maxChildren = i;
		}
		build(1, 1, n);
		pos = startIndex;//pos代表第几个仍然在队伍里的人的位置
		for(int childrenPassed=1;childrenPassed<=maxChildren;childrenPassed++){
			leftAlive = 0;
			rightAlive = 0;
			update(1, pos);
			if(childrenPassed == n) continue;
			if(n - childrenPassed == 1){
				pos=1;
				continue;
			}
			int cd = children[now].value;

			//计算下一个有人的位置。。这里真的是恶心
			if(cd < 0){
				cd = -(cd % (n - childrenPassed));
				if(!cd){
					cd = n - childrenPassed;
				}
				if(cd <= leftAlive){
					cd = leftAlive - cd + 1;
				}else{
					cd = rightAlive - (cd - leftAlive) + 1 + leftAlive;
				}
			}else{
				cd = cd % (n - childrenPassed);
				if(!cd){
					cd = n - childrenPassed;
				}
				if(cd <= rightAlive){
					cd = leftAlive + cd;
				}else{
					cd = cd - rightAlive;
				}
			}
			pos = cd;
		}
		printf("%s %d\n", children[now].name, candys[maxChildren]);
	}
	return 0;
}
