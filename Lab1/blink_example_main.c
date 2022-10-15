/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"

static const char *TAG = "";

/* Use project configuration menu (idf.py menuconfig) to choose the GPIO to blink,
   or you can edit the following line and set a number here.
*/
//#define BLINK_GPIO GPIO_NUM_2
//#define LED_PIN GPIO_NUM_17
#define PUSH_BUTTON_PIN GPIO_NUM_13

//static uint8_t s_led_state = 0;
//
//#ifdef CONFIG_BLINK_LED_RMT
//static led_strip_t *pStrip_a;

//static void blink_led(void)
//{
//    /* If the addressable LED is enabled */
//    if (s_led_state) {
//        /* Set the LED pixel using RGB from 0 (0%) to 255 (100%) for each color */
//        pStrip_a->set_pixel(pStrip_a, 0, 16, 16, 16);
//        /* Refresh the strip to send data */
//        pStrip_a->refresh(pStrip_a, 100);
//    } else {
//        /* Set all LED off to clear all pixels */
//        pStrip_a->clear(pStrip_a, 50);
//    }
//}

//static void configure_led(void)
//{
//    //ESP_LOGI(TAG, "Example configured to blink addressable LED!");
//    /* LED strip initialization with the GPIO and pixels number*/
//    pStrip_a = led_strip_init(CONFIG_BLINK_LED_RMT_CHANNEL, BLINK_GPIO, 1);
//    /* Set all LED off to clear all pixels */
//    pStrip_a->clear(pStrip_a, 50);
////    gpio_reset_pin(BLINK_GPIO);
////    /* Set the GPIO as a push/pull output */
////    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
//}

//#elif CONFIG_BLINK_LED_GPIO
//
//static void blink_led(void)
//{
//    /* Set the GPIO level according to the state (LOW or HIGH)*/
//    gpio_set_level(BLINK_GPIO, s_led_state);
//}
//
//static void configure_led(void){
//	    gpio_reset_pin(BLINK_GPIO);
//	    /* Set the GPIO as a push/pull output */
//	    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
//}

static void configure_button(void)
{
    gpio_set_pull_mode(PUSH_BUTTON_PIN, GPIO_PULLDOWN_ONLY);
    gpio_set_level(PUSH_BUTTON_PIN, 0);
    gpio_set_direction(PUSH_BUTTON_PIN, GPIO_MODE_INPUT);
}

//#endif

void app_main(void)
{

    /* Configure the peripheral according to the LED type */
    configure_button();
   // configure_led();
    int current_state;
    int last_state = 1;
    int mssv = 0;
    while (1) {
//        ESP_LOGI(TAG, "Turning the LED %s!", s_led_state == true ? "ON" : "OFF");
//        ESP_LOGI(TAG, " ");
//        blink_led();
        /* Toggle the LED state */
//        s_led_state = !s_led_state;
    	mssv += 1;
    	if (mssv >= 100) {mssv = 0; printf("1912791\n"); }
//        vTaskDelay(CONFIG_BLINK_PERIOD / portTICK_PERIOD_MS);
    	current_state = gpio_get_level(PUSH_BUTTON_PIN);

    	if (last_state == 1 && current_state == 0){
    		ESP_LOGI(TAG, "esp32");
    		//printf("esp32\n");
    	}
    	else if (last_state == 0 && current_state == 1) {}
    	last_state = current_state;

    	vTaskDelay(1);

    }

}
