#include <iostream>
#include <cstring>
using namespace std;
#include "MyString.h"

int main()
{
	myString str1("hello hello ya")	;
	myString str2("what is it?");
	myString str3("is");
	//cout << str1+str2 << endl;
	if (str2.Find(str3)>=0)
	{
		cout << "�ҵ���" <<str3<<" �� "<<str2<< endl;
	}
	else
		cout << "can not find" << endl;

	if (str1 < str2) cout << "<" << endl;
	else cout << ">" << endl;

	//λ�õĲ���
	cout <<"str1 is :   "<< str1 << "	length: "<< str1.Length() 
		<< endl;
	cout << str1(2, 4) << endl;//str1 ��2������4��
	cout << str1[4] << endl;

	//���ص����������
	myString ms;
	cin >> ms;
	cout << ms << endl;


	system("pause");
	return 0;
}
