/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-05-12 21:49:18
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-05-12 21:52:08
*/

//http://acm.ecnu.edu.cn/contest/11/problem/A/
//恶心，我也很绝望啊🤢。

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

const int N = 2000;
char str[N];

char iMap[N] = {'a','o','e','i','u','v'};//顺序写错了。。。这。。。。

int main(void)
{
	// INPUT_TEST;
	int T;
	int cas = 1;
	cin>>T;
	while(T--){
		scanf("%s", str);
		int len = strlen(str);
		if(!isdigit(str[len-1])){
			printf("Case %d: ", cas);
			for(int i=0;i<len;i++){
				if(str[i] == 'v'){
					if(str[i+1] != 'e'){
						printf("ü");
					}else{
						printf("u");
					}
				}else{
					printf("%c", str[i]);
				}
			}
			cas++;
			printf("\n");
		}else{
			int x = 0;
			int y = 0;
			int book = 0;
			printf("Case %d: ", cas);
			int flag = str[len - 1] - '0';//加的音调种类
			str[len - 1] = '\0';
			for(int i=0;i<6;i++){
				for(int j=0;j<len;j++){
					if(str[j] == iMap[i]){
						x = j;//被改变的字符的位置
						y = i;//被改变的字符种类
						book = 1;
						break;
					}
				}
				if(book){
					break;
				}
			}

			if(str[x] == 'i' && str[x+1] == 'u'){
				x++;
				y++;
			}

			for(int i=0;i<len-1;i++){
				if(i != x){
					if(str[i] == 'v'){
						if(str[i+1] == 'e'){
							printf("u");
						}else{
							printf("ü");
						}
					}else{
						printf("%c", str[i]);
					}
				}else{
					if(y == 0){
						switch(flag){
							case 1:printf("ā");break;
							case 2:printf("á");break;
							case 3:printf("ǎ");break;
							case 4:printf("à");break;
							default:break;
						}
					}else if(y == 1){
						switch(flag){
							case 1:printf("ō");break;
							case 2:printf("ó");break;
							case 3:printf("ǒ");break;
							case 4:printf("ò");break;
							default:break;
						}
					}else if(y == 2){
						switch(flag){
							case 1:printf("ē");break;
							case 2:printf("é");break;
							case 3:printf("ě");break;
							case 4:printf("è");break;
							default:break;
						}
					}else if(y == 3){
						switch(flag){
							case 1:printf("ī");break;
							case 2:printf("í");break;
							case 3:printf("ǐ");break;
							case 4:printf("ì");break;
							default:break;
						}
					}else if(y == 4){
						switch(flag){
							case 1:printf("ū");break;
							case 2:printf("ú");break;
							case 3:printf("ǔ");break;
							case 4:printf("ù");break;
							default:break;
						}
					}else if(y == 5){
						switch(flag){
							case 1:printf("ǖ");break;
							case 2:printf("ǘ");break;
							case 3:printf("ǚ");break;
							case 4:printf("ǜ");break;
							default:break;
						}
					}
				}
			}
			cas++;
			printf("\n");
		}
	}
	return 0;
}