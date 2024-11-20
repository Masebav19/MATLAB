/*
 * PARQUEADERO_MODELO.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PARQUEADERO_MODELO".
 *
 * Model version              : 1.3
 * Simulink Coder version : 9.4 (R2020b) 29-Jul-2020
 * C source code generated on : Wed Jun 29 15:23:02 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PARQUEADERO_MODELO_h_
#define RTW_HEADER_PARQUEADERO_MODELO_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef PARQUEADERO_MODELO_COMMON_INCLUDES_
#define PARQUEADERO_MODELO_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* PARQUEADERO_MODELO_COMMON_INCLUDES_ */

#include "PARQUEADERO_MODELO_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T numero_coches;                /* '<S1>/Chart' */
  real_T ON_OFF;                       /* '<S1>/Chart' */
  int32_T clockTickCounter;            /* '<S1>/Pulse Generator' */
  uint8_T is_active_c3_PARQUEADERO_MODELO;/* '<S1>/Chart' */
  uint8_T is_c3_PARQUEADERO_MODELO;    /* '<S1>/Chart' */
  uint8_T is_OCUPADO;                  /* '<S1>/Chart' */
  uint8_T is_LIBRE;                    /* '<S1>/Chart' */
} DW_PARQUEADERO_MODELO_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Chart_Trig_ZCE;           /* '<S1>/Chart' */
} PrevZCX_PARQUEADERO_MODELO_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T A_SEN;                        /* '<Root>/A_SEN' */
  real_T E_SEN;                        /* '<Root>/E_SEN' */
} ExtU_PARQUEADERO_MODELO_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T MOTOR;                        /* '<Root>/MOTOR' */
  real_T coches;                       /* '<Root>/coches' */
  real_T ST_PARKIN;                    /* '<Root>/ST_PARKIN' */
} ExtY_PARQUEADERO_MODELO_T;

/* Parameters (default storage) */
struct P_PARQUEADERO_MODELO_T_ {
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S1>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<S1>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<S1>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S1>/Pulse Generator'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_PARQUEADERO_MODELO_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_PARQUEADERO_MODELO_T PARQUEADERO_MODELO_P;

/* Block states (default storage) */
extern DW_PARQUEADERO_MODELO_T PARQUEADERO_MODELO_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_PARQUEADERO_MODELO_T PARQUEADERO_MODELO_PrevZCX;

/* External inputs (root inport signals with default storage) */
extern ExtU_PARQUEADERO_MODELO_T PARQUEADERO_MODELO_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_PARQUEADERO_MODELO_T PARQUEADERO_MODELO_Y;

/* Model entry point functions */
extern void PARQUEADERO_MODELO_initialize(void);
extern void PARQUEADERO_MODELO_step(void);
extern void PARQUEADERO_MODELO_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PARQUEADERO_MODELO_T *const PARQUEADERO_MODELO_M;

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
