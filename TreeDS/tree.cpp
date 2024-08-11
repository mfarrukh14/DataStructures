#include<iostream>
#include<memory>
#include<string>

using namespace std;

template<typename T>
class TreeNode
{
public:

    T value;
    shared_ptr<TreeNode<T>> left;
    shared_ptr<TreeNode<T>> right;

    TreeNode(T val): value(val), left(nullptr), right(nullptr) {}
};


template<typename T>

class BinaryTree
{
private:
shared_ptr<TreeNode<T>> root;

void insertHelper(shared_ptr<TreeNode<T>> node, const T& val)
{
    if(!root) root = make_shared<TreeNode<T>>(val);

    else if(val < node->value)
    {
        if(node->left == nullptr)
        {
            node->left = make_shared<TreeNode<T>>(val);
        }
        else insertHelper(node->left, val);
    }

    else if(val >= node->value)
    {
        if(node->right == nullptr) node->right = make_shared<TreeNode<T>>(val);
        else insertHelper(node->right, val);
    }

}

shared_ptr<TreeNode<T>> findMin(shared_ptr<TreeNode<T>> node)
{
    while(node != nullptr)
    {
        node = node->left;
    }
    return node;
}

shared_ptr<TreeNode<T>> removeHelper(shared_ptr<TreeNode<T>> node, const T& val)
{
    if(!node)
    {
        return node;
    }

    if(val < node->value)

    {
        removeHelper(node->left, val);
    }

    if(val > node->value)
    {
        insertHelper(node->right, val);
    }
    else{
        if(node->left == nullptr) return node->right;
        else if(node->right == nullptr) return node->left;

        node->value = findMin(node->right)->value;
        node->right = removeHelper(node->right, node->value);
    }
    return node;
}

void inOrderHelper(shared_ptr<TreeNode<T>> node)
{
    if(!root)
    {
        cout << "\nTree empty\n";
        return;
    }
    if(node != nullptr)
    {
        inOrderHelper(node->left);
        cout << node->value << " ";
        inOrderHelper(node->right);
    }
}

public:

BinaryTree(): root(nullptr){}

void insert(const T& val)
{
    insertHelper(root, val);
}

void remove(const T& val)
{
    root = removeHelper(root, val);
}

void inOrder()
{
    inOrderHelper(root);
}

void clear()
{
    root.reset();
}

};


int main()
{

    BinaryTree<string> b1;

    b1.insert("Farrukh");
    b1.insert("Naveed");
    b1.insert("Homera");

    b1.inOrder();

    cout << "\n";

    b1.remove("Farrukh");
    b1.remove("Naveed");
    b1.remove("Homera");

    //b1.insert("1");

    b1.inOrder();



    return 0;
}