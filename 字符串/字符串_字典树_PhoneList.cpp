/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-02 15:38:22
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-02 21:16:45
*/

//HDU 1671
//字典树的基础题，主要是加上判断，坑的是居然还要自己删内存 = =

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

const int N = 110;
const int NUMBER_SIZE = 10;
int ans;

struct Node
{
	int count;
	int isLast;
	Node* children[NUMBER_SIZE];
	Node(){
		count = 0;
		isLast = 0;
		for(int i=0;i<NUMBER_SIZE;i++){
			children[i] = NULL;
		}
	}
};

Node* root;

void insert(char str[])
{
	Node* current = root;
	int len = (int)strlen(str);
	for(int i=0;i<len;i++){
		int number = str[i] - '0';
		if(current->children[number] == NULL){
			current->children[number] = new Node;
			current = current->children[number];
			(current->count)++;
		}else{
			if(current->children[number]->isLast > 0){
				ans = 1;
				return;
			}
			current = current->children[number];
			(current->count)++;
		}
	}
	(current->isLast)++;
	if(current->count > 1){
		ans = 1;
	}
}

void del(Node* root)
{
	for(int i=0;i<NUMBER_SIZE;i++){
		if(root->children[i] != NULL){
			del(root->children[i]);
		}
	}
	free(root);
}

int main(void)
{
	int T;
	int n;
	char str[N];
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		root = new Node;
		for(int i=0;i<n;i++){
			scanf("%s", str);
			if(ans == 0) insert(str);
		}
		if(ans){
			printf("NO\n");
		}else{
			printf("YES\n");
		}
		ans = 0;
		del(root);
	}
	return 0;
}