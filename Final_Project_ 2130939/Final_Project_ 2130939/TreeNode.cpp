#include "TreeNode.h"

TreeNode::TreeNode(const string& id)
    : medicareId(id), parentPtr(nullptr), directContacts(0), totalCases(1) {
    // Constructor for root node initializes member variables
}

TreeNode::TreeNode(TreeNode* parent, const string& id)
    : medicareId(id), parentPtr(parent), directContacts(0), totalCases(1) {
    // Constructor for child nodes sets parent and updates parent's list and counts
    parent->directContactsPtrList.push_back(this);
    parent->directContacts++;
    for (TreeNode* current = parent; current != nullptr; current = current->parentPtr) {
        current->totalCases++;
    }
}
