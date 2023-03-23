#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

void insert(int d) {
    struct node* temp, *par;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
    par = NULL;
    if (root == NULL)
        root = temp;
    else {
        struct node* curr = root;
        while (curr) {
            par = curr;
            if (temp->data > curr->data)
                curr = curr->right;
            else
                curr = curr->left;
        }
        if (temp->data > par->data)
            par->right = temp;
        else
            par->left = temp;
    }
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node* search(struct node* root, int value) {
    if (root == NULL) {
        printf("Empty");
        return NULL;
    }
    if (root->data == value) {
        printf("Found");
        return root;
    }
    if (root->data > value)
        return search(root->left, value);
    if (root->data < value)
        return search(root->right, value);
    return NULL;
}

int main() {
    int ch, d, value;
    while (1) {
        printf("\nEnter the Choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("\nEnter the data to insert in BST: ");
            scanf("%d", &d);
            insert(d);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            printf("\nEnter the data to search in BST: ");
            scanf("%d", &value);
            search(root, value);
            break;
        }
    }
    return 0;
}
