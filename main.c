#include "stm32f10x.h"


void delay(uint32_t t) {
    while(t--) {
        __ASM("NOP");
    };
}

int main(void) {
    RCC->CR |= RCC_CR_HSEON;
    while((RCC->CR & RCC_CR_HSERDY) == 0);
    //Configure Flash latency
    FLASH->ACR |= FLASH_ACR_PRFTBE;
    FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
	FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_2;   
    //Configure prescalers
    RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1;
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV2;
    //Configure PLL multiplier to 72 MHz
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL));
    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLMULL9);

    RCC->CR |= RCC_CR_PLLON;
    while((RCC->CR & RCC_CR_PLLRDY) == 0);
    //Use PLL as system clock source
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
    RCC->CFGR |= (uint32_t)RCC_CFGR_SW_PLL;    
    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)0x08);
  
    //Configure GPIO
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
    GPIOC->CRH &= ~GPIO_CRH_CNF13;
    GPIOC->CRH |= GPIO_CRH_MODE13;

    
    while(1) {
        GPIOC->BSRR = GPIO_BSRR_BR13;
        delay(3000000);
        GPIOC->BSRR = GPIO_BSRR_BS13;
        delay(3000000);
        
        ;
    }
    return 0;
};