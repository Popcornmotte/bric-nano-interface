/*****************************************************************************
* |	This version:   V1.0
* | Date        :   2022
*
******************************************************************************/
#include "KEY_APP.h"
#include "LCD_GUI.h"
#include "LCD_Driver.h"
#include "LCD_BMP.h"
#include <bcm2835.h>
// #include "Debug.h"


int selection = 0;
int optionCount = 3;

// if use 2019-06-20-raspbian-buster
// sudo nano /boot/config.txt
// add:
// gpio=6,19,5,26,13,21,20,16=pu

// the info above this comment need verfication. -Phil

void Draw_Init(void)
{
    LCD_Clear(BLACK);

    GUI_DisString_EN(10, 10, "Main Menu", &Font16, GUI_BACKGROUND, WHITE);

    //GUI_DrawRectangle(8, 35, 240, 55, WHITE, DRAW_EMPTY, DOT_PIXEL_DFT); Doesnt Work??
    GUI_DisString_EN(10, 40, "- Option 0", &Font12, GUI_BACKGROUND, WHITE);

    GUI_DisString_EN(10, 55, "- Option 1", &Font12, GUI_BACKGROUND, WHITE);

    GUI_DisString_EN(10, 70, "- Option 2", &Font12, GUI_BACKGROUND, WHITE);

    //GUI_DisString_EN(10, 100, "Debug", &Font16, WHITE, BLACK);



//    /* Press */
//    GUI_DrawRectangle(40, 60, 60, 80, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
//    GUI_DisString_EN(43, 60, "P", &Font24, GUI_BACKGROUND, BLUE);
//
//    /* Left */
//    GUI_DrawRectangle(20, 60, 40, 80, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
//    GUI_DisString_EN(23, 60, "L", &Font24, GUI_BACKGROUND, BLUE);
//
//    /* Right */
//    GUI_DrawRectangle(60, 60, 80, 80, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
//    GUI_DisString_EN(63, 60, "R", &Font24, GUI_BACKGROUND, BLUE);
//
//    /* Up */
//    GUI_DrawRectangle(40, 40, 60, 60, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
//    GUI_DisString_EN(43, 40, "U", &Font24, GUI_BACKGROUND, BLUE);
//
//    /* Down */
//    GUI_DrawRectangle(40, 80, 60, 100, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
//    GUI_DisString_EN(43, 80, "D", &Font24, GUI_BACKGROUND, BLUE);
//
//    /* Key1 */
//    GUI_DrawRectangle(95, 40, 120, 60, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
//    GUI_DisString_EN(98, 43, "K1", &Font16, GUI_BACKGROUND, BLUE);
//
//    /* Key2	*/
//    GUI_DrawRectangle(95, 60, 120, 80, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
//    GUI_DisString_EN(98, 63, "K2", &Font16, GUI_BACKGROUND, BLUE);
//
//    /* Key3 */
//    GUI_DrawRectangle(95, 80, 120, 100, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
//    GUI_DisString_EN(98, 83, "K3", &Font16, GUI_BACKGROUND, BLUE);
}

void KEY_Listen(void)
{
    Draw_Init();
    int lastKey = -1;
    for(;;) {
        int lastSelection = selection;
        if(GET_KEY_UP == 0) {
            while(GET_KEY_UP == 0) {
                //GUI_DrawRectangle(40, 40, 60, 60, BLUE, DRAW_FULL, DOT_PIXEL_DFT);
                // GUI_DisString_EN(43, 40, "U", &Font24, GUI_BACKGROUND, BLUE);
            }
            //if (lastKey != 0) {
                selection = abs((selection+1)%optionCount);
                printf("\nSelection is %i",selection);
                
            //}
            
            //GUI_DrawRectangle(40, 40, 60, 60, WHITE, DRAW_FULL, DOT_PIXEL_DFT);
            //GUI_DrawRectangle(40, 40, 60, 60, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
            //GUI_DisString_EN(43, 40, "U", &Font24, GUI_BACKGROUND, BLUE);
            lastKey = 0;
        }
        if(GET_KEY_DOWN == 0) {
            while(GET_KEY_DOWN == 0) {
                //GUI_DrawRectangle(40, 80, 60, 100, BLUE, DRAW_FULL, DOT_PIXEL_DFT);
                // GUI_DisString_EN(43, 80, "D", &Font24, GUI_BACKGROUND, BLUE);
            }
            //if (lastKey != 1) {
                selection = abs((selection-1)%optionCount); 
                printf("\nSelection is %i",selection);
            //}
            //GUI_DrawRectangle(40, 80, 60, 100, WHITE, DRAW_FULL, DOT_PIXEL_DFT);
            //GUI_DrawRectangle(40, 80, 60, 100, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
            //GUI_DisString_EN(43, 80, "D", &Font24, GUI_BACKGROUND, BLUE);
            lastKey = 1;
        }
        if(GET_KEY3 == 0) {
            while(GET_KEY3 == 0) {
                //GUI_DrawRectangle(95, 80, 120, 100, BLUE, DRAW_FULL, DOT_PIXEL_DFT);
                // GUI_DisString_EN(98, 83, "K3", &Font16, GUI_BACKGROUND, BLUE);
                
            }
            LCD_ShowBmp();
            DEV_Delay_ms(5000);
            //bcm2835_spi_end();
            //bcm2835_close();
            //DEV_ModuleExit();
            //GUI_DrawRectangle(95, 80, 120, 100, WHITE, DRAW_FULL, DOT_PIXEL_DFT);
            //GUI_DrawRectangle(95, 80, 120, 100, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
            //GUI_DisString_EN(98, 83, "K3", &Font16, GUI_BACKGROUND, BLUE);
        }
        
        if(lastSelection!=selection){
            Draw_Init();
            switch (selection) {
            case 0:
                //GUI_DrawRectangle(8, 35, 240, 55, WHITE, DRAW_EMPTY, DOT_PIXEL_DFT);
                GUI_DisString_EN(10, 40, "- Option 0", &Font12, GUI_BACKGROUND, YELLOW);
                break;
            case 1:
                //GUI_DrawRectangle(8, 50, 240, 70, WHITE, DRAW_EMPTY, DOT_PIXEL_DFT);
                GUI_DisString_EN(10, 55, "- Option 1", &Font12, GUI_BACKGROUND, YELLOW);
                break;
            case 2:
                //GUI_DrawRectangle(8, 50, 240, 70, WHITE, DRAW_EMPTY, DOT_PIXEL_DFT);
                GUI_DisString_EN(10, 70, "- Option 2", &Font12, GUI_BACKGROUND, YELLOW);
                break;
            }
        }
        
        /*
        if(GET_KEY_UP == 0) {
            while(GET_KEY_UP == 0) {
                GUI_DrawRectangle(40, 40, 60, 60, BLUE, DRAW_FULL, DOT_PIXEL_DFT);
                // GUI_DisString_EN(43, 40, "U", &Font24, GUI_BACKGROUND, BLUE);
            }
            GUI_DrawRectangle(40, 40, 60, 60, WHITE, DRAW_FULL, DOT_PIXEL_DFT);
            GUI_DrawRectangle(40, 40, 60, 60, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
            GUI_DisString_EN(43, 40, "U", &Font24, GUI_BACKGROUND, BLUE);
        }
        if(GET_KEY_DOWN == 0) {
            while(GET_KEY_DOWN == 0) {
                GUI_DrawRectangle(40, 80, 60, 100, BLUE, DRAW_FULL, DOT_PIXEL_DFT);
                // GUI_DisString_EN(43, 80, "D", &Font24, GUI_BACKGROUND, BLUE);
            }
            GUI_DrawRectangle(40, 80, 60, 100, WHITE, DRAW_FULL, DOT_PIXEL_DFT);
            GUI_DrawRectangle(40, 80, 60, 100, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
            GUI_DisString_EN(43, 80, "D", &Font24, GUI_BACKGROUND, BLUE);
        }
        if(GET_KEY_LEFT == 0) {
            while(GET_KEY_LEFT == 0) {
                GUI_DrawRectangle(20, 60, 40, 80, BLUE, DRAW_FULL, DOT_PIXEL_DFT);
                // GUI_DisString_EN(23, 60, "L", &Font24, GUI_BACKGROUND, BLUE);
            }
            GUI_DrawRectangle(20, 60, 40, 80, WHITE, DRAW_FULL, DOT_PIXEL_DFT);
            GUI_DrawRectangle(20, 60, 40, 80, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
            GUI_DisString_EN(23, 60, "L", &Font24, GUI_BACKGROUND, BLUE);
        }
        if(GET_KEY_RIGHT == 0) {
            while(GET_KEY_RIGHT == 0) {
                GUI_DrawRectangle(60, 60, 80, 80, BLUE, DRAW_FULL, DOT_PIXEL_DFT);
                // GUI_DisString_EN(63, 60, "R", &Font24, GUI_BACKGROUND, BLUE);
            }
            GUI_DrawRectangle(60, 60, 80, 80, WHITE, DRAW_FULL, DOT_PIXEL_DFT);
            GUI_DrawRectangle(60, 60, 80, 80, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
            GUI_DisString_EN(63, 60, "R", &Font24, GUI_BACKGROUND, BLUE);
        }
        if(GET_KEY_PRESS == 0) {
            while(GET_KEY_PRESS == 0) {
                GUI_DrawRectangle(40, 60, 60, 80, BLUE, DRAW_FULL, DOT_PIXEL_DFT);
                // GUI_DisString_EN(43, 60, "P", &Font24, GUI_BACKGROUND, BLUE);
            }
            GUI_DrawRectangle(40, 60, 60, 80, WHITE, DRAW_FULL, DOT_PIXEL_DFT);
            GUI_DrawRectangle(40, 60, 60, 80, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
            GUI_DisString_EN(43, 60, "P", &Font24, GUI_BACKGROUND, BLUE);
        }
        if(GET_KEY1 == 0) {
            while(GET_KEY1 == 0) {
                GUI_DrawRectangle(95, 40, 120, 60, BLUE, DRAW_FULL, DOT_PIXEL_DFT);
                // GUI_DisString_EN(98, 43, "K1", &Font16, GUI_BACKGROUND, BLUE);
            }
            GUI_DrawRectangle(95, 40, 120, 60, WHITE, DRAW_FULL, DOT_PIXEL_DFT);
            GUI_DrawRectangle(95, 40, 120, 60, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
            GUI_DisString_EN(98, 43, "K1", &Font16, GUI_BACKGROUND, BLUE);
        }
        if(GET_KEY2 == 0) {
            while(GET_KEY2 == 0) {
                GUI_DrawRectangle(95, 60, 120, 80, BLUE, DRAW_FULL, DOT_PIXEL_DFT);
                // GUI_DisString_EN(98, 63, "K2", &Font16, GUI_BACKGROUND, BLUE);
            }
            GUI_DrawRectangle(95, 60, 120, 80, WHITE, DRAW_FULL, DOT_PIXEL_DFT);
            GUI_DrawRectangle(95, 60, 120, 80, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
            GUI_DisString_EN(98, 63, "K2", &Font16, GUI_BACKGROUND, BLUE);
        }
        if(GET_KEY3 == 0) {
            while(GET_KEY3 == 0) {
                GUI_DrawRectangle(95, 80, 120, 100, BLUE, DRAW_FULL, DOT_PIXEL_DFT);
                // GUI_DisString_EN(98, 83, "K3", &Font16, GUI_BACKGROUND, BLUE);
            }
            GUI_DrawRectangle(95, 80, 120, 100, WHITE, DRAW_FULL, DOT_PIXEL_DFT);
            GUI_DrawRectangle(95, 80, 120, 100, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
            GUI_DisString_EN(98, 83, "K3", &Font16, GUI_BACKGROUND, BLUE);
        }*/
    }
}