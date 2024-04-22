#include "ContactTree.h"
#include <queue>
#include <iostream>

// Destructor for ContactTree
ContactTree::~ContactTree() {
    DeleteSubTree(root);
}

// Check if the tree is empty
bool ContactTree::IsEmpty() const {
    return root == nullptr;
}

// Return the size of the tree
int ContactTree::GetSize() const {
    return size;
}

// Add the initial patient (root node)
void ContactTree::AddPatient0(const String& medicareId) {
    if (root == nullptr) {
        root = new TreeNode(medicareId);
        size = 1;
    }
}

// Add a contact as a child to an existing node
void ContactTree::AddContact(const String& parentMedicareId, const String& childMedicareId) {
    TreeNode* parent = LookUpContact(parentMedicareId);
    if (parent != nullptr) {
        TreeNode* child = new TreeNode(parent, childMedicareId);
        parent->directContactsPtrList.push_back(child);
        parent->directContacts++;

        // Increment total cases for parent and all ancestors
        TreeNode* current = parent;
        while (current != nullptr) {
            current->totalCases++;
            current = current->parentPtr;
        }
        size++;
    }
}

// Find a node by medicareId
TreeNode* ContactTree::LookUpContact(const String& medicareId) {
    if (root == nullptr) return nullptr;

    std::queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
        TreeNode* current = queue.front();
        queue.pop();

        if (current->medicareId == medicareId) return current;

        for (auto child : current->directContactsPtrList) {
            queue.push(child);
        }
    }

    return nullptr;
}

// Delete a contact and its subtree
void ContactTree::DeleteContact(const String& medicareId) {
    TreeNode* node = LookUpContact(medicareId);
    if (node == nullptr) return;

    // Detach from parent if not root
    if (node->parentPtr != nullptr) {
        auto& siblings = node->parentPtr->directContactsPtrList;
        siblings.erase(std::remove(siblings.begin(), siblings.end(), node), siblings.end());
        node->parentPtr->directContacts--;
    }

    DeleteSubTree(node);
    size--;
}

// Recursive helper to delete subtree
void ContactTree::DeleteSubTree(TreeNode* subtreeRoot) {
    for (TreeNode* child : subtreeRoot->directContactsPtrList) {
        DeleteSubTree(child);
    }
    delete subtreeRoot;
}

// Display a single contact
void ContactTree::DisplayContact(const String& medicareId) {
    TreeNode* node = LookUpContact(medicareId);
    if (node != nullptr) {
        DisplayContact(node);
    }
}

// Display node information
void ContactTree::DisplayContact(TreeNode* node) {
    std::cout << "Medicare ID: " << node->medicareId
        << ", Direct Contacts: " << node->directContacts
        << ", Total Cases: " << node->totalCases << std::endl;
}

// Print all nodes from a node to the root
void ContactTree::TraceSource(const String& medicareId) {
    TreeNode* node = LookUpContact(medicareId);
    while (node != nullptr) {
        DisplayContact(node);
        node = node->parentPtr;
    }
}

// Print direct children of a contact
void ContactTree::PrintContactCases(const String& medicareId) {
    TreeNode* node = LookUpContact(medicareId);
    if (node != nullptr) {
        for (TreeNode* child : node->directContactsPtrList) {
            DisplayContact(child);
        }
    }
}

// Breadth First Traversal to print all contacts
void ContactTree::PrintContactTree() {
    if (root == nullptr) return;

    std::queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
        TreeNode* current = queue.front();
        queue.pop();

        DisplayContact(current);

        for (auto child : current->directContactsPtrList) {
            queue.push(child);
        }
    }
}

// Recursive hierarchical display of the tree
void ContactTree::PrintHierarchicalTree() {
    DisplaySubTree(root, 0);
}

// Helper for hierarchical display
void ContactTree::DisplaySubTree(TreeNode* node, int level) {
    if (node == nullptr) return;

    std::string indent(level * 2, ' '); // Create indentation based on the level
    std::cout << indent << node->medicareId << " (" << node->totalCases << ")" << std::endl;

    for (TreeNode* child : node->directContactsPtrList) {
        DisplaySubTree(child, level + 1);
    }
}




void displayMenu() {
    std::cout << "\n--- Contact Tree Menu ---\n";
    std::cout << "1. Add Patient Zero\n";
    std::cout << "2. Add Contact\n";
    std::cout << "3. Display Entire Tree\n";
    std::cout << "4. Display Hierarchical Tree\n";
    std::cout << "5. Trace Source\n";
    std::cout << "6. Print Direct Contacts\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    ContactTree tree;
    int choice;
    std::string id, parentId;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter Medicare ID for Patient Zero: ";
            std::cin >> id;
            tree.AddPatient0(id);
            std::cout << "Patient Zero added.\n";
            break;
        case 2:
            std::cout << "Enter Parent Medicare ID: ";
            std::cin >> parentId;
            std::cout << "Enter Child Medicare ID: ";
            std::cin >> id;
            tree.AddContact(parentId, id);
            std::cout << "Contact added.\n";
            break;
        case 3:
            std::cout << "Contact Tree:\n";
            tree.PrintContactTree();
            break;
        case 4:
            std::cout << "Hierarchical View of Contact Tree:\n";
            tree.PrintHierarchicalTree();
            break;
        case 5:
            std::cout << "Enter Medicare ID to trace source: ";
            std::cin >> id;
            std::cout << "Trace Source for " << id << ":\n";
            tree.TraceSource(id);
            break;
        case 6:
            std::cout << "Enter Medicare ID to print direct contacts: ";
            std::cin >> id;
            std::cout << "Direct Contacts for " << id << ":\n";
            tree.PrintContactCases(id);
            break;
        case 7:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

