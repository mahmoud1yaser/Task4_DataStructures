#ifndef MY_TREE_H
#define MY_TREE_H
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

template <class T>
class MyTree {
private:

    struct BstNode{
        int data;
        BstNode* left;
        BstNode* right;
    };
    BstNode* root;
public:

    MyTree() { root = NULL; }

    MyTree(vector<T> elements) {
        root=NULL;
        sort(elements.begin(), elements.end());
        root=InsertVectors(elements, 0, elements.size()-1 );
    }

    BstNode* InsertVectors ( vector <T> v, int start, int end ) {
        if (start> end)
            return NULL;
        int middle = (start+end)/2;
        BstNode* ptr = GetNewNode(v[middle]);
        ptr->left = InsertVectors(v, start, middle-1);
        ptr->right = InsertVectors(v, middle+1, end );
        return ptr;
    }

    BstNode* GetNewNode(T data){
        // BstNode* newNode = (BstNode*) malloc(sizeof(BstNode*));
        BstNode* newNode = new BstNode();
        newNode->data=data;
        newNode->left=newNode->right=NULL;
        return newNode;
    }

    bool Search(T key)
    {
        BstNode* ptr = root;
        while (ptr != NULL) {
            if (key > ptr->data) ptr = ptr->right;
            else if (key < ptr->data) ptr = ptr->left;
            else return true;
        }
        return false;
    }

    void Insert(T key) {
        BstNode* newNode = GetNewNode(key);
        BstNode* ptrX = root;
        BstNode* ptrY = NULL;

        while (ptrX != NULL) {
            ptrY = ptrX;
            if (key < ptrX->data) ptrX = ptrX->left;
            else if (key > ptrX->data) ptrX = ptrX->right;
            else return;
        }
        if (root == NULL) root = newNode;
        else if (key < ptrY->data) ptrY->left = newNode;
        else ptrY->right = newNode;
    }

    int Height(BstNode* node)
    {
        if (node == NULL)
            return 0;
        else {

            int LeftHeight = Height(node->left);
            int RightHeight = Height(node->right);

            if (LeftHeight > RightHeight) {
                return (LeftHeight + 1);
            }
            else {
                return (RightHeight + 1);
            }
        }
    }

    void BreadthTraversal() {
        int h = Height(root);
        int i;
        for (i = 1; i <= h; i++)
            PrintLevel(root, i);
    }


    void PrintLevel(BstNode* ptr, int level)
    {
        if (ptr == NULL)
            return;
        if (level == 1)
            cout << ptr->data << " ";
        else if (level > 1) {
            PrintLevel(ptr->left, level - 1);
            PrintLevel(ptr->right, level - 1);
        }
    }


    void Inorder()
    {
        stack<BstNode*> s1;
        BstNode* current = root;

        while (current != NULL || s1.empty() == false)
        {
            while (current != NULL)
            {
                s1.push(current);
                current = current->left;
            }

            current = s1.top();
            s1.pop();

            cout << current->data << " ";
            current = current->right;

        }
    }

    void Inorder(BstNode* node)
    {
        if (node == NULL)
            return;
        Inorder(node->left);
        cout << node->data << " ";
        Inorder(node->right);
    }

    void InorderRec() {
        Inorder(root);
    }



    void Preorder() {
        BstNode* current = root;
        if (current == nullptr)
            return;
        stack<BstNode*> stack;
        stack.push(current);
        while (!stack.empty())
        {
            BstNode* currentLocal = stack.top();
            stack.pop();
            cout << currentLocal->data << " ";
            if (currentLocal->right) { stack.push(currentLocal->right); }
            if (currentLocal->left) { stack.push(currentLocal->left); }
        }
    }


    void Preorder( BstNode* node) {
        if (node == NULL)
            return;
        cout << node->data << " ";
        Preorder(node->left);
        Preorder(node->right);
    }

    void PreorderRec() {
        Preorder(root);
    }

    void Postorder() {
        BstNode* current  = root;
        if (current  == NULL) {
            return;
        }
        stack<BstNode*> s2;
        s2.push(current);
        stack<int> out;
        while (!s2.empty()) {
            BstNode* curr = s2.top();
            s2.pop();
            out.push(curr->data);
            if (curr->left) {
                s2.push(curr->left);
            }
            if (curr->right) {
                s2.push(curr->right);
            }
        }
        while (!out.empty())
        {
            cout << out.top() << " ";
            out.pop();
        }
    }

    void PostorderRec(BstNode* Node){
        if (Node == NULL)
            return;
        PostorderRec(Node->left);
        PostorderRec(Node->right);
        cout << Node->data << " ";
    }

    void PostorderRec() {
        PostorderRec(root);
    }




    int Size(BstNode* size) {
        if (size == NULL) return 0;
        else return(Size(size->left) + 1 + Size(size->right));
    }
    int Size() {
        return Size(root);
    }



};

#endif