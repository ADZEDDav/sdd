#include <stdlib.h>

#include "tree.h"
#include "./../list/list.h"
#include "./../queue/queue.h"
#include "./../stack/stack.h"

// TODO: Implement
static TreeNode *create_node(void *data) {
    TreeNode *node = malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node; 
}

Tree *tree_create() {
    Tree *tree = malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

static void destroy_nodes(TreeNode *node) {
    if (!node) return;
    destroy_nodes(node->left);
    destroy_nodes(node->right);
    free(node);
}

void tree_destroy(Tree *tree) {
    if (!tree) return;
    destroy_nodes(tree->root);
    free(tree);
}
void tree_insert(Tree *tree, void *data, int (*cmp)(void*, void *)) {
    if (!tree->root) {
        tree->root = create_node(data);
        return;
    }
    
    TreeNode *current = tree->root;

    while (1) {
        int c = cmp(data, current->data);

        if (c < 0) {
            if (!current->left) {
                current->left = create_node(data);
                return;
            }
            current = current->left;
        }
        else {
            if (!current->right) {
                current->right = create_node(data);
                return;
            }
            current = current->right;
        }
    } 
}

TreeNode *tree_search(Tree *tree, void *data, int (*cmp)(void *, void *)) {
    TreeNode *current = tree->root;

    while (current) {
        int c = cmp(data, current->data);

        if (c == 0)
            return current;
        else if(c < 0)
            current = current->left;
        else 
            current = current->right;

    }
    return NULL;
}

List *tree_bfs(Tree *tree) {
    List *list = list_create();
    if (!tree->root) return list;

    Queue *q = queue_create();
    queue_enqueue(q, tree->root);

    while (queue_size(q) > 0) {
        TreeNode *node = queue_dequeue(q);
        list_append(list, node->data);

        if (node->left)
            queue_enqueue(q, node->left);
        if (node->right)
             queue_enqueue(q, node->right);
    }

    return list;
    
}

List *tree_dfs(Tree *tree) {
    List *list = list_create();
    if (!tree->root) return list;

    Stack *s = stack_create();
    stack_push(s, tree->root);

    while (stack_size(s) > 0) {
        TreeNode *node = stack_pop(s);
        list_append(list, node->data);

        // Push right first so left is processed first
        if (node->right)
            stack_push(s, node->right);

        if (node->left)
           stack_push(s, node->left);
    }

    return list;

    
}