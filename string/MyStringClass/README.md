# 自己实现一个String类

这是在C++面试中撸代码时很有可能被问到的一个题，通过面试者自己实现一个String类能多方面考察面试者的C++基础功底能力

实现一个类一般需要设计以下方法：
* **直接构造函数**
    ``` c++
    String(const char *ch = NULL);
    ```
* **赋值构造函数** 
    ``` c++
    String(const String &other);
    ```
    Tips: 赋值构造函数需要注意将参数设置为const String&, 如果不传入引用， 会引起无限循环 <br/> <br/>
* **拷贝构造函数**
    ```c++ 
    String & operator=(const String &other);
    ```
    Tips: 拷贝构造函数应该返回的是引用类型 <br><br>
* **析构函数**
* **重载[ ]符号**
    ``` c++
    char & operator[](int n);
    const char & operator[](int n) const;
    ```
* **重载==符号**
    ``` c++
    bool operator==(const String &other) const;
    ```
* **重载+符号**
    ``` c++
    String operator+(const String &str1);
    ```
* **重载<<符号**
    ``` c++
    friend std::ostream & operator<<(std::ostream& out, const String& str );
    // 注意：<< 和 >>符号的重载不能声明为成员函数，一般声明为友元函数
    ```
* **重载>>符号**
    ``` c++
    friend std::istream & operator>>(std::istream& in, const String& str );
    ```
