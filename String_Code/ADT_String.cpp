/*
** ���Ķѷ���洢��ʾ ʵ�� 
**�����ݽṹ��c���԰棩����ε�� 
** �㷨4.4 P76 
** @2016/03/15
*/
#include <iostream>
#include <string.h>
using namespace std;

//���Ľṹ 
typedef struct {
	char *ch;//�ǿմ����������ȷ���ռ䣬��λNULL 
	int length;//���ĳ��� 
}HString;

//��������������˵�� 
//1.����һ����ֵ����chars���ַ���T 
//ʧ�ܷ���-1 
int StrAssign(HString &T,  char *chars)
{
	//��һ�䲻��Ҫ����û�г�ʼ�����ָ�� 
	//if (T.ch) free(T.ch);//�ǿ����
	//��chars�ĳ���
	int i=0;
	/*
	 char *c;
	for (i=0,c=chars; c;/*cָ����chars�ַ���ָ��c�ǿ�*/
	//	++i,++c);
	
	i=strlen(chars);//20
	
	if (!i) {//������ַ���Ϊ�յ� 
		T.ch=NULL;
		T.length=0;
	}
	else {
		//�����Ӧ��С���ڴ�
		
		if (!(T.ch=(char *)malloc(i*sizeof(char)))) /*exit(1);*/return -1;
		for (int pos=0; pos<i; pos++)
			T.ch[pos]=chars[pos];//���Ƶ�����
		T.length=i; 
	}
	return 0;	
}//StrAssign

//2.return The string's length
int StrLength(HString S)
{
	return S.length;
}

//3.compare,if S>T return >0; if S=T return =0;
int StrCompare(HString S, HString T)
{
	//�Ƚϣ���Ӧ����ĸ��
	for (int i=0; i<S.length && i<T.length; ++i) {
		if (S.ch[i] != T.ch[i]) //���ֲ���ͬ�ľͽ��� 
		return S.ch[i]-T.ch[i]; 
	} 
	//����forѭ���������ǣ���һ�����������Ѿ���������
	//ǰ��Ĵ�������ͬ�� 
	return S.length-T.length;
}

//4.Clear The string and free the mem
int ClearString(HString &S)
{
	if (S.ch) {
		free(S.ch);
		S.ch=NULL;
		S.length=0;
	}
	return 0;		
}

//5.connected two string 
//success return 0, errors return -1
int Concat(HString &T, HString S1, HString S2)
{
	//û��ʼ����ָ�벻��ֱ���ã������� 
	//if (T.ch) free(T.ch);
	if (!(T.ch=(char*)malloc((S1.length+S2.length)*sizeof(char))))
		return -1;
	T.length=S1.length+S2.length;
	int i=0;
	int pos=0;
	for (i=0; i<S1.length; i++)
		T.ch[pos++]=S1.ch[i];
	for (i=0; i<S2.length; i++) 
		T.ch[pos++]=S2.ch[i];
	return 0;
}
//6.return S' postion pos,and length len
int  SubString(HString &Sub, HString S, int pos, int len)
{
	if (pos<1 || pos>S.length || len<0 || len>S.length-pos+1)
		return -1;
	if (Sub.ch) free(Sub.ch);
	if (!len) {
		Sub.ch=NULL;
		Sub.length=0;
	}
	else {
		Sub.ch=(char*)malloc(len*sizeof(char));
		int s_pos=pos-1;
		for (int i=0; i<len; i++) {
			Sub.ch[i]=S.ch[s_pos++];
		}
		Sub.length=len;
	}
	return 0;
}
void PrintStr(HString T)
{
	for (int i=0;i<T.length;i++)
		cout<<T.ch[i];
	cout<<endl;
}
int main()
{
	HString mystring;
	HString yourstring;
	HString tempstring;
	string s1="hello word,i am zgf!";
	string s2="what it is?";
	//char ch[]="hello";
	int len=s1.length();
	int len2=s2.length();
	 char *ch = (char*)malloc(len*sizeof(char));
	 char *ch2= (char*)malloc(len2*sizeof(char));
	 s1.copy(ch,len,0);
	 s2.copy(ch2,len2,0);
	 //ch[len+1]='\0';
	 cout<<ch<<endl;
	 cout<<strlen(ch)<<endl;
	if(StrAssign(mystring,ch)<0)//��ʼ��string1 
		cout<<"init error"<<endl;
	if(StrAssign(yourstring,ch2)<0)//��ʼ��string2
		cout<<"init error"<<endl; 
	cout<<mystring.length<<endl;
	//ֱ����ָ����������׳������룬�ڴ����� 
	/*cout<<mystring.ch<<endl;*/
	PrintStr(mystring);
	cout<<"your string Length is : "<<StrLength(yourstring)<<endl;
	PrintStr(yourstring);
	Concat(tempstring,mystring,yourstring);
	cout<<"hebing i and you is : (length "<<StrLength(tempstring)<<")"<<endl;
	PrintStr(tempstring);
	return 0;
}









