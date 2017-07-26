/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-04-25 13:58:12
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-04-25 16:30:47
*/

//字符串匹配方面的水题
//在学校机房的电脑上写的，所以代码风格不太一样，为了熟悉codeblock.

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

const int N = 11000;
char dic[N][20];
char solo[30];
int cnt;

void readDic()
{
    cnt = 0;
    while(scanf("%s", dic[cnt]))
    {
        if(dic[cnt][0] == '#')
        {
            break;
        }else
        {
            cnt++;
        }
    }
}

void replace()
{
    printf("%s:", solo);
    int lenA = strlen(solo);
    int book[30];
    for(int i=0;i<cnt;i++)
    {
        int lenB = strlen(dic[i]);
        if(lenA == lenB)
        {
            int temp  = 0;
            for(int j=0;j<lenA;j++)
            {
                if(solo[j] != dic[i][j]) temp++;
            }
            if(temp == 1)
            {
                printf(" %s", dic[i]);
            }
        }else if(lenA == lenB + 1)
        {
            memset(book, -1, sizeof(book));
            int posA = 0;
            int posB = 0;
            int dif = 0;
            while(posA < lenA && posA < lenA)
            {
                if(solo[posA] == dic[i][posB])
                {
                    posA++;
                    posB++;
                }else
                {
                    posA++;
                    dif++;
                }
            }
            if(dif == 1 || dif == 0)
            {
                printf(" %s", dic[i]);
            }
        }else if(lenA == lenB - 1)
        {
            memset(book, -1, sizeof(book));
            int posA = 0;
            int posB = 0;
            int dif = 0;
            while(posB < lenB && posA < lenA)
            {
                if(solo[posA] == dic[i][posB])
                {
                    posA++;
                    posB++;
                }else
                {
                    posB++;
                    dif++;
                }
            }
            if(dif == 1 || dif == 0)
            {
                printf(" %s", dic[i]);
            }
        }
    }
}

bool isCorrect()
{
    for(int i=0;i<cnt;i++)
    {
        if(strcmp(solo, dic[i]) == 0)
        {
            return true;
        }
    }
    return false;
}

int main(void)
{
	// INPUT_TEST;
    readDic();

    while(scanf("%s", solo), solo[0] != '#')
    {
        if(isCorrect())
        {
            printf("%s is correct\n", solo);
        }else
        {
            replace();
            printf("\n");
        }
    }
    return 0;
}
