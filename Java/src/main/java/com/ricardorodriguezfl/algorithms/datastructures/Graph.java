package com.rick.algorithms;

import java.util.List;

import com.rick.algorithms.model.Node;

/**
 * Implements graph algorithms
 * 
 * @author Ricardo Rodriguez
 * @see com.rick.algorithms.model.Node
 *
 */
public class Graph {

	//-----------------------------------------------------------------------------------	
	/**
	 * Determines whether or not a "simple" graph is cyclical.  That is, a graph
	 * that is not bidirectional 
	 * @param node Node representing the head of the graph structure
	 * @param visitedNodes List&lt;Node&gt; representing visited nodes -- should 
	 * initially be empty 
	 * @return boolean indicating whether or not the graph is cyclical
	 */
	public boolean isCyclical(Node node, List<Node> visitedNodes) {
	    if(visitedNodes.contains(node)) {
	        return true;
	     } else {
	        visitedNodes.add(node);
	        for(Node childNode : node.getChildren()) {
	             if(isCyclical(childNode, visitedNodes)) {
	                 return true;
	             }
	        }
	        return false;
	     }
	 }
}
