/*
 * Tree.cpp
 *
 *  Created on: Jun 3, 2011
 *      Author: Ricardo Rodriguez
 */

#include "Tree.h"
#include <limits>
#include <iostream>

namespace Sabiduria {
namespace Structures {

////////////////////////////////////////////////////////////////////////
TreeNode::TreeNode(int val) : _left(NULL), _right(NULL), _middle(NULL)
{
	_value = val;
}

////////////////////////////////////////////////////////////////////////
TreeNode::~TreeNode()
{
	delete _left;
	delete _right;
	delete _middle;
}

////////////////////////////////////////////////////////////////////////
Tree::Tree() : _rootNode(NULL)
{
}

////////////////////////////////////////////////////////////////////////
Tree::Tree(TreeNode *rootNode) : _rootNode(rootNode)
{
}

////////////////////////////////////////////////////////////////////////
Tree::~Tree()
{
	// TODO Auto-generated destructor stub
}

////////////////////////////////////////////////////////////////////////
bool Tree::IsBinarySearchTree(TreeNode *rootNode, int min, int max)
{
	// Return if we've reached a leaf node
	if(rootNode == NULL)
	{
		return true;
	}

	// Validate that this node is within the min and max value
	if(rootNode->_value < min || rootNode->_value > max)
	{
		return false;
	}

	// Validate that this node has, at most, two child nodes
	if(rootNode->_left != NULL && rootNode->_right != NULL && rootNode->_middle != NULL)
	{
		// There were more than one child node
		return false;
	}

	// Now check the left and right side of the tree: note the min/max values
	return ( IsBinarySearchTree(rootNode->_left, min, rootNode->_value) &&
			 IsBinarySearchTree(rootNode->_right, rootNode->_value+1, max)
		   );
}

////////////////////////////////////////////////////////////////////////
bool Tree::IsBinarySearchTree()
{
	return IsBinarySearchTree(_rootNode, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

////////////////////////////////////////////////////////////////////////
bool Tree::IsNodeInTree(int value)
{
	TreeNode node(value);
	return IsNodeInTree(&node, _rootNode);
}

////////////////////////////////////////////////////////////////////////
bool Tree::IsNodeInTree(TreeNode *nodeToFind)
{
	return IsNodeInTree(nodeToFind, _rootNode);
}

////////////////////////////////////////////////////////////////////////
bool Tree::IsNodeInTree(TreeNode *nodeToFind, TreeNode *nodeToInspect)
{
	if(nodeToInspect == NULL)
		return false;

	if(nodeToInspect->_value == nodeToFind->_value)
		return true;

	if(nodeToFind->_value < nodeToInspect->_value)
	{
		return IsNodeInTree(nodeToFind, nodeToInspect->_left);
	} else {
		return IsNodeInTree(nodeToFind, nodeToInspect->_right);
	}
}

////////////////////////////////////////////////////////////////////////
void Tree::TraverseTree(TraversalOrder traversalType)
{
	TraverseTree(_rootNode, traversalType);
	std::cout << std::endl;
}

////////////////////////////////////////////////////////////////////////
void Tree::TraverseTree(TreeNode *rootNode, TraversalOrder traversalType)
{
	if(rootNode == NULL)
		return;

	switch(traversalType)
	{
	case PREORDER:
		std::cout << rootNode->_value << " ";
		TraverseTree(rootNode->_left, traversalType);
		TraverseTree(rootNode->_right, traversalType);
		break;

	case INORDER:
		TraverseTree(rootNode->_left, traversalType);
		std::cout << rootNode->_value << " ";
		TraverseTree(rootNode->_right, traversalType);
		break;

	case POSTORDER:
		TraverseTree(rootNode->_left, traversalType);
		TraverseTree(rootNode->_right, traversalType);
		std::cout << rootNode->_value << " ";
		break;

	default:
		std::cout << "INCORRECT TRAVERSAL ORDER!!";
		break;

	}
}

////////////////////////////////////////////////////////////////////////

}
}
