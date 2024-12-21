# Programming Assignment 3 - Cycle Breaking

This program solves the cycle breaking problem for both undirected and directed graphs. Given a graph G = (V, E, w), it finds a set of edges to remove to make G acyclic while minimizing the total weight of removed edges.

## Compilation

The program can be compiled using the provided makefile:

```bash
make
```

This will create an executable named `cb` in the `bin` directory.

## Usage

The program can be run using the following command format:

```bash
./bin/cb <input_file> <output_file>
```

Example:
```bash
./bin/cb inputs/public_case_1.in outputs/public_case_1.out
```

## Input Format

The input file should contain:
- First line: a character 'u' (undirected) or 'd' (directed)
- Second line: integer n (number of vertices)
- Third line: integer m (number of edges)
- Following m lines: three integers per line (i, j, w) representing an edge from vertex i to j with weight w
- Last line: single "0" (zero) to signify end of input

## Output Format

The program outputs:
- First line: total weight of removed edges
- Following lines: removed edges in format "source target weight"
- If no edges are removed, outputs single "0" (zero)

## Constraints

- For undirected graphs: n ? 10,000; m ? 20,000,000
- For directed graphs: n ? 5,000; m ? 10,000
- Edge weights: -100 ? w ? 100

## Directory Structure

```
.
¢u¢w¢w bin/          # Contains executable
¢u¢w¢w src/          # Source files
¢x   ¢u¢w¢w main.cpp
¢x   ¢|¢w¢w cyclebreak.cpp
¢u¢w¢w makefile
¢|¢w¢w README.md
```

## Notice
Since the directed weighted graph is an NP hard problem, and I haven't find a efficient algorithm to solve it, so I just return 0.
