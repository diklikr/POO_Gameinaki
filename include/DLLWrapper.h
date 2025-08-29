#pragma once
typedef size_t(*WriteCallback)(const char* message);

class DLLWrapper
{
public:
	static int MBError(const wchar_t* message, const wchar_t* boxTitle);
		static int MBWarning(const wchar_t* message, const wchar_t* boxTitle);

		static int httpGet(const char* url, WriteCallback callback);
		
};

