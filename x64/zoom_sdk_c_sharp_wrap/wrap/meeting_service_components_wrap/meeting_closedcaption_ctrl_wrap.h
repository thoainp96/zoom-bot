#pragma once
#include "common_include.h"
BEGIN_ZOOM_SDK_NAMESPACE
class IMeetingServiceWrap;
IClosedCaptionController* InitIClosedCaptionControllerFunc(IClosedCaptionControllerEvent* pEvent, IMeetingServiceWrap* pOwner);
void UninitIClosedCaptionControllerFunc(IClosedCaptionController* obj);
BEGIN_CLASS_DEFINE_WITHCALLBACK(IClosedCaptionController, IClosedCaptionControllerEvent)
NORMAL_CLASS(IClosedCaptionController)
INIT_UNINIT_WITHEVENT_AND_OWNSERVICE(IClosedCaptionController, IMeetingServiceWrap)
virtual SDKError SetEvent(IClosedCaptionControllerEvent* pEvent)
{
	external_cb = pEvent;
	return SDKERR_SUCCESS;
}

//virtual bool IsMeetingSupportCC() = 0;
DEFINE_FUNC_0(IsMeetingSupportCC, bool)
//virtual bool CanAssignOthersToSendCC() = 0;
DEFINE_FUNC_0(CanAssignOthersToSendCC, bool)
//virtual SDKError AssignCCPriviledge(unsigned int userid, bool bAssigned) = 0;
DEFINE_FUNC_2(AssignCCPriviledge, SDKError, unsigned int, userid, bool, bAssigned)
//virtual bool CanBeAssignedToSendCC(unsigned int userid) = 0;
DEFINE_FUNC_1(CanBeAssignedToSendCC, bool, unsigned int, userid)
//virtual bool CanSendClosedCaption() = 0;
DEFINE_FUNC_0(CanSendClosedCaption, bool)
//virtual SDKError SendClosedCaption(const wchar_t* ccMsg) = 0;
DEFINE_FUNC_1(SendClosedCaption, SDKError, const wchar_t*, ccMsg)
//virtual bool IsSaveCCEnabled() = 0;
DEFINE_FUNC_0(IsSaveCCEnabled, bool)
//virtual SDKError SaveCCHistory() = 0;
DEFINE_FUNC_0(SaveCCHistory, SDKError)
//virtual const wchar_t* GetClosedCaptionHistorySavedPath() = 0;
DEFINE_FUNC_0(GetClosedCaptionHistorySavedPath, const wchar_t*)
//virtual const wchar_t* GetClosedCaptionUrlFor3rdParty() = 0;
DEFINE_FUNC_0(GetClosedCaptionUrlFor3rdParty, const wchar_t*)
//virtual bool IsLiveTranscriptLegalNoticeAvailable() = 0;
DEFINE_FUNC_0(IsLiveTranscriptLegalNoticeAvailable, bool)
//virtual const wchar_t* getLiveTranscriptChatLegalNoticesPrompt() = 0;
DEFINE_FUNC_0(getLiveTranscriptLegalNoticesPrompt, const wchar_t*)
//virtual const wchar_t* getLiveTranscriptLegalNoticesExplained() = 0;
DEFINE_FUNC_0(getLiveTranscriptLegalNoticesExplained, const wchar_t*)
//virtual bool IsLiveTranscriptionFeatureEnabled() = 0;
DEFINE_FUNC_0(IsLiveTranscriptionFeatureEnabled, bool)
//virtual SDKLiveTranscriptionStatus GetLiveTranscriptionStatus() = 0;
DEFINE_FUNC_0(GetLiveTranscriptionStatus, SDKLiveTranscriptionStatus)
//virtual bool CanStartLiveTranscription() = 0;
DEFINE_FUNC_0(CanStartLiveTranscription, bool)
//virtual SDKError StartLiveTranscription() = 0;
DEFINE_FUNC_0(StartLiveTranscription, SDKError)
//virtual SDKError StopLiveTranscription() = 0;
DEFINE_FUNC_0(StopLiveTranscription, SDKError)
//virtual SDKError EnableRequestLiveTranscription(bool bEnable) = 0;
DEFINE_FUNC_1(EnableRequestLiveTranscription, SDKError, bool, bEnable)
//virtual bool IsRequestToStartLiveTranscriptionEnalbed() = 0;
DEFINE_FUNC_0(IsRequestToStartLiveTranscriptionEnalbed, bool)
//virtual SDKError RequestToStartLiveTranscription(bool bRequestAnonymous) = 0;
DEFINE_FUNC_1(RequestToStartLiveTranscription, SDKError, bool, bRequestAnonymous)

//virtual void onAssignedToSendCC(bool bAssigned) = 0;
CallBack_FUNC_1(onAssignedToSendCC, bool, bAssigned)
//virtual void onClosedCaptionMsgReceived(const wchar_t* ccMsg, unsigned int sender_id, time_t time) = 0;
CallBack_FUNC_3(onClosedCaptionMsgReceived, const wchar_t*, ccMsg, unsigned int, sender_id, time_t, time)
//virtual void onLiveTranscriptionStatus(SDKLiveTranscriptionStatus status) = 0;
CallBack_FUNC_1(onLiveTranscriptionStatus, SDKLiveTranscriptionStatus, status)
//virtual void onLiveTranscriptionMsgReceived(const wchar_t* ltMsg, unsigned int speark_id, SDKLiveTranscriptionOperationType type) = 0;
CallBack_FUNC_3(onLiveTranscriptionMsgReceived, const wchar_t*, ltMsg, unsigned int, speark_id, SDKLiveTranscriptionOperationType, type)
//virtual void onRequestForLiveTranscriptReceived(unsigned int requester_id, bool bAnonymous) = 0;
CallBack_FUNC_2(onRequestForLiveTranscriptReceived, unsigned int, requester_id, bool, bAnonymous)
//virtual void onRequestLiveTranscriptionStatusChange(bool bEnabled) = 0;
CallBack_FUNC_1(onRequestLiveTranscriptionStatusChange, bool, bEnabled)
//virtual void onLiveTranscriptionMsgError(ILiveTranscriptionLanguage* speakLanguage, ILiveTranscriptionLanguage* transcriptLanguage) = 0;
CallBack_FUNC_2(onLiveTranscriptionMsgError, ILiveTranscriptionLanguage*, speakLanguage, ILiveTranscriptionLanguage*, transcriptLanguage)
END_CLASS_DEFINE(IClosedCaptionController)
END_ZOOM_SDK_NAMESPACE