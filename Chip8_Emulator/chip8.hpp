//
//  chip8.hpp
//  Chip8_Emulator
//
//  Interface for Chip8 CPU Emulator
//
//  Created by Avnish on 1/8/16.
//  Copyright © 2016 masuroson. All rights reserved.
//

#ifndef chip8_hpp
#define chip8_hpp

#include <cstring>
#include "chip8_opcodes.hpp"


class chip8 {
  
public:
  
  chip8() { initialize(); }
  
  ~chip8() { }
  
  unsigned char * getGFX() { return gfx; }
  unsigned char * getKeys() { return keys; }  //
  
  bool drawFlagIsSet() { return drawFlag; }
  
  /* Set up emulator to valid start state */
  void initialize();
  
  /* Emulate a single cycle of emulation */
  void emulateCycle();
  
private:
  
  unsigned char chip8_fontset[FONT_SET_SIZE] =
  {
    0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
    0x20, 0x60, 0x20, 0x20, 0x70, // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
    0x90, 0x90, 0xF0, 0x10, 0x10, // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
    0xF0, 0x10, 0x20, 0x40, 0x40, // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90, // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
    0xF0, 0x80, 0x80, 0x80, 0xF0, // C
    0xE0, 0x90, 0x90, 0x90, 0xE0, // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
    0xF0, 0x80, 0xF0, 0x80, 0x80  // F
  };
  
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
  
  unsigned char keys[NUM_OF_KEYS];     // Input
  
  // Display Resolution : 64 x 32
  // Graphics are drawn to the screen solely by drawing sprites,
  // which are 8 pixels wide and may be from 1 to 15 pixels in height.
  // Sprite pixels that are set flip the color of the corresponding screen
  // pixel, while unset sprite pixels do nothing. The carry flag (VF) is set
  // to 1 if any screen pixels are flipped from set to unset when a sprite
  // is drawn and set to 0 otherwise.
  // Graphics Pixel Map
  unsigned char gfx[DISPLAY_HEIGHT * DISPLAY_WIDTH];
  
  bool drawFlag;
  
  /* Loads game at <filename> into memory starting at START_PC_OFFSET */
  bool loadGame(char * filename);
  
  /* Returns appropriate function pointer with appropriate args using opcode 
   TODO: void decodeInstruction(unsigned short opcode);
   */
};


#endif /* chip8_hpp */
