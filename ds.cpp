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
	struct subset {
		int parent;
		int rank;
	};

	int find(subset* subsets, int i) {
		if(subsets[i].parent == -1) return i;
		subsets[i].parent = find(subsets, subsets[i].parent);
		return subsets[i].parent;
	}

	void make_union(subset* subsets, int x, int y) {
		if(subsets[x].rank < subsets[y].rank) {
			subsets[x].parent = y;
			subsets[y].rank += subsets[x].rank;
		} else {
			subsets[y].parent = x;
			subsets[x].rank += subsets[y].rank;
		}
	}

	vector<vector<int>> mst(int v, vector<vector<int>>& edges) {
		sort(all(edges), [](vector<int>& left, vector<int>& right) {
			return left[2] < right[2];
		});

		subset* subsets = (subset*)malloc(v * sizeof(subset));
		vector<vector<int>> g;
		int x, y;

		for(int i = 0; i < v; i++) {
			subsets[i].parent = -1;
			subsets[i].rank	  = 1;
		}

		for(auto edge : edges) {
			x = find(subsets, edge[0]);
			y = find(subsets, edge[1]);
			if(x != y) {
				g.push_back(edge);
				make_union(subsets, x, y);
			}
		}

		return g;
	}
}  // namespace kruskals_mst

int main() {
	int n, e;
	vector<vector<int>> edges;
	int d, s, w;

	cin >> n >> e;

	for(int i = 0; i < e; i++) {
		cin >> d >> s >> w;
		edges.push_back({d, s, w});
	}

	cout << kruskals_mst::mst(n, edges) << endl;
}