/*
 * File Name: strstr.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Sun Oct  8 20:20:38 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 
*/ 
#include <iostream>
using namespace std;

// char* my_strstr(char* src, char* sub) const //ERROR  只有成员函数才能使用const修饰，不是成员函数不能使用const来修饰
char* my_strstr(char* src, char* sub){
    if(src == NULL || sub == NULL) {
        return src;
    } 

    const char* tmpSrc;
    const char* tmpSub;

    while(*src){ // 遍历src字符串
        tmpSrc = src;
        tmpSub = sub;
        
        do{ // 遍历sub字符串
            if(!*tmpSub){ // sub字符串结束
                return src; // 找到sub字符串在src中的位置
            } 
        }while(*tmpSrc++ == *tmpSub++);
        src += 1;
    } 

    return NULL; // 查找失败
} 

int main(){
    char p[] = "12345";
    char q[] = "34";
    char* res = my_strstr(p, q);
    cout << res << endl;
    return 0;
} 
