#include "pch.h"
#include "MyLibrary.h"


MYLIBRARY_API void HelloWorld()
{
	std::cout << "hola mundo desde la DLL" << std::endl;
}

MYLIBRARY_API int MyMessageBoxError(const wchar_t* message, const wchar_t * boxTitle)
{
	return MessageBoxW(NULL, message, boxTitle, MB_ICONERROR);
}

MYLIBRARY_API int MyMessageBoxWarning(const wchar_t* message, const wchar_t * boxTitle)
{
	return MessageBoxW(NULL, message, boxTitle, MB_ICONEXCLAMATION);
}

MYLIBRARY_API int HTTPGet(const char* url, WriteCallback callback)
{
	CURL* curl;
	CURLcode res;

	curl = curl_easy_init();

	if (curl)
	{
		std::string response;
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT)
	}
}

size_t writefunction(void* ptr, size_t size, size_t nmemb, void* userdata)
{
	size_t totalSize = size + nmemb;

	std::cout <<"recibidos" << totalSize << "bytes"

}
size_t writefunction(void* ptr, size_t size, size_t nmemb, void* userdata)
{
	size_t totalSize = size + nmemb;
	if (userCallback)
	{
		userCallback("hola desde la dll :D");
	}
	std::cout << "recibidos" << totalSize << "bytes" << std::endl;
	return totalSize;
}