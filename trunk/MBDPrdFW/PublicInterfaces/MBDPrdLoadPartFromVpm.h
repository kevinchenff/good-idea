#ifdef  _WINDOWS_SOURCE
#ifdef  __MBDPrdLoadPartFromVpm
#define ExportedByMBDPrdLoadPartFromVpm     __declspec(dllexport)
#else
#define ExportedByMBDPrdLoadPartFromVpm     __declspec(dllimport)
#endif
#else
#define ExportedByMBDPrdLoadPartFromVpm
#endif
