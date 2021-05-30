//============================================================
// Assignment- 06
// Name- Raisa Zaman
// Date- 3/01/2020
// Last edited- 11:48 PM
// Title: Assignment 06: Implementing a Binary Search Tree
// Description:
//    This C++ console application loads numbers and adds it to a tree, and runs functions on the tree to answer 1. How many nodes were in your search tree?//
//2. Print the entire tree.
//3. What is the smallest element in the tree ?
//4. What is the largest element in the tree ?
//5. What is the height of the tree ?
//6. What is the height of the left sub - tree ?
//7. What is the height of the right sub - tree ?
//8. Check an element in the BST ?
//9. How many nodes are in level "N" of the tree ?
//10. Print the smallest value in the tree.
//11. Print the largest value in the tree.
//12. Destroy the treeand put the memory back to the pool.
//
//==========================================================

#include <conio.h> // For function getch()
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include <stack> // stack library 

using namespace std;

struct MyTree
{
	int element;
	MyTree* left;
	MyTree* right;
};

class TreeClass
{
public:
	TreeClass();
	void insertFirst(int numOne);
	MyTree* getRoot()const;
	bool treeIsEmpty()const; 
	void insert(MyTree* leaf, int  newNum);
	bool treeContains(MyTree* node, int& key)const;
	int treeHeight(MyTree* hightNode);
	int treeHeightL(MyTree* hightLnode);
	int treeHeightR(MyTree* hightRnode);
	int treeCountNodes(MyTree* countNode); 
	void treePrint(MyTree* printNode)const;
	int treeFindMin(MyTree* minNode);
	int treeFindMax(MyTree* maxNode);
	int LevelNodeCount(MyTree* node, int start, int level);
	void deleteT(MyTree* deleteNode);


private:
	MyTree* root;
};

TreeClass::TreeClass()
{
	root = NULL; 
}

void TreeClass::insertFirst(int numOne)
{
	root = new MyTree;
	root->element = numOne;
	root->left = NULL;
	root->right = NULL;
}

MyTree* TreeClass::getRoot() const
{
	return root;
}

bool TreeClass::treeIsEmpty() const
{

	if (root == NULL)
	{
		cout << "Tree is empty." << endl << endl;
		return true;
	}
	else
	{
		cout << "Tree is not empty." << endl << endl;
		return false;
	}
}

void TreeClass::insert(MyTree * node, int  newNum)
{
	if (node == NULL)
	{
		insertFirst(newNum);
	}
	else if (node->element > newNum)
	{
		if (node->left != nullptr)
		{
			insert(node->left, newNum);
		}

		else
		{
			node->left = new MyTree;
			node = node->left;
			node->element = newNum;
			node->left = nullptr;
			node->right = nullptr;
		}
	}
	else if (node->element < newNum)
	{
		if (node->right != nullptr)
		{
			insert(node->right, newNum);
		}

		else
		{
			node->right = new MyTree;
			node = node->right;
			node->element = newNum;
			node->left = nullptr;
			node->right = nullptr;
		}
	}
	else
		return;
}


bool TreeClass::treeContains(MyTree* node, int& key) const
{
	if (node == nullptr)
	{
		return false;
	}
	else if (key < node->element)
	{
		return treeContains(node->left, key);
	}
	else if (key > node->element)
	{
		return treeContains(node->right, key);
	}
	else
	{
		return true;
	}
}


int TreeClass::treeHeight(MyTree * heightNode)
{
	if (heightNode == NULL)
	{
		return 0;
	}
	else
	{
		int leftSide = treeHeight(heightNode->left);
		int rightSide = treeHeight(heightNode->right);
		if (leftSide > rightSide)
		{
			return(leftSide +1);
		}
		else
		{
			return(rightSide +1);
		}
	}
}

int TreeClass::treeHeightL(MyTree * heightLnode)
{
	if (heightLnode == NULL)
	{
		return 0;
	}
	else
	{
		int left = treeHeight(heightLnode->left);
		int l = (left) -1;
		return l;
	}
}

int TreeClass::treeHeightR(MyTree * heightRnode)
{
	if (heightRnode == NULL)
	{
		return 0;
	}
	else
	{
		int right = treeHeight(heightRnode->right);
		int r = (right)-1;
		return r;
	}
}

int TreeClass::treeCountNodes(MyTree * countNode)
{
	if (countNode == NULL)
	{
		return 0;
	}
	else
	{
		return(treeCountNodes(countNode->left) + 1 + treeCountNodes(countNode->right));
	}
}

void TreeClass::treePrint(MyTree * printNode) const
{
	if (root != NULL)
	{ 
		if (printNode->left != NULL)
		{
			treePrint(printNode->left);
		}
		cout << printNode->element << " ";
		if (printNode->right != NULL)
		{
		treePrint(printNode->right);
		}
	}
	else
	{
		cout << "Tree was deleted." << endl;
	}
}

int TreeClass::treeFindMin(MyTree * minNode)
{
	if (minNode == NULL)
	{
		return NULL;
	}
	while (minNode->left != NULL)
	{
		minNode = minNode->left;
	}
	return minNode ->element;
}

int TreeClass::treeFindMax(MyTree * maxNode)
{
	if (maxNode == NULL)
	{
		return NULL;
	}
	while (maxNode->right != NULL)
	{
		maxNode = maxNode->right;
	}
	return maxNode->element;
}

int TreeClass::LevelNodeCount(MyTree* node, int start, int level)
{
	if (node == NULL)
	{ 
		return 0;
	}
	else if (start == level)
	{
		return 1;

	}
	else
	{ 
		return LevelNodeCount(node->left, start + 1, level) +
		LevelNodeCount(node->right, start + 1, level);
	}
}

void TreeClass::deleteT(MyTree* deleteNode)
{
	if (deleteNode != NULL)
	{
		deleteT(deleteNode->left);
		deleteT(deleteNode->right);
		delete(deleteNode);
	}
	root = NULL; 
}

int main()
{
	TreeClass theTree;
	ifstream new_file;
	int searchNum;
	new_file.open("BinarySearchTree.data");
	if (!new_file)
	{
		cout << "File BinarySearchTree.data Can't be opened" << endl << endl;
	}

	else
	{
		int num1;
		int num2;
		int num3;
		int num4;
		int num5;
		int num6;
		int num7;
		int num8;
		int num9;
		int num10;
		theTree.treeIsEmpty();
		cout << "File BinarySearchTree.data successfully opened." << endl << endl;
		cout << "Elements are being inserted. " << endl << endl; 
		while (new_file >> num1 >> num2 >> num3 >> num4 >> num5 >> num6 >> num7 >> num8 >> num9 >> num10)
		{
			theTree.insert(theTree.getRoot(), num1);
			theTree.insert(theTree.getRoot(), num2);
			theTree.insert(theTree.getRoot(), num3);
			theTree.insert(theTree.getRoot(), num4);
			theTree.insert(theTree.getRoot(), num5);
			theTree.insert(theTree.getRoot(), num6);
			theTree.insert(theTree.getRoot(), num7);
			theTree.insert(theTree.getRoot(), num8);
			theTree.insert(theTree.getRoot(), num9);
			theTree.insert(theTree.getRoot(), num10);
		}
	
		theTree.treeIsEmpty();
		cout << "Tree height calculated. The height of the tree is: " << theTree.treeHeight(theTree.getRoot()) - 1 << endl << endl;
		cout << "Tree left height calculated. The left side's height of the tree is: " << theTree.treeHeightL(theTree.getRoot()) << endl << endl;
		cout << "Tree right height calculated. The right side's height of the tree is: " << theTree.treeHeightR(theTree.getRoot()) << endl << endl;
		cout << "Tree nodes counted. Number of Nodes: " << theTree.treeCountNodes(theTree.getRoot()) << endl << endl;
		cout << "The tree is being printed. The elements in the tree: ";
		theTree.treePrint(theTree.getRoot());
		cout << endl << endl;
		cout << "Tree min value calculated. The min value of the tree is: " << theTree.treeFindMin(theTree.getRoot()) << endl << endl;
		cout << "Tree max value calculated. The max value of the tree is: " << theTree.treeFindMax(theTree.getRoot()) << endl << endl;
		cout << "What number are you looking for in the tree: ";
		cin >> searchNum;
		if (!theTree.treeContains(theTree.getRoot(), searchNum))
		{
			cout << "Element not found" << endl;
		}

		else
		{
			cout << "Element found" << endl;
		}
		int start = 0;
		int level = 0;
		cout << endl;
		cout << "What level's nodes are you looking for: ";
		cin >> level;
		cout << "There are " << theTree.LevelNodeCount(theTree.getRoot(), start, level) << " nodes on level " << level << "." << endl << endl;
		theTree.deleteT(theTree.getRoot());
		theTree.treePrint(theTree.getRoot());
	}
	new_file.close();
	return 0; 
}

