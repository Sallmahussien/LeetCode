void reverse(char* str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

bool isPalindrome(char* s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

char* shortestPalindrome(char* s) {
    int len = strlen(s);
    int r = len - 1, l = 0;

    // Find the longest palindromic prefix
    while (l < r) {
        if (isPalindrome(s, l, r)) {
            break;
        }
        r--;
    }

    // Compute the non-palindromic part
    int remaining_len = len - (r + 1);
    char* front = (char*)malloc(remaining_len + 1);

    // Copy the non-palindromic part and reverse it
    if (remaining_len > 0) {
        strncpy(front, s + r + 1, remaining_len);
        front[remaining_len] = '\\0';
        reverse(front, 0, remaining_len - 1);
    } else {
        front[0] = '\\0'; // If no characters are remaining, return an empty string
    }

    // Prepare the result string (front + original string)
    char* result = (char*)malloc(strlen(s) + remaining_len + 1);
    strcpy(result, front);
    strcat(result, s);

    // Free the allocated memory for the front string
    free(front);

    return result;
}
