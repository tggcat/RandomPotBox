#ifndef EDNEPLIB_H
#define EDNEPLIB_H

#include <string>
#include <vector>

#ifdef _WIN32
#define EDNEP_API __declspec(dllexport)
#else
#define EDNEP_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define EDNEP_MAX_PROCESSES 64
#define EDNEP_LOG_FILE "ednep_log.txt"

typedef struct {
    const char* processName;
    int restartIfMissing;
    int criticalLevel;
} EDNEP_ProtectedProcess;

EDNEP_API void EDNEP_Init();
EDNEP_API int EDNEP_RegisterProcess(const EDNEP_ProtectedProcess* proc);
EDNEP_API void EDNEP_StartWatchdog();
EDNEP_API void EDNEP_StopWatchdog();
EDNEP_API void EDNEP_Log(const char* message);

EDNEP_API const char* ednep_http_get(const char* url);
EDNEP_API const char* ednep_http_post(const char* url, const char* body, const char* contentType);
EDNEP_API int ednep_discord_send(const char* webhookUrl, const char* message);
EDNEP_API const char* ednep_google_search(const char* apiKey, const char* cx, const char* query);

#ifdef __cplusplus
}
#endif

#endif // EDNEPLIB_H