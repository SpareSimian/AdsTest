#pragma once

#include "BaseTypes.h"

// TwinCAT3 structure ST_AxisParameterSet

namespace TwinCAT3 {

// https://infosys.beckhoff.com/english.php?content=../content/1033/tc3_ads_intro/713061899.html&id=4266053388574064834
// note that there seems to be no PLC state type for this so we craft
// one from the API description

#pragma pack(push, 8)

union ST_AxisState
{
   uint8_t buffer[256]; // to pad to the desired size for AdsSyncReadReq
   struct
   {
      int32_t nErrorState;
      int32_t reserved1;
      LREAL fActualPosition;
      LREAL fModuloActualPosition;
      LREAL fSetPosition;
      LREAL fModuloSetPosition;
      LREAL fActualVelocity;
      LREAL fSetVelocity;
      uint32_t nVelocityOverride; // 0..1000000, 1000000 = 100%
      uint32_t reserved2;
      LREAL fLagErrorPosition;
      LREAL fPeakHoldValueForMaxNegativePositionLag;
      LREAL fPeakHoldValueForMaxPositivePositionLag;
      LREAL fControllerOutputPercent;
      LREAL fTotalOutputPercent;
      uint32_t nAxisState;
      uint32_t nAxisControl;
      uint32_t nSlaveCouplingState;
      uint32_t nAxisControlLoopIndex;
      LREAL fActualAcceleration;
      LREAL fSetAcceleration;
      LREAL fSetJerk;
      LREAL fSetTorque;
      LREAL fActualTorque;
      LREAL fSetTorqueChange;
      LREAL fAdditiveSetTorque;
   };
};

#pragma pack(pop)

} // namespace
