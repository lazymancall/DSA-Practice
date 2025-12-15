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
	Node * create_node(int data);
	bool delete_node(Node *& parent, int data);
	void delete_all_nodes(Node *& parent);
	void list_nodes(Node * parent);
	bool search_node(Node * parent, int data);

	public:
	BinaryTree();
	~BinaryTree();

	void add(int data);
	void list();
	int search(int data);
	bool remove(int data);
	int get_count();
	
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