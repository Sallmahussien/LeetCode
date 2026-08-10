func isAnagram(s string, t string) bool {
    sSet := make(map[rune]int)
    tSet := make(map[rune]int)

    for _, c := range s {
        sSet[c]++
    }

    for _, c := range t {
        tSet[c]++
    }

    for _, c := range s {
        if sSet[c] != tSet[c] {
            return false
        }
    }

    return len(sSet) == len(tSet)
}