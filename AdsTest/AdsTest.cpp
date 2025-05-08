// test ADS communication to TwinCAT 3 NC PTP system

#include <iostream>
#include <TcAdsApi.h>
#include "ST_AxisParameterSet.h"

int main()
{
   const ads_i32 nTemp = AdsGetDllVersion();
   const AdsVersion* pDLLVersion = reinterpret_cast<const AdsVersion *>(&nTemp);
   std::cout << "Version: " << (int)pDLLVersion->version << '\n';
   std::cout << "Revision: " << (int)pDLLVersion->revision << '\n';
   std::cout << "Build: " << pDLLVersion->build << '\n';

   const long nPort = AdsPortOpen();
   AmsAddr addr;
   long nErr = AdsGetLocalAddress(&addr);
   if (nErr)
   {
      std::cerr << "AdsGetLocalAddress: " << nErr << '\n';
      AdsPortClose();
      return 1;
   }
   addr.port = 500; // NC
   const int axisId = 1;
   ads_i32 axisIdRead;
   nErr = AdsSyncReadReq(&addr, 0x4000 + axisId, 0x00000001, sizeof axisIdRead, &axisIdRead);
   if (nErr) std::cerr << "AdsSyncReadReq failed " << nErr << '\n';
   else std::cout << "axis ID read " << axisIdRead << '\n';

   TwinCAT3::ST_AxisParameterSet axisParameterSet;
   nErr = AdsSyncReadReq(&addr, 0x4000 + axisId, axisId * 0x100000, sizeof axisParameterSet, &axisParameterSet);
   if (nErr) std::cerr << "AdsSyncReadReq(ST_AxisParameterSet) failed " << nErr << '\n';

   AdsPortClose();
   return 0;
}

