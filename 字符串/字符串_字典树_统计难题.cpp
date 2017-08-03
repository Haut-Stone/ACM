/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-02 11:07:07
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-02 11:07:47
*/

//HDU 1251
//字典树的板子题

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

const int N = 10010;
const int ALPHABET_SIZE = 26;

struct Node
{
	int count;
	Node* children[ALPHABET_SIZE];
	Node(){
		count = 0;
		for(int i=0;i<ALPHABET_SIZE;i++){
			children[i] = NULL;
		}
	}
};

Node* root = new Node;
Node* current;
Node* newNode;

void insert(char str[])
{
	current = root;
	for(int i=0;i<strlen(str);i++){
		int tempChar = str[i] - 'a';
		if(current->children[tempChar] != NULL){
			current = current->children[tempChar];
			(current->count)++;
		}else{
			newNode = new Node;
			(newNode->count)++;
			current->children[tempChar] = newNode;
			current = newNode;
		}
	}
}

int query(char sbuStr[])
{
	current = root;
	for(int i=0;i<strlen(sbuStr);i++){
		int tempChar = sbuStr[i] - 'a';
		if(current->children[tempChar] == NULL){
			return 0;
		}
		current = current->children[tempChar];
	}
	return current->count;
}

int main(void)
{
	char str[N];
	char subStr[N];
	
	while(gets(str)){
		if(str[0] == '\n' || str[0] == '\0') break;
		insert(str);
	}
	while(gets(subStr) != NULL){
		int ans = query(subStr);
		printf("%d\n", ans);
	}
	return 0;
}