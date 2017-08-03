/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-02 09:26:05
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-02 09:26:36
*/

//HDU 3068
//马拉车的一道模版题

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

const int N = 300010;
char newString[N<<1];
char text[N];
int book[N];

void init(char text[], int len1)
{
    newString[0] = '$';
    newString[1] = '#';
    for(int i=0;i<len1;i++){
        newString[(i+1)*2] = text[i];
        newString[(i+1)*2+1] = '#';
    }
    newString[(len1+1)*2] = '*';
    newString[(len1+1)*2+1] = '\0';
}

int manachr(char text[], int len1)
{
    init(text, len1);
    int lastPos = 0;
    int ans = 0;
    int id = 0;
    int len2 = (int)strlen(newString);
    for(int i=1;i<len2;i++){
        if(lastPos > i){
            book[i] = min(book[2*id - i], lastPos - i);
        }else{
            book[i] = 1;
        }
        while(newString[i+book[i]] == newString[i-book[i]]){
            book[i]++;
        }
        if(book[i]+i > lastPos){
            lastPos = book[i] + i;
            id = i;
        }
    }
    
    for(int i=0;i<len2;i++){
        ans = max(ans, book[i]);
    }
    return ans - 1;
}

int main(void)
{
    while(~scanf("%s", text)){
        int len1 = (int)strlen(text);
        int ans = manachr(text, len1);
        printf("%d\n", ans);
    }
    return 0;
}