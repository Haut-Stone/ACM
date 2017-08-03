/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-06-03 12:15:58
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-08-02 14:08:21
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

const int N = 1000100;
const int ALPHABET_SIZE = 26;

struct Node
{
	int count;
	Node* fail;
	Node* children[ALPHABET_SIZE];
	Node(){
		count = 0;
		fail = NULL;
		for(int i=0;i<ALPHABET_SIZE;i++){
			children[i] = NULL;
		}
	}
};

Node* root;

void insert(char pattern[])
{
	Node* current;
	Node* temp;
	
	current = root;
	for(int i=0;i<strlen(pattern);i++){
		int tempChar = pattern[i] - 'a';
		if(current->children[tempChar] != NULL){
			current = current->children[tempChar];
		}else{
			temp = new Node;
			current->children[tempChar] = temp;
			current = current->children[tempChar];
		}
	}
	(current->count)++;
}

void initFailPointer()
{
	Node* current;
	Node* son;
	Node* father;
	queue<Node* > Q;
	
	current = root;
	Q.push(current);
	
	while(!Q.empty()){
		father = Q.front();
		Q.pop();
		
		for(int i=0;i<ALPHABET_SIZE;i++){
			son = father->children[i];
			if(son != NULL){
				if(father == root){
					son->fail = root;
				}else{
					current = father->fail;
					while(current){
						if(current->children[i]){
							son->fail = current->children[i];
							break;
						}
						current = current->fail;
					}
					if(!current) son->fail = root;
				}
				Q.push(son);
			}
		}
	}
}

int query(char text[])
{
	Node* current;
	Node* temp;
	int cnt = 0;
	int textLen = (int)strlen(text);
	current = root;
	for(int i=0;i<textLen;i++){
		int tempChar = text[i] - 'a';
		while(!current->children[tempChar] && current != root){
			current = current->fail;
		}
		current = current->children[tempChar];
		if(current == NULL) current = root;
		temp = current;
		while(temp != root){
			if(temp->count >= 0){
				cnt += temp->count;
				temp->count = -1;
			}else{
				break;
			}
			temp = temp->fail;
		}
	}
	return cnt;
}

int main(void)
{
	int T;
	int n;
	char patterns[N];
	char text[N];
	
	scanf("%d", &T);
	for(int cas=1;cas<=T;cas++){
		root = new Node;
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%s", patterns);
			insert(patterns);
		}
		initFailPointer();
		scanf("%s", text);
		int ans = query(text);
		printf("%d\n", ans);
	}
	return 0;
}