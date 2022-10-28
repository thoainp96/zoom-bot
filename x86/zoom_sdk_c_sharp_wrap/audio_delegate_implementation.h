#pragma once
#include "wrap/sdk_wrap.h"
#include<iostream>
namespace HELPER {
    //public delegate void CallbackRawData(char^ buffer, uint32_t node_id);
    typedef void (*CallbackFunction)(char*, uint32_t);
    class AudioDelegateImplementation sealed : public ZOOM_SDK_NAMESPACE::IZoomSDKAudioRawDataDelegate {
    private:
       
        CallbackFunction m_onOneWayAudioReceived;
    public:
        AudioDelegateImplementation();
        AudioDelegateImplementation(CallbackFunction cb) {
            m_onOneWayAudioReceived = cb;
        }

        ~AudioDelegateImplementation() {

        }
        void Add_CB(CallbackFunction cb) {
            m_onOneWayAudioReceived = cb;
        }

        void onMixedAudioRawDataReceived(AudioRawData* data_) override {

        }

        void onOneWayAudioRawDataReceived(AudioRawData* data_, uint32_t node_id) override {
            std::cout << "callback";
            // Access user-specific raw data here for the user associated with the user.
            if (!data_) return;

            unsigned int audioChannelNumber = data_->GetChannelNum();
            unsigned int audioSampleRate = data_->GetSampleRate();
            unsigned int bufferLength = data_->GetBufferLen();

            char* buffer = data_->GetBuffer();
            std::cout << "callback";
            m_onOneWayAudioReceived(buffer, node_id);
        };
    };
}

