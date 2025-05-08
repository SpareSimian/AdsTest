#pragma once

#include "BaseTypes.h"

// TwinCAT3 structure ST_AxisParameterSet

namespace TwinCAT3 {

// https://infosys.beckhoff.com/english.php?content=../content/1033/tcplclib_tc2_mc2/70159755.html&id=

#pragma pack(push, 8)

union ST_AxisParameterSet
{
   uint8_t buffer[1024]; // to pad to the desired size for AdsSyncReadReq
   struct
   {
      /* AXIS: */
      DWORD AxisId;          /* 0x00000001 */
      E_NcAxisType nAxisType;   /* 0x00000003 */
      STRING sAxisName[1 + 31];     /* 0x00000002 */
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
      STRING sEncName[1 + 31];     /* 0x00010002 */
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
      STRING sCtrlName[1 + 31];   /* 0x00020002 */
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
      STRING sDriveName[1 + 31];   /* 0x00030002 */
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
