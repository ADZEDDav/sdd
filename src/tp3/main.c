#include <stdio.h>

#include "./../../lib/list/list.h"
#include "./../../lib/tree/tree.h"

int int_cmp(void *a, void *b){
    int x = (int)a;
    int y = (int)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0; 
}

int main()
{
    // TODO: Implement
    Tree *tree = tree_create();
    
    // Insertion de quelques valeurs
    tree_insert(tree, (void*)5, int_cmp);
    tree_insert(tree, (void*)3, int_cmp);
    tree_insert(tree, (void*)7, int_cmp);
    tree_insert(tree, (void*)2, int_cmp);
    tree_insert(tree, (void*)4, int_cmp);
    tree_insert(tree, (void*)6, int_cmp);
    tree_insert(tree, (void*)8, int_cmp);

    // BFS
    printf("BFS: ");
    List *bfs_list = tree_bfs(tree);
    for (int i = 0; i < list_size(bfs_list); i++){
        printf("%d", (int)list_get(bfs_list, i));
    }

    printf("\n");
    
    // DFS 
    printf("DFS : ");
    List *dfs_list = tree_dfs(tree);
    for (int i = 0; i < list_size(dfs_list); i++) {
        printf("%d ", (int)list_get(dfs_list, i));
    }
    printf("\n");

    // Nettoyage
    tree_destroy(tree);

    return 0;
}
