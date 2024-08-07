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
