/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-28 17:03:40
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-28 17:04:54
*/

//PAT A 1020 Tree Traversals
//给后序和中序遍历，建树并求其层序遍历

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

const int N = 100;

struct Node
{
	int value;
	Node* leftChild;
	Node* rightChild;
};

int pre[N];//先序遍历序列
int in[N];//中序遍历序列
int post[N];//后序遍历序列
int nodeNumer;
int num = 0;//已输出的节点数

void read()
{
	
	cin>>nodeNumer;
	for(int i=0;i<nodeNumer;i++){
		scanf("%d", &post[i]);
	}
	for(int i=0;i<nodeNumer;i++){
		scanf("%d", &in[i]);
	}
}

//致敬Re:Creater
Node* ReCreater(int postL, int postR, int inL, int inR)
{
	if(postL > postR){
		return NULL;
	}

	Node* root = new Node;
	root->value = post[postR];

	int temp;
	for(temp = 0;temp < nodeNumer;temp++){
		if(in[temp] == post[postR]){
			break;
		}
	}

	int numLeft = temp - inL;//左子树上的节点数

	root->rightChild = ReCreater(postL + numLeft, postR-1, temp + 1, inR);
	root->leftChild = ReCreater(postL, postL + numLeft - 1, inL, temp - 1);
	return root;
}

void bfs(Node* root)
{
	queue<Node* > Q;
	Q.push(root);
	while(!Q.empty()){
		Node* solo = Q.front();
		Q.pop();
		printf("%d", solo->value);
		num++;
		if(num < nodeNumer) printf(" ");
		if(solo->leftChild != NULL) Q.push(solo->leftChild);
		if(solo->rightChild != NULL) Q.push(solo->rightChild);
	}
}

int main(void)
{
	// INPUT_TEST;
	read();
	Node* root = ReCreater(0, nodeNumer-1, 0, nodeNumer-1);
	bfs(root);
	return 0;
}