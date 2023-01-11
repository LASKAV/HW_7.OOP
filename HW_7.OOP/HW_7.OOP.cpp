#include <iostream>
#include <stdarg.h>
using namespace std;
/*
�������� ���������, ������� ��������� ������� � �������������� ����������� ����������,
���������������� ��������������� ����� �� �����.
����������� ������� va_start() � va_arg()
*/

void AnyType(int count, bool typeof, ...) {
	//����� ��� ������������� ����������
	int sumi = 0;
	//����� ��� ������������ ����������
	double sumd = 0.0;
	//������ ��������� �� ������ ����������
	va_list arg_ptr;
	//�������� ���� ���������, ������������
	//�� ������� ������������ ���������
	va_start(arg_ptr, count);
	//���������� ������ ����������� ��������
	va_arg(arg_ptr, bool);
	//count ��� ��������� ����������� ���������
	while (count--) {
		//���� typeof - true, �� ��������� ��������� 
		//���� int
		//���� typeof - false, �� ��������� ��������� 
		//���� double 
		(typeof) ? sumi += va_arg(arg_ptr, int) :
			sumd += va_arg(arg_ptr, double);
	}
	//��������� ������ ����������
	va_end(arg_ptr);
	//���� typeof - true, �� ���������� ����� ���� int
	//���� typeof - false, �� ���������� �����
	//���� double
	(typeof) ? cout << "Integer sum = " << sumi : cout << "Double sum = " << sumd;
	cout << "\n\n";
}
int main()
{
	//�������� ������� ��� ������������ 
	//���������� ���� int
	AnyType(4, true, 3, 8, 9, 4);
	//�������� ������� ��� ������������ 
	//���������� ���� double
	AnyType(3, false, 2.5, 1.1, 3.6);
}

// ������ � ������� ������� va_start � va_arg ��������� ������������� ��������� �� ������ 
// ������������� ����������, �� � � ������� ������