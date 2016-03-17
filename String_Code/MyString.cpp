#include <iostream>
#include <cstring>
using namespace std;
#include "MyString.h"

//默认构造函数
myString::myString() {
	m_pstr=new char[MAXSIZE+1];
	if (!m_pstr) {
		cout<<"allocation error"<<endl;
		exit(1);
	}
	this->m_ncurlen=0;
	m_pstr[0]='\0';
} 
//构造函数 
myString::myString(const char *init)
{
	m_pstr=new char[MAXSIZE+1];
	if(!m_pstr) {
		cout<<"error"<<endl;
		exit(1);
	} 
	this->m_ncurlen=strlen(init);
	strcpy(m_pstr,init);
}
myString::myString(const myString &copy)
{
	m_pstr=new char[MAXSIZE+1];
	if(!m_pstr){
		cerr<<"Allocation Error"<<endl;
		exit(1);
	}
	this->m_ncurlen=copy.m_ncurlen;
	strcpy(m_pstr,copy.m_pstr);
}
//KMP 构造的next数组 
void myString::get_next()
{
	int len=this->m_ncurlen;
	this->m_pnext=new int[len];
	this->m_pnext[0]=0;
	int i=1,j=0;
	while(i<len) {
		if (j==0||this->m_pstr[i-1]==this->m_pstr[j-1]) {
			++i;
			++j;
			this->m_pnext[i-1]=j;
		}
		else {
			j=m_pnext[j-1];
		}
	}	
}
int myString::Find(myString part)//KMP find
{
	int i=0,j=0;
	part.get_next();//获得子串的next数组 
	while (i<(this->m_ncurlen) && j<(part.m_ncurlen)) {
		if (j==0 || this->m_pstr[i]==part.m_pstr[j]) {
			++i;
			++j;
		}
		else {
			j=part.m_pnext[j-1];
		}
	}
	delete [] part.m_pnext;
	if (j>=(part.m_ncurlen))
		return 0;
	else 
		return -1;	
}
//重载运算符 
myString& myString::operator()(int pos, int len)
{//用于查找pos到pos+len位置的字符串
	myString *temp=new myString;
	if (pos<0||pos+len-1>MAXSIZE||len<0) {
		temp->m_ncurlen=0;
		temp->m_pstr[0]='\0';
	}
	else {//范围正常 
		if (pos+len>this->m_ncurlen)
			len=this->m_ncurlen-pos+1;
		temp->m_ncurlen=len;
		int j=pos-1;//第pos个元素的下标 
		for (int i=0; i<temp->m_ncurlen; i++) {
			temp->m_pstr[i]=this->m_pstr[j++];		
		}
		temp->m_pstr[len]='\0';
	}
	return *temp;	 
	
}
bool myString::operator==(const myString cmp_str) const
{
	if (this->m_ncurlen!=cmp_str.m_ncurlen)
		return false;
	for (int i=0; i<this->m_ncurlen; i++) {
		if (this->m_pstr[i]!=cmp_str.m_pstr[i])
			return false;
	}
	return true;
}

bool myString::operator>(const myString cmp_str) const
{
	if (this->m_ncurlen!=cmp_str.m_ncurlen)
		return false;
	for (int i=0; i<this->m_ncurlen; i++) {
		if (this->m_pstr[i]!=cmp_str.m_pstr[i])
			return this->m_pstr[i] > cmp_str.m_pstr[i];
	}
	return 0;	
}
bool myString::operator<(const myString cmp_str) const
{
	if (this->m_ncurlen!=cmp_str.m_ncurlen)
		return false;
	for (int i=0; i<this->m_ncurlen; i++) {
		if (this->m_pstr[i]!=cmp_str.m_pstr[i])
			return this->m_pstr[i] < cmp_str.m_pstr[i];
	}
	return 0;
}
myString& myString::operator=(const myString& copy)
{
	delete [] this->m_pstr;
	this->m_pstr=new char[copy.m_ncurlen+1];
	this->m_ncurlen=copy.m_ncurlen;
	strcpy(this->m_pstr,copy.m_pstr);
	return *this;
}
myString& myString::operator+(const myString& add)
{
	int n=this->m_ncurlen;
	int length=n+add.m_ncurlen+1;
	myString temp(*this);
	delete[] this->m_pstr;
	this->m_pstr=new char[length];//重新分配空间
	int i=0;
	int j;
	for (j=0; j<n; j++)
		this->m_pstr[i++]=temp.m_pstr[j];
	for (j=0; j<add.m_ncurlen; j++)
		this->m_pstr[i++]=add.m_pstr[j];
	this->m_pstr[i]='\0';
	this->m_ncurlen=length-1;
	return *this; 
	
}
char& myString::operator[](int i)
{
	//从0开始
	if (i<0 || i>=this->m_ncurlen) {
		cout<<"bound is error"<<endl;
		exit(1);
	}
	return this->m_pstr[i];
}
ostream& operator<<(ostream& os, myString& str)
{
	os<<str.m_pstr;
	return os;
}
istream& operator>>(istream& is, myString& str)
{
	is>>str.m_pstr;
	return is;
}	
