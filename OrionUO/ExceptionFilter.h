
#pragma once

#if defined(ORION_WINDOWS)

LONG __stdcall OrionUnhandledExceptionFilter(struct _EXCEPTION_POINTERS *ExceptionInfo);

#endif
