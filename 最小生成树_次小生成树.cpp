/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-31 19:50:15
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-21 22:30:12
*/

//https://vjudge.net/contest/156294?#problem/G
//这道题WA了3次，本来以为是逻辑问题，谁知道是sort了多次，造成超时了，也不知道提示TLE，还以为是咋回事呢。。。。坑。
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
using namespace std;

#define INPUT_TEST freopen("in.txt", "r", stdin)


const int LEN = 505;

int parents[LEN];
int vis[200005];//用以记录最小生成树所用的边
int edgeNumber;
int vertexNumber;//本题中这个数据无效
int ans;
int secondAns;
bool isTree;
bool canBeFind;

//用来存边
struct Edge
{
	int begin;
	int end;
	int distance;
}edges[200005];
//比较函数
bool cmp(Edge a, Edge b)
{	
	return a.distance < b.distance;
}
//并查集的查找
int find(int x)
{
	if(parents[x] == x){//到达根结点的时候
		return x;
	}else{
		return parents[x] = find(parents[x]);
	}	
}

//初始化并查集
void init()
{
	for(int i=1;i<=LEN;i++){//相当于声明了27个没有叶子的树。
		parents[i] = i;
	}
}
//合并两树
bool hadUnite(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x == y){
		return true;
	}else{
		parents[x] = y;//如果不是同一个集合的，则将两个点连起来。
	}
	return false;
}

int kruskal(int flag)
{
	init();
	int ans = 0;
	for(int i=1;i<=edgeNumber;i++){
		if(vis[i] < 2){//如果该边未被删除
			if(hadUnite(edges[i].begin, edges[i].end)){
				continue;
			}else{
				ans += edges[i].distance;//这里在hadUnite函数里已经合并过了。这里不用再合并。
				if(flag) vis[i] = 1;//标记该边已被查找
			}
		}
	}
	return ans;
}

void read()
{
	cin>>vertexNumber>>edgeNumber;
	for(int i=1;i<=edgeNumber;i++){
		cin>>edges[i].begin>>edges[i].end>>edges[i].distance;//读入各个边的数据
	}	
	memset(vis,0,sizeof(vis));
}

int main(void)
{

	INPUT_TEST;
	int T;
	cin>>T;//数据的组数
	while(T--){
		read();//读入数据
		sort(edges+1, edges+1+edgeNumber, cmp);
		ans = kruskal(1);//求最小生成树
		canBeFind  = false;//设答案状态为没有找到

		for(int i=1;i<=edgeNumber;i++){
			if(vis[i] == 1) vis[i] = 2;//2表示该边已被删除
			if(vis[i] == 0) continue;
				secondAns = kruskal(0);

				isTree = true;
				int temp = find(1);
				for(int j=2;j<=vertexNumber;j++){
					if(temp != find(j)){
						isTree = false;
						break;
					}
				}
				if(isTree){
					if(ans == secondAns){
						canBeFind = true;
						break;
					}
				}
				vis[i] = 1;
		}
		if(canBeFind){
			printf("Not Unique!\n");
		}else{
			printf("%d\n", ans);
		}
	}
    return 0;
}