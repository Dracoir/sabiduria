package com.rick.algorithms.model;

import java.util.LinkedList;
import java.util.List;

/**
 * Manages basic "node" entity/model
 * 
 * @author Ricardo Rodriguez
 *
 */
public class Node {
	private int value;
	
	private List<Node> children;

	//-----------------------------------------------------------------------------------	
	/**
	 * Default constructor, taking an integer value for the node 
	 * @param value int representing the node value
	 */
	public Node(int value) {
		this.value = value;
		children = new LinkedList<Node>();
	}
	
	//-----------------------------------------------------------------------------------
	/**
	 * Gets the node's value
	 * @return int
	 */
	public int getValue() {
		return value;
	}

	//-----------------------------------------------------------------------------------	
	/**
	 * Sets the node's integer value
	 * 
	 * @param value int representing the node's value
	 */
	public void setValue(int value) {
		this.value = value;
	}

	//-----------------------------------------------------------------------------------	
	/**
	 * Gets the node's children
	 * 
	 * @return List&lt;Node&gt;
	 */
	public List<Node> getChildren() {
		return children;
	}

	//-----------------------------------------------------------------------------------	
	/**
	 * Sets a node's children
	 * 
	 * @param children List&lt;Node&gt; representing the children nodes
	 */
	public void setChildren(List<Node> children) {
		this.children = children;
	}

	//-----------------------------------------------------------------------------------	
	/**
	 * Sets a child node
	 * 
	 * @param node Node representing the child
	 */
	public void setChild(Node node) {
		children.add(node);
	}

}
