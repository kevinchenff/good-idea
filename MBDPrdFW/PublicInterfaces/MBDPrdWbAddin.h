#ifdef  _WINDOWS_SOURCE
#ifdef  __MBDPrdWbAddin
#define ExportedByMBDPrdWbAddin     __declspec(dllexport)
#else
#define ExportedByMBDPrdWbAddin     __declspec(dllimport)
#endif
#else
#define ExportedByMBDPrdWbAddin
#endif
