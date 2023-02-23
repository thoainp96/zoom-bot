#pragma once
using namespace System;
#include "zoom_sdk_dotnet_wrap_def.h"
namespace ZOOM_SDK_DOTNET_WRAP {

	public enum class VideoStatus : int
	{
		Video_ON,
		Video_OFF,
	};

	public delegate void onUserVideoStatusChange(unsigned int userId, VideoStatus status);
	public delegate void onSpotlightVideoChangeNotification(array<unsigned int>^ lstSpotlightedUserID);
	public delegate void onActiveSpeakerVideoUserChanged(unsigned int userId);
	public interface class IMeetingVideoControllerDotNetWrap
	{
	public:
		SDKError MuteVideo();
		SDKError UnmuteVideo();
		
		SDKError PinVideoToFirstView(unsigned int userid);
		SDKError UnPinVideoFromFirstView(unsigned int userid);
		SDKError SpotlightVideo(unsigned int userid);
		SDKError UnSpotlightVideo(unsigned int userid);
		SDKError HideOrShowNoVideoUserOnVideoWall(bool bHide);
		SDKError AskAttendeeToStartVideo(unsigned int userid);

		void Add_CB_onUserVideoStatusChange(onUserVideoStatusChange^ cb);
		void Add_CB_onSpotlightVideoChangeNotification(onSpotlightVideoChangeNotification^ cb);
		void Add_CB_onActiveSpeakerVideoUserChanged(onActiveSpeakerVideoUserChanged^ cb);
		void Remove_CB_onUserVideoStatusChange(onUserVideoStatusChange^ cb);
		void Remove_CB_onSpotlightVideoChangeNotification(onSpotlightVideoChangeNotification^ cb);
		void Remove_CB_onActiveSpeakerVideoUserChanged(onActiveSpeakerVideoUserChanged^ cb);
	};

	private ref class CMeetingVideoControllerDotNetWrap sealed : public IMeetingVideoControllerDotNetWrap
	{
	public:
		static property CMeetingVideoControllerDotNetWrap^ Instance
		{
			CMeetingVideoControllerDotNetWrap^ get() { return m_Instance; }
		}

		void BindEvent();

		virtual SDKError MuteVideo();
		virtual SDKError UnmuteVideo();
		
		virtual SDKError PinVideoToFirstView(unsigned int userid);
		virtual SDKError UnPinVideoFromFirstView(unsigned int userid);
		virtual SDKError SpotlightVideo(unsigned int userid);
		virtual SDKError UnSpotlightVideo(unsigned int userid);
		virtual SDKError HideOrShowNoVideoUserOnVideoWall(bool bHide);
		virtual SDKError AskAttendeeToStartVideo(unsigned int userid);

		virtual void Add_CB_onUserVideoStatusChange(onUserVideoStatusChange^ cb)
		{
			event_onUserVideoStatusChange += cb;
		}

		virtual void Remove_CB_onUserVideoStatusChange(onUserVideoStatusChange^ cb)
		{
			event_onUserVideoStatusChange -= cb;
		}

		virtual void Add_CB_onSpotlightVideoChangeNotification(onSpotlightVideoChangeNotification^ cb)
		{
			event_onSpotlightVideoChangeNotification += cb;
		}

		virtual void Remove_CB_onSpotlightVideoChangeNotification(onSpotlightVideoChangeNotification^ cb)
		{
			event_onSpotlightVideoChangeNotification -= cb;
		}

		virtual void Add_CB_onActiveSpeakerVideoUserChanged(onActiveSpeakerVideoUserChanged^ cb)
		{
			event_onActiveSpeakerVideoUserChanged += cb;
		}

		virtual void Remove_CB_onActiveSpeakerVideoUserChanged(onActiveSpeakerVideoUserChanged^ cb)
		{
			event_onActiveSpeakerVideoUserChanged -= cb;
		}

		void ProcUserVideoStatusChange(unsigned int userId, VideoStatus status);
		void ProcSpotlightedUserListChangeNotification(array<unsigned int>^ lstSpotlightedUserID);
		void ProcOnActiveSpeakerVideoUserChanged(unsigned int userId);

	private:
		event onUserVideoStatusChange^ event_onUserVideoStatusChange;
		event onSpotlightVideoChangeNotification^ event_onSpotlightVideoChangeNotification;
		event onActiveSpeakerVideoUserChanged^ event_onActiveSpeakerVideoUserChanged;
		static CMeetingVideoControllerDotNetWrap^ m_Instance = gcnew CMeetingVideoControllerDotNetWrap;
	};
}