#include "Stopwatch.h"
#include <lvgl/lvgl.h>

using namespace Pinetime::Applications::Screens;

Stopwatch::Stopwatch(Pinetime::Applications::DisplayApp *app) : Screen(app){
    label_time = lv_label_create(lv_scr_act(), nullptr);
    lv_label_set_text(label_time, "TIME");
    lv_obj_set_auto_realign(label_time, true);
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
    default:
      return false;
  }
}