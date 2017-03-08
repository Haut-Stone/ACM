/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-03-08 18:37:12
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-03-08 20:55:04
*/

//http://vj.sdutacm.org/contest/view.action?cid=62917#problem/D
//出题的背景居然是冰火。。。壮哉！


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

long long ans;

void solve(long long first, long long last, long long left, long long right, long long Number)
{
	if(first > last || left > right){//如果长度空，或者区间空，问题解决完成，返回。
		return;
	}else{
		long long mid = (first+last)/2;//取中值。
		if(right < mid){
			solve(first, mid-1, left, right, Number/2);
		}else if(mid < left){
			solve(mid+1, last, left, right, Number/2);
		}else{
			ans += Number % 2;
			solve(first, mid-1, left, mid-1, Number/2);
			solve(mid+1, last, mid+1, right, Number/2);
		}
	}
	return;
}

int main(void)
{
	long long rawNumber;
	long long rawLeft;
	long long rawRight;
	long long temp;	
	long long length;
	cin>>rawNumber>>rawLeft>>rawRight;
	length = 1;
	temp = rawNumber;
	while(temp >= 2){
		temp /= 2;
		length = length*2+1;//确定01串的长度
	}
	solve(1, length, rawLeft, rawRight, rawNumber);
	cout<<ans<<endl;
    return 0;
}