#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define SIGN 0x80000000

enum returns { OK, INF, NEGATIVE_INF, DIVISION_BY_ZERO };
enum converts { SUCCESS, CONVERTING_ERROR };

typedef struct {
    unsigned int bits[4];
} s21_decimal;

typedef union {
  int ui;
  float fl;
} floatbits;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

int get_bit(const s21_decimal decVar, int bit);
int get_sign(const s21_decimal *varPtr);
int get_scale(const s21_decimal *varPtr);
void scale_equalize(s21_decimal *number_1, s21_decimal *number_2);
int last_bit(s21_decimal number);
void bits_copy(s21_decimal src, s21_decimal *dest);
void convert_to_addcode(s21_decimal *number_1);
void set_scale(s21_decimal *varPtr, int scale);
int offset_left(s21_decimal *varPtr, int value_offset);
void init_struct(s21_decimal *varPtr);
void set_bit(s21_decimal *varPtr, int bit, int value);
void set_sign(s21_decimal *varPtr, int sign);
void clear_bits(s21_decimal *varPtr);
int bit_addition(s21_decimal var1, s21_decimal var2, s21_decimal* result);
void div_only_bits(s21_decimal a, s21_decimal b, s21_decimal *buf,
                          s21_decimal *result);
void sub_only_bits(s21_decimal number_1, s21_decimal number_2, s21_decimal* result);
void add_only_bits(s21_decimal number_1, s21_decimal number_2, s21_decimal* result);
s21_decimal check_for_mul(s21_decimal number_1, s21_decimal number_2);
s21_decimal check_for_add(s21_decimal number_1, s21_decimal number_2);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int get_float_exp(float *src);
int get_float_sign(float *src);
int s21_is_even(s21_decimal dec1);
int is_NAN(s21_decimal *dec1, s21_decimal *dec2);
int zero_check(s21_decimal dec1, s21_decimal dec2);
int is_inf(s21_decimal *dec1, s21_decimal *dec2);
int is_neg_inf(s21_decimal *dec1, s21_decimal *dec2);
int is_negative(s21_decimal *dec1, s21_decimal *dec2);
void check_scale(s21_decimal *dec1, s21_decimal *dec2);
void minus_scale(s21_decimal* a);

#endif  // SRC_S21_DECIMAL_H_
