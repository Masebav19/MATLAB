/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ONTROL.h
 *
 * Code generated for Simulink model 'ONTROL'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Wed Jul 27 16:30:47 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ONTROL_h_
#define RTW_HEADER_ONTROL_h_
#ifndef ONTROL_COMMON_INCLUDES_
#define ONTROL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* ONTROL_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real_T cont1;                        /* '<S1>/Chart' */
  int32_T clockTickCounter;            /* '<S1>/Pulse Generator' */
  uint8_T is_active_c3_ONTROL;         /* '<S1>/Chart' */
  uint8_T is_c3_ONTROL;                /* '<S1>/Chart' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Chart_Trig_ZCE;           /* '<S1>/Chart' */
} PrevZCX;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T P1;                           /* '<Root>/P1' */
  real_T P2;                           /* '<Root>/P2' */
  real_T P3;                           /* '<Root>/P3' */
  real_T P4;                           /* '<Root>/P4' */
  real_T P5;                           /* '<Root>/P5' */
  real_T DOOR_IN;                      /* '<Root>/DOOR_IN' */
  real_T DOOR_OUT;                     /* '<Root>/DOOR_OUT' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T ST1;                          /* '<Root>/ST1' */
  real_T ST2;                          /* '<Root>/ST2' */
  real_T ST3;                          /* '<Root>/ST3' */
  real_T ST4;                          /* '<Root>/ST4' */
  real_T ST5;                          /* '<Root>/ST5' */
  real_T cont;                         /* '<Root>/cont' */
  real_T puerta_in;                    /* '<Root>/puerta_in' */
  real_T puerta_out;                   /* '<Root>/puerta_out' */
} ExtY;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (default storage) */
extern DW rtDW;

/* Zero-crossing (trigger) state */
extern PrevZCX rtPrevZCX;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void ONTROL_initialize(void);
extern void ONTROL_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('untitled/ONTROL PARQUEADERO')    - opens subsystem untitled/ONTROL PARQUEADERO
 * hilite_system('untitled/ONTROL PARQUEADERO/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'untitled'
 * '<S1>'   : 'untitled/ONTROL PARQUEADERO'
 * '<S2>'   : 'untitled/ONTROL PARQUEADERO/Chart'
 */
#endif                                 /* RTW_HEADER_ONTROL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
