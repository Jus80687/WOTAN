/*******************************************************************************
* File Name: ADC_Buffer.c
* Version 1.90
*
* Description:
*  This file provides the source code to the API for OpAmp (Analog Buffer) 
*  Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_Buffer.h"

uint8 ADC_Buffer_initVar = 0u;


/*******************************************************************************   
* Function Name: ADC_Buffer_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the 
*  customizer of the component placed onto schematic. Usually called in 
*  ADC_Buffer_Start().
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void ADC_Buffer_Init(void) 
{
    ADC_Buffer_SetPower(ADC_Buffer_DEFAULT_POWER);
}


/*******************************************************************************   
* Function Name: ADC_Buffer_Enable
********************************************************************************
*
* Summary:
*  Enables the OpAmp block operation
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void ADC_Buffer_Enable(void) 
{
    /* Enable negative charge pumps in ANIF */
    ADC_Buffer_PUMP_CR1_REG  |= (ADC_Buffer_PUMP_CR1_CLKSEL | ADC_Buffer_PUMP_CR1_FORCE);

    /* Enable power to buffer in active mode */
    ADC_Buffer_PM_ACT_CFG_REG |= ADC_Buffer_ACT_PWR_EN;

    /* Enable power to buffer in alternative active mode */
    ADC_Buffer_PM_STBY_CFG_REG |= ADC_Buffer_STBY_PWR_EN;
}


/*******************************************************************************
* Function Name:   ADC_Buffer_Start
********************************************************************************
*
* Summary:
*  The start function initializes the Analog Buffer with the default values and 
*  sets the power to the given level. A power level of 0, is same as 
*  executing the stop function.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  ADC_Buffer_initVar: Used to check the initial configuration, modified 
*  when this function is called for the first time.
*
*******************************************************************************/
void ADC_Buffer_Start(void) 
{
    if(ADC_Buffer_initVar == 0u)
    {
        ADC_Buffer_initVar = 1u;
        ADC_Buffer_Init();
    }

    ADC_Buffer_Enable();
}


/*******************************************************************************
* Function Name: ADC_Buffer_Stop
********************************************************************************
*
* Summary:
*  Powers down amplifier to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void ADC_Buffer_Stop(void) 
{
    /* Disable power to buffer in active mode template */
    ADC_Buffer_PM_ACT_CFG_REG &= (uint8)(~ADC_Buffer_ACT_PWR_EN);

    /* Disable power to buffer in alternative active mode template */
    ADC_Buffer_PM_STBY_CFG_REG &= (uint8)(~ADC_Buffer_STBY_PWR_EN);
    
    /* Disable negative charge pumps for ANIF only if all ABuf is turned OFF */
    if(ADC_Buffer_PM_ACT_CFG_REG == 0u)
    {
        ADC_Buffer_PUMP_CR1_REG &= (uint8)(~(ADC_Buffer_PUMP_CR1_CLKSEL | ADC_Buffer_PUMP_CR1_FORCE));
    }
}


/*******************************************************************************
* Function Name: ADC_Buffer_SetPower
********************************************************************************
*
* Summary:
*  Sets power level of Analog buffer.
*
* Parameters: 
*  power: PSoC3: Sets power level between low (1) and high power (3).
*         PSoC5: Sets power level High (0)
*
* Return:
*  void
*
**********************************************************************************/
void ADC_Buffer_SetPower(uint8 power) 
{
    #if (CY_PSOC3 || CY_PSOC5LP)
        ADC_Buffer_CR_REG &= (uint8)(~ADC_Buffer_PWR_MASK);
        ADC_Buffer_CR_REG |= power & ADC_Buffer_PWR_MASK;      /* Set device power */
    #else
        CYASSERT(ADC_Buffer_HIGHPOWER == power);
    #endif /* CY_PSOC3 || CY_PSOC5LP */
}


/* [] END OF FILE */
