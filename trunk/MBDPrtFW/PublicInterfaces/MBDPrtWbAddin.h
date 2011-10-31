#ifdef  _WINDOWS_SOURCE
#ifdef  __MBDPrtWbAddin
#define ExportedByMBDPrtWbAddin     __declspec(dllexport)
#else
#define ExportedByMBDPrtWbAddin     __declspec(dllimport)
#endif
#else
#define ExportedByMBDPrtWbAddin
#endif
