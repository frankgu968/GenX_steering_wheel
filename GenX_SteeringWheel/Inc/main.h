/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ACC_6_Pin GPIO_PIN_13
#define ACC_6_GPIO_Port GPIOC
#define ACC_7_Pin GPIO_PIN_14
#define ACC_7_GPIO_Port GPIOC
#define ACC_8_Pin GPIO_PIN_15
#define ACC_8_GPIO_Port GPIOC
#define L_SIGNAL_Pin GPIO_PIN_0
#define L_SIGNAL_GPIO_Port GPIOC
#define R_SIGNAL_Pin GPIO_PIN_1
#define R_SIGNAL_GPIO_Port GPIOC
#define D_PAD_A_Pin GPIO_PIN_0
#define D_PAD_A_GPIO_Port GPIOA
#define D_PAD_B_Pin GPIO_PIN_1
#define D_PAD_B_GPIO_Port GPIOA
#define ACC_1_Pin GPIO_PIN_8
#define ACC_1_GPIO_Port GPIOC
#define ACC_2_Pin GPIO_PIN_9
#define ACC_2_GPIO_Port GPIOC
#define ACC_3_Pin GPIO_PIN_10
#define ACC_3_GPIO_Port GPIOC
#define ACC_4_Pin GPIO_PIN_11
#define ACC_4_GPIO_Port GPIOC
#define ACC_5_Pin GPIO_PIN_12
#define ACC_5_GPIO_Port GPIOC
#define D_PAD_1_Pin GPIO_PIN_2
#define D_PAD_1_GPIO_Port GPIOD
#define D_PAD_2_Pin GPIO_PIN_3
#define D_PAD_2_GPIO_Port GPIOB
#define D_PAD_3_Pin GPIO_PIN_4
#define D_PAD_3_GPIO_Port GPIOB
#define D_PAD_4_Pin GPIO_PIN_5
#define D_PAD_4_GPIO_Port GPIOB
#define D_PAD_5_Pin GPIO_PIN_6
#define D_PAD_5_GPIO_Port GPIOB
#define RADIO_Pin GPIO_PIN_7
#define RADIO_GPIO_Port GPIOB
#define D_TEMP_SCL_Pin GPIO_PIN_8
#define D_TEMP_SCL_GPIO_Port GPIOB
#define D_TEMP_SDA_Pin GPIO_PIN_9
#define D_TEMP_SDA_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
