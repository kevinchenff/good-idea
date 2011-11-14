#ifdef  _WINDOWS_SOURCE
#ifdef  __MBDPrtFstDesignMod
#define ExportedByMBDPrtFstDesignMod     __declspec(dllexport)
#else
#define ExportedByMBDPrtFstDesignMod     __declspec(dllimport)
#endif
#else
#define ExportedByMBDPrtFstDesignMod
#endif
