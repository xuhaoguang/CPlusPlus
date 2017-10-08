/*
 * File Name: strlen.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Sun Oct  8 19:53:12 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 
*/ 
#include <iostream>
#include <assert.h>
using namespace std;

//计算一个字符串的长度时，src 和 len 都需要同时加1
int strlen1(const char* src){
    assert(NULL != src);
    int len = 0;
    while(*src++ != '\0'){
        len++;
    } 

    return len;
} 

//计算一个字符串的长度时，只需要src每次加1， 因此strlen2的性能要比strlen1高
int strlen2(const char* src){
    assert(NULL != src);
    const char* tmp = src;

    while(*src++ != '\0');
    return (src - tmp - 1);
}

int main(){
    char* s = "hello world!";
    cout << strlen1(s) << endl;
    cout << strlen2(s) << endl;
    return 0;
}
