#include <stdio.h>
#include <stdlib.h>

// A binary tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new node in a BST
struct node* insert(struct node* node, int data) {
    if (node == NULL) return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

// Function to check if an array is sorted or not
int isSorted(int arr[], int n) {
    int i;
    for (i = 0; i < n-1; i++) {
        if (arr[i] > arr[i+1])
            return 0;
    }
    return 1;
}

// Function to traverse BST in inorder and store it in an array
void inorderTraversal(struct node* node, int arr[], int* index) {
    if (node == NULL) return;

    inorderTraversal(node->left, arr, index);
    arr[*index] = node->data;
    (*index)++;
    inorderTraversal(node->right, arr, index);
}

// Function to check if the given array is valid for a BST or not
int isValidBST(int arr[], int n) {
    if (n == 0) return 1;

    // Create a new BST and insert all elements of the array
    struct node* root = NULL;
    int i;
    for (i = 0; i < n; i++)
        root = insert(root, arr[i]);

    // Check if the inorder traversal of the BST gives the same array
    int index = 0;
    int inorder[n];
    inorderTraversal(root, inorder, &index);

    return isSorted(inorder, n);
}

// Driver program to test above functions
int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (isValidBST(arr, n))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
