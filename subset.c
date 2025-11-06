#include <stdio.h>

void sumOfSubsets(int set[], int n, int target, int subset[], int subsetSize, int sum, int index) {
    // If the current sum equals target, print the subset
    if (sum == target) {
        printf("{ ");
        for (int i = 0; i < subsetSize; i++)
            printf("%d ", subset[i]);
        printf("}\n");
        return;
    }

    // If sum exceeds target or we reach the end, return
    if (sum > target || index == n)
        return;

    // Include the current element in the subset
    subset[subsetSize] = set[index];
    sumOfSubsets(set, n, target, subset, subsetSize + 1, sum + set[index], index + 1);

    // Exclude the current element and move to the next
    sumOfSubsets(set, n, target, subset, subsetSize, sum, index + 1);
}

int main() {
    int n, target;

    printf("Enter number of elements in the set: ");
    scanf("%d", &n);

    int set[n];
    printf("Enter %d distinct integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter the target sum: ");
    scanf("%d", &target);

    int subset[n];  // temporary array to store current subset

    printf("\nSubsets with sum %d:\n", target);
    sumOfSubsets(set, n, target, subset, 0, 0, 0);

    return 0;
}
