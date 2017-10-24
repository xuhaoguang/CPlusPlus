/*
 * File Name: gbk_strlen.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Sat Oct 21 14:23:14 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 统计字符串中中文汉字的个数 
 *         中文汉字编码是双字节，其中首字节<0，尾字节在0-63以外
*/ 

#include <iostream>
using namespace std;

int gbk_strlen(const char* str){
    const char* p = str;  //p用于后面遍历
    while(*p){
        if(*p < 0 && (*(p+1) < 0 || *(p+1) > 63) ){ //中文汉字情况
            str++; //str移动一位
            p += 2; //p移动两位
        }else{
            p++;
        } 
    } 

    return p - str;
} 

int main(){
    char* str = "我叫Harvey, I am from 中国";
    cout << gbk_strlen(str) << endl;
    return 0;
} 
