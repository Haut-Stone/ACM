/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: li
* @Date:   2017-07-27 19:24:51
* @Last Modified by:   li
* @Last Modified time: 2017-07-27 19:26:12
*/

//显示程序运行时间的小工具
//

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


int main(void)
{
	auto start = clock();
	/*
	
	中间是主流程

	 */
    cout << (clock() - start) / (double)CLOCKS_PER_SEC;
	return 0;
}