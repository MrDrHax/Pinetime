#include "../DisplayApp.h"
#include "components/datetime/DateTimeController.h"
#include "Stopwatch.h"
#include "Symbols.h"

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
  lv_obj_align(label_extra, label_time, LV_ALIGN_CENTER, 0, 10);

  lv_label_set_text(label_time, "Time v0.0.7");
}

Stopwatch::~Stopwatch() {
  lv_obj_clean(lv_scr_act());
}

bool Stopwatch::Refresh() {
    if (countingTime){
        // fix this

        //1st count new time

        double time = getCurrentTime();

        // 2nd update timer label
        char otherStr[50];
        convertToHMS(time, &miliseconds, &seconds, &minutes, &hours);
        sprintf(otherStr, "%02i.%02i", seconds, miliseconds);
        lv_label_set_text(label_time, otherStr);
        
        char timeStr[50];
        lv_label_set_text(label_extra, "counting...");
        lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);

        
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
}

void Stopwatch::restartTimer(){
    elapsedTime = 0.;

    lv_label_set_text(label_time, "RESTART");
    lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);

    lv_label_set_text(label_extra, "0:0:0.0");
    lv_obj_align(label_extra, lv_scr_act(), LV_ALIGN_CENTER, 0, 20);

    countingTime = false;
}

double Stopwatch::getCurrentTime() {
  duration<double> delta =
      duration_cast<duration<double>>(dateTimeController.CurrentDateTime() - startTime);
  return (double) delta.count();
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
