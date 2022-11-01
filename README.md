# decimal.h
1. [In English](#description)
2. [На русском](#описание)
### Description
Implementation of decimal.h library from C#. The library is developed in C language of C11 standard using gcc compiler.


### Arithmetic Operators
| Operator name | Operators  | Function                                                                           | 
| ------ | ------ |------------------------------------------------------------------------------------|
| Addition | + | int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)         |
| Subtraction | - | int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) |
| Multiplication | * | int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) | 
| Division | / | int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) |
| Modulo | Mod | int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) |

The functions return the error code:
- 0 - OK
- 1 - the number is too large or equal to infinity
- 2 - the number is too small or equal to negative infinity
- 3 - division by 0

### Comparison Operators
| Operator name | Operators  | Function | 
| ------ | ------ | ------ |
| Less than | < | int s21_is_less(s21_decimal, s21_decimal) |
| Less than or equal to | <= | int s21_is_less_or_equal(s21_decimal, s21_decimal) | 
| Greater than | > |  int s21_is_greater(s21_decimal, s21_decimal) |
| Greater than or equal to | >= | int s21_is_greater_or_equal(s21_decimal, s21_decimal) | 
| Equal to | == |  int s21_is_equal(s21_decimal, s21_decimal) |
| Not equal to | != |  int s21_is_not_equal(s21_decimal, s21_decimal) |

Return value:
- 0 - FALSE
- 1 - TRUE

### Convertors and parsers
| Convertor/parser | Function | 
| ------ | ------ |
| From int  | int s21_from_int_to_decimal(int src, s21_decimal *dst) |
| From float  | int s21_from_float_to_decimal(float src, s21_decimal *dst) |
| To int  | int s21_from_decimal_to_int(s21_decimal src, int *dst) |
| To float  | int s21_from_decimal_to_float(s21_decimal src, float *dst) |

Return value - code error:
- 0 - OK
- 1 - convertation error

### Another functions
| Description | Function                                                         | 
| ------ |------------------------------------------------------------------|
| Rounds a specified Decimal number to the closest integer toward negative infinity. | int s21_floor(s21_decimal value, s21_decimal *result)            |	
| Rounds a decimal value to the nearest integer. | int s21_round(s21_decimal value, s21_decimal *result)    |
| Returns the integral digits of the specified Decimal; any fractional digits are discarded, including trailing zeroes. | int s21_truncate(s21_decimal value, s21_decimal *result) |
| Returns the result of multiplying the specified Decimal value by negative one. | int s21_negate(s21_decimal value, s21_decimal *result)   |

Return value - code error:
- 0 - OK
- 1 - calculation error
***

### Описание
Реализация библиотеки decimal.h из C#. Библиотека разработана на языке C стандарта C11 с использованием компилятора gcc.

### Арифметические операторы
| Название оператора | Оператор  | Функция                                                                            | 
| ------ | ------ |------------------------------------------------------------------------------------|
| Сложение | + | int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)         |
| Вычитание | - | int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result)         |
| Умножение | * | int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) | 
| Деление | / | int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) |
| Остаток от деления | Mod | int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) |

Функции возвращают код ошибки:  
- 0 - OK  
- 1 - число слишком велико или равно бесконечности
- 2 - число слишком мало или равно отрицательной бесконечности
- 3 - деление на 0

### Операторы сравнения
| Название оператора | Оператор  | Функция | 
| ------ | ------ | ------ |
| Меньше  | < | int s21_is_less(s21_decimal, s21_decimal) |
| Меньше или равно | <= | int s21_is_less_or_equal(s21_decimal, s21_decimal) | 
| Больше | \> |  int s21_is_greater(s21_decimal, s21_decimal) |
| Больше или равно | \>= | int s21_is_greater_or_equal(s21_decimal, s21_decimal) | 
| Равно | == |  int s21_is_equal(s21_decimal, s21_decimal) |
| Не равно | != |  int s21_is_not_equal(s21_decimal, s21_decimal) |

Возвращаемое значение:
- 0 - FALSE
- 1 - TRUE

### Преобразователи 
| Преобразователь | Функция | 
| ------ | ------ |
| Из int | int s21_from_int_to_decimal(int src, s21_decimal *dst) |
| Из float  | int s21_from_float_to_decimal(float src, s21_decimal *dst) |
| В int  | int s21_from_decimal_to_int(s21_decimal src, int *dst) |
| В float  | int s21_from_decimal_to_float(s21_decimal src, float *dst) |

Возвращаемое значение - код ошибки:
 - 0 - OK
 - 1 - ошибка конвертации
 
 ### Другие функции

| Описание | Функция                                                  | 
| ------ |----------------------------------------------------------|
| Округляет указанное Decimal число до ближайшего целого числа в сторону отрицательной бесконечности. | int s21_floor(s21_decimal value, s21_decimal *result)    |	
| Округляет Decimal до ближайшего целого числа. | int s21_round(s21_decimal value, s21_decimal *result)    |
| Возвращает целые цифры указанного Decimal числа; любые дробные цифры отбрасываются, включая конечные нули. | int s21_truncate(s21_decimal value, s21_decimal *result) |
| Возвращает результат умножения указанного Decimal на -1. | int s21_negate(s21_decimal value, s21_decimal *result)   |

Возвращаемое значение - код ошибки:
 - 0 - OK
 - 1 - ошибка вычисления
 
