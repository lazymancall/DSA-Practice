#ifndef _BINARYTREE_
#define _BINARYTREE_

struct Node {
	int data;
	Node *right, *left;
};

class BinaryTree {
	private:
	Node * head;
	int count;

	void insert_node(Node *& parent, int data);
	void insert_node(Node *& parent, int * data_set, int index, int size);
	Node * create_node(int data);
	bool delete_node(Node *& parent, int data);
	void delete_all_nodes(Node *& parent);
	bool search_node(Node * parent, int data);
	
	void list_preorder_nodes(Node * parent);
	void list_postorder_nodes(Node * parent);
	void list_inorder_nodes(Node * parent);
	void list_level_order_nodes(Node * parent);

	public:
	BinaryTree();
	BinaryTree(int * data_set, int size);
	~BinaryTree();

	void add(int data);
	int search(int data);
	bool remove(int data);
	int get_count();

	void list_preorder();
	void list_postorder();
	void list_inorder();
	void list_level_order();
	
};

/*
class Leaf {
	private:
	int num;
	char * name;

	public:
	void set_num(int new_num) {
		num = new_num;
	}
	
	void set_name(char * new_name) {
		if (name != nullptr) {
			delete[] name;
		}
		name = new char[strlen(new_name) + 1];
		strcpy(name, new_name, strlen(new_name) + 1);
	}

	int get_num() {
		return num;
	}

	char* get_name() {
		return name;
	}
};
*/
#endif