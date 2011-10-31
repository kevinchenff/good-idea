#ifdef  _WINDOWS_SOURCE
#ifdef  __MBDPrtAnnotateXMLMod
#define ExportedByMBDPrtAnnotateXMLMod     __declspec(dllexport)
#else
#define ExportedByMBDPrtAnnotateXMLMod     __declspec(dllimport)
#endif
#else
#define ExportedByMBDPrtAnnotateXMLMod
#endif
