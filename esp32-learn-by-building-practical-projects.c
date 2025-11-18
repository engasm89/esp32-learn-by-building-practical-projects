/*
 * Course: Esp32 Learn By Building Practical Projects
 * Platform: ESP32
 * Author: Ashraf S A AlMadhoun
 * 
 * Description:
 * This code demonstrates the core concepts taught in the "Esp32 Learn By Building Practical Projects" course.
 * It provides a practical implementation that students can study, modify, and
 * use as a foundation for their own projects.
 * 
 * Learning Objectives:
 * - Understand the fundamental principles covered in this course
 * - Practice implementing the concepts with real code
 * - Build a working example that can be extended
 * 
 * Hardware Requirements:
 * - Development board (ESP32)
 * - Components as specified in CIRCUIT.md
 * - USB cable for programming
 * 
 * Pin Connections:
 * Refer to CIRCUIT.md for detailed wiring diagrams and pin assignments.
 * 
 * Usage:
 * 1. Review the code structure and comments
 * 2. Connect hardware according to CIRCUIT.md
 * 3. Upload code to your development board
 * 4. Monitor serial output for debugging
 * 
 * Course Link: https://www.udemy.com/course/esp32-learn-by-building-practical-projects/
 * Repository: https://github.com/engasm89/esp32-learn-by-building-practical-projects
 * 
 * Copyright (c) 2025 Ashraf S A AlMadhoun
 * Licensed under MIT License
 */

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

void app_main(void) { // Program entry point
  gpio_set_direction(LED, GPIO_MODE_OUTPUT); // Output
  xTaskCreate(pattern_task, "pattern", 2048, NULL, 5, NULL); // Start task
} // End of main function

