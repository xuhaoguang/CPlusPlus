# 自己实现一个String类

这是在C++面试中撸代码时很有可能被问到的一个题，通过面试者自己实现一个String类能多方面考察面试者的C++基础功底能力

实现一个类一般需要设计以下方法：
* **直接构造函数 
  > String(const char *ch = NULL);
* 赋值构造函数
  > String(const String &other);
* 析构函数
