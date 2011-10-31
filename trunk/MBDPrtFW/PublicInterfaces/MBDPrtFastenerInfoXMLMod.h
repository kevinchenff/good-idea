#ifdef  _WINDOWS_SOURCE
#ifdef  __MBDPrtFastenerInfoXMLMod
#define ExportedByMBDPrtFastenerInfoXMLMod     __declspec(dllexport)
#else
#define ExportedByMBDPrtFastenerInfoXMLMod     __declspec(dllimport)
#endif
#else
#define ExportedByMBDPrtFastenerInfoXMLMod
#endif
