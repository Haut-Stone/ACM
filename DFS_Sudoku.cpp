9b/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: li
* @Date:   2017-03-05 18:53:57
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-07-24 11:18:40
*/

//http://vj.sdutacm.org/contest/view.action?cid=62898#problem/E

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

#define INPUT_TEST freopen("in.txt", "r", stdin)

const int N = 40;
char rawMap[N][N];
int Imap[N][N];
int rowBook[N][N];
int colBook[N][N];
int latticeBook[N][N];
bool flag;

void dfs(int row, int col)
{
    if(row == 9 && col == 0){//如果可以搜到最后一个的之后一个...输出
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                printf("%d", Imap[i][j]);
            }
            printf("\n");
        }
        flag = true;//更改状态为可完成。
    }else{
        if(Imap[row][col] != 0){//如果之前这个位置有数字
            if(col<=7){//如果没有到达最后一列
                dfs(row, col+1);//向右搜索
            }else{
                dfs(row+1, 0);//搜索下一行
            }i
        }else{//如果之前这个位置是空的
            for(int i=1;i<=9;i++){//搜索都有哪些可用数字（从1->9遍历）
                if(rowBook[row][i] == 0 && colBook[col][i] == 0 && latticeBook[row/3*3+col/3][i] == 0){//根据i,j标定它所属的行，列，和所在的小矩阵,如果这个数字从未出现过。
                    int s = row/3*3+col/3;//这里是判断数独的关键！！！！
                    Imap[row][col] = i;//填入数字
                    rowBook[row][i] = 1;//改变标记状态为已出现。
                    colBook[col][i] = 1;
                    ilatticeBook[s][i] = 1;
                    if(col<=7){
                        dfs(row, col+1);
                    }else{
                        dfs(row+1, 0);
                    }
                    if(flag) return;
                    Imap[row][col] = 0;//一旦回溯过来，必须重新置0，因为说明此数字对于后面的搜索产生了不满足，故将其置0.
                    rowBook[row][i] = 0;
                    colBook[col][i] = 0;
                    latticeBook[s][i] = 0;
                }
            }
        }
    }
}


int main(void)
{
    INPUT_TEST;

    int T;
    cin>>T;
    while(T--){

        memset(rowBook, 0, sizeof(rowBook));
        memset(colBook, 0, sizeof(colBook));
        memset(latticeBook, 0, sizeof(latticeBook));//reset

        for(int i=0;i<9;i++){
            scanf("%s", rawMap[i]);//更高效率的读入字符地图
        }
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                Imap[i][j] = rawMap[i][j] - '0';//将原始地图转为数字地图 
                int s = Imap[i][j];
                if(s!=0){
                    rowBook[i][s] = 1;//将已经被使用过的数字进行标记
                    colBook[j][s] = 1;
                    latticeBook[i/3*3+j/3][s] = 1;//初始，一旦有数字，则要将它所在的行列及小矩阵标为1
                }
            }
        }
        flag = false;//用来指示是否可以按要求补全数独。
        dfs(0,0);//从第一个数字位置开始搜索。
    }
    return 0;
}