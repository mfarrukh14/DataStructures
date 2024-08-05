<<<<<<< HEAD
#include <iostream>
#include <memory>
#include <string>

// A template class for the tree node
template <typename T>
class TreeNode {
public:
    T value;
    std::shared_ptr<TreeNode<T>> left;
    std::shared_ptr<TreeNode<T>> right;

    TreeNode(T val) : value(val), left(nullptr), right(nullptr) {}
};

// A template class for the binary tree
template <typename T>
class BinaryTree {
public:
    std::shared_ptr<TreeNode<T>> root;

    BinaryTree() : root(nullptr) {}

    void insert(const T& val) {
        if (root == nullptr) {
            root = std::make_shared<TreeNode<T>>(val);
        } else {
            insertHelper(root, val);
        }
    }

    void inorder() const {
        inorderHelper(root);
    }

private:
    void insertHelper(std::shared_ptr<TreeNode<T>> node, const T& val) {
        if (val < node->value) {
            if (node->left == nullptr) {
                node->left = std::make_shared<TreeNode<T>>(val);
            } else {
                insertHelper(node->left, val);
            }
        } else {
            if (node->right == nullptr) {
                node->right = std::make_shared<TreeNode<T>>(val);
            } else {
                insertHelper(node->right, val);
            }
        }
    }

    void inorderHelper(std::shared_ptr<TreeNode<T>> node) const {
        if (node != nullptr) {
            inorderHelper(node->left);
            std::cout << node->value << " ";
            inorderHelper(node->right);
        }
    }
};

// Define a sample user class
class User {
public:
    std::string name;
    int age;

    User(std::string n, int a) : name(n), age(a) {}

    bool operator<(const User& other) const {
        return age < other.age;
    }

    bool operator>(const User& other) const {
        return age > other.age;
    }

    friend std::ostream& operator<<(std::ostream& os, const User& user) {
        os << "User(Name: " << user.name << ", Age: " << user.age << ")";
        return os;
    }
};

int main() {
    BinaryTree<int> intTree;
    intTree.insert(10);
    intTree.insert(5);
    intTree.insert(15);
    intTree.insert(3);
    intTree.insert(7);

    std::cout << "Inorder traversal of int tree: ";
    intTree.inorder();
    std::cout << std::endl;

    BinaryTree<std::string> stringTree;
    stringTree.insert("apple");
    stringTree.insert("banana");
    stringTree.insert("cherry");
    stringTree.insert("date");
    stringTree.insert("fig");

    std::cout << "Inorder traversal of string tree: ";
    stringTree.inorder();
    std::cout << std::endl;

    BinaryTree<User> userTree;
    userTree.insert(User("Alice", 30));
    userTree.insert(User("Bob", 25));
    userTree.insert(User("Charlie", 35));
    userTree.insert(User("David", 20));
    userTree.insert(User("Eve", 40));

    std::cout << "Inorder traversal of user tree: ";
    userTree.inorder();
    std::cout << std::endl;

    return 0;
}
=======
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
>>>>>>> bf2230de0cc880b3e96847fd0f9b23c2532cae0f
