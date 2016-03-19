#include<iostream>
using namespace std;
//非递减序输出 递归算法的实现 
int a[10]={2,3,5,1,8,7,10,4,6,9};
void Print(int arr[], int n);
void InsertSort(int arr[], int n)
{
	if (n>1) {
		InsertSort(a, n-1);//前n-1个元素已经是有序的了 
		int now = a[n-1];//记录最后一个元素
		cout<<now<<endl; 
		
		int i;
		for (i=n-2; now<a[i]; i--) {//向后移动元素 
			/*if (now<a[i]) {//后一个比较大，交换 
				int temp=a[i];
				a[i]=a[n-1];
				a[n-1]=temp;		
			}*/
			a[i+1]=a[i];//向后移动 
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
