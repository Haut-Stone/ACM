/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-10-01 12:45:19
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-01 12:46:27
*/

//这道题很有意思，离散数学的题，看来【P->Q = !P或Q】这个式子果然很重要啊
//http://218.28.220.249:50015/JudgeOnline/problem.php?cid=1027&pid=5

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <stack>
#include <vector>
using namespace std;


int a, b, c;
bool OK;

int main(void)
{
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &a, &b, &c);
		if(a == 0 && b == 0 && c != 0){
			OK = true;
		}else if(a == 0 && b == 0 && c == 0){
			OK = false;//离散数学P->Q = !P或Q
		}else if(a == 0 && b != 0){
			if(c % b != 0){//Q
				OK = false;
			}else{
				OK = true;
			}
		}else if(a != 0){
			int temp = b*b - 4*a*c;
			if(temp < 0){//无解
				OK = true;
			}else{
				double top1 = -b + sqrt(temp);
				double top2 = -b - sqrt(temp);
				double base = 2*a;
				double n1 = top1 / base;
				double n2 = top2 / base;
				if((n1-(int)n1) == 0 && (n2-(int)n2) == 0){
					OK = true;
				}else{
					OK = false;
				}
			}
		}
		if(OK){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
