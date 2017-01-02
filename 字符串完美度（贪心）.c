/*
约翰认为字符串的完美度等于它里面所有字母的完美度之和。每个字母的完美度可以由你来分配，不同字母的完美度不同，分别对应一个1-26之间的整数。

约翰不在乎字母大小写。（也就是说字母F和f）的完美度相同。给定一个字符串，输出它的最大可能的完美度。例如：dad，你可以将26分配给d，25分配给a，这样整个字符串完美度为77。

分析： 由排序不等式，出现次数最多的字母显然应该给26。所以这个题目变成了统计每种字母出现的次数了，然后按照出现次数从大到小，依次分配从高到低的权值。这就是最朴素的贪心思想。
最后，我们来提供输入输出数据，由你来写一段程序，实现这个算法，只有写出了正确的程序，才能继续后面的课程。

输入

输入一个字符串S(S的长度 <= 10000)，S中没有除字母外的其他字符。

输出

由你将1-26分配给不同的字母，使得字符串S的完美度最大，输出这个完美度。

输入示例

dad

输出示例

77

请选取你熟悉的语言，并在下面的代码框中完成你的程序，注意数据范围，最终结果会造成Int32溢出，这样会输出错误的答案。
不同语言如何处理输入输出，请查看下面的语言说明。
 */
//
//  main.c
//  贪心练习1
//
//  Created by Jack Lee on 2016/11/29.
//  Copyright © 2016年 SJH. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
	char line[10010];
	int a[27] = {0};
	long long product = 0;
	int maxNumber;
	int maxPosition;
	scanf("%s", line);
	int temp = 26;

	for(int i=0;i<strlen(line);i++){
		if(isupper(line[i])) line[i] = tolower(line[i]);
		a[line[i] - 96]++;
	}

	for(int i=1;i<27;i++){
		maxNumber = 0;
		for(int j=1;j<27;j++){
			if(a[j] > maxNumber){
				maxNumber = a[j];
				maxPosition = j;
			}
		}
		product += temp * a[maxPosition];
		temp--;
		a[maxPosition] = 0;
	}
	printf("%lld\n", product);
	return 0;
}