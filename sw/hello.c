#include <stdio.h>
// #include <read_hwvariation.h>



void read_hwvariation(int hw_variation) {
    printf("HW Variation: %d\n", hw_variation);
    switch(hw_variation) {
        case 0:
            // Change ADC sampling rate to 1ms
            printf("ADC sampling rate set to 1ms\n");
            break;
        case 1:
            // Change ADC sampling rate to 2ms
            printf("ADC sampling rate set to 2ms\n");
            break;
        default:
            printf("Invalid HW Variation\n");
            break;
    }
    //return 0;
    
}
int main() {
    int hw_variation;
    printf("Enter HW Variation: ");
    // Provide HW variation as an input to the function
    scanf("%d", &hw_variation);
   // Read-HW variation and change adc sampling rate
    read_hwvariation(hw_variation);
    return 0;
}



