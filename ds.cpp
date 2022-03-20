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
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
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
        int i = 0;
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
            num = num >> 1;
            i++;
        }

        return value;
    }
}  // namespace btrie

namespace disjoin_sets {
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
        x = find(subsets, x);
        y = find(subsets, y);

        if(subsets[x].rank < subsets[y].rank) {
            subsets[x].parent = y;
            subsets[y].rank += subsets[x].rank;
        } else {
            subsets[y].parent = x;
            subsets[x].rank += subsets[y].rank;
        }
    }

}  // namespace disjoin_sets

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
            subsets[i].rank = 1;
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

    int sample() {
        int n, e;
        vector<vector<int>> edges;
        int s, d, w;

        cin >> n >> e;

        for(int i = 0; i < e; i++) {
            cin >> s >> d >> w;
            edges.push_back({s, d, w});
        }

        cout << kruskals_mst::mst(n, edges) << endl;

        return 0;
    }
}  // namespace kruskals_mst

namespace bin_idx_tree {
    struct tree {
        int* nodes;

        tree(int n) {
            n++;
            nodes = (int*)malloc(n * sizeof(int));
            memset(nodes, 0, n * sizeof(int));
        }

        int getSum(int idx) {
            int sum = 0;
            for(idx++; idx > 0; idx -= idx & (-idx)) sum += nodes[idx];
            return sum;
        }

        void update(int n, int idx, int val) {
            for(idx++; idx <= n; idx += idx & (-idx)) nodes[idx] += val;
        }

        vector<int> to_vec(int n) {
            n++;
            return vector<int>(nodes, nodes + n);
        }
    };

    int sample() {
        int n, tmp;
        vector<int> nums;

        cin >> n;

        for(int i = 0; i < n; i++) {
            cin >> tmp;
            nums.push_back(tmp);
        }

        cout << nums << endl;
        bin_idx_tree::tree root(n);

        for(int i = 0; i < n; i++) {
            root.update(n, i, nums[i]);
        }

        cout << root.to_vec(n) << endl;
        cout << root.getSum(4) << endl;

        root.update(n, 3, 1);

        cout << root.to_vec(n) << endl;
        cout << root.getSum(4) << endl;
        cout << root.getSum(2) << endl;

        return 0;
    }
}  // namespace bin_idx_tree

namespace avl_tree {
    /*
            Time Complexity:
                    Insertion - O(logn)
                    Deletion - O(logn)
                    balancing - O(1)
    */
    struct Node {
        int val;
        Node* left;
        Node* right;
        int height;

        Node(int _val) {
            val = _val;
            height = 1;
            left = NULL;
            right = NULL;
        }
    };

    int get_height(Node* root) {
        if(root == NULL) return 0;
        return root->height;
    }

    int get_diff(Node* root) {
        if(root == NULL) return 0;
        return get_height(root->left) - get_height(root->right);
    }

    Node* right_rotate(Node* root) {
        Node* tmp = root->left;
        root->left = tmp->right;
        tmp->right = root;

        root->height = 1 + max(get_height(root->left), get_height(root->right));
        tmp->height = 1 + max(get_height(tmp->left), get_height(tmp->right));

        return tmp;
    }

    Node* left_rotate(Node* root) {
        Node* tmp = root->right;
        root->right = tmp->left;
        tmp->left = root;

        root->height = 1 + max(get_height(root->left), get_height(root->right));
        tmp->height = 1 + max(get_height(tmp->left), get_height(tmp->right));

        return tmp;
    }

    Node* insert(Node* root, int val) {
        if(root == NULL)
            root = new Node(val);

        else if(val > root->val)
            root->right = insert(root->right, val);
        else if(val < root->val)
            root->left = insert(root->left, val);
        else
            return root;

        root->height = 1 + max(get_height(root->left), get_height(root->right));
        int diff = get_diff(root);

        if(diff > 1 and val < root->left->val) return right_rotate(root);

        if(diff < -1 and val > root->right->val) return left_rotate(root);

        if(diff > 1 and val > root->left->val) {
            root->left = left_rotate(root->left);
            return right_rotate(root);
        }

        if(diff < -1 and val < root->right->val) {
            root->right = right_rotate(root->right);
            return left_rotate(root);
        }

        return root;
    }

    Node* del(Node* root, int val) {
        if(root == NULL)
            return root;

        else if(val > root->val)
            root->right = del(root->right, val);

        else if(val < root->val)
            root->left = del(root->left, val);

        else {
            if(root->left == NULL) {
                Node* tmp = root->right;
                delete root;
                return tmp;
            }
            if(root->right == NULL) {
                Node* tmp = root->left;
                delete root;
                return tmp;
            }

            Node* succ_parent = root;
            Node* succ = root->right;

            while(succ->left != NULL) {
                succ_parent = succ;
                succ = succ->left;
            }

            root->val = succ->val;
            if(succ_parent != root)
                succ_parent->left = succ->right;
            else
                succ_parent->right = succ->right;

            delete succ;
        }

        if(root == NULL) return root;

        root->height = 1 + max(get_height(root->left), get_height(root->right));

        int diff = get_diff(root);

        if(diff > 1 and get_diff(root->left) >= 0) return right_rotate(root);
        if(diff < -1 and get_diff(root->right) <= 0) return left_rotate(root);

        if(diff > 1 and get_diff(root->left) < 0) {
            root->left = left_rotate(root->left);
            return right_rotate(root);
        }

        if(diff < -1 and get_diff(root->right) > 0) {
            root->right = right_rotate(root->right);
            return left_rotate(root);
        }

        return root;
    }

    void pre_order(Node* root) {
        if(root == NULL) return;
        cout << root->val << " ";
        pre_order(root->left);
        pre_order(root->right);
    }

    void sample() {
        int n, tmp;
        vector<int> arr;

        cin >> n;
        while(n--) {
            cin >> tmp;
            arr.push_back(tmp);
        }

        avl_tree::Node* root = NULL;

        for(int i : arr) root = avl_tree::insert(root, i);

        cout << "Original Array: " << endl;
        cout << arr << endl << endl;

        cout << "Tree (pre order)" << endl;
        avl_tree::pre_order(root);
        cout << endl << endl;

        cout << "Tree (pre order) After Deletion(10)" << endl;
        root = avl_tree::del(root, 10);
        avl_tree::pre_order(root);
        cout << endl;
    }

}  // namespace avl_tree

namespace search {
    int binary_search(vector<int>& arr, int val) {
        int left = 0, right = (int)arr.size() - 1;
        int mid;

        while(left <= right) {
            mid = left + (right - left) / 2;
            if(arr[mid] == val) return mid;

            if(arr[mid] < val)
                left = mid + 1;

            else
                right = mid - 1;
        }

        return (int)arr.size();
    }

    int ternary_search(vector<int>& arr, int val) {
        int left = 0, right = (int)arr.size() - 1;
        int mid1, mid2;

        while(left <= right) {
            mid1 = left + (right - left) / 3;
            mid2 = mid1 + (right - left) / 3;

            if(arr[mid1] == val) return mid1;

            if(arr[mid2] == val) return mid2;

            if(arr[mid1] > val)
                right = mid1 - 1;

            else if(arr[mid2] < val)
                left = mid2 + 1;

            else {
                left = mid1 + 1;
                right = mid2 - 1;
            }
        }

        return (int)arr.size();
    }

    void sample() {
        int n, val;
        cin >> n;
        vector<int> arr;

        while(n--) {
            arr.push_back(int());
            cin >> arr.back();
        }

        cin >> val;

        cout << "Binary search Output: ";
        cout << search::binary_search(arr, val) << endl;
        cout << "Ternary search Output: ";
        cout << search::ternary_search(arr, val) << endl;
    }

}  // namespace search

namespace dijkstra {
    const int inf = 1e9 + 7;
    auto comp = ([](auto lhs, auto rhs) { return lhs.first > rhs.first; });

    vector<int> sp(int n, int s, vector<vector<pair<int, int>>> graph) {
        vector<pair<int, int>> setp;
        setp.push_back({0, s});

        vector<int> dist(n, inf);
        dist[s] = 0;
        while(not setp.empty()) {
            pop_heap(setp.begin(), setp.end(), comp);
            auto [_, u] = setp.back();
            setp.pop_back();

            for(auto [w, v] : graph[u]) {
                if(dist[v] > dist[u] + w) {
                    if(dist[v] != inf) {
                        auto iter = find(setp.begin(), setp.end(),
                                         make_pair(dist[v], v));
                        iter->first = dist[u] + w;
                        make_heap(setp.begin(), setp.end(), comp);
                    } else {
                        setp.push_back({dist[u] + w, v});
                        push_heap(setp.begin(), setp.end(), comp);
                    }
                    dist[v] = dist[u] + w;
                }
            }
        }
        return dist;
    }

    void sample() {
        int n, e;
        int s, d, w;

        cin >> n >> e;
        vector<vector<pair<int, int>>> graph(n);

        for(int i = 0; i < e; i++) {
            cin >> s >> d >> w;
            graph[s].push_back({w, d});
            graph[d].push_back({w, s});
        }

        cout << dijkstra::sp(n, 0, graph) << endl;
    }
}  // namespace dijkstra

int main() {
    dijkstra::sample();
    return 0;
}