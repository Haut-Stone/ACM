/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
*
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-06-03 12:15:58
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-10-17 19:31:54
*/

#include <iostream>
using namespace std;
#define MAX 100

const int N = 110;
const int INF = 0x3f3f3f3f;

int n;
char a[N];

int main(void)
{
	while(~scanf("%d %s", &n, a)){
		if(n == 1){
			printf("%d%d%d%d\n", a[0]-'a' + 1, a[1]-'a' + 1, a[2]-'a' + 1, a[3]-'a' + 1);
		}else if(n == 2){
			printf("%d%d%d%d\n", a[3]-'a' + 1, a[2]-'a' + 1, a[1]-'a' + 1, a[0]-'a' + 1);
		}else if(n == 3){
			printf("%d%d%d%d\n", a[2]-'a' + 1, a[3]-'a' + 1, a[0]-'a' + 1, a[1]-'a' + 1);
		}else if(n == 4){
			printf("%d%d%d%d\n", a[1]-'a' + 1, a[0]-'a' + 1, a[3]-'a' + 1, a[2]-'a' + 1);
		}
	}
	return 0;
}
