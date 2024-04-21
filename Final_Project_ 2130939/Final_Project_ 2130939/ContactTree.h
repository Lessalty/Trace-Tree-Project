#ifndef CONTACTTREE_H
#define CONTACTTREE_H

#include "TreeNode.h"
using namespace std;

class ContactTree {
private:
    TreeNode* root;
    void deleteSubtree(TreeNode* node);

public:
    ContactTree();
    ~ContactTree();
    void AddPatientZero(const string& id);
    bool AddContact(const string& parentId, const string& childId);
    void PrintContactTree();
    TreeNode* LookUpContact(const string& id);
};

#endif // CONTACTTREE_H
