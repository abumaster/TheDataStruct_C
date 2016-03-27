#include <iostream>
using namespace std;
#include "BinaryTree.h"

int main()
{
	BinaryTree<int> tree(-1);
	/*int init[30] = { 17, 6, 22, 29, 14, 0, 21, 13, 27, 18, 2, 28, 8,
	26, 3, 12, 20, 4, 9, 23, 15, 1, 11, 5, 19, 24, 16, 7, 10, 25 };
	for (int i = 0; i < 30; i++)
		tree.Insert(init[i]);*/
	cin >> tree;
	cout << tree << endl;
	cout << "中序遍历：" << endl;
	tree.InOrder();
	cout << "\n先序遍历：" << endl;
	tree.PreOrder();
	cout << "\n后序遍历：" << endl;
	tree.PostOrder();
	cout << endl;

	cout << "The Tree size: " << tree.Size() << endl;
	cout << "The Tree Height: " << tree.Height() << endl;
	cout << "The root is: " << tree.GetRoot()->GetData() << endl;

	BinaryTree<int> tree2 = tree;
	cout << "tree2 is: \n" << tree2 << endl;

	cout << "please input the number you want find: " << endl;
	int intemp;
	cin >> intemp;
	cout << "result: " << (tree2.Find(intemp) ? "yes" : "no") << endl;

	cout << "----------------------------" << endl;
	cout << "the num " << intemp << " parent is: " <<
		tree2.GetParent(tree2.Find(intemp))->GetData() << endl;
	cout << "the num " << intemp << " left is: " <<
		tree2.GetLeft(tree2.Find(intemp))->GetData() << endl;
	cout << "the num " << intemp << " right is: " <<
		tree2.GetRight(tree2.Find(intemp))->GetData() << endl;


	system("pause");

}