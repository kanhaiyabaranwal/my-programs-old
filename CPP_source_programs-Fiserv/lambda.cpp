//#define __IBMCPP_TR1__
#include<iostream>

int main()
{
int offset=42;
function<int(int)> offset_a=[&](int j){return offset+j;};
offset=123;
function<int(int)> offset_b=[&](int j){return offset+j;};
//std::cout<<offset_a(12)<<","<<offset_b(12)<<std::endl;
std::cout<<offset_a(12)<<offset_b(12)<<std::endl;
offset=99;
//std::cout<<offset_a(12)<<","<<offset_b(12)<<std::endl;
}
