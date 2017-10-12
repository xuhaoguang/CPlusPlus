/*
 * File Name: four_cast.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Tue Oct 10 08:58:34 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 测试C++中四中cast 
*/ 
#include <iostream>
using namespace std;

class A{
public:
    int num;
    A(){
        num = 0;
    } 
};

class B{
public:
	virtual void fun(){
		cout << 'B' << endl;
	}

private:
	int i;
};

class C : public B{
public:
	virtual void fun(){
		cout << 'C' << endl;
	}
};

	
int main(){
    /*
     * const_cast
     * 1 常量指针转非常量指针
     * 2 常量引用转非常量引用
     * 3 注意：不可以通过const_cast将常量对象或者常量基本类型转成非常量
     */
     
    //常量指针转非常量指针
    //------------指针指向类-------------
    const A* p1 = new A();
    cout << p1->num << endl; // 0
    //p1->num = 100; //ERROR: const常量不允许修改属性成员值

    A* p2 = const_cast<A*>(p1); //去除const成员，此时p2和p1指向的是同一个变量
    cout << p1->num << "\t" << p2->num << endl; // 0, 0
    p2->num = 100; //此时p2将p1的const属性去除了，因此可以修改属性成员值
    cout << p1->num << "\t" << p2->num << endl; // 100, 100 
    
    //------------指针指向基本类型-------------
    const int i = 100;
    //i = 200; //ERROR
    int* j = const_cast<int*>(&i);
    *j = 200;
    cout << i << "\t" << *j << endl; //200, 200
    

    //常量引用转非常量引用
    A a0;
    const A& a1 = a0;
    //a1.num = 200; //ERROR
    cout << a0.num << "\t" << a1.num << "\t" << endl; //0, 0
    A& a2 = const_cast<A&>(a1);
    a2.num = 200;
    cout << a0.num << "\t" << a1.num << "\t" << a2.num << endl; //200, 200, 200
    
    
    /*
     * static_cast
     * 1 用于基本数据类型之间的转换
     * 2 用于基类和子类之间指针或者引用的转换
     *   上行转换安全（把子类指针或者引用转换成基类表示
     *   下行转换不安全，没有动态类型检查（将基类指针或者引用转换成子类表示
     * 3 把void指针转换成目标类型指针
    */
    
    //1 用于基本数据类型之间的转换
    double a = 3.1315;
    int b = (int)a; // 隐式转换
    cout << b << endl; 
    int c = static_cast<int>(a); // 显示转换
    cout << c << endl;
    
    int d = 100;
    float e = static_cast<float>(d);
    cout << e << endl;
    
    //2 用于基类和子类之间指针或者引用的转换
    B *pb = new B();
    pb->fun();
	C *pc = static_cast<C*>(pb); //下行转换(不安全)
    pc->fun();

	C *ppc = new C();
    ppc->fun();
	B *ppb = static_cast<B*>(ppc); //上行转换(安全)
    ppb->fun();
    
    //3 把void指针转换成目标类型指针
    double aa = 1.999;
    void * vptr = & aa;
    double * dptr = static_cast<double*>(vptr);
    cout<<*dptr<<endl; //输出1.999   

    /*
     * dynamic_cast
     * 1 进行上行转换和下行转换时效果和static_cast是一样的，但是在做下行转换时dynamic_cast会做安全检查，而static_cast不会做安全检查
     * 2 上下行转换时需要有virtual虚函数的存在，不然使用dynamic_cast会出现编译错误
     * 3 为了让dynamic_cast能正常工作，必须让编译器支持运行期类型信息（RTTI）
     */

    //B *pb_1 = new B();
    //pb_1->fun();
	//C *pc_1 = dynamic_cast<C*>(pb_1); //下行转换(不安全)
    //pc_1->fun();

	C *ppc_1 = new C();
    ppc_1->fun();
	B *ppb_1 = static_cast<B*>(ppc_1); //上行转换(安全) 
    ppb_1->fun();

    /*
     * reinterpret_cast
     */

    return 0;
} 
