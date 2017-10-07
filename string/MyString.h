/*
 * File Name: MyString.h
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Sat Oct  7 15:21:23 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: head file for MyString 
*/

#ifndef  _SICT_MYSTRING_CLASS
#define  _SICT_MYSTRING_CLASS

#include <iostream>
#include <string.h>

class String {
public:
    //@briefs: 直接构造函数
    //@params：const char *
    //@return: 
    String(const char *ch = NULL);
    
    //@briefs: 拷贝构造函数
    //@params：const String &
    //@return: 
    String(const String &other);
    //知识点：为什么拷贝构造函数需要用const String&参数类型

    //@briefs: 析构函数
    //@params：
    //@return: 
    ~String(); 

    //@briefs: 拷贝赋值函数
    //@params：const String &
    //@return: String &
    String & operator=(const String &other); 
    //知识点：拷贝构造函数的返回类型应该是String &

    //@briefs: string内容的get方法
    //@params：
    //@return: char *
    char* get_data() const;
    
    //@briefs: string内容的set方法
    //@params：char*
    //@return: void
    void set_data(char *d);

    //@briefs: string内容的长度
    //@params：
    //@return: int
    int size() const;

    //@briefs: 下标取值运算符重载--普通引用版本
    //@params：int
    //@return: char &
    char & operator[](int n); 

    //@briefs: 下标取值运算符重载--常量引用版本
    //@params：int
    //@return: const char &
    const char & operator[](int n) const; 
    
    //@briefs: 重载==，判断两个string对象是否相等
    //@params：const String &
    //@return: bool
    bool operator==(const String &other) const;

    //@briefs: 重载+，两个string对象相加
    //@params：const String &, const String &
    //@return: String 
    String operator+(const String &str1);

    //@briefs: 重载<<，输出字符串
    //@params：ostream &
    //@return: ostream &
    friend std::ostream & operator<<(std::ostream& out, const String& str );
  
    //@briefs: 重载>>，输入字符串
    //@params：istream &
    //@return: istream &
    friend std::istream & operator>>(std::istream& in, const String& str );

private:
    char *data; // meta data
};

#endif

