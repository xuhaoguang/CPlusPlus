## 常见的字符串处理函数的相关问题
1. strcpy、memcpy。memmove，sprintf函数的区别
* strcpy只能用于复制字符串(char\*)类型，而memcpy, memmove是内存拷贝，针对指针处理的，是可以处理任意类型的数据
* strcpy对于目标字符数组长度不够时，可能会出现溢出情况, strcpy遇到被复制字符的串结束符"\0"才结束，所以容易溢出
* 当出现内存重叠时。memcpy复制后的结果不准确，而memmove会正确处理
* sprintf函数操作的源对象不限于字符串：源对象可以是字符串、也可以是任意基本类型的数据。主要是实现将其他数据类型转换为字符串

2. 写一个求字符串长度的函数strlen
* 求字符串长度的基本做法就是：依次遍历字符串直到遇到\0字符，统计走过的步数
* 但是strlen2的效率要比strlen高
    ```c++
    //计算一个字符串的长度时，src 和 len 都需要同时加1
    int strlen1(const char* src){
        assert(NULL != src);
        int len = 0;
        while(*src++ != '\0'){
            len++;
        }
    
        return len;
    }
    
    //计算一个字符串的长度时，只需要src每次加1， 因此strlen2的性能要比strlen1高
    int strlen2(const char* src){
        assert(NULL != src);
        const char* tmp = src;
    
        while(*src++ != '\0');
        return (src - tmp - 1);
    }
    ```
