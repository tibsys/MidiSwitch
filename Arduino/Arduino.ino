/*
   This program manages the USB switch pedal.

   Dependencies:
   - MIDIUSB library. To install it, use the library manager in Arduino IDE.

   The hardware is based on
   - M-AUDIO EX-P expression pedal
   - Arduino Pro Micro board

   The pedal is based on a simple switch (or two). We send VCC and react when we receive VCC on A0 (and A1 for second switch).

   Created: 2020-05-25
   Version: 1.0
   Author: Tristan Israël <tristan@alefbet.net
   
   https://www.alefbet.net
*/

#include <MIDIUSB.h>

/**
 * Constants
 */
const bool DEBUG = false;
const int PEDAL_SWITCH_1_INPUT = A0;  //first switch on digital input 2
const int PEDAL_SWITCH_2_INPUT = A1;  //first switch on digital input 3
const uint8_t PEDAL_SWITCH_ON = 127; //Maximum value in MIDI CC
const uint8_t PEDAL_SWITCH_OFF = 0; //Maximum value in MIDI CC
const uint8_t MIDI_CC_FOOTCONTROLLER_1 = 80; //Value for General purpose controller 1 Control Change message
const uint8_t MIDI_CC_FOOTCONTROLLER_2 = 81; //Value for General purpose controller 2 Control Change message
const uint8_t PEDAL_SWITCH_1 = 1;
const uint8_t PEDAL_SWITCH_2 = 2;
uint8_t SWITCH_1_LAST_VALUE = 0;
uint8_t SWITCH_2_LAST_VALUE = 0;

/** 
 * Variables
 */
uint8_t currentSwitch1_State = false;
uint8_t currentSwitch2_State = false;
long debounce_delay = 50;
long last_read = 0;

void setup() {
  pinMode(PEDAL_SWITCH_1_INPUT, INPUT);
  pinMode(PEDAL_SWITCH_2_INPUT, INPUT);
  
  if(DEBUG) {
    Serial.begin(115200);
    Serial.println("MIDI Switch pedal initialized and ready!");
  } else {
    Serial.begin(31250);
  }

  sendPedalPosition(PEDAL_SWITCH_1, false);
  sendPedalPosition(PEDAL_SWITCH_2, false);
}

void loop() {
  //Debounce
  if(millis() - last_read < debounce_delay) {
    return 0;
  }

  last_read = millis();
    
  int switch1_currentValue = analogRead(PEDAL_SWITCH_1_INPUT);   
  //The hardware must use a pull-down resistor
  bool newSwitch1_State = switch1_currentValue > 0;  

  if(newSwitch1_State != currentSwitch1_State) {    
    currentSwitch1_State = newSwitch1_State;
    
    if(!newSwitch1_State) {
      SWITCH_1_LAST_VALUE = !SWITCH_1_LAST_VALUE;
      
      if(DEBUG) {
        Serial.print("Switch 1 is "); Serial.println(SWITCH_1_LAST_VALUE ? "ON" : "OFF");
        //Serial.print("val1="); Serial.println(switch1_currentValue);        
      }
      
      sendPedalPosition(PEDAL_SWITCH_1, SWITCH_1_LAST_VALUE);
    }    
  }

  int switch2_currentValue = analogRead(PEDAL_SWITCH_2_INPUT);   
  //The hardware must use a pull-down resistor
  bool newSwitch2_State = switch2_currentValue > 0;  

  if(newSwitch2_State != currentSwitch2_State) {    
    currentSwitch2_State = newSwitch2_State;
    
    if(!newSwitch2_State) {
      SWITCH_2_LAST_VALUE = !SWITCH_2_LAST_VALUE;
      
      if(DEBUG) {
        Serial.print("Switch 2 is "); Serial.println(SWITCH_2_LAST_VALUE ? "ON" : "OFF");
        //Serial.print("val2="); Serial.println(switch2_currentValue);        
      }
      
      sendPedalPosition(PEDAL_SWITCH_2, SWITCH_2_LAST_VALUE);
    }    
  }
}

/**
 * Sends the pedal position to the MIDI controller
 */
void sendPedalPosition(uint8_t pedalSwitch, bool active) {
  if(pedalSwitch == PEDAL_SWITCH_1) {
    sendControlChange(MIDI_CC_FOOTCONTROLLER_1, active ? PEDAL_SWITCH_ON : PEDAL_SWITCH_OFF);
  } else {
    sendControlChange(MIDI_CC_FOOTCONTROLLER_2, active ? PEDAL_SWITCH_ON : PEDAL_SWITCH_OFF);
  }
}

/**
 * Sends a control change message to the MIDI controller
 * control - the CC message identifier (0-127)
 * value - the value associated to the message (0-127)
 */
void sendControlChange(byte control, byte value) {
  midiEventPacket_t event = {0xB, 0xB0, control, value};
  if(DEBUG) {
    Serial.print(control); Serial.print(":"); Serial.println(value);
  }

  MidiUSB.sendMIDI(event);
  MidiUSB.flush();
}
