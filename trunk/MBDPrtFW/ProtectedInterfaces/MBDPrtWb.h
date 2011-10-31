#ifdef  _WINDOWS_SOURCE
#ifdef  __MBDPrtWb
#define ExportedByMBDPrtWb     __declspec(dllexport)
#else
#define ExportedByMBDPrtWb     __declspec(dllimport)
#endif
#else
#define ExportedByMBDPrtWb
#endif

