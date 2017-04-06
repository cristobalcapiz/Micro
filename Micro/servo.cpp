#include <stdio.h>
#include <mraa.h>

#define SERVO_PIN 6

int alto,bajo;

int main(void)
{
	mraa_pwm_context pwm;
	mraa_init();
	pwm = mraa_pwm_init(SERVO_PIN);
        mraa_pwm_period_us(pwm, 2000);
	mraa_pwm_enable(pwm, 1); 
	while(1)
	{
		printf("Periodo en alto: ");
		alto = scanf("%d",&alto);
		bajo = 100 - alto;
		mraa_pwm_write(pwm, alto);
		sleep(3);
	}
}

