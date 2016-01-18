//
//  chip8.cpp
//  Chip8_Emulator
//
//  Created by Avnish on 1/17/16.
//  Copyright © 2016 masuroson. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "chip8.hpp"

void chip8::initialize()
{
  sp = I = opcode = NULL;
  pc = START_PC_OFFSET;
  drawFlag = false;
  
  memset(main_memory, NULL, MEMORY_SIZE);
  memset(V, NULL, NUM_OF_REGISTERS);
  memset(stack, NULL, STACK_DEPTH);
  memset(keys, NULL, NUM_OF_KEYS);
  memset(gfx, NULL, DISPLAY_HEIGHT * DISPLAY_WIDTH);
  
  // load font set into reserved memory
  for(int i = 0; i < FONT_SET_SIZE; i++)
  {
    main_memory[i] = chip8_fontset[i];
  }
}

void chip8::emulateCycle()
{
  // FETCH
  opcode = main_memory[pc] << 8 | main_memory[pc + 1];
  
  // DECODE & EXECUTE
  switch (opcode & 0xF000)
  {
    case ANNN:
      I = opcode & 0x0FFF;
      pc += sizeof(opcode);
      break;
    default:
      std::cerr << "Unknown opcode: " << std::hex << opcode << std::endl;
      break;
  }
 
  
  
}

/* Loads game at <filename> into memory starting at START_PC_OFFSET */

bool chip8::loadGame(char * filename)
{
  std::ifstream gameFile (filename, std::fstream::in | std::fstream::binary);
  
  if (gameFile.is_open()) {
    // Get length of file:
    gameFile.seekg (0, gameFile.end);
    auto length = gameFile.tellg();
    
    // Reset cursor to beginning of file and clear error flags
    gameFile.seekg (0, gameFile.beg);
    gameFile.clear();
    
    // Read file into memory at starting PC address
    gameFile.read((char *)&main_memory[START_PC_OFFSET],length);
    
    if (gameFile.eof())
    {
      return true;
    }
    else
    {
      std::cerr << "File read, but end-of-file not reached." << std::endl;
      return false;
    }
  }
  else
  {
    std::cerr << "File failed to open. Please check path: " << filename;
    std::cerr << std::endl;
    return false;
  }
}

/* Returns appropriate function pointer with appropriate args using opcode */
// void chip8::decodeInstruction(unsigned short opcode) { }
