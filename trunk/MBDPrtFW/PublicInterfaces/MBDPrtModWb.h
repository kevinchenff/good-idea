#ifdef  _WINDOWS_SOURCE
#ifdef  __MBDPrtModWb
#define ExportedByMBDPrtModWb     __declspec(dllexport)
#else
#define ExportedByMBDPrtModWb     __declspec(dllimport)
#endif
#else
#define ExportedByMBDPrtModWb
#endif
