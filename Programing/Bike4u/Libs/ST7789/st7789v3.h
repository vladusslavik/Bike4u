#pragma once

#include "main.h"
//#include "image_map.h"
#include "symbols_font.h"
#include "string.h"

extern SPI_HandleTypeDef hspi1;

#define SPI_ST7789V3		hspi1

#define DCX_CMD     HAL_GPIO_WritePin(D_C_GPIO_Port, D_C_Pin,0)
#define DCX_DATA    HAL_GPIO_WritePin(D_C_GPIO_Port, D_C_Pin,1)
#define CS_HIGH     HAL_GPIO_WritePin(CS_ST7789_GPIO_Port, CS_ST7789_Pin,1)
#define CS_LOW      HAL_GPIO_WritePin(CS_ST7789_GPIO_Port, CS_ST7789_Pin,0)
#define BLK_HIGH    HAL_GPIO_WritePin(BLK_GPIO_Port, BLK_Pin,1)
#define BLK_LOW     HAL_GPIO_WritePin(BLK_GPIO_Port, BLK_Pin,0)
#define RES_HIGH    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4,1)
#define RES_LOW     HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4,0)

//#define WIDTH  240
//#define HEIGHT 280
#define		PIXELS			67200
#define		BYTES_FOR_PIXEL	3

#define		BUFFER_SCREEN	900
#define		REMAINDER		(PIXELS * BYTES_FOR_PIXEL) / BUFFER_SCREEN

#define		CHAR_LINE_BUF	COLUMNS*MAX_SIZE*BYTES_FOR_PIXEL

//#define X_OFFSET	0
//#define Y_OFFSET	20

//************COMANDS************//

//******SOFTWARE Reset******//
#define	SWRESET				0x01


	  //******POWER******//
#define	SLPIN				0x10	//Sleep in
#define SLPOUT				0x11	//Sleep out
#define PWCTRL1				0xD0	//Power control 1
#define PWCTRL2				0xE8	//Power control 2
#define DISPOFF				0x28	//Display off
#define DISPON				0x29	//Display on

	  //******Geometry******//
#define PTLON				0x12	//Partial display mode off
#define	NORON				0x13	//Normal display mode on
#define	INVOFF				0x20	//Inversion off
#define INVON				0x21	//Inversion on
#define MADCTL				0x36	//Memory Data Access Control

	  //Effect and set pixels//
#define	CASET				0x2A	// Column address set
#define RASET				0x2B	// Row address set
#define VSCRDEF				0x33	// Vertical Scrolling definiton
#define VSCSAD				0x37 	// Vertical Scroll Start
#define TEOFF				0x34	// Tearing Effects line off
#define	TEON				0x35	// Tearing Effects line on

	   //Write parameters//
#define	RAMWR				0x2C	// Write Memory
#define WRDISBV				0x51	// Write Display Brightness

	  // Another functions//
#define IDMOFF				0x38	// Idle mode off
#define	IDMON				0x39	// Idle mode on
#define COLMOD				0x3A	// Interface pixels format


#define bit_interface		bit18_pixel
#define bit18_pixel			0b01100110
//************COMANDS************//

typedef enum{
	NORMAL = 0, Y_Mirror = 0x80 , X_Mirror = 0x40, X_Y_Mirror = 0xC0,
	X_Y_Exchange = 0x20, X_Y_Exchange_Y_Mirror = 0xA0,
	X_Y_Exchange_X_Mirror = 0x60, X_Y_Exchange_X_Y_Mirror = 0xE0

}rotation;

typedef enum{
	WRTParameters, FillScrn,  WriteChar

}DMA_Actions;

//****************Functions****************//

void InitST7789V3(rotation parameter);
void FillScreen(uint8_t red, uint8_t green, uint8_t blue);
void DataAccessControl(rotation parameter);
void SetPixel(uint16_t x_position, uint16_t y_position,
		uint8_t red, uint8_t green, uint8_t blue); // rgb per 6 bits(0-63)
void SetBrighteness(uint8_t brightness);
void DrawPicture(const uint8_t* data);
void DrawChar(uint16_t x, uint16_t y, char ch, uint8_t *color, uint8_t size);
void ST7789_SetScrollArea(uint16_t tfa, uint16_t vsa, uint16_t bfa);
void ST7789_SetScrollAddress(uint16_t vsp);
void ST7789_DrawChar(uint16_t x, uint16_t y, char ch, uint8_t *color, uint8_t size);
void ST7789_DrawString(uint16_t x, uint16_t y, const char *str, uint8_t *color, uint8_t size);
void ST7789_FillRectangle(uint16_t x_s, uint16_t y_s, uint16_t x_e, uint16_t y_e, uint8_t *color);
void ST7789_Sleep_In();
void ST7789_Sleep_Out();
