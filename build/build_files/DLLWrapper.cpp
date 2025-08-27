#include "DLLWrapper.h"
#include "MyLibrary.h"

int DLLWrapper::MBError(const wchar_t* message, const wchar_t* boxTitle)
{
	return MyMessageBoxError(message, boxTitle);
}

int DLLWrapper::MBWarning(const wchar_t* message, const wchar_t* boxTitle)
{
	return MyMessageBoxWarning(message, boxTitle);
}