/*
** 串类
*/
#include <iostream>
using namespace std;
const int MAXSIZE=100;
class myString {
public:
	myString();
	myString(const char* init);
	myString(const myString &copy);
	~myString() {
		delete []m_pstr;
	}
public:
	int Length() const {
		return m_ncurlen;
	}
	int Find(myString part);
	//char *GetBuf() const;
	//operator overload
	myString& operator()(int pos, int len);
	bool operator==(const myString cmp_str) const;
	bool operator>(const myString cmp_str) const;
	bool operator<(const myString cmp_str) const;
	myString& operator=(const myString& copy);
	myString& operator+(const myString& add);
	char& operator[](int i);
	friend ostream& operator<<(ostream&, myString&);
	friend istream& operator>>(istream&, myString&);	
private:
	void get_next();//KMP算法辅助数组next	
private:
	int m_ncurlen;
	char *m_pstr;
	int *m_pnext;			
};
