#include <iostream>
using namespace std;

struct node {
    int item;
    node* left;
    node* right;
};

class BinarySearchTree {
private:
    node* root;
public:
    BinarySearchTree() {
        root = nullptr; 
    }
    node* getroot() {
        return root;
    }
    node* createNode(int data) {
        node* newNode = new node;
        newNode->item = data;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    void insertToTree(int item) {
        root = insert(root, item);
    }
    node* insert(node* currentNode, int item) {
        if (currentNode == nullptr) {
            return createNode(item);
        }

        if (item <= currentNode->item) {
            currentNode->left = insert(currentNode->left, item);
        }
        else {
            currentNode->right = insert(currentNode->right, item);
        }
        return currentNode;
    }
    node* search(int element) {
        node* temp = root;
        while (temp != nullptr) {
            if (temp->item == element) {
                return temp;
            }
            else if (temp->item < element) {
                temp = temp->right; 
            }
            else { 
                temp = temp->left;
            }
        }
        return nullptr; 
    }
    void deleteByCopying(int element) {
        root = deleteRecursive(root, element);
    }

    node* deleteRecursive(node* currentNode, int element) {
        if (currentNode == nullptr) {
            return currentNode;
        }
        if (element < currentNode->item) {
            currentNode->left = deleteRecursive(currentNode->left, element);
        }
        else if (element > currentNode->item) {
            currentNode->right = deleteRecursive(currentNode->right, element);
        }
        else {
            if (currentNode->left == nullptr) {
                node* temp = currentNode->right;
                delete currentNode;
                return temp;
            }
            else if (currentNode->right == nullptr) {
                node* temp = currentNode->left;
                delete currentNode;
                return temp;
            }
            node* temp = minNode(currentNode->right);
            currentNode->item = temp->item;
            currentNode->right = deleteRecursive(currentNode->right, temp->item);
        }
        return currentNode;
    }
    node* minNode(node* currentNode) {
        node* current = currentNode;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }
    void preorder(node* root) {
        if (root != nullptr) {
            cout << root->item;
            preorder(root->left);
            preorder(root->right);
           
        }
    }
    void inorder(node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->item;
            inorder(root->right);
           
        }
    }
    void postorder(node* root) {
        if (root != nullptr) {
            postorder(root->left);
            postorder(root->right);
            cout << root->item;
         
        }
    }
};
int main()
{
    BinarySearchTree tree;
    tree.insertToTree(5);
    tree.insertToTree(3);
    tree.insertToTree(7);
    tree.deleteByCopying(7);
    if (tree.search(7) == nullptr) {
        cout << "not found ";
    }
}

