// TestHttp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include <Windows.h>
#include "winhttp.h"
using namespace std;
#pragma comment(lib,"Winhttp.lib")

static void MultiByteToWideString(std::wstring& ascString, const char* URL)
{
	size_t size = MultiByteToWideChar(CP_OEMCP, 0, URL, strlen(URL) + 1, NULL, 0);
	ascString.resize(size + 1);
	MultiByteToWideChar(CP_OEMCP, 0, URL, strlen(URL) + 1, &ascString[0], size);
	ascString[size] = L'\0';

}

int main()
{
	//char* url = "http://10.253.114.241:7763/TILE_3D_MODEL/shenzhen/tileset.json";
	char* url = "http://10.253.114.241:8842/TILE_3D_MODEL/shenzhen/top/0_-1_-1_0.json";
	//char* url = "http://10.253.114.241:7763/TILE_3D_MODEL/shenzhen/top/Tile_-174_-062/Tile_-174_-062_L18_000000t3.json";
	//char* url = "http://10.253.114.241:7763/TILE_3D_MODEL/shenzhen/Tile_-159_-050/Tile_-159_-050_L18_000000t3.json";
	//char* url = "http://10.253.114.241:7763/TILE_3D_MODEL/shenzhen/Tile_-135_-041/Tile_-135_-041_L17_00000t1.json";
	//char* url = "http://10.253.114.241:7763/TILE_3D_MODEL/shenzhen/Tile_-183_-061/Tile_-183_-061_L18_000000t3.b3dm";
	bool use_proxy_mode = false;
	WINHTTP_CURRENT_USER_IE_PROXY_CONFIG proxy_config = { 0 };
	if (WinHttpGetIEProxyConfigForCurrentUser(&proxy_config))
	{
		if (proxy_config.lpszProxy != NULL)
		{
			use_proxy_mode = true;
		}
	}

	URL_COMPONENTS url_components;
	memset(&url_components, 0, sizeof(URL_COMPONENTS));

	url_components.dwStructSize = sizeof(URL_COMPONENTS);
	url_components.dwSchemeLength = (DWORD)-1;
	url_components.dwHostNameLength = (DWORD)-1;
	url_components.dwUrlPathLength = (DWORD)-1;
	url_components.dwExtraInfoLength = (DWORD)-1;

	HINTERNET hSession = INVALID_HANDLE_VALUE;
	HINTERNET hConnection = INVALID_HANDLE_VALUE;
	HINTERNET hRequest = INVALID_HANDLE_VALUE;
	std::string mutiheaderstr;
	std::wstring ascwidestringurl;

	MultiByteToWideString(ascwidestringurl, url);
	if (WinHttpCrackUrl(ascwidestringurl.c_str(), ascwidestringurl.length(), 0, &url_components) == FALSE)
	{
		int  err_state_no = GetLastError();
		return 0;
	}

	if (use_proxy_mode)
	{
		hSession = WinHttpOpen(L"HttpDBManager/2.0"
			, WINHTTP_ACCESS_TYPE_NAMED_PROXY
			, proxy_config.lpszProxy
			, proxy_config.lpszProxyBypass, 0);

		if (proxy_config.lpszAutoConfigUrl != NULL)
		{
			GlobalFree(proxy_config.lpszAutoConfigUrl);
		}
		if (proxy_config.lpszProxy != NULL)
		{
			GlobalFree(proxy_config.lpszProxy);
		}
		if (proxy_config.lpszProxyBypass != NULL)
		{
			GlobalFree(proxy_config.lpszProxyBypass);
		}
	}
	else
	{
		hSession = WinHttpOpen(L"HttpWraper", WINHTTP_ACCESS_TYPE_NO_PROXY,
			WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
		if (0 == hSession)
		{
			return 0;
		}
	}

	std::wstring hostName;
	hostName.resize(url_components.dwHostNameLength);
	memcpy(&hostName[0], &url_components.lpszHostName[0], url_components.dwHostNameLength * 2);
	hConnection = WinHttpConnect(hSession, hostName.c_str(), url_components.nPort, 0);
	if (0 == hConnection)
	{
		CloseHandle(hSession);
		return 0;
	}

	DWORD requestFlags = WINHTTP_FLAG_ESCAPE_PERCENT;
	if (strncmp(url, "https:", 6) == 0)
	{
		requestFlags |= WINHTTP_FLAG_SECURE;
	}
	hRequest = WinHttpOpenRequest(hConnection, L"GET", url_components.lpszUrlPath, NULL,
		WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, requestFlags);
	if (!hRequest)
	{
		CloseHandle(hConnection);
		CloseHandle(hSession);
		return 0;
	}
	
	const wchar_t* cookierequestheader = L"szvsud-license-key:PdOyCebn0NwnwqczjtyMl+Jo3AT9nYGaqCpKQd5Si1j8gQHLDQYBbw==";
	//const wchar_t* cookierequestheader = L"szvsud-license-key:XsMFAOQQLtvW7sny7/f1/dxET9WY2Vdd9L3r+zGCJZkshjybcGtFrg==";
	WinHttpAddRequestHeaders(hRequest, cookierequestheader, wcslen(cookierequestheader), WINHTTP_ADDREQ_FLAG_ADD);

	const wchar_t* sm3requestheader = L"Content-Type: deepeye/sm3";
	WinHttpAddRequestHeaders(hRequest, sm3requestheader, wcslen(sm3requestheader), WINHTTP_ADDREQ_FLAG_ADD);

	const wchar_t* gzibrequestheader = L"accept-encoding: gzip, deflate, br";
	WinHttpAddRequestHeaders(hRequest, gzibrequestheader, wcslen(gzibrequestheader), WINHTTP_ADDREQ_FLAG_ADD);


	bool sucess = WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0);
	if (!sucess)
	{
		int  err_state_no = GetLastError();
		cout << "发送请求失败！错误码：" << err_state_no << endl;
	}
	cout << "发送请求成功！"  << endl;
	if (!WinHttpReceiveResponse(hRequest, 0))
	{
		int  err_state_no = GetLastError();
		cout << "接收响应失败！错误码：" << err_state_no << endl;
	}
	cout << "接收响应成功！" << endl;

	DWORD totalheadsize = 0;
	wchar_t* headercontent = 0;
	WinHttpQueryHeaders(hRequest, WINHTTP_QUERY_STATUS_CODE, WINHTTP_HEADER_NAME_BY_INDEX, 0, &totalheadsize, WINHTTP_NO_HEADER_INDEX);
	if (ERROR_INSUFFICIENT_BUFFER == GetLastError())
	{
		headercontent = new wchar_t[totalheadsize / sizeof(wchar_t)];
		WinHttpQueryHeaders(hRequest, WINHTTP_QUERY_STATUS_CODE, WINHTTP_HEADER_NAME_BY_INDEX, headercontent, &totalheadsize, WINHTTP_NO_HEADER_INDEX);
	}
	cout << "WinHttpQueryHeaders::WINHTTP_QUERY_STATUS_CODE::totalheadsize->" <<totalheadsize<< endl;

	cout << "WinHttpQueryHeaders::WINHTTP_QUERY_STATUS_CODE::headercontent->" <<headercontent<< endl;
	if (wcscmp(headercontent, L"200") != 0)
	{
		
		delete[] headercontent;
		headercontent = 0;
	}
	

	bool dynamicload = false;
	delete[] headercontent;
	headercontent = 0;
	//查询内容长度
	totalheadsize = 0;
	int datasize = 0;
	WinHttpQueryHeaders(hRequest, WINHTTP_QUERY_CONTENT_LENGTH, WINHTTP_HEADER_NAME_BY_INDEX, 0, &totalheadsize, WINHTTP_NO_HEADER_INDEX);
	if (ERROR_INSUFFICIENT_BUFFER == GetLastError())
	{
		if (totalheadsize == 0)
		{
			cout << "WinHttpQueryHeaders::WINHTTP_QUERY_CONTENT_LENGTH::totalheadsize::0" << endl;
			return 0;
		}
		headercontent = new wchar_t[totalheadsize / sizeof(wchar_t)];
		WinHttpQueryHeaders(hRequest, WINHTTP_QUERY_CONTENT_LENGTH, WINHTTP_HEADER_NAME_BY_INDEX, headercontent, &totalheadsize, WINHTTP_NO_HEADER_INDEX);

		int mutisize = ::WideCharToMultiByte(0, 0, headercontent, totalheadsize / sizeof(wchar_t), 0, 0, 0, 0);
		if (mutisize == 0)
		{
			cout << "WinHttpQueryHeaders::WINHTTP_QUERY_CONTENT_LENGTH::headercontent::0" << endl;
			goto Err;
		}

		mutiheaderstr.resize(mutisize);
		::WideCharToMultiByte(0, 0, headercontent, totalheadsize / sizeof(wchar_t), &mutiheaderstr[0], mutisize, 0, 0);
		datasize = atoi(mutiheaderstr.c_str());
		delete[] headercontent;
		headercontent = 0;
	}
	else
	{
		if (headercontent != 0)
		{
			delete[] headercontent;
			headercontent = 0;
		}
		dynamicload = true;

	}

	bool isgzip = false;
	WinHttpQueryHeaders(hRequest, WINHTTP_QUERY_CONTENT_ENCODING, WINHTTP_HEADER_NAME_BY_INDEX, 0, &totalheadsize, WINHTTP_NO_HEADER_INDEX);
	if (ERROR_INSUFFICIENT_BUFFER == GetLastError())
	{
		if (totalheadsize == 0)
		{
			cout << "WinHttpQueryHeaders::WINHTTP_QUERY_CONTENT_ENCODING::totalheadsize::0" << endl;
			goto Err;
		}

		headercontent = new wchar_t[totalheadsize / sizeof(wchar_t)];
		WinHttpQueryHeaders(hRequest, WINHTTP_QUERY_CONTENT_ENCODING, WINHTTP_HEADER_NAME_BY_INDEX, headercontent, &totalheadsize, WINHTTP_NO_HEADER_INDEX);

		for (int i = 0; i < totalheadsize / sizeof(wchar_t); ++i)
		{
			headercontent[i] = towlower(headercontent[i]);
		}

		if (wcscmp(headercontent, L"gzip") == 0)
		{
			isgzip = true;
		}
		delete[] headercontent;
		headercontent = 0;
	}

	sucess = WinHttpQueryDataAvailable(hRequest, 0);
	if (!sucess)
	{
		cout << "WinHttpQueryDataAvailable执行失败！" << endl;
		goto Err;
	}

	cout << "dynamicload::" << dynamicload<<endl;

	DWORD buffersize = 4;
	DWORD maxresponesedrainbuffersize = 0;
	if (!WinHttpQueryOption(hRequest, WINHTTP_OPTION_MAX_RESPONSE_DRAIN_SIZE,
		&maxresponesedrainbuffersize, &buffersize))
	{
		cout << "WinHttpQueryOption::WINHTTP_OPTION_MAX_RESPONSE_DRAIN_SIZE 失败！" << endl;
		goto Err;
	}
	DWORD readsize;
	cout << "datasize::" << datasize << endl;

	/*Blob* blob = 0;
	blob = Blob::Create(datasize);*/
	//char* buffer = (char*)blob->GetPointer();
	char* buffer = new char[datasize+1];
	if (datasize < maxresponesedrainbuffersize)
	{
		sucess = WinHttpReadData(hRequest, buffer, datasize, &readsize);
		if (sucess && datasize == readsize)
		{
			cout << "245 WinHttpReadData执行成功！" << endl;
			cout << "isgzip：" <<isgzip<< endl;
			if (buffer == NULL || buffer == " ")
			{
				buffer = "没有值！";
			}
			cout << buffer << endl;
			WinHttpCloseHandle(hRequest);
			WinHttpCloseHandle(hConnection);
			WinHttpCloseHandle(hSession);
			//return IsGzip(blob, isgzip);
		}
		else
		{
			//blob->Release();
			cout << "245 WinHttpReadData执行失败！" << endl;
			goto Err;
		}
	}
	else
	{
		int leavesize = datasize;
		do
		{
			sucess = WinHttpReadData(hRequest, buffer, maxresponesedrainbuffersize, &readsize);
			buffer += readsize;
			leavesize = leavesize - readsize;
		} while (sucess && leavesize > 0);

		if (sucess && leavesize == 0)
		{
			cout << "266 WinHttpReadData执行成功！" << endl;

			WinHttpCloseHandle(hRequest);
			WinHttpCloseHandle(hConnection);
			WinHttpCloseHandle(hSession);
			//return IsGzip(blob, isgzip);
		}
		else
		{
			cout << "266 WinHttpReadData执行失败！" << endl;
			//blob->Release();
			goto Err;
		}
	}

Err:
	system("pause");

	system("pause");
    return 0;
}

