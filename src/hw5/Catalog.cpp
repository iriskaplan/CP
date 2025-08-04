// Created by Iris, Liel & Eliav.

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

typedef pair<ll, ll> pll;

void fastio() {
	ios::sync_with_stdio(0);
	cin.tie(0);
}

class Node {
  public:
  Node* parent;
  ll label;
  ll idx;
  ll rank;

  Node(Node* parent, ll label, ll idx, ll rank)
      : parent(parent), label(label), idx(idx), rank(rank) {}
};

Node make_set(ll idx, ll label) {
  return {nullptr, label, idx, 0};
}

Node& find_set(Node &v) {
  if (v.parent == nullptr) {
    return v;
  }
  v.parent = &find_set(*v.parent);
  return *v.parent;
}

void union_sets(Node &a, Node &b) {
  Node* rep_a = &find_set(a);
  Node *rep_b = &find_set(b);
  if (rep_a != rep_b) {
    if (rep_a->rank < rep_b->rank)
      swap(rep_a, rep_b);
    rep_b->parent = rep_a;
    if (rep_a->rank == rep_b->rank)
      rep_a ->rank += 1;
  }
}

int main() {
  fastio();
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    ll n, q, label;
    cin >> n >> q;

    vector<Node> nodes;
    nodes.reserve(n);
    unordered_map<ll, Node*> values;

    for (ll j = 0; j < n; j++) {
      cin >> label;
      Node node = make_set(j, label);
      nodes.push_back(node);
      Node* node_ptr = &nodes.back();
      if (values.find(label) != values.end()) {
        union_sets(*values[label], *node_ptr);
      }
      values[label] = node_ptr;
    }

    cout << "Case " << i + 1<< ":" << "\n";
    ll op;
    for (ll k = 0; k < q; k++) {
      cin >> op;
      if (op == 1) {
        ll old_label, new_label;;
        cin >> old_label >> new_label;
        if (values.find(old_label) != values.end()) {
          Node* old_ptr = values[old_label];
          find_set(*old_ptr).label = new_label;
          if (values.find(new_label) != values.end()) {
            union_sets(*old_ptr, *values[new_label]);
          }
          values[new_label] = &find_set(*old_ptr);
          if (old_label != new_label)
            values.erase (old_label);
        }
      } else if (op == 2) {
        ll idx;
        cin >> idx;
        cout << find_set(nodes[idx - 1]).label << "\n";
      }
    }
  }
  return 0;
}
