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
			while(dummy->next != NULL)
				dummy = dummy->next;

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

	Node* reverse(Node* head){
		Node *prev, *curr, *next;
		prev = NULL;
		curr = head;
		next = head;

		while(curr != NULL){
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		return prev; 
	}

}  // namespace sll

using namespace sll;

int main() {
	Node* head = new Node();

	int n, tmp;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> tmp;
		*head << tmp;		
	}
	head = head->next;

	cout << head << endl;
	cout << reverse(head) << endl;

	return 0;
}