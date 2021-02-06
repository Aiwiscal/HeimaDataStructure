#include <iostream>
#include "BinaryTree.h"

int main() {
    BinaryTree tree;
    tree.createBinaryTree();

    // 递归前序遍历
    std::cout << "递归前序遍历：" << std::endl;
    tree.recursion();
    std::cout << "\n****************************" << std::endl;

    // 计算叶子结点数目
    tree.calculateLeafNum();
    std::cout << "****************************" << std::endl;

    // 计算二叉树的高度
    tree.calculateTreeHeight();
    std::cout << "****************************" << std::endl;

    // 非递归前序遍历
    std::cout << "非递归前序遍历：" << std::endl;
    tree.nonRecursion();
    std::cout << "\n****************************" << std::endl;

    BinaryTree copyTree;

    // 深拷贝二叉树
    std::cout << "拷贝二叉树..." << std::endl;
    copyTree = tree;
    std::cout << "拷贝二叉树的前序遍历：" << std::endl;
    copyTree.recursion();
    std::cout << "\n****************************" << std::endl;

    // #号法创建二叉树
    char nodeSeq[] = {'A', 'B', '#', 'C', 'D', '#', '#', 'E','#', '#', 'F', '#', 'G', 'H', '#', '#', '#'};
    int num = 17;
    BinaryTree seqTree;
    std::cout << "#号法创建二叉树..." << std::endl;
    seqTree.createBinaryTree(nodeSeq, num);
    std::cout << "#号法创建二叉树前序遍历：" << std::endl;
    seqTree.recursion();
    std::cout << "\n****************************" << std::endl;

    // 二叉树的反序列化与序列化
    std::string nodeSeqStr = "AB#CD##E##F#GH###";
    BinaryTree seqTree2;
    std::cout << "二叉树反序列化-" << nodeSeqStr << "..." << std::endl;
    seqTree2.deserializeTree(nodeSeqStr);
    std::cout << "反序列化二叉树前序遍历：" << std::endl;
    seqTree2.recursion();
    std::cout << "\n二叉树序列化：" << std::endl;
    std::string nodeSeqStr2 = seqTree2.serializeTree();
    std::cout << nodeSeqStr2 << std::endl;

    // 自动调用析构函数释放内存（4次）

    return 0;
}
