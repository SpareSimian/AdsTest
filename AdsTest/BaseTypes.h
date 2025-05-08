#pragma once
   
#include <cstdint>

namespace TwinCAT3 {

// these base types make it easier to import and edit structures from PLC documentation

typedef uint32_t DWORD;
typedef char STRING; // STRING types are null-terminated so we need to add a byte when importing
typedef float REAL; // 4-byte
typedef double LREAL; // 8-byte
typedef uint16_t WORD;
typedef uint16_t UINT;
typedef uint32_t UDINT;

typedef char T_AmsNetId[1 + 23];

// https://infosys.beckhoff.com/english.php?content=../content/1033/tcplclib_tc2_mc2/12929722635.html&id=

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

// https://infosys.beckhoff.com/english.php?content=../content/1033/tcplclib_tc2_mc2/12930870795.html&id=

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

// https://infosys.beckhoff.com/english.php?content=../content/1033/tcplclib_tc2_mc2/12929727371.html&id=

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

} // namespace
