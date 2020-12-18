#include "Stopwatch.h"
#include <lvgl/lvgl.h>
#include <chrono>
#include <cstdint>
#include <cstdio>

using namespace Pinetime::Applications::Screens;

extern lv_style_t* LabelBigStyle;

Stopwatch::Stopwatch(Pinetime::Applications::DisplayApp *app) : Screen(app){
    label_time = lv_label_create(lv_scr_act(), nullptr);
    //lv_label_set_style(label_time, LV_LABEL_STYLE_MAIN, LabelBigStyle);
    lv_label_set_text(label_time, "TIME");
    lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);
}

Stopwatch::~Stopwatch() {
    lv_obj_clean(lv_scr_act());
}

bool Stopwatch::Refresh() {
    return running;
}

bool Stopwatch::OnButtonPushed() {
  running = false;
  return true;
}

bool Stopwatch::OnTouchEvent(Pinetime::Applications::TouchEvents event) {
  switch(event) {
    case TouchEvents::SwipeLeft:
        // go to next tab
        return true;
    case TouchEvents::SwipeRight:
        // go to next tab
        return true;
    case TouchEvents::SwipeDown:
        restartTimer();
        return true;
    case TouchEvents::Tap:
        // get tap
        if (countingTime){
            stopTimer();
        }
        else{
            startTimer();
        }
        return true;
    default:
        return false;
  }
}

void Stopwatch::startTimer(){
    startTime = std::chrono::system_clock::now();

    countingTime = true;
}

void Stopwatch::stopTimer(){
    endTime = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = endTime - startTime;
    elapsedTime += elapsed_seconds.count();

    char timeStr[20];
    sprintf(timeStr, "%c s", (int)(elapsedTime * 100) / 100);
    lv_label_set_text(label_time, timeStr);

    countingTime = false;
}

void Stopwatch::restartTimer(){
    elapsedTime = 0;
    lv_label_set_text(label_time, "timeStr");
    countingTime = false;
}