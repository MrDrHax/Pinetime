#include "Clock.h"

#include <date/date.h>
#include <lvgl/lvgl.h>
#include <cstdio>
#include "BatteryIcon.h"
#include "BleIcon.h"
#include "NotificationIcon.h"
#include "Symbols.h"
#include "components/battery/BatteryController.h"
#include "components/ble/BleController.h"
#include "components/ble/NotificationManager.h"
#include "../DisplayApp.h"

using namespace Pinetime::Applications::Screens;

extern lv_font_t jetbrains_mono_extrabold_compressed;
extern lv_font_t jetbrains_mono_bold_20;
// extern lv_font_t PressStart2p_8p;

extern lv_style_t* LabelBigStyle;

// TODO:
/*
  2) find out how to draw lines
  3) find out how to draw in different colours
    -make AM/PM labels be drawn in different shade depending on what is active
    -add orange
    -decide what other colourScheme we can make
  5) search how to recognize different touches (like swipe or long press)
    -make swipe down oppen app (can be anyone for the timebeing)

  - after this, notification list will be planned
*/

static void event_handler(lv_obj_t * obj, lv_event_t event) {
  Clock* screen = static_cast<Clock *>(obj->user_data);
  screen->OnObjectEvent(obj, event);
}

Clock::Clock(DisplayApp* app,
        Controllers::DateTime& dateTimeController,
        Controllers::Battery& batteryController,
        Controllers::Ble& bleController,
        Controllers::NotificationManager& notificatioManager) : Screen(app), currentDateTime{{}},
                                           dateTimeController{dateTimeController}, batteryController{batteryController},
                                           bleController{bleController}, notificatioManager{notificatioManager} {
  displayedChar[0] = 0;
  displayedChar[1] = 0;
  displayedChar[2] = 0;
  displayedChar[3] = 0;
  displayedChar[4] = 0;

  // set icons for every item that needs one

  lv_style_copy(&LV_STYLE_CLOCK_EXTRAS, &lv_style_plain);

  LV_STYLE_CLOCK_EXTRAS.text.color = LV_COLOR_WHITE;

  batteryIcon = lv_label_create(lv_scr_act(), nullptr);
  //lv_obj_set_style(batteryIcon, &LV_STYLE_CLOCK_EXTRAS);
  lv_label_set_text(batteryIcon, "100");
  lv_obj_align(batteryIcon, lv_scr_act(), LV_ALIGN_IN_TOP_RIGHT, -8, -6);

  batteryPlug = lv_label_create(lv_scr_act(), nullptr);
  //lv_obj_set_style(batteryPlug, &LV_STYLE_CLOCK_EXTRAS);
  lv_label_set_text(batteryPlug, Symbols::plug);
  lv_obj_align(batteryPlug, batteryIcon, LV_ALIGN_OUT_LEFT_MID, -5, 0);

  bleIcon = lv_label_create(lv_scr_act(), nullptr);
  //lv_obj_set_style(bleIcon, &LV_STYLE_CLOCK_EXTRAS);
  lv_label_set_text(bleIcon, Symbols::bluetooth);
  lv_obj_align(bleIcon, batteryPlug, LV_ALIGN_OUT_LEFT_MID, -5, 0);

  notificationIcon = lv_label_create(lv_scr_act(), NULL);
  //lv_obj_set_style(notificationIcon, &LV_STYLE_CLOCK_EXTRAS);
  lv_label_set_text(notificationIcon, NotificationIcon::GetIcon(false));
  lv_obj_align(notificationIcon, nullptr, LV_ALIGN_IN_TOP_LEFT, 10, 0);

  // date labels
  label_date = lv_label_create(lv_scr_act(), nullptr);
  label_date2 = lv_label_create(lv_scr_act(), nullptr);

  lv_obj_align(label_date, lv_scr_act(), LV_ALIGN_IN_TOP_LEFT, 5, 140);
  lv_obj_align(label_date2, lv_scr_act(), LV_ALIGN_IN_TOP_LEFT, 5, 160);

  label_time = lv_label_create(lv_scr_act(), nullptr);
  lv_label_set_style(label_time, LV_LABEL_STYLE_MAIN, LabelBigStyle);
  lv_label_set_text(label_time, "00:00"); // makes sure it is alligned in mid
  lv_obj_align(label_time, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 60);

  // make the lines sorrounding the hour

  lv_style_copy(&LV_STYLE_CLOCK_BACKGROUND, &lv_style_scr);

  LV_STYLE_CLOCK_BACKGROUND.body.main_color = LV_COLOR_MAKE(252, 231, 93);
  LV_STYLE_CLOCK_BACKGROUND.body.grad_color = LV_COLOR_MAKE(252, 231, 93);
  LV_STYLE_CLOCK_BACKGROUND.body.radius = 5;

  box1 = lv_obj_create(lv_scr_act(), nullptr);
  lv_obj_set_size(box1, 200, 10);
  lv_obj_align(box1, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 35);
  lv_obj_set_style(box1, &LV_STYLE_CLOCK_BACKGROUND);

  box2 = lv_obj_create(lv_scr_act(), nullptr);
  lv_obj_set_size(box2, 200, 10);
  lv_obj_align(box2, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 110);
  lv_obj_set_style(box2, &LV_STYLE_CLOCK_BACKGROUND);

  lv_obj_refresh_style(box1);
  lv_obj_refresh_style(box2);


  // set the background button to change to other screen
  // note!!!!!! we can use this to launch the chosen app!!!!!
  /*
  backgroundLabel = lv_label_create(lv_scr_act(), nullptr);
  backgroundLabel->user_data = this;
  lv_obj_set_click(backgroundLabel, true);
  lv_obj_set_event_cb(backgroundLabel, event_handler);
  lv_label_set_long_mode(backgroundLabel, LV_LABEL_LONG_CROP);
  lv_obj_set_size(backgroundLabel, 60, 60);
  lv_obj_align(backgroundLabel, lv_scr_act(), LV_ALIGN_IN_BOTTOM_RIGHT, -20, -20);
  lv_label_set_text(backgroundLabel, "A");
  lv_label_set_recolor()
  */

  backgroundLabel = lv_btn_create(lv_scr_act(), NULL);
  lv_obj_set_event_cb(backgroundLabel, event_handler);
  lv_obj_set_size(backgroundLabel, 60, 60);
  lv_obj_align(backgroundLabel, lv_scr_act(), LV_ALIGN_IN_BOTTOM_RIGHT, -20, -20);

  cuickAppIcon = lv_label_create(backgroundLabel, NULL);
  lv_label_set_text(cuickAppIcon, "A");

  heartbeatIcon = lv_label_create(lv_scr_act(), nullptr);
  lv_label_set_text(heartbeatIcon, Symbols::heartBeat);
  lv_obj_align(heartbeatIcon, lv_scr_act(), LV_ALIGN_IN_BOTTOM_LEFT, 13, -2);

  heartbeatValue = lv_label_create(lv_scr_act(), nullptr);
  lv_label_set_text(heartbeatValue, "0");
  lv_obj_align(heartbeatValue, heartbeatIcon, LV_ALIGN_OUT_RIGHT_MID, 5, 0);

  heartbeatBpm = lv_label_create(lv_scr_act(), nullptr);
  lv_label_set_text(heartbeatBpm, "UwUs");
  lv_obj_align(heartbeatBpm, heartbeatValue, LV_ALIGN_OUT_RIGHT_MID, 5, 0);

  stepValue = lv_label_create(lv_scr_act(), nullptr);
  lv_label_set_text(stepValue, "0");
  lv_obj_align(stepValue, lv_scr_act(), LV_ALIGN_IN_BOTTOM_LEFT, 5, -2);

  stepIcon = lv_label_create(lv_scr_act(), nullptr);
  lv_label_set_text(stepIcon, Symbols::shoe);
  lv_obj_align(stepIcon, stepValue, LV_ALIGN_OUT_LEFT_MID, -5, 0);
}

Clock::~Clock() {
  lv_obj_clean(lv_scr_act());
}

bool Clock::Refresh() { // gets called every frame

  // info icons -----------------------------------------------------------------------------------------------
  // change battery percentage
  batteryPercentRemaining = batteryController.PercentRemaining();
  if (batteryPercentRemaining.IsUpdated()) { // do something if battery is changed, and change icon to resemblance percentage
    auto batteryPercent = batteryPercentRemaining.Get();

    char str[3];

    if (batteryPercent == 100) sprintf(str, "100");
    else sprintf(str, "%02d%%", static_cast<int>(batteryPercent));

    lv_label_set_text(batteryIcon, str);

    auto isCharging = batteryController.IsCharging() || batteryController.IsPowerPresent();
    lv_label_set_text(batteryPlug, BatteryIcon::GetPlugIcon(isCharging));
  }

  // check if ble is connected, and display if it is
  bleState = bleController.IsConnected();
  if (bleState.IsUpdated()) {
    if(bleState.Get() == true) {
      lv_label_set_text(bleIcon, BleIcon::GetIcon(true));
    } else {
      lv_label_set_text(bleIcon, BleIcon::GetIcon(false));
    }
  }

  // icon alligment

  lv_obj_align(batteryIcon, lv_scr_act(), LV_ALIGN_IN_TOP_RIGHT, -30, 10);
  lv_obj_align(batteryPlug, batteryIcon, LV_ALIGN_OUT_LEFT_MID, -5, -3);
  lv_obj_align(bleIcon, batteryPlug, LV_ALIGN_OUT_LEFT_MID, -5, 0);

  // notifications ----------------------------------------------------------------------------------------------------

  notificationState = notificatioManager.AreNewNotificationsAvailable();
  if(notificationState.IsUpdated()) {
    if(notificationState.Get() == true)
      lv_label_set_text(notificationIcon, NotificationIcon::GetIcon(true));
    else
      lv_label_set_text(notificationIcon, NotificationIcon::GetIcon(false));
  }

  // date and time ----------------------------------------------------------------------------------------------------

  currentDateTime = dateTimeController.CurrentDateTime(); // get new time

  if(currentDateTime.IsUpdated()) { // update the clock if it needs to be updated
    auto newDateTime = currentDateTime.Get();

    // start separating date from time
    auto dp = date::floor<date::days>(newDateTime);
    auto time = date::make_time(newDateTime-dp);
    auto yearMonthDay = date::year_month_day(dp);

    // get info for date 
    auto year = (int)yearMonthDay.year();
    auto month = static_cast<Pinetime::Controllers::DateTime::Months>((unsigned)yearMonthDay.month());
    auto day = (unsigned)yearMonthDay.day();
    auto dayOfWeek = static_cast<Pinetime::Controllers::DateTime::Days>(date::weekday(yearMonthDay).iso_encoding());

    // get time separated into hour and minute
    auto hour = time.hours().count();
    auto minute = time.minutes().count();

    // change to AM/PM

    if (hour > 12 && AMPM){
      hour -= 12;
    }

    // change colour of label depending on time of day

    if (hour >= 12){
      LV_STYLE_CLOCK_BACKGROUND.body.main_color = LV_COLOR_MAKE(163, 205, 255);
      LV_STYLE_CLOCK_BACKGROUND.body.grad_color = LV_COLOR_MAKE(163, 205, 255);
    }
    else{
      LV_STYLE_CLOCK_BACKGROUND.body.main_color = LV_COLOR_MAKE(252, 231, 93);
      LV_STYLE_CLOCK_BACKGROUND.body.grad_color = LV_COLOR_MAKE(252, 231, 93);
    }

    lv_obj_refresh_style(box1);
    lv_obj_refresh_style(box2);

    // build time string
    char minutesChar[3];
    sprintf(minutesChar, "%02d", static_cast<int>(minute));

    char hoursChar[3];
    sprintf(hoursChar, "%02d", static_cast<int>(hour));

    char timeStr[6];
    sprintf(timeStr, "%c%c:%c%c", hoursChar[0],hoursChar[1],minutesChar[0], minutesChar[1]);

    // see if time change is necesary
    if(hoursChar[0] != displayedChar[0] || hoursChar[1] != displayedChar[1] || minutesChar[0] != displayedChar[2] || minutesChar[1] != displayedChar[3]) {
      displayedChar[0] = hoursChar[0];
      displayedChar[1] = hoursChar[1];
      displayedChar[2] = minutesChar[0];
      displayedChar[3] = minutesChar[1];

      lv_label_set_text(label_time, timeStr);
    }

    // change year if changed
    if ((year != currentYear) || (month != currentMonth) || (dayOfWeek != currentDayOfWeek) || (day != currentDay)) {
      char dateStr[9];
      char dateStr2[6];
      sprintf(dateStr, "%s, %d", MonthToString(month), year);
      sprintf(dateStr2, "%s %02d", DayOfWeekToString(dayOfWeek), day);
      lv_label_set_text(label_date, dateStr);
      lv_label_set_text(label_date2, dateStr2);

      currentYear = year;
      currentMonth = month;
      currentDayOfWeek = dayOfWeek;
      currentDay = day;
    }
  }

  // heartbeat (WIP) ---------------------------------------------------------------------------------------------------
  // TODO: heartbeat = heartBeatController.GetValue();
  if(heartbeat.IsUpdated()) {
    char heartbeatBuffer[4];
    sprintf(heartbeatBuffer, "%d", heartbeat.Get());
    lv_label_set_text(heartbeatValue, heartbeatBuffer);
    lv_obj_align(heartbeatIcon, lv_scr_act(), LV_ALIGN_IN_BOTTOM_LEFT, 5, -2);
    lv_obj_align(heartbeatValue, heartbeatIcon, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_obj_align(heartbeatBpm, heartbeatValue, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
  }

  // stepcounter (WIP) -------------------------------------------------------------------------------------------------
  // TODO stepCount = stepController.GetValue();
  if(stepCount.IsUpdated()) {
    char stepBuffer[5];
    sprintf(stepBuffer, "%lu", stepCount.Get());
    lv_label_set_text(stepValue, stepBuffer);
    lv_obj_align(stepIcon, lv_scr_act(),  LV_ALIGN_IN_BOTTOM_LEFT, 5, -21);
    lv_obj_align(stepValue, stepIcon, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
  }

  // ens app if running is false, making clock turn off
  return running;
}

// gate date and moth from number to string
const char *Clock::MonthToString(Pinetime::Controllers::DateTime::Months month) {
  return Clock::MonthsString[static_cast<uint8_t>(month)];
}

const char *Clock::DayOfWeekToString(Pinetime::Controllers::DateTime::Days dayOfWeek) {
  return Clock::DaysString[static_cast<uint8_t>(dayOfWeek)];
}

char const *Clock::DaysString[] = { // string reference for dates conversion
        "",
        "MON",
        "TUE",
        "WED",
        "THU",
        "FRI",
        "SAT",
        "SUN"
};

char const *Clock::MonthsString[] = { // string reference for months
        "",
        "JAN",
        "FEB",
        "MAR",
        "APR",
        "MAY",
        "JUN",
        "JUL",
        "AUG",
        "SEP",
        "OCT",
        "NOV",
        "DEC"
};

// check clicks on objects
void Clock::OnObjectEvent(lv_obj_t *obj, lv_event_t event) {
  if(obj == backgroundLabel) {
    if (event == LV_EVENT_CLICKED) {

      running = false;
    }
  }
}

// end app if button is pressed
bool Clock::OnButtonPushed() {
  running = false; // app terminator on main loop
  return false;
}

bool Clock::OnTouchEvent(Pinetime::Applications::TouchEvents event) {
  switch(event) {
    case TouchEvents::SwipeDown:
      // start notifications here
      
      return true;
    
    case TouchEvents::LongTap:
      // get tap

      // change to AM PM format or back
      if (AMPM) AMPM = false;
      else AMPM = true;
      
      return true;
    default:
      return false;
  }
}
