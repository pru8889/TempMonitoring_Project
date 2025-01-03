#ifndef READ_HWVARIATION_H
#define READ_HWVARIATION_H


namespace hw_variation {

    //Define enum for the hardware variations
    typedef enum {
        REV_A = 0U,
        REV_B = 1U
    } hw_variation_enum_t;

    //Define constants for the hardware variations
    const float REV_A_OFFSET = 1.0f;
    const float REV_B_OFFSET = 0.1f;

    hw_variation_enum_t read_hwvariation(int hw_variation);

}

#endif 