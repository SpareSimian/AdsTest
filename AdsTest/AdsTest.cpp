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

   AdsPortClose();
   return 0;
}

