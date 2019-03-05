//
//  neon.cpp
//
//  Created by liaogang on 2019/2/18.
//  Copyright © 2019 liaogang. All rights reserved.
//

#include "neon.h"

int8 bit_unextension_s16(int16 t)
{
    int8 r;
    
    r = 0xFFFF & t;
    
    return r;
}

int16 bit_unextension_s32(int32 t)
{
    int16 r;
    
    r = 0xFFFFFFFF & t;
    
    return r;
}


//zero extension from 8 to 16 bit
uint16 bit_extension_u8( uint8 t)
{
    int16 r;
    
    r = 0x0000 | t;
    
    return r;
}

//sign ....
int16 bit_extension_s8( int8 t)
{
    int16 r;
    
    if ( t > 0 ) {
        r = 0xffff & t;
    }
    else{
        r = 0x0000 | t;
    }
    
    return r;
}


int32 bit_extension_s16( int16 t)
{
    int32 r;
    
    if ( t > 0 ) {
        r = 0xffffffff & t;
    }
    else{
        r = 0x00000000 | t;
    }
    
    return r;
}


int32 bit_extension_u16( int16 t)
{
    int32 r;
    
    r = 0x00000000 | t;
    
    return r;
}


uint16x8_t vmovl_high_u8(uint8x16_t t)
{
    uint16x8_t result = {0};
    
    for (int i = 0; i < 8; i++) {
        result.val[i] = bit_extension_u8( t.val[i+8] );
    }
    
    return result;
}


uint32x4_t vmovl_u16(uint16x4_t t)
{
    uint32x4_t result = {0};
    
    for (int i = 0; i < 4; i++) {
        result.val[i] = bit_extension_u16( t.val[i] );
    }
    
    return result;
}


uint32x4_t vmovl_high_u16 (uint16x8_t a)
{
    uint32x4_t result = {0};
    
    for (int i = 0; i < 4; i++) {
        result.val[i] = bit_extension_u16( a.val[i+4] );
    }
    
    return result;
}

int8x16_t vmovl_high_u16_1 (uint16x8_t a)
{
    uint32x4_t result = vmovl_high_u16(a);
    
    int8x16_t result2 = *(int8x16_t*)&result;
    
    return result2;
}


uint8x16_t vcgtq_u8(uint8x16_t a,uint8x16_t b)
{
    uint8x16_t result = {0};
    
    for (int i = 0; i < 16; i++) {
        result.val[i] = a.val[i]>b.val[i] ? 0xff : 0x00;
    }
    
    return result;
}

/**
 CGE　大于或等于
 CMHS Vd.16B,Vm.16B,Vn.16B
*/
uint8x16_t vcgeq_u8 (uint8x16_t a, uint8x16_t b)
{
    uint8x16_t result = {0};
    
    for (int i = 0; i < 16; i++) {
        result.val[i] = a.val[i]>=b.val[i] ? 0xff : 0x00;
    }
    
    return result;
}

uint32x4_t vcgtq_u32(uint32x4_t a, uint32x4_t b)
{
    uint32x4_t result = {0};
    
    for (int i = 0; i < 4; i++) {
        result.val[i] = a.val[i]>b.val[i] ? 0xffffffff : 0x00000000;
    }
    
    return result;
}

uint32x4_t vcgtq_u32(uint32x4_t a, int32x4_t b1)
{
    uint32x4_t b = *(uint32x4_t*)&b1;
    
    
    uint32x4_t result = {0};
    
    for (int i = 0; i < 4; i++) {
        result.val[i] = a.val[i]>b.val[i] ? 0xffffffff : 0x00000000;
    }
    
    return result;
}

uint8x16_t vcgtq_u32_1(uint32x4_t a, uint32x4_t b)
{
    uint32x4_t result = vcgtq_u32(a, b);
    uint8x16_t r2 = *(uint8x16_t*)&result;
    
    return r2;
}

int16x8_t vmovl_s8(int8x8_t t)
{
    int16x8_t result = {0};
    
    for (int i = 0; i < 8; i++) {
        result.val[i] = bit_extension_s8( t.val[i] );
    }
    
    return result;
}


/**
 Vector Move Not (register) inverts the value of each bit from the source register and places the results into the destination register.

 (0x05, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00)
 ->
 (0xfa, 0xff, 0xff, 0xff, 0xcc, 0xff, 0xff, 0xff, 0xf6, 0xff, 0xff, 0xff, 0xce, 0xff, 0xff, 0xff)
 */
int8x16_t vmvnq_s8 (int8x16_t a)
{
    for (int i = 0; i < 16; i++) {
        a.val[i] = ~a.val[i] ;
    }
    
    return a;
}

int16x8_t vmovl_high_s8(int8x16_t t)
{
    int16x8_t result = {0};
    
    for (int i = 0; i < 8; i++) {
        result.val[i] = bit_extension_s8( t.val[i+8] );
    }
    
    return result;
}


uint16x8_t vmovl_u8(uint8x8_t t)
{
    uint16x8_t result = {0};
    
    for (int i = 0; i < 8; i++) {
        result.val[i] = bit_extension_u8( t.val[i] );
    }
    
    return result;
}


int32x4_t vmovl_high_s16 (int16x8_t t)
{
    int32x4_t result = {0};
    
    for (int i = 0; i < 4; i++) {
        result.val[i] = bit_extension_s16( t.val[i+4] );
    }
    
    return result;
}


int32x4_t vmovl_s16(int16x4_t t)
{
    int32x4_t result = {0};
    
    for (int i = 0; i < 4; i++) {
        result.val[i] = bit_extension_s16( t.val[i] );
    }
    
    return result;
}


uint32x4_t vsraq_n_u32(uint32x4_t a, uint32x4_t b, const int n)
{
    uint32x4_t result = {0};
    
    for (int i = 0; i < 4; i++) {
        uint32 bb = b.val[i];
        uint32 tmp = bb >> n;
        result.val[i] = tmp + a.val[i];
    }
    
    return result;
}


uint32x4_t vsraq_n_u32(int8x16_t a1, uint32x4_t b, const int n)
{
    uint32x4_t a = *(uint32x4_t*)&a1;
    return vsraq_n_u32(a, b, n);
}


uint32x4_t vsraq_n_u32(int8x16_t a1, int8x16_t b1, const int n)
{
    uint32x4_t a = *(uint32x4_t*)&a1;
    uint32x4_t b = *(uint32x4_t*)&b1;
    
    return vsraq_n_u32(a, b, n);
}

uint32x4_t vsraq_n_u32(uint8x16_t a1, int8x16_t b1, const int n)
{
    uint32x4_t a = *(uint32x4_t*)&a1;
    uint32x4_t b = *(uint32x4_t*)&b1;
    
    return vsraq_n_u32(a, b, n);
}

uint8 bitselect(uint8 t, uint8 a, uint8 b)
{
    uint8 result = 0;
    
    for (int i = 0; i < 16 ; i++ ) {
        uint8 flag = 0x01 << i;
        result |= (t & flag) ? (a & flag) : (b & flag);
    }
    
    return result;
}


int8x16_t vbslq_s8(uint8x16_t t, int8x16_t a, int8x16_t b)
{
    int8x16_t result = {0};
    
    for (int i = 0; i < 16; i++) {
        result.val[i] = bitselect( t.val[i] , a.val[i] , b.val[i] );
    }
    
    return result;
}


int8x16_t vbslq_s8(uint32x4_t t1, int8x16_t a, int8x16_t b)
{
    uint8x16_t t = *(uint8x16_t*)&t1;
    
    int8x16_t result = {0};
    
    for (int i = 0; i < 16; i++) {
        result.val[i] = bitselect( t.val[i] , a.val[i] , b.val[i] );
    }
    
    return result;
}

int8x16_t vbslq_s8(int32x4_t t1, int8x16_t a, int8x16_t b)
{
    uint8x16_t t = *(uint8x16_t*)&t1;
    
    int8x16_t result = {0};
    
    for (int i = 0; i < 16; i++) {
        result.val[i] = bitselect( t.val[i] , a.val[i] , b.val[i] );
    }
    
    return result;
}


//uint32x4_t vbslq_s8_1(int32x4_t t1, int8x16_t a, int8x16_t b)
//{
//    uint8x16_t t = *(uint8x16_t*)&t1;
//    
//    int8x16_t result = vbslq_s8(t, a, b);
//    
//    uint32x4_t r2 = *(uint32x4_t*)&result;
//    
//    return r2;
//}


int16x8_t vmovn_s32(int32x4_t t)
{
    int16x8_t result = {0};
    
    for (int i = 0; i < 4; i++) {
        result.val[i] = bit_unextension_s32(t.val[i]);
    }
    
    return result;
}


int16x8_t vmovn_s32(uint32x4_t t1)
{
    int32x4_t t = *(int32x4_t*)&t1;
    int16x8_t result = {0};
    
    for (int i = 0; i < 4; i++) {
        result.val[i] = bit_unextension_s32(t.val[i]);
    }
    
    return result;
}


int16x4_t vmovn_s32_another(int32x4_t t)
{
    int16x8_t result = vmovn_s32(t);
    
    int16x4_t *result2 = (int16x4_t*)&result;
    
    return *result2;
}


int8x8_t vmovn_s16(int16x8_t a)
{
    int8x8_t result = {0};
    
    for (int i = 0; i < 8; i++) {
        result.val[i] = bit_unextension_s16(a.val[i]);
    }
    
    return result;
}


int8x16_t vmovn_high_s16(int8x8_t r, int16x8_t a)
{
    int8x16_t result = {0};
    
    for (int i = 0; i < 8; i++) {
        result.val[i] = r.val[i];
    }
    
    for (int i = 0; i < 8; i++) {
        result.val[8+i] = bit_unextension_s16(a.val[i]);
    }
    
    return result;
}


int16x8_t vmovn_high_s32_(int16x8_t r, int32x4_t a)
{
    int16x8_t result = {0};
    
    for (int i = 0; i < 4; i++) {
        result.val[i] = r.val[i];
    }
    
    for (int i = 0; i < 4; i++) {
        result.val[4+i] = bit_unextension_s32(a.val[i]);
    }
    
    return result;
}

int16x8_t vmovn_high_s32(int16x4_t r, int32x4_t a)
{
    int16x8_t result = {0};
    
    for (int i = 0; i < 4; i++) {
        result.val[i] = r.val[i];
    }
    
    for (int i = 0; i < 4; i++) {
        result.val[4+i] = bit_unextension_s32(a.val[i]);
    }
    
    return result;
}


int8x16_t vandq_s8 (int8x16_t a, int8x16_t b)
{
    for (int i = 0; i < 16; i++) {
        a.val[i] = a.val[i] & b.val[i];
    }
    
    return a;
}

int32x4_t vandq_s8_1(int8x16_t a, int8x16_t b)
{
    int8x16_t r = vandq_s8(a, b);
    int32x4_t r2 = *(int32x4_t*)&r;
    return r2;
}

int32x4_t vandq_s32(int32x4_t a, int32x4_t b)
{
    for (int i = 0; i < 4; i++) {
        a.val[i] = a.val[i] & b.val[i];
    }
    
    return a;
}


int32x4_t vaddq_s32 (int32x4_t a, int32x4_t b)
{
    for (int i = 0; i < 4; i++) {
        a.val[i] = a.val[i] + b.val[i];
    }
    
    return a;
}

int32x4_t vaddq_s32 (int8x16_t a1, int32x4_t b)
{
    int32x4_t a = *(int32x4_t*)&a1;
    
    for (int i = 0; i < 4; i++) {
        a.val[i] = a.val[i] + b.val[i];
    }
    
    return a;
}

int8x16_t vaddq_s8 (int8x16_t a, int8x16_t b)
{
    for (int i = 0; i < 16; i++) {
        a.val[i] = a.val[i] + b.val[i];
    }
    
    return a;
}

/** w 宽型运算
 @see http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dui0473m/dom1359731190431.html
 
 (0xd0, 0xff, 0xff, 0xff,   0xd0, 0xff, 0xff, 0xff,   0xd0, 0xff, 0xff, 0xff,  0xd0, 0xff, 0xff, 0xff)
 (0x35, 0x00,                0x63, 0x00,              0x39, 0x00,              0x61, 0x00,                                                     0x32, 0x00, 0x33, 0x00,  0x64, 0x00, 0x35, 0x00)
 = 溢出了
 (0x05, 0x00, 0x00, 0x00,   0x33, 0x00, 0x00, 0x00,   0x09, 0x00, 0x00, 0x00,  0x31, 0x00, 0x00, 0x00)
 */
int32x4_t vaddw_s16 (int32x4_t a, int16x4_t b)
{
    for (int i = 0; i < 4; i++) {
        a.val[i] = a.val[i] + b.val[i];
    }

    return a;
}

int32x4_t vaddw_high_s16 (int32x4_t a, int16x8_t b)
{
    for (int i = 0; i < 4; i++) {
        a.val[i] = a.val[i] + b.val[i+4];
    }
    
    return a;
}


/*Store N-element structure to memory
 */
void vst2q_s8(int8 * ptr, int8x16x2_t t)
{
    int index = 0;
    for (int i = 0; i < 16; i++) {
        ptr[index++] = t.val[0].val[i];
        ptr[index++] = t.val[1].val[i];
        
//        ptr.val[index++] = val.val.val[0].val[i];
//        ptr.val[index++] = val.val.val[1].val[i];
    }
    
}





/*
  (0xa3, 0x01, 0x66, 0x01, 0x8f, 0x01, 0x0a, 0x01, 0xfa, 0x01, 0xc7, 0x01, 0x2c, 0x01, 0xa3, 0x01)
  (0x29, 0x01, 0x00, 0x00, 0xe0, 0x01, 0x00, 0x00, 0xe1, 0x01, 0x00, 0x00, 0xbb, 0x01, 0x00, 0x00)
 0x12775fbf1: 0x66656631 0x30626134 0x33353832 0x39623931
 0x12775fc01: 0x33636135 0x34616639 0x38336332 0x66353064
 
 ---
 (0x31, 0x65, 0x34, 0x62, 0x32, 0x35, 0x31, 0x62, 0x35, 0x63, 0x39, 0x61, 0x32, 0x33, 0x64, 0x35)
 (0x66, 0x66, 0x61, 0x30, 0x38, 0x33, 0x39, 0x39, 0x61, 0x33, 0x66, 0x34, 0x63, 0x38, 0x30, 0x66)
 
 1 3 5
 2 4
 */
int8x16x2_t vld2q_s8 (int8 const * ptr)
{
    int8x16x2_t r = {0};

    int row0Index = 0;
    int row1Index = 0;
    
    for (int i = 0; i < 16*2; i++) {
        if ( i % 2 == 0) {
            r.val[0].val[row0Index++] = ptr[i];
        }
        else{
            r.val[1].val[row1Index++] = ptr[i];
        }
    }

    return r;
}

//int32x4_t vdupq_n_s32 (int32_t value);





/**
 Bitwise OR
 */
int8x16_t vorrq_s8 (int8x16_t a, int8x16_t b)
{
    for (int i = 0; i < 16; i++) {
        a.val[i] |= b.val[i];
    }
    return a;
}

/**
 Vector Shift Left
 SHL Vd.4S,Vn.4S,#n
 
 (0x0f, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00)
 ->
 0xf0, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00)
 */
int32x4_t vshlq_n_s32 (int32x4_t a, const int n)
{
    for (int i = 0; i < 4; i++) {
        a.val[i] = a.val[i] << n;
    }

    return a;
}
