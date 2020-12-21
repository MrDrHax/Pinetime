#pragma once

#include "../DisplayApp.h"
#include "components/datetime/DateTimeController.h"
#include "Symbols.h"
#include "Screen.h"
#include <chrono>

namespace Pinetime {
    namespace Applications {
        namespace Screens {
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

                int getCurrentTime();

                void startTimer();
                void stopTimer();
                void restartTimer();
                void calculateTime(float timeDifference);
                void convertToHMS(int seconds, unsigned short int *ms, unsigned short int *s, unsigned short int *m, unsigned int *h);

                lv_obj_t * label_time;
                lv_obj_t * label_extra;
            };
        }
    }
}
