#include "../DisplayApp.h"
#include "components/datetime/DateTimeController.h"
#include "Stopwatch.h"
#include "Symbols.h"
#include <chrono>

using namespace Pinetime::Applications::Screens;

using std::chrono::duration;
using std::chrono::duration_cast;

extern lv_font_t jetbrains_mono_extrabold_compressed;
extern lv_font_t jetbrains_mono_bold_20;

Stopwatch::Stopwatch(DisplayApp* app,
                     Controllers::DateTime& dateTimeController) : Screen(app),
                     dateTimeController{dateTimeController} {

  label_time = lv_label_create(lv_scr_act(), nullptr);
  lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);
  lv_label_set_align(label_time, LV_LABEL_ALIGN_CENTER);

  label_extra = lv_label_create(lv_scr_act(), nullptr);
  lv_obj_align(label_extra, lv_scr_act(), LV_ALIGN_CENTER, 0, 50);

  lv_label_set_text(label_time, "Time v0.0.9");
}

Stopwatch::~Stopwatch() {
  lv_obj_clean(lv_scr_act());
}

bool Stopwatch::Refresh() {
    if (countingTime){
        // fix this

        //1st count new time

        int time = getCurrentTime();

        // 2nd update timer label
        char otherStr[13];

        calculateTime(time, otherStr);
        lv_label_set_text(label_time, otherStr);
        lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);
        
        char timeStr[11];
        sprintf(timeStr, "%i", time);
        lv_label_set_text(label_extra, timeStr);
        
    }

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
    startTime = dateTimeController.CurrentDateTime();

    countingTime = true;
}

void Stopwatch::stopTimer(){
    // add paused lavel here
    countingTime = false;
    elapsedTime = getCurrentTime();
    lv_label_set_text(label_extra, "paused");
}

void Stopwatch::restartTimer(){
    elapsedTime = 0.;

    lv_label_set_text(label_extra, "RESTART");

    lv_label_set_text(label_time, "00.00");

    countingTime = false;
}

int Stopwatch::getCurrentTime() {
    auto delta =
        duration_cast<std::chrono::milliseconds>(dateTimeController.CurrentDateTime() - startTime);
        
    return delta.count() + elapsedTime;
}

void Stopwatch::calculateTime(float timeDifference, char *timeStr){
    convertToHMS(timeDifference, &miliseconds ,&seconds, &minutes, &hours);

    if (hours > 0) sprintf(timeStr, "%02i:%02i:%02i.%02i", hours, minutes, seconds, miliseconds);
    else if (minutes > 0) sprintf(timeStr, "%02i:%02i.%02i", minutes, seconds, miliseconds);
    else sprintf(timeStr, "%02i.%02i", seconds, miliseconds);
}

void Stopwatch::convertToHMS(int seconds, unsigned short int *ms, unsigned short int *s, unsigned short int *m, unsigned int *h){
    int temp = static_cast<int>(seconds * 1.);

    *h = temp / (1 * 60 * 60);
    temp -= *h * (1 * 60 * 60);

    *m = temp / (1 * 60);
    temp -= *m * (1 * 60);

    *s = temp / 1;
    temp -= *s * 1;
    *ms = temp;
}
