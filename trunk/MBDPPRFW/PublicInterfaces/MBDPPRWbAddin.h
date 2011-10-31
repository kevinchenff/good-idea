#ifdef  _WINDOWS_SOURCE
#ifdef  __MBDPPRWbAddin
#define ExportedByMBDPPRWbAddin     __declspec(dllexport)
#else
#define ExportedByMBDPPRWbAddin     __declspec(dllimport)
#endif
#else
#define ExportedByMBDPPRWbAddin
#endif
