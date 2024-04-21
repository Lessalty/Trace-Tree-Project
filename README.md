# TraceTree

## Overview

TraceTree is a C++ console application designed to simulate a contact tracing system. It utilizes a tree data structure to manage and visualize the relationship between a "Patient Zero" and subsequent contacts. This project aims to demonstrate basic data structure manipulation, specifically tree operations, in a real-world scenario.

## Features

- **Add Patient Zero**: Establish the initial node or root of the contact tracing tree.
- **Add Contact**: Link new contacts to any existing contact, effectively growing the tree structure.
- **Display Tree**: Output the complete tree structure in a console, showing all connections and hierarchies.

## Installation

### Prerequisites

Make sure you have a C++ compiler installed that supports C++11 standards or newer. The project was developed using GCC, but any standard-compliant compiler should work.

### Compiling and Running

1. **Clone the Repository**
   - Obtain the project files by cloning the repository using Git:
     ```bash
     git clone https://github.com/Lessalty/Trace-Tree-Project/TraceTree.git
     ```
   - Navigate into the project directory:
     ```bash
     cd TraceTree
     ```

2. **Compile the Project**
   - Compile the project using the following command:
     ```bash
     g++ -o TraceTree src/main.cpp src/ContactTree.cpp src/TreeNode.cpp -I include
     ```

3. **Run the Application**
   - Execute the compiled application:
     ```bash
     ./TraceTree
     ```
   - On Windows platforms, if using cmd, run:
     ```cmd
     TraceTree.exe
     ```

## Usage

After launching the application, the user is presented with a simple menu:

1. **Add Patient Zero**: Input the ID for Patient Zero when prompted.
2. **Add Contact**: Provide an existing contact's ID followed by the new contact's ID.
3. **Display All Contacts**: The tree structure, including all nodes and their connections, will be displayed.

Navigate through the menu by inputting the number corresponding to your choice and following the prompts for data as required.

## Contributing

Contributions to TraceTree are welcome! Please adhere to the following guidelines:

- Fork the repository.
- Create a new branch for each feature or improvement.
- Send a pull request from each feature branch to the main branch for review.

## Feedback

Your feedback is valuable to us! If you have suggestions on how to improve this application or encounter any issues, please open an issue in the repository.

## License

TraceTree is released under the MIT License. See the `LICENSE` file in the project directory for full details.

## Author

- **[Anh Khoa Nguyen]** - Initial development and design of TraceTree.

Thank you for exploring TraceTree!
