/*
 * File Name: bigint.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Sat Oct 21 11:59:24 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 大数加法
*/ 
#include <iostream>
using namespace std;

char* addBigInt(char* num1, char* num2){
    int c = 0; //表示进位，开始最低进位为0
    int i = strlen(num1) - 1; //指向第一个加数的最低位
    int j = strlen(num2) - 1; //指向第二个加数的最低位
    
    int maxLength = strlen(num1) >= strlen(num2) ? strlen(num1)+1 : strlen(num2)+1;
    char* res = (char*)malloc(maxLength+1); //保存返回结果
    if(res == NULL){ //内存分配失败
        cerr << "malloc error" << endl;
        return NULL;
    } 

    res[maxLength] = '\0'; //将字符串最后一位标识为'\0'
    int k = maxLength - 1; //指向结果数的最低位

    while(i >= 0 && j >= 0){
        res[k] = ((num1[i] - '0') + (num2[j] - '0') + c) % 10 + '0'; //计算本位的值
        c = ((num1[i] - '0') + (num2[j] - '0') + c) / 10; //计算进位值
        //cout << "res[" << k << "] =" <<  res[k] << endl;
        --i;
        --j;
        --k;
    } 
    
    while(i >= 0){
        res[k] = ((num1[i] - '0') + c) % 10 + '0';
        c = ((num1[i] - '0') + c) / 10;
        --i;
        --k;
    } 

    while(j >= 0){
        res[k] = ((num2[j] - '0') + c) % 10 + '0';
        c = ((num2[j] - '0') + c) / 10;
        --j;
        --k;
    }


    res[0] = c + '0';

    if(res[0] != '0'){ //如果最高位不等于0，则输出结果
        return res;
    }else{
        return res+1; //最高位没有进位
    } 

    return NULL;
}

int main(){
    char* num1 = "123456789";
    //char* num2 = "123456789";
    char* num2 = "923456789";
    
    char* sum = addBigInt(num1, num2);
    if(sum == NULL){
        cout << "sum is null" << endl;
    }else{
        cout << sum << endl;
    } 

    return 0;
} 
