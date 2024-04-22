#pragma once
#ifndef TREENODE_H
#define TREENODE_H

#include <string>
#include <vector>

typedef std::string String;

class TreeNode {
public:
    String medicareId; // Unique identifier, cannot be duplicated
    int directContacts = 0; // Number of children this node has
    int totalCases = 1; // Total number of cases in the subtree including this node
    TreeNode* parentPtr; // Pointer to the parent node
    std::vector<TreeNode*> directContactsPtrList; // List of pointers to child nodes

    // Constructors
    TreeNode(const String& medId) : medicareId(medId), parentPtr(nullptr) {}
    TreeNode(TreeNode* parentPtr, const String& medId) : medicareId(medId), parentPtr(parentPtr) {}

    // Destructor
    ~TreeNode();
};

#endif // TREENODE_H
