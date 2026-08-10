func containsDuplicate(nums []int) bool {
    numsSet := make(map[int]struct{})
    for _, n := range nums {
        if _, exists := numsSet[n]; exists {
            return true
        }
        numsSet[n] = struct{}{}
    }
    return false
    
}