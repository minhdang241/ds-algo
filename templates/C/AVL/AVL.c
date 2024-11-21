#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define SELF_BALANCE

struct Node {
    long value;
    struct Node *left;
    struct Node *right;
    long height;
};

typedef struct Node *NodePtr;

void insert(NodePtr *root, long value);
void delete(NodePtr *root, long value);
void inorder_traverse(NodePtr root);
NodePtr search(NodePtr *root, long value);
static long compute_bfactor(NodePtr node);
int main(void) {
    long nums[] = {10, 20, 30, 40};
    NodePtr root = NULL;
    int size = sizeof(nums) / sizeof(long);
    for (int i = 0; i < size; i++) {
        insert(&root, nums[i]);
    }
    printf("b_factor: %ld \n", compute_bfactor(root));
    inorder_traverse(root);
    return 0;
}

static NodePtr create_node(long value, NodePtr left, NodePtr right) {
    NodePtr node = malloc(sizeof(struct Node));
    node->value = value;
    node->left = left;
    node->right = right;
    node->height = 1;
    return node;
}
static long max(long a, long b) {
    if (a > b)
        return a;
    else
        return b;
}
static void update_height(NodePtr node) {
    if (node == NULL)
        return;
    long height = 0;
    if (node->left != NULL) {
        height = max(height, node->left->height);
    }
    if (node->right != NULL) {
        height = max(height, node->right->height);
    }
    node->height = height + 1;
}
static long compute_bfactor(NodePtr node) {
    if (node == NULL)
        return 0;
    long result = 0;
    if (node->left != NULL) {
        result += node->left->height;
    }
    if (node->right != NULL) {
        result -= node->right->height;
    }
    return result;
}
#ifdef SELF_BALANCE
static void rotate_left(NodePtr *root) {
    NodePtr curr = *root;
    NodePtr right_child = curr->right;
    NodePtr right_child_left = right_child->left;
    right_child->left = curr;
    curr->right = right_child_left;
    update_height(right_child);
    update_height(curr);
    *root = right_child;
}
static void rotate_right(NodePtr *root) {
    NodePtr curr = *root;
    NodePtr left_child = curr->left;
    NodePtr left_child_right = left_child->right;
    left_child->right = curr;
    curr->left = left_child_right;
    update_height(left_child);
    update_height(curr);
    *root = left_child;
}

static void self_balancing(NodePtr *root) {
    NodePtr curr = *root;
    if (curr == NULL)
        return;
    long b_factor = compute_bfactor(curr);
    if (b_factor > 1 && compute_bfactor(curr->left) >= 0) {
        // LEFT-LEFT / BALANCE
        rotate_right(root);
    } else if (b_factor > 1 && compute_bfactor(curr->left) < 0) {
        //LEFT-RIGHT
        rotate_left(&(curr->left));
        rotate_right(root);
    } else if (b_factor < -1 && compute_bfactor(curr->right) <= 0) {
        // RIGHT - RIGHT / BALANCE
        rotate_left(root);
    } else if (b_factor < -1 && compute_bfactor(curr->right) > 0) {
        // RIGHT - LEFT
        rotate_right(&(curr->right));
        rotate_left(root);
    }
}
#endif

void insert(NodePtr *root, long value) {
    NodePtr curr = *root;
    if (curr == NULL) {
        NodePtr new_node = create_node(value, NULL, NULL);
        *root = new_node;
    } else {
        if (value < curr->value) {
            insert(&(curr->left), value);
        } else if (value > curr->value) {
            insert(&(curr->right), value);
        } else {
            // Atm, we assume that the node values are distinct
        }
    }
    update_height(curr);
#ifdef SELF_BALANCE
    self_balancing(root);
#endif
}

void inorder_traverse(NodePtr root) {
    if (root == NULL) {
        return;
    }
    inorder_traverse(root->left);
    printf("%ld ", root->value);
    inorder_traverse(root->right);
}
