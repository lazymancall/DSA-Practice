# Implementations of Data Structures
## Binary Tree

### Public Methods

`BinaryTree()` : The default constructor.

`BinaryTree(int * dataset, int size)` : The Array to BinaryTree constructor. Inserts data into binary tree in level order.
- dataset : Address of a Node Pointer
- size : Integer

`~BinaryTree()` : The default destructor.

`void add(int data)` : Adds a node to the tree.
- data : Integer

`int search(int data)` : Search for node in tree if it exists.
- data : Integer

`bool remove(int data)` : Removes node in tree if it exists.
- data : Integer

`int get_count()` : Gets the number of nodes in the tree.

`void list_preorder()` : Lists node data while traversing in preorder.

`void list_postorder()` : Lists node data while traversing in postorder.

`void list_inorder()` : Lists node data while traversing in inorder.

`void list_level_order()` : Lists node data while traversing in level order.

### Private Methods

`void insert_node(parent, data)` : Inserts node by comparing node data.
- parent : Address of a Node Pointer
- data : Integer

`void insert_node(parent, dataset, index, size)` : Inserts nodes in a level order fashion.
- parent : Address of a Node Pointer
- dataset : Integer Pointer
- index : Integer
- size : Integer

`Node * create_node(data)` : Creates node with data given.
- data : Integer

`bool delete_node(parent, data)` : removes node with given data if it exists.
- parent : Address of a Node Pointer
- data : Integer

`void delete_all_nodes(parent)` : Deletes all nodes in the tree.
- parent : Address of a Node Pointer

`bool search_node(parent, data)` : Searches for a node and sees if it exists.
- parent : Address of a Node Pointer
- data : Integer

`void list_preorder_nodes(parent)` : Lists node data while traversing in preorder.
- parent : Address of a Node Pointer

`void list_postorder_nodes(parent)` : Lists node data while traversing in postorder.
- parent : Address of a Node Pointer
  
`void list_inorder_nodes(parent)` : Lists node data while traversing in inorder.
- parent : Address of a Node Pointer

`void list_level_order_nodes(parent)` : Lists node data while traversing in level order.
- parent : Address of a Node Pointer

---