#include<iostream>
using namespace std;
//�ǵݼ������ �ݹ��㷨��ʵ�� 
int a[10]={2,3,5,1,8,7,10,4,6,9};
void Print(int arr[], int n);
void InsertSort(int arr[], int n)
{
	if (n>1) {
		InsertSort(a, n-1);//ǰn-1��Ԫ���Ѿ���������� 
		int now = a[n-1];//��¼���һ��Ԫ��
		cout<<now<<endl; 
		
		int i;
		for (i=n-2; now<a[i]; i--) {//����ƶ�Ԫ�� 
			/*if (now<a[i]) {//��һ���Ƚϴ󣬽��� 
				int temp=a[i];
				a[i]=a[n-1];
				a[n-1]=temp;		
			}*/
			a[i+1]=a[i];//����ƶ� 
		}
		a[i+1]=now;
		Print(a,10);
	}
	//else return 0;
}
void Print(int arr[], int n)
{
	for (int i=0; i<n; i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	
	Print(a,10);
	InsertSort(a,10);
	Print(a,10);
	return 0;
} 
