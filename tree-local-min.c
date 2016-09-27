//
// Created by zl on 2016/9/26.
//

#include "tree-local-min.h"

#include "stdlib.h"

int findTreeLocalMin(Tree *tree) {
    if (tree->left == NULL && tree->right == NULL) {
        return tree->val;
    }
    if (tree->left->val > tree->val && tree->right->val > tree->val) {
        return tree->val;
    }
    if (tree->left->val < tree->val) {
        return findTreeLocalMin(tree->left);
    }
    return findTreeLocalMin(tree->right);
}
