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

static lv_img_dsc_t img_clock1;
const uint8_t img_clock1_map[] = {
    0x00, 0x1c, 0x00, 0x00, 
    0x00, 0x1c, 0x66, 0x00, 
    0x30, 0x1c, 0x66, 0x00, 
    0x38, 0x1c, 0x66, 0x00, 
    0x1c, 0x00, 0x66, 0x00, 
    0x0c, 0x00, 0x66, 0x00, 
    0x02, 0x00, 0x66, 0x00, 
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

static lv_img_dsc_t img_clock2;
const uint8_t img_clock2_map[] = {
    0x00, 0x1c, 0x00, 0x00, 
    0x00, 0x1d, 0x80, 0x00, 
    0x30, 0x1d, 0xe0, 0x00, 
    0x38, 0x1d, 0xf8, 0x00, 
    0x1c, 0x01, 0xfe, 0x00, 
    0x0c, 0x01, 0xff, 0x80, 
    0x02, 0x01, 0xfe, 0x00, 
    0x01, 0x01, 0xf8, 0x00, 
    0x00, 0x81, 0xe0, 0x00, 
    0x00, 0x41, 0x80, 0x00, 
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

static lv_img_dsc_t img_clock3;
const uint8_t img_clock3_map[] = {
    0x00, 0x1c, 0x00, 0x00, 
    0x00, 0x1c, 0x00, 0x00, 
    0x30, 0x00, 0x06, 0x00, 
    0x38, 0x0c, 0x0e, 0x00, 
    0x1c, 0x0f, 0x9c, 0x00, 
    0x0c, 0x0f, 0xd8, 0x00, 
    0x00, 0x0f, 0xe0, 0x00, 
    0x00, 0x0f, 0xf0, 0x00, 
    0x00, 0x0f, 0xf8, 0x00, 
    0x00, 0x0f, 0xf8, 0x00, 
    0x00, 0x0f, 0xf8, 0x00, 
    0xf0, 0x0f, 0xfd, 0x80, 
    0xf0, 0x0f, 0xfd, 0x80, 
    0xf0, 0x1f, 0xfd, 0x80, 
    0x00, 0x3f, 0xf8, 0x00, 
    0x00, 0x7f, 0xf8, 0x00, 
    0x00, 0x7f, 0xf8, 0x00, 
    0x00, 0xff, 0xf0, 0x00, 
    0x00, 0xff, 0xe0, 0x00, 
    0x0d, 0xff, 0xd8, 0x00, 
    0x1c, 0xff, 0x9c, 0x00, 
    0x38, 0x1c, 0x0e, 0x00, 
    0x30, 0x00, 0x06, 0x00, 
    0x00, 0x1c, 0x00, 0x00, 
    0x00, 0x1c, 0x00, 0x00
};

static lv_img_dsc_t img_clock4;
const uint8_t img_clock4_map[] = {
    0x00, 0x1c, 0x00, 0x00, 
    0x00, 0x3e, 0x00, 0x00, 
    0x60, 0x7f, 0x03, 0x00, 
    0xf0, 0x00, 0x07, 0x80, 
    0xe0, 0x3e, 0x03, 0x80, 
    0x58, 0xff, 0x8d, 0x00, 
    0x1f, 0xc1, 0xfc, 0x00, 
    0x0f, 0x00, 0x78, 0x00, 
    0x0e, 0x00, 0x18, 0x00, 
    0x0d, 0x00, 0x18, 0x00, 
    0x18, 0x80, 0x0c, 0x00, 
    0x18, 0x40, 0x0c, 0x00, 
    0x30, 0x20, 0x06, 0x00, 
    0x30, 0x18, 0x06, 0x00, 
    0x30, 0x1c, 0x06, 0x00, 
    0x30, 0x1c, 0x06, 0x00, 
    0x30, 0x1c, 0x06, 0x00, 
    0x18, 0x08, 0x0c, 0x00, 
    0x18, 0x08, 0x0c, 0x00, 
    0x0c, 0x00, 0x18, 0x00, 
    0x0e, 0x00, 0x38, 0x00, 
    0x07, 0x00, 0x70, 0x00, 
    0x0b, 0xc1, 0xe8, 0x00, 
    0x18, 0xff, 0x8c, 0x00, 
    0x10, 0x3e, 0x04, 0x00
};

Stopwatch::Stopwatch(DisplayApp* app,
                     Controllers::DateTime& dateTimeController) : Screen(app),
                     dateTimeController{dateTimeController} {

    label_time = lv_label_create(lv_scr_act(), nullptr);
    lv_label_set_text(label_time, "00");
    lv_label_set_style(label_time, LV_LABEL_STYLE_MAIN, LabelBigStyle);
    lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);

    label_info = lv_label_create(lv_scr_act(), nullptr);
    lv_label_set_text(label_info, "");
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

    img_clock1.header.always_zero = 0; //Initialization
    img_clock1.header.w = 25;
    img_clock1.header.h = 25;
    img_clock1.data_size = 100; 
    img_clock1.header.cf = LV_IMG_CF_ALPHA_1BIT; 
    img_clock1.data = img_clock0_map;

    img_clock2.header.always_zero = 0; //Initialization
    img_clock2.header.w = 25;
    img_clock2.header.h = 25;
    img_clock2.data_size = 100; 
    img_clock2.header.cf = LV_IMG_CF_ALPHA_1BIT; 
    img_clock2.data = img_clock0_map;

    img_clock3.header.always_zero = 0; //Initialization
    img_clock3.header.w = 25;
    img_clock3.header.h = 25;
    img_clock3.data_size = 100; 
    img_clock3.header.cf = LV_IMG_CF_ALPHA_1BIT; 
    img_clock3.data = img_clock0_map;

    img_clock4.header.always_zero = 0; //Initialization
    img_clock4.header.w = 25;
    img_clock4.header.h = 25;
    img_clock4.data_size = 100; 
    img_clock4.header.cf = LV_IMG_CF_ALPHA_1BIT; 
    img_clock4.data = img_clock0_map;

    changeClockIMG(img_clock0);

    timerEnd = std::chrono::system_clock::from_time_t(0);
}

Stopwatch::~Stopwatch() {
    lv_obj_clean(lv_scr_act());
}

bool Stopwatch::Refresh() {
    switch (currentScreen)
    {
    case 0:
        if (countingTime){
            //1st count new time

            int time = getCurrentTime();

            // 2nd update timer label

            calculateTime(time);
        }
        break;
    
    case 1:
        if (timerCountingTime){

        }
        else{
            // 1st count new time

            int time = timerEnd.time_since_epoch().count();

            // 2nd update timer label

            calculateTime(time);
        }
        break;

    case 2:
        break;

    default:
        break;
    }
    

    return running;
}

bool Stopwatch::OnButtonPushed() {
    // TODO add here save states
  running = false;
  return true;
}

bool Stopwatch::OnTouchEvent(Pinetime::Applications::TouchEvents event) {
    switch (currentScreen)
    {
    case 0: // make this in case of stopwatch
        switch(event) {
            case TouchEvents::SwipeLeft:
                // go to next tab
                currentScreen --;
                if (currentScreen < 0) currentScreen = 2;
                updateCurrentScreen();
                return true;
            case TouchEvents::SwipeRight:
                // go to next tab
                currentScreen ++;
                if (currentScreen > 2) currentScreen = 0; 
                updateCurrentScreen();
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
        break;
    
    case 1:
        switch(event) {
            case TouchEvents::SwipeLeft:
                // go to next tab
                currentScreen --;
                if (currentScreen < 0) currentScreen = 2;
                updateCurrentScreen();
                return true;
            case TouchEvents::SwipeRight:
                // go to next tab
                currentScreen ++;
                if (currentScreen > 2) currentScreen = 0; 
                updateCurrentScreen();
                return true;
            case TouchEvents::SwipeDown:
                // reduce amount of time
                timerEnd -= std::chrono::minutes(1);
                return true;
            case TouchEvents::SwipeUp:
                // aument the time untill the end
                timerEnd += std::chrono::minutes(1);
                return true;
            case TouchEvents::Tap:
                // get tap
                // start the countdown here
                return true;
            default:
                return true;
        }
        break;

    case 2:
        break;

    default:
        return false;
    }
    return true;
}

void Stopwatch::startTimer(){
    changeClockIMG(img_clock2);
    startTime = dateTimeController.CurrentDateTime();

    countingTime = true;
}

void Stopwatch::stopTimer(){
    // add paused lavel here
    countingTime = false;
    elapsedTime = getCurrentTime();
    changeClockIMG(img_clock1);
}

void Stopwatch::restartTimer(){
    elapsedTime = 0;

    lv_img_set_src(img_src, &img_clock0);
    lv_obj_align(img_src, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 20);

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


void Stopwatch::updateCurrentScreen(){
    switch (currentScreen)
    {
    case 0:
        drawStopwatchScreen();
        break;
    case 1:
        drawTimerScreen();
        break;
    case 2:
        drawAlarmScreen();
        break;
    
    default:
        drawStopwatchScreen();
        break;
    }
    lv_obj_align(img_src, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 20);
}

void Stopwatch::drawStopwatchScreen(){
    lv_label_set_text(label_extra, "");

    lv_label_set_text(label_info, "");

    lv_label_set_text(label_time, "00");

    lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);
    lv_obj_align(label_extra, lv_scr_act(), LV_ALIGN_CENTER, 0, label_extra_offset);
    lv_obj_align(label_info, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 40);
}

void Stopwatch::drawTimerScreen(){
    changeClockIMG(img_clock3);

    lv_label_set_text(label_extra, "00");

    lv_label_set_text(label_info, "timer 1");

    lv_label_set_text(label_time, "00:00");

    lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);
    lv_obj_align(label_extra, lv_scr_act(), LV_ALIGN_CENTER, 0, label_extra_offset);
    lv_obj_align(label_info, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 50);
}

void Stopwatch::drawAlarmScreen(){
    changeClockIMG(img_clock4);

    lv_label_set_text(label_extra, "");

    lv_label_set_text(label_info, "wip");

    lv_label_set_text(label_time, "00:00");

    lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);
    lv_obj_align(label_extra, lv_scr_act(), LV_ALIGN_CENTER, 0, label_extra_offset);
    lv_obj_align(label_info, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 40);
}

void Stopwatch::changeClockIMG(lv_img_dsc_t newImage){
    img_src = lv_img_create(lv_scr_act(), NULL);  
    lv_img_set_src(img_src, &newImage);

    lv_obj_align(img_src, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 15);
}