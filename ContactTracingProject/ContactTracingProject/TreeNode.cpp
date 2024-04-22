#include "TreeNode.h"

// Destructor for TreeNode
TreeNode::~TreeNode() {
    for (auto child : directContactsPtrList) {
        delete child;
    }
}
