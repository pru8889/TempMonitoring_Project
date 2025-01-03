#ifndef READ_HWVARIATION_H
#define READ_HWVARIATION_H

//Define enum for hardware variations
typedef enum {
    REV_A = 0U,
    REV_B = 1U
} hw_variation_enum_t;

//Define constants for hardware variations
#define REV_A_OFFSET 1.0f
#define REV_B_OFFSET 0.1f

//Declare function prototype
hw_variation_enum_t read_hwvariation(int hw_variation);
#endif // READ_HWVARIATION_H 