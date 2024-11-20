/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ONTROL.c
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

#include "ONTROL.h"

/* Named constants for Chart: '<S1>/Chart' */
#define IN_INICIO                      ((uint8_T)1U)
#define IN_PARQ1_OFF                   ((uint8_T)2U)
#define IN_PARQ1_ON                    ((uint8_T)3U)
#define IN_PARQ2_OFF                   ((uint8_T)4U)
#define IN_PARQ2_ON                    ((uint8_T)5U)
#define IN_PARQ3_OFF                   ((uint8_T)6U)
#define IN_PARQ3_ON                    ((uint8_T)7U)
#define IN_PARQ4_OFF                   ((uint8_T)8U)
#define IN_PARQ4_ON                    ((uint8_T)9U)
#define IN_PARQ5_OFF                   ((uint8_T)10U)
#define IN_PARQ5_ON                    ((uint8_T)11U)
#define IN_abrir                       ((uint8_T)12U)
#define IN_abrir1                      ((uint8_T)13U)
#define IN_aumentar                    ((uint8_T)14U)
#define IN_disminuir                   ((uint8_T)15U)
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
void ONTROL_step(void)
{
  int32_T rtb_PulseGenerator;
  boolean_T guard1 = false;
  boolean_T guard10 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  boolean_T guard8 = false;
  boolean_T guard9 = false;
  ZCEventType zcEvent;

  /* DiscretePulseGenerator: '<S1>/Pulse Generator' */
  rtb_PulseGenerator = ((rtDW.clockTickCounter < 1) && (rtDW.clockTickCounter >=
    0));
  if (rtDW.clockTickCounter >= 1) {
    rtDW.clockTickCounter = 0;
  } else {
    rtDW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Pulse Generator' */

  /* Chart: '<S1>/Chart' incorporates:
   *  TriggerPort: '<S2>/clock'
   */
  zcEvent = rt_ZCFcn(ANY_ZERO_CROSSING,&rtPrevZCX.Chart_Trig_ZCE,
                     ((real_T)rtb_PulseGenerator));
  if (zcEvent != NO_ZCEVENT) {
    if (rtDW.is_active_c3_ONTROL == 0U) {
      rtDW.is_active_c3_ONTROL = 1U;
      rtDW.is_c3_ONTROL = IN_INICIO;

      /* Outport: '<Root>/ST1' */
      rtY.ST1 = 0.0;

      /* Outport: '<Root>/ST2' */
      rtY.ST2 = 0.0;

      /* Outport: '<Root>/ST3' */
      rtY.ST3 = 0.0;

      /* Outport: '<Root>/ST4' */
      rtY.ST4 = 0.0;

      /* Outport: '<Root>/ST5' */
      rtY.ST5 = 0.0;
    } else {
      guard1 = false;
      guard2 = false;
      guard3 = false;
      guard4 = false;
      guard5 = false;
      guard6 = false;
      guard7 = false;
      guard8 = false;
      guard9 = false;
      guard10 = false;
      switch (rtDW.is_c3_ONTROL) {
       case IN_INICIO:
        /* Outport: '<Root>/ST1' */
        rtY.ST1 = 0.0;

        /* Outport: '<Root>/ST2' */
        rtY.ST2 = 0.0;

        /* Outport: '<Root>/ST3' */
        rtY.ST3 = 0.0;

        /* Outport: '<Root>/ST4' */
        rtY.ST4 = 0.0;

        /* Outport: '<Root>/ST5' */
        rtY.ST5 = 0.0;

        /* Inport: '<Root>/DOOR_OUT' incorporates:
         *  Inport: '<Root>/DOOR_IN'
         */
        if (rtU.DOOR_OUT == 1.0) {
          rtDW.is_c3_ONTROL = IN_abrir1;

          /* Outport: '<Root>/puerta_out' */
          rtY.puerta_out = 1.0;
        } else {
          if (rtU.DOOR_IN == 1.0) {
            rtDW.is_c3_ONTROL = IN_abrir;

            /* Outport: '<Root>/puerta_in' */
            rtY.puerta_in = 1.0;
          }
        }
        break;

       case IN_PARQ1_OFF:
        /* Outport: '<Root>/ST1' */
        rtY.ST1 = 0.0;
        if ((rtDW.cont1 == 5.0) && (rtU.DOOR_OUT == 1.0)) {
          guard1 = true;
        } else if (rtU.DOOR_IN == 1.0) {
          rtDW.is_c3_ONTROL = IN_abrir;

          /* Outport: '<Root>/puerta_in' */
          rtY.puerta_in = 1.0;
        } else {
          if (rtU.DOOR_OUT == 1.0) {
            guard1 = true;
          }
        }
        break;

       case IN_PARQ1_ON:
        /* Outport: '<Root>/ST1' */
        rtY.ST1 = 1.0;
        if ((rtDW.cont1 == 5.0) && (rtU.DOOR_OUT == 1.0)) {
          guard2 = true;
        } else if (rtU.DOOR_IN == 1.0) {
          rtDW.is_c3_ONTROL = IN_abrir;

          /* Outport: '<Root>/puerta_in' */
          rtY.puerta_in = 1.0;
        } else {
          if (rtU.DOOR_OUT == 1.0) {
            guard2 = true;
          }
        }
        break;

       case IN_PARQ2_OFF:
        /* Outport: '<Root>/ST2' */
        rtY.ST2 = 0.0;
        if ((rtDW.cont1 == 5.0) && (rtU.DOOR_OUT == 1.0)) {
          guard3 = true;
        } else if (rtU.DOOR_IN == 1.0) {
          rtDW.is_c3_ONTROL = IN_abrir;

          /* Outport: '<Root>/puerta_in' */
          rtY.puerta_in = 1.0;
        } else {
          if (rtU.DOOR_OUT == 1.0) {
            guard3 = true;
          }
        }
        break;

       case IN_PARQ2_ON:
        /* Outport: '<Root>/ST2' */
        rtY.ST2 = 1.0;
        if ((rtDW.cont1 == 5.0) && (rtU.DOOR_OUT == 1.0)) {
          guard4 = true;
        } else if (rtU.DOOR_IN == 1.0) {
          rtDW.is_c3_ONTROL = IN_abrir;

          /* Outport: '<Root>/puerta_in' */
          rtY.puerta_in = 1.0;
        } else {
          if (rtU.DOOR_OUT == 1.0) {
            guard4 = true;
          }
        }
        break;

       case IN_PARQ3_OFF:
        /* Outport: '<Root>/ST3' */
        rtY.ST3 = 0.0;
        if ((rtDW.cont1 == 5.0) && (rtU.DOOR_OUT == 1.0)) {
          guard5 = true;
        } else if (rtU.DOOR_IN == 1.0) {
          rtDW.is_c3_ONTROL = IN_abrir;

          /* Outport: '<Root>/puerta_in' */
          rtY.puerta_in = 1.0;
        } else {
          if (rtU.DOOR_OUT == 1.0) {
            guard5 = true;
          }
        }
        break;

       case IN_PARQ3_ON:
        /* Outport: '<Root>/ST3' */
        rtY.ST3 = 1.0;
        if ((rtDW.cont1 == 5.0) && (rtU.DOOR_OUT == 1.0)) {
          guard6 = true;
        } else if (rtU.DOOR_IN == 1.0) {
          rtDW.is_c3_ONTROL = IN_abrir;

          /* Outport: '<Root>/puerta_in' */
          rtY.puerta_in = 1.0;
        } else {
          if (rtU.DOOR_OUT == 1.0) {
            guard6 = true;
          }
        }
        break;

       case IN_PARQ4_OFF:
        /* Outport: '<Root>/ST4' */
        rtY.ST4 = 0.0;
        if ((rtDW.cont1 == 5.0) && (rtU.DOOR_OUT == 1.0)) {
          guard7 = true;
        } else if (rtU.DOOR_IN == 1.0) {
          rtDW.is_c3_ONTROL = IN_abrir;

          /* Outport: '<Root>/puerta_in' */
          rtY.puerta_in = 1.0;
        } else {
          if (rtU.DOOR_OUT == 1.0) {
            guard7 = true;
          }
        }
        break;

       case IN_PARQ4_ON:
        /* Outport: '<Root>/ST4' */
        rtY.ST4 = 1.0;
        if ((rtDW.cont1 == 5.0) && (rtU.DOOR_OUT == 1.0)) {
          guard8 = true;
        } else if (rtU.DOOR_IN == 1.0) {
          rtDW.is_c3_ONTROL = IN_abrir;

          /* Outport: '<Root>/puerta_in' */
          rtY.puerta_in = 1.0;
        } else {
          if (rtU.DOOR_OUT == 1.0) {
            guard8 = true;
          }
        }
        break;

       case IN_PARQ5_OFF:
        /* Outport: '<Root>/ST5' */
        rtY.ST5 = 0.0;
        if ((rtDW.cont1 == 5.0) && (rtU.DOOR_OUT == 1.0)) {
          guard9 = true;
        } else if (rtU.DOOR_IN == 1.0) {
          rtDW.is_c3_ONTROL = IN_abrir;

          /* Outport: '<Root>/puerta_in' */
          rtY.puerta_in = 1.0;
        } else {
          if (rtU.DOOR_OUT == 1.0) {
            guard9 = true;
          }
        }
        break;

       case IN_PARQ5_ON:
        /* Outport: '<Root>/ST5' */
        rtY.ST5 = 1.0;
        if ((rtDW.cont1 == 5.0) && (rtU.DOOR_OUT == 1.0)) {
          guard10 = true;
        } else if (rtU.DOOR_IN == 1.0) {
          rtDW.is_c3_ONTROL = IN_abrir;

          /* Outport: '<Root>/puerta_in' */
          rtY.puerta_in = 1.0;
        } else {
          if (rtU.DOOR_OUT == 1.0) {
            guard10 = true;
          }
        }
        break;

       case IN_abrir:
        /* Outport: '<Root>/puerta_in' */
        rtY.puerta_in = 1.0;

        /* Inport: '<Root>/DOOR_IN' */
        if (rtU.DOOR_IN == 0.0) {
          rtDW.is_c3_ONTROL = IN_aumentar;

          /* Outport: '<Root>/puerta_in' */
          rtY.puerta_in = 0.0;
          rtDW.cont1++;

          /* Outport: '<Root>/cont' */
          rtY.cont++;
        }
        break;

       case IN_abrir1:
        /* Outport: '<Root>/puerta_out' */
        rtY.puerta_out = 1.0;

        /* Inport: '<Root>/DOOR_OUT' */
        if (rtU.DOOR_OUT == 0.0) {
          rtDW.is_c3_ONTROL = IN_disminuir;

          /* Outport: '<Root>/puerta_out' */
          rtY.puerta_out = 0.0;
          rtDW.cont1--;

          /* Outport: '<Root>/cont' */
          rtY.cont--;
        }
        break;

       case IN_aumentar:
        /* Outport: '<Root>/puerta_in' */
        rtY.puerta_in = 0.0;

        /* Inport: '<Root>/P1' incorporates:
         *  Inport: '<Root>/P2'
         *  Inport: '<Root>/P3'
         *  Inport: '<Root>/P4'
         *  Inport: '<Root>/P5'
         */
        if (rtU.P1 == 1.0) {
          rtDW.is_c3_ONTROL = IN_PARQ1_ON;

          /* Outport: '<Root>/ST1' */
          rtY.ST1 = 1.0;
        } else if (rtU.P2 == 1.0) {
          rtDW.is_c3_ONTROL = IN_PARQ2_ON;

          /* Outport: '<Root>/ST2' */
          rtY.ST2 = 1.0;
        } else if (rtU.P3 == 1.0) {
          rtDW.is_c3_ONTROL = IN_PARQ3_ON;

          /* Outport: '<Root>/ST3' */
          rtY.ST3 = 1.0;
        } else if (rtU.P4 == 1.0) {
          rtDW.is_c3_ONTROL = IN_PARQ4_ON;

          /* Outport: '<Root>/ST4' */
          rtY.ST4 = 1.0;
        } else {
          if (rtU.P5 == 1.0) {
            rtDW.is_c3_ONTROL = IN_PARQ5_ON;

            /* Outport: '<Root>/ST5' */
            rtY.ST5 = 1.0;
          }
        }
        break;

       default:
        /* Outport: '<Root>/puerta_out' */
        /* case IN_disminuir: */
        rtY.puerta_out = 0.0;

        /* Inport: '<Root>/P1' incorporates:
         *  Inport: '<Root>/P2'
         *  Inport: '<Root>/P3'
         *  Inport: '<Root>/P4'
         *  Inport: '<Root>/P5'
         */
        if (rtU.P1 == 0.0) {
          rtDW.is_c3_ONTROL = IN_PARQ1_OFF;

          /* Outport: '<Root>/ST1' */
          rtY.ST1 = 0.0;
        } else if (rtU.P2 == 0.0) {
          rtDW.is_c3_ONTROL = IN_PARQ2_OFF;

          /* Outport: '<Root>/ST2' */
          rtY.ST2 = 0.0;
        } else if (rtU.P3 == 0.0) {
          rtDW.is_c3_ONTROL = IN_PARQ3_OFF;

          /* Outport: '<Root>/ST3' */
          rtY.ST3 = 0.0;
        } else if (rtU.P4 == 0.0) {
          rtDW.is_c3_ONTROL = IN_PARQ4_OFF;

          /* Outport: '<Root>/ST4' */
          rtY.ST4 = 0.0;
        } else {
          if (rtU.P5 == 0.0) {
            rtDW.is_c3_ONTROL = IN_PARQ5_OFF;

            /* Outport: '<Root>/ST5' */
            rtY.ST5 = 0.0;
          }
        }
        break;
      }

      if (guard10) {
        rtDW.is_c3_ONTROL = IN_abrir1;

        /* Outport: '<Root>/puerta_out' */
        rtY.puerta_out = 1.0;
      }

      if (guard9) {
        rtDW.is_c3_ONTROL = IN_abrir1;

        /* Outport: '<Root>/puerta_out' */
        rtY.puerta_out = 1.0;
      }

      if (guard8) {
        rtDW.is_c3_ONTROL = IN_abrir1;

        /* Outport: '<Root>/puerta_out' */
        rtY.puerta_out = 1.0;
      }

      if (guard7) {
        rtDW.is_c3_ONTROL = IN_abrir1;

        /* Outport: '<Root>/puerta_out' */
        rtY.puerta_out = 1.0;
      }

      if (guard6) {
        rtDW.is_c3_ONTROL = IN_abrir1;

        /* Outport: '<Root>/puerta_out' */
        rtY.puerta_out = 1.0;
      }

      if (guard5) {
        rtDW.is_c3_ONTROL = IN_abrir1;

        /* Outport: '<Root>/puerta_out' */
        rtY.puerta_out = 1.0;
      }

      if (guard4) {
        rtDW.is_c3_ONTROL = IN_abrir1;

        /* Outport: '<Root>/puerta_out' */
        rtY.puerta_out = 1.0;
      }

      if (guard3) {
        rtDW.is_c3_ONTROL = IN_abrir1;

        /* Outport: '<Root>/puerta_out' */
        rtY.puerta_out = 1.0;
      }

      if (guard2) {
        rtDW.is_c3_ONTROL = IN_abrir1;

        /* Outport: '<Root>/puerta_out' */
        rtY.puerta_out = 1.0;
      }

      if (guard1) {
        rtDW.is_c3_ONTROL = IN_abrir1;

        /* Outport: '<Root>/puerta_out' */
        rtY.puerta_out = 1.0;
      }
    }
  }
}

/* Model initialize function */
void ONTROL_initialize(void)
{
  rtPrevZCX.Chart_Trig_ZCE = UNINITIALIZED_ZCSIG;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
