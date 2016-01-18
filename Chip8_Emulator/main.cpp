//
//  main.cpp
//  Chip8_Emulator
//
//  Created by Avnish on 1/8/16.
//  Copyright © 2016 masuroson. All rights reserved.
//
#include <iostream>
#include "chip8.hpp"

chip8 myChip8; // Declare globally

int main(int argc, const char * argv[])
{
    // OpenGL initialization
  
  myChip8.initialize();
  
  
  // Emulation loop
  for(;;)
  {
    
  }
  
  return 0;
}
