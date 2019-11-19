/*Author: Steven Czarnecki
  Course: CSCI 3080

  Lab number: Lab 5
  Purpose: Tree array representation traversials
  Due date: 11/18/2019
  */

#include <iostream>
#include <iomanip>
using namespace std;

void preorder(int tree[], int root)
void inorder(int tree[], int root)
void postorder(int tree[], int root)

int main()
{
	int tree[10][3];
	int nodes, i, j;

	cout << "Please input the number of nodes: ";
	cin >> nodes;
	cout << "Please input the tree array representation of the graph: ";
	for(i=0; i<nodes; i++)
	{
		for(j=0; j<3; j++)
		{
			cin >> tree[i][j];
		}
	}

	cout << "\nThe preorder traversal is: \n";
	preorder(tree, 0);
	cout << "\n The inorder traversial is: \n";
	inorder(tree, 0);
	cout << "\n the postorder traversial is: \n";
	postorder(tree, 0);

	return 0;
}

//root, left, middle, right
void preorder(int tree[], int root)
{
	cout << root+1 << " ";
	if(tree[root][0]!=0)
	{
		preorder(tree, tree[root][0]);
	}
	if(tree[root][1]!=0)
	{
		preorder(tree, tree[root][1]);
	}
	if(tree[root][2]!=0)
	{
		preorder(tree, tree[root][2]);
	}
	return;
}

//left, root, middle, right
void inorder(int tree[], int root)
{
	if(tree[root][0]!=0)
	{
		inorder(tree, tree[root][0]);
	}
	cout << root+1 << " ";
	if(tree[root][1]!=0)
	{
		inorder(tree, tree[root][1]);
	}
	if(tree[root][2]!=0)
	{
		inorder(tree, tree[root][2]);
	}
	return;
}

//left, middle, right, root
void postorder(int tree[], int root)
{
	if(tree[root][0]!=0)
	{
		postorder(tree,tree[root][0]);
	}
	if(tree[root][1]!=0)
	{
		postorder(tree,tree[root][1]);
	}
	if(tree[root][2]!=0)
	{
		postorder(tree,tree[root][2]);
	}
	cout << root+1 << " ";
}