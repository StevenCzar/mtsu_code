/*Author: Steven Czarnecki
  Course: CSCI 3080

  Lab number: Lab 5
  Purpose: Tree array representation traversials
  Due date: 11/18/2019
  */

#include <iostream>
#include <iomanip>
using namespace std;

//prototypes gotta have the 3 there or it doesn't work cause c++ yay
void preorder(int tree[][3], int root);
void inorder(int tree[][3], int root);
void postorder(int tree[][3], int root);

int main()
{
	//declare things
	int tree[10][3];
	int nodes, i, j;

	//input stuff
	cout << "Please input the number of nodes: ";
	cin >> nodes;
	cout << "Please input the tree array representation of the graph: \n";
	for(i=0; i<nodes; i++)
	{
		for(j=0; j<3; j++)
		{
			//fun nested for-loop to fill array
			cin >> tree[i][j];
		}
	}

	//print stuff and run traversals
	cout << "\nThe preorder traversal is: \n";
	preorder(tree, 0);
	cout << "\n The inorder traversal is: \n";
	inorder(tree, 0);
	cout << "\n the postorder traversal is: \n";
	postorder(tree, 0);
	cout << endl;

	return 0;
}

//root, left, middle, right
//preorder function prints whatever it's on, then checks left->middle->right
void preorder(int tree[][3], int root)
{
	cout << root+1 << " ";
	if(tree[root][0]!=0)
	{
		preorder(tree, (tree[root][0]-1));
	}
	if(tree[root][1]!=0)
	{
		preorder(tree, (tree[root][1]-1));
	}
	if(tree[root][2]!=0)
	{
		preorder(tree, (tree[root][2]-1));
	}
	return;
}

//left, root, middle, right
//inorder function checks left, prints if nothing there, then checks middle->right
void inorder(int tree[][3], int root)
{
	if(tree[root][0]!=0)
	{
		inorder(tree, (tree[root][0])-1);
	}
	cout << root+1 << " ";
	if(tree[root][1]!=0)
	{
		inorder(tree, (tree[root][1])-1);
	}
	if(tree[root][2]!=0)
	{
		inorder(tree, (tree[root][2])-1);
	}
	return;
}

//left, middle, right, root
//postorder checks if anything is a child, if not, prints current node
void postorder(int tree[][3], int root)
{
	if(tree[root][0]!=0)
	{
		postorder(tree,(tree[root][0])-1);
	}
	if(tree[root][1]!=0)
	{
		postorder(tree,(tree[root][1])-1);
	}
	if(tree[root][2]!=0)
	{
		postorder(tree,(tree[root][2])-1);
	}
	cout << root+1 << " ";
}