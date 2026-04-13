#include <iostream>
#include <algorithm>
using namespace std;

class avl_node{
public:
    string key, meaning;
    avl_node *left, *right;

    avl_node(string k, string m){
        key = k;
        meaning = m;
        left = right = NULL;
    }
};

class avlTree{
public:
    avl_node *root;

    avlTree(){
        root = NULL;
    }

    int height(avl_node *node){
        if (node == NULL)
            return 0;

        return max(height(node->left), height(node->right)) + 1;
    }

    int diff(avl_node *node){
        return height(node->left) - height(node->right);
    }

    avl_node *ll_rotation(avl_node *parent){
        avl_node *temp = parent->left;
        parent->left = temp->right;
        temp->right = parent;
        return temp;
    }

    avl_node *rr_rotation(avl_node *parent){
        avl_node *temp = parent->right;
        parent->right = temp->left;
        temp->left = parent;
        return temp;
    }

    avl_node *lr_rotation(avl_node *parent){
        parent->left = rr_rotation(parent->left);
        return ll_rotation(parent);
    }

    avl_node *rl_rotation(avl_node *parent){
        parent->right = ll_rotation(parent->right);
        return rr_rotation(parent);
    }

    avl_node *balance(avl_node *node){
        int bf = diff(node);

        if (bf > 1)
        {
            if (diff(node->left) > 0)
                node = ll_rotation(node);
            else
                node = lr_rotation(node);
        }
        else if (bf < -1)
        {
            if (diff(node->right) < 0)
                node = rr_rotation(node);
            else
                node = rl_rotation(node);
        }

        return node;
    }

    avl_node *insert(avl_node *node, string key, string meaning){
        if (node == NULL)
            return new avl_node(key, meaning);

        if (key < node->key)
            node->left = insert(node->left, key, meaning);
        else if (key > node->key)
            node->right = insert(node->right, key, meaning);
        else
        {
            node->meaning = meaning;
            return node;
        }

        return balance(node);
    }

    void inorder(avl_node *node)
    {
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->key << " : " << node->meaning << endl;
        inorder(node->right);
    }

    void preorder(avl_node *node)
    {
        if (node == NULL)
            return;

        cout << node->key << " : " << node->meaning << endl;
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(avl_node *node)
    {
        if (node == NULL)
            return;

        postorder(node->left);
        postorder(node->right);
        cout << node->key << " : " << node->meaning << endl;
    }

};

int main()
{
    avlTree tree;
    int choice;
    string key, meaning;

    do
    {
        cout << "\nAVL Dictionary Menu\n";
        cout << "1. Insert Keyword\n";
        cout << "2. Update Meaning\n";
        cout << "3. Display (All Traversals)\n";
        cout << "4. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter keyword: ";
            cin >> key;
            cout << "Enter meaning: ";
            cin.ignore();
            getline(cin, meaning);
            tree.root = tree.insert(tree.root, key, meaning);
            break;

        case 2:
            cout << "Enter keyword to update: ";
            cin >> key;
            cout << "Enter new meaning: ";
            cin.ignore();
            getline(cin, meaning);
            tree.root = tree.insert(tree.root, key, meaning);
            break;

        case 3:
            cout << "\nInorder Traversal:\n";
            tree.inorder(tree.root);

            cout << "\nPreorder Traversal:\n";
            tree.preorder(tree.root);

            cout << "\nPostorder Traversal:\n";
            tree.postorder(tree.root);
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}