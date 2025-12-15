#include <iostream>
#include "binaryTree.h"

BinaryTree::BinaryTree() {
	head = nullptr;
	count = 0;
}

BinaryTree::BinaryTree(int * data_set, int size) {
	if (size > 0) {
		insert_node(head, data_set, 0, size);
	}
	count = size;
}

BinaryTree::~BinaryTree() {
	delete_all_nodes(head);
}

// public

void BinaryTree::add(int data) {
	insert_node(head, data);
	count++;
}


bool BinaryTree::remove(int data) {
	bool has_deleted = false;
	if (head != nullptr) {
		has_deleted = delete_node(head, data);
	}
	return has_deleted;
}

void BinaryTree::list_preorder() {
	std::cout << "Preorder List: " << std::endl;
	list_preorder_nodes(head);
}

void BinaryTree::list_postorder() {
	std::cout << "Postorder List: " << std::endl;
	list_postorder_nodes(head);
}

void BinaryTree::list_inorder() {
	std::cout << "Inorder List: " << std::endl;
	list_inorder_nodes(head);
}

void BinaryTree::list_level_order() {
	std::cout << "Level Order List: " << std::endl;
	list_level_order_nodes(head);
}

int BinaryTree::search(int data) {
	return search_node(head, data);
}

int BinaryTree::get_count() {
	return count;
}

// private

bool BinaryTree::search_node(Node * parent, int data) {
	int data_found = false;

	if (data == parent->data) { // data with node is found
		data_found = true;
	}
	else { // keep looking for node
		if (parent->right != nullptr || parent->left != nullptr) {      
			if(parent->right != nullptr && data_found != true) {
				data_found = search_node(parent->right, data);
			} 
			if (parent->left != nullptr && data_found != true) {
				data_found = search_node(parent->left, data);
			}
		}
	}
	return data_found;
}

bool BinaryTree::delete_node(Node *& parent, int data) {
	bool has_deleted = false;

	if (data == parent->data) { // data with node is found
		if (parent->right == nullptr && parent->left == nullptr) { // if has no children
			parent = nullptr;
			delete parent;
		}
		else if (parent->right != nullptr && parent->left != nullptr) { // if has two children
			Node * temp = parent->left;
			while(temp->right != nullptr) { // get the left node's rightmost node
				temp = temp->right;
			}
			// write that node's data to the parent node's data
			parent->data = temp->data;
			has_deleted = delete_node(parent->left, temp->data);
			count++;
		}
		else if (parent->right != nullptr) { // if left node is null
			Node * temp = parent->right; // get right node

			// replace parent variables with right node
			parent->data = temp->data;
			parent->right = temp->right;
			parent->left = temp->left;

			// discard old right node
			temp = nullptr;
			delete temp;
		} 
		else if (parent->left != nullptr) { // if right node is null
			Node * temp = parent->left;
			
			parent->data = temp->data;
			parent->right = temp->right;
			parent->left = temp->left;
			
			temp = nullptr;
			delete temp;
		}
		has_deleted = true;
		count--;
	}
	else { // keep looking for node
		if (parent->right != nullptr && has_deleted != true) {
			has_deleted = delete_node(parent->right, data);
		} 
		if (parent->left != nullptr && has_deleted != true) {
			has_deleted = delete_node(parent->left, data);
		}
	}
	return has_deleted;
}

void BinaryTree::delete_all_nodes(Node *& parent) {
	if(parent != nullptr) {
		// go through both left and right nodes
		if(parent->left != nullptr) {
			delete_all_nodes(parent->left);
		} 
		if (parent->right != nullptr) {
			delete_all_nodes(parent->right);
		}
		parent = nullptr;
		delete parent;
	}
}

void BinaryTree::insert_node(Node *& parent, int data)  {
	// if node is empty, add node
	if (parent == nullptr) {
		parent = new Node();
		parent = create_node(data);
	}
	// otherwise, recur down the tree
	else {
		if (data < parent->data) {
			insert_node(parent->left, data);
		}
		else if (data >= parent->data) {
			insert_node(parent->right, data);
		}
	}
}

void BinaryTree::insert_node(Node *& parent, int * data_set, int index, int size)  {
	// if index is smaller than size, create node
	if (index < size) {
		parent = create_node(data_set[index]);
		insert_node(parent->left, data_set, (2 * index + 1), size);
		insert_node(parent->right, data_set, (2 * index + 2), size);
	}
}

// done
void BinaryTree::list_preorder_nodes(Node * parent) {
	if(parent != nullptr) {
		std::cout << " " << parent->data << std::endl;
		// go through both left and right nodes
		if(parent->left != nullptr) {
			list_preorder_nodes(parent->left);
		} 
		if (parent->right != nullptr) {
			list_preorder_nodes(parent->right);
		}
	}
}

void BinaryTree::list_postorder_nodes(Node * parent) {
	if(parent != nullptr) {
		// go through both left and right nodes
		if(parent->left != nullptr) {
			list_postorder_nodes(parent->left);
		}
		if (parent->right != nullptr) {
			list_postorder_nodes(parent->right);
		}
		std::cout << " " << parent->data << std::endl; 
	}
}

void BinaryTree::list_inorder_nodes(Node * parent) {
	if(parent != nullptr) {
		// go through both left and right nodes
		if(parent->left != nullptr) {
			list_inorder_nodes(parent->left);
		} 
		std::cout << " " << parent->data << std::endl;
		if (parent->right != nullptr) {
			list_inorder_nodes(parent->right);
		}
	}
}

void BinaryTree::list_level_order_nodes(Node * parent) {
	if(parent != nullptr) {
		if (parent == head) {
			std::cout << " " << parent->data << std::endl;
		}
		if (parent->left != nullptr && parent->right != nullptr) {
			std::cout << " " << parent->left->data << std::endl;
			std::cout << " " << parent->right->data << std::endl;
			list_level_order_nodes(parent->left);
			list_level_order_nodes(parent->right);
		}
		else if (parent->left != nullptr) {
			std::cout << " " << parent->left->data << std::endl;
			list_level_order_nodes(parent->left);
		}
		else if (parent->right != nullptr) {
			std::cout << " " << parent->right->data << std::endl;
			list_level_order_nodes(parent->right);
		}
	}
}

Node * BinaryTree::create_node(int data) {
	Node * new_node = new Node();
	new_node->data = data;
	new_node->left = nullptr;
	new_node->right = nullptr;
	return new_node;
}

int main() {
	std::cout << "test" << std::endl;
	// creating array
	int * arr = new int[7];
	for (int i = 0; i < 7; i++) {
		arr[i] = i+1;
	}

	// creating tree from array
	BinaryTree newTree = BinaryTree(arr, 7);

	std::cout << "count : " << newTree.get_count() << std::endl;
	newTree.list_level_order();
	newTree.list_inorder();
	newTree.list_preorder();
	newTree.list_postorder();
	return 0;
}