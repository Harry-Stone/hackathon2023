#include <Arduino.h>

void blinkLights( void *pvParameters );

void blinkLights(void *pvParameters)  {
    while(1) {
        digitalWrite(14, HIGH);
        digitalWrite(32,LOW);
        vTaskDelay( 100 / portTICK_PERIOD_MS );
        digitalWrite(14, LOW);
        digitalWrite(32,LOW);
        vTaskDelay( 100 / portTICK_PERIOD_MS );
        digitalWrite(14, HIGH);
        digitalWrite(32,LOW);
        vTaskDelay( 100 / portTICK_PERIOD_MS );
        digitalWrite(14, LOW);
        digitalWrite(32,LOW);
        vTaskDelay( 400 / portTICK_PERIOD_MS );
        digitalWrite(14, LOW);
        digitalWrite(32,HIGH);
        vTaskDelay( 100 / portTICK_PERIOD_MS );
        digitalWrite(14, LOW);
        digitalWrite(32,LOW);
        vTaskDelay( 100 / portTICK_PERIOD_MS );
        digitalWrite(14, LOW);
        digitalWrite(32,HIGH);
        vTaskDelay( 100 / portTICK_PERIOD_MS );
        digitalWrite(14, LOW);
        digitalWrite(32,LOW);
        vTaskDelay( 400 / portTICK_PERIOD_MS );
    }
}
