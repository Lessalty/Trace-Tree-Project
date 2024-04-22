#pragma once
#ifndef CONTACTTREE_H
#define CONTACTTREE_H

#include "TreeNode.h"

class ContactTree {
private:
    TreeNode* root; // Pointer to the root of the tree
    int size; // Number of nodes in the tree

public:
    // Constructor and Destructor
    ContactTree() : root(nullptr), size(0) {}
    ~ContactTree();

    // Member functions
    bool IsEmpty() const;
    int GetSize() const;
    void AddPatient0(const String& medicareId);
    void AddContact(const String& parentMedicareId, const String& childMedicareId);
    TreeNode* LookUpContact(const String& medicareId);
    void DeleteContact(const String& medicareId);
    void DisplayContact(const String& medicareId);
    void DisplayContact(TreeNode* node);
    void TraceSource(const String& medicareId);
    void PrintContactCases(const String& medicareId);
    void PrintContactTree();
    void PrintHierarchicalTree();

private:
    // Helper functions
    void DeleteSubTree(TreeNode* subtreeRoot);
    void DisplaySubTree(TreeNode* node, int level); // Used for hierarchical display
};

#endif // CONTACTTREE_H
