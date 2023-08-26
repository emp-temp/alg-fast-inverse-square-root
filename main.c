#include <stdio.h>

float invsqrt(float);

int main() {
    float input;
    scanf("%f", &input);
    printf("%f", invsqrt(input));
    return 0;
}

float invsqrt(float x) {
    long X, Y;
    float y;
    X = *(long*)&x;
    Y = 0x5F3759DF - (X >> 1);
    y = *(float*)&Y;

    float x2 = x * 0.5f;
    for (int i = 0; i < 10; i++) {
        y = y * (1.5f - (x2 * y * y));
    }
    return y;
}