#include <iostream>
#include "string.h"
using namespace std; 

int *p_next;
//求辅助的next数组 
void get_next_1(char *part, int next[])
{
	int len=strlen(part);
	cout<<len<<endl;
	int i=1,j=0;
	next[0]=0;
	while (i<len) {
		if (j==0 || part[i-1]==part[j-1]) {
			++i;//2
			++j;//1
			next[i-1]=j;
		}
		else {
			j=next[j-1];
		}
	}	
}
//从主串S中查找子串T 成功返回rue，失败返回false 
bool mod_find(char *S, char *T)
{
	int i=0;
	int j=0;
	while (i<strlen(S) && j<strlen(T)) {
		if (j==0 || S[i]==T[j]) {//当前相等 
			++i;++j;
		}
		else {
			j=p_next[j-1];
		}	
	}
	if (j>=strlen(T)) return true;
	else return false;
}

int main()
{
	string s1="abaabcacac";
	string s2="acabaabaabcacaabc";
	char *master=new char[s2.length()];
	char *part=new char[s1.length()];
	strcpy(master,s2.c_str());
	strcpy(part,s1.c_str());
	int next[10]={0};
	get_next_1(part,next);
	p_next=new int[10];
	p_next=NULL;
	p_next=next;
	int i;
	cout<<"主串是: "<<endl;
	for (i=0;i<strlen(master); i++)
		cout<<master[i]<<" ";
	cout<<"\n子串: "<<endl;
	for (i=0; i<strlen(part); i++)
		cout<<part[i]<<" ";
	//cout<<endl<<"next[]: ";
	cout<<endl;
	for (i=0; i<strlen(part); i++)
		cout<<next[i]<<" ";
	cout<<endl;
	
	if(mod_find(master,part))
		cout<<"success"<<endl;
	else
		cout<<"false"<<endl;
//	delete [] p_next;
	return 0;
}
