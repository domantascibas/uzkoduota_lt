#include "mbed.h"
#include "puzzle.h"
#include "MagnetService.h"
#include "PaintingPuzzle.h"
#include "MotionSensorPuzzle.h"
// #include "rtos.h"
// #include "HCSR04.h"
// #include "MFRC522.h"

// #define BUFF_SIZE 128
// #define DIST_UPDATE_INTERVAL 0.2
// #define TESTMODE true

DigitalOut led(D13);

// InterruptIn bigButton(PB_13);//(USER_BUTTON); //USER_BUTTON == PC_13

// //SRF05 sr(PC_1, PC_0);   // Trigger, Echo
// HCSR04 sr(PC_1, PC_0);
// //SRF05 sr2(PA_4, PB_0);  // Trigger, Echo
// HCSR04 sr2(PC_8, PC_6);
// //SRF05 sr3(PA_1, PA_0);  // Trigger, Echo
// //HCSR04 sr3(PB_15, PB_14);       //PB_14, PB_13
// MFRC522    RfChip   (PC_12, PC_11, PC_10, PD_2, PC_9);

// Ticker distTick;
Ticker blinky;

//magnets PH_1, PH_0, PC_15, PC_14
//leds PB_7, PA_15, PA_14, PA_13

Serial pc(USBTX, USBRX);

Puzzle *painting_puzzle = new PaintingPuzzle();
Puzzle *motion_sensor_puzzle = new MotionSensorPuzzle();
//NfcPuzzle
//DistanceSensorPuzzle
//SafePuzzle

void blinky_ISR() {
  led = !led;
}

int main() {
  led = 0;
  blinky.attach(&blinky_ISR, 1.0);
  magnets.turnOff(MAG1);  //activate trap door
  painting_puzzle->activate();
  while(1) {
    painting_puzzle->solve();
    __WFI();
  }
}