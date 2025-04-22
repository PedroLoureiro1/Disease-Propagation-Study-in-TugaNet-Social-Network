Disease Propagation Study in TugaNet Social Network
This project focuses on analyzing the worst-case scenario of disease transmission in Portugal, with the goal of determining the maximum number of "hops" (or jumps) a disease can make as it spreads through a social network. The network in question is based on data from a fictional social network, TugaNet, which is assumed to represent the real-life interactions between individuals in Portugal.

The task is to model the transmission of a disease among individuals by considering their social connections as a directed graph. In this graph:

Each node represents an individual.

A directed edge between two nodes indicates that one individual knows another.

When a disease is introduced to an individual, it spreads instantly to anyone they are directly or indirectly connected to, simulating the disease propagation through the network.

Objective:
The main goal of the project is to compute the maximum number of "hops" or connections that a disease can traverse, starting from any individual in the network, in the worst-case scenario. A hop represents a step from one individual to another through a known relationship.

Input Format:
The input starts with two integers: n, the number of individuals (nodes), and m, the number of directed relationships (edges).

The next m lines contain two integers x and y, indicating that individual x knows individual y (directed edge from x to y).

Output Format:
The program should output an integer representing the maximum number of hops (i.e., the longest path) a disease can make across the network. If no disease can be transmitted (i.e., no paths exist), the program should output 0.

Constraints:
The input graph can be cyclic.

The solution should efficiently compute the longest path in a directed graph.

The problem should be solved with iterative algorithms to avoid issues with recursion stack limits.