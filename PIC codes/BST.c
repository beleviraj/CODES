#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data) {
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int data) {
    if (root == NULL)
        return createnode(data);

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct node *bst() {
    struct node *root = NULL;
    int n, data;
    printf("\nEnter the number of nodes: \n");
    scanf("%d", &n);
    printf("Enter the Elements: ");
    for (int i = 0; i < n; i++) {
        printf("node %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }
    return root;
}

int main() {
    struct node *root = bst();

    printf("\nIn-order traversal is: ");
    inorder(root);
    printf("\n");

    printf("Pre-order traversal is: ");
    preorder(root);
    printf("\n");

    printf("Post-order traversal is: ");
    postorder(root);
    printf("\n");

    return 0;
}

