/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-06-03 12:15:58
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-07-30 16:13:41
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

const int N = 50;

stack<int> val;
stack<char> op;
map<char, int> mapping;
char str[N];

void opNot(int a)
{
	while(!op.empty() && op.top() == '!'){
		op.pop();
		a = !a;
	}
	val.push(a);
}

int main(void)
{
	mapping['!'] = 3;
	mapping['&'] = 2;
	mapping['|'] = 1;
	int soloChar;
	int a, b, t = 0;
	while((soloChar = getchar()) && soloChar != EOF){
		t++;
		while(!val.empty()){
			val.pop();
		}
		while(!op.empty()){
			op.pop();
		}
		
		do{
			if(soloChar == ' '){
				continue;
			}
			if(soloChar == 'V'){
				a = 1;
				opNot(a);
			}else if(soloChar == 'F'){
				a = 0;
				opNot(a);
			}else if(soloChar == '('){
				op.push(soloChar);
			}else if(soloChar == ')'){
				while(op.top() != '('){
					a = val.top();
					val.pop();
					b = val.top();
					val.pop();
					if(op.top() == '|'){
						val.push(a|b);
					}else{
						val.push(a&b);
					}
					op.pop();
				}
				op.pop();
				while(!op.empty() && op.top() == '!'){
					a = val.top();
					val.pop();
					op.pop();
					val.push(!a);
				}
			}else{
				while(!op.empty() && op.top() != '(' && op.top() != '!' && mapping[soloChar] <= mapping[op.top()]){
					a = val.top();
					val.pop();
					b = val.top();
					val.pop();
					if(op.top() == '|'){
						val.push(a|b);
					}else{
						val.push(a&b);
					}
					op.pop();
				}
				op.push(soloChar);
			}
		}while((soloChar = getchar()) && (soloChar != EOF && soloChar != '\n'));
		while(!op.empty()){
			int soloOp = op.top();
			op.pop();
			a = val.top();
			val.pop();
			b = val.top();
			val.pop();
			if(soloOp == '|'){
				val.push(a|b);
			}else{
				val.push(a&b);
			}
		}
		if(val.top() == 1){
			soloChar = 'V';
		}else{
			soloChar = 'F';
		}
		printf("Expression %d: %c\n", t, soloChar);
	}
	return 0;
}