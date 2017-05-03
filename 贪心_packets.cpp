/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-02 21:44:40
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-02 22:16:03
*/

//http://poj.org/problem?id=1017
//搞清楚箱子大小的关系，顺序模拟即可

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

int main(void)
{
	// INPUT_TEST;

	int s1,s2,s3,s4,s5,s6;//6种盒子分别的数量。
	while(cin>>s1>>s2>>s3>>s4>>s5>>s6 && (s1+s2+s3+s4+s5+s6)){
		int boxNum = 0;
		boxNum += s6;

		boxNum += s5;
		s1 = max(0, s1-s5*11);

		boxNum += s4;

		if(s2 >= s4*5){
			s2 -= s4*5;
		}else{
			s1 = max(0, s1-4*(s4*5 - s2));
			s2 = 0;
		}

		boxNum += (s3 + 3) / 4;
		s3 %= 4;

		if(s3){
			if(s2 >= 7-2*s3){
				s2 -= 7-2*s3;
				s1 = max(0, s1-(8-s3));
			}else{
				s1 = max(0, s1-(36 - 9*s3 - 4*s2));
				s2 = 0;
			}
		}

		boxNum += (s2 + 8)/9;
		s2 %= 9;
		
		if(s2){
			s1 = max(0, s1 - (36 - 4*s2));
		}
		boxNum += (s1 + 35) / 36;
		cout<<boxNum<<endl;
	}
	return 0;
}