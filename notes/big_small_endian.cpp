/*
 * File Name: big_small_endian.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Tue Oct 10 15:37:41 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 判断处理器是大端模式还是小端模式
*/ 

#include <iostream>
using namespace std;


//大端模式：低地址存储高位数据
//小端模式：低地址存储低位数据
void checkCPUendian(){ //返回1，为小端；反之，为大端；
	union{
	 	unsigned int num; //注意用unsigned类型
	  	unsigned char ch;
	}p;

	p.num = 0x12345678;
	
    if (p.ch == 0x78) {
		cout << "Little endian" << endl;
	} else {
		cout << "Big endian" << endl;
	}
}

//大小端转换
void convertToLittleEndian(unsigned int *data){
   *data = ((*data & 0xff000000) >> 24)
         | ((*data & 0x00ff0000) >>  8)
         | ((*data & 0x0000ff00) <<  8)
         | ((*data & 0x000000ff) << 24)
}

int main(){
    checkCPUendian();
    return 0;
} 
