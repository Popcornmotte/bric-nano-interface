/*****************************************************************************
* |	This version:   V1.0
* | Date        :   2019-07-06
* | Info        :   Basic version
*
******************************************************************************/
#include "KEY_APP.h"
#include "LCD_GUI.h"
#include "LCD_Driver.h"
// #include "Debug.h"


short selection = 0;
short optionCount = 2;

// if use 2019-06-20-raspbian-buster
// sudo nano /boot/config.txt
// add:
// gpio=6,19,5,26,13,21,20,16=pu

void Draw_Init(void)
{
    LCD_Clear(BLACK);

    GUI_DisString_EN(10, 10, "Main Menu", &Font16, GUI_BACKGROUND, WHITE);

    GUI_DisString_EN(10, 40, "- Option 0", &Font12, GUI_BACKGROUND, WHITE);

    GUI_DisString_EN(10, 55, "- Option 1", &Font12, GUI_BACKGROUND, WHITE);


    GUI_DisString_EN(10, 100, "Debug", &Font16, WHITE, BLACK);



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
    short lastKey = -1;
    for(;;) {
        short lastSelection = selection;
        if(GET_KEY_UP == 0) {
            //while(GET_KEY_UP == 0) {
                //GUI_DrawRectangle(40, 40, 60, 60, BLUE, DRAW_FULL, DOT_PIXEL_DFT);
                // GUI_DisString_EN(43, 40, "U", &Font24, GUI_BACKGROUND, BLUE);
            //}
            if (lastKey == 0) {
                selection = (selection+1)%optionCount;
            }
            
            //GUI_DrawRectangle(40, 40, 60, 60, WHITE, DRAW_FULL, DOT_PIXEL_DFT);
            //GUI_DrawRectangle(40, 40, 60, 60, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
            //GUI_DisString_EN(43, 40, "U", &Font24, GUI_BACKGROUND, BLUE);
            lastKey = 0;
        }
        if(GET_KEY_DOWN == 0) {
            //while(GET_KEY_DOWN == 0) {
                //GUI_DrawRectangle(40, 80, 60, 100, BLUE, DRAW_FULL, DOT_PIXEL_DFT);
                // GUI_DisString_EN(43, 80, "D", &Font24, GUI_BACKGROUND, BLUE);
            //}
            if (lastKey == 1) {
                selection = (selection-1)%optionCount;
            }
            //GUI_DrawRectangle(40, 80, 60, 100, WHITE, DRAW_FULL, DOT_PIXEL_DFT);
            //GUI_DrawRectangle(40, 80, 60, 100, RED, DRAW_EMPTY, DOT_PIXEL_DFT);
            //GUI_DisString_EN(43, 80, "D", &Font24, GUI_BACKGROUND, BLUE);
            lastKey = 1;
        }
        
        if(lastSelection!=selection){
            Draw_Init();
            switch (selection) {
            case 0:
                GUI_DisString_EN(10, 40, "- Option 0", &Font12, WHITE, BLACK);
            case 1:
                GUI_DisString_EN(10, 55, "- Option 1", &Font12, WHITE, BLACK);
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