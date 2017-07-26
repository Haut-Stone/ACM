/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-08 10:50:58
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-08 13:08:50
*/

//https://acm.zzuli.edu.cn/zzuliacm/problem.php?id=1730
//小写的distance居然不能做函数名。。。(╯‵□′)╯︵┻━┻

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

// #define INPUT_TEST freopen("in.txt", "r", stdin)

const int N = 20;
const double INF = 1e8 + 10;

double costOfBaseStation;
double costOfRange;
int numberOfHouse;
int tempA, tempB;

double sum;
int s[N];
int a[N];
int b[N];
double use[N];

struct Node
{
	double x;
	double y;
}Houses[N];

double Distance(int a, int b)
{
	return sqrt((Houses[a].x - Houses[b].x)*(Houses[a].x - Houses[b].x) + (Houses[a].y - Houses[b].y)*(Houses[a].y - Houses[b].y));
}

void dfs(int pos)
{
	if(pos == tempA + 1){//如果所有的点都被覆盖了
		double res = 0;
		for(int i=1;i<=numberOfHouse;i++){
			res += use[i];
		}
		sum = min(res, sum);
		return;
	}
	for(int i=1;i<=tempB;i++){
		double dis = Distance(b[i], a[pos]);
		double temp = use[i];
		use[i] = max(use[i], dis);
		dfs(pos + 1);
		use[i] = temp;
	}		
}
 
double solve(int num)//num表示有建立基站的房子的个数。
{
	double res = costOfBaseStation * num;
	tempA = 0;
	tempB = 0;
	for(int i=1;i<=numberOfHouse;i++){
		if(s[i]){
			b[++tempB] = i;//用来标记建立基站的房子
		}else{
			a[++tempA] = i;//用来标记没有建立基站的房子，只要在dfs中用所有a的点可以覆盖b中的点就可以了。
		}
		use[i] = 0;
	}
	sum = 0;
	if(num != numberOfHouse){//所有房子都建立基站的情况，范围用为0
		sum = INF;
		dfs(1);//从第一个未被覆盖的房子开始搜起。
	}
	// printf("现在所需要的辐射半径是%.2f， 建有基站的个数是%d\n", sum, num);
	return res + sum * costOfRange;
}

int main(void)
{
	// INPUT_TEST;

	int T; 
	cin>>T;
	while(T--){
		cin>>numberOfHouse>>costOfBaseStation>>costOfRange;
		for(int i=1;i<=numberOfHouse;i++){//存储房子的位置信息
			cin>>Houses[i].x>>Houses[i].y;
		}
		double ans = INF;
		for(int i=1;i<=numberOfHouse;i++){//搜索建立基站的所有全排列。
			memset(s, 0, sizeof(s));
			for(int j=1;j<=i;j++){
				s[j] = 1;
			}
			do{
				ans = min(ans, solve(i));
			}while(prev_permutation(s+1, s+numberOfHouse+1));
		}
		printf("%.2f\n",ans);
	}
    return 0;
} 