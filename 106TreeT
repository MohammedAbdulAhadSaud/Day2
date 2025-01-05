#include <stdio.h>
#include <stdlib.h>

struct node {
    int item;
    struct node* left;
    struct node* right;
};


struct node* createNode(int value);
struct node* insertNode(struct node* root, int value);
void inorderTraversal(struct node* root);
void preorderTraversal(struct node* root);
void postorderTraversal(struct node* root);


struct node* createNode(int value) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct node* insertNode(struct node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    char direction;
    printf("Insert %d to the left or right of %d? (l/r): ", value, root->item);
    scanf(" %c", &direction);
    if (direction == 'l' || direction == 'L') {
        root->left = insertNode(root->left, value);
    } else if (direction == 'r' || direction == 'R') {
        root->right = insertNode(root->right, value);
    } else {
        printf("Invalid input! Node not inserted.\n");
    }
    return root;
}

// Inorder 
void inorderTraversal(struct node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d -> ", root->item);
    inorderTraversal(root->right);
}

// Preorder 
void preorderTraversal(struct node* root) {
    if (root == NULL) return;
    printf("%d -> ", root->item);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Postorder 
void postorderTraversal(struct node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d -> ", root->item);
}

int main() {
    struct node* root = NULL;
    int choice, value;

    printf("Binary Tree Operations\n");
    printf("1. Insert Node\n");
    printf("2. Inorder Traversal\n");
    printf("3. Preorder Traversal\n");
    printf("4. Postorder Traversal\n");
    printf("5. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            if (root == NULL) {
                root = createNode(value);
            } else {
                insertNode(root, value);
            }
            break;
        case 2:
            printf("Inorder traversal: ");
            inorderTraversal(root);
            printf("\n");
            break;
        case 3:
            printf("Preorder traversal: ");
            preorderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("Postorder traversal: ");
            postorderTraversal(root);
            printf("\n");
            break;
        case 5:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
