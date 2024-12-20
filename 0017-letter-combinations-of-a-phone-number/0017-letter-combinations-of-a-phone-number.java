import java.util.*;

public class Solution {
    public List<String> letterCombinations(String digits) {
        // Mapping of digits to corresponding letters
        String[] digitToChar = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        // Base case: if input is empty
        if (digits == null || digits.isEmpty()) {
            return new ArrayList<>();
        }

        // Resultant list to store combinations
        List<String> result = new ArrayList<>();
        backtrack(digits, 0, new StringBuilder(), digitToChar, result);
        return result;
    }

    private void backtrack(String digits, int index, StringBuilder current, String[] digitToChar, List<String> result) {
        // Base case: if the current combination is complete
        if (index == digits.length()) {
            result.add(current.toString());
            return;
        }

        // Get the characters corresponding to the current digit
        int digit = digits.charAt(index) - '0';
        String possibleChars = digitToChar[digit];

        // Explore all possible characters for the current digit
        for (char ch : possibleChars.toCharArray()) {
            current.append(ch);
            backtrack(digits, index + 1, current, digitToChar, result);
            current.deleteCharAt(current.length() - 1); // Backtrack
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Example 1
        String digits1 = "23";
        System.out.println(solution.letterCombinations(digits1)); // ["ad","ae","af","bd","be","bf","cd","ce","cf"]

        // Example 2
        String digits2 = "";
        System.out.println(solution.letterCombinations(digits2)); // []

        // Example 3
        String digits3 = "2";
        System.out.println(solution.letterCombinations(digits3)); // ["a","b","c"]
    }
}
