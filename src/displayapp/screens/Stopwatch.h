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
                
                std::chrono::_V2::system_clock::time_point startTime = std::chrono::system_clock::now();
                std::chrono::_V2::system_clock::time_point endTime = std::chrono::system_clock::now();
                double elapsedTime = 0;

                void startTimer();
                void stopTimer();
                void restartTimer();

                lv_obj_t * label_time;
            };
        }
    }
}
