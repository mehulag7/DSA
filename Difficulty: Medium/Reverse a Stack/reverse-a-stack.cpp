class Solution {
  public:
  void insertAtBottom(stack<int> &st, int val) {
    // If stack is empty, push the value
    if (st.empty()) {
        st.push(val);
        return;
    }

    // Pop the top element
    int topVal = st.top();
    st.pop();

    // Recurse for the rest of the stack
    insertAtBottom(st, val);

    // Push the popped element back
    st.push(topVal);
}

// Function to reverse the stack
void reverseStack(stack<int> &st) {
    // Base case: If stack is empty, return
    if (st.empty()) return;

    // Pop the top element
    int topVal = st.top();
    st.pop();

    // Recursively reverse the remaining stack
    reverseStack(st);

    // Insert the popped element at the bottom
    insertAtBottom(st, topVal);
}
};