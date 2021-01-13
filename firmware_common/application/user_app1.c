/*!*********************************************************************************************************************
@file user_app1.c                                                                
@brief User's tasks / applications are written here.  This description
should be replaced by something specific to the task.
----------------------------------------------------------------------------------------------------------------------
To start a new task using this user_app1 as a template:
 1. Copy both user_app1.c and user_app1.h to the Application directory
 2. Rename the files yournewtaskname.c and yournewtaskname.h
 3. Add yournewtaskname.c and yournewtaskname.h to the Application Include and Source groups in the IAR project
 4. Use ctrl-h (make sure "Match Case" is checked) to find and replace all instances of "user_app1" with "yournewtaskname"
 5. Use ctrl-h to find and replace all instances of "UserApp1" with "YourNewTaskName"
 6. Use ctrl-h to find and replace all instances of "USER_APP1" with "YOUR_NEW_TASK_NAME"
 7. Add a call to YourNewTaskNameInitialize() in the init section of main
 8. Add a call to YourNewTaskNameRunActiveState() in the Super Loop section of main
 9. Update yournewtaskname.h per the instructions at the top of yournewtaskname.h
10. Delete this text (between the dashed lines) and update the Description below to describe your task
----------------------------------------------------------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------
GLOBALS
- NONE
CONSTANTS
- NONE
TYPES
- NONE
PUBLIC FUNCTIONS
- NONE
PROTECTED FUNCTIONS
- void UserApp1Initialize(void)
- void UserApp1RunActiveState(void)
**********************************************************************************************************************/

#include "configuration.h"

/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_<type>UserApp1"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32UserApp1Flags;                          /*!< @brief Global state flags */


/*--------------------------------------------------------------------------------------------------------------------*/
/* Existing variables (defined in other files -- should all contain the "extern" keyword) */
extern volatile u32 G_u32SystemFlags;                     /*!< @brief From main.c */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "UserApp1_" and be declared as static.
***********************************************************************************************************************/
static fnCode_type UserApp1_StateMachine;                 /*!< @brief The state machine function pointer */
//static u32 UserApp1_u32Timeout;                         /*!< @brief Timeout counter used across states */


/**********************************************************************************************************************
Function Definitions
**********************************************************************************************************************/

/*--------------------------------------------------------------------------------------------------------------------*/
/*! @publicsection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------*/
/*! @protectedsection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/


/*!--------------------------------------------------------------------------------------------------------------------
@fn void UserApp1Initialize(void)
@brief
Initializes the State Machine and its variables.
Should only be called once in main init section.
Requires:
- NONE
Promises:
- NONE
*/
void UserApp1Initialize(void)
{ 
  /* If good initialization, set state to Idle */
  if( 1 )
  {
    UserApp1_StateMachine = UserApp1SM_Idle;
  }
  else
  {
    /* The task isn't properly initialized, so shut it down and don't run */
    UserApp1_StateMachine = UserApp1SM_Error;
  }

} /* end UserApp1Initialize() */

  
/*!----------------------------------------------------------------------------------------------------------------------
@fn void UserApp1RunActiveState(void)
@brief Selects and runs one iteration of the current state in the state machine.
All state machines have a TOTAL of 1ms to execute, so on average n state machines
may take 1ms / n to execute.
Requires:
- State machine function pointer points at current state
Promises:
- Calls the function to pointed by the state machine function pointer
*/
void UserApp1RunActiveState(void)
{
  UserApp1_StateMachine();

} /* end UserApp1RunActiveState */


/*------------------------------------------------------------------------------------------------------------------*/
/*! @privatesection */                                                                                            
/*--------------------------------------------------------------------------------------------------------------------*/


/**********************************************************************************************************************
State Machine Function Definitions
**********************************************************************************************************************/

/*!-------------------------------------------------------------------------------------------------------------------
@fn static void UserApp1SM_Idle(void)
@brief What does this function do?
*/
static void UserApp1SM_Idle(void)
{
  static u32 u32Counter = 0;
  static u8 u8Counter = 0;
  
  u32Counter++;
  if(u32Counter == 1000)
  {
      u8Counter++;
      if(u8Counter > 64)
      {
        u8Counter = 0;
      }
    u32Counter = 0;
  }
  
  for(u8 i = 0; i < U8_TOTAL_LEDS; i++)
  {
    if( u8Counter & (1 << i))
    {
      LedOn((LedNameType) i);
    }
    else
    {
      LedOff((LedNameType) i);
    }
  }
     
  /*
  if(u8Counter == 2000)
  {
    LedBlink(PURPLE, LED_8HZ);
  }
  
  if(u32Counter == 4000)
  {
    LedBlink(PURPLE, LED_4HZ);
  }
  if(u32Counter == 6000)
  {
    LedBlink(PURPLE, LED_2HZ);
  }
  if(u32Counter == 8000)
  {
    LedBlink(PURPLE, LED_1HZ);
  }
  */
} /* end UserApp1SM_Idle() */
    

/*!-------------------------------------------------------------------------------------------------------------------
@fn static void UserApp1SM_Error(void)
@brief Handle an error here.  For now, the task is just held in this state. 
*/
static void UserApp1SM_Error(void)          
{
  
} /* end UserApp1SM_Error() */




/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File                                                                                                        */
/*--------------------------------------------------------------------------------------------------------------------*/