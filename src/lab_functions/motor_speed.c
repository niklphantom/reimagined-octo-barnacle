/*******************************************************************************************************
Definition: File to get speed from motor
Developer: Trishin Vadim
Notes: 
*******************************************************************************************************/
/*******************************************************************************************************
Описание: Файл для установки напряжения на мотор
Разработчик: Тришин Вадим
Заметки: 
*******************************************************************************************************/
#include "motor_speed.h"
#include <stm32f10x.h>

/***************************************************************************************************
Local defines
***************************************************************************************************/
/***************************************************************************************************
Локальные дефайны
***************************************************************************************************/

/***************************************************************************************************
Local data types
***************************************************************************************************/
/***************************************************************************************************
Локальные типы данных
***************************************************************************************************/

/***************************************************************************************************
File local variables
***************************************************************************************************/
/***************************************************************************************************
Локальные переменные файла
***************************************************************************************************/

/***************************************************************************************************
Global functions
***************************************************************************************************/
/***************************************************************************************************
Глобальные функции
***************************************************************************************************/

/**************************************************************************************************
Definition: Initialize pin for reading speed value
Arguments: No
Return:   No
Notes: 
**************************************************************************************************/
/**************************************************************************************************
Описание: Инициализация пина для чтения значения скорости
Аргументы: Нет
Возврат:   Значение скорости
Замечания: 
**************************************************************************************************/
void motor_speed_init(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE);
  
  GPIO_InitTypeDef structGPIO;
  
  // ADC12_IN8, remap(TIM1_CH2N)
	structGPIO.GPIO_Speed = GPIO_Speed_2MHz;
	structGPIO.GPIO_Pin  = GPIO_Pin_0; 
  structGPIO.GPIO_Mode = GPIO_Mode_IN_FLOATING; // Check
  
  GPIO_Init(GPIOB, &structGPIO);	
}

/**************************************************************************************************
Definition: Get the speed value of motor
Arguments: No
Return:   Speed value
Notes: 
**************************************************************************************************/
/**************************************************************************************************
Описание: Получение скорости мотора
Аргументы: Нет
Возврат:   Значение скорости
Замечания: 
**************************************************************************************************/
int16_t motor_speed_getSpeed(void)
{
	int16_t speed;
	return speed;
}

// классический ассерт для STM32
//#ifdef USE_FULL_ASSERT
//void assert_failed(uint8_t * file, uint32_t line)
//{ 
//    /* User can add his own implementation to report the file name and line number,
//     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
//     
//    (void)file;
//    (void)line;

//    __disable_irq();
//    while(1)
//    {
//        // это ассемблерная инструкция "отладчик, стой тут"
//        // если вы попали сюда, значит вы ошиблись в параметрах. Смотрите в call stack
//        __BKPT(0xAB);
//    }
//}
//#endif