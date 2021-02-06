//
// Created by wenhan on 2021/1/28.
//

#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H

typedef struct BINARYNODE{
    char ch;
    struct BINARYNODE * lchild;
    struct BINARYNODE * rchild;
}BinaryNode;

typedef struct BITREESTACKNODE{
    BinaryNode *root;
    bool flag;
}BiTreeStackNode;

class BinaryTree {
private:
    BinaryNode *root;

public:
    BinaryTree();

    ~BinaryTree();

    void createBinaryTree();

    void createBinaryTree(char* nodeSeq, size_t num);

    // 先序遍历递归实现
    void recursion();

    // 计算叶子结点数目
    void calculateLeafNum();

    // 计算二叉树的高度，对应视频无法观看，自己实现
    void calculateTreeHeight();

    // 先序遍历非递归实现，借助STL中的stack实现
    void nonRecursion();

    // 序列化
    std::string serializeTree();

    // 反序列化
    void deserializeTree(const std::string &treeSeq);

    // 重载赋值运算符，实现拷贝
    BinaryTree& operator=(const BinaryTree &tree);

private:
    static void _recursion(BinaryNode* currentRoot);

    static void _freeBinaryTree(BinaryNode* currentRoot);

    static void _calculateLeafNum(BinaryNode* currentRoot, int& num);

    static void _calculateTreeHeight(BinaryNode* currentRoot, int& height);

    // 自己想的拷贝方式，比较繁琐
    static void _copyBinaryTree(BinaryNode* currentRoot, BinaryNode** copyRoot);

    // 视频中的拷贝方式，比较简洁
    static BinaryNode* _copyBinaryTree(BinaryNode* currentRoot);

    static BinaryNode* _createBinaryTree(const char* nodeSeq, size_t num, int &pos);

    static std::string _serializeTree(BinaryNode* currentRoot);

    static BinaryNode* _deserializeTree(const std::string &treeSeq, int &pos);

};


#endif //BINARYTREE_BINARYTREE_H
