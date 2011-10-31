#ifdef  _WINDOWS_SOURCE
#ifdef  __MBDPrdWb
#define ExportedByMBDPrdWb     __declspec(dllexport)
#else
#define ExportedByMBDPrdWb     __declspec(dllimport)
#endif
#else
#define ExportedByMBDPrdWb
#endif
