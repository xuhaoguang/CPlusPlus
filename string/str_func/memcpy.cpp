/*
 * File Name: memcpy.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Sun Oct  8 14:30:42 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 
*/ 
#include <iostream>
using namespace std;

//@briefs: 内存复制函数(内存重叠时不能正确处理)
//@params: void*, void *, size_t
//@return: void*
void* memcpy(void* memTo, void* memFrom, size_t size){
    if(memTo == NULL || memFrom == NULL){
        return NULL;
    } 
    
    char* tmpTo = (char*)memTo;
    char* tmpFrom = (char*)memFrom;

    while(size-- > 0){
        *tmpTo++ = *tmpFrom++;
    } 

    return memTo;
} 

int main(){
    char From[6] = "abcde";
    char To[10];
    memcpy(To, From, 6);
    cout << To << endl;
    
    memcpy(To, From, 3);
    To[3]  = '\0'; //注意认为在后面加上\0
    cout << To << endl;
    return 0;
} 
