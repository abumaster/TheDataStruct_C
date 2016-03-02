#include <iostream>
#include <string>
#include "Seqlist.h"
using namespace std;

int main()
{
	SeqList<int> test(15);
	int array[15]={2,5,8,1,9,9,7,6,4,3,2,9,7,7,9};
	for(int i=0;i<15;i++){
		test.Insert(array[i],0);
 	}
 	test.Insert(1,0);
	cout<<(test.Find(0)?"can't be found ":"Be found ")<< 0 << endl<<endl;
	test.Print("ԭ���Ա�");
	if(test.Remove(7)>0)
		test.Print("ɾ��7������Ա�");
	if(test.Remove(9)>0)
		test.Print("ɾ��9������Ա�");
	if(test.Remove(10)>0)
		test.Print("ɾ��10��");

	return 1;


}
