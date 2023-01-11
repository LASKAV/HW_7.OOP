#include <iostream>
#include <stdarg.h>
using namespace std;
/*
Написать программу, которая реализует функцию с неограниченным количеством параметров,
организовывающую форматированный вывод на экран.
Используйте функции va_start() и va_arg()
*/

void AnyType(int count, bool typeof, ...) {
	//сумма для целочисленных параметров
	int sumi = 0;
	//сумма для вещественных параметров
	double sumd = 0.0;
	//создаём указатель на список параметров
	va_list arg_ptr;
	//получаем этот указатель, отталкиваясь
	//от первого фактического параметра
	va_start(arg_ptr, count);
	//пропускаем второй фактический параметр
	va_arg(arg_ptr, bool);
	//count раз считываем последующие параметры
	while (count--) {
		//если typeof - true, то считываем параметры 
		//типа int
		//если typeof - false, то считываем параметры 
		//типа double 
		(typeof) ? sumi += va_arg(arg_ptr, int) :
			sumd += va_arg(arg_ptr, double);
	}
	//закрываем список параметров
	va_end(arg_ptr);
	//если typeof - true, то показываем сумму типа int
	//если typeof - false, то показываем сумму
	//типа double
	(typeof) ? cout << "Integer sum = " << sumi : cout << "Double sum = " << sumd;
	cout << "\n\n";
}
int main()
{
	//вызываем функцию для суммирования 
	//параметров типа int
	AnyType(4, true, 3, 8, 9, 4);
	//вызываем функцию для суммирования 
	//параметров типа double
	AnyType(3, false, 2.5, 1.1, 3.6);
}

// подход с помощью функций va_start и va_arg позволяет анализировать аргументы не только 
// произвольного количества, но и с разными типами