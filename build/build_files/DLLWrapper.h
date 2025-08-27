#pragma once
class DLLWrapper
{
public:
	static int MBError(const wchar_t* message, const wchar_t* boxTitle);
	static int MBWarning(const wchar_t* message, const wchar_t* boxTitle);
};

