/*
 * File Name: strcmp.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Mon Oct  9 18:41:10 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 字符串比较算法 
*/ 
#include <iostream>
using namespace std;

int mystrcmp(const char* src, const char* dest){
    int res = 0;  //src == dest
    while( !(res = *src - *dest) && *dest){
        ++src;
        ++dest;
    } 
    
    if(res < 0){
        res = -1; //src < dest
    }else if(res > 0){
        res = 1;  //src > dest
    } 
    
    return res;
}


int main(){
    char str1[] = "abcdef";
    char str2[] = "abcdef";
    char str3[] = "fbcdef";
    
    cout << mystrcmp(str1, str2) << endl;
    cout << mystrcmp(str2, str3) << endl;
    cout << mystrcmp(str3, str2) << endl;
    return 0;
} 
