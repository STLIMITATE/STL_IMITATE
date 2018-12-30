// vector.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/vector_proxy.hpp>
#include <boost/numeric/ublas/io.hpp>
//#include "myVector.h"

int main() {
	using namespace boost::numeric::ublas;
	vector<int> v(20, 0);
	int array[5] = { 0, 3, 4, 6, 8 };
	basic_randomlist<int, vector<int>::size_type> randoml((int*)array, 5);
	vector_randomlist<vector<int> > vrl(v, randoml);
	for (unsigned i = 0; i < randoml.size(); ++i)
		vrl(i) = i;
	std::cout << vrl << std::endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
