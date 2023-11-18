#include <stdio.h>


struct Product {
    char name[50];
    float unitPrice;
    float gstPercentage;
    int quantity;
};

float calculateGST(struct Product *product) {
    return (product->unitPrice * product->gstPercentage / 100) * product->quantity;
}

int main() {
    
    struct Product basket[] = {
        {"Leather wallet", 1100, 18, 1},
        {"Umbrella", 900, 12, 4},
        {"Cigarette", 200, 28, 3},
        {"Honey", 100, 0, 2},
    };

    int numProducts = sizeof(basket) / sizeof(basket[0]);

    
    float maxGST = 0;
    int maxGSTIndex = -1;

    for (int i = 0; i < numProducts; ++i) {
        float gstAmount = calculateGST(&basket[i]);
        if (gstAmount > maxGST) {
            maxGST = gstAmount;
            maxGSTIndex = i;
        }
    }


    if (maxGSTIndex != -1) {
        printf("Product with maximum GST amount: %s\n", basket[maxGSTIndex].name);
    } else {
        printf("No products in the basket.\n");
    }

    
    float totalAmount = 0;

    for (int i = 0; i < numProducts; ++i) {
        totalAmount += (basket[i].unitPrice + calculateGST(&basket[i])) * basket[i].quantity;
    }
    printf("Total amount to be paid to the shopkeeper: %.2f\n", totalAmount);
    return 0;
}
