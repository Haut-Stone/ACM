/*
 * Created by ShiJiahuan(li) in haut.
 * for more please visit www.shallweitalk.com
 *
 * Copyright 2017 SJH. All rights reserved.
 *
 * @Author: Haut-Stone
 * @Date:   2017-01-22 11:12:17
 * @Last Modified by:   Haut-Stone
 * @Last Modified time: 2017-08-04 14:18:51
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

const int N = 110;
const int DNA_SIZE = 4;
const int INF = 99999999;
int dp[N][N];//表示到达查找串第i个字符时，对应于AC自动机的j节点所需要的最小改变数。

struct Node
{
	int id;
	Node* fail;
	Node* children[DNA_SIZE];
	Node(){
		id = 0;
		fail = NULL;
		for(int i=0;i<DNA_SIZE;i++){
			children[i] = NULL;
		}
	}
}*root;

map<char, int> mapping;
int total;

void insert(char pattern[], int id)
{
	Node* current = root;
	int len = (int)strlen(pattern);
	for(int i=0;i<len;i++){
		int pos = mapping[pattern[i]];
		if(current->children[pos] == NULL){
			current->children[pos] = new Node;
			total++;
		}
		current = current->children[pos];
	}
	current->id = id;
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
		for(int i=0;i<DNA_SIZE;i++){
			son = father->children[i];
			if(son != NULL){
				if(father == root){
					son->fail = root;
				}else{
					fatherFail = father->fail;
					son->fail = fatherFail->children[i];
					if(son->fail->id != 0){
						son->id = son->fail->id;
					}
				}
				Q.push(son);
			}else{
				if(father == root){
					son = root;
				}else{
					son = father->fail->children[i];
				}
			}
		}
	}
}

int query(char text[])
{
	Node* temp;
	int len = strlen(text);
	for(int i=0;i<=len;i++){
		for(int j=0;j<total;j++){
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	for(int i=1;i<=len;i++){
		for(int j=0;j<total;j++){
			if(dp[i-1][j] < INF){
				for(int k=0;k<DNA_SIZE;k++){
					if()
				}
			}
		}
	}
	return 0;
}

int main(void)
{
	int n;
	int cas = 1;
	char patterns[N];
	char text[N];
	mapping['A'] = 0;
	mapping['C'] = 1;
	mapping['G'] = 2;
	mapping['T'] = 3;
	while(~scanf("%d", &n) && n!=0){
		root = new Node;
		total = 0;
		for(int i=1;i<=n;i++){
			scanf("%s", patterns);
			insert(patterns, i);
		}
		initFailPointer();
		scanf("%s", text);
		int ans = query(text);
		printf("Case %d: %d\n", cas, ans);
	}
	return 0;
}