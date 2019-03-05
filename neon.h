//
//  neon.h
//
//  Created by liaogang on 2019/2/18.
//  Copyright © 2019 liaogang. All rights reserved.
//

#include "defs.h"

struct int8x8_t {
    int8 val[8];
};

struct uint8x8_t {
    uint8 val[8];
};

struct uint16x8_t {
    uint16 val[8];
};

struct int16x8_t {
    int16 val[8];
};

struct int8x16_t {
    int8 val[16];
};
struct uint8x16_t {
    uint8 val[16];
};

struct uint32x4_t {
    uint32 val[4];
};

struct int32x4_t {
    int32 val[4];
};

struct int16x4_t {
    int16 val[4];
};

struct uint16x4_t {
    uint16 val[4];
};

struct int8x16x2_t{
    int8x16_t val[2];
};


uint16x8_t vmovl_high_u8(uint8x16_t t);

uint32x4_t vmovl_u16(uint16x4_t t);

uint32x4_t vmovl_high_u16 (uint16x8_t a);

int8x16_t vmovl_high_u16_1 (uint16x8_t a);

uint8x16_t vcgtq_u8(uint8x16_t a,uint8x16_t b);

uint8x16_t vcgeq_u8 (uint8x16_t a, uint8x16_t b);

uint32x4_t vcgtq_u32(uint32x4_t a, uint32x4_t b);

uint32x4_t vcgtq_u32(uint32x4_t a, int32x4_t b1);

uint8x16_t vcgtq_u32_1(uint32x4_t a, uint32x4_t b);

int16x8_t vmovl_s8(int8x8_t t);

int8x16_t vmvnq_s8 (int8x16_t a);

int16x8_t vmovl_high_s8(int8x16_t t);

uint16x8_t vmovl_u8(uint8x8_t t);

int32x4_t vmovl_high_s16 (int16x8_t t);

int32x4_t vmovl_s16(int16x4_t t);

uint32x4_t vsraq_n_u32(uint32x4_t a, uint32x4_t b, const int n);

uint32x4_t vsraq_n_u32(int8x16_t a1, uint32x4_t b, const int n);

uint32x4_t vsraq_n_u32(int8x16_t a1, int8x16_t b1, const int n);

uint32x4_t vsraq_n_u32(uint8x16_t a1, int8x16_t b1, const int n);

uint8 bitselect(uint8 t, uint8 a, uint8 b);

int8x16_t vbslq_s8(uint8x16_t t, int8x16_t a, int8x16_t b);

int8x16_t vbslq_s8(uint32x4_t t1, int8x16_t a, int8x16_t b);

int8x16_t vbslq_s8(int32x4_t t1, int8x16_t a, int8x16_t b);

int16x8_t vmovn_s32(int32x4_t t);

int16x8_t vmovn_s32(uint32x4_t t1);

int16x4_t vmovn_s32_another(int32x4_t t);

int8x8_t vmovn_s16(int16x8_t a);

int8x16_t vmovn_high_s16(int8x8_t r, int16x8_t a);

int16x8_t vmovn_high_s32_(int16x8_t r, int32x4_t a);

int16x8_t vmovn_high_s32(int16x4_t r, int32x4_t a);

int8x16_t vandq_s8 (int8x16_t a, int8x16_t b);

int32x4_t vandq_s8_1(int8x16_t a, int8x16_t b);

int32x4_t vandq_s32(int32x4_t a, int32x4_t b);

int32x4_t vaddq_s32 (int32x4_t a, int32x4_t b);

int32x4_t vaddq_s32 (int8x16_t a1, int32x4_t b);

int8x16_t vaddq_s8 (int8x16_t a, int8x16_t b);

int32x4_t vaddw_s16 (int32x4_t a, int16x4_t b);

int32x4_t vaddw_high_s16 (int32x4_t a, int16x8_t b);

void vst2q_s8(int8 * ptr, int8x16x2_t t);

int8x16x2_t vld2q_s8 (int8 const * ptr);

int8x16_t vorrq_s8 (int8x16_t a, int8x16_t b);

int32x4_t vshlq_n_s32 (int32x4_t a, const int n);

