#include <bits/stdc++.h>

#include "templates.h"
using namespace std;

namespace sll {
	struct Node {
		int data;
		Node* next;

		Node() {
			data = 0;
			next = NULL;
		}

		Node(int _data) {
			data = _data;
			next = NULL;
		}

		Node* operator<<(int rhs) {
			Node* dummy = this;
			while(dummy->next != NULL) dummy = dummy->next;

			dummy->next = new Node(rhs);
			return next;
		}
	};

	std::ostream& operator<<(std::ostream& os, Node* head) {
		os << "[";
		while(head->next != NULL) {
			os << head->data << ", ";
			head = head->next;
		}
		return os << head->data << "]";
	}

	Node* reverse(Node* head) {
		Node *prev, *curr, *next;
		prev = NULL;
		curr = head;
		next = head;

		while(curr != NULL) {
			next	   = curr->next;
			curr->next = prev;
			prev	   = curr;
			curr	   = next;
		}

		return prev;
	}

}  // namespace sll

namespace btrie {
	struct node {
		node* children[2];
		bool endofword;
	};

	void insert(node* root, int num) {
		int i = num & 1;
		if(num == 0) {
			root->endofword = true;
			return;
		}

		if(root->children[i] == NULL) {
			root->children[i] = new node();
		}

		insert(root->children[i], num >> 1);
	}

	void dfs(node* root, int value, int depth) {
		if(root->endofword) cout << value << "\t" << depth << endl;

		if(root->children[0] != NULL) dfs(root->children[0], value, depth + 1);

		if(root->children[1] != NULL)
			dfs(root->children[1], (1 << (depth)) + value, depth + 1);
	}

	int findMin(node* root, int num) {
		int i	  = 0;
		int value = 0;

		while(num != 0) {
			int idx = (num & 1) ^ 1;
			if(root->children[idx] != NULL)
				root = root->children[idx];
			else if(root->children[idx ^ 1] != NULL)
				root = root->children[idx ^ 1];
			else
				return value;

			value = (idx << i) + value;
			num	  = num >> 1;
			i++;
		}

		return value;
	}
}  // namespace btrie

namespace kruskals_mst {
	
}

int solve(int n, vector<int> arr) {
	
}

int main() {
	
}