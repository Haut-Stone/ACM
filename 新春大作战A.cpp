/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-01-27 22:44:29
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-01-27 23:30:20
*/
//题意：
//今天是周三，这周的第三天，明天是2015的最后一天。
//-->2015的最后一天是周四
//Limak想证明她是一个熊，他要为2016攒糖果。
//可以按月存。也可以按周存
//可以选择一种计划
//Input：
//按周的存法or按月的存法
/*
2016每周数据：
all...42
1...10
2...10
3...10
4...10
5...11
6...11
7...10
 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
using namespace std;


int main(void)
{
	int solo;
	string str;
	scanf("%d", &solo);
	cin>>str;
	cin>>str;
	if(str == "week"){
		switch(solo){
			case 7:
			case 1:
			case 2:
			case 3:
			case 4:printf("52\n");break;
			case 5:       
			case 6:printf("53\n");break;
			default:break;
		}
	}else if(str == "month"){
		switch(solo){
			case 30:printf("11\n");break;
			case 31:printf("7\n");break;
			default:printf("12\n");break;
		}
	}
    return 0;
}