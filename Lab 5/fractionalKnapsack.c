#include <stdio.h>

void main()
{
    int capacity, no_items, cur_weight, item;
    int used[10];
    float total_profit;
    int i;
    int weight[10];
    int value[10];

    //inputting necessary data
    printf("Enter the capacity of knapsack:\n");
    scanf("%d", &capacity);

    printf("Enter the number of items:\n");
    scanf("%d", &no_items);

    printf("Enter the weight and value of %d item:\n", no_items);
    for (i = 0; i < no_items; i++)
    {
        printf("Weight of object %d \t", i);
        scanf("%d", &weight[i]);
        printf("Value of object %d \t", i);
        scanf("%d", &value[i]);
    }

    //initializing all objects as not taken, i.e. 0
    for (i = 0; i < no_items; ++i)
        used[i] = 0;

    cur_weight = capacity; //current available weight as capacity

    while (cur_weight > 0)//while available weight is greater than 0
    {
        item = -1;
        for (i = 0; i < no_items; ++i)
            if ((used[i] == 0) &&
                ((item == -1) || ((float)value[i] / weight[i] > (float)value[item] / weight[item])))
                item = i;

        used[item] = 1;
        cur_weight = cur_weight - weight[item];
        total_profit = total_profit + value[item];
        if (cur_weight < 0)
        {
            total_profit = total_profit - value[item];
            total_profit = total_profit + (1 + (float)cur_weight / weight[item]) * value[item];
        }
    }

    printf("Filled the bag with objects valued %.2f \n", total_profit);
}