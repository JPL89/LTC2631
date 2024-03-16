// @File		LTC2631.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		15/03/24
//
//
// Copyright (C) 2024 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
#ifndef LTC2631_H
#define LTC2631_H

#define LTC2631_SLA_W 0x20

// COMMAND:
// 0x00: Write to Input Register
// 0x01: Update (Power Up) DAC Register
// 0x03: Write to and Update (Power Up) DAC Register
// 0x04: Power Down
// 0x06: Select Internal Reference
// 0x07: Select External Reference
//
void LTC2631_Write(unsigned char command, unsigned int data)
{
    data <<= 4;
    
    Wire_Start();
    Wire_Write(LTC2631_SLA_W);
    Wire_Write(command);
    Wire_Write((unsigned char)((data >> 8) & 0xFF));
    Wire_Write((unsigned char)(data & 0xFF));
    Wire_Stop();
}

#endif 
