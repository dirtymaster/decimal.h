#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_decimal.h"

START_TEST(s21_is_greater_1) {
    s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    int return_value = s21_is_greater(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_greater_2) {
    s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    set_sign(&value_1, 1);
    int return_value = s21_is_greater(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_is_greater_3) {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    set_sign(&value_2, 1);
    int return_value = s21_is_greater(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_greater_4) {
    s21_decimal value_1 = {{0, 0, 0, 0}};
    s21_decimal value_2 = {{0, 0, 0, 0}};
    set_sign(&value_2, 1);
    int return_value = s21_is_greater(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_greater_5) {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    set_sign(&value_1, 1);
    set_sign(&value_2, 1);
    int return_value = s21_is_greater(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_greater_6) {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    set_scale(&value_2, 10);
    int return_value = s21_is_greater(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_greater_7) {
    s21_decimal value_1 = {{234, 0, 0, 0}};
    s21_decimal value_2 = {{2, 0, 0, 0}};
    set_scale(&value_1, 2);
    int return_value = s21_is_greater(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_equal_1) {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
    int return_value = s21_is_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_equal_2) {
    s21_decimal value_1 = {{123453u, 654u, 0xFFFFFFFF, 80000000}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
    int return_value = s21_is_equal(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_is_equal_3) {
    s21_decimal value_1 = {{0, 0, 0, 0}};
    s21_decimal value_2 = {{0, 0, 0, 0x80000000}};
    int return_value = s21_is_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_equal_4) {
    s21_decimal value_1 = {{2, 0, 0, 0}};
    s21_decimal value_2 = {{20, 0, 0, 0}};
    set_scale(&value_2, 1);
    int return_value = s21_is_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_1) {
    s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    int return_value = s21_is_greater_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_2) {
    s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    set_sign(&value_1, 1);
    int return_value = s21_is_greater_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_3) {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    set_sign(&value_2, 1);
    int return_value = s21_is_greater_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_4) {
    s21_decimal value_1 = {{0, 0, 0, 0}};
    s21_decimal value_2 = {{0, 0, 0, 0}};
    set_sign(&value_2, 1);
    int return_value = s21_is_greater_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_5) {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    set_sign(&value_1, 1);
    set_sign(&value_2, 1);
    int return_value = s21_is_greater_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_6) {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    set_scale(&value_2, 2);
    int return_value = s21_is_greater_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_7) {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    int return_value = s21_is_greater_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_greater_or_equal_8) {
    s21_decimal value_1 = {{12345, 0, 0, 0}};
    set_scale(&value_1, 4);
    s21_decimal value_2 = {{12u, 0, 0, 0}};
    set_scale(&value_1, 1);
    int return_value = s21_is_greater_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_less_1) {
    s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    int return_value = s21_is_less(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_is_less_2) {
    s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    set_sign(&value_1, 1);
    int return_value = s21_is_less(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_less_3) {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    set_sign(&value_2, 1);
    int return_value = s21_is_less(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_is_less_4) {
    s21_decimal value_1 = {{0, 0, 0, 0}};
    s21_decimal value_2 = {{0, 0, 0, 0}};
    set_sign(&value_2, 1);
    int return_value = s21_is_less(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_is_less_5) {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    set_sign(&value_1, 1);
    set_sign(&value_2, 1);
    int return_value = s21_is_less(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_is_less_6) {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    set_scale(&value_2, 2);
    int return_value = s21_is_less(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_1) {
    s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    int return_value = s21_is_less_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_2) {
    s21_decimal value_1 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    set_sign(&value_1, 1);
    int return_value = s21_is_less_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_3) {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    set_sign(&value_2, 1);
    int return_value = s21_is_less_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_4) {
    s21_decimal value_1 = {{0, 0, 0, 0}};
    s21_decimal value_2 = {{0, 0, 0, 0}};
    set_sign(&value_2, 1);
    int return_value = s21_is_less_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_less_or_equal_5) {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123457u, 654u, 0xFFFFFFFF, 0}};
    set_sign(&value_1, 1);
    set_sign(&value_2, 1);
    int return_value = s21_is_less_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_6) {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    set_scale(&value_2, 2);
    int return_value = s21_is_less_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_is_less_or_equal_7) {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 0}};
    int return_value = s21_is_less_or_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_1) {
    s21_decimal value_1 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
    int return_value = s21_is_not_equal(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_is_not_equal_2) {
    s21_decimal value_1 = {{123453u, 654u, 0xFFFFFFFF, 80000000}};
    s21_decimal value_2 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
    int return_value = s21_is_not_equal(value_1, value_2);
    ck_assert_int_eq(return_value, TRUE);
}
END_TEST

START_TEST(s21_is_not_equal_3) {
    s21_decimal value_1 = {{0, 0, 0, 80000000}};
    s21_decimal value_2 = {{0, 0, 0, 0}};
    int return_value = s21_is_not_equal(value_1, value_2);
    ck_assert_int_eq(return_value, FALSE);
}
END_TEST

START_TEST(s21_add_1) {
    s21_decimal value_1 = {{13, 0, 0, 0}};
    set_scale(&value_1, 1);
    s21_decimal value_2 = {{286, 0, 0, 0}};
    set_scale(&value_2, 2);
    s21_decimal result;
    s21_decimal check = {{416, 0, 0, 0}};
    set_scale(&check, 2);
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_add_2) {
    s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    set_sign(&value_2, 1);
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal check = {{0, 0, 0, 0}};
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_add_3) {
    s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0, 0}};
    set_scale(&value_1, 1);
    s21_decimal value_2 = {{2, 0, 0, 0}};
    set_scale(&value_2, 1);
    s21_decimal result;
    s21_decimal check = {{0x1, 0x0, 0x1, 0}};
    set_scale(&check, 1);
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_add_4) {
    s21_decimal value_1 = {{13, 0, 0, 0}};
    set_scale(&value_1, 2);
    s21_decimal value_2 = {{286, 0, 0, 0}};
    set_scale(&value_2, 1);
    s21_decimal result;
    s21_decimal check = {{2873, 0, 0, 0}};
    set_scale(&check, 2);
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_add_5) {
    s21_decimal value_1 = {{1, 0, 0, 0}};
    s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    set_scale(&value_2, 1);
    s21_decimal result;
    s21_decimal check = {{0x9999999a, 0x99999999, 0x19999999, 0}};
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_add_6) {
    s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    set_scale(&value_1, 1);
    s21_decimal value_2 = {{1, 0, 0, 0}};
    s21_decimal result;
    s21_decimal check = {{0x9999999a, 0x99999999, 0x19999999, 0}};
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_add_7) {
    s21_decimal value_1 = {{1, 0, 0, 0}};
    s21_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    s21_decimal result;
    s21_decimal check = {{0, 0, 0, 0}};
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, INF);
}
END_TEST

START_TEST(s21_add_8) {
    s21_decimal value_1 = {{13, 0, 0, 0}};
    set_scale(&value_1, 2);
    set_sign(&value_1, 1);
    s21_decimal value_2 = {{286, 0, 0, 0}};
    set_scale(&value_2, 1);
    s21_decimal result;
    s21_decimal check = {{2847, 0, 0, 0}};
    set_scale(&check, 2);
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_add_9) {
    s21_decimal value_1 = {{13, 0, 0, 0}};
    set_scale(&value_1, 1);
    set_sign(&value_1, 1);
    s21_decimal value_2 = {{286, 0, 0, 0}};
    set_scale(&value_2, 2);
    set_sign(&value_2, 1);
    s21_decimal result;
    s21_decimal check = {{416, 0, 0, 0}};
    set_scale(&check, 2);
    set_sign(&check, 1);
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_add_10) {
    s21_decimal value_1 = {{1614, 0, 0, 0}};
    set_scale(&value_1, 3);
    s21_decimal value_2 = {{46071, 0, 0, 0}};
    set_scale(&value_2, 2);
    s21_decimal result;
    s21_decimal check = {{462324, 0, 0, 0}};
    set_scale(&check, 3);
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_add_11) {
    s21_decimal src1, src2;
    int a = -1234;
    float b = -1.234;
    float res_our_dec = 0.0;
    s21_from_int_to_decimal(a, &src1);
    s21_from_float_to_decimal(b, &src2);
    float res_origin = -1235.234;
    s21_decimal res_od;
    s21_add(src1, src2, &res_od);
    s21_from_decimal_to_float(res_od, &res_our_dec);
    ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_add_12) {
    s21_decimal src1, src2;
    float a = -1234;
    float b = -221.234;
    float res_our_dec = 0.0;
    s21_from_float_to_decimal(a, &src1);
    s21_from_float_to_decimal(b, &src2);
    float res_origin = -1455.234;
    s21_decimal res_od;
    s21_add(src1, src2, &res_od);
    s21_from_decimal_to_float(res_od, &res_our_dec);
    ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_add_13) {
    s21_decimal src1, src2;
    float a = -9403;
    float b = 0.00234;
    float res_our_dec = 0.0;
    s21_from_float_to_decimal(a, &src1);
    s21_from_float_to_decimal(b, &src2);
    float res_origin = -9402.99766;
    s21_decimal res_od;
    s21_add(src1, src2, &res_od);
    s21_from_decimal_to_float(res_od, &res_our_dec);
    ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_add_14) {
    s21_decimal src1, src2;
    float a = -0.94e03;
    float b = -112.0e2;
    float res_our_dec = 0.0;
    s21_from_float_to_decimal(a, &src1);
    s21_from_float_to_decimal(b, &src2);
    float res_origin = -12140;
    s21_decimal res_od;
    s21_add(src1, src2, &res_od);
    s21_from_decimal_to_float(res_od, &res_our_dec);
    ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_add_15) {
    s21_decimal src1, src2;
    src1.bits[3] = 0x300000;
    src1.bits[2] = 0;
    src1.bits[1] = 0xF;
    src1.bits[0] = 0x67E4FEEF;
    src2.bits[3] = 0x300000;
    src2.bits[2] = 0;
    src2.bits[1] = 0xFF;
    src2.bits[0] = 0x67E4FFFF;
    s21_decimal result_origin;
    result_origin.bits[3] = 0x300000;
    result_origin.bits[2] = 0;
    result_origin.bits[1] = 0x10E;
    result_origin.bits[0] = 0xCFC9FEEE;
    s21_decimal result_our;
    s21_add(src1, src2, &result_our);
    ck_assert_int_eq(result_origin.bits[3], result_our.bits[3]);
    ck_assert_int_eq(result_origin.bits[2], result_our.bits[2]);
    ck_assert_int_eq(result_origin.bits[1], result_our.bits[1]);
    ck_assert_int_eq(result_origin.bits[0], result_our.bits[0]);
}
END_TEST

START_TEST(s21_add_16) {
    s21_decimal src1, src2;
    src1.bits[3] = 0x80030000;
    src1.bits[2] = 0;
    src1.bits[1] = 0xFFFF;
    src1.bits[0] = 0xFF837E4F;
    src2.bits[3] = 0x70000;
    src2.bits[2] = 0;
    src2.bits[1] = 0xFFF;
    src2.bits[0] = 0xFF837E4F;
    s21_decimal result_origin;
    result_origin.bits[3] = 0x80070000;
    result_origin.bits[2] = 0;
    result_origin.bits[1] = 0x270FEFED;
    result_origin.bits[0] = 0x00F26FA1;
    s21_decimal result_our;
    s21_add(src1, src2, &result_our);
    ck_assert_int_eq(result_origin.bits[3], result_our.bits[3]);
    ck_assert_int_eq(result_origin.bits[2], result_our.bits[2]);
    ck_assert_int_eq(result_origin.bits[1], result_our.bits[1]);
    ck_assert_int_eq(result_origin.bits[0], result_our.bits[0]);
}
END_TEST

START_TEST(s21_sub_1) {
    s21_decimal value_1 = {{13, 0, 0, 0}};
    set_scale(&value_1, 1);
    set_sign(&value_1, 1);
    s21_decimal value_2 = {{286, 0, 0, 0}};
    set_scale(&value_2, 2);
    set_sign(&value_2, 1);
    s21_decimal result;
    s21_decimal check = {{156, 0, 0, 0}};
    set_scale(&check, 2);
    int return_value = s21_sub(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_sub_2) {
    s21_decimal value_1 = {{13, 0, 0, 0}};
    set_scale(&value_1, 1);
    set_sign(&value_1, 1);
    s21_decimal value_2 = {{286, 0, 0, 0}};
    set_scale(&value_2, 2);
    s21_decimal result;
    s21_decimal check = {{416, 0, 0, 0}};
    set_scale(&check, 2);
    set_sign(&check, 1);
    int return_value = s21_sub(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_sub_3) {
    s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    set_sign(&value_1, 1);
    s21_decimal value_2 = {{2, 0, 0, 0}};
    s21_decimal result;
    s21_decimal check = {{0, 0, 0, 0}};
    int return_value = s21_sub(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, NEGATIVE_INF);
}
END_TEST

START_TEST(s21_sub_4) {
    s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    set_sign(&value_1, 1);
    s21_decimal value_2 = {{2, 0, 0, 0}};
    set_sign(&value_2, 1);
    s21_decimal result;
    s21_decimal check = {{0, 0, 0, 0}};
    int return_value = s21_add(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, NEGATIVE_INF);
}
END_TEST

START_TEST(s21_sub_5) {
    s21_decimal value_1 = {{64071, 0, 0, 0}};
    set_scale(&value_1, 4);
    s21_decimal value_2 = {{5919, 0, 0, 0}};
    set_scale(&value_2, 1);
    s21_decimal result;
    s21_decimal check = {{5854929, 0, 0, 0}};
    set_scale(&check, 4);
    set_sign(&check, 1);
    int return_value = s21_sub(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_sub_6) {
    s21_decimal src1, src2;
    float a = -9403;
    float b = 202.098;
    float res_our_dec = 0.0;
    s21_from_float_to_decimal(a, &src1);
    s21_from_float_to_decimal(b, &src2);
    float res_origin = a - b;
    s21_decimal res_od;
    s21_sub(src1, src2, &res_od);
    s21_from_decimal_to_float(res_od, &res_our_dec);
    ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_sub_7) {
    s21_decimal src1, src2;
    src1.bits[3] = 0b00000000000000010000000000000000;
    src1.bits[2] = 0;
    src1.bits[1] = 0;
    src1.bits[0] = 0b00000000000000000110011011110000;
    src2.bits[3] = 0b00000000000000110000000000000000;
    src2.bits[2] = 0;
    src2.bits[1] = 0;
    src2.bits[0] = 0b00000000000001000101000111010110;
    s21_decimal result_origin;
    result_origin.bits[3] = 0b00000000000000110000000000000000;
    result_origin.bits[2] = 0;
    result_origin.bits[1] = 0;
    result_origin.bits[0] = 0b00000000001000111110001111101010;
    s21_decimal result_our;
    s21_sub(src1, src2, &result_our);
    ck_assert_int_eq(result_origin.bits[3], result_our.bits[3]);
    ck_assert_int_eq(result_origin.bits[2], result_our.bits[2]);
    ck_assert_int_eq(result_origin.bits[1], result_our.bits[1]);
    ck_assert_int_eq(result_origin.bits[0], result_our.bits[0]);
}
END_TEST

START_TEST(s21_mul_1) {
    s21_decimal value_1 = {{5, 0, 0, 0}};
    s21_decimal value_2 = {{7, 0, 0, 0}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal check = {{35, 0, 0, 0}};
    int return_value = s21_mul(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_mul_2) {
    s21_decimal value_1 = {{0xFFFFFFFF, 0, 0, 0}};
    s21_decimal value_2 = {{0xFFFFFFFF, 0, 0, 0}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal check = {{1, 0xFFFFFFFE, 0, 0}};
    int return_value = s21_mul(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_mul_3) {
    s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{2, 0, 0, 0}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal check = {{0, 0, 0, 0}};
    int return_value = s21_mul(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, INF);
}
END_TEST

START_TEST(s21_mul_4) {
    s21_decimal value_1 = {{123456u, 123u, 0, 0}};
    s21_decimal value_2 = {{654321u, 654u, 0, 0}};
    set_sign(&value_2, 1);
    set_scale(&value_1, 2);
    set_scale(&value_2, 3);
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal check = {{0xcedabe40, 0x99c0c5d, 0x13a3a, 0x80050000}};
    int return_value = s21_mul(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_mul_5) {
    s21_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
    s21_decimal value_2 = {{2, 0, 0, 0}};
    set_sign(&value_2, 1);
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal check = {{0, 0, 0, 0}};
    int return_value = s21_mul(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, NEGATIVE_INF);
}
END_TEST

START_TEST(s21_mul_6) {
    s21_decimal value_1 = {{17, 0, 0, 0}};
    set_sign(&value_1, 1);
    s21_decimal value_2 = {{0, 0, 0, 0}};
    s21_decimal result;
    s21_decimal check = {{0, 0, 0, 0}};
    int return_value = s21_mul(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_mul_7) {
    s21_decimal src1, src2;
    float a = 9403.0e2;
    float b = 9403.0e2;
    float res_our_dec = 0.0;
    s21_from_float_to_decimal(a, &src1);
    s21_from_float_to_decimal(b, &src2);
    float res_origin = 884164090000;
    s21_decimal res_od;
    s21_mul(src1, src2, &res_od);
    s21_from_decimal_to_float(res_od, &res_our_dec);
    ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_mul_8) {
    s21_decimal src1, src2;
    int a = -32768;
    int b = 32768;
    int res_our_dec = 0;
    s21_from_int_to_decimal(a, &src1);
    s21_from_int_to_decimal(b, &src2);
    int res_origin = -1073741824;
    s21_decimal res_od;
    s21_mul(src1, src2, &res_od);
    s21_from_decimal_to_int(res_od, &res_our_dec);
    ck_assert_int_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_div_1) {
    s21_decimal value_1 = {{35, 0, 0, 0}};
    s21_decimal value_2 = {{5, 0, 0, 0}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal check = {{70, 0, 0, 0}};
    set_scale(&value_1, 1);
    set_scale(&value_2, 2);
    int return_value = s21_div(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_div_2) {
    s21_decimal value_1 = {{0x88888888, 0x88888888, 0x88888888, 0}};
    s21_decimal value_2 = {{0x2, 0, 0, 0}};
    set_sign(&value_2, 1);
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal check = {{0x44444444, 0x44444444, 0x44444444, 0}};
    set_sign(&check, 1);
    int return_value = s21_div(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_div_3) {
    s21_decimal value_1 = {{10, 0, 0, 0}};
    set_sign(&value_1, 1);
    s21_decimal value_2 = {{8, 0, 0, 0}};
    set_sign(&value_2, 1);
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal check = {{125, 0, 0, 0}};
    set_scale(&check, 2);
    int return_value = s21_div(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_div_4) {
    s21_decimal value_1 = {{15, 0, 0, 0}};
    set_sign(&value_1, 1);
    s21_decimal value_2 = {{0, 0, 0, 0}};
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal check = {{0, 0, 0, 0}};
    int return_value = s21_div(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(s21_div_5) {
    s21_decimal value_1 = {{10, 0, 0, 0}};
    s21_decimal value_2 = {{1, 0, 0, 0}};
    set_scale(&value_2, 2);
    s21_decimal result = {{0, 0, 0, 0}};
    s21_decimal check = {{1000u, 0, 0, 0}};
    int return_value = s21_div(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_div_6) {
    s21_decimal src1, src2;
    float a = 9403.0e2;
    int b = 202;
    float res_our_dec = 0.0;
    s21_from_float_to_decimal(a, &src1);
    s21_from_int_to_decimal(b, &src2);
    float res_origin = 4654.950495049504950495049505;
    s21_decimal res_od;
    s21_div(src1, src2, &res_od);
    s21_from_decimal_to_float(res_od, &res_our_dec);
    ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_div_7) {
    s21_decimal src1, src2;
    float a = -9403.0e2;
    float b = -2020.29;
    float res_our_dec = 0.0;
    s21_from_float_to_decimal(a, &src1);
    s21_from_float_to_decimal(b, &src2);
    float res_origin = 465.4282306005573457275935633;
    s21_decimal res_od;
    s21_div(src1, src2, &res_od);
    s21_from_decimal_to_float(res_od, &res_our_dec);
    ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_div_8) {
    s21_decimal src1, src2;
    float a = -9403.0e20;
    float b = 2.28e17;
    float res_our_dec = 0.0;
    s21_from_float_to_decimal(a, &src1);
    s21_from_float_to_decimal(b, &src2);
    float res_origin = a / b;
    s21_decimal res_od;
    s21_div(src1, src2, &res_od);
    s21_from_decimal_to_float(res_od, &res_our_dec);
    ck_assert_float_eq(res_our_dec, res_origin);
}
END_TEST

START_TEST(s21_div_9) {
    s21_decimal src1, src2;
    src1.bits[0] = 0b00010001100000110100010101000111;
    src1.bits[1] = 0b00000000000000101011011100110010;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b00000000000001010000000000000000;
    src2.bits[0] = 0b01111001000001000011011001001011;
    src2.bits[1] = 0b00000000000000000101010011111111;
    src2.bits[2] = 0b00000000000000000000000000000000;
    src2.bits[3] = 0b00000000000001010000000000000000;
    s21_decimal result_origin;
    result_origin.bits[0] = 0b01000111110000001001001101101011;
    result_origin.bits[1] = 0b10111000000101111000101110100000;
    result_origin.bits[2] = 0b00011010011011010111110000110100;
    result_origin.bits[3] = 0b00000000000110110000000000000000;
    s21_decimal res_od;
    s21_div(src1, src2, &res_od);
    float a, b;
    s21_from_decimal_to_float(result_origin, &a);
    s21_from_decimal_to_float(res_od, &b);
    ck_assert_float_eq(a, b);
}
END_TEST

START_TEST(s21_truncate_1) {
    s21_decimal value_1 = {{35, 0, 0, 0}};
    s21_decimal check = {{3, 0, 0, 0}};
    set_scale(&value_1, 1);
    s21_truncate(value_1, &value_1);
    ck_assert_int_eq(s21_is_equal(value_1, check), 1);
}
END_TEST

START_TEST(s21_truncate_2) {
    s21_decimal value_1 = {{123456, 0, 0, 0}};
    set_scale(&value_1, 3);
    set_sign(&value_1, 1);
    s21_decimal check = {{123, 0, 0, 0}};
    set_sign(&check, 1);
    s21_truncate(value_1, &value_1);
    ck_assert_int_eq(s21_is_equal(value_1, check), 1);
}
END_TEST

START_TEST(s21_truncate_3) {
    s21_decimal src1;
    src1.bits[3] = 0x000A0000;
    src1.bits[2] = 0x0;
    src1.bits[1] = 0xFFFFFFFF;
    src1.bits[0] = 0xFFFFFFFF;
    s21_decimal result;
    result.bits[3] = 0x0;
    result.bits[2] = 0x0;
    result.bits[1] = 0x0;
    result.bits[0] = 0x6DF37F67;
    s21_decimal res_od;
    s21_truncate(src1, &res_od);
    ck_assert_float_eq(res_od.bits[0], result.bits[0]);
    ck_assert_float_eq(res_od.bits[1], result.bits[1]);
    ck_assert_float_eq(res_od.bits[2], result.bits[2]);
    ck_assert_float_eq(res_od.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_4) {
    s21_decimal src1;
    src1.bits[0] = 0b00000000000000000000000001101101;
    src1.bits[1] = 0b00000000000011000110010101011011;
    src1.bits[2] = 0b00000000000000000011000000111001;
    src1.bits[3] = 0b00000000000011100000000000000000;
    s21_decimal result;
    result.bits[0] = 0b10000111101111000001011000011110;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b00000000000000000000000000000000;
    s21_decimal res_od;
    s21_truncate(src1, &res_od);
    ck_assert_float_eq(res_od.bits[0], result.bits[0]);
    ck_assert_float_eq(res_od.bits[1], result.bits[1]);
    ck_assert_float_eq(res_od.bits[2], result.bits[2]);
    ck_assert_float_eq(res_od.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_negate_1) {
    s21_decimal value_1 = {{5, 0xFFFFFFFF, 0, 0}};
    set_sign(&value_1, 1);
    s21_decimal check = {{5, 0xFFFFFFFF, 0, 0}};
    s21_decimal result;
    int return_value = s21_negate(value_1, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_negate_2) {
    s21_decimal value_1 = {{1, 1, 1, 0}};
    s21_decimal check = {{1, 1, 1, 0x80000000}};
    s21_decimal result;
    int return_value = s21_negate(value_1, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_negate_3) {
    float a = 10.1234e5;
    float res_a = 0;
    s21_decimal src;
    s21_from_float_to_decimal(a, &src);
    s21_decimal res;
    s21_negate(src, &res);
    s21_from_decimal_to_float(res, &res_a);
    ck_assert_float_eq(-10.1234e5, res_a);
}
END_TEST

START_TEST(s21_mod_1) {
    s21_decimal value_1 = {{46, 0, 0, 0}};
    set_scale(&value_1, 1);
    s21_decimal value_2 = {{123, 0, 0, 0}};
    set_scale(&value_2, 2);
    s21_decimal check = {{91, 0, 0, 0}};
    set_scale(&check, 2);
    s21_decimal result;
    int return_value = s21_mod(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_mod_2) {
    s21_decimal value_1 = {{46, 0, 0, 0}};
    set_scale(&value_1, 1);
    s21_decimal value_2 = {{0, 0, 0, 0}};
    set_scale(&value_2, 2);
    s21_decimal check = {{0, 0, 0, 0}};
    s21_decimal result;
    int return_value = s21_mod(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, DIVISION_BY_ZERO);
}
END_TEST

START_TEST(s21_mod_3) {
    s21_decimal value_1 = {{46, 0, 0, 0}};
    set_scale(&value_1, 1);
    s21_decimal value_2 = {{123, 0, 0, 0}};
    set_scale(&value_2, 2);
    set_sign(&value_2, 1);
    s21_decimal check = {{91, 0, 0, 0}};
    set_scale(&check, 2);
    s21_decimal result;
    int return_value = s21_mod(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_mod_4) {
    s21_decimal value_1 = {{46, 0, 0, 0}};
    set_scale(&value_1, 1);
    set_sign(&value_1, 1);
    s21_decimal value_2 = {{123, 0, 0, 0}};
    set_scale(&value_2, 2);
    s21_decimal check = {{91, 0, 0, 0}};
    set_scale(&check, 2);
    set_sign(&check, 1);
    s21_decimal result;
    int return_value = s21_mod(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_mod_5) {
    s21_decimal value_1 = {{46, 0, 0, 0}};
    set_scale(&value_1, 1);
    set_sign(&value_1, 1);
    s21_decimal value_2 = {{123, 0, 0, 0}};
    set_scale(&value_2, 2);
    set_sign(&value_2, 1);
    s21_decimal check = {{91, 0, 0, 0}};
    set_scale(&check, 2);
    set_sign(&check, 1);
    s21_decimal result;
    int return_value = s21_mod(value_1, value_2, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_mod_6) {
    s21_decimal src1, src2, res_mod;
    int a = -98765;
    int b = 1234;
    int res_origin = a % b;
    int res = 0;
    s21_from_int_to_decimal(a, &src1);
    s21_from_int_to_decimal(b, &src2);
    s21_mod(src1, src2, &res_mod);
    s21_from_decimal_to_int(res_mod, &res);
    ck_assert_int_eq(res_origin, res);
}
END_TEST

START_TEST(s21_mod_7) {
    s21_decimal src1, src2, res_mod;
    float a = 1.2;
    float b = 0.3;
    float res_origin = fmod(a, b);
    float res = 0.0;
    s21_from_float_to_decimal(a, &src1);
    s21_from_float_to_decimal(b, &src2);
    s21_mod(src1, src2, &res_mod);
    s21_from_decimal_to_float(res_mod, &res);
    ck_assert_float_eq(res_origin, res);
}
END_TEST

START_TEST(s21_round_1) {
    s21_decimal value_1 = {{7464923, 0, 0, 0}};
    set_scale(&value_1, 5);
    s21_decimal check = {{75, 0, 0, 0}};
    s21_decimal result;
    int return_value = s21_round(value_1, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_round_2) {
    s21_decimal value_1 = {{7444923, 0, 0, 0}};
    set_scale(&value_1, 5);
    s21_decimal check = {{74, 0, 0, 0}};
    s21_decimal result;
    int return_value = s21_round(value_1, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_round_3) {
    s21_decimal value_1 = {{7464923, 0, 0, 0}};
    set_sign(&value_1, 1);
    set_scale(&value_1, 5);
    s21_decimal check = {{75, 0, 0, 0}};
    set_sign(&check, 1);
    s21_decimal result;
    int return_value = s21_round(value_1, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_round_4) {
    s21_decimal value_1 = {{7444923, 0, 0, 0}};
    set_sign(&value_1, 1);
    set_scale(&value_1, 5);
    s21_decimal check = {{74, 0, 0, 0}};
    set_sign(&check, 1);
    s21_decimal result;
    int return_value = s21_round(value_1, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_round_5) {
    s21_decimal src1;
    src1.bits[0] = 0b01010101001110101110101110110001;
    src1.bits[1] = 0b00001101101101001101101001011111;
    src1.bits[2] = 0b00000000000000000000000000000000;
    src1.bits[3] = 0b10000000000100100000000000000000;
    s21_decimal result;
    result.bits[0] = 0b00000000000000000000000000000001;
    result.bits[1] = 0b00000000000000000000000000000000;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    s21_decimal res_od;
    s21_round(src1, &res_od);
    ck_assert_float_eq(res_od.bits[0], result.bits[0]);
    ck_assert_float_eq(res_od.bits[1], result.bits[1]);
    ck_assert_float_eq(res_od.bits[2], result.bits[2]);
    ck_assert_float_eq(res_od.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_round_6) {
    s21_decimal src1;
    src1.bits[0] = 0b10010111011100111001111111111111;
    src1.bits[1] = 0b00111100000010000011000110001101;
    src1.bits[2] = 0b00000000000000000000000000000001;
    src1.bits[3] = 0b10000000000001110000000000000000;
    s21_decimal res_od;
    s21_round(src1, &res_od);
    s21_decimal result;
    result.bits[3] = 0b10000000000000000000000000000000;
    result.bits[2] = 0;
    result.bits[1] = 0b00000000000000000000001000010010;
    result.bits[0] = 0b00110110101101101000110001000000;
    ck_assert_float_eq(res_od.bits[0], result.bits[0]);
    ck_assert_float_eq(res_od.bits[1], result.bits[1]);
    ck_assert_float_eq(res_od.bits[2], result.bits[2]);
    ck_assert_float_eq(res_od.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_1) {
    s21_decimal value_1 = {{7444923, 0, 0, 0}};
    set_scale(&value_1, 5);
    s21_decimal check = {{74, 0, 0, 0}};
    s21_decimal result;
    int return_value = s21_floor(value_1, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_floor_2) {
    s21_decimal value_1 = {{7444923, 0, 0, 0}};
    set_scale(&value_1, 5);
    set_sign(&value_1, 1);
    s21_decimal check = {{75, 0, 0, 0}};
    set_sign(&check, 1);
    s21_decimal result;
    int return_value = s21_floor(value_1, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, OK);
}
END_TEST

START_TEST(s21_floor_3) {
    s21_decimal src1;
    src1.bits[0] = 0b00001111111111111111111111111111;
    src1.bits[1] = 0b00111110001001010000001001100001;
    src1.bits[2] = 0b00100000010011111100111001011110;
    src1.bits[3] = 0b10000000000010100000000000000000;
    s21_decimal res_od;
    s21_floor(src1, &res_od);
    s21_decimal result;
    result.bits[0] = 0b10100111011001000000000000000000;
    result.bits[1] = 0b00001101111000001011011010110011;
    result.bits[2] = 0b00000000000000000000000000000000;
    result.bits[3] = 0b10000000000000000000000000000000;
    ck_assert_float_eq(res_od.bits[0], result.bits[0]);
    ck_assert_float_eq(res_od.bits[1], result.bits[1]);
    ck_assert_float_eq(res_od.bits[2], result.bits[2]);
    ck_assert_float_eq(res_od.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_from_int_to_decimal_1) {
    int src = 49135648;
    s21_decimal check = {{49135648, 0, 0, 0}};
    s21_decimal result;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, SUCCESS);
}
END_TEST

START_TEST(s21_from_int_to_decimal_2) {
    int src = -49135648;
    s21_decimal check = {{49135648, 0, 0, 0}};
    set_sign(&check, 1);
    s21_decimal result;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, SUCCESS);
}
END_TEST

START_TEST(s21_from_int_to_decimal_3) {
    int src = -49135648;
    s21_decimal check = {{49135648, 0, 0, 0}};
    set_sign(&check, 1);
    s21_decimal result;
    int return_value = s21_from_int_to_decimal(src, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, SUCCESS);
}
END_TEST

START_TEST(s21_from_int_to_decimal_4) {
    s21_decimal val;

    s21_from_float_to_decimal(0.03, &val);
    ck_assert_int_eq(val.bits[0], 3);
    ck_assert_int_eq(val.bits[1], 0);
    ck_assert_int_eq(val.bits[2], 0);
    ck_assert_int_eq(val.bits[3], 131072);

    s21_from_float_to_decimal(127.1234, &val);
    ck_assert_int_eq(val.bits[0], 1271234);
    ck_assert_int_eq(val.bits[1], 0);
    ck_assert_int_eq(val.bits[2], 0);
    ck_assert_int_eq(val.bits[3], 262144);
}
END_TEST

START_TEST(s21_from_decimal_to_int_1) {
    s21_decimal value = {{49135648, 0, 0, 0}};
    set_sign(&value, 1);
    set_scale(&value, 1);
    int dst;
    int check = -4913564;
    int return_value = s21_from_decimal_to_int(value, &dst);
    ck_assert_int_eq(dst, check);
    ck_assert_int_eq(return_value, SUCCESS);
}
END_TEST

START_TEST(s21_from_decimal_to_int_2) {
    s21_decimal value = {{49135648, 0, 0, 0}};
    set_scale(&value, 1);
    int dst;
    int check = 4913564;
    int return_value = s21_from_decimal_to_int(value, &dst);
    ck_assert_int_eq(dst, check);
    ck_assert_int_eq(return_value, SUCCESS);
}
END_TEST

START_TEST(s21_from_decimal_to_int_3) {
    s21_decimal value = {{2, 3, 0, 0}};
    int dst;
    int check = 0;
    int return_value = s21_from_decimal_to_int(value, &dst);
    ck_assert_int_eq(dst, check);
    ck_assert_int_eq(return_value, CONVERTING_ERROR);
}
END_TEST

START_TEST(s21_from_float_to_decimal_1) {
    float f = 0.03;
    s21_decimal result;
    s21_decimal check = {{3, 0, 0, 0}};
    set_scale(&check, 2);
    int return_value = s21_from_float_to_decimal(f, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, SUCCESS);
}
END_TEST

START_TEST(s21_from_float_to_decimal_2) {
    float f = -128.023;
    s21_decimal result;
    s21_decimal check = {{12802299, 0, 0, 0}};
    set_scale(&check, 5);
    set_sign(&check, 1);
    int return_value = s21_from_float_to_decimal(f, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, SUCCESS);
}
END_TEST

START_TEST(s21_from_float_to_decimal_3) {
    float f = 1.0 / 0.0;
    s21_decimal result;
    s21_decimal check = {{0, 0, 0, 0}};
    int return_value = s21_from_float_to_decimal(f, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, CONVERTING_ERROR);
}
END_TEST

START_TEST(s21_from_float_to_decimal_4) {
    float f = 0.0 / 0.0;
    s21_decimal result;
    s21_decimal check = {{0, 0, 0, 0}};
    int return_value = s21_from_float_to_decimal(f, &result);
    ck_assert_int_eq(s21_is_equal(result, check), 1);
    ck_assert_int_eq(return_value, CONVERTING_ERROR);
}
END_TEST

START_TEST(s21_from_decimal_to_float_1) {
    s21_decimal value = {{1812, 0, 0, 0}};
    set_sign(&value, 1);
    float result;
    float check = -1812;
    int return_value = s21_from_decimal_to_float(value, &result);
    ck_assert_float_eq(result, check);
    ck_assert_int_eq(return_value, SUCCESS);
}
END_TEST

START_TEST(s21_from_decimal_to_float_2) {
    s21_decimal value = {{18122, 0, 0, 0}};
    set_scale(&value, 3);
    set_sign(&value, 1);
    float result;
    float check = -18.122;
    int return_value = s21_from_decimal_to_float(value, &result);
    ck_assert_float_eq(result, check);
    ck_assert_int_eq(return_value, SUCCESS);
}
END_TEST

START_TEST(s21_from_decimal_to_float_3) {
    s21_decimal value = {{0xFFFFFF, 0, 0, 0}};
    float result;
    float check = 16777215;
    int return_value = s21_from_decimal_to_float(value, &result);
    ck_assert_float_eq(result, check);
    ck_assert_int_eq(return_value, SUCCESS);
}
END_TEST

START_TEST(s21_from_decimal_to_float_4) {
    s21_decimal value = {{0xFFFFFFFF, 0xFFFFFFFF, 0, 0}};
    float result;
    float check = 0xFFFFFFFFFFFFFFFF;
    int return_value = s21_from_decimal_to_float(value, &result);
    ck_assert_float_eq(result, check);
    ck_assert_int_eq(return_value, SUCCESS);
}
END_TEST

START_TEST(s21_from_decimal_to_float_5) {
    s21_decimal src;
    int result = 0;
    float number = 0.0;
    src.bits[0] = 23450987;
    src.bits[1] = 0;
    src.bits[2] = 0;
    src.bits[3] = 2147745792;
    result = s21_from_decimal_to_float(src, &number);
    ck_assert_float_eq(number, -2345.0987);
    ck_assert_int_eq(result, 0);
}
END_TEST

Suite *lib_suite(void) {
    Suite *s;
    s = suite_create("Check");

    TCase *tc_is_greater_1;
    tc_is_greater_1 = tcase_create("s21_is_greater_1");
    suite_add_tcase(s, tc_is_greater_1);
    tcase_add_test(tc_is_greater_1, s21_is_greater_1);

    TCase *tc_is_greater_2;
    tc_is_greater_2 = tcase_create("s21_is_greater_2");
    suite_add_tcase(s, tc_is_greater_2);
    tcase_add_test(tc_is_greater_2, s21_is_greater_2);

    TCase *tc_is_greater_3;
    tc_is_greater_3 = tcase_create("s21_is_greater_3");
    suite_add_tcase(s, tc_is_greater_3);
    tcase_add_test(tc_is_greater_3, s21_is_greater_3);

    TCase *tc_is_greater_4;
    tc_is_greater_4 = tcase_create("s21_is_greater_4");
    suite_add_tcase(s, tc_is_greater_4);
    tcase_add_test(tc_is_greater_4, s21_is_greater_4);

    TCase *tc_is_greater_5;
    tc_is_greater_5 = tcase_create("s21_is_greater_5");
    suite_add_tcase(s, tc_is_greater_5);
    tcase_add_test(tc_is_greater_5, s21_is_greater_5);

    TCase *tc_is_greater_6;
    tc_is_greater_6 = tcase_create("s21_is_greater_6");
    suite_add_tcase(s, tc_is_greater_6);
    tcase_add_test(tc_is_greater_6, s21_is_greater_6);

    TCase *tc_is_greater_7;
    tc_is_greater_7 = tcase_create("s21_is_greater_7");
    suite_add_tcase(s, tc_is_greater_7);
    tcase_add_test(tc_is_greater_7, s21_is_greater_7);

    TCase *tc_is_equal_1;
    tc_is_equal_1 = tcase_create("s21_is_equal_1");
    suite_add_tcase(s, tc_is_equal_1);
    tcase_add_test(tc_is_equal_1, s21_is_equal_1);

    TCase *tc_is_equal_2;
    tc_is_equal_2 = tcase_create("s21_is_equal_2");
    suite_add_tcase(s, tc_is_equal_2);
    tcase_add_test(tc_is_equal_2, s21_is_equal_2);

    TCase *tc_is_equal_3;
    tc_is_equal_3 = tcase_create("s21_is_equal_3");
    suite_add_tcase(s, tc_is_equal_3);
    tcase_add_test(tc_is_equal_3, s21_is_equal_3);

    TCase *tc_is_equal_4;
    tc_is_equal_4 = tcase_create("s21_is_equal_4");
    suite_add_tcase(s, tc_is_equal_4);
    tcase_add_test(tc_is_equal_4, s21_is_equal_4);

    TCase *tc_is_greater_or_equal_1;
    tc_is_greater_or_equal_1 = tcase_create("s21_is_greater_or_equal_1");
    suite_add_tcase(s, tc_is_greater_or_equal_1);
    tcase_add_test(tc_is_greater_or_equal_1, s21_is_greater_or_equal_1);

    TCase *tc_is_greater_or_equal_2;
    tc_is_greater_or_equal_2 = tcase_create("s21_is_greater_or_equal_2");
    suite_add_tcase(s, tc_is_greater_or_equal_2);
    tcase_add_test(tc_is_greater_or_equal_2, s21_is_greater_or_equal_2);

    TCase *tc_is_greater_or_equal_3;
    tc_is_greater_or_equal_3 = tcase_create("s21_is_greater_or_equal_3");
    suite_add_tcase(s, tc_is_greater_or_equal_3);
    tcase_add_test(tc_is_greater_or_equal_3, s21_is_greater_or_equal_3);

    TCase *tc_is_greater_or_equal_4;
    tc_is_greater_or_equal_4 = tcase_create("s21_is_greater_or_equal_4");
    suite_add_tcase(s, tc_is_greater_or_equal_4);
    tcase_add_test(tc_is_greater_or_equal_4, s21_is_greater_or_equal_4);

    TCase *tc_is_greater_or_equal_5;
    tc_is_greater_or_equal_5 = tcase_create("s21_is_greater_or_equal_5");
    suite_add_tcase(s, tc_is_greater_or_equal_5);
    tcase_add_test(tc_is_greater_or_equal_5, s21_is_greater_or_equal_5);

    TCase *tc_is_greater_or_equal_6;
    tc_is_greater_or_equal_6 = tcase_create("s21_is_greater_or_equal_6");
    suite_add_tcase(s, tc_is_greater_or_equal_6);
    tcase_add_test(tc_is_greater_or_equal_6, s21_is_greater_or_equal_6);

    TCase *tc_is_greater_or_equal_7;
    tc_is_greater_or_equal_7 = tcase_create("s21_is_greater_or_equal_7");
    suite_add_tcase(s, tc_is_greater_or_equal_7);
    tcase_add_test(tc_is_greater_or_equal_7, s21_is_greater_or_equal_7);

    TCase *tc_is_greater_or_equal_8;
    tc_is_greater_or_equal_8 = tcase_create("s21_is_greater_or_equal_8");
    suite_add_tcase(s, tc_is_greater_or_equal_8);
    tcase_add_test(tc_is_greater_or_equal_8, s21_is_greater_or_equal_8);

    TCase *tc_is_less_1;
    tc_is_less_1 = tcase_create("s21_is_less_1");
    suite_add_tcase(s, tc_is_less_1);
    tcase_add_test(tc_is_less_1, s21_is_less_1);

    TCase *tc_is_less_2;
    tc_is_less_2 = tcase_create("s21_is_less_2");
    suite_add_tcase(s, tc_is_less_2);
    tcase_add_test(tc_is_less_2, s21_is_less_2);

    TCase *tc_is_less_3;
    tc_is_less_3 = tcase_create("s21_is_less_3");
    suite_add_tcase(s, tc_is_less_3);
    tcase_add_test(tc_is_less_3, s21_is_less_3);

    TCase *tc_is_less_4;
    tc_is_less_4 = tcase_create("s21_is_less_4");
    suite_add_tcase(s, tc_is_less_4);
    tcase_add_test(tc_is_less_4, s21_is_less_4);

    TCase *tc_is_less_5;
    tc_is_less_5 = tcase_create("s21_is_less_5");
    suite_add_tcase(s, tc_is_less_5);
    tcase_add_test(tc_is_less_5, s21_is_less_5);

    TCase *tc_is_less_6;
    tc_is_less_6 = tcase_create("s21_is_less_6");
    suite_add_tcase(s, tc_is_less_6);
    tcase_add_test(tc_is_less_6, s21_is_less_6);

    TCase *tc_is_less_or_equal_1;
    tc_is_less_or_equal_1 = tcase_create("s21_is_less_or_equal_1");
    suite_add_tcase(s, tc_is_less_or_equal_1);
    tcase_add_test(tc_is_less_or_equal_1, s21_is_less_or_equal_1);

    TCase *tc_is_less_or_equal_2;
    tc_is_less_or_equal_2 = tcase_create("s21_is_less_or_equal_2");
    suite_add_tcase(s, tc_is_less_or_equal_2);
    tcase_add_test(tc_is_less_or_equal_2, s21_is_less_or_equal_2);

    TCase *tc_is_less_or_equal_3;
    tc_is_less_or_equal_3 = tcase_create("s21_is_less_or_equal_3");
    suite_add_tcase(s, tc_is_less_or_equal_3);
    tcase_add_test(tc_is_less_or_equal_3, s21_is_less_or_equal_3);

    TCase *tc_is_less_or_equal_4;
    tc_is_less_or_equal_4 = tcase_create("s21_is_less_or_equal_4");
    suite_add_tcase(s, tc_is_less_or_equal_4);
    tcase_add_test(tc_is_less_or_equal_4, s21_is_less_or_equal_4);

    TCase *tc_is_less_or_equal_5;
    tc_is_less_or_equal_5 = tcase_create("s21_is_less_or_equal_5");
    suite_add_tcase(s, tc_is_less_or_equal_5);
    tcase_add_test(tc_is_less_or_equal_5, s21_is_less_or_equal_5);

    TCase *tc_is_less_or_equal_6;
    tc_is_less_or_equal_6 = tcase_create("s21_is_less_or_equal_6");
    suite_add_tcase(s, tc_is_less_or_equal_6);
    tcase_add_test(tc_is_less_or_equal_6, s21_is_less_or_equal_6);

    TCase *tc_is_less_or_equal_7;
    tc_is_less_or_equal_7 = tcase_create("s21_is_less_or_equal_7");
    suite_add_tcase(s, tc_is_less_or_equal_7);
    tcase_add_test(tc_is_less_or_equal_7, s21_is_less_or_equal_7);

    TCase *tc_is_not_equal_1;
    tc_is_not_equal_1 = tcase_create("s21_is_not_equal_1");
    suite_add_tcase(s, tc_is_not_equal_1);
    tcase_add_test(tc_is_not_equal_1, s21_is_not_equal_1);

    TCase *tc_is_not_equal_2;
    tc_is_not_equal_2 = tcase_create("s21_is_not_equal_2");
    suite_add_tcase(s, tc_is_not_equal_2);
    tcase_add_test(tc_is_not_equal_2, s21_is_not_equal_2);

    TCase *tc_is_not_equal_3;
    tc_is_not_equal_3 = tcase_create("s21_is_not_equal_3");
    suite_add_tcase(s, tc_is_not_equal_3);
    tcase_add_test(tc_is_not_equal_3, s21_is_not_equal_3);

    TCase *tc_add_1;
    tc_add_1 = tcase_create("s21_add_1");
    suite_add_tcase(s, tc_add_1);
    tcase_add_test(tc_add_1, s21_add_1);

    TCase *tc_add_2;
    tc_add_2 = tcase_create("s21_add_2");
    suite_add_tcase(s, tc_add_2);
    tcase_add_test(tc_add_2, s21_add_2);

    TCase *tc_add_3;
    tc_add_3 = tcase_create("s21_add_3");
    suite_add_tcase(s, tc_add_3);
    tcase_add_test(tc_add_3, s21_add_3);

    TCase *tc_add_4;
    tc_add_4 = tcase_create("s21_add_4");
    suite_add_tcase(s, tc_add_4);
    tcase_add_test(tc_add_4, s21_add_4);

    TCase *tc_add_5;
    tc_add_5 = tcase_create("s21_add_5");
    suite_add_tcase(s, tc_add_5);
    tcase_add_test(tc_add_5, s21_add_5);

    TCase *tc_add_6;
    tc_add_6 = tcase_create("s21_add_6");
    suite_add_tcase(s, tc_add_6);
    tcase_add_test(tc_add_6, s21_add_6);

    TCase *tc_add_7;
    tc_add_7 = tcase_create("s21_add_7");
    suite_add_tcase(s, tc_add_7);
    tcase_add_test(tc_add_7, s21_add_7);

    TCase *tc_add_8;
    tc_add_8 = tcase_create("s21_add_8");
    suite_add_tcase(s, tc_add_8);
    tcase_add_test(tc_add_8, s21_add_8);

    TCase *tc_add_9;
    tc_add_9 = tcase_create("s21_add_9");
    suite_add_tcase(s, tc_add_9);
    tcase_add_test(tc_add_9, s21_add_9);

    TCase *tc_add_10;
    tc_add_10 = tcase_create("s21_add_10");
    suite_add_tcase(s, tc_add_10);
    tcase_add_test(tc_add_10, s21_add_10);

    TCase *tc_add_11;
    tc_add_11 = tcase_create("s21_add_11");
    suite_add_tcase(s, tc_add_11);
    tcase_add_test(tc_add_11, s21_add_11);

    TCase *tc_add_12;
    tc_add_12 = tcase_create("s21_add_12");
    suite_add_tcase(s, tc_add_12);
    tcase_add_test(tc_add_12, s21_add_12);

    TCase *tc_add_13;
    tc_add_13 = tcase_create("s21_add_13");
    suite_add_tcase(s, tc_add_13);
    tcase_add_test(tc_add_13, s21_add_13);

    TCase *tc_add_14;
    tc_add_14 = tcase_create("s21_add_14");
    suite_add_tcase(s, tc_add_14);
    tcase_add_test(tc_add_14, s21_add_14);

    TCase *tc_add_15;
    tc_add_15 = tcase_create("s21_add_15");
    suite_add_tcase(s, tc_add_15);
    tcase_add_test(tc_add_15, s21_add_15);

    TCase *tc_add_16;
    tc_add_16 = tcase_create("s21_add_16");
    suite_add_tcase(s, tc_add_16);
    tcase_add_test(tc_add_16, s21_add_16);

    TCase *tc_sub_1;
    tc_sub_1 = tcase_create("s21_sub_1");
    suite_add_tcase(s, tc_sub_1);
    tcase_add_test(tc_sub_1, s21_sub_1);

    TCase *tc_sub_2;
    tc_sub_2 = tcase_create("s21_sub_2");
    suite_add_tcase(s, tc_sub_2);
    tcase_add_test(tc_sub_2, s21_sub_2);

    TCase *tc_sub_3;
    tc_sub_3 = tcase_create("s21_sub_3");
    suite_add_tcase(s, tc_sub_3);
    tcase_add_test(tc_sub_3, s21_sub_3);

    TCase *tc_sub_4;
    tc_sub_4 = tcase_create("s21_sub_4");
    suite_add_tcase(s, tc_sub_4);
    tcase_add_test(tc_sub_4, s21_sub_4);

    TCase *tc_sub_5;
    tc_sub_5 = tcase_create("s21_sub_5");
    suite_add_tcase(s, tc_sub_5);
    tcase_add_test(tc_sub_5, s21_sub_5);

    TCase *tc_sub_6;
    tc_sub_6 = tcase_create("s21_sub_6");
    suite_add_tcase(s, tc_sub_6);
    tcase_add_test(tc_sub_6, s21_sub_6);

    TCase *tc_sub_7;
    tc_sub_7 = tcase_create("s21_sub_7");
    suite_add_tcase(s, tc_sub_7);
    tcase_add_test(tc_sub_7, s21_sub_7);

    TCase *tc_mul_1;
    tc_mul_1 = tcase_create("s21_mul_1");
    suite_add_tcase(s, tc_mul_1);
    tcase_add_test(tc_mul_1, s21_mul_1);

    TCase *tc_mul_2;
    tc_mul_2 = tcase_create("s21_mul_2");
    suite_add_tcase(s, tc_mul_2);
    tcase_add_test(tc_mul_2, s21_mul_2);

    TCase *tc_mul_3;
    tc_mul_3 = tcase_create("s21_mul_3");
    suite_add_tcase(s, tc_mul_3);
    tcase_add_test(tc_mul_3, s21_mul_3);

    TCase *tc_mul_4;
    tc_mul_4 = tcase_create("s21_mul_4");
    suite_add_tcase(s, tc_mul_4);
    tcase_add_test(tc_mul_4, s21_mul_4);

    TCase *tc_mul_5;
    tc_mul_5 = tcase_create("s21_mul_5");
    suite_add_tcase(s, tc_mul_5);
    tcase_add_test(tc_mul_5, s21_mul_5);

    TCase *tc_mul_6;
    tc_mul_6 = tcase_create("s21_mul_6");
    suite_add_tcase(s, tc_mul_6);
    tcase_add_test(tc_mul_6, s21_mul_6);

    TCase *tc_mul_7;
    tc_mul_7 = tcase_create("s21_mul_7");
    suite_add_tcase(s, tc_mul_7);
    tcase_add_test(tc_mul_7, s21_mul_7);

    TCase *tc_mul_8;
    tc_mul_8 = tcase_create("s21_mul_8");
    suite_add_tcase(s, tc_mul_8);
    tcase_add_test(tc_mul_8, s21_mul_8);

    TCase *tc_div_1;
    tc_div_1 = tcase_create("s21_div_1");
    suite_add_tcase(s, tc_div_1);
    tcase_add_test(tc_div_1, s21_div_1);

    TCase *tc_div_2;
    tc_div_2 = tcase_create("s21_div_2");
    suite_add_tcase(s, tc_div_2);
    tcase_add_test(tc_div_2, s21_div_2);

    TCase *tc_div_3;
    tc_div_3 = tcase_create("s21_div_3");
    suite_add_tcase(s, tc_div_3);
    tcase_add_test(tc_div_3, s21_div_3);

    TCase *tc_div_4;
    tc_div_4 = tcase_create("s21_div_4");
    suite_add_tcase(s, tc_div_4);
    tcase_add_test(tc_div_4, s21_div_4);

    TCase *tc_div_5;
    tc_div_5 = tcase_create("s21_div_5");
    suite_add_tcase(s, tc_div_5);
    tcase_add_test(tc_div_5, s21_div_5);

    TCase *tc_div_6;
    tc_div_6 = tcase_create("s21_div_6");
    suite_add_tcase(s, tc_div_6);
    tcase_add_test(tc_div_6, s21_div_6);

    TCase *tc_div_7;
    tc_div_7 = tcase_create("s21_div_7");
    suite_add_tcase(s, tc_div_7);
    tcase_add_test(tc_div_7, s21_div_7);

    TCase *tc_div_8;
    tc_div_8 = tcase_create("s21_div_8");
    suite_add_tcase(s, tc_div_8);
    tcase_add_test(tc_div_8, s21_div_8);

    TCase *tc_div_9;
    tc_div_9 = tcase_create("s21_div_9");
    suite_add_tcase(s, tc_div_9);
    tcase_add_test(tc_div_9, s21_div_9);

    TCase *tc_truncate_1;
    tc_truncate_1 = tcase_create("s21_truncate_1");
    suite_add_tcase(s, tc_truncate_1);
    tcase_add_test(tc_truncate_1, s21_truncate_1);

    TCase *tc_truncate_2;
    tc_truncate_2 = tcase_create("s21_truncate_2");
    suite_add_tcase(s, tc_truncate_2);
    tcase_add_test(tc_truncate_2, s21_truncate_2);

    TCase *tc_truncate_3;
    tc_truncate_3 = tcase_create("s21_truncate_3");
    suite_add_tcase(s, tc_truncate_3);
    tcase_add_test(tc_truncate_3, s21_truncate_3);

    TCase *tc_truncate_4;
    tc_truncate_4 = tcase_create("s21_truncate_4");
    suite_add_tcase(s, tc_truncate_4);
    tcase_add_test(tc_truncate_4, s21_truncate_4);

    TCase *tc_negate_1;
    tc_negate_1 = tcase_create("s21_negate_1");
    suite_add_tcase(s, tc_negate_1);
    tcase_add_test(tc_negate_1, s21_negate_1);

    TCase *tc_negate_2;
    tc_negate_2 = tcase_create("s21_negate_2");
    suite_add_tcase(s, tc_negate_2);
    tcase_add_test(tc_negate_2, s21_negate_2);

    TCase *tc_negate_3;
    tc_negate_3 = tcase_create("s21_negate_3");
    suite_add_tcase(s, tc_negate_3);
    tcase_add_test(tc_negate_3, s21_negate_3);

    TCase *tc_mod_1;
    tc_mod_1 = tcase_create("s21_mod_1");
    suite_add_tcase(s, tc_mod_1);
    tcase_add_test(tc_mod_1, s21_mod_1);

    TCase *tc_mod_2;
    tc_mod_2 = tcase_create("s21_mod_2");
    suite_add_tcase(s, tc_mod_2);
    tcase_add_test(tc_mod_2, s21_mod_2);

    TCase *tc_mod_3;
    tc_mod_3 = tcase_create("s21_mod_3");
    suite_add_tcase(s, tc_mod_3);
    tcase_add_test(tc_mod_3, s21_mod_3);

    TCase *tc_mod_4;
    tc_mod_4 = tcase_create("s21_mod_4");
    suite_add_tcase(s, tc_mod_4);
    tcase_add_test(tc_mod_4, s21_mod_4);

    TCase *tc_mod_5;
    tc_mod_5 = tcase_create("s21_mod_5");
    suite_add_tcase(s, tc_mod_5);
    tcase_add_test(tc_mod_5, s21_mod_5);

    TCase *tc_mod_6;
    tc_mod_6 = tcase_create("s21_mod_6");
    suite_add_tcase(s, tc_mod_6);
    tcase_add_test(tc_mod_6, s21_mod_6);

    TCase *tc_mod_7;
    tc_mod_7 = tcase_create("s21_mod_7");
    suite_add_tcase(s, tc_mod_7);
    tcase_add_test(tc_mod_7, s21_mod_7);

    TCase *tc_round_1;
    tc_round_1 = tcase_create("s21_round_1");
    suite_add_tcase(s, tc_round_1);
    tcase_add_test(tc_round_1, s21_round_1);

    TCase *tc_round_2;
    tc_round_2 = tcase_create("s21_round_2");
    suite_add_tcase(s, tc_round_2);
    tcase_add_test(tc_round_2, s21_round_2);

    TCase *tc_round_3;
    tc_round_3 = tcase_create("s21_round_3");
    suite_add_tcase(s, tc_round_3);
    tcase_add_test(tc_round_3, s21_round_3);

    TCase *tc_round_4;
    tc_round_4 = tcase_create("s21_round_4");
    suite_add_tcase(s, tc_round_4);
    tcase_add_test(tc_round_4, s21_round_4);

    TCase *tc_round_5;
    tc_round_5 = tcase_create("s21_round_5");
    suite_add_tcase(s, tc_round_5);
    tcase_add_test(tc_round_5, s21_round_5);

    TCase *tc_round_6;
    tc_round_6 = tcase_create("s21_round_6");
    suite_add_tcase(s, tc_round_6);
    tcase_add_test(tc_round_6, s21_round_6);

    TCase *tc_floor_1;
    tc_floor_1 = tcase_create("s21_floor_1");
    suite_add_tcase(s, tc_floor_1);
    tcase_add_test(tc_floor_1, s21_floor_1);

    TCase *tc_floor_2;
    tc_floor_2 = tcase_create("s21_floor_2");
    suite_add_tcase(s, tc_floor_2);
    tcase_add_test(tc_floor_2, s21_floor_2);

    TCase *tc_floor_3;
    tc_floor_3 = tcase_create("s21_floor_3");
    suite_add_tcase(s, tc_floor_3);
    tcase_add_test(tc_floor_3, s21_floor_3);

    TCase *tc_from_int_to_decimal_1;
    tc_from_int_to_decimal_1 = tcase_create("s21_from_int_to_decimal_1");
    suite_add_tcase(s, tc_from_int_to_decimal_1);
    tcase_add_test(tc_from_int_to_decimal_1, s21_from_int_to_decimal_1);

    TCase *tc_from_int_to_decimal_2;
    tc_from_int_to_decimal_2 = tcase_create("s21_from_int_to_decimal_2");
    suite_add_tcase(s, tc_from_int_to_decimal_2);
    tcase_add_test(tc_from_int_to_decimal_2, s21_from_int_to_decimal_2);

    TCase *tc_from_int_to_decimal_3;
    tc_from_int_to_decimal_3 = tcase_create("s21_from_int_to_decimal_3");
    suite_add_tcase(s, tc_from_int_to_decimal_3);
    tcase_add_test(tc_from_int_to_decimal_3, s21_from_int_to_decimal_3);

    TCase *tc_from_int_to_decimal_4;
    tc_from_int_to_decimal_4 = tcase_create("s21_from_int_to_decimal_4");
    suite_add_tcase(s, tc_from_int_to_decimal_4);
    tcase_add_test(tc_from_int_to_decimal_4, s21_from_int_to_decimal_4);

    TCase *tc_from_decimal_to_int_1;
    tc_from_decimal_to_int_1 = tcase_create("s21_from_decimal_to_int_1");
    suite_add_tcase(s, tc_from_decimal_to_int_1);
    tcase_add_test(tc_from_decimal_to_int_1, s21_from_decimal_to_int_1);

    TCase *tc_from_decimal_to_int_2;
    tc_from_decimal_to_int_2 = tcase_create("s21_from_decimal_to_int_2");
    suite_add_tcase(s, tc_from_decimal_to_int_2);
    tcase_add_test(tc_from_decimal_to_int_2, s21_from_decimal_to_int_2);

    TCase *tc_from_decimal_to_int_3;
    tc_from_decimal_to_int_3 = tcase_create("s21_from_decimal_to_int_3");
    suite_add_tcase(s, tc_from_decimal_to_int_3);
    tcase_add_test(tc_from_decimal_to_int_3, s21_from_decimal_to_int_3);

    TCase *tc_from_float_to_decimal_1;
    tc_from_float_to_decimal_1 = tcase_create("s21_from_float_to_decimal_1");
    suite_add_tcase(s, tc_from_float_to_decimal_1);
    tcase_add_test(tc_from_float_to_decimal_1, s21_from_float_to_decimal_1);

    TCase *tc_from_float_to_decimal_2;
    tc_from_float_to_decimal_2 = tcase_create("s21_from_float_to_decimal_2");
    suite_add_tcase(s, tc_from_float_to_decimal_2);
    tcase_add_test(tc_from_float_to_decimal_2, s21_from_float_to_decimal_2);

    TCase *tc_from_float_to_decimal_3;
    tc_from_float_to_decimal_3 = tcase_create("s21_from_float_to_decimal_3");
    suite_add_tcase(s, tc_from_float_to_decimal_3);
    tcase_add_test(tc_from_float_to_decimal_3, s21_from_float_to_decimal_3);

    TCase *tc_from_float_to_decimal_4;
    tc_from_float_to_decimal_4 = tcase_create("s21_from_float_to_decimal_4");
    suite_add_tcase(s, tc_from_float_to_decimal_4);
    tcase_add_test(tc_from_float_to_decimal_4, s21_from_float_to_decimal_4);

    TCase *tc_from_decimal_to_float_1;
    tc_from_decimal_to_float_1 = tcase_create("s21_from_decimal_to_float_1");
    suite_add_tcase(s, tc_from_decimal_to_float_1);
    tcase_add_test(tc_from_decimal_to_float_1, s21_from_decimal_to_float_1);

    TCase *tc_from_decimal_to_float_2;
    tc_from_decimal_to_float_2 = tcase_create("s21_from_decimal_to_float_2");
    suite_add_tcase(s, tc_from_decimal_to_float_2);
    tcase_add_test(tc_from_decimal_to_float_2, s21_from_decimal_to_float_2);

    TCase *tc_from_decimal_to_float_3;
    tc_from_decimal_to_float_3 = tcase_create("s21_from_decimal_to_float_3");
    suite_add_tcase(s, tc_from_decimal_to_float_3);
    tcase_add_test(tc_from_decimal_to_float_3, s21_from_decimal_to_float_3);

    TCase *tc_from_decimal_to_float_4;
    tc_from_decimal_to_float_4 = tcase_create("s21_from_decimal_to_float_4");
    suite_add_tcase(s, tc_from_decimal_to_float_4);
    tcase_add_test(tc_from_decimal_to_float_4, s21_from_decimal_to_float_4);

    TCase *tc_from_decimal_to_float_5;
    tc_from_decimal_to_float_5 = tcase_create("s21_from_decimal_to_float_5");
    suite_add_tcase(s, tc_from_decimal_to_float_5);
    tcase_add_test(tc_from_decimal_to_float_5, s21_from_decimal_to_float_5);

    return s;
}

int main(void) {
    Suite *s;
    SRunner *sr;

    s = lib_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_VERBOSE);
    srunner_free(sr);
    return 0;
}
