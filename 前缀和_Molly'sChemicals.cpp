/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-23 19:59:52
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-23 22:28:31
*/

//http://vj.sdutacm.org/contest/view.action?cid=62953#problem/A
//前缀和，map的运用
//map其实就是特殊的数组映射，没什么。不用畏惧

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N = 100005;
const long long INF = 1e16 + 10; 
int n, k;
int solo;
long long ans;
long long sum[N];
long long rom[70];
map<long long , long long>Imap;

void init()//打一张次方表
{
	rom[0] = 1;
	for(int i=1;i<=64;i++){
		if(rom[i-1] < INF){
			rom[i] = rom[i-1] * k;
		}
	}
	return;
}

int main(void)
{
	cin>>n>>k;

	//初始化与打表部分
	Imap.clear();
	memset(sum, 0, sizeof(sum));
	init();

	//前缀和判断
	for(int i=1;i<=n;i++){
		cin>>solo;
		for(int j=0;j<=64 && rom[j] < INF;j++){
			if(k == 1 || k == -1){//特殊情况的处理
				if(k == -1)  Imap[sum[i-1]-1]++;//这里对于1和-1的处理十分的巧妙
                Imap[sum[i-1]+1]++;  
                break;
			}else{
				Imap[sum[i-1] + rom[j]]++;//这里将原来被减数移到了等号的右边（关键）
			}
		}
		sum[i] = sum[i-1] + solo;//以前缀和的方式保存数组
		ans += Imap[sum[i]];
	}
	printf("%lld\n", ans);
    return 0;
}