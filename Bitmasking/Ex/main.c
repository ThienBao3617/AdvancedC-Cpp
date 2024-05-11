#include <stdio.h>
#include <stdint.h>


#define GENDER        1 << 0  // Bit 0: gender (0 = male, 1 = female)
#define TSHIRT        1 << 1  // Bit 1: tshirt (0 = no, 1 = yes)
#define HAT           1 << 2  // Bit 2: hat (0 = no, 1 = yes)
#define SHOES         1 << 3  // Bit 3: shoes (0 = no, 1 = yes)
#define GUN           1 << 4  // Bit 4: gun (0 = no, 1 = yes)
#define SWORD         1 << 5  // Bit 5: sword (0 = no, 1 = yes)
#define SHIELD        1 << 6  // Bit 6: shield (0 = no, 1 = yes)
#define SELF_HEALING  1 << 7  // Bit 7: self_healing (0 = no, 1 = yes)

void enableFeature(uint8_t *features, uint8_t feature) {
    *features |= feature;
}

void disableFeature(uint8_t *features, uint8_t feature) {
    *features &= ~feature;
}


int isFeatureEnabled(uint8_t features, uint8_t feature) {
    return (features & feature) != 0;
}

void listSelectedFeatures(uint8_t features) {
    printf("Selected Features:\n");

    if (features & GENDER) {
        printf("- Gender\n");
    }
    if (features & TSHIRT) {
        printf("- T-Shirt\n");
    }
    if (features & HAT) {
        printf("- Hat\n");
    }
    if (features & SHOES) {
        printf("- Shoes\n");
    }
    if (features & GUN) {
        printf("- Gun\n");
    }
    if (features & SWORD) {
        printf("- Sword\n");
    }
    if (features & SHIELD) {
        printf("- Shield\n");
    }
    if (features & SELF_HEALING) {
        printf("- Self_healing\n");
    }

    for (int i = 0; i < 8; i++)
    {
        printf("feature selected: %d\n", (features >> i) & 1);
    }
}



int main() {
    uint8_t options = 0;

    // Add more features
    enableFeature(&options, GENDER | TSHIRT | HAT | GUN | SELF_HEALING);

    disableFeature(&options, HAT);

    // List selected features
    listSelectedFeatures(options);
    
    return 0;
}



