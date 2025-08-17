#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n, choice, pos, value, i;

    printf("Enter size of Array: ");
    scanf("%d", &n);

    if (n > MAX_SIZE || n <= 0) {
        printf("Invalid size! Please enter a value between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\n************************************\n");
        printf("Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // Insert
                if (n >= MAX_SIZE) {
                    printf("Array is full! Cannot insert more elements.\n");
                    break;
                }

                printf("Enter position to insert (1 to %d): ", n + 1);
                scanf("%d", &pos);

                if (pos < 1 || pos > n + 1) {
                    printf("Invalid position!\n");
                    break;
                }

                printf("Enter value to insert: ");
                scanf("%d", &value);

                for (i = n; i >= pos; i--)
                    arr[i] = arr[i - 1];

                arr[pos - 1] = value;
                n++;
                printf("Element inserted successfully.\n");
                break;

            case 2:  // Delete
                if (n <= 0) {
                    printf("Array is empty! Nothing to delete.\n");
                    break;
                }

                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);

                if (pos < 1 || pos > n) {
                    printf("Invalid position!\n");
                    break;
                }

                for (i = pos - 1; i < n - 1; i++)
                    arr[i] = arr[i + 1];

                n--;
                printf("Element deleted successfully.\n");
                break;

            case 3:  // Search
                printf("Enter value to search: ");
                scanf("%d", &value);
                int found = 0;

                for (i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        printf("Element %d found at position %d.\n", value, i + 1);
                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("Element %d not found in the array.\n", value);
                break;

            case 4:  // Display
                if (n == 0) {
                    printf("Array is empty!\n");
                } else {
                    printf("Array elements: ");
                    for (i = 0; i < n; i++)
                        printf("%d ", arr[i]);
                    printf("\n");
                }
                break;

            case 5:  // Exit
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
