/*
 * File: Arduino_Simulink_CarController.c
 *
 * Code generated for Simulink model 'Arduino_Simulink_CarController'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Sun Feb 09 18:56:39 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Arduino_Simulink_CarController.h"
#include "Arduino_Simulink_CarController_private.h"
#include "Arduino_Simulink_CarController_dt.h"

/* Real-time model */
RT_MODEL_Arduino_Simulink_Car_T Arduino_Simulink_CarControll_M_;
RT_MODEL_Arduino_Simulink_Car_T *const Arduino_Simulink_CarControll_M =
  &Arduino_Simulink_CarControll_M_;

/* Model step function */
void Arduino_Simulink_CarController_step(void)
{
  uint8_T tmp;

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (Arduino_Simulink_CarControlle_P.Constant_Value < 256.0) {
    if (Arduino_Simulink_CarControlle_P.Constant_Value >= 0.0) {
      tmp = (uint8_T)Arduino_Simulink_CarControlle_P.Constant_Value;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S1>/Digital Output' */
  MW_digitalWrite(Arduino_Simulink_CarControlle_P.DigitalOutput_pinNumber, tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  if (Arduino_Simulink_CarControlle_P.Constant1_Value < 256.0) {
    if (Arduino_Simulink_CarControlle_P.Constant1_Value >= 0.0) {
      tmp = (uint8_T)Arduino_Simulink_CarControlle_P.Constant1_Value;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S2>/Digital Output' */
  MW_digitalWrite
    (Arduino_Simulink_CarControlle_P.DigitalOutput_pinNum_cegre2zem4, tmp);

  /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  if (Arduino_Simulink_CarControlle_P.Constant2_Value < 256.0) {
    if (Arduino_Simulink_CarControlle_P.Constant2_Value >= 0.0) {
      tmp = (uint8_T)Arduino_Simulink_CarControlle_P.Constant2_Value;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S3>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S3>/Digital Output' */
  MW_digitalWrite
    (Arduino_Simulink_CarControlle_P.DigitalOutput_pinNum_ebpdnypdzt, tmp);

  /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  if (Arduino_Simulink_CarControlle_P.Constant3_Value < 256.0) {
    if (Arduino_Simulink_CarControlle_P.Constant3_Value >= 0.0) {
      tmp = (uint8_T)Arduino_Simulink_CarControlle_P.Constant3_Value;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S4>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S4>/Digital Output' */
  MW_digitalWrite
    (Arduino_Simulink_CarControlle_P.DigitalOutput_pinNum_er4ywp3lth, tmp);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.2s, 0.0s] */
    rtExtModeUpload(0, Arduino_Simulink_CarControll_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal(Arduino_Simulink_CarControll_M)!=-1) &&
        !((rtmGetTFinal(Arduino_Simulink_CarControll_M)-
           Arduino_Simulink_CarControll_M->Timing.taskTime0) >
          Arduino_Simulink_CarControll_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Arduino_Simulink_CarControll_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Arduino_Simulink_CarControll_M)) {
      rtmSetErrorStatus(Arduino_Simulink_CarControll_M, "Simulation finished");
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
  if (!(++Arduino_Simulink_CarControll_M->Timing.clockTick0)) {
    ++Arduino_Simulink_CarControll_M->Timing.clockTickH0;
  }

  Arduino_Simulink_CarControll_M->Timing.taskTime0 =
    Arduino_Simulink_CarControll_M->Timing.clockTick0 *
    Arduino_Simulink_CarControll_M->Timing.stepSize0 +
    Arduino_Simulink_CarControll_M->Timing.clockTickH0 *
    Arduino_Simulink_CarControll_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Arduino_Simulink_CarController_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Arduino_Simulink_CarControll_M, 0,
                sizeof(RT_MODEL_Arduino_Simulink_Car_T));
  rtmSetTFinal(Arduino_Simulink_CarControll_M, -1);
  Arduino_Simulink_CarControll_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  Arduino_Simulink_CarControll_M->Sizes.checksums[0] = (2494825236U);
  Arduino_Simulink_CarControll_M->Sizes.checksums[1] = (3379680840U);
  Arduino_Simulink_CarControll_M->Sizes.checksums[2] = (461467940U);
  Arduino_Simulink_CarControll_M->Sizes.checksums[3] = (1514040388U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Arduino_Simulink_CarControll_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Arduino_Simulink_CarControll_M->extModeInfo,
      &Arduino_Simulink_CarControll_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Arduino_Simulink_CarControll_M->extModeInfo,
                        Arduino_Simulink_CarControll_M->Sizes.checksums);
    rteiSetTPtr(Arduino_Simulink_CarControll_M->extModeInfo, rtmGetTPtr
                (Arduino_Simulink_CarControll_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Arduino_Simulink_CarControll_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S1>/Digital Output' */
  MW_pinModeOutput(Arduino_Simulink_CarControlle_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S2>/Digital Output' */
  MW_pinModeOutput
    (Arduino_Simulink_CarControlle_P.DigitalOutput_pinNum_cegre2zem4);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S3>/Digital Output' */
  MW_pinModeOutput
    (Arduino_Simulink_CarControlle_P.DigitalOutput_pinNum_ebpdnypdzt);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S4>/Digital Output' */
  MW_pinModeOutput
    (Arduino_Simulink_CarControlle_P.DigitalOutput_pinNum_er4ywp3lth);
}

/* Model terminate function */
void Arduino_Simulink_CarController_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
