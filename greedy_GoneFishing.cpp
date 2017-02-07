/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-02-07 18:56:36
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-02-07 21:10:11
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

const int N = 25;

int n, h;
int f[N], d[N], t[N];
int ans;
int each[N];
int tans, teach[N];
int th, tf[N];


int main(void)
{
	while(cin>>n && n > 0){
		cin>>h;
		for(int i=0;i<n;i++) cin>>f[i];
		for(int i=0;i<n;i++) cin>>d[i];
		for(int i=0;i<n;i++) cin>>t[i];

		h *= 12;
		ans = -1;
		for(int i=0;i<n;i++){
			//初始化每次贪心的相关量。
			th = h;
			for(int j=0;j<n;j++){
				tf[j] = f[j];
				teach[j] = 0;
			}
			tans = 0;

			//对每一个5分钟贪心选择钓鱼量最大的湖钓鱼
			while(th>0){
				int ind, max;
				ind = 0;
				max = tf[0];
				for(int j=1;j<=i;j++){
					if(tf[j] > max){
						max = tf[j];
						ind = j;
					}
				}
				if(max == 0){
					teach[0] += th*5;
					break;
				}else{
					teach[ind] += 5;
					tans += tf[ind];
					if(tf[ind] >= d[ind]){
						tf[ind] -= d[ind];
					}else{
						tf[ind] = 0;
					}
				}
				th--;
			}
			//走过的湖个数为i+2时候的钓鱼时间
			if(i!=n-1){
				h -= t[i];
			}
			//更新最优方案结果
			if(tans > ans){
				ans = tans;
				for(int j=0;j<n;j++){
					each[j] = teach[j];
				}
			}
		}
		//输出结果
		cout<<each[0];
		for(int i=1;i<n;i++){
			cout<<", "<<each[i];
		}
		cout<<endl;
		cout<<"Number of fish expected: "<<ans<<endl;
		cout<<endl;
	}
    return 0;
}