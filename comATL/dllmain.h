// dllmain.h: 模块类的声明。

class CcomATLModule : public ATL::CAtlDllModuleT< CcomATLModule >
{
public :
	DECLARE_LIBID(LIBID_comATLLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_COMATL, "{4f36a51d-ba4d-4c4f-a32e-e51c9c45a13b}")
};

extern class CcomATLModule _AtlModule;
