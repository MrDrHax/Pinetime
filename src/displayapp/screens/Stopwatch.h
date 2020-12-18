#pragma once

#include <lvgl/src/lv_core/lv_obj.h>
#include <cstdint>
#include <cstdio>
#include <chrono>
#include "Screen.h"

namespace Pinetime {
    namespace Applications {
        namespace Screens {
            class Stopwatch : public Screen {
                public:
                Stopwatch(DisplayApp* app);
                ~Stopwatch() override;
                bool Refresh() override;
                bool OnButtonPushed() override;
                bool OnTouchEvent(TouchEvents event) override;

                //void OnValueChanged();
                private:
                bool running = true;

                bool countingTime = false;
                
                std::chrono::_V2::system_clock::time_point startTime;
                std::chrono::_V2::system_clock::time_point endTime;
                double elapsedTime = 0;
                unsigned short int miliseconds;
                unsigned short int seconds;
                unsigned short int minutes;
                unsigned int hours;

                void startTimer();
                void stopTimer();
                void restartTimer();
                void calculateTime(double timeDifference, char* timeStr);
                void convertToHMS(double seconds, unsigned short int *ms, unsigned short int *s, unsigned short int *m, unsigned int *h);

                lv_obj_t * label_time;
            };
        }
    }
}
