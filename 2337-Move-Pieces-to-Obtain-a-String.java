class Solution {
    private Map<Character, Integer> createFrequencyMap(String str) {
        Map<Character, Integer> frequencyMap = new HashMap<>();
        frequencyMap.put('L', 0);
        frequencyMap.put('R', 0);

        for (char c : str.toCharArray()) {
            if (frequencyMap.containsKey(c)) {
                frequencyMap.put(c, frequencyMap.get(c) + 1);
            }
        }

        return frequencyMap;
    }

    public boolean canChange(String start, String target) {
        // Early return if the strings are already equal
        if (start.equals(target)) {
            return true;
        }

        // Check if the frequency maps match
        if (!createFrequencyMap(start).equals(createFrequencyMap(target))) {
            return false;
        }

        int startIndex = 0, targetIndex = 0;
        int startLength = start.length(), targetLength = target.length();

        // Two-pointer traversal to match positions
        while (startIndex < startLength && targetIndex < targetLength) {
            // Skip blank spaces ('_') in both strings
            while (startIndex < startLength && start.charAt(startIndex) == '_') {
                startIndex++;
            }
            while (targetIndex < targetLength && target.charAt(targetIndex) == '_') {
                targetIndex++;
            }

            // If one pointer reaches the end, break
            if (startIndex == startLength || targetIndex == targetLength) {
                break;
            }

            // Check for mismatched characters
            char startChar = start.charAt(startIndex);
            char targetChar = target.charAt(targetIndex);
            if (startChar != targetChar) {
                return false;
            }

            // Validate movement constraints
            if (targetChar == 'L' && startIndex < targetIndex) {
                return false; // 'L' can only move left
            }
            if (targetChar == 'R' && startIndex > targetIndex) {
                return false; // 'R' can only move right
            }

            // Move both pointers forward
            startIndex++;
            targetIndex++;
        }

        return true;
    }
}
