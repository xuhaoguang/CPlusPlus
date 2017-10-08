/*
 * File Name: memmove.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Sun Oct  8 14:47:26 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 
*/ 
#include <iostream>
using namespace std;

//@briefs: 内存复制函数(内存重叠时能正常处理)
//@params: void*, void *, size_t
//@return: void*
void* mememove(void* dest, void* src, size_t size){
    if(dest == NULL || src == NULL){
        return NULL;
    } 

    char* s_dest = (char*)dest;
    char* s_src = (char*)src;
    
    //内存重叠的情况下：
    if((s_dest > s_src) && (s_src + size > s_dest)){
        s_dest = s_dest + size - 1;
        s_src = s_src + size - 1;

        while(size--){
            *s_dest-- = *src--;
        } 
    }else{
        while(size--){
            *s_dest++ = *src++;
        } 
    } 

    return dest;
} 

int main(){
    return 0;
} 
