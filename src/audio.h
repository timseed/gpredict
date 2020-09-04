#include <stdlib.h>
#include <pthread.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#undef main
#define MAIN_SLEEP 2
#define THREAD_SLEEP 1
#define AUDIO_FILE  "/Users/tim/Dev/gpredict-2.2.1/allegro_test/arriving.wav"
#define ALLEGRO_NO_MAGIC_MAIN
extern pthread_mutex_t mtx;
extern pthread_mutex_t  audio_running;
int   play_audio(void);
