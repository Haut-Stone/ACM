<p align="center">
  <a href="http://shallweitalk.com">
	<img src="https://raw.githubusercontent.com/Haut-Stone/ACM/master/photos/me.png" width=220 height=220>
  </a>
  <h3 align="center">Stone</h3>
  <p align="center">
  <span style="color: #D96045">Write</span>
  <span style="color: #449AD8">The</span> 
  <span style="color: #64C271">Code,</span>
  <span style="color: #EDC233">Change</span>
  <span style="color: #449AD8">The</span>
  <span style="color: #D96045">World.</span>
	<br>
  </p>
</p>
<br>

## 题目

>[这里是题目哦](http://cxsjsxmooc.openjudge.cn/2017t2summerw3/2/)

## 题解

>[这里是题解哦](http://blog.csdn.net/kucece/article/details/46759235)
需要注意的是，这道题卡搜索的时间，我的代码是`超时`的，但是费了心思写下来的，还是觉得要留下来
下面的思路里面的代码是正确的解决方法。

另外这道题还可以用`完全背包🎒`做[背包解法](http://blog.csdn.net/qq_37785469/article/details/76377188)

## 思路

```cpp
int n;
int ans;

int dfs(int n, int k)
{
	if(n == 1 || k == 1){
		return 1;
	}else if(n < k){
		return dfs(n, n);
	}else if(n == k){
		return 1 + dfs(n, k-1);
	}else{
		return dfs(n - k, k) + dfs(n, k-1);
	}
}

int main(void)
{
	while(~scanf("%d", &n)){
		ans = dfs(n, n);
		printf("%d\n", ans);
	}
	return 0;
}
```

## 总结

	wait...... 