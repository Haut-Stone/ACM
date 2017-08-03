/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-02 21:05:22
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-02 21:07:54
*/

//HDU 2896
//这题的重点在于，要去匹配多个字符串，所以就不能记录为-1了，这里就给一个特殊的id号就好了
//md这题， 卡内存卡到怀疑人生，最后好不容易解决了，居然TM最后输出还要排个序。mmp垃圾。

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

const int N = 10050;
const int ALPHABET_SIZE = 128;

struct Node
{
	Node* children[ALPHABET_SIZE];
	Node* fail;
	int id;
	int flag;
	Node(){
		id = 0;
		flag = 0;
		fail = NULL;
		for(int i=0;i<ALPHABET_SIZE;i++){
			children[i] = NULL;
		}
	}
};

Node* root;
int out[300];

void insert(char pattern[], int id)
{
	Node* current = root;
	int len = (int)strlen(pattern);
	for(int i=0;i<len;i++){
		int pos = pattern[i];
		if(current->children[pos] == NULL){
			current->children[pos] = new Node;
		}
		current = current->children[pos];
	}
	current->id = id;//给每一个匹配串结尾分配id
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
				}else{
					fatherFail = father->fail;
					while(fatherFail != NULL){
						if(fatherFail->children[i] != NULL){
							son->fail = fatherFail->children[i];
							break;
						}
						fatherFail = fatherFail->fail;
					}
					if(fatherFail == NULL){
						son->fail = root;
					}
				}
				Q.push(son);
			}
		}
	}
}

int query(char text[], int book)
{
	Node* current;
	Node* temp;
	int haveSubString = 0;
	int textLen = (int)strlen(text);
	current = root;
	
	for(int i=0;i<textLen;i++){
		int pos = text[i];
		while(current->children[pos] == NULL && current != root){
			current = current->fail;
		}
		current = current->children[pos];
		if(current == NULL) current = root;
		temp = current;
		while(temp != root){
			if(haveSubString >= 3) break;
			if(temp->flag != book && temp->id > 0){
				out[haveSubString++] = temp->id;
				temp->flag = book;
			}else{
				break;
			}
			temp = temp->fail;
		}
		if(haveSubString >= 3) break;
	}
	return haveSubString;
}


int main(void)
{
	int n, m;
	char patterns[300];
	char text[N];
	int total;
	while(~scanf("%d", &n)){
		root = new Node;
		total = 0;
		for(int i=1;i<=n;i++){
			scanf("%s", patterns);
			insert(patterns, i);
		}
		initFailPointer();
		scanf("%d", &m);
		for(int i=1;i<=m;i++){
			scanf("%s", text);
			int ans = query(text, i);
			if(ans > 0){
				sort(out, out+ans);
				printf("web %d:", i);
				for(int j=0;j<ans;j++){
					printf(" %d", out[j]);
				}
				total++;
				printf("\n");
			}
		}
		printf("total: %d\n", total);
	}
	return 0;
}