//
//  chip8.h
//  Chip8_Emulator
//
//  Interface for Chip8 CPU Emulator
//
//  Created by Avnish on 1/8/16.
//  Copyright © 2016 masuroson. All rights reserved.
//

#ifndef chip8_hpp
#define chip8_hpp

#define NUM_OF_REGISTERS 16
#define STACK_DEPTH 16
#define MEMORY_SIZE 4096

#define NUM_OF_KEYS 16

#define DISPLAY_HEIGHT 64
#define DISPLAY_WIDTH 32

public class Chip8
{
  
private:
  
  // 4096 memory locations of 8
  // first 512 reserved for font set
  // Uppermost 256 reserved for display refresh
  // 96 below that are for call stack, internal use, etc.
  
  unsigned char main_memory[MEMORY_SIZE];
  
  unsigned char V[NUM_OF_REGISTERS];  // Register Bank, with VF for carry
  
  unsigned short stack[STACK_DEPTH];  // Call stack
  unsigned short sp;                  // Current stack pointer
  
  unsigned short I;                   // Instruction Register (16 bits)
  unsigned short pc;                  // Program Counter
  
  unsigned short opcode;              // Current Opcode
  
  // two timers at 60 HZ
  unsigned char delay_timer;
  unsigned char sound_timer;
  
  
  unsigned char key[NUM_OF_KEYS];     // Input
  
  
  // Display Resolution : 64 x 32
  // Graphics are drawn to the screen solely by drawing sprites,
  // which are 8 pixels wide and may be from 1 to 15 pixels in height.
  // Sprite pixels that are set flip the color of the corresponding screen
  // pixel, while unset sprite pixels do nothing. The carry flag (VF) is set
  // to 1 if any screen pixels are flipped from set to unset when a sprite
  // is drawn and set to 0 otherwise.
  // Graphics Pixel Map
  unsigned char gfx[DISPLAY_HEIGHT * DISPLAY_WIDTH];
  
  void Fetch();
  void Decode();
  void Execute();
  
};


#endif /* chip8_hpp */
