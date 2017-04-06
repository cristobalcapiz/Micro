#include<mraa.h>
#define LED_PIN   13
#define SW_PIN    5
int value;

int main(void){
	mraa_gpio_context    ledPin;
	mraa_gpio_context    swPin;
	mraa_init();
	ledPin = mraa_gpio_init(LED_PIN);
	swPin = mraa_gpio_init(SW_PIN);

	mraa_gpio_dir(ledPin,MRAA_GPIO_OUT);
	mraa_gpio_dir(swPin,MRAA_GPIO_IN);

	while(1){
		value = mraa_gpio_read(swPin);
		if (value == 1){ mraa_gpio_write(ledPin,1);}
		else {mraa_gpio_write(ledPin,1);}
	}
}

