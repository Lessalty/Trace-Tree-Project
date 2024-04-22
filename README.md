# Contact Tracing Tree Project

## Project Description
This project implements a contact tracing tree using C++ to manage a network of individuals identified by their Medicare IDs. The tree helps trace the direct and indirect connections between individuals, useful in scenarios like epidemic investigations to trace potential transmissions.

## Features
- **Add Patient Zero**: Initialize the tree with a root node.
- **Add Contact**: Add a node as a child to an existing node, establishing a contact relationship.
- **Display Entire Tree**: Shows all nodes in the tree with details using a breadth-first traversal.
- **Display Hierarchical Tree**: Displays the tree in a hierarchical format, similar to a file system view.
- **Trace Source**: Traces back from a given node to the root, showing the path.
- **Print Direct Contacts**: Displays direct contacts of a given node.

## How to Compile and Run
Ensure you have a C++ compiler installed (e.g., GCC, Clang, MSVC). The project is structured as follows:

- `include/` - Contains header files.
- `src/` - Contains implementation files.
- `main.cpp` - The main program entry file.

### Compilation
Navigate to the project directory where the files are located and run the following command:

```bash
g++ -o ContactTreeApp main.cpp src/TreeNode.cpp src/ContactTree.cpp -I include
