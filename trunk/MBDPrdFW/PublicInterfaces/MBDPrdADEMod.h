#ifdef  _WINDOWS_SOURCE
#ifdef  __MBDPrdADEMod
#define ExportedByMBDPrdADEMod     __declspec(dllexport)
#else
#define ExportedByMBDPrdADEMod     __declspec(dllimport)
#endif
#else
#define ExportedByMBDPrdADEMod
#endif
