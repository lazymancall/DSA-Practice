#include <iostream>
#include "binaryTree.h"

BinaryTree::BinaryTree() {
	head = nullptr;
	count = 0;
}

BinaryTree::~BinaryTree() {
	delete_all_nodes(head);
	std::cout << "tree terminated" << std::endl;
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

void BinaryTree::list() {
	list_nodes(head);
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

	if (data == parent->data) {                                         	// data with node is found
		data_found = true;
	}
	else {															    	// keep looking for node
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
			std::cout << "no child" <<  std::endl;
			parent = nullptr;
			delete parent;
		}
		else if (parent->right != nullptr && parent->left != nullptr) { // if has two children
			std::cout << "two child" <<  std::endl;
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
			std::cout << "one child right" <<  std::endl;
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
			std::cout << "one child left" <<  std::endl;
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
		delete parent;
	}
}

void BinaryTree::insert_node(Node *& parent, int data)  {
	// if node is empty, add node
	std::cout << "part 1" << std::endl;
	if (parent == nullptr) {
		parent = new Node();
		parent = create_node(data);
	}
	// otherwise, recur down the tree
	else {
		if (data >= parent->data) {
			insert_node(parent->left, data);
		}
		else if (data <= parent->data) {
			insert_node(parent->right, data);
		}
	}
}

void BinaryTree::list_nodes(Node * parent) {
	if(parent != nullptr) {
		std::cout << " " << parent->data << std::endl;
		// go through both left and right nodes
		if(parent->left != nullptr) {
			list_nodes(parent->left);
		} 
		if (parent->right != nullptr) {
			list_nodes(parent->right);
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
	BinaryTree newTree;

	newTree.add(2);
	newTree.add(9);
	newTree.add(1);
	newTree.add(8);
	newTree.add(7);
	newTree.add(3);
	newTree.add(5);
	newTree.add(6);
	newTree.add(0);

	std::cout << "count : " << newTree.get_count() << std::endl;
	std::cout << "list : " << std::endl;
	newTree.list();
	std::cout << "9 is found: " << newTree.search(9) << std::endl;


	newTree.list();
	return 0;
}