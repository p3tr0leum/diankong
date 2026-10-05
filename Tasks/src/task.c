/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2026-10-05 16:06:39
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2026-10-05 23:06:18
 * @FilePath: \assignment1\Tasks\src\task.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "task.h"

volatile uint32_t tick = 0;
void TASK1_Init (void)
{
    HAL_GPIO_WritePin (GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
}
void TASK2_Init (void)
{
    HAL_TIM_Base_Start_IT (&htim2);
}
void HAL_TIM_PeriodElapsedCallback (TIM_HandleTypeDef *htim)
{
    if (htim -> Instance == TIM2)
    {
        tick++;
        HAL_IWDG_Refresh (&hiwdg);
    }
}