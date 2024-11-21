#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  long value;
} NodeValue;

struct TreeNode {
  NodeValue node_value;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode *TreeNodePtr;

TreeNodePtr create_node(long value, TreeNodePtr left, TreeNodePtr right);
void insert(TreeNodePtr *root_ptr, long value);
void delete(TreeNodePtr *root_ptr, long value);
TreeNodePtr search(TreeNodePtr root_ptr, long value);
void inorder_traversal(TreeNodePtr root_ptr);

// Internal use
static TreeNodePtr find_min_value_node(TreeNodePtr root_ptr);

int main(void) {
  long nums[] = {50, 20, 10, 30, 40, 70, 60, 100, 90, 80};
  TreeNodePtr root = NULL;
  int size = sizeof(nums) / sizeof(long);
  for (int i = 0; i < size; i++) {
    insert(&root, nums[i]);
  }
  inorder_traversal(root);

  printf("Testing search \n");
  assert(search(root, 90) != NULL);
  assert(search(root, 110) == NULL);

  printf("\n");
  for (int i = 0; i < size; i++) {
    delete (&root, nums[i]);
    inorder_traversal(root);
    printf("\n");
  }

  return 0;
}

TreeNodePtr create_node(long value, TreeNodePtr left, TreeNodePtr right) {
  TreeNodePtr root = malloc(sizeof(struct TreeNode));
  root->node_value.value = value;
  root->left = left;
  root->right = right;
  return root;
}

void insert(TreeNodePtr *root_ptr, long value) {
  TreeNodePtr current = *root_ptr;
  if (current == NULL) {
    TreeNodePtr new_node = create_node(value, NULL, NULL);
    *root_ptr = new_node;
  } else if (value > current->node_value.value) {
    insert(&(current->right), value);
  } else if (value < current->node_value.value) {
    insert(&(current->left), value);
  } else {
    // Atm, we assume node values are distinct
  }
}

static TreeNodePtr find_min_value_node(TreeNodePtr root_ptr) {
  TreeNodePtr curr = root_ptr;
  while ((curr != NULL) && (curr->left != NULL)) {
    curr = curr->left;
  }
  return curr;
}

void delete(TreeNodePtr *root_ptr, long value) {
  TreeNodePtr current = *root_ptr;
  if (current) {
    if (current->node_value.value == value) {
      if (current->left == NULL) {
        *root_ptr = current->right;
        free(current);
      } else if (current->right == NULL) {
        *root_ptr = current->left;
        free(current);
      } else {
        TreeNodePtr min_node = find_min_value_node(current->right);
        NodeValue tmp = min_node->node_value;
        min_node->node_value = current->node_value;
        current->node_value = tmp;
        delete (&(current->right), value);
      }
    } else if (current->node_value.value < value) {
      delete (&(current->right), value);
    } else {
      delete (&(current->left), value);
    }
  }
}

TreeNodePtr search(TreeNodePtr root, long value) {
  if (root == NULL) {
    return NULL;
  }

  if (value == root->node_value.value) {
    return root;
  } else if (value < root->node_value.value) {
    return search(root->left, value);
  } else {
    return search(root->right, value);
  }
}

void inorder_traversal(TreeNodePtr root_ptr) {
  if (root_ptr == NULL) {
    return;
  } else {
    inorder_traversal(root_ptr->left);
    printf("%ld ", root_ptr->node_value.value);
    inorder_traversal(root_ptr->right);
  }
}
