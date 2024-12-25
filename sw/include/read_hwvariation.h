#ifndef READ_HWVARIATION_H
#define READ_HWVARIATION_H

//Define enum for the hardware variations
typedef enum {
    REV_A = 0,
    REV_B = 1
} hw_variation_enum_t;

hw_variation_enum_t read_hwvariation(int hw_variation);
#endif // READ_HWVARIATION_H 