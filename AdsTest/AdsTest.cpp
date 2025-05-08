// test ADS communication to TwinCAT 3 NC PTP system

#include <iostream>
#include <stdexcept>
#include <sstream>
#include "hexdump/hexdump.hpp"

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
   typedef TwinCAT3::ST_AxisParameterSet APS;
   os << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
   os << " AXIS:\n";
   os << std::hex << offsetof(APS, AxisId) << ' ' << sizeof aps.AxisId << " AxisId: " << std::dec << aps.AxisId << '\n';
   os << std::hex << offsetof(APS, nAxisType) << ' ' << sizeof aps.nAxisType << " nAxisType: " << std::dec << static_cast<unsigned>(aps.nAxisType) << '\n';
   os << std::hex << offsetof(APS, sAxisName) << ' ' << sizeof aps.sAxisName << " sAxisName: " << std::dec << aps.sAxisName << '\n';
   os << std::hex << offsetof(APS, fAxisCycleTime) << ' ' << sizeof aps.fAxisCycleTime << " fAxisCycleTime: " << std::dec << aps.fAxisCycleTime << '\n';
   os << std::hex << offsetof(APS, bEnablePositionAreaControl) << ' ' << sizeof aps.bEnablePositionAreaControl << " bEnablePositionAreaControl: " << std::dec << aps.bEnablePositionAreaControl << '\n';
   os << std::hex << offsetof(APS, fPositionAreaControlRange) << ' ' << sizeof aps.fPositionAreaControlRange << " fPositionAreaControlRange: " << std::dec << aps.fPositionAreaControlRange << '\n';
   os << std::hex << offsetof(APS, bEnableMotionControl) << ' ' << sizeof aps.bEnableMotionControl << " bEnableMotionControl: " << std::dec << aps.bEnableMotionControl << '\n';
   os << std::hex << offsetof(APS, fMotionControlTime) << ' ' << sizeof aps.fMotionControlTime << " fMotionControlTime: " << std::dec << aps.fMotionControlTime << '\n';
   os << std::hex << offsetof(APS, bEnableLoop) << ' ' << sizeof aps.bEnableLoop << " bEnableLoop: " << std::dec << aps.bEnableLoop << '\n';
   os << std::hex << offsetof(APS, fLoopDistance) << ' ' << sizeof aps.fLoopDistance << " fLoopDistance: " << std::dec << aps.fLoopDistance << '\n';
   os << std::hex << offsetof(APS, bEnableTargetPosControl) << ' ' << sizeof aps.bEnableTargetPosControl << " bEnableTargetPosControl: " << std::dec << aps.bEnableTargetPosControl << '\n';
   os << std::hex << offsetof(APS, fTargetPosControlRange) << ' ' << sizeof aps.fTargetPosControlRange << " fTargetPosControlRange: " << std::dec << aps.fTargetPosControlRange << '\n';
   os << std::hex << offsetof(APS, fTargetPosControlTime) << ' ' << sizeof aps.fTargetPosControlTime << " fTargetPosControlTime: " << std::dec << aps.fTargetPosControlTime << '\n';
   os << std::hex << offsetof(APS, fVeloMaximum) << ' ' << sizeof aps.fVeloMaximum << " fVeloMaximum: " << std::dec << aps.fVeloMaximum << '\n';
   os << std::hex << offsetof(APS, fRefVeloSearch) << ' ' << sizeof aps.fRefVeloSearch << " fRefVeloSearch: " << std::dec << aps.fRefVeloSearch << '\n';
   os << std::hex << offsetof(APS, fRefVeloSync) << ' ' << sizeof aps.fRefVeloSync << " fRefVeloSync: " << std::dec << aps.fRefVeloSync << '\n';
   os << std::hex << offsetof(APS, fVeloSlowManual) << ' ' << sizeof aps.fVeloSlowManual << " fVeloSlowManual: " << std::dec << aps.fVeloSlowManual << '\n';
   os << std::hex << offsetof(APS, fVeloFastManual) << ' ' << sizeof aps.fVeloFastManual << " fVeloFastManual: " << std::dec << aps.fVeloFastManual << '\n';
   os << std::hex << offsetof(APS, fMotionControlRange) << ' ' << sizeof aps.fMotionControlRange << " fMotionControlRange: " << std::dec << aps.fMotionControlRange << '\n';
   os << std::hex << offsetof(APS, bEnablePEHTimeControl) << ' ' << sizeof aps.bEnablePEHTimeControl << " bEnablePEHTimeControl: " << std::dec << aps.bEnablePEHTimeControl << '\n';
   os << std::hex << offsetof(APS, fPEHControlTime) << ' ' << sizeof aps.fPEHControlTime << " fPEHControlTime: " << std::dec << aps.fPEHControlTime << '\n';
   os << std::hex << offsetof(APS, bEnableBacklashCompensation) << ' ' << sizeof aps.bEnableBacklashCompensation << " bEnableBacklashCompensation: " << std::dec << aps.bEnableBacklashCompensation << '\n';
   os << std::hex << offsetof(APS, fBacklash) << ' ' << sizeof aps.fBacklash << " fBacklash: " << std::dec << aps.fBacklash << '\n';
   os << std::hex << offsetof(APS, sAmsNetId) << ' ' << sizeof aps.sAmsNetId << " sAmsNetId: " << std::dec << aps.sAmsNetId << '\n';
   os << std::hex << offsetof(APS, nPort) << ' ' << sizeof aps.nPort << " nPort: " << std::dec << aps.nPort << '\n';
   os << std::hex << offsetof(APS, nChnNo) << ' ' << sizeof aps.nChnNo << " nChnNo: " << std::dec << aps.nChnNo << '\n';
   os << std::hex << offsetof(APS, fAcceleration) << ' ' << sizeof aps.fAcceleration << " fAcceleration: " << std::dec << aps.fAcceleration << '\n';
   os << std::hex << offsetof(APS, fDeceleration) << ' ' << sizeof aps.fDeceleration << " fDeceleration: " << std::dec << aps.fDeceleration << '\n';
   os << std::hex << offsetof(APS, fJerk) << ' ' << sizeof aps.fJerk << " fJerk: " << std::dec << aps.fJerk << '\n';

   os << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
   os << " ENCODER:\n";
   os << std::hex << offsetof(APS, nEncId) << ' ' << sizeof aps.nEncId << " nEncId: " << std::dec << aps.nEncId << '\n';
   os << std::hex << offsetof(APS, nEncType) << ' ' << sizeof aps.nEncType << " nEncType: " << std::dec << static_cast<unsigned>(aps.nEncType) << '\n';
   os << std::hex << offsetof(APS, sEncName) << ' ' << sizeof aps.sEncName << " sEncName: " << std::dec << aps.sEncName << '\n';
   os << std::hex << offsetof(APS, fEncScaleFactorNumerator) << ' ' << sizeof aps.fEncScaleFactorNumerator << " fEncScaleFactorNumerator: " << std::dec << aps.fEncScaleFactorNumerator << '\n';
   os << std::hex << offsetof(APS, fEncScaleFactorDenominator) << ' ' << sizeof aps.fEncScaleFactorDenominator << " fEncScaleFactorDenominator: " << std::dec << aps.fEncScaleFactorDenominator << '\n';
   os << std::hex << offsetof(APS, fEncScaleFactor) << ' ' << sizeof aps.fEncScaleFactor << " fEncScaleFactor: " << std::dec << aps.fEncScaleFactor << '\n';
   os << std::hex << offsetof(APS, fEncOffset) << ' ' << sizeof aps.fEncOffset << " fEncOffset: " << std::dec << aps.fEncOffset << '\n';
   os << std::hex << offsetof(APS, bEncIsInverse) << ' ' << sizeof aps.bEncIsInverse << " bEncIsInverse: " << std::dec << aps.bEncIsInverse << '\n';
   os << std::hex << offsetof(APS, fEncModuloFactor) << ' ' << sizeof aps.fEncModuloFactor << " fEncModuloFactor: " << std::dec << aps.fEncModuloFactor << '\n';
   os << std::hex << offsetof(APS, nEncMode) << ' ' << sizeof aps.nEncMode << " nEncMode: " << std::dec << aps.nEncMode << '\n';
   os << std::hex << offsetof(APS, bEncEnableSoftEndMinControl) << ' ' << sizeof aps.bEncEnableSoftEndMinControl << " bEncEnableSoftEndMinControl: " << std::dec << aps.bEncEnableSoftEndMinControl << '\n';
   os << std::hex << offsetof(APS, bEncEnableSoftEndMaxControl) << ' ' << sizeof aps.bEncEnableSoftEndMaxControl << " bEncEnableSoftEndMaxControl: " << std::dec << aps.bEncEnableSoftEndMaxControl << '\n';
   os << std::hex << offsetof(APS, fEncSoftEndMin) << ' ' << sizeof aps.fEncSoftEndMin << " fEncSoftEndMin: " << std::dec << aps.fEncSoftEndMin << '\n';
   os << std::hex << offsetof(APS, fEncSoftEndMax) << ' ' << sizeof aps.fEncSoftEndMax << " fEncSoftEndMax: " << std::dec << aps.fEncSoftEndMax << '\n';
   os << std::hex << offsetof(APS, nEncMaxIncrement) << ' ' << sizeof aps.nEncMaxIncrement << " nEncMaxIncrement: " << std::dec << aps.nEncMaxIncrement << '\n';
   os << std::hex << offsetof(APS, nEncRefSoftSyncMask) << ' ' << sizeof aps.nEncRefSoftSyncMask << " nEncRefSoftSyncMask: " << std::dec << aps.nEncRefSoftSyncMask << '\n';
   os << std::hex << offsetof(APS, bEncEnablePosCorrection) << ' ' << sizeof aps.bEncEnablePosCorrection << " bEncEnablePosCorrection: " << std::dec << aps.bEncEnablePosCorrection << '\n';
   os << std::hex << offsetof(APS, nEncReferenceSystem) << ' ' << sizeof aps.nEncReferenceSystem << " nEncReferenceSystem: " << std::dec << aps.nEncReferenceSystem << '\n';
   os << std::hex << offsetof(APS, fEncPosCorrectionFilterTime) << ' ' << sizeof aps.fEncPosCorrectionFilterTime << " fEncPosCorrectionFilterTime: " << std::dec << aps.fEncPosCorrectionFilterTime << '\n';
   os << std::hex << offsetof(APS, bEncRefSearchInverse) << ' ' << sizeof aps.bEncRefSearchInverse << " bEncRefSearchInverse: " << std::dec << aps.bEncRefSearchInverse << '\n';
   os << std::hex << offsetof(APS, bEncRefSyncInverse) << ' ' << sizeof aps.bEncRefSyncInverse << " bEncRefSyncInverse: " << std::dec << aps.bEncRefSyncInverse << '\n';
   os << std::hex << offsetof(APS, nEncRefMode) << ' ' << sizeof aps.nEncRefMode << " nEncRefMode: " << std::dec << aps.nEncRefMode << '\n';
   os << std::hex << offsetof(APS, fEncRefPosition) << ' ' << sizeof aps.fEncRefPosition << " fEncRefPosition: " << std::dec << aps.fEncRefPosition << '\n';

   os << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
   os << " CONTROLLER:\n";
   os << std::hex << offsetof(APS, nCtrlId) << ' ' << sizeof aps.nCtrlId << " nCtrlId: " << std::dec << aps.nCtrlId << '\n';
   os << std::hex << offsetof(APS, nCtrlType) << ' ' << sizeof aps.nCtrlType << " nCtrlType: " << std::dec << aps.nCtrlType << '\n';
   os << std::hex << offsetof(APS, sCtrlName) << ' ' << sizeof aps.sCtrlName << " sCtrlName: " << std::dec << aps.sCtrlName << '\n';
   os << std::hex << offsetof(APS, bCtrlEnablePosDiffControl) << ' ' << sizeof aps.bCtrlEnablePosDiffControl << " bCtrlEnablePosDiffControl: " << std::dec << aps.bCtrlEnablePosDiffControl << '\n';
   os << std::hex << offsetof(APS, bCtrlEnableVeloDiffControl) << ' ' << sizeof aps.bCtrlEnableVeloDiffControl << " bCtrlEnableVeloDiffControl: " << std::dec << aps.bCtrlEnableVeloDiffControl << '\n';
   os << std::hex << offsetof(APS, fCtrlPosDiffMax) << ' ' << sizeof aps.fCtrlPosDiffMax << " fCtrlPosDiffMax: " << std::dec << aps.fCtrlPosDiffMax << '\n';
   os << std::hex << offsetof(APS, fCtrlPosDiffMaxTime) << ' ' << sizeof aps.fCtrlPosDiffMaxTime << " fCtrlPosDiffMaxTime: " << std::dec << aps.fCtrlPosDiffMaxTime << '\n';
   os << std::hex << offsetof(APS, fCtrlPosKp) << ' ' << sizeof aps.fCtrlPosKp << " fCtrlPosKp: " << std::dec << aps.fCtrlPosKp << '\n';
   os << std::hex << offsetof(APS, fCtrlPosTn) << ' ' << sizeof aps.fCtrlPosTn << " fCtrlPosTn: " << std::dec << aps.fCtrlPosTn << '\n';
   os << std::hex << offsetof(APS, fCtrlPosTv) << ' ' << sizeof aps.fCtrlPosTv << " fCtrlPosTv: " << std::dec << aps.fCtrlPosTv << '\n';
   os << std::hex << offsetof(APS, fCtrlPosTd) << ' ' << sizeof aps.fCtrlPosTd << " fCtrlPosTd: " << std::dec << aps.fCtrlPosTd << '\n';
   os << std::hex << offsetof(APS, fCtrlPosExtKp) << ' ' << sizeof aps.fCtrlPosExtKp << " fCtrlPosExtKp: " << std::dec << aps.fCtrlPosExtKp << '\n';
   os << std::hex << offsetof(APS, fCtrlPosExtVelo) << ' ' << sizeof aps.fCtrlPosExtVelo << " fCtrlPosExtVelo: " << std::dec << aps.fCtrlPosExtVelo << '\n';
   os << std::hex << offsetof(APS, fCtrlAccKa) << ' ' << sizeof aps.fCtrlAccKa << " fCtrlAccKa: " << std::dec << aps.fCtrlAccKa << '\n';

   os << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
   os << " DRIVE:\n";
   os << std::hex << offsetof(APS, nDriveId) << ' ' << sizeof aps.nDriveId << " nDriveId: " << std::dec << aps.nDriveId << '\n';
   os << std::hex << offsetof(APS, nDriveType) << ' ' << sizeof aps.nDriveType << " nDriveType: " << std::dec << static_cast<unsigned>(aps.nDriveType) << '\n';
   os << std::hex << offsetof(APS, sDriveName) << ' ' << sizeof aps.sDriveName << " sDriveName: " << std::dec << aps.sDriveName << '\n';
   os << std::hex << offsetof(APS, bDriveIsInverse) << ' ' << sizeof aps.bDriveIsInverse << " bDriveIsInverse: " << std::dec << aps.bDriveIsInverse << '\n';
   os << std::hex << offsetof(APS, nDriveControlDWord) << ' ' << sizeof aps.nDriveControlDWord << " nDriveControlDWord: " << std::dec << aps.nDriveControlDWord << '\n';
   os << std::hex << offsetof(APS, fDriveVeloReferenz) << ' ' << sizeof aps.fDriveVeloReferenz << " fDriveVeloReferenz: " << std::dec << aps.fDriveVeloReferenz << '\n';
   os << std::hex << offsetof(APS, fDriveOutputReferenz) << ' ' << sizeof aps.fDriveOutputReferenz << " fDriveOutputReferenz: " << std::dec << aps.fDriveOutputReferenz << '\n';
   os << std::hex << offsetof(APS, fDriveOutputScalingAcc) << ' ' << sizeof aps.fDriveOutputScalingAcc << " fDriveOutputScalingAcc: " << std::dec << aps.fDriveOutputScalingAcc << '\n';
   os << std::hex << offsetof(APS, fDriveOutputScalingTorque) << ' ' << sizeof aps.fDriveOutputScalingTorque << " fDriveOutputScalingTorque: " << std::dec << aps.fDriveOutputScalingTorque << '\n';
   os << std::hex << offsetof(APS, fDriveInputScalingTorque) << ' ' << sizeof aps.fDriveInputScalingTorque << " fDriveInputScalingTorque: " << std::dec << aps.fDriveInputScalingTorque << '\n';
   os << std::hex << offsetof(APS, fDriveInputFiltertimeTorque) << ' ' << sizeof aps.fDriveInputFiltertimeTorque << " fDriveInputFiltertimeTorque: " << std::dec << aps.fDriveInputFiltertimeTorque << '\n';
   os << std::hex << offsetof(APS, fDriveInputFiltertimeTorqueDerivative) << ' ' << sizeof aps.fDriveInputFiltertimeTorqueDerivative << " fDriveInputFiltertimeTorqueDerivative: " << std::dec << aps.fDriveInputFiltertimeTorqueDerivative << '\n';

   os << std::hex << offsetof(APS, fAccelerationMax) << ' ' << sizeof aps.fAccelerationMax << " fAccelerationMax: " << std::dec << aps.fAccelerationMax << '\n';
   os << std::hex << offsetof(APS, fDecelerationMax) << ' ' << sizeof aps.fDecelerationMax << " fDecelerationMax: " << std::dec << aps.fDecelerationMax << '\n';

   os << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
   os << Hexdump(aps.buffer, sizeof aps.buffer) << '\n';
   os << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
   
   return os;
};

int main()
{
   const ads_i32 nTemp = AdsGetDllVersion();
   const AdsVersion* pDLLVersion = reinterpret_cast<const AdsVersion *>(&nTemp);
   std::cout << "Version: " << std::dec << (int)pDLLVersion->version << '\n';
   std::cout << "Revision: " << std::dec << (int)pDLLVersion->revision << '\n';
   std::cout << "Build: " << std::dec << pDLLVersion->build << '\n';

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

