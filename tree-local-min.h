//
// Created by zl on 2016/9/26.
//

#ifndef WORKSPACE_TREE_LOCAL_MIN_H
#define WORKSPACE_TREE_LOCAL_MIN_H

typedef struct tagNode {
    int val;
    struct tagNode *left;
    struct tagNode *right;
} Node;
typedef Node Tree;

int findTreeLocalMin(Tree *tree);

#endif //WORKSPACE_TREE_LOCAL_MIN_H
