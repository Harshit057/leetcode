import java.util.PriorityQueue;
import java.util.Map;
import java.util.HashMap;

public class Solution {
    public String repeatLimitedString(String s, int repeatLimit) {
        // Step 1: Count the frequencies of characters
        Map<Character, Integer> freqMap = new HashMap<>();
        for (char c : s.toCharArray()) {
            freqMap.put(c, freqMap.getOrDefault(c, 0) + 1);
        }

        // Step 2: Create a max-heap (PriorityQueue in Java)
        PriorityQueue<Character> maxHeap = new PriorityQueue<>((a, b) -> b - a);
        maxHeap.addAll(freqMap.keySet());

        StringBuilder result = new StringBuilder();

        while (!maxHeap.isEmpty()) {
            char current = maxHeap.poll(); // Pick the largest character
            int count = freqMap.get(current);

            // Determine how many times we can add the current character
            int addCount = Math.min(count, repeatLimit);
            for (int i = 0; i < addCount; i++) {
                result.append(current);
            }

            // Update the frequency map
            freqMap.put(current, count - addCount);

            // If there are remaining occurrences of the current character
            if (freqMap.get(current) > 0) {
                if (maxHeap.isEmpty()) {
                    // No other characters available to break the streak
                    break;
                }

                // Use the next largest character as a breaker
                char next = maxHeap.poll();
                result.append(next);

                // Update the frequency map for the breaker
                freqMap.put(next, freqMap.get(next) - 1);
                if (freqMap.get(next) > 0) {
                    maxHeap.offer(next);
                }

                // Push the current character back into the heap
                maxHeap.offer(current);
            }
        }

        return result.toString();
    }
}
