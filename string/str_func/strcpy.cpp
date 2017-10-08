/*
 * File Name: strcpy.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Sun Oct  8 14:16:47 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 
*/ 

#include <iostream>
using namespace std;

char* strcpy(char* strDest, char* strSrc){
    if(strDest == NULL || strSrc == NULL){
        return NULL;
    } 

    char* res = strDest;
    while((*strDest++ = *strSrc++) != '\0');

    return res;
} 

int main(){
    char dest[10];
    char src[6] = "abcde";

    cout << strcpy(dest, src) << endl;
    return 0;
} 
