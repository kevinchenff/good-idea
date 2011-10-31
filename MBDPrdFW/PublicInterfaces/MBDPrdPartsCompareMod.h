#ifdef  _WINDOWS_SOURCE
#ifdef  __MBDPrdPartsCompareMod
#define ExportedByMBDPrdPartsCompareMod     __declspec(dllexport)
#else
#define ExportedByMBDPrdPartsCompareMod     __declspec(dllimport)
#endif
#else
#define ExportedByMBDPrdPartsCompareMod
#endif
