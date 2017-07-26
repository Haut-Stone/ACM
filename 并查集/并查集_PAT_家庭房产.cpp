/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-29 10:13:10
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-29 10:14:32
*/

//这道题的关键就是存储关系，与并查集基础模版的区别在于，这次一定要是以id小的为根。
//https://pta.patest.cn/pta/test/6152/exam/4/question/89751

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

const int N = 10010;

struct Node
{
	int id;
	int fid;//父亲的ID
	int mid;//母亲的ID
	int k;//孩子的数量
	int sid[10];//孩子
	int n;//拥有的房子数量
	int s;//房子的面积
}d[1005];

struct Ans
{
	int id;
	int num;
	int a1;
	int a2;
	double b1;
	double b2;
}ans[N], res[N];

int par[N];//父节点
int Irank[N];//秩
bool vis[N];
bool has[N];

void init(int n)
{
	for(int i=0;i<n;i++){
		par[i] = i;
	}
}

int find(int x)
{	
	if(par[x] == x){
		return x;
	}else{
		return par[x] = find(par[x]);//在一次搜索后会优化，将连接直接连到根上。
	}
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(x < y){
		par[y] = x;//将大的点连接在小的点上
	}else{
		par[x] = y;
	}
}


bool cmp(Ans a, Ans b)
{
	if(a.b2 == b.b2){
		return a.id < b.id;
	}
	return a.b2 > b.b2;
}

int main(void)
{
	// INPUT_TEST;

	init(9999);
	int n;
	cin>>n;

	//数据输入和并查集集的关系处理
	for(int i=0;i<n;i++){
		scanf("%d %d %d", &d[i].id, &d[i].fid, &d[i].mid);
		vis[d[i].id] = true;
		if(d[i].fid != -1){
			vis[d[i].fid] = true;
			unite(d[i].id, d[i].fid);
		}
		if(d[i].mid != -1){
			vis[d[i].mid] = true;
			unite(d[i].id, d[i].mid);
		}
		cin>>d[i].k;
		for(int j=0;j<d[i].k;j++){
			scanf("%d", &d[i].sid[j]);
			if(d[i].sid[j] != -1){
				vis[d[i].sid[j]] = true;
				unite(d[i].id, d[i].sid[j]);
			}
		}
		cin>>d[i].n>>d[i].s;
	}

	for(int i=0;i<n;i++){
		int id = find(d[i].id);
		ans[id].id = id;//记录最小的点的ID
		ans[id].a1 += d[i].n;
		ans[id].a2 += d[i].s;
	}

	for(int i=0;i<N;i++){
		if(vis[i]) ans[find(i)].num++;//记录有关系的亲友的数量
	}

	int cnt = 0;
	for(int i=0;i<N;i++){
		if(vis[i]){
			int id = find(i);
			if(!has[id]){//如果这个节点没有被记录过的话
				has[id] = true;
				res[cnt].b1 = (double)ans[id].a1 / (double)ans[id].num;
				res[cnt].b2 = (double)ans[id].a2 / (double)ans[id].num;
				res[cnt].id = id;
				res[cnt++].num = ans[id].num;
			}
		}
	}

	sort(res, res+cnt, cmp);//调整输出的顺序
	printf("%d\n", cnt);
	for(int i=0;i<cnt;i++){
		if(res[i].id < 10){
			printf("000%d %d %.3f %.3f\n", res[i].id, res[i].num, res[i].b1, res[i].b2);
		}else if(res[i].id < 100){
			printf("00%d %d %.3f %.3f\n", res[i].id, res[i].num, res[i].b1, res[i].b2);
		}else if(res[i].id < 1000){
			printf("0%d %d %.3f %.3f\n", res[i].id, res[i].num, res[i].b1, res[i].b2);
		}else{
			printf("%d %d %.3f %.3f\n", res[i].id, res[i].num, res[i].b1, res[i].b2);
		}
	}
	return 0;
}