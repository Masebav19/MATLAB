/*
 * PARQUEADERO_MODELO.c
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

#include "PARQUEADERO_MODELO.h"
#include "PARQUEADERO_MODELO_private.h"

/* Named constants for Chart: '<S1>/Chart' */
#define PARQUEADERO_MODELO_IN_LIBRE    ((uint8_T)1U)
#define PARQUEADERO_MODELO_IN_OCUPADO  ((uint8_T)2U)
#define PARQUEADERO_MODELO_IN_inicio   ((uint8_T)3U)
#define PARQUEADERO_MODELO_IN_inicio_  ((uint8_T)3U)
#define PARQUEADERO_MODELO_IN_inicio_f ((uint8_T)4U)
#define PARQUEADERO_MODEL_IN_PASO_LIBRE ((uint8_T)1U)
#define PARQUEADERO_MOD_IN_paso_ocupado ((uint8_T)5U)
#define PARQUEADERO_MO_IN_CERRAR_PUERTA ((uint8_T)1U)
#define PARQUEADERO_MO_IN_RESTAR_COCHES ((uint8_T)2U)
#define PARQUEADERO_MO_IN_SUMAR_COCHES1 ((uint8_T)3U)
#define PARQUEADERO__IN_NO_ACTIVE_CHILD ((uint8_T)0U)

/* Block states (default storage) */
DW_PARQUEADERO_MODELO_T PARQUEADERO_MODELO_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_PARQUEADERO_MODELO_T PARQUEADERO_MODELO_PrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU_PARQUEADERO_MODELO_T PARQUEADERO_MODELO_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_PARQUEADERO_MODELO_T PARQUEADERO_MODELO_Y;

/* Real-time model */
static RT_MODEL_PARQUEADERO_MODELO_T PARQUEADERO_MODELO_M_;
RT_MODEL_PARQUEADERO_MODELO_T *const PARQUEADERO_MODELO_M =
  &PARQUEADERO_MODELO_M_;

/* Model step function */
void PARQUEADERO_MODELO_step(void)
{
  real_T rtb_PulseGenerator;
  ZCEventType zcEvent;

  /* DiscretePulseGenerator: '<S1>/Pulse Generator' */
  rtb_PulseGenerator = (PARQUEADERO_MODELO_DW.clockTickCounter <
                        PARQUEADERO_MODELO_P.PulseGenerator_Duty) &&
    (PARQUEADERO_MODELO_DW.clockTickCounter >= 0) ?
    PARQUEADERO_MODELO_P.PulseGenerator_Amp : 0.0;
  if (PARQUEADERO_MODELO_DW.clockTickCounter >=
      PARQUEADERO_MODELO_P.PulseGenerator_Period - 1.0) {
    PARQUEADERO_MODELO_DW.clockTickCounter = 0;
  } else {
    PARQUEADERO_MODELO_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator' */

  /* Chart: '<S1>/Chart' incorporates:
   *  TriggerPort: '<S2>/CLOCK'
   */
  zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,
                     &PARQUEADERO_MODELO_PrevZCX.Chart_Trig_ZCE,
                     (rtb_PulseGenerator));
  if (zcEvent != NO_ZCEVENT) {
    if (PARQUEADERO_MODELO_DW.is_active_c3_PARQUEADERO_MODELO == 0U) {
      PARQUEADERO_MODELO_DW.is_active_c3_PARQUEADERO_MODELO = 1U;
      PARQUEADERO_MODELO_DW.is_c3_PARQUEADERO_MODELO =
        PARQUEADERO_MODELO_IN_inicio_;
      PARQUEADERO_MODELO_DW.numero_coches = 0.0;

      /* Outport: '<Root>/coches' */
      PARQUEADERO_MODELO_Y.coches = 0.0;

      /* Outport: '<Root>/MOTOR' */
      PARQUEADERO_MODELO_Y.MOTOR = 0.0;

      /* Outport: '<Root>/ST_PARKIN' */
      PARQUEADERO_MODELO_Y.ST_PARKIN = 1.0;
      PARQUEADERO_MODELO_DW.ON_OFF = 1.0;
    } else {
      switch (PARQUEADERO_MODELO_DW.is_c3_PARQUEADERO_MODELO) {
       case PARQUEADERO_MODELO_IN_LIBRE:
        if (PARQUEADERO_MODELO_DW.ON_OFF == 0.0) {
          PARQUEADERO_MODELO_DW.is_LIBRE = PARQUEADERO__IN_NO_ACTIVE_CHILD;
          PARQUEADERO_MODELO_DW.is_c3_PARQUEADERO_MODELO =
            PARQUEADERO_MODELO_IN_OCUPADO;
          PARQUEADERO_MODELO_DW.is_OCUPADO = PARQUEADERO_MODELO_IN_inicio;

          /* Outport: '<Root>/ST_PARKIN' */
          PARQUEADERO_MODELO_Y.ST_PARKIN = 0.0;

          /* Outport: '<Root>/MOTOR' */
          PARQUEADERO_MODELO_Y.MOTOR = 0.0;
        } else {
          switch (PARQUEADERO_MODELO_DW.is_LIBRE) {
           case PARQUEADERO_MO_IN_CERRAR_PUERTA:
            /* Outport: '<Root>/MOTOR' */
            PARQUEADERO_MODELO_Y.MOTOR = 0.0;
            if (PARQUEADERO_MODELO_DW.numero_coches == 10.0) {
              PARQUEADERO_MODELO_DW.is_LIBRE = PARQUEADERO_MOD_IN_paso_ocupado;
              PARQUEADERO_MODELO_DW.ON_OFF = 0.0;
            } else {
              PARQUEADERO_MODELO_DW.is_LIBRE = PARQUEADERO_MODELO_IN_inicio_f;

              /* Outport: '<Root>/ST_PARKIN' */
              PARQUEADERO_MODELO_Y.ST_PARKIN = 0.0;

              /* Outport: '<Root>/MOTOR' */
              PARQUEADERO_MODELO_Y.MOTOR = 0.0;
            }
            break;

           case PARQUEADERO_MO_IN_RESTAR_COCHES:
            /* Inport: '<Root>/E_SEN' */
            if (PARQUEADERO_MODELO_U.E_SEN == 0.0) {
              PARQUEADERO_MODELO_DW.is_LIBRE = PARQUEADERO_MODELO_IN_inicio_f;

              /* Outport: '<Root>/ST_PARKIN' */
              PARQUEADERO_MODELO_Y.ST_PARKIN = 0.0;

              /* Outport: '<Root>/MOTOR' */
              PARQUEADERO_MODELO_Y.MOTOR = 0.0;
            }
            break;

           case PARQUEADERO_MO_IN_SUMAR_COCHES1:
            /* Outport: '<Root>/MOTOR' */
            PARQUEADERO_MODELO_Y.MOTOR = 1.0;

            /* Inport: '<Root>/A_SEN' */
            if (PARQUEADERO_MODELO_U.A_SEN == 0.0) {
              PARQUEADERO_MODELO_DW.is_LIBRE = PARQUEADERO_MO_IN_CERRAR_PUERTA;

              /* Outport: '<Root>/MOTOR' */
              PARQUEADERO_MODELO_Y.MOTOR = 0.0;
            }
            break;

           case PARQUEADERO_MODELO_IN_inicio_f:
            /* Outport: '<Root>/ST_PARKIN' */
            PARQUEADERO_MODELO_Y.ST_PARKIN = 0.0;

            /* Outport: '<Root>/MOTOR' */
            PARQUEADERO_MODELO_Y.MOTOR = 0.0;

            /* Inport: '<Root>/E_SEN' incorporates:
             *  Inport: '<Root>/A_SEN'
             */
            if (PARQUEADERO_MODELO_U.E_SEN == 1.0) {
              PARQUEADERO_MODELO_DW.is_LIBRE = PARQUEADERO_MO_IN_RESTAR_COCHES;
              PARQUEADERO_MODELO_DW.numero_coches--;

              /* Outport: '<Root>/coches' */
              PARQUEADERO_MODELO_Y.coches = PARQUEADERO_MODELO_DW.numero_coches;
            } else {
              if (PARQUEADERO_MODELO_U.A_SEN == 1.0) {
                PARQUEADERO_MODELO_DW.is_LIBRE = PARQUEADERO_MO_IN_SUMAR_COCHES1;
                PARQUEADERO_MODELO_DW.numero_coches++;

                /* Outport: '<Root>/coches' */
                PARQUEADERO_MODELO_Y.coches =
                  PARQUEADERO_MODELO_DW.numero_coches;

                /* Outport: '<Root>/MOTOR' */
                PARQUEADERO_MODELO_Y.MOTOR = 1.0;
              }
            }
            break;

           default:
            /* case IN_paso_ocupado: */
            break;
          }
        }
        break;

       case PARQUEADERO_MODELO_IN_OCUPADO:
        if (PARQUEADERO_MODELO_DW.ON_OFF == 1.0) {
          PARQUEADERO_MODELO_DW.is_OCUPADO = PARQUEADERO__IN_NO_ACTIVE_CHILD;
          PARQUEADERO_MODELO_DW.is_c3_PARQUEADERO_MODELO =
            PARQUEADERO_MODELO_IN_LIBRE;
          PARQUEADERO_MODELO_DW.is_LIBRE = PARQUEADERO_MODELO_IN_inicio_f;

          /* Outport: '<Root>/ST_PARKIN' */
          PARQUEADERO_MODELO_Y.ST_PARKIN = 0.0;

          /* Outport: '<Root>/MOTOR' */
          PARQUEADERO_MODELO_Y.MOTOR = 0.0;
        } else {
          switch (PARQUEADERO_MODELO_DW.is_OCUPADO) {
           case PARQUEADERO_MODEL_IN_PASO_LIBRE:
            break;

           case PARQUEADERO_MO_IN_RESTAR_COCHES:
            /* Inport: '<Root>/E_SEN' */
            if (PARQUEADERO_MODELO_U.E_SEN == 0.0) {
              PARQUEADERO_MODELO_DW.is_OCUPADO = PARQUEADERO_MODEL_IN_PASO_LIBRE;
              PARQUEADERO_MODELO_DW.ON_OFF = 1.0;
            }
            break;

           default:
            /* Outport: '<Root>/ST_PARKIN' */
            /* case IN_inicio: */
            PARQUEADERO_MODELO_Y.ST_PARKIN = 0.0;

            /* Outport: '<Root>/MOTOR' */
            PARQUEADERO_MODELO_Y.MOTOR = 0.0;

            /* Inport: '<Root>/E_SEN' */
            if (PARQUEADERO_MODELO_U.E_SEN == 1.0) {
              PARQUEADERO_MODELO_DW.is_OCUPADO = PARQUEADERO_MO_IN_RESTAR_COCHES;
              PARQUEADERO_MODELO_DW.numero_coches--;

              /* Outport: '<Root>/coches' */
              PARQUEADERO_MODELO_Y.coches = PARQUEADERO_MODELO_DW.numero_coches;
            }
            break;
          }
        }
        break;

       default:
        /* case IN_inicio_: */
        PARQUEADERO_MODELO_DW.is_c3_PARQUEADERO_MODELO =
          PARQUEADERO_MODELO_IN_LIBRE;
        PARQUEADERO_MODELO_DW.is_LIBRE = PARQUEADERO_MODELO_IN_inicio_f;

        /* Outport: '<Root>/ST_PARKIN' */
        PARQUEADERO_MODELO_Y.ST_PARKIN = 0.0;

        /* Outport: '<Root>/MOTOR' */
        PARQUEADERO_MODELO_Y.MOTOR = 0.0;
        break;
      }
    }
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(PARQUEADERO_MODELO_M->rtwLogInfo,
                      (&PARQUEADERO_MODELO_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(PARQUEADERO_MODELO_M)!=-1) &&
        !((rtmGetTFinal(PARQUEADERO_MODELO_M)-
           PARQUEADERO_MODELO_M->Timing.taskTime0) >
          PARQUEADERO_MODELO_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(PARQUEADERO_MODELO_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++PARQUEADERO_MODELO_M->Timing.clockTick0)) {
    ++PARQUEADERO_MODELO_M->Timing.clockTickH0;
  }

  PARQUEADERO_MODELO_M->Timing.taskTime0 =
    PARQUEADERO_MODELO_M->Timing.clockTick0 *
    PARQUEADERO_MODELO_M->Timing.stepSize0 +
    PARQUEADERO_MODELO_M->Timing.clockTickH0 *
    PARQUEADERO_MODELO_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void PARQUEADERO_MODELO_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PARQUEADERO_MODELO_M, 0,
                sizeof(RT_MODEL_PARQUEADERO_MODELO_T));
  rtmSetTFinal(PARQUEADERO_MODELO_M, -1);
  PARQUEADERO_MODELO_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    PARQUEADERO_MODELO_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(PARQUEADERO_MODELO_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(PARQUEADERO_MODELO_M->rtwLogInfo, (NULL));
    rtliSetLogT(PARQUEADERO_MODELO_M->rtwLogInfo, "tout");
    rtliSetLogX(PARQUEADERO_MODELO_M->rtwLogInfo, "");
    rtliSetLogXFinal(PARQUEADERO_MODELO_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(PARQUEADERO_MODELO_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(PARQUEADERO_MODELO_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(PARQUEADERO_MODELO_M->rtwLogInfo, 0);
    rtliSetLogDecimation(PARQUEADERO_MODELO_M->rtwLogInfo, 1);
    rtliSetLogY(PARQUEADERO_MODELO_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(PARQUEADERO_MODELO_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(PARQUEADERO_MODELO_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&PARQUEADERO_MODELO_DW, 0,
                sizeof(DW_PARQUEADERO_MODELO_T));

  /* external inputs */
  (void)memset(&PARQUEADERO_MODELO_U, 0, sizeof(ExtU_PARQUEADERO_MODELO_T));

  /* external outputs */
  (void) memset((void *)&PARQUEADERO_MODELO_Y, 0,
                sizeof(ExtY_PARQUEADERO_MODELO_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(PARQUEADERO_MODELO_M->rtwLogInfo, 0.0,
    rtmGetTFinal(PARQUEADERO_MODELO_M), PARQUEADERO_MODELO_M->Timing.stepSize0,
    (&rtmGetErrorStatus(PARQUEADERO_MODELO_M)));

  /* Start for DiscretePulseGenerator: '<S1>/Pulse Generator' */
  PARQUEADERO_MODELO_DW.clockTickCounter = 0;
  PARQUEADERO_MODELO_PrevZCX.Chart_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* SystemInitialize for Chart: '<S1>/Chart' */
  PARQUEADERO_MODELO_DW.is_LIBRE = PARQUEADERO__IN_NO_ACTIVE_CHILD;
  PARQUEADERO_MODELO_DW.is_OCUPADO = PARQUEADERO__IN_NO_ACTIVE_CHILD;
  PARQUEADERO_MODELO_DW.is_active_c3_PARQUEADERO_MODELO = 0U;
  PARQUEADERO_MODELO_DW.is_c3_PARQUEADERO_MODELO =
    PARQUEADERO__IN_NO_ACTIVE_CHILD;
}

/* Model terminate function */
void PARQUEADERO_MODELO_terminate(void)
{
  /* (no terminate code required) */
}
