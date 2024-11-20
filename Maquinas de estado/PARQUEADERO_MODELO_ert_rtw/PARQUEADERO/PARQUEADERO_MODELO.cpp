/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: PARQUEADERO_MODELO.c
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

#include "PARQUEADERO_MODELO.h"

/* Named constants for Chart: '<S1>/Chart' */
#define IN_CERRAR_PUERTA               ((uint8_T)1U)
#define IN_LIBRE                       ((uint8_T)1U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_OCUPADO                     ((uint8_T)2U)
#define IN_PASO_LIBRE                  ((uint8_T)1U)
#define IN_RESTAR_COCHES               ((uint8_T)2U)
#define IN_SUMAR_COCHES1               ((uint8_T)3U)
#define IN_inicio                      ((uint8_T)3U)
#define IN_inicio_                     ((uint8_T)3U)
#define IN_inicio_f                    ((uint8_T)4U)
#define IN_paso_ocupado                ((uint8_T)5U)
#include "solver_zc.h"
#include "zero_crossing_types.h"
#ifndef slZcHadEvent
#define slZcHadEvent(ev, zcsDir)       (((ev) & (zcsDir)) != 0x00 )
#endif

#ifndef slZcUnAliasEvents
#define slZcUnAliasEvents(evL, evR)    ((((slZcHadEvent((evL), (SL_ZCS_EVENT_N2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2P))) || (slZcHadEvent((evL), (SL_ZCS_EVENT_P2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2N)))) ? (SL_ZCS_EVENT_NUL) : (evR)))
#endif

/* Block signals and states (default storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Real-time model */
static RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;
static ZCEventType rt_ZCFcn(ZCDirection zcDir, ZCSigState *prevZc, real_T
  currValue);

/* Detect zero crossings events. */
static ZCEventType rt_ZCFcn(ZCDirection zcDir, ZCSigState* prevZc, real_T
  currValue)
{
  slZcEventType zcsDir;
  slZcEventType tempEv;
  ZCEventType zcEvent = NO_ZCEVENT;    /* assume */

  /* zcEvent matrix */
  static const slZcEventType eventMatrix[4][4] = {
    /*          ZER              POS              NEG              UNK */
    { SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_Z2P, SL_ZCS_EVENT_Z2N, SL_ZCS_EVENT_NUL },/* ZER */

    { SL_ZCS_EVENT_P2Z, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_P2N, SL_ZCS_EVENT_NUL },/* POS */

    { SL_ZCS_EVENT_N2Z, SL_ZCS_EVENT_N2P, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL },/* NEG */

    { SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL, SL_ZCS_EVENT_NUL }/* UNK */
  };

  /* get prevZcEvent and prevZcSign from prevZc */
  slZcEventType prevEv = (slZcEventType)(((uint8_T)(*prevZc)) >> 2);
  slZcSignalSignType prevSign = (slZcSignalSignType)(((uint8_T)(*prevZc)) &
    (uint8_T)0x03);

  /* get current zcSignal sign from current zcSignal value */
  slZcSignalSignType currSign = (slZcSignalSignType)((currValue) > 0.0 ?
    SL_ZCS_SIGN_POS :
    ((currValue) < 0.0 ? SL_ZCS_SIGN_NEG : SL_ZCS_SIGN_ZERO));

  /* get current zcEvent based on prev and current zcSignal value */
  slZcEventType currEv = eventMatrix[prevSign][currSign];

  /* get slZcEventType from ZCDirection */
  switch (zcDir) {
   case ANY_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL;
    break;

   case FALLING_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL_DN;
    break;

   case RISING_ZERO_CROSSING:
    zcsDir = SL_ZCS_EVENT_ALL_UP;
    break;

   default:
    zcsDir = SL_ZCS_EVENT_NUL;
    break;
  }

  /*had event, check if double zc happend remove double detection. */
  if (slZcHadEvent(currEv, zcsDir)) {
    currEv = (slZcEventType)(slZcUnAliasEvents(prevEv, currEv));
  } else {
    currEv = SL_ZCS_EVENT_NUL;
  }

  /* Update prevZc */
  tempEv = (slZcEventType)(currEv << 2);/* shift left by 2 bits */
  *prevZc = (ZCSigState)((currSign) | (tempEv));
  if ((currEv & SL_ZCS_EVENT_ALL_DN) != 0) {
    zcEvent = FALLING_ZCEVENT;
  } else if ((currEv & SL_ZCS_EVENT_ALL_UP) != 0) {
    zcEvent = RISING_ZCEVENT;
  } else {
    zcEvent = NO_ZCEVENT;
  }

  return zcEvent;
}                                      /* rt_ZCFcn */

/* Model step function */
void PARQUEADERO_MODELO_step(void)
{
  int32_T rtb_PulseGenerator;
  ZCEventType zcEvent;

  /* DiscretePulseGenerator: '<S1>/Pulse Generator' */
  rtb_PulseGenerator = ((rtDW.clockTickCounter < 1) && (rtDW.clockTickCounter >=
    0));
  if (rtDW.clockTickCounter >= 19) {
    rtDW.clockTickCounter = 0;
  } else {
    rtDW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator' */

  /* Chart: '<S1>/Chart' incorporates:
   *  TriggerPort: '<S2>/CLOCK'
   */
  zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&rtPrevZCX.Chart_Trig_ZCE,
                     ((real_T)rtb_PulseGenerator));
  if (zcEvent != NO_ZCEVENT) {
    if (rtDW.is_active_c3_PARQUEADERO_MODELO == 0U) {
      rtDW.is_active_c3_PARQUEADERO_MODELO = 1U;
      rtDW.is_c3_PARQUEADERO_MODELO = IN_inicio_;
      rtDW.numero_coches = 0.0;

      /* Outport: '<Root>/coches' */
      rtY.coches = 0.0;

      /* Outport: '<Root>/MOTOR' */
      rtY.MOTOR = 0.0;

      /* Outport: '<Root>/ST_PARKIN' */
      rtY.ST_PARKIN = 1.0;
      rtDW.ON_OFF = 1.0;
    } else {
      switch (rtDW.is_c3_PARQUEADERO_MODELO) {
       case IN_LIBRE:
        if (rtDW.ON_OFF == 0.0) {
          rtDW.is_LIBRE = IN_NO_ACTIVE_CHILD;
          rtDW.is_c3_PARQUEADERO_MODELO = IN_OCUPADO;
          rtDW.is_OCUPADO = IN_inicio;

          /* Outport: '<Root>/ST_PARKIN' */
          rtY.ST_PARKIN = 0.0;

          /* Outport: '<Root>/MOTOR' */
          rtY.MOTOR = 0.0;
        } else {
          switch (rtDW.is_LIBRE) {
           case IN_CERRAR_PUERTA:
            /* Outport: '<Root>/MOTOR' */
            rtY.MOTOR = 0.0;
            if (rtDW.numero_coches == 10.0) {
              rtDW.is_LIBRE = IN_paso_ocupado;
              rtDW.ON_OFF = 0.0;
            } else {
              rtDW.is_LIBRE = IN_inicio_f;

              /* Outport: '<Root>/ST_PARKIN' */
              rtY.ST_PARKIN = 0.0;

              /* Outport: '<Root>/MOTOR' */
              rtY.MOTOR = 0.0;
            }
            break;

           case IN_RESTAR_COCHES:
            /* Inport: '<Root>/E_SEN' */
            if (rtU.E_SEN == 0.0) {
              rtDW.is_LIBRE = IN_inicio_f;

              /* Outport: '<Root>/ST_PARKIN' */
              rtY.ST_PARKIN = 0.0;

              /* Outport: '<Root>/MOTOR' */
              rtY.MOTOR = 0.0;
            }
            break;

           case IN_SUMAR_COCHES1:
            /* Outport: '<Root>/MOTOR' */
            rtY.MOTOR = 1.0;

            /* Inport: '<Root>/A_SEN' */
            if (rtU.A_SEN == 0.0) {
              rtDW.is_LIBRE = IN_CERRAR_PUERTA;

              /* Outport: '<Root>/MOTOR' */
              rtY.MOTOR = 0.0;
            }
            break;

           case IN_inicio_f:
            /* Outport: '<Root>/ST_PARKIN' */
            rtY.ST_PARKIN = 0.0;

            /* Outport: '<Root>/MOTOR' */
            rtY.MOTOR = 0.0;

            /* Inport: '<Root>/E_SEN' incorporates:
             *  Inport: '<Root>/A_SEN'
             */
            if (rtU.E_SEN == 1.0) {
              rtDW.is_LIBRE = IN_RESTAR_COCHES;
              rtDW.numero_coches--;

              /* Outport: '<Root>/coches' */
              rtY.coches = rtDW.numero_coches;
            } else {
              if (rtU.A_SEN == 1.0) {
                rtDW.is_LIBRE = IN_SUMAR_COCHES1;
                rtDW.numero_coches++;

                /* Outport: '<Root>/coches' */
                rtY.coches = rtDW.numero_coches;

                /* Outport: '<Root>/MOTOR' */
                rtY.MOTOR = 1.0;
              }
            }
            break;

           default:
            /* case IN_paso_ocupado: */
            break;
          }
        }
        break;

       case IN_OCUPADO:
        if (rtDW.ON_OFF == 1.0) {
          rtDW.is_OCUPADO = IN_NO_ACTIVE_CHILD;
          rtDW.is_c3_PARQUEADERO_MODELO = IN_LIBRE;
          rtDW.is_LIBRE = IN_inicio_f;

          /* Outport: '<Root>/ST_PARKIN' */
          rtY.ST_PARKIN = 0.0;

          /* Outport: '<Root>/MOTOR' */
          rtY.MOTOR = 0.0;
        } else {
          switch (rtDW.is_OCUPADO) {
           case IN_PASO_LIBRE:
            break;

           case IN_RESTAR_COCHES:
            /* Inport: '<Root>/E_SEN' */
            if (rtU.E_SEN == 0.0) {
              rtDW.is_OCUPADO = IN_PASO_LIBRE;
              rtDW.ON_OFF = 1.0;
            }
            break;

           default:
            /* Outport: '<Root>/ST_PARKIN' */
            /* case IN_inicio: */
            rtY.ST_PARKIN = 0.0;

            /* Outport: '<Root>/MOTOR' */
            rtY.MOTOR = 0.0;

            /* Inport: '<Root>/E_SEN' */
            if (rtU.E_SEN == 1.0) {
              rtDW.is_OCUPADO = IN_RESTAR_COCHES;
              rtDW.numero_coches--;

              /* Outport: '<Root>/coches' */
              rtY.coches = rtDW.numero_coches;
            }
            break;
          }
        }
        break;

       default:
        /* case IN_inicio_: */
        rtDW.is_c3_PARQUEADERO_MODELO = IN_LIBRE;
        rtDW.is_LIBRE = IN_inicio_f;

        /* Outport: '<Root>/ST_PARKIN' */
        rtY.ST_PARKIN = 0.0;

        /* Outport: '<Root>/MOTOR' */
        rtY.MOTOR = 0.0;
        break;
      }
    }
  }
}

/* Model initialize function */
void PARQUEADERO_MODELO_initialize(void)
{
  rtPrevZCX.Chart_Trig_ZCE = UNINITIALIZED_ZCSIG;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
