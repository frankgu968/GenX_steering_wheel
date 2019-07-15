/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */     
#include "serial.h"
#include "serializers.h"
#include "accelEncoder.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define navPadScanPeriod      50  // ms
#define acceleratorScanPeriod 10  // ms
#define RHTempScanPeriod      100 // ms
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
osThreadId scanNavPadTaskHandle;
osThreadId acceleratorTaskHandle;
osThreadId getRHTempTaskHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
   
/* USER CODE END FunctionPrototypes */

void scanNavPad(void const * argument);
void getAccelerator(void const * argument);
void getRHTemp(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];
  
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}                   
/* USER CODE END GET_IDLE_TASK_MEMORY */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */
       
  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of scanNavPadTask */
  osThreadDef(scanNavPadTask, scanNavPad, osPriorityNormal, 0, 128);
  scanNavPadTaskHandle = osThreadCreate(osThread(scanNavPadTask), NULL);

  /* definition and creation of acceleratorTask */
  osThreadDef(acceleratorTask, getAccelerator, osPriorityAboveNormal, 0, 128);
  acceleratorTaskHandle = osThreadCreate(osThread(acceleratorTask), NULL);

  /* definition and creation of getRHTempTask */
  osThreadDef(getRHTempTask, getRHTemp, osPriorityBelowNormal, 0, 128);
  getRHTempTaskHandle = osThreadCreate(osThread(getRHTempTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_scanNavPad */
/**
  * @brief  Function implementing the scanNavPadTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_scanNavPad */
void scanNavPad(void const * argument)
{

  /* USER CODE BEGIN scanNavPad */
  /* Infinite loop */
  uint32_t lastTickTime; 
  char buf[MSG_LEN_NAV];
  uint8_t navEnc, navBtn;
  lastTickTime = xTaskGetTickCount();
  for(;;)
  {
    // TODO: Placeholders
    navBtn = 0xCD;
    navEnc = 0x26;

    serializeNavPad(&buf, navBtn, navEnc);  // Assemble message
    send_data(&buf, MSG_LEN_TEMP);    // Send message to UART
    osDelayUntil(&lastTickTime, navPadScanPeriod);
  }
  /* USER CODE END scanNavPad */
}

/* USER CODE BEGIN Header_getAccelerator */
/**
* @brief Function implementing the acceleratorTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_getAccelerator */
void getAccelerator(void const * argument)
{
  /* USER CODE BEGIN getAccelerator */
  /* Infinite loop */
  uint32_t lastTickTime; 
  char buf[MSG_LEN_ENC];
  uint8_t encPos;
  lastTickTime = xTaskGetTickCount();
  for(;;)
  {
    encPos = 0x17;  // FIXME: placeholder value
    // encPos = readAccelEncoder();`// Read GPIO pin values

    serializeEncoder(&buf, encPos);  // Assemble message
    send_data(&buf, MSG_LEN_ENC);    // Send message to UART
    osDelayUntil(&lastTickTime, acceleratorScanPeriod);
  }
  /* USER CODE END getAccelerator */
}

/* USER CODE BEGIN Header_getRHTemp */
/**
* @brief Function implementing the getRHTempTask thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_getRHTemp */
void getRHTemp(void const * argument)
{
  /* USER CODE BEGIN getRHTemp */
  /* Infinite loop */
  uint32_t lastTickTime; 
  char buf[MSG_LEN_TEMP];
  uint16_t rh, temp; 
  lastTickTime = xTaskGetTickCount();
  for(;;)
  {
    // TODO: placeholders
    rh = 0x10;
    temp = 0x15;

    serializeRHTemp(&buf, temp, rh);  // Assemble message
    send_data(&buf, MSG_LEN_TEMP);    // Send message to UART
    osDelayUntil(&lastTickTime, RHTempScanPeriod);
  }
  /* USER CODE END getRHTemp */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
     
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
