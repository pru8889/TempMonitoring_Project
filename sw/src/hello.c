#include <stdio.h>
#include <read_hwvariation.h>

hw_variation_enum_t read_hwvariation(int hw_variation) {
    printf("HW Variation: %d\n", hw_variation);
    hw_variation_enum_t hw_variation_enum;
    //ToDO replace switch logic with simpler if else
    switch(hw_variation) {
        case 0:
            // Change ADC sampling rate to 1ms
            printf("REV-A hw detected ADC sampling rate set to 1 degree\n");
            //hw_variation_enum = hw_variation;
            break;
        case 1:
            // Change ADC sampling rate to 2ms
            printf("REV-B Hw detected ADC sampling rate set to 0.1 degree\n");
           // hw_variation_enum = hw_variation;
            break;
        default:
            printf("Invalid HW Variation\n");
            break;
    }
    return hw_variation_enum = hw_variation;
    //return hw_variation_enum;
    
}

int main() {
    int hw_variation;
    //hw_variation_enum_t hw_variation_enum_test = REV_A;
    printf("Enter HW Variation: ");
    // Provide HW variation as an input to the function
    scanf("%d", &hw_variation);
   // Read-HW variation and change adc sampling rate
    read_hwvariation(hw_variation);
   // printf("HW Variation Enum: %s\n", hw_variation_enum_to_string(hw_variation_enum_test));
    return 0;
}



