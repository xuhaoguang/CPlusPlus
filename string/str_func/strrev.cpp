/*
 * File Name: strrev.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Mon Oct  9 09:06:48 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 反转字符串中的单词顺序，单词内部顺序不变
 *         input:  I am from Shanghai
 *         output: Shanghai from am I
*/ 

#include <iostream>
#include <stack>
using namespace std;

//借用栈来实现倒序
void strrev(char* str){
    stack<string> res;

    char* start = str;
    char* ptr = str;

    while(*ptr++ != '\0'){
        if(*ptr == ' ' || *ptr == '\0'){
            //cout << *start << " " << *(ptr-1) << endl;  
            int len = ptr - start;
            
            //根据start和end来拷贝内存，得到字符串
            //char* tmp = (char*)malloc(len + 1);
            //memcpy(tmp, start, len);
            //tmp[len] = '\0';
            
            //通过string(start, end)来得到字符串
            string tmp(start, ptr);
            res.push(tmp);
            
            start = ptr + 1;
        } 
    } 

    while(!res.empty()){
        cout << res.top() << " ";
        res.pop();
    } 
    cout << endl;
}

//指针内部倒序
void strrev1(char* str){
    char* start = str;
    char* end = str;
    char* ptr = str;
    
    while(*ptr++ != '\0'){
        if(*ptr == ' ' || *ptr == '\0'){
            end = ptr -1;
            while(start < end){
                char tmp = *start;
                *start = *end;
                *end = tmp;

                start++;
                end--;
            } 

            start = end = ptr + 1;
        } 
    } 

    start = str;
    end = ptr - 2;
    while(start < end){
        char tmp = *start;
        *start = *end;
        *end = tmp;

        start++;
        end--;
    } 

    cout << str << endl;
} 

int main(){
    char str[] = "I am from Shanghai";
    strrev(str);
    strrev1(str);
    return 0;
} 
