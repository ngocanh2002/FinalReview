#include <iostream>
using namespace std;
struct node {
	int key;
	struct node* left;
	struct node* right;
};
typedef struct node Node;

Node* FindMin(Node* root) {
	while (root->left != NULL)
		root = root->left;
	return root;
}

Node* Insert(Node* root, int data) {
	if (root == NULL) {
		root = new Node;
		root->key = data;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		if (data <= root->key)
			root->left = Insert(root->left, data);
		if (data > root->key)
			root->right = Insert(root->right, data);
	}
	return root;
}
Node* Delete(Node* root, int data)
{
	if (root == NULL)
		return root;
	else
	{
		if (data < root->key)
			root->left = Delete(root->left, data);
		if (data > root->key)
			root->right = Delete(root->right, data);
		if (data == root->key)
		{
			//case 1: No Child
			if (root->left == NULL && root->right == NULL)
			{
				delete root;
				root = NULL;
			}
			//case 2: 1 Child
			else if (root->left == NULL)
			{
				Node* temp = root;
				root = root->right;
				delete temp;
			}
			else if (root->right == NULL)
			{
				Node* temp = root;
				root = root->left;
				delete temp;
			}
			else
			{
				Node* temp = FindMin(root->right);
				root->key = temp->key;
				root->right = Delete(root->right, temp->key);
			}


		}
	}
	return root;
}
Node* Search(Node* root, int data)
{
	if (root == NULL) {
		cout << "Element not exists!" << endl;
		return NULL;
	}
	else if (data == root->key)  cout << "Elenment exists!" << endl;
	else if (data < root->key) return Search(root->left, data);
	else  return Search(root->right, data);
}

void NLR(Node* root)
{
	if (root == NULL)
		return;
	else
	{
		cout << root->key << " ";
		NLR(root->left);
		NLR(root->right);
	}
}

int main()
{
	Node* tree = NULL;
	int n,x;
	cout << "Enter the number of elements: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "\nEnter the element: ";
		cin >> x;
		tree = Insert(tree, x);
	}
	cout << "Traverse Node_Left_Right: "<<endl;
	NLR(tree);
	int a;
	cout << "\nFind" << " "; cin >> a;
	Search(tree, a);
	int b;
	cout << "\nDelete node: ";  cin >> b;
	Delete(tree, b);
	NLR(tree);
	cout << endl;
	
	return 0;
}