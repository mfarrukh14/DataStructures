#include<iostream>

using namespace std;

template<typename T>
class TreeNode
{
public:
	T data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(T val) : data(val), left(nullptr), right(nullptr) {}
};


template<typename T>
class BST
{
private:
	TreeNode<T>* root;

	TreeNode<T>* insertRecord(TreeNode<T>* root, T val)
	{
		if (root == nullptr)
		{
			return new TreeNode<T>(val);
		}

		else if (val < root->data)
		{
			root->left = insertRecord(root->left, val);
		}
		else if (val >= root->data)
		{
			root->right = insertRecord(root->right, val);
		}

		return root;
	}

	TreeNode<T>* deleteRecord(TreeNode<T>* root, T val)
	{
		if (root == nullptr)
		{
			return root;
		}

		else if (val < root->data)
		{
			root->left = deleteRecord(root->left, val);
		}
		else if (val > root->data)
		{
			root->right = deleteRecord(root->right, val);
		}
		else
		{
			if (root->left == nullptr)
			{
				TreeNode<T>* temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr)
			{
				TreeNode<T>* temp = root->right;
				delete root;
				return temp;
			}

			TreeNode<T>* temp = minValueNode(root->right);
			root->data = temp->data;
			root->right = deleteRecord(root->right, temp->data);
		}
		return root;
	}

	TreeNode<T>* minValueNode(TreeNode<T>* node)
	{
		TreeNode<T>* current = node;

		while (current && current->left != nullptr)
		{
			current = current->left;
		}

		return current;
	}

	TreeNode<T>* searchRecord(TreeNode<T>* root, T val)
	{
		if (root == nullptr || root->data == val)
		{
			return root;
		}

		else if (val < root->data)
		{
			return searchRecord(root->left, val);
		}

		return searchRecord(root->right, val);
	}

	void inorderRecord(TreeNode<T>* root)
	{
		if (root != nullptr)
		{
			inorderRecord(root->left);
			cout << root->data << " ";
			inorderRecord(root->right);
		}
	}

public:

	BST() : root(nullptr) {}

	template<typename T>
	void insert(T val)
	{
		root = insertRecord(root, val);
	}
	void deleteNode(T val)
	{
		root = deleteRecord(root, val);
	}
	bool search(T val)
	{
		return searchRecord(root, val) != nullptr;
	}
	void inorder()
	{
		inorderRecord(root);
		cout << endl;
	}
};


int main() {
	BST<int> bst;

	bst.insert(50);
	bst.insert(30);
	bst.insert(20);
	bst.insert(40);
	bst.insert(70);
	bst.insert(60);
	bst.insert(80);

	std::cout << "Inorder traversal of the BST: ";
	bst.inorder();

	std::cout << "Delete 20\n";
	bst.deleteNode(20);
	std::cout << "Inorder traversal of the modified BST: ";
	bst.inorder();

	std::cout << "Search for 30: " << (bst.search(30) ? "Found" : "Not found") << std::endl;
	std::cout << "Search for 100: " << (bst.search(100) ? "Found" : "Not found") << std::endl;

	return 0;
}