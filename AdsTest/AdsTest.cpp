// test ADS communication to TwinCAT 3 NC PTP system

#include <iostream>
#include <stdexcept>
#include <sstream>

#include <TcAdsApi.h>
#include "ST_AxisParameterSet.h"

// RAII class to release port on exceptions
class AdsPort
{
public:
   AdsPort() { AdsPortOpen(); }
   ~AdsPort() { AdsPortClose(); }
};

class AdsNcConnection
{
   AdsPort port;
   AmsAddr addr;
public:
   AdsNcConnection();
   AmsAddr& getAddr() { return addr; }
};

static std::string apiFailed(const std::string& api, ads_i32 nErr)
{
   std::ostringstream os;
   os << api << " failed: " << nErr;
   return os.str();
}

AdsNcConnection::AdsNcConnection()
{
   long nErr = AdsGetLocalAddress(&addr);
   if (nErr)
      throw std::runtime_error(apiFailed("AdsGetLocalAddress", nErr));
   addr.port = 500; // NC uses this AMS port
}

std::ostream& operator<<(std::ostream& os, const TwinCAT3::ST_AxisParameterSet& aps)
{
   os << "AxisId: " << aps.AxisId << '\n';
   os << "nAxisType: " << static_cast<unsigned>(aps.nAxisType) << '\n';
   os << "sAxisName: " << aps.sAxisName << '\n';
   os << "fAxisCycleTime: " << aps.fAxisCycleTime << '\n';
   os << "bEnablePositionAreaControl: " << aps.bEnablePositionAreaControl << '\n';
   os << "fPositionAreaControlRange: " << aps.fPositionAreaControlRange << '\n';
   os << "bEnableMotionControl: " << aps.bEnableMotionControl << '\n';
   os << "fMotionControlTime: " << aps.fMotionControlTime << '\n';
   os << "bEnableLoop: " << aps.bEnableLoop << '\n';
   os << "fLoopDistance: " << aps.fLoopDistance << '\n';
   os << "bEnableTargetPosControl: " << aps.bEnableTargetPosControl << '\n';
   os << "fTargetPosControlRange: " << aps.fTargetPosControlRange << '\n';
   os << "fTargetPosControlTime: " << aps.fTargetPosControlTime << '\n';
   os << "fVeloMaximum: " << aps.fVeloMaximum << '\n';
   os << "fRefVeloSearch: " << aps.fRefVeloSearch << '\n';
   os << "fRefVeloSync: " << aps.fRefVeloSync << '\n';
   os << "fVeloSlowManual: " << aps.fVeloSlowManual << '\n';
   os << "fVeloFastManual: " << aps.fVeloFastManual << '\n';
   os << "fMotionControlRange: " << aps.fMotionControlRange << '\n';
   os << "bEnablePEHTimeControl: " << aps.bEnablePEHTimeControl << '\n';
   os << "fPEHControlTime: " << aps.fPEHControlTime << '\n';
   os << "bEnableBacklashCompensation: " << aps.bEnableBacklashCompensation << '\n';
   os << "fBacklash: " << aps.fBacklash << '\n';
   os << "sAmsNetId: " << aps.sAmsNetId << '\n';
   os << "nPort: " << aps.nPort << '\n';
   os << "nChnNo: " << aps.nChnNo << '\n';
   os << "fAcceleration: " << aps.fAcceleration << '\n';
   os << "fDeceleration: " << aps.fDeceleration << '\n';
   os << "fJerk: " << aps.fJerk << '\n';

   /* ENCODER: */
   os << "nEncId: " << aps.nEncId << '\n';
   os << "nEncType: " << static_cast<unsigned>(aps.nEncType) << '\n';
   os << "sEncName: " << aps.sEncName << '\n';
   os << "fEncScaleFactorNumerator: " << aps.fEncScaleFactorNumerator << '\n';
   os << "fEncScaleFactorDenominator: " << aps.fEncScaleFactorDenominator << '\n';
   os << "fEncScaleFactor: " << aps.fEncScaleFactor << '\n';
   os << "fEncOffset: " << aps.fEncOffset << '\n';
   os << "bEncIsInverse: " << aps.bEncIsInverse << '\n';
   os << "fEncModuloFactor: " << aps.fEncModuloFactor << '\n';
   os << "nEncMode: " << aps.nEncMode << '\n';
   os << "bEncEnableSoftEndMinControl: " << aps.bEncEnableSoftEndMinControl << '\n';
   os << "bEncEnableSoftEndMaxControl: " << aps.bEncEnableSoftEndMaxControl << '\n';
   os << "fEncSoftEndMin: " << aps.fEncSoftEndMin << '\n';
   os << "fEncSoftEndMax: " << aps.fEncSoftEndMax << '\n';
   os << "nEncMaxIncrement: " << aps.nEncMaxIncrement << '\n';
   os << "nEncRefSoftSyncMask: " << aps.nEncRefSoftSyncMask << '\n';
   os << "bEncEnablePosCorrection: " << aps.bEncEnablePosCorrection << '\n';
   os << "nEncReferenceSystem: " << aps.nEncReferenceSystem << '\n';
   os << "fEncPosCorrectionFilterTime: " << aps.fEncPosCorrectionFilterTime << '\n';
   os << "bEncRefSearchInverse: " << aps.bEncRefSearchInverse << '\n';
   os << "bEncRefSyncInverse: " << aps.bEncRefSyncInverse << '\n';
   os << "nEncRefMode: " << aps.nEncRefMode << '\n';
   os << "fEncRefPosition: " << aps.fEncRefPosition << '\n';

   /* CONTROLLER: */
   os << "nCtrlId: " << aps.nCtrlId << '\n';
   os << "nCtrlType: " << aps.nCtrlType << '\n';
   os << "sCtrlName: " << aps.sCtrlName << '\n';
   os << "bCtrlEnablePosDiffControl: " << aps.bCtrlEnablePosDiffControl << '\n';
   os << "bCtrlEnableVeloDiffControl: " << aps.bCtrlEnableVeloDiffControl << '\n';
   os << "fCtrlPosDiffMax: " << aps.fCtrlPosDiffMax << '\n';
   os << "fCtrlPosDiffMaxTime: " << aps.fCtrlPosDiffMaxTime << '\n';
   os << "fCtrlPosKp: " << aps.fCtrlPosKp << '\n';
   os << "fCtrlPosTn: " << aps.fCtrlPosTn << '\n';
   os << "fCtrlPosTv: " << aps.fCtrlPosTv << '\n';
   os << "fCtrlPosTd: " << aps.fCtrlPosTd << '\n';
   os << "fCtrlPosExtKp: " << aps.fCtrlPosExtKp << '\n';
   os << "fCtrlPosExtVelo: " << aps.fCtrlPosExtVelo << '\n';
   os << "fCtrlAccKa: " << aps.fCtrlAccKa << '\n';

   /* DRIVE: */
   os << "nDriveId: " << aps.nDriveId << '\n';
   os << "nDriveType: " << static_cast<unsigned>(aps.nDriveType) << '\n';
   os << "sDriveName: " << aps.sDriveName << '\n';
   os << "bDriveIsInverse: " << aps.bDriveIsInverse << '\n';
   os << "nDriveControlDWord: " << aps.nDriveControlDWord << '\n';
   os << "fDriveVeloReferenz: " << aps.fDriveVeloReferenz << '\n';
   os << "fDriveOutputReferenz: " << aps.fDriveOutputReferenz << '\n';
   os << "fDriveOutputScalingAcc: " << aps.fDriveOutputScalingAcc << '\n';
   os << "fDriveOutputScalingTorque: " << aps.fDriveOutputScalingTorque << '\n';
   os << "fDriveInputScalingTorque: " << aps.fDriveInputScalingTorque << '\n';
   os << "fDriveInputFiltertimeTorque: " << aps.fDriveInputFiltertimeTorque << '\n';
   os << "fDriveInputFiltertimeTorqueDerivative: " << aps.fDriveInputFiltertimeTorqueDerivative << '\n';

   os << "fAccelerationMax: " << aps.fAccelerationMax << '\n';
   os << "fDecelerationMax: " << aps.fDecelerationMax << '\n';

   return os;
};

int main()
{
   const ads_i32 nTemp = AdsGetDllVersion();
   const AdsVersion* pDLLVersion = reinterpret_cast<const AdsVersion *>(&nTemp);
   std::cout << "Version: " << (int)pDLLVersion->version << '\n';
   std::cout << "Revision: " << (int)pDLLVersion->revision << '\n';
   std::cout << "Build: " << pDLLVersion->build << '\n';

   AdsNcConnection conn;

   const int axisId = 1;
   ads_i32 axisIdRead;
   ads_i32 nErr = AdsSyncReadReq(&conn.getAddr(), 0x4000 + axisId, 0x00000001, sizeof axisIdRead, &axisIdRead);
   if (nErr) throw std::runtime_error(apiFailed("AdsSyncReadReq", nErr));
   else std::cout << "axis ID read " << axisIdRead << '\n';

   TwinCAT3::ST_AxisParameterSet axisParameterSet;
   nErr = AdsSyncReadReq(&conn.getAddr(), 0x4000 + axisId, axisId * 0x100000, sizeof axisParameterSet, &axisParameterSet);
   if (nErr) throw std::runtime_error(apiFailed("AdsSyncReadReq(ST_AxisParameterSet)", nErr));
   std::cout << axisParameterSet;
   
   AdsPortClose();
   return 0;
}

