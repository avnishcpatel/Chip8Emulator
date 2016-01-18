  //
  //  chip8_opcodes.hpp
  //  Chip8_Emulator
  //
  //  Created by Avnish on 1/17/16.
  //  Copyright © 2016 masuroson. All rights reserved.
  //

#ifndef chip8_opcodes_hpp
#define chip8_opcodes_hpp

#define NUM_OF_REGISTERS 16
#define STACK_DEPTH 16
#define MEMORY_SIZE 4096

#define START_PC_OFFSET 0x200

#define FONT_SET_SIZE 0x50

#define NUM_OF_KEYS 16

#define DISPLAY_HEIGHT 64
#define DISPLAY_WIDTH 32

#define ANNN 0xA000 // ANNN: Sets I to address NNN

#endif /* chip8_opcodes_hpp */
