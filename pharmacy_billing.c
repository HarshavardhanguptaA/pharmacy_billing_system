#include <stdio.h>
#include <string.h>

struct Medicine {
    char name[20];
    char batch[10];
    char expiry[10];
    float price;
    int quantity;
};

int main() {
    FILE *fp, *temp;
    struct Medicine m;
    char search[20];
    int reqQty;
    float total = 0;
    int found = 0;

    fp = fopen("C:\\Users\\Harshavardhan Gupta\\mini pjt\\medicine.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        printf("File error!\n");
        return 1;
    }

    printf("Enter medicine name: ");
    scanf("%s", search);

    printf("Enter required quantity: ");
    scanf("%d", &reqQty);

    while (fscanf(fp, "%s %s %s %f %d",
                  m.name, m.batch, m.expiry,
                  &m.price, &m.quantity) != EOF) {

        if (strcmp(m.name, search) == 0 && m.quantity >= reqQty) {
            found = 1;

            float cost = reqQty * m.price;
            total += cost;

            printf("\n--- BILL ---\n");
            printf("Medicine : %s\n", m.name);
            printf("Batch    : %s\n", m.batch);
            printf("Expiry   : %s\n", m.expiry);
            printf("Price    : %.2f\n", m.price);
            printf("Quantity : %d\n", reqQty);
            printf("Cost     : %.2f\n", cost);

            m.quantity -= reqQty;  // update stock
        }

        fprintf(temp, "%s %s %s %.2f %d\n",
                m.name, m.batch, m.expiry,
                m.price, m.quantity);
    }

    fclose(fp);
    fclose(temp);

    remove("medicine.txt");
    rename("temp.txt", "medicine.txt");

    if (!found) {
        printf("\nMedicine not found or insufficient stock!\n");
    } else {
        printf("\nTotal Bill Amount: %.2f\n", total);
    }

    return 0;
}
