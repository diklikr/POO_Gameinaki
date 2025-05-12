#pragma once
#include <iostream>
class EjemploConstCast
{
	static void ejemploConstCast()
	{
		const int x = 10;
		int* p = const_cast<int*>(&x);
		*p = 20;
		std::cout << "Valor de x:" << x << std::endl;
 }
};

