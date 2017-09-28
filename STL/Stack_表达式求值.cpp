/*
* Created by ShiJiahuan(li) in haut.
* For more please visit www.shallweitalk.com.
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-09-28 18:28:15
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-09-28 18:29:49
*/

//去你妈的这道题，阅读理解，只有单个数字比如：
//   999
//   这种也是输入样例，因为一个数字本身就可以是一个表达式。

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <stack>
#include <vector>
using namespace std;

const int N = 4000;
stack<int> operatorStack;
stack<int> numberStack;
bool negative = false;

int solve(char str[N])
{
	int len = (int)strlen(str);
	int flag = 0;
	while(!operatorStack.empty()){
		operatorStack.pop();
	}
	while (!numberStack.empty()) {
		numberStack.pop();
	}
	while(flag < len){
		if(str[flag] == 'a'){
			flag += 4;
			operatorStack.push(1);
		}else if(str[flag] == 'm'){
			flag++;
			if(str[flag] == 'i'){
				flag += 3;
				operatorStack.push(3);
			}else{
				flag += 3;
				operatorStack.push(2);
			}
		}else if(isdigit(str[flag])){
			int number = 0;
			while(str[flag] != ',' && str[flag] != ')'){
				number += str[flag] - '0';
				number *= 10;
				flag++;
			}
			if(negative){
				numberStack.push(-(number/10));
				negative = false;
			}else{
				numberStack.push(number/10);
			}
			if(str[flag] == ',') flag++;
		}else if(str[flag] == ')'){
			int a = numberStack.top();
			numberStack.pop();
			int b = numberStack.top();
			numberStack.pop();
			int op = operatorStack.top();
			operatorStack.pop();
			if(op == 1){
				numberStack.push(a+b);
			}else if(op == 2){
				numberStack.push(max(a, b));
			}else if(op == 3){
				numberStack.push(min(a, b));
			}
			flag++;
		}else if(str[flag] == '-'){
			negative = true;
			flag++;
		}else{
			flag++;
		}
	}
	return numberStack.top();
}

int main(void)
{
	int n;
	scanf("%d", &n);
	for(int k=0;k<n;k++){
		char rawString[N];
		scanf("%s", rawString);
		if(isdigit(rawString[0])){
			int ans = 0;
			int flag = 0;
			while(flag < strlen(rawString)){
				ans += rawString[flag] - '0';
				flag++;
				ans *= 10;
			}
			printf("%d\n", ans/10);
		}else{
			int ans = solve(rawString);
			printf("%d\n", ans);
		}
	}
	return 0;
}
