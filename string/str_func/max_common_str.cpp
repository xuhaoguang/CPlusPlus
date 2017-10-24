/*
 * File Name: max_common_str.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Fri Oct 20 16:22:51 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 求两个字符串的最长公共子串 
*/ 
#include <iostream>
using namespace std;

char* common_string(char* str1, char* str2){
    char* shortstr;
    char* longstr;
    char* substr;

    if(str1 == NULL || str2 == NULL){
        return NULL;
    } 
    
    if(strlen(str1) <= strlen(str2)){
        shortstr = str1;
        longstr = str2;
    }else{
        shortstr = str2;
        longstr = str1;
    } 

    if(strstr(longstr, shortstr) != NULL){
        return shortstr;
    } 

    substr = (char*)malloc(sizeof(char) * (strlen(shortstr) + 1));

    for(int i = strlen(shortstr) - 1; i >= 0; i--){
        for(int j = 0; j < strlen(shortstr) - i; j++){
            memcpy(substr, &shortstr[j], i+1);
            substr[i+1] = '\0';
            if(strstr(longstr, substr) != NULL){
                return substr;
            } 
        } 
    }

    return NULL;
} 

int main(){
    //char* str1 = "abcdef";
    //char* str2 = "12345678";
    
    char* str1 = "asdfghjk";
    char* str2 = "1dfghj2";

    char* res = common_string(str1, str2);
    
    if(res != NULL){
        cout << res << endl;
    }else{
        cout << "Not find" << endl;
    } 
    return 0;
} 
