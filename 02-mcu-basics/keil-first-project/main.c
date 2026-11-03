#include "stm32f10x.h"

int main(void)
{
    uint32_t i;

    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    GPIOC->CRH &= ~(0xFU << 20);
    GPIOC->CRH |=  (0x2U << 20);

    for (;;) {
        GPIOC->ODR ^= (1U << 13);
        for (i = 0; i < 200000U; i++) { }
    }
}
