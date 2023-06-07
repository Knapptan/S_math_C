#include "s21_math.h"

long double s21_asin(double x) {
  // Инициализация результата значением S21_NAN
  long double result = S21_NAN;

  if (x == S21_NAN || x == S21_INFINITY || x == S21_MINUS_INFINITY) {
    // Если x равно S21_NAN, S21_INFINITY или S21_MINUS_INFINITY, результату
    // присваивается отрицательное значение S21_NAN
    result = -S21_NAN;
  } else if (x == 1) {
    // Если x равно 1, результату присваивается значение S21_PI / 2.0 (половина
    // значения пи)
    result = S21_PI / 2.0;
  } else if (x == -1) {
    // Если x равно -1, результату присваивается значение -1.0 * S21_PI / 2.0
    // (отрицательная половина значения пи)
    result = -1.0 * S21_PI / 2.0;
  } else if (x > 1 || x < -1) {
    // Если x больше 1 или меньше -1, результату присваивается значение -nan
    result = -S21_NAN;
    // Если x находится в диапазоне (-1, 1), результату присваивается значение
  } else if (x > -1 && x < 1) {
    // арктангенса от x / (квадратный корень из (1 - x^2))
    result = s21_atan(x / (s21_sqrt(1 - x * x)));
  }

  return result;
}