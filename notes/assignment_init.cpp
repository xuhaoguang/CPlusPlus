/*
 * File Name: assignment_init.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Tue Oct 10 16:28:17 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 类成员的初始化和赋值的区别论述 
*/ 

#include <iostream>
using namespace std;

// 当成员变量是const类型时，必须使用初始化方法！
class A{
public:
    const int a;
    
    /*
    A(int x){
        a = x; //ERROR 编译错误
    } 
    */
    
    A(int x) : a(x){

    } 
}; 

// 当成员变量是引用类型时，必须使用初始化方法！
class B{
public:
    int & a;
    /* 
    B(int x){ //ERROR 编译错误
        a = x;
    } 
    */
    
    B(int x) : a(x){

    } 
};

class Base{
public:
    Base(int x){
        a = x;
    } 

private:
    int a;
};

//当类需要调用基类的构造函数，需要使初始化方法
class Derived : public Base{
public:
    int b;
    /*
    Derived(int _a, int _b){ //ERROR 编译错误，因为a是Base类的private成员，所以不能显示赋值
        a = _a;
        b = _b;
    }
    */
    Derived(int _a, int _b) : Base(_a), b(_b){ //TRUE 通过初始化的方式是可以完成
    }
}; 

int main(){
    return 0;
} 
