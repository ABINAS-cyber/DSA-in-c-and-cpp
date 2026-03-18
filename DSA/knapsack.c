#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float weight;
    float value;
    float ratio;
} Item;

int compareItems(const void* a, const void* b) {
    Item* itemA = (Item*)a;
    Item* itemB = (Item*)b;

    if (itemB->ratio > itemA->ratio) return 1;
    if (itemB->ratio < itemA->ratio) return -1;
    return 0;
}


void fractionalKnapsack(int n, Item items[], float capacity) {
    float totalValue = 0.0;
    float remainingCapacity = capacity;
    int i;


    for (i = 0; i < n; i++) {
        items[i].ratio = items[i].value / items[i].weight;
    }

    // 2. Sort all items in descending order of their ratio
    qsort(items, n, sizeof(Item), compareItems);

    printf("Items sorted by value/weight ratio (descending):\n");
    printf("Weight\tValue\tRatio\n");
    for (i = 0; i < n; i++) {
        printf("%.2f\t%.2f\t%.2f\n", items[i].weight, items[i].value, items[i].ratio);
    }
    printf("\n");


    for (i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity) {

            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
            printf("Added entire item (Weight: %.2f, Value: %.2f). Remaining capacity: %.2f\n", items[i].weight, items[i].value, remainingCapacity);
        } else {

            float fraction = remainingCapacity / items[i].weight;
            totalValue += items[i].value * fraction;
            remainingCapacity = 0; 
            printf("Added fractional part (Fraction: %.2f) of item (Weight: %.2f, Value: %.2f). Remaining capacity: %.2f\n", fraction, items[i].weight, items[i].value, remainingCapacity);
            break; 
        }
    }

    printf("\nMaximum total value in the knapsack: %.2f\n", totalValue);
}


int main() {
    int n;
    float capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];

    printf("Enter the weight and value for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d (Weight Value): ", i + 1);
        scanf("%f %f", &items[i].weight, &items[i].value);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%f", &capacity);

    fractionalKnapsack(n, items, capacity);

    return 0;
}

