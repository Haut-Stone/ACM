/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-09-22 19:10:57
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-09-22 19:24:51
*/

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


//多校脸萌的题，话说这题在处理字符串方面很厉害啊。
//http://112.74.53.124/contest.php?cid=1006

const int N = 1100;

char str[N];
int start;

//这个操作缺失挺骚的
int val()
{
	int v, n;
	switch(str[start]){
		case 'm':{
			start += 3;
			if(str[start-2] == 'i'){
				return min(val(), val());
			}else{
				return max(val(), val());
			}
		}
		case 'a':{
			start += 3;
			return val() + val();
		}
		case ')':
		case '(':
		case ',':{
			start++;
			return val();
		}
		default:{
			sscanf(str+start, "%d%n", &v, &n);//这里的%n代表已经读入的字符数，帮了大忙了呢。important!
			start += n;
			return v;
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	while(n--){
		scanf("%s", str);
		start = 0;
		printf("%d\n", val());
	}
}