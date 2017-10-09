/*
 * File Name: huiwen.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Mon Oct  9 10:57:48 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 判断一个字符串是不是回文 
*/ 
#include <iostream>
using namespace std;

//判断一个字符串是否为回文
bool isHuiwen(char* str){
	if(str == NULL){
        return false;
	}
    bool flag = true;

    int len = strlen(str);
    for(int i = 0; i < (len / 2); i++){
        //cout << str[i] << " " << str[len - i - 1] << endl;
        if(str[i] != str[len - i - 1]){
            flag = false;
            break;
        } 
    } 

    return flag;
} 

//求字符串中最大回文长度
//int getHuiwenLength(char* str){
//    if(NULL == str) {
//        return 0;
//    }
//
//    int n = strlen(str);
//    int i, j;
//    int max = 0;
//
//    if((n & 0x1) == 1){ //奇数情况
//        for(i = 0; i < n; ++i){
//            for(j = 0; (i-j >= 0) && (i+j < n); ++j){
//                cout << str[i-j] << " " <<  str[i+j] << endl;
//                if(str[i-j] != str[i+j]){
//                    break;
//                }
//            }
//            j--; 
//            cout << i << " " << j << endl << endl;
//            if(j * 2 + 1 > max){
//                max = j * 2 + 1;  
//            }
//        }
//    }else{ //偶数情况
//        for(i = 0; i < n; ++i){
//            for(j = 0; (i-j>=0)&&(i+j+1<n); ++j){
//                //cout << str[i-j] << " " <<  str[i+j+1] << endl;
//                if(str[i-j] != str[i+j+1]) {
//                    break;
//                }
//            }
//            j--;
//            //cout << i << " " << j << endl << endl;
//            if(j * 2 + 1 > max) {
//                max = j * 2 + 2;
//            }
//        }         
//    }
//      
//    return max;
//}


int LongestPalindrome(char* str, int length)
{
	int i, j, max, current;
	if (str == NULL || length < 1)
		return 0;
	max = 0;

	for (i = 0; i < length; ++i) //i 看成是中心元素，然后i-j是左边，i+j是右边元素，比较这两个元素是否相等
	{
		for (j = 0; (i - j >= 0) && (i + j  < length); ++j)
		{
			if (str[i - j] != str[i + j]) //比较左右对称的元素是否相等，此时i固定，j在增加
				break;
			current = 2 * j + 1; //直到不相等，回文结束，此时回文长度为2*j+1
		}

		if (current > max)
			max = current;	//如果current的值大于最大记录的回文长度，则更新最大记录；

		for (j = 0; (i - j >= 0) && (i + j + 1 < length); ++j)
		{
			if (str[i - j] != str[i + j + 1])
				break;
			current = 2 * j + 2; //同理在偶数长度时，回文长度为2*j+2
		}
		if (current > max)
			max = current; //如果current的值大于最大记录的回文长度，则更新最大记录；
	}
	return max;
}

int main(){
    //char str[] = "aabcddcbaa";
    //cout << isHuiwen(str) << endl;

    //char str1[] = "abcd1dcba";
    //cout << isHuiwen(str1) << endl;
    //
    //cout << getHuiwenLength(str1) << endl;
    //cout << getHuiwenLength(str) << endl;
   
    char str2[] = "1abbcddcb";
    char str3[] = "abbcddcb";

    //cout << isHuiwen(str2) << endl;
    //cout << getHuiwenLength(str2) << endl;
	cout << LongestPalindrome(str2, 9) << endl;;
	cout << LongestPalindrome(str3, 8) << endl;;
    return 0;
} 
