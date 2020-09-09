# getline
cin.getline 将istream输入读取到字符数组中，需要指定长度，遇到超长字符串会出错。

getline 将istream输入读取到string对象中，可以读取超长字符串，遇到换行符停止，且丢弃换行符。