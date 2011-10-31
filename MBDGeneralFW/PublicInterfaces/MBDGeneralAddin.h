#ifdef  _WINDOWS_SOURCE
#ifdef  __MBDGeneralAddin
#define ExportedByMBDGeneralAddin     __declspec(dllexport)
#else
#define ExportedByMBDGeneralAddin     __declspec(dllimport)
#endif
#else
#define ExportedByMBDGeneralAddin
#endif
