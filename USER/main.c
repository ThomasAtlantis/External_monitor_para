#include "stm32f10x.h"
#include "delay\delay.h"
#include "usart\usart.h"
#include "adc\adc.h"

int main() {
	u16 value;
	float voltValue;
	SystemInit();
	delay_init();
	adc_init();
	uart_init(9600);
	while (1) {
		value = get_Adc(0);
		voltValue = (float) value * (3.3 / 4096);
		printf("voltValue: %f\r\n", voltValue);
		delay_ms(500);
	}
}
