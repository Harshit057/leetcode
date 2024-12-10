#include <queue>
#include <vector>
using namespace std;

// Assuming ListNode is already defined in the included header file

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Custom comparator for the priority queue
        auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };

        // Min-heap to store the current heads of the linked lists
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);

        // Push the head of each linked list into the heap
        for (auto list : lists) {
            if (list) minHeap.push(list);
        }

        // Dummy node to simplify result list construction
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        // Process the heap
        while (!minHeap.empty()) {
            // Extract the smallest node
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            // Add it to the result list
            current->next = smallest;
            current = current->next;

            // Push the next node from the same list into the heap
            if (smallest->next) {
                minHeap.push(smallest->next);
            }
        }

        // Return the merged list
        return dummy->next;
    }
};
