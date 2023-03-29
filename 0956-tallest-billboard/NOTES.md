lSubset -> Đại diện cho distance của subset bên left
rSubset -> Đại diện cho distance của subset bên right
​
{1, 2}, {3, 6}
​
Tập {1, 2} -|||||||||||||
​
4997 -> [], [1, 2]
5003 -> [1, 2], []
5000 -> [], []
​
Tập {3, 6} -|||||||||||||
​
[3], [6] -> 4997
[6], [3] -> 5003
5000 -> [], []