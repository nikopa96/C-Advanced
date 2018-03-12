#ifndef PRAX06_TREE_H
#define PRAX06_TREE_H

#include <string>
#include <memory>

using NodeHandler = int (*)(int, int);

class TreeNode {
public:
    /**
     * Default constructor - creates an empty node
     */
    TreeNode();

    /**
     * Constructs a leaf node
     * @param value value stored in a node
     */
    TreeNode(int value);

    /**
     * Constructs an operator node
     * @param handler pointer to a function with signature int(int,int)
     * @param left  a pointer to the left child node
     * @param right a pointer to the right child node
     */
    TreeNode(NodeHandler handler, TreeNode *left, TreeNode* right);

    /**
     * Destructor deinitializes the object
     */
    ~TreeNode();

    /**
     * Evaluates expression represented by the tree
     * @return the result expression valuation
     */
    int evaluateExpression();

    /**
     * Returns a string representation of the tree
     * @return string corresponding to the expression
     */
    std::string toString();

    /**
     * Counts the number of leafs in a subtree
     * @return the number of leafs (unsigned int)
     */
    size_t countLeafs();

    /**
     * Checks if a node is a leaf node
     * @return true if handler is nullptr, false otherwise
     */
    bool isLeaf();

    /**
     * Checks if a node is an operator node
     * @return true if handler is not nullptr, false otherwise
     */
    bool isOperator();

private:
    //TreeNode *leftChild, *rightChild;
    std::unique_ptr <TreeNode> leftChild, rightChild;
    int payload;
    NodeHandler handler;
};

class MyTree {
public:
    /**
     * Creates a tree
     */
    MyTree();

    /**
     * Destructs a tree
     */
    ~MyTree();

    /**
     * Evaluates the expression of the tree
     * @return the result of computation
     */
    int evaluateExpression();

    /**
     * Returns a string representation of the tree
     * @return a string representation of the tree
     */
    std::string toString();

    /**
     * Counts the number of leafs in the tree
     * @return the number of leavs (unsigned int)
     */
    size_t countLeafs();
private:
    //TreeNode *root;
    std::unique_ptr <TreeNode> root;
};

#endif //PRAX06_TREE_H
