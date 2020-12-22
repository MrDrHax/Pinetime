#include "../DisplayApp.h"
#include "components/datetime/DateTimeController.h"
//#include "displayapp/icons/stopwatch/clock0.c"
#include "Stopwatch.h"
#include "Symbols.h"
#include <chrono>
#include <cstdio>

using namespace Pinetime::Applications::Screens;

using std::chrono::duration;
using std::chrono::duration_cast;

extern lv_font_t jetbrains_mono_extrabold_compressed;
extern lv_font_t jetbrains_mono_bold_20;

extern lv_style_t* LabelBigStyle;
 
static lv_img_dsc_t img_clock0;
const uint8_t img_clock0_map[] = {
    0x00, 0x1c, 0x00, 0x00, 
    0x00, 0x1c, 0x00, 0x00, 
    0x30, 0x1c, 0x06, 0x00, 
    0x38, 0x1c, 0x0e, 0x00, 
    0x1c, 0x00, 0x1c, 0x00, 
    0x0c, 0x00, 0x18, 0x00, 
    0x02, 0x00, 0x00, 0x00, 
    0x01, 0x00, 0x00, 0x00, 
    0x00, 0x80, 0x00, 0x00, 
    0x00, 0x40, 0x00, 0x00, 
    0x00, 0x20, 0x00, 0x00, 
    0xf0, 0x18, 0x07, 0x80, 
    0xf0, 0x1c, 0x07, 0x80, 
    0xf0, 0x1c, 0x07, 0x80, 
    0x00, 0x1c, 0x00, 0x00, 
    0x00, 0x1c, 0x00, 0x00, 
    0x00, 0x08, 0x00, 0x00, 
    0x00, 0x08, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x0c, 0x00, 0x18, 0x00, 
    0x1c, 0x00, 0x1c, 0x00, 
    0x38, 0x1c, 0x0e, 0x00, 
    0x30, 0x1c, 0x06, 0x00, 
    0x00, 0x1c, 0x00, 0x00, 
    0x00, 0x1c, 0x00, 0x00
};

lv_obj_t *img_waitchMain = lv_img_create(lv_scr_act(), NULL);


Stopwatch::Stopwatch(DisplayApp* app,
                     Controllers::DateTime& dateTimeController) : Screen(app),
                     dateTimeController{dateTimeController} {

    label_time = lv_label_create(lv_scr_act(), nullptr);
    lv_label_set_text(label_time, "00");
    lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);
    lv_label_set_style(label_time, LV_LABEL_STYLE_MAIN, LabelBigStyle);

    label_info = lv_label_create(lv_scr_act(), nullptr);
    lv_label_set_text(label_info, "paused");
    lv_obj_align(label_info, lv_scr_act(), LV_ALIGN_CENTER, 0, -80);

    label_extra = lv_label_create(lv_scr_act(), nullptr);
    lv_label_set_text(label_extra, "");
    lv_obj_align(label_extra, lv_scr_act(), LV_ALIGN_CENTER, 0, label_extra_offset);
    lv_label_set_style(label_extra, LV_LABEL_STYLE_MAIN, LabelBigStyle);

    // set images
    img_clock0.header.always_zero = 0; //Initialization
    img_clock0.header.w = 25;
    img_clock0.header.h = 25;
    img_clock0.data_size = 100; 
    img_clock0.header.cf = LV_IMG_CF_ALPHA_1BIT; 
    img_clock0.data = img_clock0_map;
    lv_obj_t *img_src = lv_img_create(lv_scr_act(), NULL);  
    lv_img_set_src(img_src, &img_clock0);       

    lv_obj_align(img_src, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 0); 
}

Stopwatch::~Stopwatch() {
    lv_obj_clean(lv_scr_act());
}

bool Stopwatch::Refresh() {
    if (countingTime){
        //1st count new time

        int time = getCurrentTime();

        // 2nd update timer label

        calculateTime(time);
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
        return true;
  }
}

void Stopwatch::startTimer(){
    lv_label_set_text(label_info, "counting");
    startTime = dateTimeController.CurrentDateTime();

    countingTime = true;
}

void Stopwatch::stopTimer(){
    // add paused lavel here
    countingTime = false;
    elapsedTime = getCurrentTime();
    lv_label_set_text(label_info, "paused");
}

void Stopwatch::restartTimer(){
    elapsedTime = 0;

    lv_label_set_text(label_info, "paused");

    lv_label_set_text(label_extra, "");

    lv_label_set_text(label_time, "00");

    countingTime = false;
}

int Stopwatch::getCurrentTime() {
    auto delta =
        duration_cast<std::chrono::milliseconds>(dateTimeController.CurrentDateTime() - startTime);
        
    return delta.count() + elapsedTime;
}

void Stopwatch::calculateTime(float timeDifference){
    convertToHMS(timeDifference, &miliseconds ,&seconds, &minutes, &hours);
    char timeStr[6];

    if (hours > 0) {
        sprintf(timeStr, "%02i:%02i", hours, minutes);

        lv_label_set_text(label_time, timeStr);
        lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_CENTER, 0, -20);
        
        sprintf(timeStr, "%02i", seconds);

        lv_label_set_text(label_extra, timeStr);
        lv_obj_align(label_extra, lv_scr_act(), LV_ALIGN_CENTER, 0, label_extra_offset - 20);
    }
    else if (minutes > 0) {
        sprintf(timeStr, "%02i:%02i", minutes, seconds);

        lv_label_set_text(label_time, timeStr);
        lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);
        
        //sprintf(timeStr, "%i", miliseconds); // add miliseconds when you find out how to here!!!!
        
        lv_label_set_text(label_extra, "");
        lv_obj_align(label_extra, lv_scr_act(), LV_ALIGN_CENTER, 0, label_extra_offset);
    }
    else {
        sprintf(timeStr, "%02i", seconds); // add ms here when you know how to

        lv_label_set_text(label_time, timeStr);
        lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);
        
        //sprintf(timeStr, "%i", miliseconds); // add miliseconds when you find out how to here!!!!
        
        lv_label_set_text(label_extra, "");
        lv_obj_align(label_extra, lv_scr_act(), LV_ALIGN_CENTER, 0, label_extra_offset);
    }
}

void Stopwatch::convertToHMS(int seconds, unsigned short int *ms, unsigned short int *s, unsigned short int *m, unsigned int *h){
    static int multiplier = 1000;
    int temp = static_cast<int>(seconds);

    *h = temp / (multiplier * 60 * 60);
    temp -= *h * (multiplier * 60 * 60);

    *m = temp / (multiplier * 60);
    temp -= *m * (multiplier * 60);

    *s = temp / multiplier;
    temp -= *s * multiplier;
    *ms = temp;
}
