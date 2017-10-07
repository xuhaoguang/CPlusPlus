/*
 * File Name: MyString.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Sat Oct  7 15:20:01 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 
*/ 
#include <iostream>
#include "MyString.h"

using namespace std;

//@briefs: 直接构造函数
//@params：const char *
//@return: 
String::String(const char *ch){
    if(ch == NULL){
        data = new char[1];
        *data = '\0';
    }else{
        int length = strlen(ch);
        data = new char[length + 1];
        strcpy(data, ch);
    }          
}              
               
//@briefs: 拷贝构造函数
//@params：const String &
//@return: 
String::String(const String &other){
    //int length = strlen(other.data);
    int length = other.size();
    data = new char[length + 1];
    strcpy(data, other.data);
} 

//@briefs: 析构函数
//@params：
//@return: 
String::~String(){
    if(data != NULL){
        delete[] data;
    } 
} 

//@briefs: 拷贝赋值函数
//@params：const String &
//@return: String &
inline String & String::operator=(const String &other){
    //这一步很重要 当参数是本身时，需要直接返回自身
    if(this == &other){
        return *this;
    } 

    delete[]  data;
    int length = strlen(other.data);
    data = new char[length + 1];
    strcpy(data, other.data);
    
    return *this;
} 

//@briefs: string内容的get方法
//@params：
//@return: char *
inline char* String::get_data() const{
    return data;
} 

//@briefs: string内容的set方法
//@params：char*
//@return: void
void String::set_data(char *d){
    int length = strlen(d);
    data = new char[length + 1];
    strcpy(data, d);
} 

//@briefs: string内容的长度
//@params：
//@return: int
inline int String::size() const{
    return strlen(data);
} 

//@briefs: 下标取值运算符重载--普通引用版本
//@params：int
//@return: char &
inline char & String::operator[](int n){
    if(n < 0 || n >= strlen(data)){
        cerr << "Out of Range" << endl;
        return data[strlen(data) - 1];
    } 

    return data[n];
} 

//@briefs: 下标取值运算符重载--常量引用版本
//@params：int
//@return: const char &
const char & String::operator[](int n) const{
    if(n < 0 || n >= strlen(data)){
        cerr << n <<   "Out of Range ";
        //char c = '\0';
        return data[strlen(data) - 1];
    } 

    return data[n];
} 

//@briefs: 重载==，判断两个string对象是否相等
//@params：const String &
//@return: bool
inline bool String::operator==(const String &other) const{
    if(size() != other.size()){
        return false;
    } 

    return strcmp(data, other.data) ? false : true;
} 

//@briefs: 重载+，两个string对象相加
//@params：const String &, const String &
//@return: String 
String String::operator+(const String &str1){
    String sum;
    char* data = new char[size() + str1.size() + 1];
    strcpy(data, get_data());
    strcat(data, str1.get_data());
    sum.set_data(data);
    return sum;
} 

//@briefs: 重载<<，输出字符串
//@params：ostream &
//@return: ostream &
//注意：<< >>重载函数不能作为类的成员函数，而是用friend友元函数来重载
std::ostream & operator<<(std::ostream& out, const String& str){
    out << str.get_data();
    return out;
} 

//@briefs: 重载>>，输入字符串
//@params：istream &
//@return: istream &
std::istream & operator>>(std::istream& in, String& str){
    char* data = new char[1000];
    in >> data;
    if(in){
        str.set_data(data);
    }else{
        str.set_data(NULL);
    } 

    return in;
} 

int main(int argc, char** argv){
    String s1("abcde");
    cout << "s1.get_data() = " << s1.get_data() << endl;
    cout << "s1.size() = " << s1.size() << endl;
    cout << "s1[0] = " << s1[0] << endl;
    cout << "s1[10] = " << s1[10] << endl;
    cout << "s1[-5] = " << s1[-5] << endl;
   
    s1.set_data("qwert");
    cout << "s1.get_data() = " << s1.get_data() << endl;
    
    const String s2 = s1;
    cout << "s2.get_data() = " << s2.get_data() << endl;
   
    cout << "(s1 == s2) : " << (s1 == s2) << endl;

    String s3 = "12345";
    cout << "(s2 == s3) : " << (s2 == s3) << endl;
    
    String s4 = s1 + s3;
    cout << "s4.get_data() = " << s4.get_data() << endl;
    
    cout << "cout << s4 " << s4 << endl;

    String s5;
    cin >> s5;
    cout << s5 << endl;
    return 0;
} 
