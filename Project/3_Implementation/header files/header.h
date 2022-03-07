/**
 * @file header.h
 * @author TR AJEESH
 * @brief This the project on automation movement of vacuum cleaner shortly 
 * tittled as "SMART VACUUM CLEANER" 
 * @version 0.1
 * @date 2022-03-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "BLEHM10.h"
#include "ESP8266.h"
#include "NewPing.h"
#include "LiquidCrystal.h"
#include "Relay.h"
#include "StepperMotor.h"
#include "Button.h"


// Pin Definitions
#define BLEHM10_PIN_TXD	11
#define BLEHM10_PIN_RXD	10
#define WIFI_PIN_TX	3
#define WIFI_PIN_RX	2
#define HCSR04_PIN_TRIG	5
#define HCSR04_PIN_ECHO	4
#define LCD_PIN_RS	13
#define LCD_PIN_E	12
#define LCD_PIN_DB4	6
#define LCD_PIN_DB5	7
#define LCD_PIN_DB6	8
#define LCD_PIN_DB7	9
#define RELAYMODULE_PIN_SIGNAL	A3
#define STEPPER_PIN_STEP	A1
#define STEPPER_PIN_DIR	A4
#define REFLECTIVEIR_PIN_COLL	A5



// Global variables and defines
String blehm10Str = "";
// ====================================================================
// vvvvvvvvvvvvvvvvvvvv ENTER YOUR WI-FI SETTINGS  vvvvvvvvvvvvvvvvvvvv
//
const char *SSID     = "WIFI-SSID"; // Enter your Wi-Fi name 
const char *PASSWORD = "PASSWORD" ; // Enter your Wi-Fi password
//
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
// ====================================================================
char* const host = "www.google.com";
int hostPort = 80;
#define stepperDelayTime  1000
// object initialization
BLEHM10 blehm10(BLEHM10_PIN_RXD,BLEHM10_PIN_TXD);
ESP8266 wifi(WIFI_PIN_RX,WIFI_PIN_TX);
NewPing hcsr04(HCSR04_PIN_TRIG,HCSR04_PIN_ECHO);
LiquidCrystal lcd(LCD_PIN_RS,LCD_PIN_E,LCD_PIN_DB4,LCD_PIN_DB5,LCD_PIN_DB6,LCD_PIN_DB7);
Relay relayModule(RELAYMODULE_PIN_SIGNAL);
StepperMotor stepper(STEPPER_PIN_STEP,STEPPER_PIN_DIR);
Button ReflectiveIR(REFLECTIVEIR_PIN_COLL);
