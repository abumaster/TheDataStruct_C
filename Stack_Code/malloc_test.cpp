#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int *base;
	int *pn=(int *)malloc(20*sizeof(int));
	base=pn;
	cout<<pn<<" "<<" "<<sizeof(int)<<endl;
	for (int i=0; i<10; i++)
	*(pn++) = i;
	pn=pn-10;
	//free(pn);
	for (int i=0; i<10; i++)
	cout<<*(pn++) <<" ";
	
	return 0;
}
