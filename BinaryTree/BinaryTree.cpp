//
// Created by wenhan on 2021/1/28.
//

#include <iostream>
#include "BinaryTree.h"
#include <stack>

BinaryTree::BinaryTree() {
    root = nullptr;
}

BinaryTree::~BinaryTree() {
    std::cout << "\n-------------------" << std::endl;
    std::cout << "free BinaryTree: ";
    _freeBinaryTree(root);
}

void BinaryTree::createBinaryTree() {
    // 创建结点
    // 这里必须使用new, 否则构造完成后各node会自动销毁！
    // 使用new之后，虽不会被自动销毁，但是必须手动在析构函数中释放内存！

    auto *node1 = new BinaryNode{'A', nullptr, nullptr};
    auto *node2 = new BinaryNode{'B', nullptr, nullptr};
    auto *node3 = new BinaryNode{'C', nullptr, nullptr};
    auto *node4 = new BinaryNode{'D', nullptr, nullptr};
    auto *node5 = new BinaryNode{'E', nullptr, nullptr};
    auto *node6 = new BinaryNode{'F', nullptr, nullptr};
    auto *node7 = new BinaryNode{'G', nullptr, nullptr};
    auto *node8 = new BinaryNode{'H', nullptr, nullptr};

    // 建立结点关系
    node1->lchild = node2;
    node1->rchild = node6;
    node2->rchild = node3;
    node3->lchild = node4;
    node3->rchild = node5;
    node6->rchild = node7;
    node7->lchild = node8;

    root = node1;
}


void BinaryTree::createBinaryTree(char *nodeSeq, size_t num) {
    if (nodeSeq == nullptr){
        return;
    }
    if (root != nullptr){
        _freeBinaryTree(root);
    }
    int pos = 0;
    root = _createBinaryTree(nodeSeq, num, pos);
}

// 先序遍历递归实现
void BinaryTree::recursion() {
    if (root == nullptr){
        return;
    }
    _recursion(root);
}

// 计算叶子结点数目
void BinaryTree::calculateLeafNum() {
    if (root == nullptr){
        return;
    }
    int num = 0;
    _calculateLeafNum(root, num);
    std::cout << "叶子结点的数目:" << num << std::endl;
}

void BinaryTree::calculateTreeHeight() {
    if (root == nullptr){
        return;
    }
    int height = 0;
    _calculateTreeHeight(root, height);
    std::cout << "树的高度:" << height << std::endl;
}

// 先序遍历非递归实现，借助STL中的stack实现
void BinaryTree::nonRecursion() {
    if (root == nullptr){
        return;
    }

    std::stack<BiTreeStackNode> stk;
    BiTreeStackNode biTreeStackNode{root, false};
    stk.push(biTreeStackNode);
    while (!stk.empty()){
        BiTreeStackNode& node = stk.top();
        // 必须重新复制一个与node一样的结点，否则node一直指向stack栈顶，出现结果异常！
        BiTreeStackNode rootNode{node.root, node.flag};
        stk.pop();
        if (rootNode.root == nullptr){
            continue;
        }
        if (rootNode.flag){
            std::cout << rootNode.root->ch << " ";
            continue;
        }
        rootNode.flag = true;

        // 通过控制入栈的顺序，可以分别实现前序、中序、后序遍历！

        // 当前结点的右结点入栈
        BiTreeStackNode rnode{rootNode.root->rchild, false};
        stk.push(rnode);
        // 当前结点的左结点入栈
        BiTreeStackNode lnode{rootNode.root->lchild, false};
        stk.push(lnode);
        // 当前结点入栈
        stk.push(rootNode);
    }
}

// 序列化
std::string BinaryTree::serializeTree(){
    return _serializeTree(root);
}

// 反序列化
void BinaryTree::deserializeTree(const std::string &treeSeq){
    if (treeSeq.empty()){
        return;
    }
    if (root != nullptr){
        _freeBinaryTree(root);
    }
    int pos = 0;
    root = _deserializeTree(treeSeq, pos);
}

// 重载赋值运算符，实现拷贝

BinaryTree & BinaryTree::operator=(const BinaryTree& tree){
    if (tree.root == nullptr){
        return *this;
    }
    // 检查是否自我赋值！
    if (this == &tree){
        return *this;
    }
//    BinaryNode *root_;
//    _copyBinaryTree(tree.root, &root_);
    this->root = _copyBinaryTree(tree.root);
    return *this;
}

void BinaryTree::_recursion(BinaryNode *currentRoot) {
    if (currentRoot == nullptr){
        return;
    }

    // 访问根结点
    std::cout << currentRoot->ch << " ";

    // 遍历左子树
    _recursion(currentRoot->lchild);

    // 遍历右子树
    _recursion(currentRoot->rchild);
}

void BinaryTree::_freeBinaryTree(BinaryNode *currentRoot) {
    // 后序遍历销毁各结点

    if (currentRoot == nullptr){
        return;
    }
    // 释放左子树
    _freeBinaryTree(currentRoot->lchild);
    // 释放右子树
    _freeBinaryTree(currentRoot->rchild);
    std::cout << currentRoot->ch << " ";
    // 释放当前结点
    delete currentRoot;
}

void BinaryTree::_calculateLeafNum(BinaryNode *currentRoot, int &num) {
    if (currentRoot == nullptr){
        return;
    }
    if (currentRoot->lchild == nullptr && currentRoot->rchild == nullptr){
        num ++;
    }
    // 左子树叶子结点数目
    _calculateLeafNum(currentRoot->lchild, num);

    // 右子树叶子结点数目
    _calculateLeafNum(currentRoot->rchild, num);

}

void BinaryTree::_calculateTreeHeight(BinaryNode *currentRoot, int &height) {
    if (currentRoot == nullptr){
        return;
    }
    int lh = 0, rh = 0;
    _calculateTreeHeight(currentRoot->lchild,lh);
    _calculateTreeHeight(currentRoot->rchild, rh);
    height = 1 + ((lh>rh)?lh:rh);
}

void BinaryTree::_copyBinaryTree(BinaryNode* currentRoot, BinaryNode** copyRoot){
    if (currentRoot == nullptr){
        return;
    }
    *copyRoot = new BinaryNode{currentRoot->ch, nullptr, nullptr};
    _copyBinaryTree(currentRoot->lchild, &((*copyRoot)->lchild));
    _copyBinaryTree(currentRoot->rchild, &((*copyRoot)->rchild));
}

BinaryNode* BinaryTree::_copyBinaryTree(BinaryNode* currentRoot){
    if (currentRoot == nullptr){
        return nullptr;
    }
    // 拷贝左子树
    BinaryNode *lchild = _copyBinaryTree(currentRoot->lchild);

    // 拷贝右子树
    BinaryNode *rchild = _copyBinaryTree(currentRoot->rchild);

    // 创建结点
    auto *newNode = new BinaryNode{currentRoot->ch, lchild, rchild};
    return newNode;
}

BinaryNode* BinaryTree::_createBinaryTree(const char* nodeSeq, size_t num, int &pos){
    if (nodeSeq == nullptr){
        return nullptr;
    }
    if (pos >= num){
        return nullptr;
    }
    if (nodeSeq[pos] == '#'){
        pos++;
        return nullptr;
    }
    auto pNode = new BinaryNode{nodeSeq[pos], nullptr, nullptr};
    pos++;
    pNode->lchild =  _createBinaryTree(nodeSeq, num, pos);
    pNode->rchild = _createBinaryTree(nodeSeq, num, pos);
    return pNode;
}

std::string BinaryTree::_serializeTree(BinaryNode* currentRoot){
    if (currentRoot == nullptr){
        return "#";
    }

    std::string treeString;
    treeString = treeString + currentRoot->ch;
    treeString += _serializeTree(currentRoot->lchild);
    treeString += _serializeTree(currentRoot->rchild);

    return treeString;
}

BinaryNode* BinaryTree::_deserializeTree(const std::string &treeSeq, int &pos) {
    if (treeSeq.empty()){
        return nullptr;
    }
    if (pos >= treeSeq.size()){
        return nullptr;
    }
    char ch = treeSeq.at(pos);
    if (ch == '#'){
        pos ++;
        return nullptr;
    }
    auto *node = new BinaryNode{ch, nullptr, nullptr};
    pos ++;
    node->lchild = _deserializeTree(treeSeq, pos);
    node->rchild = _deserializeTree(treeSeq, pos);
    return node;
}