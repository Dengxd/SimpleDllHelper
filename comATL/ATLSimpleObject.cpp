// ATLSimpleObject.cpp: CATLSimpleObject 的实现

#include "pch.h"
#include "ATLSimpleObject.h"


// CATLSimpleObject



STDMETHODIMP CATLSimpleObject::atlsum(LONG a, LONG b, LONG* c)
{
    // TODO: 在此处添加实现代码
	HINSTANCE hinstLib;
	hinstLib = LoadLibrary(TEXT("c:\\TestDll.dll"));
	if (hinstLib != NULL)
	{
		typedef int(__stdcall* SUM)(int, int);
		SUM sum;
		sum = (SUM)GetProcAddress(hinstLib, "sum"); //这是获取dll里面的sum函数

		if (NULL != sum)
		{
			int ret = sum(a, b);  //调用dll的sum函数
			* c = ret;  //设置返回值
		}
		FreeLibrary(hinstLib);
	}
    return S_OK;
}
