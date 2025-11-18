// ESP32 practical projects demo with pattern cycling
#include "freertos/FreeRTOS.h" // FreeRTOS
#include "freertos/task.h" // Tasks
#include "driver/gpio.h" // GPIO

#define LED GPIO_NUM_2 // LED

static void pattern_task(void *arg) { // Pattern task
  int mode = 0; // Current mode
  while (true) { // Loop
    mode = (mode + 1) % 3; // Cycle modes
    if (mode == 0) { // Blink
      gpio_set_level(LED, 1); vTaskDelay(pdMS_TO_TICKS(200)); gpio_set_level(LED, 0); vTaskDelay(pdMS_TO_TICKS(200));
    } else if (mode == 1) { // Quick pulse
      gpio_set_level(LED, 1); vTaskDelay(pdMS_TO_TICKS(50)); gpio_set_level(LED, 0); vTaskDelay(pdMS_TO_TICKS(400));
    } else { // Long ON
      gpio_set_level(LED, 1); vTaskDelay(pdMS_TO_TICKS(800)); gpio_set_level(LED, 0); vTaskDelay(pdMS_TO_TICKS(100));
    } // End mode
  } // End loop
}

void app_main(void) { // Entry
  gpio_set_direction(LED, GPIO_MODE_OUTPUT); // Output
  xTaskCreate(pattern_task, "pattern", 2048, NULL, 5, NULL); // Start task
} // End app_main

