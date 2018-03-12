#include <sstream>
#include "tree.h"

int sum(int a, int b) { return a+b; }
int prod(int a, int b) { return a*b; }

TreeNode::TreeNode() {
    //leftChild = nullptr;
    //rightChild = nullptr;
    handler = nullptr;
    payload = 0;
}

TreeNode::TreeNode(int value) {
    //leftChild = nullptr;
    //rightChild = nullptr;
    handler = nullptr;
    payload = value;
}

TreeNode::TreeNode(NodeHandler handler, TreeNode *left, TreeNode *right) {
    this->handler = handler;
    //leftChild = left;
    //rightChild = right;
    leftChild.reset(left);
    rightChild.reset(right);
    payload = 0;
}

TreeNode::~TreeNode() {
    //delete leftChild;
    //delete rightChild;
}

int TreeNode::evaluateExpression() {

    if ( isLeaf() ) {
        return payload;
    }

    int leftChildValuation = leftChild->evaluateExpression();
    int rightChildValuation = rightChild->evaluateExpression();

    return handler(leftChildValuation, rightChildValuation);

}

std::string TreeNode::toString() {

    if ( isLeaf() ) {
        return std::to_string(payload);
    }

    std::string leftChildValuation = leftChild->toString();
    std::string rightChildValuation = rightChild->toString();

    std::string result = "(" + leftChildValuation;
    result += " op " + rightChildValuation + ")";

    std::stringstream ss;

    ss << "("
       << leftChildValuation
       << " op "
       << rightChildValuation
       << ")";

    return ss.str();
}

size_t TreeNode::countLeafs() {

    if ( isLeaf() )
        return 1;

    size_t numLeftSubtreeLeafs = leftChild->countLeafs();
    size_t numRightSubtreeLeafs = rightChild->countLeafs();
    return numLeftSubtreeLeafs + numRightSubtreeLeafs;
}

bool TreeNode::isLeaf() {
    return handler == nullptr;
}

bool TreeNode::isOperator() {
    return handler != nullptr;
}

MyTree::MyTree() {

    TreeNode *root =  new TreeNode(
            sum,
            new TreeNode( prod, new TreeNode(5), new TreeNode(3) ),
            new TreeNode( prod, new TreeNode(2), new TreeNode(8) )
    );

    this->root.reset(root);

}

MyTree::~MyTree() {
    //delete root;
}

int MyTree::evaluateExpression() {
    return root->evaluateExpression();
}

std::string MyTree::toString() {
    return root->toString();
}

size_t MyTree::countLeafs() {
    return root->countLeafs();
}
