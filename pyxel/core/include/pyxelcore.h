#ifndef PYXELCORE_H_
#define PYXELCORE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#ifdef WIN32
#ifdef PYXEL_DLL
#define PYXEL_API __declspec(dllexport)
#else
#define PYXEL_API __declspec(dllimport)
#endif
#else
#define PYXEL_API
#endif

//
// System
//
PYXEL_API int32_t width_getter();
PYXEL_API int32_t height_getter();
PYXEL_API int32_t frame_count_getter();

PYXEL_API void init(int32_t width,
                    int32_t height,
                    const char* caption,
                    int32_t scale,
                    const int32_t* palette,
                    int32_t fps,
                    int32_t border_width,
                    int32_t border_color);
PYXEL_API void run(void (*update)(), void (*draw)());
PYXEL_API void quit();
PYXEL_API void error(const char* func, const char* msg);

//
// Resource
//
PYXEL_API void save(const char* filename);
PYXEL_API void load(const char* filename);

//
// Input
//
PYXEL_API int32_t mouse_x_getter();
PYXEL_API int32_t mouse_y_getter();

PYXEL_API int32_t btn(int32_t key);
PYXEL_API int32_t btnp(int32_t key, int32_t hold, int32_t period);
PYXEL_API int32_t btnr(int32_t key);
PYXEL_API void mouse(int32_t visible);

//
// Graphics
//
PYXEL_API void* image(int32_t img, int32_t system);
PYXEL_API void* tilemap(int32_t tm);
PYXEL_API void clip0();
PYXEL_API void clip(int32_t x1, int32_t y1, int32_t x2, int32_t y2);
PYXEL_API void pal0();
PYXEL_API void pal(int32_t col1, int32_t col2);
PYXEL_API void cls(int32_t col);
PYXEL_API void pix(int32_t x, int32_t y, int32_t col);
PYXEL_API void line(int32_t x1,
                    int32_t y1,
                    int32_t x2,
                    int32_t y2,
                    int32_t col);
PYXEL_API void rect(int32_t x1,
                    int32_t y1,
                    int32_t x2,
                    int32_t y2,
                    int32_t col);
PYXEL_API void rectb(int32_t x1,
                     int32_t y1,
                     int32_t x2,
                     int32_t y2,
                     int32_t col);
PYXEL_API void circ(int32_t x, int32_t y, int32_t r, int32_t col);
PYXEL_API void circb(int32_t x, int32_t y, int32_t r, int32_t col);
PYXEL_API void blt(int32_t x,
                   int32_t y,
                   int32_t img,
                   int32_t u,
                   int32_t v,
                   int32_t w,
                   int32_t h,
                   int32_t colkey);
PYXEL_API void bltm(int32_t x,
                    int32_t y,
                    int32_t tm,
                    int32_t u,
                    int32_t v,
                    int32_t w,
                    int32_t h,
                    int32_t colkey);
PYXEL_API void text(int32_t x, int32_t y, const char* s, int32_t col);

//
// Audio
//
PYXEL_API void* sound(int32_t snd, int32_t system);
PYXEL_API void* music(int32_t msc);
PYXEL_API void play(int32_t ch, int32_t snd, int32_t loop);
PYXEL_API void playm(int32_t msc, int32_t loop);
PYXEL_API void stop(int32_t ch);

//
// Image class
//
PYXEL_API int32_t image_width_getter(void* self);
PYXEL_API int32_t image_height_getter(void* self);
PYXEL_API int32_t* image_data_getter(void* self);

PYXEL_API int32_t image_get(void* self, int32_t x, int32_t y);
PYXEL_API void image_set1(void* self, int32_t x, int32_t y, int32_t col);
PYXEL_API void image_set(void* self,
                         int32_t x,
                         int32_t y,
                         const char** col,
                         int32_t col_count);
PYXEL_API void image_load(void* self,
                          int32_t x,
                          int32_t y,
                          const char* filename);
PYXEL_API void image_copy(void* self,
                          int32_t x,
                          int32_t y,
                          int32_t img,
                          int32_t u,
                          int32_t v,
                          int32_t w,
                          int32_t h);

//
// Tilemap class
//
PYXEL_API int32_t tilemap_width_getter(void* self);
PYXEL_API int32_t tilemap_height_getter(void* self);
PYXEL_API int32_t* tilemap_data_getter(void* self);
PYXEL_API int32_t tilemap_refimg_getter(void* self);
PYXEL_API void tilemap_refimg_setter(void* self, int32_t refimg);

PYXEL_API int32_t tilemap_get(void* self, int32_t x, int32_t y);
PYXEL_API void timemap_set1(void* self, int32_t x, int32_t y, int32_t val);
PYXEL_API void timemap_set(void* self,
                           int32_t x,
                           int32_t y,
                           const char** val,
                           int32_t val_count);
PYXEL_API void timemap_copy(void* self,
                            int32_t x,
                            int32_t y,
                            int32_t tm,
                            int32_t u,
                            int32_t v,
                            int32_t w,
                            int32_t h);

//
// Sound class
//
PYXEL_API int32_t* sound_note_getter(void* self, int32_t* length);
PYXEL_API void sound_note_setter(void* self,
                                 const int32_t* data,
                                 int32_t length);
PYXEL_API int32_t* sound_tone_getter(void* self, int32_t* length);
PYXEL_API void sound_tone_setter(void* self,
                                 const int32_t* data,
                                 int32_t length);
PYXEL_API int32_t* sound_volume_getter(void* self, int32_t* length);
PYXEL_API void sound_volume_setter(void* self,
                                   const int32_t* data,
                                   int32_t length);
PYXEL_API int32_t* sound_effect_getter(void* self, int32_t* length);
PYXEL_API void sound_effect_setter(void* self,
                                   const int32_t* data,
                                   int32_t length);
PYXEL_API int32_t sound_speed_getter(void* self);
PYXEL_API void sound_speed_setter(void* self, int32_t speed);

PYXEL_API void sound_set(void* self,
                         const char* note,
                         const char* tone,
                         const char* volume,
                         const char* effect,
                         int32_t speed);
PYXEL_API void sound_set_note(void* self, const char* data);
PYXEL_API void sound_set_tone(void* self, const char* data);
PYXEL_API void sound_set_volume(void* self, const char* data);
PYXEL_API void sound_set_effect(void* self, const char* data);

//
// Music class
//
PYXEL_API int32_t* music_ch0_getter(void* self, int32_t* length);
PYXEL_API void music_ch0_setter(void* self,
                                const int32_t* data,
                                int32_t length);
PYXEL_API int32_t* music_ch1_getter(void* self, int32_t* length);
PYXEL_API void music_ch1_setter(void* self,
                                const int32_t* data,
                                int32_t length);
PYXEL_API int32_t* music_ch2_getter(void* self, int32_t* length);
PYXEL_API void music_ch2_setter(void* self,
                                const int32_t* data,
                                int32_t length);
PYXEL_API int32_t* music_ch3_getter(void* self, int32_t* length);
PYXEL_API void music_ch3_setter(void* self,
                                const int32_t* data,
                                int32_t length);

PYXEL_API void music_set(void* msc,
                         const int32_t* ch0,
                         int32_t ch0_length,
                         const int32_t* ch1,
                         int32_t ch1_length,
                         const int32_t* ch2,
                         int32_t ch2_length,
                         const int32_t* ch3,
                         int32_t ch3_length);
PYXEL_API void music_set_ch0(void* self, const int32_t* data, int32_t length);
PYXEL_API void music_set_ch1(void* self, const int32_t* data, int32_t length);
PYXEL_API void music_set_ch2(void* self, const int32_t* data, int32_t length);
PYXEL_API void music_set_ch3(void* self, const int32_t* data, int32_t length);

//
// Utilities
//
PYXEL_API int32_t get_constant_number(const char* name);
PYXEL_API const char* get_constant_string(const char* name);

#ifdef __cplusplus
}
#endif

#endif  // PYXELCORE_H_
