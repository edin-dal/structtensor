
#ifndef RING_COFACTOR_HPP
#define RING_COFACTOR_HPP

#include <array>
#include <unordered_map>
#include "hash.hpp"


template <typename T, int CONT_SZ, int CAT_SZ>
struct RingCofactor {
    long count;
    std::array<double, CONT_SZ> cont_sum1;
    std::array<std::array<double, CONT_SZ>, CONT_SZ> cont_degree2;
    
    std::array<std::array<std::array<double, CONT_SZ>, CONT_SZ>, CONT_SZ> cont_degree3;
    std::array<std::array<std::array<std::array<double, CONT_SZ>, CONT_SZ>, CONT_SZ>, CONT_SZ> cont_degree4;
      


    explicit RingCofactor() : count(0) {
      cont_sum1 = {};
      cont_degree2 = {};
      
      cont_degree3 = {};
      cont_degree4 = {};
        
    }

    template <typename... Args>
    explicit RingCofactor(Args&&... args): count(1), cont_sum1 { args... } {
        static_assert(CONT_SZ == sizeof...(args) && CAT_SZ == 0, "Incompatible array sizes");




for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm3 = cont_degree2[x0];

auto &cm4 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {


cm3[x1] = (cm4 * cont_sum1[x1]);
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm6 = cont_degree3[x0];

auto &cm7 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm8 = cm6[x1];

auto &cm9 = cont_sum1[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {


cm8[x2] = (cm7 * cm9 * cont_sum1[x2]);
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm11 = cont_degree4[x0];

auto &cm12 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm13 = cm11[x1];

auto &cm14 = cont_sum1[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm15 = cm13[x2];

auto &cm16 = cont_sum1[x2];

for (int x3 = x2; x3 < CONT_SZ; ++x3) {


cm15[x3] = (cm12 * cm14 * cm16 * cont_sum1[x3]);
}
}
}
}


    }
    
    inline bool isZero() const { return count == 0; }

    void finished(double div_val = 0, bool mapping_flag = false) {

    }

    RingCofactor& operator+=(const RingCofactor& other) {
        peqInplace(other);
        return *this;
    }

    void peqInplace(const RingCofactor& other, bool sort_merge_flag = false) {
        if (other.isZero()) return;


count += ((other.count));


for (int x0 = 0; x0 < CONT_SZ; ++x0) {


cont_sum1[x0] += (other.cont_sum1[x0]);
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm17 = cont_degree2[x0];

auto &cm18 = other.cont_degree2[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {


cm17[x1] += (cm18[x1]);
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm19 = cont_degree3[x0];

auto &cm20 = other.cont_degree3[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm21 = cm19[x1];

auto &cm22 = cm20[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {


cm21[x2] += (cm22[x2]);
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm23 = cont_degree4[x0];

auto &cm24 = other.cont_degree4[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm25 = cm23[x1];

auto &cm26 = cm24[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm27 = cm25[x2];

auto &cm28 = cm26[x2];

for (int x3 = x2; x3 < CONT_SZ; ++x3) {


cm27[x3] += (cm28[x3]);
}
}
}
}


    }
    template <int CONT_SZ2, int CAT_SZ2>
    RingCofactor<T, CONT_SZ + CONT_SZ2, CAT_SZ + CAT_SZ2> operator*(const RingCofactor<T, CONT_SZ2, CAT_SZ2>& other) const {
        if (isZero() || other.isZero()) return RingCofactor<T, CONT_SZ + CONT_SZ2, CAT_SZ + CAT_SZ2>();
        return this->multiply(other);
    }

    template <int CONT_SZ2, int CAT_SZ2>
    RingCofactor<T, CONT_SZ + CONT_SZ2, CAT_SZ + CAT_SZ2>
    multiply(const RingCofactor<T, CONT_SZ2, CAT_SZ2>& other) const {
        RingCofactor<T, CONT_SZ + CONT_SZ2, CAT_SZ + CAT_SZ2> r;
        multiplyDPS(other, r);
        return r;
    }

    template <int CONT_SZ2, int CAT_SZ2>
    void
    multiplyDPS(const RingCofactor<T, CONT_SZ2, CAT_SZ2>& other, RingCofactor<T, CONT_SZ + CONT_SZ2, CAT_SZ + CAT_SZ2>& r) const {    


r.count += ((count * other.count));


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
double tmp = 0.0;

auto &cm153 = cont_sum1[x0];





tmp += (cm153 * other.count);

r.cont_sum1[x0] += tmp;
}


for (int x0 = CONT_SZ; x0 < (CONT_SZ2 + CONT_SZ); ++x0) {
double tmp = 0.0;






tmp += (count * other.cont_sum1[(x0 - CONT_SZ)]);

r.cont_sum1[x0] += tmp;
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm170 = r.cont_degree2[x0];

auto &cm171 = cont_degree2[x0];
auto &cm172 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
double tmp = 0.0;

auto &cm173 = cm171[x1];
auto &cm174 = cont_sum1[x1];



auto &cm175 = other.cont_sum1[y1];





tmp += (cm173 * other.count);

cm170[x1] += tmp;
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm176 = r.cont_degree2[x0];

auto &cm177 = cont_degree2[x0];
auto &cm178 = cont_sum1[x0];

for (int x1 = CONT_SZ; x1 < (CONT_SZ2 + CONT_SZ); ++x1) {
double tmp = 0.0;




auto &cm181 = other.cont_sum1[(x1 - CONT_SZ)];





tmp += (cm178 * cm181);

cm176[x1] += tmp;
}
}


for (int x0 = CONT_SZ; x0 < (CONT_SZ2 + CONT_SZ); ++x0) {
auto &cm182 = r.cont_degree2[x0];


for (int x1 = std::max({x0, CONT_SZ}); x1 < (CONT_SZ2 + CONT_SZ); ++x1) {
double tmp = 0.0;




auto &cm187 = other.cont_sum1[(x1 - CONT_SZ)];





tmp += (count * other.cont_degree2[(x0 - CONT_SZ)][(x1 - CONT_SZ)]);

cm182[x1] += tmp;
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm220 = r.cont_degree3[x0];

auto &cm221 = cont_degree3[x0];
auto &cm222 = cont_degree2[x0];
auto &cm223 = cont_degree2[x0];
auto &cm224 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm225 = cm220[x1];

auto &cm226 = cm221[x1];
auto &cm227 = cm222[x1];
auto &cm228 = cont_degree2[x1];
auto &cm229 = cont_sum1[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
double tmp = 0.0;

auto &cm230 = cm226[x2];
auto &cm231 = cm223[x2];
auto &cm232 = cm228[x2];
auto &cm233 = cont_sum1[x2];



auto &cm234 = other.cont_sum1[y2];



auto &cm235 = other.cont_sum1[y1];
auto &cm236 = other.cont_degree2[y1];





tmp += (cm230 * other.count);

cm225[x2] += tmp;
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm237 = r.cont_degree3[x0];

auto &cm238 = cont_degree3[x0];
auto &cm239 = cont_degree2[x0];
auto &cm240 = cont_degree2[x0];
auto &cm241 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm242 = cm237[x1];

auto &cm243 = cm238[x1];
auto &cm244 = cm239[x1];
auto &cm245 = cont_degree2[x1];
auto &cm246 = cont_sum1[x1];

for (int x2 = CONT_SZ; x2 < (CONT_SZ2 + CONT_SZ); ++x2) {
double tmp = 0.0;




auto &cm251 = other.cont_sum1[(x2 - CONT_SZ)];



auto &cm252 = other.cont_sum1[y1];
auto &cm253 = other.cont_degree2[y1];





tmp += (cm244 * cm251);

cm242[x2] += tmp;
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm254 = r.cont_degree3[x0];

auto &cm255 = cont_degree3[x0];
auto &cm256 = cont_degree2[x0];
auto &cm257 = cont_degree2[x0];
auto &cm258 = cont_sum1[x0];

for (int x1 = CONT_SZ; x1 < (CONT_SZ2 + CONT_SZ); ++x1) {
auto &cm259 = cm254[x1];


for (int x2 = std::max({x1, CONT_SZ}); x2 < (CONT_SZ2 + CONT_SZ); ++x2) {
double tmp = 0.0;




auto &cm268 = other.cont_sum1[(x2 - CONT_SZ)];



auto &cm269 = other.cont_sum1[(x1 - CONT_SZ)];
auto &cm270 = other.cont_degree2[(x1 - CONT_SZ)];





tmp += (cm258 * cm270[(x2 - CONT_SZ)]);

cm259[x2] += tmp;
}
}
}


for (int x0 = CONT_SZ; x0 < (CONT_SZ2 + CONT_SZ); ++x0) {
auto &cm271 = r.cont_degree3[x0];


for (int x1 = std::max({x0, CONT_SZ}); x1 < (CONT_SZ2 + CONT_SZ); ++x1) {
auto &cm276 = cm271[x1];


for (int x2 = std::max({x1, CONT_SZ}); x2 < (CONT_SZ2 + CONT_SZ); ++x2) {
double tmp = 0.0;




auto &cm285 = other.cont_sum1[(x2 - CONT_SZ)];



auto &cm286 = other.cont_sum1[(x1 - CONT_SZ)];
auto &cm287 = other.cont_degree2[(x1 - CONT_SZ)];





tmp += (count * other.cont_degree3[(x0 - CONT_SZ)][(x1 - CONT_SZ)][(x2 - CONT_SZ)]);

cm276[x2] += tmp;
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm353 = r.cont_degree4[x0];

auto &cm354 = cont_degree4[x0];
auto &cm355 = cont_degree3[x0];
auto &cm356 = cont_degree3[x0];
auto &cm357 = cont_degree3[x0];
auto &cm358 = cont_degree2[x0];
auto &cm359 = cont_degree2[x0];
auto &cm360 = cont_degree2[x0];
auto &cm361 = cont_sum1[x0];

for (int x1 = CONT_SZ; x1 < (CONT_SZ2 + CONT_SZ); ++x1) {
auto &cm362 = cm353[x1];


for (int x2 = std::max({x1, CONT_SZ}); x2 < (CONT_SZ2 + CONT_SZ); ++x2) {
auto &cm371 = cm362[x2];


for (int x3 = std::max({x2, CONT_SZ}); x3 < (CONT_SZ2 + CONT_SZ); ++x3) {
double tmp = 0.0;




auto &cm388 = other.cont_sum1[(x3 - CONT_SZ)];



auto &cm389 = other.cont_sum1[(x2 - CONT_SZ)];
auto &cm390 = other.cont_degree2[(x2 - CONT_SZ)];



auto &cm391 = other.cont_sum1[(x1 - CONT_SZ)];
auto &cm392 = other.cont_degree2[(x1 - CONT_SZ)];
auto &cm393 = other.cont_degree2[(x1 - CONT_SZ)];
auto &cm394 = other.cont_degree3[(x1 - CONT_SZ)];





tmp += (cm361 * cm394[(x2 - CONT_SZ)][(x3 - CONT_SZ)]);

cm371[x3] += tmp;
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm395 = r.cont_degree4[x0];

auto &cm396 = cont_degree4[x0];
auto &cm397 = cont_degree3[x0];
auto &cm398 = cont_degree3[x0];
auto &cm399 = cont_degree3[x0];
auto &cm400 = cont_degree2[x0];
auto &cm401 = cont_degree2[x0];
auto &cm402 = cont_degree2[x0];
auto &cm403 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm404 = cm395[x1];

auto &cm405 = cm396[x1];
auto &cm406 = cm397[x1];
auto &cm407 = cm398[x1];
auto &cm408 = cont_degree3[x1];
auto &cm409 = cm400[x1];
auto &cm410 = cont_degree2[x1];
auto &cm411 = cont_degree2[x1];
auto &cm412 = cont_sum1[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm413 = cm404[x2];

auto &cm414 = cm405[x2];
auto &cm415 = cm406[x2];
auto &cm416 = cm399[x2];
auto &cm417 = cm408[x2];
auto &cm418 = cm401[x2];
auto &cm419 = cm410[x2];
auto &cm420 = cont_degree2[x2];
auto &cm421 = cont_sum1[x2];

for (int x3 = x2; x3 < CONT_SZ; ++x3) {
double tmp = 0.0;

auto &cm422 = cm414[x3];
auto &cm423 = cm407[x3];
auto &cm424 = cm416[x3];
auto &cm425 = cm417[x3];
auto &cm426 = cm402[x3];
auto &cm427 = cm411[x3];
auto &cm428 = cm420[x3];
auto &cm429 = cont_sum1[x3];



auto &cm430 = other.cont_sum1[y3];



auto &cm431 = other.cont_sum1[y2];
auto &cm432 = other.cont_degree2[y2];



auto &cm433 = other.cont_sum1[y1];
auto &cm434 = other.cont_degree2[y1];
auto &cm435 = other.cont_degree2[y1];
auto &cm436 = other.cont_degree3[y1];





tmp += (cm422 * other.count);

cm413[x3] += tmp;
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm437 = r.cont_degree4[x0];

auto &cm438 = cont_degree4[x0];
auto &cm439 = cont_degree3[x0];
auto &cm440 = cont_degree3[x0];
auto &cm441 = cont_degree3[x0];
auto &cm442 = cont_degree2[x0];
auto &cm443 = cont_degree2[x0];
auto &cm444 = cont_degree2[x0];
auto &cm445 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm446 = cm437[x1];

auto &cm447 = cm438[x1];
auto &cm448 = cm439[x1];
auto &cm449 = cm440[x1];
auto &cm450 = cont_degree3[x1];
auto &cm451 = cm442[x1];
auto &cm452 = cont_degree2[x1];
auto &cm453 = cont_degree2[x1];
auto &cm454 = cont_sum1[x1];

for (int x2 = CONT_SZ; x2 < (CONT_SZ2 + CONT_SZ); ++x2) {
auto &cm455 = cm446[x2];


for (int x3 = std::max({x2, CONT_SZ}); x3 < (CONT_SZ2 + CONT_SZ); ++x3) {
double tmp = 0.0;




auto &cm472 = other.cont_sum1[(x3 - CONT_SZ)];



auto &cm473 = other.cont_sum1[(x2 - CONT_SZ)];
auto &cm474 = other.cont_degree2[(x2 - CONT_SZ)];



auto &cm475 = other.cont_sum1[y1];
auto &cm476 = other.cont_degree2[y1];
auto &cm477 = other.cont_degree2[y1];
auto &cm478 = other.cont_degree3[y1];





tmp += (cm451 * cm474[(x3 - CONT_SZ)]);

cm455[x3] += tmp;
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm479 = r.cont_degree4[x0];

auto &cm480 = cont_degree4[x0];
auto &cm481 = cont_degree3[x0];
auto &cm482 = cont_degree3[x0];
auto &cm483 = cont_degree3[x0];
auto &cm484 = cont_degree2[x0];
auto &cm485 = cont_degree2[x0];
auto &cm486 = cont_degree2[x0];
auto &cm487 = cont_sum1[x0];

for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm488 = cm479[x1];

auto &cm489 = cm480[x1];
auto &cm490 = cm481[x1];
auto &cm491 = cm482[x1];
auto &cm492 = cont_degree3[x1];
auto &cm493 = cm484[x1];
auto &cm494 = cont_degree2[x1];
auto &cm495 = cont_degree2[x1];
auto &cm496 = cont_sum1[x1];

for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm497 = cm488[x2];

auto &cm498 = cm489[x2];
auto &cm499 = cm490[x2];
auto &cm500 = cm483[x2];
auto &cm501 = cm492[x2];
auto &cm502 = cm485[x2];
auto &cm503 = cm494[x2];
auto &cm504 = cont_degree2[x2];
auto &cm505 = cont_sum1[x2];

for (int x3 = CONT_SZ; x3 < (CONT_SZ2 + CONT_SZ); ++x3) {
double tmp = 0.0;




auto &cm514 = other.cont_sum1[(x3 - CONT_SZ)];



auto &cm515 = other.cont_sum1[y2];
auto &cm516 = other.cont_degree2[y2];



auto &cm517 = other.cont_sum1[y1];
auto &cm518 = other.cont_degree2[y1];
auto &cm519 = other.cont_degree2[y1];
auto &cm520 = other.cont_degree3[y1];





tmp += (cm499 * cm514);

cm497[x3] += tmp;
}
}
}
}


for (int x0 = CONT_SZ; x0 < (CONT_SZ2 + CONT_SZ); ++x0) {
auto &cm521 = r.cont_degree4[x0];


for (int x1 = std::max({x0, CONT_SZ}); x1 < (CONT_SZ2 + CONT_SZ); ++x1) {
auto &cm530 = cm521[x1];


for (int x2 = std::max({x1, CONT_SZ}); x2 < (CONT_SZ2 + CONT_SZ); ++x2) {
auto &cm539 = cm530[x2];


for (int x3 = std::max({x2, CONT_SZ}); x3 < (CONT_SZ2 + CONT_SZ); ++x3) {
double tmp = 0.0;




auto &cm556 = other.cont_sum1[(x3 - CONT_SZ)];



auto &cm557 = other.cont_sum1[(x2 - CONT_SZ)];
auto &cm558 = other.cont_degree2[(x2 - CONT_SZ)];



auto &cm559 = other.cont_sum1[(x1 - CONT_SZ)];
auto &cm560 = other.cont_degree2[(x1 - CONT_SZ)];
auto &cm561 = other.cont_degree2[(x1 - CONT_SZ)];
auto &cm562 = other.cont_degree3[(x1 - CONT_SZ)];





tmp += (count * other.cont_degree4[(x0 - CONT_SZ)][(x1 - CONT_SZ)][(x2 - CONT_SZ)][(x3 - CONT_SZ)]);

cm539[x3] += tmp;
}
}
}
}


        }


    void clean() {
      count = 0;

      for(int i1 = 0; i1 < CONT_SZ; ++i1) {
        cont_sum1[i1] = 0;
      }

      for(int i1 = 0; i1 < CONT_SZ; ++i1) {

        for(int i2 = i1; i2 < CONT_SZ; ++i2) {
          cont_degree2[i1][i2] = 0;
        }
      }

      
      for(int i1 = 0; i1 < CONT_SZ; ++i1) {

        for(int i2 = i1; i2 < CONT_SZ; ++i2) {

          for(int i3 = i2; i3 < CONT_SZ; ++i3) {
            cont_degree3[i1][i2][i3] = 0;
          }
        }
      }

      for(int i1 = 0; i1 < CONT_SZ; ++i1) {

        for(int i2 = i1; i2 < CONT_SZ; ++i2) {

          for(int i3 = i2; i3 < CONT_SZ; ++i3) {

            for(int i4 = i3; i4 < CONT_SZ; ++i4) {
              cont_degree4[i1][i2][i3][i4] = 0;
            }
          }
        }
      }

    }    
    void reconstruct() {




for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm563 = cont_degree2[x0];


for (int x1 = 0; x1 < std::min({x0, CONT_SZ}); ++x1) {








cm563[x1] = cont_degree2[x1][x0];
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm565 = cont_degree3[x0];


for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm566 = cm565[x1];


for (int x2 = 0; x2 < std::min({CONT_SZ, (x0 + 1)}); ++x2) {











cm566[x2] = cont_degree3[x2][x0][x1];
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm567 = cont_degree3[x0];


for (int x1 = 0; x1 < std::min({CONT_SZ, (x0 + 1)}); ++x1) {
auto &cm568 = cm567[x1];


for (int x2 = x0; x2 < CONT_SZ; ++x2) {











cm568[x2] = cont_degree3[x1][x0][x2];
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm569 = cont_degree3[x0];


for (int x1 = 0; x1 < std::min({CONT_SZ, (x0 + 1)}); ++x1) {
auto &cm570 = cm569[x1];


for (int x2 = 0; x2 < std::min({CONT_SZ, (x1 + 1)}); ++x2) {











cm570[x2] = cont_degree3[x2][x1][x0];
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm571 = cont_degree3[x0];


for (int x1 = 0; x1 < CONT_SZ; ++x1) {
auto &cm572 = cm571[x1];


for (int x2 = x1; x2 < std::min({CONT_SZ, (x0 + 1)}); ++x2) {











cm572[x2] = cont_degree3[x1][x2][x0];
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm573 = cont_degree3[x0];


for (int x1 = 0; x1 < CONT_SZ; ++x1) {
auto &cm574 = cm573[x1];


for (int x2 = x0; x2 < std::min({CONT_SZ, (x1 + 1)}); ++x2) {











cm574[x2] = cont_degree3[x0][x2][x1];
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm576 = cont_degree4[x0];


for (int x1 = 0; x1 < CONT_SZ; ++x1) {
auto &cm577 = cm576[x1];


for (int x2 = x1; x2 < std::min({CONT_SZ, (x0 + 1)}); ++x2) {
auto &cm578 = cm577[x2];


for (int x3 = 0; x3 < std::min({CONT_SZ, (x1 + 1)}); ++x3) {














cm578[x3] = cont_degree4[x3][x1][x2][x0];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm579 = cont_degree4[x0];


for (int x1 = 0; x1 < std::min({CONT_SZ, (x0 + 1)}); ++x1) {
auto &cm580 = cm579[x1];


for (int x2 = 0; x2 < std::min({CONT_SZ, (x1 + 1)}); ++x2) {
auto &cm581 = cm580[x2];


for (int x3 = 0; x3 < std::min({CONT_SZ, (x2 + 1)}); ++x3) {














cm581[x3] = cont_degree4[x3][x2][x1][x0];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm582 = cont_degree4[x0];


for (int x1 = 0; x1 < CONT_SZ; ++x1) {
auto &cm583 = cm582[x1];


for (int x2 = x0; x2 < std::min({CONT_SZ, (x1 + 1)}); ++x2) {
auto &cm584 = cm583[x2];


for (int x3 = 0; x3 < std::min({CONT_SZ, (x0 + 1)}); ++x3) {














cm584[x3] = cont_degree4[x3][x0][x2][x1];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm585 = cont_degree4[x0];


for (int x1 = 0; x1 < CONT_SZ; ++x1) {
auto &cm586 = cm585[x1];


for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm587 = cm586[x2];


for (int x3 = x2; x3 < std::min({CONT_SZ, (x0 + 1)}); ++x3) {














cm587[x3] = cont_degree4[x1][x2][x3][x0];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm588 = cont_degree4[x0];


for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm589 = cm588[x1];


for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm590 = cm589[x2];


for (int x3 = 0; x3 < std::min({CONT_SZ, (x0 + 1)}); ++x3) {














cm590[x3] = cont_degree4[x3][x0][x1][x2];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm591 = cont_degree4[x0];


for (int x1 = 0; x1 < CONT_SZ; ++x1) {
auto &cm592 = cm591[x1];


for (int x2 = x0; x2 < CONT_SZ; ++x2) {
auto &cm593 = cm592[x2];


for (int x3 = x1; x3 < std::min({CONT_SZ, (x0 + 1)}); ++x3) {














cm593[x3] = cont_degree4[x1][x3][x0][x2];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm594 = cont_degree4[x0];


for (int x1 = 0; x1 < CONT_SZ; ++x1) {
auto &cm595 = cm594[x1];


for (int x2 = 0; x2 < std::min({CONT_SZ, (x0 + 1)}); ++x2) {
auto &cm596 = cm595[x2];


for (int x3 = x0; x3 < std::min({CONT_SZ, (x1 + 1)}); ++x3) {














cm596[x3] = cont_degree4[x2][x0][x3][x1];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm597 = cont_degree4[x0];


for (int x1 = 0; x1 < CONT_SZ; ++x1) {
auto &cm598 = cm597[x1];


for (int x2 = x1; x2 < std::min({CONT_SZ, (x0 + 1)}); ++x2) {
auto &cm599 = cm598[x2];


for (int x3 = x0; x3 < CONT_SZ; ++x3) {














cm599[x3] = cont_degree4[x1][x2][x0][x3];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm600 = cont_degree4[x0];


for (int x1 = 0; x1 < std::min({CONT_SZ, (x0 + 1)}); ++x1) {
auto &cm601 = cm600[x1];


for (int x2 = 0; x2 < std::min({CONT_SZ, (x1 + 1)}); ++x2) {
auto &cm602 = cm601[x2];


for (int x3 = x0; x3 < CONT_SZ; ++x3) {














cm602[x3] = cont_degree4[x2][x1][x0][x3];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm603 = cont_degree4[x0];


for (int x1 = 0; x1 < CONT_SZ; ++x1) {
auto &cm604 = cm603[x1];


for (int x2 = 0; x2 < std::min({CONT_SZ, (x1 + 1)}); ++x2) {
auto &cm605 = cm604[x2];


for (int x3 = x1; x3 < std::min({CONT_SZ, (x0 + 1)}); ++x3) {














cm605[x3] = cont_degree4[x2][x1][x3][x0];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm606 = cont_degree4[x0];


for (int x1 = 0; x1 < std::min({CONT_SZ, (x0 + 1)}); ++x1) {
auto &cm607 = cm606[x1];


for (int x2 = 0; x2 < CONT_SZ; ++x2) {
auto &cm608 = cm607[x2];


for (int x3 = x0; x3 < std::min({CONT_SZ, (x2 + 1)}); ++x3) {














cm608[x3] = cont_degree4[x1][x0][x3][x2];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm609 = cont_degree4[x0];


for (int x1 = 0; x1 < CONT_SZ; ++x1) {
auto &cm610 = cm609[x1];


for (int x2 = x0; x2 < std::min({CONT_SZ, (x1 + 1)}); ++x2) {
auto &cm611 = cm610[x2];


for (int x3 = x1; x3 < CONT_SZ; ++x3) {














cm611[x3] = cont_degree4[x0][x2][x1][x3];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm612 = cont_degree4[x0];


for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm613 = cm612[x1];


for (int x2 = 0; x2 < CONT_SZ; ++x2) {
auto &cm614 = cm613[x2];


for (int x3 = x2; x3 < std::min({CONT_SZ, (x0 + 1)}); ++x3) {














cm614[x3] = cont_degree4[x2][x3][x0][x1];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm615 = cont_degree4[x0];


for (int x1 = 0; x1 < std::min({CONT_SZ, (x0 + 1)}); ++x1) {
auto &cm616 = cm615[x1];


for (int x2 = x0; x2 < CONT_SZ; ++x2) {
auto &cm617 = cm616[x2];


for (int x3 = x2; x3 < CONT_SZ; ++x3) {














cm617[x3] = cont_degree4[x1][x0][x2][x3];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm618 = cont_degree4[x0];


for (int x1 = 0; x1 < CONT_SZ; ++x1) {
auto &cm619 = cm618[x1];


for (int x2 = x0; x2 < CONT_SZ; ++x2) {
auto &cm620 = cm619[x2];


for (int x3 = x2; x3 < std::min({CONT_SZ, (x1 + 1)}); ++x3) {














cm620[x3] = cont_degree4[x0][x2][x3][x1];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm621 = cont_degree4[x0];


for (int x1 = 0; x1 < CONT_SZ; ++x1) {
auto &cm622 = cm621[x1];


for (int x2 = 0; x2 < std::min({CONT_SZ, (x1 + 1)}); ++x2) {
auto &cm623 = cm622[x2];


for (int x3 = x0; x3 < std::min({CONT_SZ, (x2 + 1)}); ++x3) {














cm623[x3] = cont_degree4[x0][x3][x2][x1];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm624 = cont_degree4[x0];


for (int x1 = 0; x1 < CONT_SZ; ++x1) {
auto &cm625 = cm624[x1];


for (int x2 = x1; x2 < CONT_SZ; ++x2) {
auto &cm626 = cm625[x2];


for (int x3 = x0; x3 < std::min({CONT_SZ, (x1 + 1)}); ++x3) {














cm626[x3] = cont_degree4[x0][x3][x1][x2];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm627 = cont_degree4[x0];


for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm628 = cm627[x1];


for (int x2 = 0; x2 < std::min({CONT_SZ, (x0 + 1)}); ++x2) {
auto &cm629 = cm628[x2];


for (int x3 = 0; x3 < std::min({CONT_SZ, (x2 + 1)}); ++x3) {














cm629[x3] = cont_degree4[x3][x2][x0][x1];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm630 = cont_degree4[x0];


for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm631 = cm630[x1];


for (int x2 = 0; x2 < std::min({CONT_SZ, (x0 + 1)}); ++x2) {
auto &cm632 = cm631[x2];


for (int x3 = x1; x3 < CONT_SZ; ++x3) {














cm632[x3] = cont_degree4[x2][x0][x1][x3];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm633 = cont_degree4[x0];


for (int x1 = 0; x1 < std::min({CONT_SZ, (x0 + 1)}); ++x1) {
auto &cm634 = cm633[x1];


for (int x2 = x0; x2 < CONT_SZ; ++x2) {
auto &cm635 = cm634[x2];


for (int x3 = 0; x3 < std::min({CONT_SZ, (x1 + 1)}); ++x3) {














cm635[x3] = cont_degree4[x3][x1][x0][x2];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm636 = cont_degree4[x0];


for (int x1 = 0; x1 < CONT_SZ; ++x1) {
auto &cm637 = cm636[x1];


for (int x2 = 0; x2 < std::min({CONT_SZ, (x0 + 1)}); ++x2) {
auto &cm638 = cm637[x2];


for (int x3 = x1; x3 < std::min({CONT_SZ, (x2 + 1)}); ++x3) {














cm638[x3] = cont_degree4[x1][x3][x2][x0];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm639 = cont_degree4[x0];


for (int x1 = 0; x1 < std::min({CONT_SZ, (x0 + 1)}); ++x1) {
auto &cm640 = cm639[x1];


for (int x2 = 0; x2 < CONT_SZ; ++x2) {
auto &cm641 = cm640[x2];


for (int x3 = x2; x3 < std::min({CONT_SZ, (x1 + 1)}); ++x3) {














cm641[x3] = cont_degree4[x2][x3][x1][x0];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
auto &cm642 = cont_degree4[x0];


for (int x1 = x0; x1 < CONT_SZ; ++x1) {
auto &cm643 = cm642[x1];


for (int x2 = 0; x2 < CONT_SZ; ++x2) {
auto &cm644 = cm643[x2];


for (int x3 = x1; x3 < std::min({CONT_SZ, (x2 + 1)}); ++x3) {














cm644[x3] = cont_degree4[x0][x1][x3][x2];
}
}
}
}


        std::cerr << cont_sum1[CONT_SZ - 1];
        std::cerr << cont_degree2[CONT_SZ - 1][CONT_SZ - 1];
        
        std::cerr << cont_degree3[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1];
        std::cerr << cont_degree4[CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1][CONT_SZ - 1];

    }

};

template <typename T, size_t CONT_SZ, size_t CAT_SZ>
RingCofactor<T, CONT_SZ, CAT_SZ> operator*(long int alpha, const RingCofactor<T, CONT_SZ, CAT_SZ>& c) {
    if (alpha == 1L) return c;
    return c.multiply(alpha);
}

template <typename T>
inline double convert(T x) { return x; }

template <typename... Args>
RingCofactor<double, sizeof...(Args), 0> Uliftcont(Args&&... args) {
    return RingCofactor<double, sizeof...(Args), 0>(convert(args)...);
}

template <typename... Args>
RingCofactor<double, 0, sizeof...(Args)> Uliftcat(Args&&... args) {
    return RingCofactor<double, 0, sizeof...(Args)>(true, args...);
}

template <typename T, int CONT_SZ, int CAT_SZ>
std::ostream& operator<<(std::ostream& os, const RingCofactor<T, CONT_SZ, CAT_SZ>& v) {
os << "Cofactor: <CONT_SZ: " << CONT_SZ << ", CAT_SZ: " << CAT_SZ << ">\n";
  os << v.count << "\n";
  os << "cont_sum1:\n";
  for (int i = 0; i < CONT_SZ; ++i) {
    os << v.cont_sum1[i] << ((i < CONT_SZ - 1) ? ", " : "\n");
  }

  os << "cont_degree2:\n";
  for (int i = 0; i < CONT_SZ; ++i) {
    for (int j = 0; j < CONT_SZ; ++j) {
        os << v.cont_degree2[i][j] << ", ";
    }
  }
  os << "\n";

  
  os << "cont_degree3:\n";
  for (int i = 0; i < CONT_SZ; ++i) {
    for (int j = 0; j < CONT_SZ; ++j) {
        for (int k = 0; k < CONT_SZ; ++k) {
            os << v.cont_degree3[i][j][k] << ", ";
        }
    }
  }
  os << "\n";

  os << "cont_degree4:\n";
  for (int i = 0; i < CONT_SZ; ++i) {
    for (int j = 0; j < CONT_SZ; ++j) {
        for (int k = 0; k < CONT_SZ; ++k) {
            for (int l = 0; l < CONT_SZ; ++l) {
                os << v.cont_degree4[i][j][k][l] << ", ";
            }
        }
    }
  }
  os << "\n";

  return os;
}

#endif /* RING_COFACTOR_HPP */
