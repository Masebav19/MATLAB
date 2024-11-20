/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PARQUEADERO_MODELO.h
 *
 * Code generated for Simulink model 'PARQUEADERO_MODELO'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.4 (R2020b) 29-Jul-2020
 * C/C++ source code generated on : Thu Jun 30 08:37:34 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PARQUEADERO_MODELO_h_
#define RTW_HEADER_PARQUEADERO_MODELO_h_
#ifndef PARQUEADERO_MODELO_COMMON_INCLUDES_
#define PARQUEADERO_MODELO_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* PARQUEADERO_MODELO_COMMON_INCLUDES_ */

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
  real_T numero_coches;                /* '<S1>/Chart' */
  real_T ON_OFF;                       /* '<S1>/Chart' */
  int32_T clockTickCounter;            /* '<S1>/Pulse Generator' */
  uint8_T is_active_c3_PARQUEADERO_MODELO;/* '<S1>/Chart' */
  uint8_T is_c3_PARQUEADERO_MODELO;    /* '<S1>/Chart' */
  uint8_T is_OCUPADO;                  /* '<S1>/Chart' */
  uint8_T is_LIBRE;                    /* '<S1>/Chart' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Chart_Trig_ZCE;           /* '<S1>/Chart' */
} PrevZCX;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T A_SEN;                        /* '<Root>/A_SEN' */
  real_T E_SEN;                        /* '<Root>/E_SEN' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T MOTOR;                        /* '<Root>/MOTOR' */
  real_T coches;                       /* '<Root>/coches' */
  real_T ST_PARKIN;                    /* '<Root>/ST_PARKIN' */
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
extern void PARQUEADERO_MODELO_initialize(void);
extern void PARQUEADERO_MODELO_step(void);

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
 * hilite_system('Parqueadero/PARQUEADERO_MODELO ')    - opens subsystem Parqueadero/PARQUEADERO_MODELO
 * hilite_system('Parqueadero/PARQUEADERO_MODELO /Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Parqueadero'
 * '<S1>'   : 'Parqueadero/PARQUEADERO_MODELO '
 * '<S2>'   : 'Parqueadero/PARQUEADERO_MODELO /Chart'
 */
#endif                                 /* RTW_HEADER_PARQUEADERO_MODELO_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
