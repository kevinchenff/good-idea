#ifdef  _WINDOWS_SOURCE
#ifdef  __MBDPrtAddMaterialMod
#define ExportedByMBDPrtAddMaterialMod     __declspec(dllexport)
#else
#define ExportedByMBDPrtAddMaterialMod     __declspec(dllimport)
#endif
#else
#define ExportedByMBDPrtAddMaterialMod
#endif
