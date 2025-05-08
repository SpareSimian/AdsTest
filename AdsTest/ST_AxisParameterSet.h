#pragma once

// TwinCAT3 structures

#include <cstdint>

namespace TwinCAT3 {

#pragma pack(push, 1)

typedef uint32_t DWORD;
typedef char STRING;
typedef float REAL;
typedef double LREAL;
typedef short WORD;
typedef uint16_t UINT;
typedef uint32_t UDINT;

typedef char T_AmsNetId[23];

enum class E_NcAxisType : DWORD
{
   NcAxisType_undefined            = 0,
   NcAxisType_Continious           = 1,
   NcAxisType_Discrete_TwoSpeed    = 2,
   NcAxisType_LowCostStepper_DigIO = 3,
   NcAxisType_Encoder              = 5,
   NcAxisType_Hydraulic            = 6,
   NcAxisType_TimeGenerator        = 7,
   NcAxisType_Specific             = 100
};

enum class E_NcEncoderType : DWORD
{
     NcEncoderType_undefined, 
     NcEncoderType_Simulation,
     NcEncoderType_ABS_M3000,
     NcEncoderType_INC_M31X0,
     NcEncoderType_INC_KL5101,
     NcEncoderType_ABS_KL5001_SSI,
     NcEncoderType_INC_KL5051,
     NcEncoderType_ABS_KL30XX,
     NcEncoderType_INC_Sercos_P,
     NcEncoderType_INC_Sercos_PV,
     NcEncoderType_INC_Binary,
     NcEncoderType_ABS_M2510,
     NcEncoderType_ABS_FOX50,
     NcEncoderType_HYDRAULIC_FORCE,
     NcEncoderType_AX2000_B200,
     NcEncoderType_PROFIDRIVE,
     NcEncoderType_UNIVERSAL,
     NcEncoderType_NCBACKPLANE,
     NcEncoderType_CANOPEN_LENZE,
     NcEncoderType_CANOPEN_DS402_MDP513_MDP742,
     NcEncoderType_AX2000_B900, 
     NcEncoderType_KL5151,
     NcEncoderType_IP5209,
     NcEncoderType_KL2531_Stepper,
     NcEncoderType_KL2532_DC,
     NcEncoderType_TIMEBASEGENERATOR, 
     NcEncoderType_INC_TCOM,
     NcEncoderType_CANOPEN_MDP513_64BIT,
     NcEncoderType_SPECIFIC
};

enum class E_NcDriveType : DWORD
{
NcDriveType_undefined            = 0,
NcDriveType_M2400_DAC1           = 1,
NcDriveType_M2400_DAC2           = 2,
NcDriveType_M2400_DAC3           = 3,
NcDriveType_M2400_DAC4           = 4,
NcDriveType_KL4xxx               = 5,
NcDriveType_KL4xxx_NonLinear     = 6,
NcDriveType_Discete_TwoSpeed     = 7,
NcDriveType_Stepper              = 8,
NcDriveType_Sercos               = 9,
NcDriveType_KL5051               = 10,
NcDriveType_AX2000_B200          = 11,
NcDriveType_ProfilDrive          = 12,
NcDriveType_Universal            = 13,
NcDriveType_NcBackplane          = 14,
NcDriveType_CANopen_Lenze        = 15,
NcDriveType_CANopen_DS402_MDP742 = 16,
NcDriveType_AX2000_B900          = 17,
NcDriveType_KL2531_Stepper       = 20,
NcDriveType_KL2532_DC            = 21,
NcDriveType_TCOM                 = 22,
NcDriveType_MDP_733              = 23,
NcDriveType_MDP_703              = 24
};

union ST_AxisParameterSet
{
   uint8_t buffer[1024]; // to pad to the desired size for AdsSyncReadReq
   struct
   {
      /* AXIS: */
      DWORD AxisId;          /* 0x00000001 */
      E_NcAxisType nAxisType;   /* 0x00000003 */
      STRING sAxisName[31];     /* 0x00000002 */
      LREAL fAxisCycleTime;          /* 0x00000004 */
      WORD bEnablePositionAreaControl;           /* 0x0000000F */
      LREAL fPositionAreaControlRange;          /* 0x00000010 */
      WORD bEnableMotionControl;           /* 0x00000011 */
      LREAL fMotionControlTime;          /* 0x00000012 */
      WORD bEnableLoop;           /* 0x00000013 */
      LREAL fLoopDistance;          /* 0x00000014 */
      WORD bEnableTargetPosControl;           /* 0x00000015 */
      LREAL fTargetPosControlRange;          /* 0x00000016 */
      LREAL fTargetPosControlTime;          /* 0x00000017 */
      LREAL fVeloMaximum;          /* 0x00000027 */
      LREAL fRefVeloSearch;          /* 0x00000006 */
      LREAL fRefVeloSync;          /* 0x00000007 */
      LREAL fVeloSlowManual;          /* 0x00000008 */
      LREAL fVeloFastManual;          /* 0x00000009 */
      LREAL fMotionControlRange;          /* 0x00000028 */
      WORD bEnablePEHTimeControl;           /* 0x00000029 */
      LREAL fPEHControlTime;          /* 0x0000002A */
      WORD bEnableBacklashCompensation;           /* 0x0000002B */
      LREAL fBacklash;          /* 0x0000002C */
      T_AmsNetId sAmsNetId;     /* 0x00000031 */
      WORD nPort;           /* 0x00000031 */
      WORD nChnNo;           /* 0x00000031 */
      LREAL fAcceleration;          /* 0x00000101 */
      LREAL fDeceleration;          /* 0x00000102 */
      LREAL fJerk;          /* 0x00000103 */

      /* ENCODER: */
      DWORD nEncId;          /* 0x00010001 */
      E_NcEncoderType nEncType;/* 0x00010003 */
      STRING sEncName[31];     /* 0x00010002 */
      LREAL fEncScaleFactorNumerator;          /* 0x00010023 */
      LREAL fEncScaleFactorDenominator;          /* 0x00010024 */
      LREAL fEncScaleFactor;          /* 0x00010006 */
      LREAL fEncOffset;          /* 0x00010007 */
      WORD bEncIsInverse;           /* 0x00010008 */
      LREAL fEncModuloFactor;          /* 0x00010009 */
      DWORD nEncMode;          /* 0x0001000A */
      WORD bEncEnableSoftEndMinControl;           /* 0x0001000B */
      WORD bEncEnableSoftEndMaxControl;           /* 0x0001000C */
      LREAL fEncSoftEndMin;          /* 0x0001000D */
      LREAL fEncSoftEndMax;          /* 0x0001000E */
      DWORD nEncMaxIncrement;          /* 0x00010015 */
      DWORD nEncRefSoftSyncMask;          /* 0x00010108 */
      WORD bEncEnablePosCorrection;           /* 0x00010016 */
      DWORD nEncReferenceSystem;          /* 0x00010019 */
      LREAL fEncPosCorrectionFilterTime;          /* 0x00010017 */
      UINT bEncRefSearchInverse;           /* 0x00010101 */
      UINT bEncRefSyncInverse;           /* 0x00010102 */
      UDINT nEncRefMode;          /* 0x00010107 */
      LREAL fEncRefPosition;          /* 0x00010103 */

      /* CONTROLLER: */
      DWORD nCtrlId;        /* 0x00020001 */
      DWORD nCtrlType;        /* 0x00020003 */
      STRING sCtrlName[31];   /* 0x00020002 */
      WORD bCtrlEnablePosDiffControl;         /* 0x00020010 */
      WORD bCtrlEnableVeloDiffControl;         /* 0x00020011 */
      LREAL fCtrlPosDiffMax;        /* 0x00020012 */
      LREAL fCtrlPosDiffMaxTime;        /* 0x00020013 */
      LREAL fCtrlPosKp;        /* 0x00020102 */
      LREAL fCtrlPosTn;        /* 0x00020103 */
      LREAL fCtrlPosTv;        /* 0x00020104 */
      LREAL fCtrlPosTd;        /* 0x00020105 */
      LREAL fCtrlPosExtKp;        /* 0x00020106 */
      LREAL fCtrlPosExtVelo;        /* 0x00020107 */
      LREAL fCtrlAccKa;        /* 0x00020108 */

      /* DRIVE: */
      DWORD nDriveId;        /* 0x00030001 */
      E_NcDriveType nDriveType;/* 0x00030003 */
      STRING sDriveName[31];   /* 0x00030002 */
      WORD bDriveIsInverse;         /* 0x00030006 */
      DWORD nDriveControlDWord;        /* 0x00030010 */
      LREAL fDriveVeloReferenz;        /* 0x00030101 */
      LREAL fDriveOutputReferenz;        /* 0x00030102 */
      LREAL fDriveOutputScalingAcc;        /* 0x0003000A */
      LREAL fDriveOutputScalingTorque;        /* 0x0003000B */
      LREAL fDriveInputScalingTorque;        /* 0x00030031 */
      LREAL fDriveInputFiltertimeTorque;        /* 0x00030032 */
      LREAL fDriveInputFiltertimeTorqueDerivative;/* 0x00030033 */

      LREAL fAccelerationMax;        /* 0x000300F1 */
      LREAL fDecelerationMax;        /* 0x000300F2 */
   };
};

#pragma pack(pop)

} // namespace
