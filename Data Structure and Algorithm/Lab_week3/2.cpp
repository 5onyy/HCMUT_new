// The best way to sort a singly linked list given the head pointer is probably using merge sort.

// Both Merge sort and Insertion sort can be used for linked lists. The slow random-access performance of a linked list makes other algorithms (such as quick sort) perform poorly, and others (such as heap sort) completely impossible. Since worst case time complexity of Merge Sort is O(nLogn) and Insertion sort is O(n^2), merge sort is preferred. 

// Additionally, Merge Sort for linked list only requires a small constant amount of auxiliary storage.

// To gain a deeper understanding about Merge sort on linked lists, let's implement mergeLists and mergeSortList function below

// Constraints:

// 0 <= list.length <= 10^4
// 0 <= node.val <= 10^6

// Use the nodes in the original list and don't modify ListNode's val attribute. 

// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode(int _val = 0, ListNode* _next = nullptr) : val(_val), next(_next) { }
// };

// // Merge two sorted lists
// ListNode* mergeSortList(ListNode* head);

// // Sort an unsorted list given its head pointer
// ListNode* mergeSortList(ListNode* head);

// You must use the nodes in the original list and must not modify ListNode's val attribute. 
// Hint: You should complete the function mergeLists first and validate it using our first testcase example

// Merge two sorted lists
ListNode* mergeLists(ListNode* a, ListNode* b) {
    if (!a) return b;
    if (!b) return a;
    
    if (a->val < b->val) {
        a->next = mergeLists(a->next, b);
        return a;
    } else {
        b->next = mergeLists(a, b->next);
        return b;
    }
}


// Sort and unsorted list given its head pointer
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

ListNode* mergeSortList(ListNode* head) {
    if (!head || !head->next) return head; // Base case: 0 or 1 elements

    // Split the list into two halves
    ListNode* middle = findMiddle(head);
    ListNode* halfStart = middle->next;
    middle->next = nullptr;

    // Recursively sort both halves
    ListNode* left = mergeSortList(head);
    ListNode* right = mergeSortList(halfStart);

    // Merge the two sorted halves together
    return mergeLists(left, right);
}