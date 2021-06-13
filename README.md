# tinyCG-轻量级的计算几何算法库

## 概述
已经有像CGAL这样鼎鼎大名的几何算法库了，但是我在实际使用中使用的很少。第一个原因是CGAL使用了非常多的C++高级特性，钻研代码是比较困难的；第二个是感觉CGAL还是很重量级的，如果不清楚其中的具体原理，调用起来如果哪里存在问题也是不清楚的；第三个是二三维的图形算法往往需要根据实际的使用场景去定制，才能保证比较好的效率。基于这三个原因，还是准备自己总结一些经常使用的计算几何算法。

CGAL主要是一些类似构建三角网的高端算法，同时还能保证高效率；几何图形之间的拓扑关系，我认为GDAL的OGR组件也非常优秀。我这里主要准备实现一些简单的、常用的二三维计算几何算法，如果有机会，会向前两个库学习。

## 内容
矢量计算

二维图形算法：

1. [已知线段上某点与起点的距离，求该点的坐标](https://blog.csdn.net/charlee44/article/details/104661723)

三维图形算法：
1. [空间点与直线距离算法](https://blog.csdn.net/charlee44/article/details/116352037)

平面矩形：
1. 矩形相交

空间三角形：
1. [已知三点求平面法向量](https://blog.csdn.net/charlee44/article/details/89429243)
2. [已知空间三点组成的面求该面上某点的Z值](https://blog.csdn.net/charlee44/article/details/103739140)
3. [平面中判断点在三角形内算法(同向法)](https://blog.csdn.net/charlee44/article/details/117601564)
4. [空间中判断点在三角形内算法(方程法)](https://blog.csdn.net/charlee44/article/details/117629956)
5. [平面中判断点在三角形内算法(重心法)](https://blog.csdn.net/charlee44/article/details/117855136)
