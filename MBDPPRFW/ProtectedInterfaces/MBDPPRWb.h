#ifdef  _WINDOWS_SOURCE
#ifdef  __MBDPPRWb
#define ExportedByMBDPPRWb     __declspec(dllexport)
#else
#define ExportedByMBDPPRWb     __declspec(dllimport)
#endif
#else
#define ExportedByMBDPPRWb
#endif
