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

    char timeStr[50];
    sprintf(timeStr, "start time: %f", startTime.time_since_epoch());
    lv_label_set_text(label_time, timeStr);
    lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);

    countingTime = true;
}

void Stopwatch::stopTimer(){
    endTime = std::chrono::system_clock::now();

    elapsedTime += std::chrono::duration_cast<std::chrono::duration<double>>(endTime - startTime).count(); // get the time difference in seconds

    char timeStr[50];
    calculateTime(elapsedTime, timeStr);
    lv_label_set_text(label_time, timeStr);
    lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);

    countingTime = false;
}

void Stopwatch::restartTimer(){
    elapsedTime = 0;
    lv_label_set_text(label_time, "RESTART");
    lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);
    countingTime = false;
}

void Stopwatch::calculateTime(double timeDifference, char *timeStr){
    convertToHMS(timeDifference, &miliseconds ,&seconds, &minutes, &hours);

    if (hours > 0) sprintf(timeStr, "time: %i:%i:%i.%i", hours, minutes, seconds, miliseconds);
    else if (minutes > 0) sprintf(timeStr, "time: %i:%i.%i", minutes, seconds, miliseconds);
    else sprintf(timeStr, "time: %i.%i", seconds, miliseconds);
}

void Stopwatch::convertToHMS(double seconds, unsigned short int *ms, unsigned short int *s, unsigned short int *m, unsigned int *h){
    unsigned temp = static_cast<int>(seconds * 1000.);

    *h = temp / (1000 * 60 * 60);
    temp -= *h * (1000 * 60 * 60);

    *m = temp / (1000 * 60);
    temp -= *m * (1000 * 60);

    *s = temp / 1000;
    temp -= *s * 1000;
    *ms = temp;
}
