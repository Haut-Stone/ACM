/*      头文件: <algorithm>(需要using namespace std)
    包含函数:
	              sort      ------      对数组或结构体进行排序(快排--速度为nlogn)
				     参数: sort(待排序数组首地址, 待排序数组尾地址的后面一个地址[begin, end),指向函数的指针, 用于确定排序的顺序(comp))
				     应用举例:  sort(a+1, a+n+1, comp) 或 sort(a+1, a+n+1)(默认从小到大排序);

				  用于确定排序的顺序(comp)      ------      排序规则,若函数返回值为0,则前者应排在后者后面,返回值为1则相反(与qsort相反,但最好只用0和1)
				     参数: bool(或int) comp(int a, int b)(对什么类型的数据排序就用什么类型)
				     应用举例(对应上面的sort):    bool comp(int a, int b)
					                              {
												      return a<b;     (由小到大排序)
												  }
				  stable_sort      ------      对数组或结构体进行稳定排序(冒泡)
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef struct
{
	int k;
	char str[100];
}Node;

bool Comp(Node a, Node b)
{
	if(a.k>b.k || a.k==b.k && strcmp(a.str, b.str)>0)
		return 0;
	return 1;
}
int main(void)
{
	int n, i;
	Node s[105];
	scanf("%d", &n);
	for(i=1;i<=n;i++)
		scanf("%d%s", &s[i].k, s[i].str);
	stable_sort(s+1, s+n+1, Comp);     /*比较函数的名字可以自己定义*/
	for(i=1;i<=n;i++)
		printf("%d %s\n", s[i].k, s[i].str);   /*输出结果为从小到大*/
}
/* stable_sort和sort用法一模一样*/