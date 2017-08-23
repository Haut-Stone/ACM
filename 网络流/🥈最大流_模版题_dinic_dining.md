<p align="center">
  <a href="http://shallweitalk.com">
    <img src="https://raw.githubusercontent.com/Haut-Stone/ACM/master/photos/me.png" width=220 height=220>
  </a>
  <h3 align="center">Stone</h3>

  <p align="center">
    <a href="http://shallweitalk.com">
      <img src="https://raw.githubusercontent.com/Haut-Stone/ACM/master/photos/CodeChangeWorld.png" width=300 height=40>
    </a>
  </p>
</p>
<br>


## 题目 & 题解

>[这里是题目哦](https://github.com/Haut-Stone)
>[这里是题解哦](https://github.com/Haut-Stone)

## 思路

### 分层的意义

在原来的方法中，寻找增广路时，会将不同的路径全部找一遍，这样的话其实过程中有的路径会被重复的寻找，但是在dinic中，每次寻找的都是最短的的增广路，这样的好处在于，当你把当前长度的增广路找完后，剩余的增广路长度，肯定是要大于现在的了，相当于取掉了一部分的情况吧。分层的意义就在于，通过把通向前一层的节点路径和通向筒层的节点路径去掉，保证每次的增广都是高效的。

## 总结

	wait...... 