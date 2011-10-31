#ifdef  _WINDOWS_SOURCE
#ifdef  __MBDTechInfo
#define ExportedByMBDTechInfo     __declspec(dllexport)
#else
#define ExportedByMBDTechInfo     __declspec(dllimport)
#endif
#else
#define ExportedByMBDTechInfo
#endif
