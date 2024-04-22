#include <gtest/gtest.h>
#include "ContactTree.h"

class ContactTreeTest : public ::testing::Test {
protected:
    ContactTree tree;

    void SetUp() override {
        // Set up some initial nodes
        tree.AddPatient0("ID0");
        tree.AddContact("ID0", "ID1");
        tree.AddContact("ID0", "ID2");
        tree.AddContact("ID1", "ID3");
        tree.AddContact("ID2", "ID4");
    }

    void TearDown() override {
        // Cleanup can be handled by the destructor
    }
};

TEST_F(ContactTreeTest, IsEmptyInitially) {
    ContactTree newTree;
    EXPECT_TRUE(newTree.IsEmpty());
}

TEST_F(ContactTreeTest, IsNotEmptyAfterAddingRoot) {
    EXPECT_FALSE(tree.IsEmpty());
}

TEST_F(ContactTreeTest, CorrectSizeAfterInsertions) {
    EXPECT_EQ(5, tree.GetSize());
}

TEST_F(ContactTreeTest, LookupNodeExists) {
    TreeNode* node = tree.LookUpContact("ID1");
    ASSERT_NE(nullptr, node);
    EXPECT_EQ("ID1", node->medicareId);
}

TEST_F(ContactTreeTest, LookupNodeDoesNotExist) {
    TreeNode* node = tree.LookUpContact("NonexistentID");
    EXPECT_EQ(nullptr, node);
}

TEST_F(ContactTreeTest, DeleteNodeReducesSize) {
    tree.DeleteContact("ID3");
    EXPECT_EQ(4, tree.GetSize());
}

TEST_F(ContactTreeTest, DeleteRootClearsTree) {
    tree.DeleteContact("ID0");
    EXPECT_TRUE(tree.IsEmpty());
    EXPECT_EQ(0, tree.GetSize());
}

TEST_F(ContactTreeTest, DisplayContactPrintsCorrectly) {
    testing::internal::CaptureStdout();
    tree.DisplayContact("ID2");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Medicare ID: ID2, Direct Contacts: 1, Total Cases: 2\n", output);
}

// Additional tests for TraceSource, PrintContactCases, and hierarchical prints can be added here

TEST_F(ContactTreeTest, TraceSourcePrintsCorrectly) {
    testing::internal::CaptureStdout();
    tree.TraceSource("ID3");
    std::string output = testing::internal::GetCapturedStdout();
    // Expected output should show the trace from ID3 to ID1 to ID0 (root)
    std::string expectedOutput =
        "Medicare ID: ID3, Direct Contacts: 0, Total Cases: 1\n"
        "Medicare ID: ID1, Direct Contacts: 1, Total Cases: 2\n"
        "Medicare ID: ID0, Direct Contacts: 2, Total Cases: 5\n";
    EXPECT_EQ(expectedOutput, output);
}

TEST_F(ContactTreeTest, PrintContactCasesShowsDirectChildren) {
    testing::internal::CaptureStdout();
    tree.PrintContactCases("ID0");
    std::string output = testing::internal::GetCapturedStdout();
    // Expected output should show the direct children of ID0, which are ID1 and ID2
    std::string expectedOutput =
        "Medicare ID: ID1, Direct Contacts: 1, Total Cases: 2\n"
        "Medicare ID: ID2, Direct Contacts: 1, Total Cases: 2\n";
    EXPECT_EQ(expectedOutput, output);
}

TEST_F(ContactTreeTest, PrintHierarchicalTreePrintsCorrectStructure) {
    testing::internal::CaptureStdout();
    tree.PrintHierarchicalTree();
    std::string output = testing::internal::GetCapturedStdout();
    // Expected output should represent the hierarchical structure starting from the root
    std::string expectedOutput =
        "ID0 (5)\n"
        "  ID1 (2)\n"
        "    ID3 (1)\n"
        "  ID2 (2)\n"
        "    ID4 (1)\n";
    EXPECT_EQ(expectedOutput, output);
}
