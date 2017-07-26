/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-21 18:39:23
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-21 21:37:09
*/

//最基本的任务排列贪心问题
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
typedef pair<double, double> pdd;

double len(double r, double h)
{
	return sqrt(r*r - h*h);
}

bool cmp(pdd a, pdd b)
{
	return a.first < b.first;
}

int main(void)
{
	// INPUT_TEST;
	int N;
	int n, w, h;
	int x, r;

	cin>>N;
	while(N--){
		cin>>n>>w>>h;
		vector<pdd > v;
		for(int i=0;i<n;i++){
			cin>>x>>r;
			if(r > h/2.0){
				double l = len(r, h/2.0);
				pdd p;
				p.first = x - l;
				p.second = x + l;
				v.push_back(p);
			}
		}
		sort(v.begin(), v.end(), cmp);
		double right = 0.0;
		int count = 0;

		//这里贪心点策略是按左边端点排序，其实这道题，还是蛮简单的
		while(right < w){
			double m = 0.0;
			for(int i=0;i<v.size() && v[i].first <= right;i++){
				if(v[i].second - right > m) m = v[i].second - right;//选择符合条件的里面区间长度最长的。
			}
			if(m != 0){//如果这个区间存在，说明没有搜完。
				count++;
				right+=m;
			}else{
				break;
			}
		}
		if(right < w){
			cout<<0<<endl;
		}else{
			cout<<count<<endl;
		}
	}
	return 0;
}