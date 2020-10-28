/*
 * File: Arduino_Simulink_CarController.h
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

#ifndef RTW_HEADER_Arduino_Simulink_CarController_h_
#define RTW_HEADER_Arduino_Simulink_CarController_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Arduino_Simulink_CarController_COMMON_INCLUDES_
# define Arduino_Simulink_CarController_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "arduino_digitaloutput_lct.h"
#endif                                 /* Arduino_Simulink_CarController_COMMON_INCLUDES_ */

#include "Arduino_Simulink_CarController_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#define Arduino_Simulink_CarController_M (Arduino_Simulink_CarControll_M)

/* Parameters (auto storage) */
struct P_Arduino_Simulink_CarControl_T_ {
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S1>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNum_cegre2zem4;/* Mask Parameter: DigitalOutput_pinNum_cegre2zem4
                                            * Referenced by: '<S2>/Digital Output'
                                            */
  uint32_T DigitalOutput_pinNum_ebpdnypdzt;/* Mask Parameter: DigitalOutput_pinNum_ebpdnypdzt
                                            * Referenced by: '<S3>/Digital Output'
                                            */
  uint32_T DigitalOutput_pinNum_er4ywp3lth;/* Mask Parameter: DigitalOutput_pinNum_er4ywp3lth
                                            * Referenced by: '<S4>/Digital Output'
                                            */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Arduino_Simulink_CarC_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

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

/* Block parameters (auto storage) */
extern P_Arduino_Simulink_CarControl_T Arduino_Simulink_CarControlle_P;

/* Model entry point functions */
extern void Arduino_Simulink_CarController_initialize(void);
extern void Arduino_Simulink_CarController_step(void);
extern void Arduino_Simulink_CarController_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Arduino_Simulink_Car_T *const Arduino_Simulink_CarControll_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Arduino_Simulink_CarController'
 * '<S1>'   : 'Arduino_Simulink_CarController/Digital Output'
 * '<S2>'   : 'Arduino_Simulink_CarController/Digital Output1'
 * '<S3>'   : 'Arduino_Simulink_CarController/Digital Output2'
 * '<S4>'   : 'Arduino_Simulink_CarController/Digital Output3'
 */
#endif                                 /* RTW_HEADER_Arduino_Simulink_CarController_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
