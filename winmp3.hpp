#include <Windows.h>
#include <dshow.h>

#pragma comment(lib, "strmiids.lib")

class winmp3 {
public:
    winmp3() {
        if (FAILED(CoInitializeEx(NULL, COINIT_MULTITHREADED))) {
	    return;
	}
        if (FAILED(CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER, IID_IGraphBuilder, (void**)&p_graph))) return;
        
        p_graph->QueryInterface(IID_IMediaControl, (void**)&p_control);
        p_graph->QueryInterface(IID_IMediaEvent, (void**)&p_event);
        p_graph->QueryInterface(IID_IMediaPosition, (void**)&p_position);
        p_graph->QueryInterface(IID_IBasicAudio, (void**)&p_audio);
    }

    ~winmp3() {
        p_event->Release();
        p_control->Release();
        p_graph->Release();
        CoUninitialize();
    }

    void load_file(const char* mp3_file) {
        WCHAR w_file_name[MAX_PATH];
        MultiByteToWideChar(CP_ACP, 0, mp3_file, -1, w_file_name, MAX_PATH);
        p_graph->RenderFile(w_file_name, NULL);
    }

    void play() {
        p_control->Run();
    }

    void pause() {
        p_control->Pause();
    }

    void stop() {
        p_control->Stop();
    }

    void set_speed(float speed) {
        p_position->put_Rate(speed);
    }

    void set_volume(float volume) {
        long vol = static_cast<long>(volume * 100);
        p_audio->put_Volume(vol);
    }

private:
    IGraphBuilder* p_graph;
    IMediaControl* p_control;
    IMediaEvent* p_event;
    IMediaPosition* p_position;
    IBasicAudio* p_audio;
};
