#include <iostream>
using namespace std;

struct BSTnode
{
    int data;
    struct BSTnode *left;
    struct BSTnode *right;
};

BSTnode *insert(BSTnode *node, int inpData)
{
    if (node == NULL)
    {
        struct BSTnode *ptr = new BSTnode;
        ptr->data = inpData;
        ptr->left = ptr->right = NULL;
        return ptr;
    }
    else if (inpData < node->data)
    {
        node->left = insert(node->left, inpData);
    }
    else
    {
        node->right = insert(node->right, inpData);
    }
    return node;
}

void preorder(BSTnode *node)
{
    if (node != NULL)
    {
        cout << node->data << " " << endl;
        preorder(node->left);
        preorder(node->right);
    }
}

void inorder(BSTnode *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        cout << node->data << " " << endl;
        inorder(node->right);
    }
}

void posorder(BSTnode *node)
{
    if (node != NULL)
    {
        posorder(node->left);
        posorder(node->right);
        cout << node->data << " " << endl;
    }
}

void search(BSTnode *node, int searchData)
{
    if (node == NULL)
    {
        cout << "Data is not found" << endl;
    }
    else if (node->data == searchData)
    {
        cout << "Tree is found";
    }
    else if (node->data < searchData)
    {
        search(node->left, searchData);
    }
    else
    {
        search(node->right, searchData);
    }
}

BSTnode *finMin(BSTnode *node)
{
    while (node->left != NULL)
    {
       node = node->left;
    }
    return node;
    
}

int main()
{

    BSTnode *root = NULL;
    int inpData;
    cout << "Tree is initially empty, Insert a value: ";
    cin >> inpData;
    root = insert(root, inpData);
    cout << "Press 1 to Insert, 2 to Traversal, 0 to Exit" << endl;
    int select;
    cin >> select;

    while (select != 0)
    {
        if (select == 1)
        {
            cout << "Insert the value: ";
            cin >> inpData;
            insert(root, inpData);
        }
        else if (select == 2)
        {
            string trav;
            cout << "Press 'in' for inorder traversal\nPress Press 'pre' for preorder traversal\nPress 'pos' for postoder traversal\n'in' 'pre' o 'pos': ";
            cin >> trav;
            if (trav == "in")
            {
                inorder(root);
            }
            else if (trav == "pre")
            {
                preorder(root);
            }
            else if (trav == "pos")
            {
                posorder(root);
            }
        }
        else if (select == 3)
        {
            int searchData;
            cout << "search the value: ";
            cin >> searchData;
            search(root, searchData);
        }else if (select == 4)
        {
            BSTnode *temp;
            temp = finMin(root);
            cout<<"Min value is "<<temp->data<<endl;
        }
        cout << "Press 1 to Insert, 2 to Traversal, 0 to Exit" << endl;
        cin >> select;
    }

    return 0;
}