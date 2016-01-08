//
//  chip8.h
//  Chip8_Emulator
//
//  Interface for Chip8 CPU Emulator
//
//  Created by Avnish on 1/8/16.
//  Copyright © 2016 masuroson. All rights reserved.
//

#ifndef chip8_h
#define chip8_h

#define NUM_OF_REGISTERS 16
#define DISPLAY_HEIGHT 64
#define DISPLAY_WIDTH 32

public class Chip8
{
    // 4096 memory locations of 8 bits
    // first 512 reserved for interpreter
    // Uppermost 256 reserved for display refresh
    // 96 below that are for call stack, internal use, etc.
  
    // 16 8-bit registers V0 to VF, where VF is carry flag
    // Reserve 64 bytes for call stack
  
    // two timers at 60 HZ: Delay, Sound
  
    // Hex keyboard
  
    // Display Resolution : 64 x 32
    // Graphics are drawn to the screen solely by drawing sprites,
    // which are 8 pixels wide and may be from 1 to 15 pixels in height.
    // Sprite pixels that are set flip the color of the corresponding screen
    // pixel, while unset sprite pixels do nothing. The carry flag (VF) is set
    // to 1 if any screen pixels are flipped from set to unset when a sprite
    // is drawn and set to 0 otherwise.
  
private:
  unsigned char V[NUM_OF_REGISTERS];
  
  
};


#endif /* chip8_h */
