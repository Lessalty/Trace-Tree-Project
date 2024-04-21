// TreeNode.h
#ifndef TREENODE_H
#define TREENODE_H

#include <string>
#include <list>
using namespace std;

class TreeNode {
public:
    string medicareId;
    TreeNode* parentPtr;
    int directContacts;
    int totalCases;
    list<TreeNode*> directContactsPtrList;

    // Constructor for the root node
    TreeNode(const string& id);

    // Constructor for child nodes
    TreeNode(TreeNode* parent, const string& id);
};

#endif // TREENODE_H
