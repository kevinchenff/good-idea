#ifdef  _WINDOWS_SOURCE
#ifdef  __MBDPrdLoadPrtVPMMod
#define ExportedByMBDPrdLoadPrtVPMMod     __declspec(dllexport)
#else
#define ExportedByMBDPrdLoadPrtVPMMod     __declspec(dllimport)
#endif
#else
#define ExportedByMBDPrdLoadPrtVPMMod
#endif
