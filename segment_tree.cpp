#include <iostream>
#include <vector>

class SegmentTree {
private:
  std::vector<int> tree;
  int n;

  void build(const std::vector<int>& data, int node, int start, int end) {
    if (start == end) {
      /**
       * @brief Leaf node will have a single element
       * 
       * 
       */
      tree[node] = data[start];
    }
    else {
      int mid = (start + end) / 2;
      /**
       * @brief Recursively build the segment tree
       * 
       * 
       */
      build(data, 2 * node, start, mid);
      build(data, 2 * node + 1, mid + 1, end);
      /**
       * @brief Internal node will have the sum of both of its children
       * 
       * 
       */
      tree[node] = tree[2 * node] + tree[2 * node + 1];
    }


  }

  void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
      // Leaf node
      tree[node] = val;
    }
    else {
      int mid = (start + end) / 2;

      if (start <= idx && idx <= mid) {
        /**
         * @brief If idx is in the left child, recurse on the left child
         * 
         * 
         */
        update(2 * node, start, mid, idx, val);
      }
      else {
        /**
         * @brief If idx is in the right child, recurse on the right child
         * 
         * 
         */
        update(2 * node + 1, mid + 1, end, idx, val);
      }
      
      tree[node] = tree[2 * node] + tree[2 * node + 1];
    }


  }

  int query(int node, int start, int end, int L, int R) {
    if (R < start || end < L) {
      // range represented by a node is completely outside the given range
      return 0;
    }
    if (L <= start && end <= R) {
      // range represented by a node is completely inside the given range
      return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;

    int left_sum = query(2 * node, start, mid, L, R);
    int right_sum = query(2 * node + 1, mid + 1, end, L, R);

    return left_sum + right_sum;
  }

public:
  SegmentTree(const std::vector<int>& data) {
    n = data.size();
    tree.resize(4 * n);

    build(data, 1, 0, n - 1);
  }

  void update(int idx, int val) {
    update(1, 0, n - 1, idx, val);
    
  }

  int query(int L, int R) {
    return query(1, 0, n - 1, L, R);

  }


};

int main() {
  std::vector<int> data = {1, 3, 5, 7, 9, 11};
  SegmentTree segTree(data);

  // Query the sum of values in range [1, 3]
  std::cout << "Sum of values in range [1, 3]: " << segTree.query(1, 3) << std::endl;

  // Update: set data[1] to 10
  segTree.update(1, 10);

  // Query again after the update
  std::cout << "Sum of values in range [1, 3] after update: " << segTree.query(1, 3) << std::endl;

  return 0;
}
