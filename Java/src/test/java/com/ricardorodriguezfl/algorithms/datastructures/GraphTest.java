package com.rick.algorithms;

import java.util.LinkedList;
import java.util.List;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import com.rick.algorithms.model.Node;

/**
 * Tests the functionality of the Graph class
 * 
 * @author Ricardo Rodriguez
 * @see com.rick.algorithms.Graph
 *
 */
public class GraphTest {

	// Reference to a graph
	private Graph graph;
	
	// List of visited nodes
	private List<Node> visitedNodes;
	
	// Head node
	private Node node1;
	
	//-----------------------------------------------------------------------------------
	/**
	 * Sets up the class variables
	 */
	@Before
	public void setUp() {
		graph = new Graph();
		node1 = new Node(1);
		Node node2 = new Node(2);
		Node node3 = new Node(3);
		Node node4 = new Node(4);
		Node node5 = new Node(5);
		
		node1.setChild(node2);
		node1.setChild(node3);
		node1.setChild(node4);
		node4.setChild(node5);
		
		visitedNodes = new LinkedList<Node>();
	}
	
	//-----------------------------------------------------------------------------------
	/**
	 * Tests the Graph::isCyclical method
	 */
	@Test
	public void testIsCyclical() {
		Assert.assertTrue("Graph was cyclical!", !graph.isCyclical(node1, visitedNodes));
	}
}
