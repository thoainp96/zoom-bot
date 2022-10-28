#pragma once
#include "zoom_sdk_dotnet_wrap_def.h"
#include "wrap/sdk_wrap.h"
#include "audio_delegate_implementation.h"
using namespace System;
using namespace System::Windows;
namespace ZOOM_SDK_DOTNET_WRAP {
	public delegate void CallbackRawData(char^, uint32_t);
	public interface class IRawAudioServiceDotNetWrap
	{
	public:
		void SetUpAudioStream(CallbackRawData ^cb);
	};
	private ref class CRawAudioServiceDotNetWrap sealed : public IRawAudioServiceDotNetWrap
	{
	

	public:
		static property CRawAudioServiceDotNetWrap^ Instance
		{
			CRawAudioServiceDotNetWrap^ get() { return m_Instance; }
		}
		virtual void SetUpAudioStream(CallbackRawData^ cb);
		

	private:
		CRawAudioServiceDotNetWrap();
		virtual ~CRawAudioServiceDotNetWrap();
		void SendCallback(char* buffer, uint32_t node_id);

		static CRawAudioServiceDotNetWrap^ m_Instance = gcnew CRawAudioServiceDotNetWrap;
		//void* SendCallback(char* buffer, uint32_t node_id);
		//void Test(HELPER::CallbackFunction cb);
	};
}

