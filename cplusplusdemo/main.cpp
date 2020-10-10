//
//  main.cpp
//  cplusplusdemo
//
//  Created by dragonflykan on 2020/9/11.
//  Copyright © 2020 dragonflykan. All rights reserved.
//

#include <iostream>
#include <memory>
#include <locale>
using namespace std;
class A
{
public:
    int i;
    A(int n):i(n) { cout << i << " " << "create" << endl; };
    ~A() { cout << i << " " << "destructed" << endl; }
};
int main()
{
    struct testSizeof {
        int a;
        char b;
    };
    //1111111111111111111
    testSizeof temTestSizeof = {4,'a'};//
    int size = sizeof(temTestSizeof);
    testSizeof *p1;
    p1 = &temTestSizeof;
    printf("%d",size);
    shared_ptr<A> sp1(new A(2)); //A(2)由sp1托管，
    shared_ptr<A> sp2(sp1);       //A(2)同时交由sp2托管
    shared_ptr<A> sp3;
    sp3 = sp2;   //A(2)同时交由sp3托管
    cout << sp1->i << "," << sp2->i <<"," << sp3->i << endl;
    A * p = sp3.get();      // get返回托管的指针，p 指向 A(2)
    cout << p->i << endl;  //输出 2
    sp1.reset(new A(3));    // reset导致托管新的指针, 此时sp1托管A(3)
    sp2.reset(new A(4));    // sp2托管A(4)
    cout << sp1->i << endl; //输出 3
    sp3.reset(new A(5));    // sp3托管A(5),A(2)无人托管，被delete
    cout << "end" << endl;
    return 0;
}
//#define tab "\t"
//int main()
//{
//      locale def;
//      cout<<def.name()<<endl;
//      locale current = cout.getloc();
//      cout<<current.name()<<endl;
//
//      float val=1234.56;      cout<<val<<endl;
//
//      //chage to french/france
//      wcout.imbue(std::locale("chs"));
//      current=cout.getloc();
//      cout<<current.name()<<endl;
//      cout<<val<<endl;
//
//      //上面是说明locale的用法，下面才是本例的内容，因为其中用到了imbue函数
//      cout<<"*********************************"<<endl;
//
//      //为了保证本地化输出（文字/时间/货币等），chs表示中国，wcout必须使用本地化解析编码
//      wcout.imbue(std::locale("chs"));
//
//      //string 英文，正确颠倒位置，显示第二个字符正确
//      string str1("ABCabc");
//      string str11(str1.rbegin(),str1.rend());
//      cout<<"UK\ts1\t:"<<str1<<tab<<str1[1]<<tab<<str11<<endl;
//
//      //wstring 英文，正确颠倒位置，显示第二个字符正确
//      wstring str2=L"ABCabc";
//      wstring str22(str2.rbegin(),str2.rend());
//      wcout<<"UK\tws4\t:"<<str2<<tab<<str2[1]<<tab<<str22<<endl;
//
//      //string 中文，颠倒后，变成乱码，第二个字符读取也错误
//      string str3("你好么？");
//      string str33(str3.rbegin(),str3.rend());
//      cout<<"CHN\ts3\t:"<<str3<<tab<<str3[1]<<tab<<str33<<endl;
//
//      //正确的打印第二个字符的方法
//      cout<<"CHN\ts3\t:RIGHT\t"<<str3[2]<<str3[3]<<endl;
//
//      //中文，正确颠倒位置，显示第二个字符正确
//      wstring str4=L"你好么？";
//      wstring str44(str4.rbegin(),str4.rend());
//      wcout<<"CHN\tws4\t:"<<str4<<tab<<str4[1]<<tab<<str44<<endl;
//
//      //只有char类型的string时才可以如此构造
//      wstring str5(str1.begin(),str1.end());
//      wstring str55(str5.rbegin(),str5.rend());
//      wcout<<"CHN\tws5\t:"<<str5<<tab<<str5[1]<<tab<<str55<<endl;
//
//      //如此构造将失败!!!!
//      wstring str6(str3.begin(),str3.end());
//      wstring str66(str6.rbegin(),str6.rend());
//      wcout<<"CHN\tws6\t:"<<str6<<tab<<str6[1]<<tab<<str66<<endl;
//    return 0;
//}
