//#define DllExport   __declspec( dllexport )
#include "stdafx.h"
#include "raw_audio_service_dotnet_wrap.h"
#include "zoom_sdk_dotnet_wrap_util.h"
namespace ZOOM_SDK_DOTNET_WRAP {
	CRawAudioServiceDotNetWrap::CRawAudioServiceDotNetWrap()
	{

	}
	CRawAudioServiceDotNetWrap::~CRawAudioServiceDotNetWrap()
	{

	}
	void CRawAudioServiceDotNetWrap::SendCallback(char* buffer, uint32_t node_id) {
		//event_onCallbackRawData(*buffer, node_id);
	
	}
	void  CRawAudioServiceDotNetWrap::SetUpAudioStream(CallbackRawData^ cb) {
		//event_onCallbackRawData += cb;
		HELPER::CallbackFunction callbackPtr = (HELPER::CallbackFunction)System::Runtime::InteropServices::Marshal::GetFunctionPointerForDelegate(cb).ToPointer();
		//HELPER::CallbackFunction test = callbackPtr.To
		//CallbackRawDataTemp^ fp = gcnew CallbackRawDataTemp(SendCallback);
		cb('1', 2);
		ZOOM_SDK_NAMESPACE::IZoomSDKAudioRawDataHelperWrap& pAudioHelper = ZOOM_SDK_NAMESPACE::CSDKWrap::GetInst().GetAudioRawdataHelperWrap();
		HELPER::AudioDelegateImplementation* delegateObj = new HELPER::AudioDelegateImplementation(callbackPtr);
		pAudioHelper.subscribe(delegateObj);
	}
}

