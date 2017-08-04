/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-03 09:29:43
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-03 11:51:06
*/

//HDU 3065
//有了上一题的铺垫这道题就变的简单了很多了，一发入魂.

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

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;

const int N = 1010;
const int M = 2000010;
const int ALPHABET_SIZE = 26;

struct Node
{
	// int id;
	int isLast;
	Node* fail;
	Node* children[ALPHABET_SIZE];
	Node(){
		// id = 0;
		isLast = 0;
		fail = NULL;
		for(int i=0;i<ALPHABET_SIZE;i++){
			children[i] = NULL;
		}
	}
};

Node* root;
int out[N];
// int idNumber = 1;

void insert(char pattern[], int id)
{
	Node* current;
	Node* temp;
	int len = (int)strlen(pattern);
	current = root;
	for(int i=0;i<len;i++){
		int tempChar = pattern[i] - 'A';
		if(current->children[tempChar] == NULL){
			temp = new Node;
			current->children[tempChar] = temp;
			current = current->children[tempChar];
			// current->id = idNumber++;
		}else{
			current = current->children[tempChar];
		}
	}
	current->isLast = id;
}


void initFailPointer()
{
	Node* fatherFail;
	Node* father;
	Node* son;
	
	queue<Node* > Q;
	
	fatherFail = root;
	Q.push(fatherFail);
	
	while(!Q.empty()){
		father = Q.front();
		Q.pop();
		for(int i=0;i<ALPHABET_SIZE;i++){
			son = father->children[i];
			if(son != NULL){
				if(father == root){
					son->fail = root;
					// printf("%d---->root\n", son->id);
				}else{
					fatherFail = father->fail;
					while(fatherFail != NULL){
						if(fatherFail->children[i] != NULL){
							son->fail = fatherFail->children[i];
							// printf("%d---->%d\n", son->id, fatherFail->children[i]->id);
							break;
						}
						fatherFail = fatherFail->fail;
					}
					if(fatherFail == NULL){
						son->fail = root;
						// printf("%d---->root\n", son->id);
					}
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
	int numberOfPatternsInText = 0;
	int textLen = (int)strlen(text);
	current = root;
	
	for(int i=0;i<textLen;i++){
		int tempChar = text[i] - 'A';
		if(tempChar < 0 || tempChar > 25){
			current = root;
			continue;
		}
		while(current->children[tempChar] == NULL && current != root){
			current = current->fail;
		}
		current = current->children[tempChar];
		if(current == NULL) current = root;
		temp = current;
		while(temp != root){
			if(temp->isLast > 0){
				out[temp->isLast]++;
				numberOfPatternsInText++;
			}
			temp = temp->fail;
		}
	}
	return numberOfPatternsInText;
}


void del(Node* root)
{
	for(int i=0;i<ALPHABET_SIZE;i++){
		if(root->children[i] != NULL){
			del(root->children[i]);
		}
	}
	free(root);
}

int main(void)
{
	int n;
	char patterns[N][N];
	char text[M];
	while(~scanf("%d", &n)){
		root = new Node;
		for(int i=1;i<=n;i++){
			scanf("%s", patterns[i]);
			insert(patterns[i], i);
		}
		initFailPointer();
		scanf("%s", text);
		query(text);
//		printf("%d\n", ans);
		for(int i=1;i<=N;i++){
			if(out[i] != 0){
				printf("%s: %d\n", patterns[i], out[i]);
				out[i] = 0;
			}
		}
		del(root);
	}
	return 0;
}