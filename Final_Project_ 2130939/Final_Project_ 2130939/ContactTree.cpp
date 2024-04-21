#include "ContactTree.h"
#include <iostream>

ContactTree::ContactTree() : root(nullptr) {}

ContactTree::~ContactTree() {
    deleteSubtree(root);
}

void ContactTree::AddPatientZero(const string& id) {
    if (!root) {
        root = new TreeNode(id);
    }
}

bool ContactTree::AddContact(const string& parentId, const string& childId) {
    TreeNode* parentNode = LookUpContact(parentId);
    if (parentNode) {
        new TreeNode(parentNode, childId);  // Correct usage of the child node constructor
        return true;
    }
    return false;
}

TreeNode* ContactTree::LookUpContact(const string& id) {
    TreeNode* node = root;
    list<TreeNode*> queue;
    queue.push_back(node);

    while (!queue.empty()) {
        node = queue.front();
        queue.pop_front();
        if (node->medicareId == id) {
            return node;
        }
        for (TreeNode* child : node->directContactsPtrList) {
            queue.push_back(child);
        }
    }
    return nullptr;
}

void ContactTree::PrintContactTree() {
    if (!root) {
        cout << "The tree is empty." << endl;
        return;
    }
    list<TreeNode*> queue;
    queue.push_back(root);

    while (!queue.empty()) {
        TreeNode* current = queue.front();
        queue.pop_front();
        cout << current->medicareId << " (" << current->totalCases << " cases)" << endl;
        for (TreeNode* child : current->directContactsPtrList) {
            queue.push_back(child);
        }
    }
}

void ContactTree::deleteSubtree(TreeNode* node) {
    if (node == nullptr) return;
    for (TreeNode* child : node->directContactsPtrList) {
        deleteSubtree(child);
    }
    delete node;
}
