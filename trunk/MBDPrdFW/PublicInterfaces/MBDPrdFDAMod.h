#ifdef  _WINDOWS_SOURCE
#ifdef  __MBDPrdFDAMod
#define ExportedByMBDPrdFDAMod     __declspec(dllexport)
#else
#define ExportedByMBDPrdFDAMod     __declspec(dllimport)
#endif
#else
#define ExportedByMBDPrdFDAMod
#endif
