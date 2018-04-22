#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_t {
    int left;
    int right;
    int depth;
} Node;

Node* createBinaryTree (Node* bTree, int nLevels) {
    int numberOfNodes = (1 << (nLevels + 1)) - 1;
    int i, j;
    int ref = 0;
    int counter = 0;
    for (i = 0; i < nLevels - 1; i++) {
        for (j = ref; j < ref + (1 << i); j++) {
            bTree[j].left = ++counter;
            bTree[j].right = ++counter;
        }
        ref = ref + (1 << i);
    }
    for (i = ref; i < numberOfNodes; i++) {
        bTree[i].left = -1;
        bTree[i].right = -1;
    }
    return bTree;
}

void calculateDepth_r (Node* bTree, int node, int depth) {
    bTree[node].depth = depth;
    if (bTree[node].left != -1)
        calculateDepth_r(bTree, bTree[node].left, ++depth);
    if (bTree[node].right != -1)
        calculateDepth_r(bTree, bTree[node].right, depth);
}

void calculateDepth (Node* bTree) {
    calculateDepth_r(bTree, 0, 0);
}

int main(int argc, char** argv) {
    Node bTree[63];
    createBinaryTree(bTree, 5);
    calculateDepth(bTree);
    return (EXIT_SUCCESS);
}

