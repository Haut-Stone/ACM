/*      头文件: <algorithm>(需要using namespace std)
    包含函数:
	              max_element      ------      找出(数组)区间最大值
				  min_element      ------	   找出(数组)区间最小值
						参数: max_element(待排序数组首地址, 待排序数组尾地址的后面一个地址[begin, end).)
				  max      ------      找出两个数中的最大值(必须同类型,下同)
				  min      ------      找出两个数中的最小值
				    	参数: max(第一个数, 第二个数)
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(void)
{
	int d, e;
	int a[11] = {0,1,4,5,3,9,-2,11,5,12,15};
	d = *max_element(a, a+10);//这个地方让我再查一下dash
	e = min(a[4], a[5]);
	printf("%d %d\n", d, e);
	return 0;
}
