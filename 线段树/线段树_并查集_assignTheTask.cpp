/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-07-21 14:50:18
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-21 15:51:52
*/

//HDU 3974
//题意,公司中有n个员工,除了boss,每个员工都有自己的上司,自己下属的下属也是自己的下属  当给
//一个员工分配任务时,这个员工会把任务也分配到自己的所有下属,每个员工都只做最后一个被分配的任
//务对于每个C x,输出员工x正在做的任务,没有就输出-1把员工的关系数建成类似并查集的结构把每个
//直接分配任务的员工的任务和任务分配时间保存起来,查询时只要找这个员工所有父节点中最晚分配的任务

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

const int N = 50005;

struct Node
{
	int task;//任务
	int time;//时间
}employee[N];

int par[N];//记录父亲节点

//初始化并查集
void init(int employ_num)
{
	memset(par, -1, sizeof(par));
	for(int i=1;i<=employ_num;i++){
		employee[i].time = employee[i].task = 0;
	}
}

int main(void)
{
	int T;
	int employ_num, queryNum;
	int soloemp, task;
	char op[5];

	scanf("%d", &T);
	for(int cas=1;cas<=T;cas++){
		scanf("%d", &employ_num);
		init(employ_num);

		for(int i=0;i<employ_num-1;i++){
			scanf("%d%d", &soloemp, &task);
			par[soloemp] = task;
		}

		scanf("%d", &queryNum);
		int time = 0;
		int last;
		int ans;

		printf("Case #%d:\n", cas);
		while(queryNum--){
			scanf("%s%d", op, &soloemp);
			if(op[0] == 'C'){
				last = 0;
				while(soloemp != -1){
					if(employee[soloemp].time > last){
						last = employee[soloemp].time;
						ans = employee[soloemp].task;
					}
					soloemp = par[soloemp];
				}
				printf("%d\n", last ? ans :-1);
			}else{
				scanf("%d", &task);
				employee[soloemp].task = task;
				employee[soloemp].time = ++time;
			}
		}
	}
	return 0;
}