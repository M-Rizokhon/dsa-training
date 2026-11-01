// Time: O(V + E)
// Space: O(V)


#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};





class Solution {
public:
    unordered_map<int, Node*> visited;
    void dfs(Node* node, Node* copy_node) {
        if (visited.count(node->val)) {
            return;
        }

        visited[copy_node->val] = copy_node;
        for (auto& nd : node->neighbors) {
            if (visited.count(nd->val)) {
                copy_node->neighbors.push_back(visited[nd->val]);
                continue;
            }

            Node* new_nd = new Node(nd->val);
            copy_node->neighbors.push_back(new_nd);
            dfs(nd, copy_node->neighbors.back());
        }

    }


    Node* cloneGraph(Node* node) {
        if (!node) return node;
        Node* res = new Node(node->val);

        dfs(node, res);

        return res;
    }
};