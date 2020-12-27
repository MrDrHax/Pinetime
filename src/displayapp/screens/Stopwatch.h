#pragma once

#include "../DisplayApp.h"
#include "components/datetime/DateTimeController.h"
//#include "displayapp/icons/stopwatch/clock0.c"
#include "Symbols.h"
#include "Screen.h"
#include <chrono>
#include <cstdio>
#include <vector>



namespace Pinetime {
    namespace Applications {
        namespace Screens {

            class TimeAlarm{
                unsigned short int minutes = 0;
                unsigned int hours = 0;
                unsigned int count = 0;

                bool weekdays[7] = {false, false, false, false, false, false, false};
            };

            //lv_obj_t *img_waitchMain;

            class Stopwatch : public Screen {
                public:
                Stopwatch(DisplayApp *app, Controllers::DateTime& dateTimeController);
                ~Stopwatch() override;
                bool Refresh() override;
                bool OnButtonPushed() override;
                bool OnTouchEvent(TouchEvents event) override;

                //void OnValueChanged();
                private:
                bool running = true;

                bool countingTime = false;
                bool timerCountingTime = false;

                float elapsedTime = 0.;

                unsigned short int miliseconds = 0;
                unsigned short int seconds = 0;
                unsigned short int minutes = 0;
                unsigned int hours = 0;
                unsigned int count = 0;

                const int label_extra_offset = 80;

                Controllers::DateTime& dateTimeController;
                std::chrono::system_clock::time_point startTime;
                std::chrono::system_clock::time_point endTime;

                lv_obj_t *img_src;

                int getCurrentTime();

                void startTimer();
                void stopTimer();
                void restartTimer();
                void calculateTime(float timeDifference);
                void convertToHMS(int seconds, unsigned short int *ms, unsigned short int *s, unsigned short int *m, unsigned int *h);

                lv_obj_t * label_time;
                lv_obj_t * label_info;
                lv_obj_t * label_extra;

                int8_t currentScreen = 0;

                void updateCurrentScreen();

                void drawStopwatchScreen();
                void drawTimerScreen();
                void drawAlarmScreen();

                void changeClockIMG(lv_img_dsc_t newImage);

                // counter things

                std::chrono::system_clock::time_point timerEnd;
                std::chrono::system_clock::time_point timerToAdd;

                // alarm things

                std::vector<TimeAlarm> alarms;
            };
        }
    }
}
