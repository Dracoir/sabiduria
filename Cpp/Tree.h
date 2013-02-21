/*
 * Tree.h
 *
 *  Created on: Jun 3, 2011
 *      Author: Ricardo Rodriguez
 *
 */

#ifndef TREE_H_
#define TREE_H_

namespace Sabiduria {
namespace Structures {

////////////////////////////////////////////////////////////////////////

enum TraversalOrder {PREORDER, INORDER, POSTORDER};

/**
 * Responsible for maintain a node with a respective tree. This class
 * supports binary and tertiary trees
 */
class TreeNode {

public:
	/**
	 * Takes the value of the node
	 * @param int representing the node value
	 */
	TreeNode(int val);
	~TreeNode();

	int _value;             /** Node value */
	TreeNode *_left;        /** Node's left leaf */
	TreeNode *_right;       /** Node's right leaf */
	TreeNode *_middle;      /** Node's middle leaf */
};

////////////////////////////////////////////////////////////////////////

/**
 * Maintains a tree structure. The type of tree depends on the TreeNode
 * class's implementation, i.e. binary or tertiary
 */
class Tree {

public:
	/**
	 * Empty consturctor that simply initializes the root node to NULL
	 */
	Tree();
	/**
	 * Initializes the tree's root node with the value provided
	 * @param rootNode TreeNode representing the tree's root node
	 */
	Tree(TreeNode *rootNode);
	virtual ~Tree();

	/**
	 * Determines whether or not this Tree class represents a BST.
	 * Please note that this class is not complete, and was built
	 * for the sole purpose of demonstrating one function implementation
	 */
	bool IsBinarySearchTree();

	/**
	 * Determines whether the node parameter is part of this tree
	 * @param nodeToFind TreeNode representing value to find
	 */
	bool IsNodeInTree(TreeNode *nodeToFind);

	/**
	 * Determines whether the node parameter is part of this tree
	 * @param value int representing value to find
	 */
	bool IsNodeInTree(int value);

	/**
	 * Traverse tree, based on traversal order
	 * General algorithm adapted from http://en.wikipedia.org/wiki/Tree_traversal
	 */
	void TraverseTree(TraversalOrder traversalType);

private:

	bool IsBinarySearchTree(TreeNode *rootNode, int min, int max);
	bool IsNodeInTree(TreeNode *nodeToFind, TreeNode *nodeToInspect);
	void TraverseTree(TreeNode *rootNode, TraversalOrder traversalType);

	TreeNode *_rootNode;
};
////////////////////////////////////////////////////////////////////////

}
}
#endif /* TREE_H_ */
