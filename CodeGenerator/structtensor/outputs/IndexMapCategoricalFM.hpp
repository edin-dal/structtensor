#pragma once

#include <tuple>
#include <map>
#include <array>
#include <type_traits>


template <size_t CONT_SZ, size_t CAT_SZ>
class IndexMap {
  public:
    static constexpr size_t CONT_DEG2_SZ = (CONT_SZ - 1) * CONT_SZ / 2;
    static constexpr size_t CAT_DEG2_SZ = (CAT_SZ - 1) * CAT_SZ / 2;
    static constexpr size_t CONT_CAT_DEG2_SZ = CONT_SZ * CAT_SZ;
    
    static constexpr size_t CONT_DEG3_SZ = CONT_SZ * (CONT_SZ - 1) * (CONT_SZ - 2) / 6 + CONT_SZ * (CONT_SZ - 1);
    static constexpr size_t CONT2_CAT_DEG3_SZ = CONT_SZ * (CONT_SZ + 1) / 2 * CAT_SZ;
    static constexpr size_t CONT_CAT2_DEG3_SZ = CONT_SZ * CAT_SZ * (CAT_SZ + 1) / 2;
    static constexpr size_t CAT_DEG3_SZ = CAT_SZ * (CAT_SZ - 1) * (CAT_SZ - 2) / 6 + CAT_SZ * (CAT_SZ - 1);

    static constexpr size_t CONT_DEG4_SZ = CONT_SZ * (CONT_SZ - 1) * (CONT_SZ - 2) * (CONT_SZ - 3) / 24 + CONT_SZ * (CONT_SZ - 1) * (CONT_SZ - 2) / 2;
    static constexpr size_t CONT3_CAT_DEG4_SZ = (CONT_SZ * (CONT_SZ - 1) * (CONT_SZ - 2) / 6 + CONT_SZ * (CONT_SZ - 1)) * CAT_SZ;
    static constexpr size_t CONT2_CAT2_DEG4_SZ = CONT_SZ * (CONT_SZ - 1) / 2 * CAT_SZ * (CAT_SZ - 1) / 2 + CONT_SZ * (CONT_SZ - 1) / 2 * CAT_SZ + CONT_SZ * CAT_SZ * (CAT_SZ - 1) / 2;
    static constexpr size_t CONT_CAT3_DEG4_SZ = (CAT_SZ * (CAT_SZ - 1) * (CAT_SZ - 2) / 6 + CAT_SZ * (CAT_SZ - 1)) * CONT_SZ;
    static constexpr size_t CAT_DEG4_SZ = CAT_SZ * (CAT_SZ - 1) * (CAT_SZ - 2) * (CAT_SZ - 3) / 24 + CAT_SZ * (CAT_SZ - 1) * (CAT_SZ - 2) / 2;

    std::map<std::array<size_t, 1>, size_t> map_count; 
    std::map<size_t, std::array<size_t, 1>> rev_count;
    std::map<std::array<size_t, 1>, size_t> map_cont_sum1; 
    std::map<size_t, std::array<size_t, 1>> rev_cont_sum1;
    std::map<std::array<size_t, 1>, size_t> map_cont_sum2; 
    std::map<size_t, std::array<size_t, 1>> rev_cont_sum2;
    std::map<std::array<size_t, 2>, size_t> map_cont_sum4; 
    std::map<size_t, std::array<size_t, 2>> rev_cont_sum4;
    std::map<std::array<size_t, 2>, size_t> map_cont_degree2;
    std::map<size_t, std::array<size_t, 2>> rev_cont_degree2;
    std::map<std::array<size_t, 1>, size_t> map_cat_sum1; 
    std::map<size_t, std::array<size_t, 1>> rev_cat_sum1;
    std::map<std::array<size_t, 1>, size_t> map_cat_sum2; 
    std::map<size_t, std::array<size_t, 1>> rev_cat_sum2;
    std::map<std::array<size_t, 2>, size_t> map_cat_sum4; 
    std::map<size_t, std::array<size_t, 2>> rev_cat_sum4;
    std::map<std::array<size_t, 2>, size_t> map_cat_degree2; 
    std::map<size_t, std::array<size_t, 2>> rev_cat_degree2;
    std::map<std::array<size_t, 2>, size_t> map_cont_cat_sum4; 
    std::map<size_t, std::array<size_t, 2>> rev_cont_cat_sum4;
    std::map<std::array<size_t, 2>, size_t> map_cont_cat_degree2; 
    std::map<size_t, std::array<size_t, 2>> rev_cont_cat_degree2;
    std::map<std::array<size_t, 3>, size_t> map_cont_degree3; 
    std::map<size_t, std::array<size_t, 3>> rev_cont_degree3;
    std::map<std::array<size_t, 3>, size_t> map_cont2_cat_degree3; 
    std::map<size_t, std::array<size_t, 3>> rev_cont2_cat_degree3;
    std::map<std::array<size_t, 3>, size_t> map_cont_cat2_degree3; 
    std::map<size_t, std::array<size_t, 3>> rev_cont_cat2_degree3;
    std::map<std::array<size_t, 3>, size_t> map_cat_degree3; 
    std::map<size_t, std::array<size_t, 3>> rev_cat_degree3;
    std::map<std::array<size_t, 4>, size_t> map_cont_degree4; 
    std::map<size_t, std::array<size_t, 4>> rev_cont_degree4;
    std::map<std::array<size_t, 4>, size_t> map_cont3_cat_degree4; 
    std::map<size_t, std::array<size_t, 4>> rev_cont3_cat_degree4;
    std::map<std::array<size_t, 4>, size_t> map_cont2_cat2_degree4; 
    std::map<size_t, std::array<size_t, 4>> rev_cont2_cat2_degree4;
    std::map<std::array<size_t, 4>, size_t> map_cont_cat3_degree4; 
    std::map<size_t, std::array<size_t, 4>> rev_cont_cat3_degree4;
    std::map<std::array<size_t, 4>, size_t> map_cat_degree4; 
    std::map<size_t, std::array<size_t, 4>> rev_cat_degree4;


    explicit IndexMap() {
        // static_assert(CONT_SZ == 0 || CAT_SZ == 0, "Can't have both continuous and categorical at the same time");
        size_t cnt = 0;
        map_count[{0}] = 0;
        rev_count[0] = {0};
        for (size_t i = 0; i < CONT_SZ; i++) {
            map_cont_sum1[{i}] = i;
            rev_cont_sum1[i] = {i};
            map_cont_sum2[{i}] = i;
            rev_cont_sum2[i] = {i};
        }
        for (size_t i = 0; i < CONT_SZ; i++) {
            for (size_t j = i + 1; j < CONT_SZ; j++) {
                map_cont_sum4[{i, j}] = cnt;
                rev_cont_sum4[cnt] = {i, j};
                map_cont_degree2[{i, j}] = cnt;
                rev_cont_degree2[cnt++] = {i, j};
            }
        }
        cnt = 0;
        for (size_t i = 0; i < CONT_SZ; i++) {
          for (size_t j = i + 1; j < CONT_SZ; j++) {
            map_cont_degree3[{i, i, j}] = cnt;
            rev_cont_degree3[cnt++] = {i, i, j};
            map_cont_degree3[{i, j, j}] = cnt;
            rev_cont_degree3[cnt++] = {i, j, j};
            for (size_t k = j + 1; k < CONT_SZ; k++) {
              map_cont_degree3[{i, j, k}] = cnt;
              rev_cont_degree3[cnt++] = {i, j, k};
            }
          }
        }
        cnt = 0;
        for (size_t i = 0; i < CONT_SZ; i++) {
          for (size_t j = i + 1; j < CONT_SZ; j++) {
            for (size_t k = j + 1; k < CONT_SZ; k++) {
              map_cont_degree4[{i, i, j, k}] = cnt;
              rev_cont_degree4[cnt++] = {i, i, j, k};
              map_cont_degree4[{i, j, j, k}] = cnt;
              rev_cont_degree4[cnt++] = {i, j, j, k};
              map_cont_degree4[{i, j, k, k}] = cnt;
              rev_cont_degree4[cnt++] = {i, j, k, k};
              for (size_t l = k + 1; l < CONT_SZ; l++) {
                map_cont_degree4[{i, j, k, l}] = cnt;
                rev_cont_degree4[cnt++] = {i, j, k, l};
              }
            }
          }
        }

        cnt = 0;
        for (size_t i = 0; i < CAT_SZ; i++) {
            map_cat_sum1[{i}] = i;
            rev_cat_sum1[i] = {i};
            map_cat_sum2[{i}] = i;
            rev_cat_sum2[i] = {i};
        }
        for (size_t i = 0; i < CAT_SZ; i++) {
            for (size_t j = i + 1; j < CAT_SZ; j++) {
                map_cat_sum4[{i, j}] = cnt;
                rev_cat_sum4[cnt] = {i, j};
                map_cat_degree2[{i, j}] = cnt;
                rev_cat_degree2[cnt++] = {i, j};
            }
        }
        cnt = 0;
        for (size_t i = 0; i < CAT_SZ; i++) {
          for (size_t j = i + 1; j < CAT_SZ; j++) {
            map_cat_degree3[{i, i, j}] = cnt;
            rev_cat_degree3[cnt++] = {i, i, j};
            map_cat_degree3[{i, j, j}] = cnt;
            rev_cat_degree3[cnt++] = {i, j, j};
            for (size_t k = j + 1; k < CAT_SZ; k++) {
              map_cat_degree3[{i, j, k}] = cnt;
              rev_cat_degree3[cnt++] = {i, j, k};
            }
          }
        }
        cnt = 0;
        for (size_t i = 0; i < CAT_SZ; i++) {
          for (size_t j = i + 1; j < CAT_SZ; j++) {
            for (size_t k = j + 1; k < CAT_SZ; k++) {
              map_cat_degree4[{i, i, j, k}] = cnt;
              rev_cat_degree4[cnt++] = {i, i, j, k};
              map_cat_degree4[{i, j, j, k}] = cnt;
              rev_cat_degree4[cnt++] = {i, j, j, k};
              map_cat_degree4[{i, j, k, k}] = cnt;
              rev_cat_degree4[cnt++] = {i, j, k, k};
              for (size_t l = k + 1; l < CAT_SZ; l++) {
                map_cat_degree4[{i, j, k, l}] = cnt;
                rev_cat_degree4[cnt++] = {i, j, k, l};
              }
            }
          }
        }
    }


    template <size_t CONT_SZ2, size_t CAT_SZ2>
    IndexMap<CONT_SZ + CONT_SZ2, CAT_SZ + CAT_SZ2> operator*(const IndexMap<CONT_SZ2, CAT_SZ2>& other) const {
        return this->multiply_(other);
    }

  private:
    template <size_t CONT_SZ2, size_t CAT_SZ2>
    IndexMap<CONT_SZ + CONT_SZ2, CAT_SZ + CAT_SZ2> multiply_(const IndexMap<CONT_SZ2, CAT_SZ2>& other) const {
        IndexMap<CONT_SZ + CONT_SZ2, CAT_SZ + CAT_SZ2> r;

        std::array<size_t, 1> val1 = {0};
;
std::array<size_t, 1> val2 = {0};
;
std::array<size_t, 1> val3 = {0};
;

size_t cnt8 = 0;
for (size_t i4 = 0; i4 < 1; i4++) {
  val2 = rev_count.find(i4)->second;
  for (size_t j5 = 0; j5 < 1; j5++) {
    val3 = other.rev_count.find(j5)->second;
    for (size_t r7 = 0; r7 < 1; r7++) {
      for (size_t k6 = 0; k6 < 0; k6++) {
        val1[r7 * 0 + k6] = val2[k6] + 0;
      }
    }
    for (size_t r7 = 0; r7 < 1; r7++) {
      for (size_t k6 = 0; k6 < 0; k6++) {
        val1[r7 * 0 + k6 + 0 * 1] = val3[k6] + 0;
      }
    }
    for (size_t r7 = 0; r7 < 1; r7++) {
      for (size_t k6 = 0; k6 < 0; k6++) {
        val1[r7 * 0 + k6 + 0 * 1 + 0 * 1] = val2[0 + k6] + 0;
      }
    }
    for (size_t r7 = 0; r7 < 1; r7++) {
      for (size_t k6 = 0; k6 < 0; k6++) {
        val1[r7 * 0 + k6 + 0 * 1 + 0 * 1 + 0 * 1] = val3[0 + k6] + 0;
      }
    }
    r.map_count[val1] = 0 + cnt8;
    r.rev_count[0 + cnt8] = val1;
    cnt8++;
  }
}
;
;
;
size_t cnt9 = 0;
;
std::array<size_t, 1 + 0> val10;
;
std::array<size_t, 1 + 0> val11;
;
;

size_t cnt16 = 0;
for (size_t i12 = 0; i12 < CONT_SZ; i12++) {
  val11 = rev_cont_sum1.find(i12)->second;
  for (size_t j13 = 0; j13 < 1; j13++) {
    val3 = other.rev_count.find(j13)->second;
    for (size_t r15 = 0; r15 < 1; r15++) {
      for (size_t k14 = 0; k14 < 1; k14++) {
        val10[r15 * 1 + k14] = val11[k14] + 0;
      }
    }
    for (size_t r15 = 0; r15 < 1; r15++) {
      for (size_t k14 = 0; k14 < 0; k14++) {
        val10[r15 * 0 + k14 + 1 * 1] = val3[k14] + 0;
      }
    }
    for (size_t r15 = 0; r15 < 1; r15++) {
      for (size_t k14 = 0; k14 < 0; k14++) {
        val10[r15 * 0 + k14 + 1 * 1 + 0 * 1] = val11[1 + k14] + 0;
      }
    }
    for (size_t r15 = 0; r15 < 1; r15++) {
      for (size_t k14 = 0; k14 < 0; k14++) {
        val10[r15 * 0 + k14 + 1 * 1 + 0 * 1 + 0 * 1] = val3[0 + k14] + 0;
      }
    }
    r.map_cont_sum1[val10] = cnt9 + cnt16;
    r.rev_cont_sum1[cnt9 + cnt16] = val10;
    cnt16++;
  }
}
;
;

cnt9 += (CONT_SZ) * (1);
;
;
std::array<size_t, 1 + 0> val17;
;
;
std::array<size_t, 1 + 0> val18;
;

size_t cnt23 = 0;
for (size_t i19 = 0; i19 < 1; i19++) {
  val2 = rev_count.find(i19)->second;
  for (size_t j20 = 0; j20 < CONT_SZ2; j20++) {
    val18 = other.rev_cont_sum1.find(j20)->second;
    for (size_t r22 = 0; r22 < 1; r22++) {
      for (size_t k21 = 0; k21 < 0; k21++) {
        val17[r22 * 0 + k21] = val2[k21] + 0;
      }
    }
    for (size_t r22 = 0; r22 < 1; r22++) {
      for (size_t k21 = 0; k21 < 1; k21++) {
        val17[r22 * 1 + k21 + 0 * 1] = val18[k21] + CONT_SZ;
      }
    }
    for (size_t r22 = 0; r22 < 1; r22++) {
      for (size_t k21 = 0; k21 < 0; k21++) {
        val17[r22 * 0 + k21 + 0 * 1 + 1 * 1] = val2[0 + k21] + 0;
      }
    }
    for (size_t r22 = 0; r22 < 1; r22++) {
      for (size_t k21 = 0; k21 < 0; k21++) {
        val17[r22 * 0 + k21 + 0 * 1 + 1 * 1 + 0 * 1] = val18[1 + k21] + 0;
      }
    }
    r.map_cont_sum1[val17] = cnt9 + cnt23;
    r.rev_cont_sum1[cnt9 + cnt23] = val17;
    cnt23++;
  }
}
;
;

cnt9 += (1) * (CONT_SZ2);
;
;
;
size_t cnt24 = 0;
;
std::array<size_t, 1 + 0> val25;
;
std::array<size_t, 1 + 0> val26;
;
;

size_t cnt31 = 0;
for (size_t i27 = 0; i27 < CONT_SZ; i27++) {
  val26 = rev_cont_sum2.find(i27)->second;
  for (size_t j28 = 0; j28 < 1; j28++) {
    val3 = other.rev_count.find(j28)->second;
    for (size_t r30 = 0; r30 < 1; r30++) {
      for (size_t k29 = 0; k29 < 1; k29++) {
        val25[r30 * 1 + k29] = val26[k29] + 0;
      }
    }
    for (size_t r30 = 0; r30 < 1; r30++) {
      for (size_t k29 = 0; k29 < 0; k29++) {
        val25[r30 * 0 + k29 + 1 * 1] = val3[k29] + 0;
      }
    }
    for (size_t r30 = 0; r30 < 1; r30++) {
      for (size_t k29 = 0; k29 < 0; k29++) {
        val25[r30 * 0 + k29 + 1 * 1 + 0 * 1] = val26[1 + k29] + 0;
      }
    }
    for (size_t r30 = 0; r30 < 1; r30++) {
      for (size_t k29 = 0; k29 < 0; k29++) {
        val25[r30 * 0 + k29 + 1 * 1 + 0 * 1 + 0 * 1] = val3[0 + k29] + 0;
      }
    }
    r.map_cont_sum2[val25] = cnt24 + cnt31;
    r.rev_cont_sum2[cnt24 + cnt31] = val25;
    cnt31++;
  }
}
;
;

cnt24 += (CONT_SZ) * (1);
;
;
std::array<size_t, 1 + 0> val32;
;
;
std::array<size_t, 1 + 0> val33;
;

size_t cnt38 = 0;
for (size_t i34 = 0; i34 < 1; i34++) {
  val2 = rev_count.find(i34)->second;
  for (size_t j35 = 0; j35 < CONT_SZ2; j35++) {
    val33 = other.rev_cont_sum2.find(j35)->second;
    for (size_t r37 = 0; r37 < 1; r37++) {
      for (size_t k36 = 0; k36 < 0; k36++) {
        val32[r37 * 0 + k36] = val2[k36] + 0;
      }
    }
    for (size_t r37 = 0; r37 < 1; r37++) {
      for (size_t k36 = 0; k36 < 1; k36++) {
        val32[r37 * 1 + k36 + 0 * 1] = val33[k36] + CONT_SZ;
      }
    }
    for (size_t r37 = 0; r37 < 1; r37++) {
      for (size_t k36 = 0; k36 < 0; k36++) {
        val32[r37 * 0 + k36 + 0 * 1 + 1 * 1] = val2[0 + k36] + 0;
      }
    }
    for (size_t r37 = 0; r37 < 1; r37++) {
      for (size_t k36 = 0; k36 < 0; k36++) {
        val32[r37 * 0 + k36 + 0 * 1 + 1 * 1 + 0 * 1] = val33[1 + k36] + 0;
      }
    }
    r.map_cont_sum2[val32] = cnt24 + cnt38;
    r.rev_cont_sum2[cnt24 + cnt38] = val32;
    cnt38++;
  }
}
;
;

cnt24 += (1) * (CONT_SZ2);
;
;
;
size_t cnt39 = 0;
;
std::array<size_t, 2 + 0> val40;
;
std::array<size_t, 2 + 0> val41;
;
;

size_t cnt46 = 0;
for (size_t i42 = 0; i42 < CONT_SZ * (CONT_SZ - 1) / 2; i42++) {
  val41 = rev_cont_sum4.find(i42)->second;
  for (size_t j43 = 0; j43 < 1; j43++) {
    val3 = other.rev_count.find(j43)->second;
    for (size_t r45 = 0; r45 < 1; r45++) {
      for (size_t k44 = 0; k44 < 2; k44++) {
        val40[r45 * 2 + k44] = val41[k44] + 0;
      }
    }
    for (size_t r45 = 0; r45 < 1; r45++) {
      for (size_t k44 = 0; k44 < 0; k44++) {
        val40[r45 * 0 + k44 + 2 * 1] = val3[k44] + 0;
      }
    }
    for (size_t r45 = 0; r45 < 1; r45++) {
      for (size_t k44 = 0; k44 < 0; k44++) {
        val40[r45 * 0 + k44 + 2 * 1 + 0 * 1] = val41[2 + k44] + 0;
      }
    }
    for (size_t r45 = 0; r45 < 1; r45++) {
      for (size_t k44 = 0; k44 < 0; k44++) {
        val40[r45 * 0 + k44 + 2 * 1 + 0 * 1 + 0 * 1] = val3[0 + k44] + 0;
      }
    }
    r.map_cont_sum4[val40] = cnt39 + cnt46;
    r.rev_cont_sum4[cnt39 + cnt46] = val40;
    cnt46++;
  }
}
;
;

cnt39 += (CONT_SZ * (CONT_SZ - 1) / 2) * (1);
;
;
std::array<size_t, 2 + 0> val47;
;
;
std::array<size_t, 2 + 0> val48;
;

size_t cnt53 = 0;
for (size_t i49 = 0; i49 < 1; i49++) {
  val2 = rev_count.find(i49)->second;
  for (size_t j50 = 0; j50 < CONT_SZ2 * (CONT_SZ2 - 1) / 2; j50++) {
    val48 = other.rev_cont_sum4.find(j50)->second;
    for (size_t r52 = 0; r52 < 1; r52++) {
      for (size_t k51 = 0; k51 < 0; k51++) {
        val47[r52 * 0 + k51] = val2[k51] + 0;
      }
    }
    for (size_t r52 = 0; r52 < 1; r52++) {
      for (size_t k51 = 0; k51 < 2; k51++) {
        val47[r52 * 2 + k51 + 0 * 1] = val48[k51] + CONT_SZ;
      }
    }
    for (size_t r52 = 0; r52 < 1; r52++) {
      for (size_t k51 = 0; k51 < 0; k51++) {
        val47[r52 * 0 + k51 + 0 * 1 + 2 * 1] = val2[0 + k51] + 0;
      }
    }
    for (size_t r52 = 0; r52 < 1; r52++) {
      for (size_t k51 = 0; k51 < 0; k51++) {
        val47[r52 * 0 + k51 + 0 * 1 + 2 * 1 + 0 * 1] = val48[2 + k51] + 0;
      }
    }
    r.map_cont_sum4[val47] = cnt39 + cnt53;
    r.rev_cont_sum4[cnt39 + cnt53] = val47;
    cnt53++;
  }
}
;
;

cnt39 += (1) * (CONT_SZ2 * (CONT_SZ2 - 1) / 2);
;
;
std::array<size_t, 2 + 0> val54;
;
;
;

size_t cnt59 = 0;
for (size_t i55 = 0; i55 < CONT_SZ; i55++) {
  val26 = rev_cont_sum2.find(i55)->second;
  for (size_t j56 = 0; j56 < CONT_SZ2; j56++) {
    val33 = other.rev_cont_sum2.find(j56)->second;
    for (size_t r58 = 0; r58 < 1; r58++) {
      for (size_t k57 = 0; k57 < 1; k57++) {
        val54[r58 * 1 + k57] = val26[k57] + 0;
      }
    }
    for (size_t r58 = 0; r58 < 1; r58++) {
      for (size_t k57 = 0; k57 < 1; k57++) {
        val54[r58 * 1 + k57 + 1 * 1] = val33[k57] + CONT_SZ;
      }
    }
    for (size_t r58 = 0; r58 < 1; r58++) {
      for (size_t k57 = 0; k57 < 0; k57++) {
        val54[r58 * 0 + k57 + 1 * 1 + 1 * 1] = val26[1 + k57] + 0;
      }
    }
    for (size_t r58 = 0; r58 < 1; r58++) {
      for (size_t k57 = 0; k57 < 0; k57++) {
        val54[r58 * 0 + k57 + 1 * 1 + 1 * 1 + 0 * 1] = val33[1 + k57] + 0;
      }
    }
    r.map_cont_sum4[val54] = cnt39 + cnt59;
    r.rev_cont_sum4[cnt39 + cnt59] = val54;
    cnt59++;
  }
}
;
;

cnt39 += (CONT_SZ) * (CONT_SZ2);
;
;
;
size_t cnt60 = 0;
;
std::array<size_t, 2 + 0> val61;
;
std::array<size_t, 2 + 0> val62;
;
;

size_t cnt67 = 0;
for (size_t i63 = 0; i63 < CONT_SZ * (CONT_SZ - 1) / 2; i63++) {
  val62 = rev_cont_degree2.find(i63)->second;
  for (size_t j64 = 0; j64 < 1; j64++) {
    val3 = other.rev_count.find(j64)->second;
    for (size_t r66 = 0; r66 < 1; r66++) {
      for (size_t k65 = 0; k65 < 2; k65++) {
        val61[r66 * 2 + k65] = val62[k65] + 0;
      }
    }
    for (size_t r66 = 0; r66 < 1; r66++) {
      for (size_t k65 = 0; k65 < 0; k65++) {
        val61[r66 * 0 + k65 + 2 * 1] = val3[k65] + 0;
      }
    }
    for (size_t r66 = 0; r66 < 1; r66++) {
      for (size_t k65 = 0; k65 < 0; k65++) {
        val61[r66 * 0 + k65 + 2 * 1 + 0 * 1] = val62[2 + k65] + 0;
      }
    }
    for (size_t r66 = 0; r66 < 1; r66++) {
      for (size_t k65 = 0; k65 < 0; k65++) {
        val61[r66 * 0 + k65 + 2 * 1 + 0 * 1 + 0 * 1] = val3[0 + k65] + 0;
      }
    }
    r.map_cont_degree2[val61] = cnt60 + cnt67;
    r.rev_cont_degree2[cnt60 + cnt67] = val61;
    cnt67++;
  }
}
;
;

cnt60 += (CONT_SZ * (CONT_SZ - 1) / 2) * (1);
;
;
std::array<size_t, 2 + 0> val68;
;
;
std::array<size_t, 2 + 0> val69;
;

size_t cnt74 = 0;
for (size_t i70 = 0; i70 < 1; i70++) {
  val2 = rev_count.find(i70)->second;
  for (size_t j71 = 0; j71 < CONT_SZ2 * (CONT_SZ2 - 1) / 2; j71++) {
    val69 = other.rev_cont_degree2.find(j71)->second;
    for (size_t r73 = 0; r73 < 1; r73++) {
      for (size_t k72 = 0; k72 < 0; k72++) {
        val68[r73 * 0 + k72] = val2[k72] + 0;
      }
    }
    for (size_t r73 = 0; r73 < 1; r73++) {
      for (size_t k72 = 0; k72 < 2; k72++) {
        val68[r73 * 2 + k72 + 0 * 1] = val69[k72] + CONT_SZ;
      }
    }
    for (size_t r73 = 0; r73 < 1; r73++) {
      for (size_t k72 = 0; k72 < 0; k72++) {
        val68[r73 * 0 + k72 + 0 * 1 + 2 * 1] = val2[0 + k72] + 0;
      }
    }
    for (size_t r73 = 0; r73 < 1; r73++) {
      for (size_t k72 = 0; k72 < 0; k72++) {
        val68[r73 * 0 + k72 + 0 * 1 + 2 * 1 + 0 * 1] = val69[2 + k72] + 0;
      }
    }
    r.map_cont_degree2[val68] = cnt60 + cnt74;
    r.rev_cont_degree2[cnt60 + cnt74] = val68;
    cnt74++;
  }
}
;
;

cnt60 += (1) * (CONT_SZ2 * (CONT_SZ2 - 1) / 2);
;
;
std::array<size_t, 2 + 0> val75;
;
;
;

size_t cnt80 = 0;
for (size_t i76 = 0; i76 < CONT_SZ; i76++) {
  val11 = rev_cont_sum1.find(i76)->second;
  for (size_t j77 = 0; j77 < CONT_SZ2; j77++) {
    val18 = other.rev_cont_sum1.find(j77)->second;
    for (size_t r79 = 0; r79 < 1; r79++) {
      for (size_t k78 = 0; k78 < 1; k78++) {
        val75[r79 * 1 + k78] = val11[k78] + 0;
      }
    }
    for (size_t r79 = 0; r79 < 1; r79++) {
      for (size_t k78 = 0; k78 < 1; k78++) {
        val75[r79 * 1 + k78 + 1 * 1] = val18[k78] + CONT_SZ;
      }
    }
    for (size_t r79 = 0; r79 < 1; r79++) {
      for (size_t k78 = 0; k78 < 0; k78++) {
        val75[r79 * 0 + k78 + 1 * 1 + 1 * 1] = val11[1 + k78] + 0;
      }
    }
    for (size_t r79 = 0; r79 < 1; r79++) {
      for (size_t k78 = 0; k78 < 0; k78++) {
        val75[r79 * 0 + k78 + 1 * 1 + 1 * 1 + 0 * 1] = val18[1 + k78] + 0;
      }
    }
    r.map_cont_degree2[val75] = cnt60 + cnt80;
    r.rev_cont_degree2[cnt60 + cnt80] = val75;
    cnt80++;
  }
}
;
;

cnt60 += (CONT_SZ) * (CONT_SZ2);
;
;
;
size_t cnt81 = 0;
;
std::array<size_t, 0 + 1> val82;
;
std::array<size_t, 0 + 1> val83;
;
;

size_t cnt88 = 0;
for (size_t i84 = 0; i84 < CAT_SZ; i84++) {
  val83 = rev_cat_sum1.find(i84)->second;
  for (size_t j85 = 0; j85 < 1; j85++) {
    val3 = other.rev_count.find(j85)->second;
    for (size_t r87 = 0; r87 < 1; r87++) {
      for (size_t k86 = 0; k86 < 0; k86++) {
        val82[r87 * 0 + k86] = val83[k86] + 0;
      }
    }
    for (size_t r87 = 0; r87 < 1; r87++) {
      for (size_t k86 = 0; k86 < 0; k86++) {
        val82[r87 * 0 + k86 + 0 * 1] = val3[k86] + 0;
      }
    }
    for (size_t r87 = 0; r87 < 1; r87++) {
      for (size_t k86 = 0; k86 < 1; k86++) {
        val82[r87 * 1 + k86 + 0 * 1 + 0 * 1] = val83[0 + k86] + 0;
      }
    }
    for (size_t r87 = 0; r87 < 1; r87++) {
      for (size_t k86 = 0; k86 < 0; k86++) {
        val82[r87 * 0 + k86 + 0 * 1 + 0 * 1 + 1 * 1] = val3[0 + k86] + 0;
      }
    }
    r.map_cat_sum1[val82] = cnt81 + cnt88;
    r.rev_cat_sum1[cnt81 + cnt88] = val82;
    cnt88++;
  }
}
;
;

cnt81 += (CAT_SZ) * (1);
;
;
std::array<size_t, 0 + 1> val89;
;
;
std::array<size_t, 0 + 1> val90;
;

size_t cnt95 = 0;
for (size_t i91 = 0; i91 < 1; i91++) {
  val2 = rev_count.find(i91)->second;
  for (size_t j92 = 0; j92 < CAT_SZ2; j92++) {
    val90 = other.rev_cat_sum1.find(j92)->second;
    for (size_t r94 = 0; r94 < 1; r94++) {
      for (size_t k93 = 0; k93 < 0; k93++) {
        val89[r94 * 0 + k93] = val2[k93] + 0;
      }
    }
    for (size_t r94 = 0; r94 < 1; r94++) {
      for (size_t k93 = 0; k93 < 0; k93++) {
        val89[r94 * 0 + k93 + 0 * 1] = val90[k93] + CONT_SZ;
      }
    }
    for (size_t r94 = 0; r94 < 1; r94++) {
      for (size_t k93 = 0; k93 < 0; k93++) {
        val89[r94 * 0 + k93 + 0 * 1 + 0 * 1] = val2[0 + k93] + 0;
      }
    }
    for (size_t r94 = 0; r94 < 1; r94++) {
      for (size_t k93 = 0; k93 < 1; k93++) {
        val89[r94 * 1 + k93 + 0 * 1 + 0 * 1 + 0 * 1] = val90[0 + k93] + CAT_SZ;
      }
    }
    r.map_cat_sum1[val89] = cnt81 + cnt95;
    r.rev_cat_sum1[cnt81 + cnt95] = val89;
    cnt95++;
  }
}
;
;

cnt81 += (1) * (CAT_SZ2);
;
;
;
size_t cnt96 = 0;
;
std::array<size_t, 0 + 1> val97;
;
std::array<size_t, 0 + 1> val98;
;
;

size_t cnt103 = 0;
for (size_t i99 = 0; i99 < CAT_SZ; i99++) {
  val98 = rev_cat_sum2.find(i99)->second;
  for (size_t j100 = 0; j100 < 1; j100++) {
    val3 = other.rev_count.find(j100)->second;
    for (size_t r102 = 0; r102 < 1; r102++) {
      for (size_t k101 = 0; k101 < 0; k101++) {
        val97[r102 * 0 + k101] = val98[k101] + 0;
      }
    }
    for (size_t r102 = 0; r102 < 1; r102++) {
      for (size_t k101 = 0; k101 < 0; k101++) {
        val97[r102 * 0 + k101 + 0 * 1] = val3[k101] + 0;
      }
    }
    for (size_t r102 = 0; r102 < 1; r102++) {
      for (size_t k101 = 0; k101 < 1; k101++) {
        val97[r102 * 1 + k101 + 0 * 1 + 0 * 1] = val98[0 + k101] + 0;
      }
    }
    for (size_t r102 = 0; r102 < 1; r102++) {
      for (size_t k101 = 0; k101 < 0; k101++) {
        val97[r102 * 0 + k101 + 0 * 1 + 0 * 1 + 1 * 1] = val3[0 + k101] + 0;
      }
    }
    r.map_cat_sum2[val97] = cnt96 + cnt103;
    r.rev_cat_sum2[cnt96 + cnt103] = val97;
    cnt103++;
  }
}
;
;

cnt96 += (CAT_SZ) * (1);
;
;
std::array<size_t, 0 + 1> val104;
;
;
std::array<size_t, 0 + 1> val105;
;

size_t cnt110 = 0;
for (size_t i106 = 0; i106 < 1; i106++) {
  val2 = rev_count.find(i106)->second;
  for (size_t j107 = 0; j107 < CAT_SZ2; j107++) {
    val105 = other.rev_cat_sum2.find(j107)->second;
    for (size_t r109 = 0; r109 < 1; r109++) {
      for (size_t k108 = 0; k108 < 0; k108++) {
        val104[r109 * 0 + k108] = val2[k108] + 0;
      }
    }
    for (size_t r109 = 0; r109 < 1; r109++) {
      for (size_t k108 = 0; k108 < 0; k108++) {
        val104[r109 * 0 + k108 + 0 * 1] = val105[k108] + CONT_SZ;
      }
    }
    for (size_t r109 = 0; r109 < 1; r109++) {
      for (size_t k108 = 0; k108 < 0; k108++) {
        val104[r109 * 0 + k108 + 0 * 1 + 0 * 1] = val2[0 + k108] + 0;
      }
    }
    for (size_t r109 = 0; r109 < 1; r109++) {
      for (size_t k108 = 0; k108 < 1; k108++) {
        val104[r109 * 1 + k108 + 0 * 1 + 0 * 1 + 0 * 1] = val105[0 + k108] + CAT_SZ;
      }
    }
    r.map_cat_sum2[val104] = cnt96 + cnt110;
    r.rev_cat_sum2[cnt96 + cnt110] = val104;
    cnt110++;
  }
}
;
;

cnt96 += (1) * (CAT_SZ2);
;
;
;
size_t cnt111 = 0;
;
std::array<size_t, 0 + 2> val112;
;
std::array<size_t, 0 + 2> val113;
;
;

size_t cnt118 = 0;
for (size_t i114 = 0; i114 < CAT_SZ * (CAT_SZ - 1) / 2; i114++) {
  val113 = rev_cat_sum4.find(i114)->second;
  for (size_t j115 = 0; j115 < 1; j115++) {
    val3 = other.rev_count.find(j115)->second;
    for (size_t r117 = 0; r117 < 1; r117++) {
      for (size_t k116 = 0; k116 < 0; k116++) {
        val112[r117 * 0 + k116] = val113[k116] + 0;
      }
    }
    for (size_t r117 = 0; r117 < 1; r117++) {
      for (size_t k116 = 0; k116 < 0; k116++) {
        val112[r117 * 0 + k116 + 0 * 1] = val3[k116] + 0;
      }
    }
    for (size_t r117 = 0; r117 < 1; r117++) {
      for (size_t k116 = 0; k116 < 2; k116++) {
        val112[r117 * 2 + k116 + 0 * 1 + 0 * 1] = val113[0 + k116] + 0;
      }
    }
    for (size_t r117 = 0; r117 < 1; r117++) {
      for (size_t k116 = 0; k116 < 0; k116++) {
        val112[r117 * 0 + k116 + 0 * 1 + 0 * 1 + 2 * 1] = val3[0 + k116] + 0;
      }
    }
    r.map_cat_sum4[val112] = cnt111 + cnt118;
    r.rev_cat_sum4[cnt111 + cnt118] = val112;
    cnt118++;
  }
}
;
;

cnt111 += (CAT_SZ * (CAT_SZ - 1) / 2) * (1);
;
;
std::array<size_t, 0 + 2> val119;
;
;
std::array<size_t, 0 + 2> val120;
;

size_t cnt125 = 0;
for (size_t i121 = 0; i121 < 1; i121++) {
  val2 = rev_count.find(i121)->second;
  for (size_t j122 = 0; j122 < CAT_SZ2 * (CAT_SZ2 - 1) / 2; j122++) {
    val120 = other.rev_cat_sum4.find(j122)->second;
    for (size_t r124 = 0; r124 < 1; r124++) {
      for (size_t k123 = 0; k123 < 0; k123++) {
        val119[r124 * 0 + k123] = val2[k123] + 0;
      }
    }
    for (size_t r124 = 0; r124 < 1; r124++) {
      for (size_t k123 = 0; k123 < 0; k123++) {
        val119[r124 * 0 + k123 + 0 * 1] = val120[k123] + CONT_SZ;
      }
    }
    for (size_t r124 = 0; r124 < 1; r124++) {
      for (size_t k123 = 0; k123 < 0; k123++) {
        val119[r124 * 0 + k123 + 0 * 1 + 0 * 1] = val2[0 + k123] + 0;
      }
    }
    for (size_t r124 = 0; r124 < 1; r124++) {
      for (size_t k123 = 0; k123 < 2; k123++) {
        val119[r124 * 2 + k123 + 0 * 1 + 0 * 1 + 0 * 1] = val120[0 + k123] + CAT_SZ;
      }
    }
    r.map_cat_sum4[val119] = cnt111 + cnt125;
    r.rev_cat_sum4[cnt111 + cnt125] = val119;
    cnt125++;
  }
}
;
;

cnt111 += (1) * (CAT_SZ2 * (CAT_SZ2 - 1) / 2);
;
;
std::array<size_t, 0 + 2> val126;
;
;
;

size_t cnt131 = 0;
for (size_t i127 = 0; i127 < CAT_SZ; i127++) {
  val98 = rev_cat_sum2.find(i127)->second;
  for (size_t j128 = 0; j128 < CAT_SZ2; j128++) {
    val105 = other.rev_cat_sum2.find(j128)->second;
    for (size_t r130 = 0; r130 < 1; r130++) {
      for (size_t k129 = 0; k129 < 0; k129++) {
        val126[r130 * 0 + k129] = val98[k129] + 0;
      }
    }
    for (size_t r130 = 0; r130 < 1; r130++) {
      for (size_t k129 = 0; k129 < 0; k129++) {
        val126[r130 * 0 + k129 + 0 * 1] = val105[k129] + CONT_SZ;
      }
    }
    for (size_t r130 = 0; r130 < 1; r130++) {
      for (size_t k129 = 0; k129 < 1; k129++) {
        val126[r130 * 1 + k129 + 0 * 1 + 0 * 1] = val98[0 + k129] + 0;
      }
    }
    for (size_t r130 = 0; r130 < 1; r130++) {
      for (size_t k129 = 0; k129 < 1; k129++) {
        val126[r130 * 1 + k129 + 0 * 1 + 0 * 1 + 1 * 1] = val105[0 + k129] + CAT_SZ;
      }
    }
    r.map_cat_sum4[val126] = cnt111 + cnt131;
    r.rev_cat_sum4[cnt111 + cnt131] = val126;
    cnt131++;
  }
}
;
;

cnt111 += (CAT_SZ) * (CAT_SZ2);
;
;
;
size_t cnt132 = 0;
;
std::array<size_t, 0 + 2> val133;
;
std::array<size_t, 0 + 2> val134;
;
;

size_t cnt139 = 0;
for (size_t i135 = 0; i135 < CAT_SZ * (CAT_SZ - 1) / 2; i135++) {
  val134 = rev_cat_degree2.find(i135)->second;
  for (size_t j136 = 0; j136 < 1; j136++) {
    val3 = other.rev_count.find(j136)->second;
    for (size_t r138 = 0; r138 < 1; r138++) {
      for (size_t k137 = 0; k137 < 0; k137++) {
        val133[r138 * 0 + k137] = val134[k137] + 0;
      }
    }
    for (size_t r138 = 0; r138 < 1; r138++) {
      for (size_t k137 = 0; k137 < 0; k137++) {
        val133[r138 * 0 + k137 + 0 * 1] = val3[k137] + 0;
      }
    }
    for (size_t r138 = 0; r138 < 1; r138++) {
      for (size_t k137 = 0; k137 < 2; k137++) {
        val133[r138 * 2 + k137 + 0 * 1 + 0 * 1] = val134[0 + k137] + 0;
      }
    }
    for (size_t r138 = 0; r138 < 1; r138++) {
      for (size_t k137 = 0; k137 < 0; k137++) {
        val133[r138 * 0 + k137 + 0 * 1 + 0 * 1 + 2 * 1] = val3[0 + k137] + 0;
      }
    }
    r.map_cat_degree2[val133] = cnt132 + cnt139;
    r.rev_cat_degree2[cnt132 + cnt139] = val133;
    cnt139++;
  }
}
;
;

cnt132 += (CAT_SZ * (CAT_SZ - 1) / 2) * (1);
;
;
std::array<size_t, 0 + 2> val140;
;
;
std::array<size_t, 0 + 2> val141;
;

size_t cnt146 = 0;
for (size_t i142 = 0; i142 < 1; i142++) {
  val2 = rev_count.find(i142)->second;
  for (size_t j143 = 0; j143 < CAT_SZ2 * (CAT_SZ2 - 1) / 2; j143++) {
    val141 = other.rev_cat_degree2.find(j143)->second;
    for (size_t r145 = 0; r145 < 1; r145++) {
      for (size_t k144 = 0; k144 < 0; k144++) {
        val140[r145 * 0 + k144] = val2[k144] + 0;
      }
    }
    for (size_t r145 = 0; r145 < 1; r145++) {
      for (size_t k144 = 0; k144 < 0; k144++) {
        val140[r145 * 0 + k144 + 0 * 1] = val141[k144] + CONT_SZ;
      }
    }
    for (size_t r145 = 0; r145 < 1; r145++) {
      for (size_t k144 = 0; k144 < 0; k144++) {
        val140[r145 * 0 + k144 + 0 * 1 + 0 * 1] = val2[0 + k144] + 0;
      }
    }
    for (size_t r145 = 0; r145 < 1; r145++) {
      for (size_t k144 = 0; k144 < 2; k144++) {
        val140[r145 * 2 + k144 + 0 * 1 + 0 * 1 + 0 * 1] = val141[0 + k144] + CAT_SZ;
      }
    }
    r.map_cat_degree2[val140] = cnt132 + cnt146;
    r.rev_cat_degree2[cnt132 + cnt146] = val140;
    cnt146++;
  }
}
;
;

cnt132 += (1) * (CAT_SZ2 * (CAT_SZ2 - 1) / 2);
;
;
std::array<size_t, 0 + 2> val147;
;
;
;

size_t cnt152 = 0;
for (size_t i148 = 0; i148 < CAT_SZ; i148++) {
  val83 = rev_cat_sum1.find(i148)->second;
  for (size_t j149 = 0; j149 < CAT_SZ2; j149++) {
    val90 = other.rev_cat_sum1.find(j149)->second;
    for (size_t r151 = 0; r151 < 1; r151++) {
      for (size_t k150 = 0; k150 < 0; k150++) {
        val147[r151 * 0 + k150] = val83[k150] + 0;
      }
    }
    for (size_t r151 = 0; r151 < 1; r151++) {
      for (size_t k150 = 0; k150 < 0; k150++) {
        val147[r151 * 0 + k150 + 0 * 1] = val90[k150] + CONT_SZ;
      }
    }
    for (size_t r151 = 0; r151 < 1; r151++) {
      for (size_t k150 = 0; k150 < 1; k150++) {
        val147[r151 * 1 + k150 + 0 * 1 + 0 * 1] = val83[0 + k150] + 0;
      }
    }
    for (size_t r151 = 0; r151 < 1; r151++) {
      for (size_t k150 = 0; k150 < 1; k150++) {
        val147[r151 * 1 + k150 + 0 * 1 + 0 * 1 + 1 * 1] = val90[0 + k150] + CAT_SZ;
      }
    }
    r.map_cat_degree2[val147] = cnt132 + cnt152;
    r.rev_cat_degree2[cnt132 + cnt152] = val147;
    cnt152++;
  }
}
;
;

cnt132 += (CAT_SZ) * (CAT_SZ2);
;
;
;
size_t cnt153 = 0;
;
std::array<size_t, 1 + 1> val154;
;
std::array<size_t, 1 + 1> val155;
;
;

size_t cnt160 = 0;
for (size_t i156 = 0; i156 < CONT_SZ * CAT_SZ; i156++) {
  val155 = rev_cont_cat_sum4.find(i156)->second;
  for (size_t j157 = 0; j157 < 1; j157++) {
    val3 = other.rev_count.find(j157)->second;
    for (size_t r159 = 0; r159 < 1; r159++) {
      for (size_t k158 = 0; k158 < 1; k158++) {
        val154[r159 * 1 + k158] = val155[k158] + 0;
      }
    }
    for (size_t r159 = 0; r159 < 1; r159++) {
      for (size_t k158 = 0; k158 < 0; k158++) {
        val154[r159 * 0 + k158 + 1 * 1] = val3[k158] + 0;
      }
    }
    for (size_t r159 = 0; r159 < 1; r159++) {
      for (size_t k158 = 0; k158 < 1; k158++) {
        val154[r159 * 1 + k158 + 1 * 1 + 0 * 1] = val155[1 + k158] + 0;
      }
    }
    for (size_t r159 = 0; r159 < 1; r159++) {
      for (size_t k158 = 0; k158 < 0; k158++) {
        val154[r159 * 0 + k158 + 1 * 1 + 0 * 1 + 1 * 1] = val3[0 + k158] + 0;
      }
    }
    r.map_cont_cat_sum4[val154] = cnt153 + cnt160;
    r.rev_cont_cat_sum4[cnt153 + cnt160] = val154;
    cnt160++;
  }
}
;
;

cnt153 += (CONT_SZ * CAT_SZ) * (1);
;
;
std::array<size_t, 1 + 1> val161;
;
;
std::array<size_t, 1 + 1> val162;
;

size_t cnt167 = 0;
for (size_t i163 = 0; i163 < 1; i163++) {
  val2 = rev_count.find(i163)->second;
  for (size_t j164 = 0; j164 < CONT_SZ2 * CAT_SZ2; j164++) {
    val162 = other.rev_cont_cat_sum4.find(j164)->second;
    for (size_t r166 = 0; r166 < 1; r166++) {
      for (size_t k165 = 0; k165 < 0; k165++) {
        val161[r166 * 0 + k165] = val2[k165] + 0;
      }
    }
    for (size_t r166 = 0; r166 < 1; r166++) {
      for (size_t k165 = 0; k165 < 1; k165++) {
        val161[r166 * 1 + k165 + 0 * 1] = val162[k165] + CONT_SZ;
      }
    }
    for (size_t r166 = 0; r166 < 1; r166++) {
      for (size_t k165 = 0; k165 < 0; k165++) {
        val161[r166 * 0 + k165 + 0 * 1 + 1 * 1] = val2[0 + k165] + 0;
      }
    }
    for (size_t r166 = 0; r166 < 1; r166++) {
      for (size_t k165 = 0; k165 < 1; k165++) {
        val161[r166 * 1 + k165 + 0 * 1 + 1 * 1 + 0 * 1] = val162[1 + k165] + CAT_SZ;
      }
    }
    r.map_cont_cat_sum4[val161] = cnt153 + cnt167;
    r.rev_cont_cat_sum4[cnt153 + cnt167] = val161;
    cnt167++;
  }
}
;
;

cnt153 += (1) * (CONT_SZ2 * CAT_SZ2);
;
;
std::array<size_t, 1 + 1> val168;
;
;
;

size_t cnt173 = 0;
for (size_t i169 = 0; i169 < CONT_SZ; i169++) {
  val26 = rev_cont_sum2.find(i169)->second;
  for (size_t j170 = 0; j170 < CAT_SZ2; j170++) {
    val105 = other.rev_cat_sum2.find(j170)->second;
    for (size_t r172 = 0; r172 < 1; r172++) {
      for (size_t k171 = 0; k171 < 1; k171++) {
        val168[r172 * 1 + k171] = val26[k171] + 0;
      }
    }
    for (size_t r172 = 0; r172 < 1; r172++) {
      for (size_t k171 = 0; k171 < 0; k171++) {
        val168[r172 * 0 + k171 + 1 * 1] = val105[k171] + CONT_SZ;
      }
    }
    for (size_t r172 = 0; r172 < 1; r172++) {
      for (size_t k171 = 0; k171 < 0; k171++) {
        val168[r172 * 0 + k171 + 1 * 1 + 0 * 1] = val26[1 + k171] + 0;
      }
    }
    for (size_t r172 = 0; r172 < 1; r172++) {
      for (size_t k171 = 0; k171 < 1; k171++) {
        val168[r172 * 1 + k171 + 1 * 1 + 0 * 1 + 0 * 1] = val105[0 + k171] + CAT_SZ;
      }
    }
    r.map_cont_cat_sum4[val168] = cnt153 + cnt173;
    r.rev_cont_cat_sum4[cnt153 + cnt173] = val168;
    cnt173++;
  }
}
;
;

cnt153 += (CONT_SZ) * (CAT_SZ2);
;
;
std::array<size_t, 1 + 1> val174;
;
;
;

size_t cnt179 = 0;
for (size_t i175 = 0; i175 < CAT_SZ; i175++) {
  val98 = rev_cat_sum2.find(i175)->second;
  for (size_t j176 = 0; j176 < CONT_SZ2; j176++) {
    val33 = other.rev_cont_sum2.find(j176)->second;
    for (size_t r178 = 0; r178 < 1; r178++) {
      for (size_t k177 = 0; k177 < 0; k177++) {
        val174[r178 * 0 + k177] = val98[k177] + 0;
      }
    }
    for (size_t r178 = 0; r178 < 1; r178++) {
      for (size_t k177 = 0; k177 < 1; k177++) {
        val174[r178 * 1 + k177 + 0 * 1] = val33[k177] + CONT_SZ;
      }
    }
    for (size_t r178 = 0; r178 < 1; r178++) {
      for (size_t k177 = 0; k177 < 1; k177++) {
        val174[r178 * 1 + k177 + 0 * 1 + 1 * 1] = val98[0 + k177] + 0;
      }
    }
    for (size_t r178 = 0; r178 < 1; r178++) {
      for (size_t k177 = 0; k177 < 0; k177++) {
        val174[r178 * 0 + k177 + 0 * 1 + 1 * 1 + 1 * 1] = val33[1 + k177] + 0;
      }
    }
    r.map_cont_cat_sum4[val174] = cnt153 + cnt179;
    r.rev_cont_cat_sum4[cnt153 + cnt179] = val174;
    cnt179++;
  }
}
;
;

cnt153 += (CAT_SZ) * (CONT_SZ2);
;
;
;
size_t cnt180 = 0;
;
std::array<size_t, 1 + 1> val181;
;
std::array<size_t, 1 + 1> val182;
;
;

size_t cnt187 = 0;
for (size_t i183 = 0; i183 < CONT_SZ * CAT_SZ; i183++) {
  val182 = rev_cont_cat_degree2.find(i183)->second;
  for (size_t j184 = 0; j184 < 1; j184++) {
    val3 = other.rev_count.find(j184)->second;
    for (size_t r186 = 0; r186 < 1; r186++) {
      for (size_t k185 = 0; k185 < 1; k185++) {
        val181[r186 * 1 + k185] = val182[k185] + 0;
      }
    }
    for (size_t r186 = 0; r186 < 1; r186++) {
      for (size_t k185 = 0; k185 < 0; k185++) {
        val181[r186 * 0 + k185 + 1 * 1] = val3[k185] + 0;
      }
    }
    for (size_t r186 = 0; r186 < 1; r186++) {
      for (size_t k185 = 0; k185 < 1; k185++) {
        val181[r186 * 1 + k185 + 1 * 1 + 0 * 1] = val182[1 + k185] + 0;
      }
    }
    for (size_t r186 = 0; r186 < 1; r186++) {
      for (size_t k185 = 0; k185 < 0; k185++) {
        val181[r186 * 0 + k185 + 1 * 1 + 0 * 1 + 1 * 1] = val3[0 + k185] + 0;
      }
    }
    r.map_cont_cat_degree2[val181] = cnt180 + cnt187;
    r.rev_cont_cat_degree2[cnt180 + cnt187] = val181;
    cnt187++;
  }
}
;
;

cnt180 += (CONT_SZ * CAT_SZ) * (1);
;
;
std::array<size_t, 1 + 1> val188;
;
;
std::array<size_t, 1 + 1> val189;
;

size_t cnt194 = 0;
for (size_t i190 = 0; i190 < 1; i190++) {
  val2 = rev_count.find(i190)->second;
  for (size_t j191 = 0; j191 < CONT_SZ2 * CAT_SZ2; j191++) {
    val189 = other.rev_cont_cat_degree2.find(j191)->second;
    for (size_t r193 = 0; r193 < 1; r193++) {
      for (size_t k192 = 0; k192 < 0; k192++) {
        val188[r193 * 0 + k192] = val2[k192] + 0;
      }
    }
    for (size_t r193 = 0; r193 < 1; r193++) {
      for (size_t k192 = 0; k192 < 1; k192++) {
        val188[r193 * 1 + k192 + 0 * 1] = val189[k192] + CONT_SZ;
      }
    }
    for (size_t r193 = 0; r193 < 1; r193++) {
      for (size_t k192 = 0; k192 < 0; k192++) {
        val188[r193 * 0 + k192 + 0 * 1 + 1 * 1] = val2[0 + k192] + 0;
      }
    }
    for (size_t r193 = 0; r193 < 1; r193++) {
      for (size_t k192 = 0; k192 < 1; k192++) {
        val188[r193 * 1 + k192 + 0 * 1 + 1 * 1 + 0 * 1] = val189[1 + k192] + CAT_SZ;
      }
    }
    r.map_cont_cat_degree2[val188] = cnt180 + cnt194;
    r.rev_cont_cat_degree2[cnt180 + cnt194] = val188;
    cnt194++;
  }
}
;
;

cnt180 += (1) * (CONT_SZ2 * CAT_SZ2);
;
;
std::array<size_t, 1 + 1> val195;
;
;
;

size_t cnt200 = 0;
for (size_t i196 = 0; i196 < CONT_SZ; i196++) {
  val11 = rev_cont_sum1.find(i196)->second;
  for (size_t j197 = 0; j197 < CAT_SZ2; j197++) {
    val90 = other.rev_cat_sum1.find(j197)->second;
    for (size_t r199 = 0; r199 < 1; r199++) {
      for (size_t k198 = 0; k198 < 1; k198++) {
        val195[r199 * 1 + k198] = val11[k198] + 0;
      }
    }
    for (size_t r199 = 0; r199 < 1; r199++) {
      for (size_t k198 = 0; k198 < 0; k198++) {
        val195[r199 * 0 + k198 + 1 * 1] = val90[k198] + CONT_SZ;
      }
    }
    for (size_t r199 = 0; r199 < 1; r199++) {
      for (size_t k198 = 0; k198 < 0; k198++) {
        val195[r199 * 0 + k198 + 1 * 1 + 0 * 1] = val11[1 + k198] + 0;
      }
    }
    for (size_t r199 = 0; r199 < 1; r199++) {
      for (size_t k198 = 0; k198 < 1; k198++) {
        val195[r199 * 1 + k198 + 1 * 1 + 0 * 1 + 0 * 1] = val90[0 + k198] + CAT_SZ;
      }
    }
    r.map_cont_cat_degree2[val195] = cnt180 + cnt200;
    r.rev_cont_cat_degree2[cnt180 + cnt200] = val195;
    cnt200++;
  }
}
;
;

cnt180 += (CONT_SZ) * (CAT_SZ2);
;
;
std::array<size_t, 1 + 1> val201;
;
;
;

size_t cnt206 = 0;
for (size_t i202 = 0; i202 < CAT_SZ; i202++) {
  val83 = rev_cat_sum1.find(i202)->second;
  for (size_t j203 = 0; j203 < CONT_SZ2; j203++) {
    val18 = other.rev_cont_sum1.find(j203)->second;
    for (size_t r205 = 0; r205 < 1; r205++) {
      for (size_t k204 = 0; k204 < 0; k204++) {
        val201[r205 * 0 + k204] = val83[k204] + 0;
      }
    }
    for (size_t r205 = 0; r205 < 1; r205++) {
      for (size_t k204 = 0; k204 < 1; k204++) {
        val201[r205 * 1 + k204 + 0 * 1] = val18[k204] + CONT_SZ;
      }
    }
    for (size_t r205 = 0; r205 < 1; r205++) {
      for (size_t k204 = 0; k204 < 1; k204++) {
        val201[r205 * 1 + k204 + 0 * 1 + 1 * 1] = val83[0 + k204] + 0;
      }
    }
    for (size_t r205 = 0; r205 < 1; r205++) {
      for (size_t k204 = 0; k204 < 0; k204++) {
        val201[r205 * 0 + k204 + 0 * 1 + 1 * 1 + 1 * 1] = val18[1 + k204] + 0;
      }
    }
    r.map_cont_cat_degree2[val201] = cnt180 + cnt206;
    r.rev_cont_cat_degree2[cnt180 + cnt206] = val201;
    cnt206++;
  }
}
;
;

cnt180 += (CAT_SZ) * (CONT_SZ2);
;
;
;
size_t cnt207 = 0;
;
std::array<size_t, 3 + 0> val208;
;
std::array<size_t, 3 + 0> val209;
;
;

size_t cnt214 = 0;
for (size_t i210 = 0; i210 < CONT_SZ * (CONT_SZ - 1) * (CONT_SZ - 2) / 6 + CONT_SZ * (CONT_SZ - 1); i210++) {
  val209 = rev_cont_degree3.find(i210)->second;
  for (size_t j211 = 0; j211 < 1; j211++) {
    val3 = other.rev_count.find(j211)->second;
    for (size_t r213 = 0; r213 < 1; r213++) {
      for (size_t k212 = 0; k212 < 3; k212++) {
        val208[r213 * 3 + k212] = val209[k212] + 0;
      }
    }
    for (size_t r213 = 0; r213 < 1; r213++) {
      for (size_t k212 = 0; k212 < 0; k212++) {
        val208[r213 * 0 + k212 + 3 * 1] = val3[k212] + 0;
      }
    }
    for (size_t r213 = 0; r213 < 1; r213++) {
      for (size_t k212 = 0; k212 < 0; k212++) {
        val208[r213 * 0 + k212 + 3 * 1 + 0 * 1] = val209[3 + k212] + 0;
      }
    }
    for (size_t r213 = 0; r213 < 1; r213++) {
      for (size_t k212 = 0; k212 < 0; k212++) {
        val208[r213 * 0 + k212 + 3 * 1 + 0 * 1 + 0 * 1] = val3[0 + k212] + 0;
      }
    }
    r.map_cont_degree3[val208] = cnt207 + cnt214;
    r.rev_cont_degree3[cnt207 + cnt214] = val208;
    cnt214++;
  }
}
;
;

cnt207 += (CONT_SZ * (CONT_SZ - 1) * (CONT_SZ - 2) / 6 + CONT_SZ * (CONT_SZ - 1)) * (1);
;
;
std::array<size_t, 3 + 0> val215;
;
;
std::array<size_t, 3 + 0> val216;
;

size_t cnt221 = 0;
for (size_t i217 = 0; i217 < 1; i217++) {
  val2 = rev_count.find(i217)->second;
  for (size_t j218 = 0; j218 < CONT_SZ2 * (CONT_SZ2 - 1) * (CONT_SZ2 - 2) / 6 + CONT_SZ2 * (CONT_SZ2 - 1); j218++) {
    val216 = other.rev_cont_degree3.find(j218)->second;
    for (size_t r220 = 0; r220 < 1; r220++) {
      for (size_t k219 = 0; k219 < 0; k219++) {
        val215[r220 * 0 + k219] = val2[k219] + 0;
      }
    }
    for (size_t r220 = 0; r220 < 1; r220++) {
      for (size_t k219 = 0; k219 < 3; k219++) {
        val215[r220 * 3 + k219 + 0 * 1] = val216[k219] + CONT_SZ;
      }
    }
    for (size_t r220 = 0; r220 < 1; r220++) {
      for (size_t k219 = 0; k219 < 0; k219++) {
        val215[r220 * 0 + k219 + 0 * 1 + 3 * 1] = val2[0 + k219] + 0;
      }
    }
    for (size_t r220 = 0; r220 < 1; r220++) {
      for (size_t k219 = 0; k219 < 0; k219++) {
        val215[r220 * 0 + k219 + 0 * 1 + 3 * 1 + 0 * 1] = val216[3 + k219] + 0;
      }
    }
    r.map_cont_degree3[val215] = cnt207 + cnt221;
    r.rev_cont_degree3[cnt207 + cnt221] = val215;
    cnt221++;
  }
}
;
;

cnt207 += (1) * (CONT_SZ2 * (CONT_SZ2 - 1) * (CONT_SZ2 - 2) / 6 + CONT_SZ2 * (CONT_SZ2 - 1));
;
;
std::array<size_t, 3 + 0> val222;
;
;
;

size_t cnt227 = 0;
for (size_t i223 = 0; i223 < CONT_SZ; i223++) {
  val11 = rev_cont_sum1.find(i223)->second;
  for (size_t j224 = 0; j224 < CONT_SZ2 * (CONT_SZ2 - 1) / 2; j224++) {
    val69 = other.rev_cont_degree2.find(j224)->second;
    for (size_t r226 = 0; r226 < 1; r226++) {
      for (size_t k225 = 0; k225 < 1; k225++) {
        val222[r226 * 1 + k225] = val11[k225] + 0;
      }
    }
    for (size_t r226 = 0; r226 < 1; r226++) {
      for (size_t k225 = 0; k225 < 2; k225++) {
        val222[r226 * 2 + k225 + 1 * 1] = val69[k225] + CONT_SZ;
      }
    }
    for (size_t r226 = 0; r226 < 1; r226++) {
      for (size_t k225 = 0; k225 < 0; k225++) {
        val222[r226 * 0 + k225 + 1 * 1 + 2 * 1] = val11[1 + k225] + 0;
      }
    }
    for (size_t r226 = 0; r226 < 1; r226++) {
      for (size_t k225 = 0; k225 < 0; k225++) {
        val222[r226 * 0 + k225 + 1 * 1 + 2 * 1 + 0 * 1] = val69[2 + k225] + 0;
      }
    }
    r.map_cont_degree3[val222] = cnt207 + cnt227;
    r.rev_cont_degree3[cnt207 + cnt227] = val222;
    cnt227++;
  }
}
;
;

cnt207 += (CONT_SZ) * (CONT_SZ2 * (CONT_SZ2 - 1) / 2);
;
;
std::array<size_t, 3 + 0> val228;
;
;
;

size_t cnt233 = 0;
for (size_t i229 = 0; i229 < CONT_SZ * (CONT_SZ - 1) / 2; i229++) {
  val62 = rev_cont_degree2.find(i229)->second;
  for (size_t j230 = 0; j230 < CONT_SZ2; j230++) {
    val18 = other.rev_cont_sum1.find(j230)->second;
    for (size_t r232 = 0; r232 < 1; r232++) {
      for (size_t k231 = 0; k231 < 2; k231++) {
        val228[r232 * 2 + k231] = val62[k231] + 0;
      }
    }
    for (size_t r232 = 0; r232 < 1; r232++) {
      for (size_t k231 = 0; k231 < 1; k231++) {
        val228[r232 * 1 + k231 + 2 * 1] = val18[k231] + CONT_SZ;
      }
    }
    for (size_t r232 = 0; r232 < 1; r232++) {
      for (size_t k231 = 0; k231 < 0; k231++) {
        val228[r232 * 0 + k231 + 2 * 1 + 1 * 1] = val62[2 + k231] + 0;
      }
    }
    for (size_t r232 = 0; r232 < 1; r232++) {
      for (size_t k231 = 0; k231 < 0; k231++) {
        val228[r232 * 0 + k231 + 2 * 1 + 1 * 1 + 0 * 1] = val18[1 + k231] + 0;
      }
    }
    r.map_cont_degree3[val228] = cnt207 + cnt233;
    r.rev_cont_degree3[cnt207 + cnt233] = val228;
    cnt233++;
  }
}
;
;

cnt207 += (CONT_SZ * (CONT_SZ - 1) / 2) * (CONT_SZ2);
;
;
std::array<size_t, 3 + 0> val234;
;
;
std::array<size_t, 1 + 0> val235;
;

size_t cnt240 = 0;
for (size_t i236 = 0; i236 < CONT_SZ; i236++) {
  val11 = rev_cont_sum1.find(i236)->second;
  for (size_t j237 = 0; j237 < CONT_SZ2; j237++) {
    val235 = other.rev_cont_sum2.find(j237)->second;
    for (size_t r239 = 0; r239 < 1; r239++) {
      for (size_t k238 = 0; k238 < 1; k238++) {
        val234[r239 * 1 + k238] = val11[k238] + 0;
      }
    }
    for (size_t r239 = 0; r239 < 2; r239++) {
      for (size_t k238 = 0; k238 < 1; k238++) {
        val234[r239 * 1 + k238 + 1 * 1] = val235[k238] + CONT_SZ;
      }
    }
    for (size_t r239 = 0; r239 < 1; r239++) {
      for (size_t k238 = 0; k238 < 0; k238++) {
        val234[r239 * 0 + k238 + 1 * 1 + 1 * 2] = val11[1 + k238] + 0;
      }
    }
    for (size_t r239 = 0; r239 < 2; r239++) {
      for (size_t k238 = 0; k238 < 0; k238++) {
        val234[r239 * 0 + k238 + 1 * 1 + 1 * 2 + 0 * 1] = val235[1 + k238] + 0;
      }
    }
    r.map_cont_degree3[val234] = cnt207 + cnt240;
    r.rev_cont_degree3[cnt207 + cnt240] = val234;
    cnt240++;
  }
}
;
;

cnt207 += (CONT_SZ) * (CONT_SZ2);
;
;
std::array<size_t, 3 + 0> val241;
;
std::array<size_t, 1 + 0> val242;
;
;

size_t cnt247 = 0;
for (size_t i243 = 0; i243 < CONT_SZ; i243++) {
  val242 = rev_cont_sum2.find(i243)->second;
  for (size_t j244 = 0; j244 < CONT_SZ2; j244++) {
    val18 = other.rev_cont_sum1.find(j244)->second;
    for (size_t r246 = 0; r246 < 2; r246++) {
      for (size_t k245 = 0; k245 < 1; k245++) {
        val241[r246 * 1 + k245] = val242[k245] + 0;
      }
    }
    for (size_t r246 = 0; r246 < 1; r246++) {
      for (size_t k245 = 0; k245 < 1; k245++) {
        val241[r246 * 1 + k245 + 1 * 2] = val18[k245] + CONT_SZ;
      }
    }
    for (size_t r246 = 0; r246 < 2; r246++) {
      for (size_t k245 = 0; k245 < 0; k245++) {
        val241[r246 * 0 + k245 + 1 * 2 + 1 * 1] = val242[1 + k245] + 0;
      }
    }
    for (size_t r246 = 0; r246 < 1; r246++) {
      for (size_t k245 = 0; k245 < 0; k245++) {
        val241[r246 * 0 + k245 + 1 * 2 + 1 * 1 + 0 * 2] = val18[1 + k245] + 0;
      }
    }
    r.map_cont_degree3[val241] = cnt207 + cnt247;
    r.rev_cont_degree3[cnt207 + cnt247] = val241;
    cnt247++;
  }
}
;
;

cnt207 += (CONT_SZ) * (CONT_SZ2);
;
;
;
size_t cnt248 = 0;
;
std::array<size_t, 2 + 1> val249;
;
std::array<size_t, 2 + 1> val250;
;
;

size_t cnt255 = 0;
for (size_t i251 = 0; i251 < CONT_SZ * (CONT_SZ + 1) / 2 * CAT_SZ; i251++) {
  val250 = rev_cont2_cat_degree3.find(i251)->second;
  for (size_t j252 = 0; j252 < 1; j252++) {
    val3 = other.rev_count.find(j252)->second;
    for (size_t r254 = 0; r254 < 1; r254++) {
      for (size_t k253 = 0; k253 < 2; k253++) {
        val249[r254 * 2 + k253] = val250[k253] + 0;
      }
    }
    for (size_t r254 = 0; r254 < 1; r254++) {
      for (size_t k253 = 0; k253 < 0; k253++) {
        val249[r254 * 0 + k253 + 2 * 1] = val3[k253] + 0;
      }
    }
    for (size_t r254 = 0; r254 < 1; r254++) {
      for (size_t k253 = 0; k253 < 1; k253++) {
        val249[r254 * 1 + k253 + 2 * 1 + 0 * 1] = val250[2 + k253] + 0;
      }
    }
    for (size_t r254 = 0; r254 < 1; r254++) {
      for (size_t k253 = 0; k253 < 0; k253++) {
        val249[r254 * 0 + k253 + 2 * 1 + 0 * 1 + 1 * 1] = val3[0 + k253] + 0;
      }
    }
    r.map_cont2_cat_degree3[val249] = cnt248 + cnt255;
    r.rev_cont2_cat_degree3[cnt248 + cnt255] = val249;
    cnt255++;
  }
}
;
;

cnt248 += (CONT_SZ * (CONT_SZ + 1) / 2 * CAT_SZ) * (1);
;
;
std::array<size_t, 2 + 1> val256;
;
;
std::array<size_t, 2 + 1> val257;
;

size_t cnt262 = 0;
for (size_t i258 = 0; i258 < 1; i258++) {
  val2 = rev_count.find(i258)->second;
  for (size_t j259 = 0; j259 < CONT_SZ2 * (CONT_SZ2 + 1) / 2 * CAT_SZ2; j259++) {
    val257 = other.rev_cont2_cat_degree3.find(j259)->second;
    for (size_t r261 = 0; r261 < 1; r261++) {
      for (size_t k260 = 0; k260 < 0; k260++) {
        val256[r261 * 0 + k260] = val2[k260] + 0;
      }
    }
    for (size_t r261 = 0; r261 < 1; r261++) {
      for (size_t k260 = 0; k260 < 2; k260++) {
        val256[r261 * 2 + k260 + 0 * 1] = val257[k260] + CONT_SZ;
      }
    }
    for (size_t r261 = 0; r261 < 1; r261++) {
      for (size_t k260 = 0; k260 < 0; k260++) {
        val256[r261 * 0 + k260 + 0 * 1 + 2 * 1] = val2[0 + k260] + 0;
      }
    }
    for (size_t r261 = 0; r261 < 1; r261++) {
      for (size_t k260 = 0; k260 < 1; k260++) {
        val256[r261 * 1 + k260 + 0 * 1 + 2 * 1 + 0 * 1] = val257[2 + k260] + CAT_SZ;
      }
    }
    r.map_cont2_cat_degree3[val256] = cnt248 + cnt262;
    r.rev_cont2_cat_degree3[cnt248 + cnt262] = val256;
    cnt262++;
  }
}
;
;

cnt248 += (1) * (CONT_SZ2 * (CONT_SZ2 + 1) / 2 * CAT_SZ2);
;
;
std::array<size_t, 2 + 1> val263;
;
;
;

size_t cnt268 = 0;
for (size_t i264 = 0; i264 < CONT_SZ; i264++) {
  val242 = rev_cont_sum2.find(i264)->second;
  for (size_t j265 = 0; j265 < CAT_SZ2; j265++) {
    val90 = other.rev_cat_sum1.find(j265)->second;
    for (size_t r267 = 0; r267 < 2; r267++) {
      for (size_t k266 = 0; k266 < 1; k266++) {
        val263[r267 * 1 + k266] = val242[k266] + 0;
      }
    }
    for (size_t r267 = 0; r267 < 1; r267++) {
      for (size_t k266 = 0; k266 < 0; k266++) {
        val263[r267 * 0 + k266 + 1 * 2] = val90[k266] + CONT_SZ;
      }
    }
    for (size_t r267 = 0; r267 < 2; r267++) {
      for (size_t k266 = 0; k266 < 0; k266++) {
        val263[r267 * 0 + k266 + 1 * 2 + 0 * 1] = val242[1 + k266] + 0;
      }
    }
    for (size_t r267 = 0; r267 < 1; r267++) {
      for (size_t k266 = 0; k266 < 1; k266++) {
        val263[r267 * 1 + k266 + 1 * 2 + 0 * 1 + 0 * 2] = val90[0 + k266] + CAT_SZ;
      }
    }
    r.map_cont2_cat_degree3[val263] = cnt248 + cnt268;
    r.rev_cont2_cat_degree3[cnt248 + cnt268] = val263;
    cnt268++;
  }
}
;
;

cnt248 += (CONT_SZ) * (CAT_SZ2);
;
;
std::array<size_t, 2 + 1> val269;
;
;
;

size_t cnt274 = 0;
for (size_t i270 = 0; i270 < CAT_SZ; i270++) {
  val83 = rev_cat_sum1.find(i270)->second;
  for (size_t j271 = 0; j271 < CONT_SZ2; j271++) {
    val235 = other.rev_cont_sum2.find(j271)->second;
    for (size_t r273 = 0; r273 < 1; r273++) {
      for (size_t k272 = 0; k272 < 0; k272++) {
        val269[r273 * 0 + k272] = val83[k272] + 0;
      }
    }
    for (size_t r273 = 0; r273 < 2; r273++) {
      for (size_t k272 = 0; k272 < 1; k272++) {
        val269[r273 * 1 + k272 + 0 * 1] = val235[k272] + CONT_SZ;
      }
    }
    for (size_t r273 = 0; r273 < 1; r273++) {
      for (size_t k272 = 0; k272 < 1; k272++) {
        val269[r273 * 1 + k272 + 0 * 1 + 1 * 2] = val83[0 + k272] + 0;
      }
    }
    for (size_t r273 = 0; r273 < 2; r273++) {
      for (size_t k272 = 0; k272 < 0; k272++) {
        val269[r273 * 0 + k272 + 0 * 1 + 1 * 2 + 1 * 1] = val235[1 + k272] + 0;
      }
    }
    r.map_cont2_cat_degree3[val269] = cnt248 + cnt274;
    r.rev_cont2_cat_degree3[cnt248 + cnt274] = val269;
    cnt274++;
  }
}
;
;

cnt248 += (CAT_SZ) * (CONT_SZ2);
;
;
std::array<size_t, 2 + 1> val275;
;
;
;

size_t cnt280 = 0;
for (size_t i276 = 0; i276 < CONT_SZ * (CONT_SZ - 1) / 2; i276++) {
  val62 = rev_cont_degree2.find(i276)->second;
  for (size_t j277 = 0; j277 < CAT_SZ2; j277++) {
    val90 = other.rev_cat_sum1.find(j277)->second;
    for (size_t r279 = 0; r279 < 1; r279++) {
      for (size_t k278 = 0; k278 < 2; k278++) {
        val275[r279 * 2 + k278] = val62[k278] + 0;
      }
    }
    for (size_t r279 = 0; r279 < 1; r279++) {
      for (size_t k278 = 0; k278 < 0; k278++) {
        val275[r279 * 0 + k278 + 2 * 1] = val90[k278] + CONT_SZ;
      }
    }
    for (size_t r279 = 0; r279 < 1; r279++) {
      for (size_t k278 = 0; k278 < 0; k278++) {
        val275[r279 * 0 + k278 + 2 * 1 + 0 * 1] = val62[2 + k278] + 0;
      }
    }
    for (size_t r279 = 0; r279 < 1; r279++) {
      for (size_t k278 = 0; k278 < 1; k278++) {
        val275[r279 * 1 + k278 + 2 * 1 + 0 * 1 + 0 * 1] = val90[0 + k278] + CAT_SZ;
      }
    }
    r.map_cont2_cat_degree3[val275] = cnt248 + cnt280;
    r.rev_cont2_cat_degree3[cnt248 + cnt280] = val275;
    cnt280++;
  }
}
;
;

cnt248 += (CONT_SZ * (CONT_SZ - 1) / 2) * (CAT_SZ2);
;
;
std::array<size_t, 2 + 1> val281;
;
;
;

size_t cnt286 = 0;
for (size_t i282 = 0; i282 < CAT_SZ; i282++) {
  val83 = rev_cat_sum1.find(i282)->second;
  for (size_t j283 = 0; j283 < CONT_SZ2 * (CONT_SZ2 - 1) / 2; j283++) {
    val69 = other.rev_cont_degree2.find(j283)->second;
    for (size_t r285 = 0; r285 < 1; r285++) {
      for (size_t k284 = 0; k284 < 0; k284++) {
        val281[r285 * 0 + k284] = val83[k284] + 0;
      }
    }
    for (size_t r285 = 0; r285 < 1; r285++) {
      for (size_t k284 = 0; k284 < 2; k284++) {
        val281[r285 * 2 + k284 + 0 * 1] = val69[k284] + CONT_SZ;
      }
    }
    for (size_t r285 = 0; r285 < 1; r285++) {
      for (size_t k284 = 0; k284 < 1; k284++) {
        val281[r285 * 1 + k284 + 0 * 1 + 2 * 1] = val83[0 + k284] + 0;
      }
    }
    for (size_t r285 = 0; r285 < 1; r285++) {
      for (size_t k284 = 0; k284 < 0; k284++) {
        val281[r285 * 0 + k284 + 0 * 1 + 2 * 1 + 1 * 1] = val69[2 + k284] + 0;
      }
    }
    r.map_cont2_cat_degree3[val281] = cnt248 + cnt286;
    r.rev_cont2_cat_degree3[cnt248 + cnt286] = val281;
    cnt286++;
  }
}
;
;

cnt248 += (CAT_SZ) * (CONT_SZ2 * (CONT_SZ2 - 1) / 2);
;
;
std::array<size_t, 2 + 1> val287;
;
;
;

size_t cnt292 = 0;
for (size_t i288 = 0; i288 < CONT_SZ * CAT_SZ; i288++) {
  val182 = rev_cont_cat_degree2.find(i288)->second;
  for (size_t j289 = 0; j289 < CONT_SZ2; j289++) {
    val18 = other.rev_cont_sum1.find(j289)->second;
    for (size_t r291 = 0; r291 < 1; r291++) {
      for (size_t k290 = 0; k290 < 1; k290++) {
        val287[r291 * 1 + k290] = val182[k290] + 0;
      }
    }
    for (size_t r291 = 0; r291 < 1; r291++) {
      for (size_t k290 = 0; k290 < 1; k290++) {
        val287[r291 * 1 + k290 + 1 * 1] = val18[k290] + CONT_SZ;
      }
    }
    for (size_t r291 = 0; r291 < 1; r291++) {
      for (size_t k290 = 0; k290 < 1; k290++) {
        val287[r291 * 1 + k290 + 1 * 1 + 1 * 1] = val182[1 + k290] + 0;
      }
    }
    for (size_t r291 = 0; r291 < 1; r291++) {
      for (size_t k290 = 0; k290 < 0; k290++) {
        val287[r291 * 0 + k290 + 1 * 1 + 1 * 1 + 1 * 1] = val18[1 + k290] + 0;
      }
    }
    r.map_cont2_cat_degree3[val287] = cnt248 + cnt292;
    r.rev_cont2_cat_degree3[cnt248 + cnt292] = val287;
    cnt292++;
  }
}
;
;

cnt248 += (CONT_SZ * CAT_SZ) * (CONT_SZ2);
;
;
std::array<size_t, 2 + 1> val293;
;
;
;

size_t cnt298 = 0;
for (size_t i294 = 0; i294 < CONT_SZ; i294++) {
  val11 = rev_cont_sum1.find(i294)->second;
  for (size_t j295 = 0; j295 < CONT_SZ2 * CAT_SZ2; j295++) {
    val189 = other.rev_cont_cat_degree2.find(j295)->second;
    for (size_t r297 = 0; r297 < 1; r297++) {
      for (size_t k296 = 0; k296 < 1; k296++) {
        val293[r297 * 1 + k296] = val11[k296] + 0;
      }
    }
    for (size_t r297 = 0; r297 < 1; r297++) {
      for (size_t k296 = 0; k296 < 1; k296++) {
        val293[r297 * 1 + k296 + 1 * 1] = val189[k296] + CONT_SZ;
      }
    }
    for (size_t r297 = 0; r297 < 1; r297++) {
      for (size_t k296 = 0; k296 < 0; k296++) {
        val293[r297 * 0 + k296 + 1 * 1 + 1 * 1] = val11[1 + k296] + 0;
      }
    }
    for (size_t r297 = 0; r297 < 1; r297++) {
      for (size_t k296 = 0; k296 < 1; k296++) {
        val293[r297 * 1 + k296 + 1 * 1 + 1 * 1 + 0 * 1] = val189[1 + k296] + CAT_SZ;
      }
    }
    r.map_cont2_cat_degree3[val293] = cnt248 + cnt298;
    r.rev_cont2_cat_degree3[cnt248 + cnt298] = val293;
    cnt298++;
  }
}
;
;

cnt248 += (CONT_SZ) * (CONT_SZ2 * CAT_SZ2);
;
;
;
size_t cnt299 = 0;
;
std::array<size_t, 1 + 2> val300;
;
std::array<size_t, 1 + 2> val301;
;
;

size_t cnt306 = 0;
for (size_t i302 = 0; i302 < CONT_SZ * CAT_SZ * (CAT_SZ + 1) / 2; i302++) {
  val301 = rev_cont_cat2_degree3.find(i302)->second;
  for (size_t j303 = 0; j303 < 1; j303++) {
    val3 = other.rev_count.find(j303)->second;
    for (size_t r305 = 0; r305 < 1; r305++) {
      for (size_t k304 = 0; k304 < 1; k304++) {
        val300[r305 * 1 + k304] = val301[k304] + 0;
      }
    }
    for (size_t r305 = 0; r305 < 1; r305++) {
      for (size_t k304 = 0; k304 < 0; k304++) {
        val300[r305 * 0 + k304 + 1 * 1] = val3[k304] + 0;
      }
    }
    for (size_t r305 = 0; r305 < 1; r305++) {
      for (size_t k304 = 0; k304 < 2; k304++) {
        val300[r305 * 2 + k304 + 1 * 1 + 0 * 1] = val301[1 + k304] + 0;
      }
    }
    for (size_t r305 = 0; r305 < 1; r305++) {
      for (size_t k304 = 0; k304 < 0; k304++) {
        val300[r305 * 0 + k304 + 1 * 1 + 0 * 1 + 2 * 1] = val3[0 + k304] + 0;
      }
    }
    r.map_cont_cat2_degree3[val300] = cnt299 + cnt306;
    r.rev_cont_cat2_degree3[cnt299 + cnt306] = val300;
    cnt306++;
  }
}
;
;

cnt299 += (CONT_SZ * CAT_SZ * (CAT_SZ + 1) / 2) * (1);
;
;
std::array<size_t, 1 + 2> val307;
;
;
std::array<size_t, 1 + 2> val308;
;

size_t cnt313 = 0;
for (size_t i309 = 0; i309 < 1; i309++) {
  val2 = rev_count.find(i309)->second;
  for (size_t j310 = 0; j310 < CONT_SZ2 * CAT_SZ2 * (CAT_SZ2 + 1) / 2; j310++) {
    val308 = other.rev_cont_cat2_degree3.find(j310)->second;
    for (size_t r312 = 0; r312 < 1; r312++) {
      for (size_t k311 = 0; k311 < 0; k311++) {
        val307[r312 * 0 + k311] = val2[k311] + 0;
      }
    }
    for (size_t r312 = 0; r312 < 1; r312++) {
      for (size_t k311 = 0; k311 < 1; k311++) {
        val307[r312 * 1 + k311 + 0 * 1] = val308[k311] + CONT_SZ;
      }
    }
    for (size_t r312 = 0; r312 < 1; r312++) {
      for (size_t k311 = 0; k311 < 0; k311++) {
        val307[r312 * 0 + k311 + 0 * 1 + 1 * 1] = val2[0 + k311] + 0;
      }
    }
    for (size_t r312 = 0; r312 < 1; r312++) {
      for (size_t k311 = 0; k311 < 2; k311++) {
        val307[r312 * 2 + k311 + 0 * 1 + 1 * 1 + 0 * 1] = val308[1 + k311] + CAT_SZ;
      }
    }
    r.map_cont_cat2_degree3[val307] = cnt299 + cnt313;
    r.rev_cont_cat2_degree3[cnt299 + cnt313] = val307;
    cnt313++;
  }
}
;
;

cnt299 += (1) * (CONT_SZ2 * CAT_SZ2 * (CAT_SZ2 + 1) / 2);
;
;
std::array<size_t, 1 + 2> val314;
;
std::array<size_t, 0 + 1> val315;
;
;

size_t cnt320 = 0;
for (size_t i316 = 0; i316 < CAT_SZ; i316++) {
  val315 = rev_cat_sum2.find(i316)->second;
  for (size_t j317 = 0; j317 < CONT_SZ2; j317++) {
    val18 = other.rev_cont_sum1.find(j317)->second;
    for (size_t r319 = 0; r319 < 2; r319++) {
      for (size_t k318 = 0; k318 < 0; k318++) {
        val314[r319 * 0 + k318] = val315[k318] + 0;
      }
    }
    for (size_t r319 = 0; r319 < 1; r319++) {
      for (size_t k318 = 0; k318 < 1; k318++) {
        val314[r319 * 1 + k318 + 0 * 2] = val18[k318] + CONT_SZ;
      }
    }
    for (size_t r319 = 0; r319 < 2; r319++) {
      for (size_t k318 = 0; k318 < 1; k318++) {
        val314[r319 * 1 + k318 + 0 * 2 + 1 * 1] = val315[0 + k318] + 0;
      }
    }
    for (size_t r319 = 0; r319 < 1; r319++) {
      for (size_t k318 = 0; k318 < 0; k318++) {
        val314[r319 * 0 + k318 + 0 * 2 + 1 * 1 + 1 * 2] = val18[1 + k318] + 0;
      }
    }
    r.map_cont_cat2_degree3[val314] = cnt299 + cnt320;
    r.rev_cont_cat2_degree3[cnt299 + cnt320] = val314;
    cnt320++;
  }
}
;
;

cnt299 += (CAT_SZ) * (CONT_SZ2);
;
;
std::array<size_t, 1 + 2> val321;
;
;
std::array<size_t, 0 + 1> val322;
;

size_t cnt327 = 0;
for (size_t i323 = 0; i323 < CONT_SZ; i323++) {
  val11 = rev_cont_sum1.find(i323)->second;
  for (size_t j324 = 0; j324 < CAT_SZ2; j324++) {
    val322 = other.rev_cat_sum2.find(j324)->second;
    for (size_t r326 = 0; r326 < 1; r326++) {
      for (size_t k325 = 0; k325 < 1; k325++) {
        val321[r326 * 1 + k325] = val11[k325] + 0;
      }
    }
    for (size_t r326 = 0; r326 < 2; r326++) {
      for (size_t k325 = 0; k325 < 0; k325++) {
        val321[r326 * 0 + k325 + 1 * 1] = val322[k325] + CONT_SZ;
      }
    }
    for (size_t r326 = 0; r326 < 1; r326++) {
      for (size_t k325 = 0; k325 < 0; k325++) {
        val321[r326 * 0 + k325 + 1 * 1 + 0 * 2] = val11[1 + k325] + 0;
      }
    }
    for (size_t r326 = 0; r326 < 2; r326++) {
      for (size_t k325 = 0; k325 < 1; k325++) {
        val321[r326 * 1 + k325 + 1 * 1 + 0 * 2 + 0 * 1] = val322[0 + k325] + CAT_SZ;
      }
    }
    r.map_cont_cat2_degree3[val321] = cnt299 + cnt327;
    r.rev_cont_cat2_degree3[cnt299 + cnt327] = val321;
    cnt327++;
  }
}
;
;

cnt299 += (CONT_SZ) * (CAT_SZ2);
;
;
std::array<size_t, 1 + 2> val328;
;
;
;

size_t cnt333 = 0;
for (size_t i329 = 0; i329 < CAT_SZ * (CAT_SZ - 1) / 2; i329++) {
  val134 = rev_cat_degree2.find(i329)->second;
  for (size_t j330 = 0; j330 < CONT_SZ2; j330++) {
    val18 = other.rev_cont_sum1.find(j330)->second;
    for (size_t r332 = 0; r332 < 1; r332++) {
      for (size_t k331 = 0; k331 < 0; k331++) {
        val328[r332 * 0 + k331] = val134[k331] + 0;
      }
    }
    for (size_t r332 = 0; r332 < 1; r332++) {
      for (size_t k331 = 0; k331 < 1; k331++) {
        val328[r332 * 1 + k331 + 0 * 1] = val18[k331] + CONT_SZ;
      }
    }
    for (size_t r332 = 0; r332 < 1; r332++) {
      for (size_t k331 = 0; k331 < 2; k331++) {
        val328[r332 * 2 + k331 + 0 * 1 + 1 * 1] = val134[0 + k331] + 0;
      }
    }
    for (size_t r332 = 0; r332 < 1; r332++) {
      for (size_t k331 = 0; k331 < 0; k331++) {
        val328[r332 * 0 + k331 + 0 * 1 + 1 * 1 + 2 * 1] = val18[1 + k331] + 0;
      }
    }
    r.map_cont_cat2_degree3[val328] = cnt299 + cnt333;
    r.rev_cont_cat2_degree3[cnt299 + cnt333] = val328;
    cnt333++;
  }
}
;
;

cnt299 += (CAT_SZ * (CAT_SZ - 1) / 2) * (CONT_SZ2);
;
;
std::array<size_t, 1 + 2> val334;
;
;
;

size_t cnt339 = 0;
for (size_t i335 = 0; i335 < CONT_SZ; i335++) {
  val11 = rev_cont_sum1.find(i335)->second;
  for (size_t j336 = 0; j336 < CAT_SZ2 * (CAT_SZ2 - 1) / 2; j336++) {
    val141 = other.rev_cat_degree2.find(j336)->second;
    for (size_t r338 = 0; r338 < 1; r338++) {
      for (size_t k337 = 0; k337 < 1; k337++) {
        val334[r338 * 1 + k337] = val11[k337] + 0;
      }
    }
    for (size_t r338 = 0; r338 < 1; r338++) {
      for (size_t k337 = 0; k337 < 0; k337++) {
        val334[r338 * 0 + k337 + 1 * 1] = val141[k337] + CONT_SZ;
      }
    }
    for (size_t r338 = 0; r338 < 1; r338++) {
      for (size_t k337 = 0; k337 < 0; k337++) {
        val334[r338 * 0 + k337 + 1 * 1 + 0 * 1] = val11[1 + k337] + 0;
      }
    }
    for (size_t r338 = 0; r338 < 1; r338++) {
      for (size_t k337 = 0; k337 < 2; k337++) {
        val334[r338 * 2 + k337 + 1 * 1 + 0 * 1 + 0 * 1] = val141[0 + k337] + CAT_SZ;
      }
    }
    r.map_cont_cat2_degree3[val334] = cnt299 + cnt339;
    r.rev_cont_cat2_degree3[cnt299 + cnt339] = val334;
    cnt339++;
  }
}
;
;

cnt299 += (CONT_SZ) * (CAT_SZ2 * (CAT_SZ2 - 1) / 2);
;
;
std::array<size_t, 1 + 2> val340;
;
;
;

size_t cnt345 = 0;
for (size_t i341 = 0; i341 < CONT_SZ * CAT_SZ; i341++) {
  val182 = rev_cont_cat_degree2.find(i341)->second;
  for (size_t j342 = 0; j342 < CAT_SZ2; j342++) {
    val90 = other.rev_cat_sum1.find(j342)->second;
    for (size_t r344 = 0; r344 < 1; r344++) {
      for (size_t k343 = 0; k343 < 1; k343++) {
        val340[r344 * 1 + k343] = val182[k343] + 0;
      }
    }
    for (size_t r344 = 0; r344 < 1; r344++) {
      for (size_t k343 = 0; k343 < 0; k343++) {
        val340[r344 * 0 + k343 + 1 * 1] = val90[k343] + CONT_SZ;
      }
    }
    for (size_t r344 = 0; r344 < 1; r344++) {
      for (size_t k343 = 0; k343 < 1; k343++) {
        val340[r344 * 1 + k343 + 1 * 1 + 0 * 1] = val182[1 + k343] + 0;
      }
    }
    for (size_t r344 = 0; r344 < 1; r344++) {
      for (size_t k343 = 0; k343 < 1; k343++) {
        val340[r344 * 1 + k343 + 1 * 1 + 0 * 1 + 1 * 1] = val90[0 + k343] + CAT_SZ;
      }
    }
    r.map_cont_cat2_degree3[val340] = cnt299 + cnt345;
    r.rev_cont_cat2_degree3[cnt299 + cnt345] = val340;
    cnt345++;
  }
}
;
;

cnt299 += (CONT_SZ * CAT_SZ) * (CAT_SZ2);
;
;
std::array<size_t, 1 + 2> val346;
;
;
;

size_t cnt351 = 0;
for (size_t i347 = 0; i347 < CAT_SZ; i347++) {
  val83 = rev_cat_sum1.find(i347)->second;
  for (size_t j348 = 0; j348 < CONT_SZ2 * CAT_SZ2; j348++) {
    val189 = other.rev_cont_cat_degree2.find(j348)->second;
    for (size_t r350 = 0; r350 < 1; r350++) {
      for (size_t k349 = 0; k349 < 0; k349++) {
        val346[r350 * 0 + k349] = val83[k349] + 0;
      }
    }
    for (size_t r350 = 0; r350 < 1; r350++) {
      for (size_t k349 = 0; k349 < 1; k349++) {
        val346[r350 * 1 + k349 + 0 * 1] = val189[k349] + CONT_SZ;
      }
    }
    for (size_t r350 = 0; r350 < 1; r350++) {
      for (size_t k349 = 0; k349 < 1; k349++) {
        val346[r350 * 1 + k349 + 0 * 1 + 1 * 1] = val83[0 + k349] + 0;
      }
    }
    for (size_t r350 = 0; r350 < 1; r350++) {
      for (size_t k349 = 0; k349 < 1; k349++) {
        val346[r350 * 1 + k349 + 0 * 1 + 1 * 1 + 1 * 1] = val189[1 + k349] + CAT_SZ;
      }
    }
    r.map_cont_cat2_degree3[val346] = cnt299 + cnt351;
    r.rev_cont_cat2_degree3[cnt299 + cnt351] = val346;
    cnt351++;
  }
}
;
;

cnt299 += (CAT_SZ) * (CONT_SZ2 * CAT_SZ2);
;
;
;
size_t cnt352 = 0;
;
std::array<size_t, 0 + 3> val353;
;
std::array<size_t, 0 + 3> val354;
;
;

size_t cnt359 = 0;
for (size_t i355 = 0; i355 < CAT_SZ * (CAT_SZ - 1) * (CAT_SZ - 2) / 6 + CAT_SZ * (CAT_SZ - 1); i355++) {
  val354 = rev_cat_degree3.find(i355)->second;
  for (size_t j356 = 0; j356 < 1; j356++) {
    val3 = other.rev_count.find(j356)->second;
    for (size_t r358 = 0; r358 < 1; r358++) {
      for (size_t k357 = 0; k357 < 0; k357++) {
        val353[r358 * 0 + k357] = val354[k357] + 0;
      }
    }
    for (size_t r358 = 0; r358 < 1; r358++) {
      for (size_t k357 = 0; k357 < 0; k357++) {
        val353[r358 * 0 + k357 + 0 * 1] = val3[k357] + 0;
      }
    }
    for (size_t r358 = 0; r358 < 1; r358++) {
      for (size_t k357 = 0; k357 < 3; k357++) {
        val353[r358 * 3 + k357 + 0 * 1 + 0 * 1] = val354[0 + k357] + 0;
      }
    }
    for (size_t r358 = 0; r358 < 1; r358++) {
      for (size_t k357 = 0; k357 < 0; k357++) {
        val353[r358 * 0 + k357 + 0 * 1 + 0 * 1 + 3 * 1] = val3[0 + k357] + 0;
      }
    }
    r.map_cat_degree3[val353] = cnt352 + cnt359;
    r.rev_cat_degree3[cnt352 + cnt359] = val353;
    cnt359++;
  }
}
;
;

cnt352 += (CAT_SZ * (CAT_SZ - 1) * (CAT_SZ - 2) / 6 + CAT_SZ * (CAT_SZ - 1)) * (1);
;
;
std::array<size_t, 0 + 3> val360;
;
;
std::array<size_t, 0 + 3> val361;
;

size_t cnt366 = 0;
for (size_t i362 = 0; i362 < 1; i362++) {
  val2 = rev_count.find(i362)->second;
  for (size_t j363 = 0; j363 < CAT_SZ2 * (CAT_SZ2 - 1) * (CAT_SZ2 - 2) / 6 + CAT_SZ2 * (CAT_SZ2 - 1); j363++) {
    val361 = other.rev_cat_degree3.find(j363)->second;
    for (size_t r365 = 0; r365 < 1; r365++) {
      for (size_t k364 = 0; k364 < 0; k364++) {
        val360[r365 * 0 + k364] = val2[k364] + 0;
      }
    }
    for (size_t r365 = 0; r365 < 1; r365++) {
      for (size_t k364 = 0; k364 < 0; k364++) {
        val360[r365 * 0 + k364 + 0 * 1] = val361[k364] + CONT_SZ;
      }
    }
    for (size_t r365 = 0; r365 < 1; r365++) {
      for (size_t k364 = 0; k364 < 0; k364++) {
        val360[r365 * 0 + k364 + 0 * 1 + 0 * 1] = val2[0 + k364] + 0;
      }
    }
    for (size_t r365 = 0; r365 < 1; r365++) {
      for (size_t k364 = 0; k364 < 3; k364++) {
        val360[r365 * 3 + k364 + 0 * 1 + 0 * 1 + 0 * 1] = val361[0 + k364] + CAT_SZ;
      }
    }
    r.map_cat_degree3[val360] = cnt352 + cnt366;
    r.rev_cat_degree3[cnt352 + cnt366] = val360;
    cnt366++;
  }
}
;
;

cnt352 += (1) * (CAT_SZ2 * (CAT_SZ2 - 1) * (CAT_SZ2 - 2) / 6 + CAT_SZ2 * (CAT_SZ2 - 1));
;
;
std::array<size_t, 0 + 3> val367;
;
;
;

size_t cnt372 = 0;
for (size_t i368 = 0; i368 < CAT_SZ; i368++) {
  val83 = rev_cat_sum1.find(i368)->second;
  for (size_t j369 = 0; j369 < CAT_SZ2 * (CAT_SZ2 - 1) / 2; j369++) {
    val141 = other.rev_cat_degree2.find(j369)->second;
    for (size_t r371 = 0; r371 < 1; r371++) {
      for (size_t k370 = 0; k370 < 0; k370++) {
        val367[r371 * 0 + k370] = val83[k370] + 0;
      }
    }
    for (size_t r371 = 0; r371 < 1; r371++) {
      for (size_t k370 = 0; k370 < 0; k370++) {
        val367[r371 * 0 + k370 + 0 * 1] = val141[k370] + CONT_SZ;
      }
    }
    for (size_t r371 = 0; r371 < 1; r371++) {
      for (size_t k370 = 0; k370 < 1; k370++) {
        val367[r371 * 1 + k370 + 0 * 1 + 0 * 1] = val83[0 + k370] + 0;
      }
    }
    for (size_t r371 = 0; r371 < 1; r371++) {
      for (size_t k370 = 0; k370 < 2; k370++) {
        val367[r371 * 2 + k370 + 0 * 1 + 0 * 1 + 1 * 1] = val141[0 + k370] + CAT_SZ;
      }
    }
    r.map_cat_degree3[val367] = cnt352 + cnt372;
    r.rev_cat_degree3[cnt352 + cnt372] = val367;
    cnt372++;
  }
}
;
;

cnt352 += (CAT_SZ) * (CAT_SZ2 * (CAT_SZ2 - 1) / 2);
;
;
std::array<size_t, 0 + 3> val373;
;
;
;

size_t cnt378 = 0;
for (size_t i374 = 0; i374 < CAT_SZ * (CAT_SZ - 1) / 2; i374++) {
  val134 = rev_cat_degree2.find(i374)->second;
  for (size_t j375 = 0; j375 < CAT_SZ2; j375++) {
    val90 = other.rev_cat_sum1.find(j375)->second;
    for (size_t r377 = 0; r377 < 1; r377++) {
      for (size_t k376 = 0; k376 < 0; k376++) {
        val373[r377 * 0 + k376] = val134[k376] + 0;
      }
    }
    for (size_t r377 = 0; r377 < 1; r377++) {
      for (size_t k376 = 0; k376 < 0; k376++) {
        val373[r377 * 0 + k376 + 0 * 1] = val90[k376] + CONT_SZ;
      }
    }
    for (size_t r377 = 0; r377 < 1; r377++) {
      for (size_t k376 = 0; k376 < 2; k376++) {
        val373[r377 * 2 + k376 + 0 * 1 + 0 * 1] = val134[0 + k376] + 0;
      }
    }
    for (size_t r377 = 0; r377 < 1; r377++) {
      for (size_t k376 = 0; k376 < 1; k376++) {
        val373[r377 * 1 + k376 + 0 * 1 + 0 * 1 + 2 * 1] = val90[0 + k376] + CAT_SZ;
      }
    }
    r.map_cat_degree3[val373] = cnt352 + cnt378;
    r.rev_cat_degree3[cnt352 + cnt378] = val373;
    cnt378++;
  }
}
;
;

cnt352 += (CAT_SZ * (CAT_SZ - 1) / 2) * (CAT_SZ2);
;
;
std::array<size_t, 0 + 3> val379;
;
;
;

size_t cnt384 = 0;
for (size_t i380 = 0; i380 < CAT_SZ; i380++) {
  val83 = rev_cat_sum1.find(i380)->second;
  for (size_t j381 = 0; j381 < CAT_SZ2; j381++) {
    val322 = other.rev_cat_sum2.find(j381)->second;
    for (size_t r383 = 0; r383 < 1; r383++) {
      for (size_t k382 = 0; k382 < 0; k382++) {
        val379[r383 * 0 + k382] = val83[k382] + 0;
      }
    }
    for (size_t r383 = 0; r383 < 2; r383++) {
      for (size_t k382 = 0; k382 < 0; k382++) {
        val379[r383 * 0 + k382 + 0 * 1] = val322[k382] + CONT_SZ;
      }
    }
    for (size_t r383 = 0; r383 < 1; r383++) {
      for (size_t k382 = 0; k382 < 1; k382++) {
        val379[r383 * 1 + k382 + 0 * 1 + 0 * 2] = val83[0 + k382] + 0;
      }
    }
    for (size_t r383 = 0; r383 < 2; r383++) {
      for (size_t k382 = 0; k382 < 1; k382++) {
        val379[r383 * 1 + k382 + 0 * 1 + 0 * 2 + 1 * 1] = val322[0 + k382] + CAT_SZ;
      }
    }
    r.map_cat_degree3[val379] = cnt352 + cnt384;
    r.rev_cat_degree3[cnt352 + cnt384] = val379;
    cnt384++;
  }
}
;
;

cnt352 += (CAT_SZ) * (CAT_SZ2);
;
;
std::array<size_t, 0 + 3> val385;
;
;
;

size_t cnt390 = 0;
for (size_t i386 = 0; i386 < CAT_SZ; i386++) {
  val315 = rev_cat_sum2.find(i386)->second;
  for (size_t j387 = 0; j387 < CAT_SZ2; j387++) {
    val90 = other.rev_cat_sum1.find(j387)->second;
    for (size_t r389 = 0; r389 < 2; r389++) {
      for (size_t k388 = 0; k388 < 0; k388++) {
        val385[r389 * 0 + k388] = val315[k388] + 0;
      }
    }
    for (size_t r389 = 0; r389 < 1; r389++) {
      for (size_t k388 = 0; k388 < 0; k388++) {
        val385[r389 * 0 + k388 + 0 * 2] = val90[k388] + CONT_SZ;
      }
    }
    for (size_t r389 = 0; r389 < 2; r389++) {
      for (size_t k388 = 0; k388 < 1; k388++) {
        val385[r389 * 1 + k388 + 0 * 2 + 0 * 1] = val315[0 + k388] + 0;
      }
    }
    for (size_t r389 = 0; r389 < 1; r389++) {
      for (size_t k388 = 0; k388 < 1; k388++) {
        val385[r389 * 1 + k388 + 0 * 2 + 0 * 1 + 1 * 2] = val90[0 + k388] + CAT_SZ;
      }
    }
    r.map_cat_degree3[val385] = cnt352 + cnt390;
    r.rev_cat_degree3[cnt352 + cnt390] = val385;
    cnt390++;
  }
}
;
;

cnt352 += (CAT_SZ) * (CAT_SZ2);
;
;
;
size_t cnt391 = 0;
;
std::array<size_t, 4 + 0> val392;
;
std::array<size_t, 4 + 0> val393;
;
;

size_t cnt398 = 0;
for (size_t i394 = 0; i394 < CONT_SZ * (CONT_SZ - 1) * (CONT_SZ - 2) * (CONT_SZ - 3) / 24 + CONT_SZ * (CONT_SZ - 1) * (CONT_SZ - 2) / 2; i394++) {
  val393 = rev_cont_degree4.find(i394)->second;
  for (size_t j395 = 0; j395 < 1; j395++) {
    val3 = other.rev_count.find(j395)->second;
    for (size_t r397 = 0; r397 < 1; r397++) {
      for (size_t k396 = 0; k396 < 4; k396++) {
        val392[r397 * 4 + k396] = val393[k396] + 0;
      }
    }
    for (size_t r397 = 0; r397 < 1; r397++) {
      for (size_t k396 = 0; k396 < 0; k396++) {
        val392[r397 * 0 + k396 + 4 * 1] = val3[k396] + 0;
      }
    }
    for (size_t r397 = 0; r397 < 1; r397++) {
      for (size_t k396 = 0; k396 < 0; k396++) {
        val392[r397 * 0 + k396 + 4 * 1 + 0 * 1] = val393[4 + k396] + 0;
      }
    }
    for (size_t r397 = 0; r397 < 1; r397++) {
      for (size_t k396 = 0; k396 < 0; k396++) {
        val392[r397 * 0 + k396 + 4 * 1 + 0 * 1 + 0 * 1] = val3[0 + k396] + 0;
      }
    }
    r.map_cont_degree4[val392] = cnt391 + cnt398;
    r.rev_cont_degree4[cnt391 + cnt398] = val392;
    cnt398++;
  }
}
;
;

cnt391 += (CONT_SZ * (CONT_SZ - 1) * (CONT_SZ - 2) * (CONT_SZ - 3) / 24 + CONT_SZ * (CONT_SZ - 1) * (CONT_SZ - 2) / 2) * (1);
;
;
std::array<size_t, 4 + 0> val399;
;
;
std::array<size_t, 4 + 0> val400;
;

size_t cnt405 = 0;
for (size_t i401 = 0; i401 < 1; i401++) {
  val2 = rev_count.find(i401)->second;
  for (size_t j402 = 0; j402 < CONT_SZ2 * (CONT_SZ2 - 1) * (CONT_SZ2 - 2) * (CONT_SZ2 - 3) / 24 + CONT_SZ2 * (CONT_SZ2 - 1) * (CONT_SZ2 - 2) / 2; j402++) {
    val400 = other.rev_cont_degree4.find(j402)->second;
    for (size_t r404 = 0; r404 < 1; r404++) {
      for (size_t k403 = 0; k403 < 0; k403++) {
        val399[r404 * 0 + k403] = val2[k403] + 0;
      }
    }
    for (size_t r404 = 0; r404 < 1; r404++) {
      for (size_t k403 = 0; k403 < 4; k403++) {
        val399[r404 * 4 + k403 + 0 * 1] = val400[k403] + CONT_SZ;
      }
    }
    for (size_t r404 = 0; r404 < 1; r404++) {
      for (size_t k403 = 0; k403 < 0; k403++) {
        val399[r404 * 0 + k403 + 0 * 1 + 4 * 1] = val2[0 + k403] + 0;
      }
    }
    for (size_t r404 = 0; r404 < 1; r404++) {
      for (size_t k403 = 0; k403 < 0; k403++) {
        val399[r404 * 0 + k403 + 0 * 1 + 4 * 1 + 0 * 1] = val400[4 + k403] + 0;
      }
    }
    r.map_cont_degree4[val399] = cnt391 + cnt405;
    r.rev_cont_degree4[cnt391 + cnt405] = val399;
    cnt405++;
  }
}
;
;

cnt391 += (1) * (CONT_SZ2 * (CONT_SZ2 - 1) * (CONT_SZ2 - 2) * (CONT_SZ2 - 3) / 24 + CONT_SZ2 * (CONT_SZ2 - 1) * (CONT_SZ2 - 2) / 2);
;
;
std::array<size_t, 4 + 0> val406;
;
;
;

size_t cnt411 = 0;
for (size_t i407 = 0; i407 < CONT_SZ * (CONT_SZ - 1) / 2; i407++) {
  val62 = rev_cont_degree2.find(i407)->second;
  for (size_t j408 = 0; j408 < CONT_SZ2 * (CONT_SZ2 - 1) / 2; j408++) {
    val69 = other.rev_cont_degree2.find(j408)->second;
    for (size_t r410 = 0; r410 < 1; r410++) {
      for (size_t k409 = 0; k409 < 2; k409++) {
        val406[r410 * 2 + k409] = val62[k409] + 0;
      }
    }
    for (size_t r410 = 0; r410 < 1; r410++) {
      for (size_t k409 = 0; k409 < 2; k409++) {
        val406[r410 * 2 + k409 + 2 * 1] = val69[k409] + CONT_SZ;
      }
    }
    for (size_t r410 = 0; r410 < 1; r410++) {
      for (size_t k409 = 0; k409 < 0; k409++) {
        val406[r410 * 0 + k409 + 2 * 1 + 2 * 1] = val62[2 + k409] + 0;
      }
    }
    for (size_t r410 = 0; r410 < 1; r410++) {
      for (size_t k409 = 0; k409 < 0; k409++) {
        val406[r410 * 0 + k409 + 2 * 1 + 2 * 1 + 0 * 1] = val69[2 + k409] + 0;
      }
    }
    r.map_cont_degree4[val406] = cnt391 + cnt411;
    r.rev_cont_degree4[cnt391 + cnt411] = val406;
    cnt411++;
  }
}
;
;

cnt391 += (CONT_SZ * (CONT_SZ - 1) / 2) * (CONT_SZ2 * (CONT_SZ2 - 1) / 2);
;
;
std::array<size_t, 4 + 0> val412;
;
;
;

size_t cnt417 = 0;
for (size_t i413 = 0; i413 < CONT_SZ * (CONT_SZ - 1) / 2; i413++) {
  val62 = rev_cont_degree2.find(i413)->second;
  for (size_t j414 = 0; j414 < CONT_SZ2; j414++) {
    val235 = other.rev_cont_sum2.find(j414)->second;
    for (size_t r416 = 0; r416 < 1; r416++) {
      for (size_t k415 = 0; k415 < 2; k415++) {
        val412[r416 * 2 + k415] = val62[k415] + 0;
      }
    }
    for (size_t r416 = 0; r416 < 2; r416++) {
      for (size_t k415 = 0; k415 < 1; k415++) {
        val412[r416 * 1 + k415 + 2 * 1] = val235[k415] + CONT_SZ;
      }
    }
    for (size_t r416 = 0; r416 < 1; r416++) {
      for (size_t k415 = 0; k415 < 0; k415++) {
        val412[r416 * 0 + k415 + 2 * 1 + 1 * 2] = val62[2 + k415] + 0;
      }
    }
    for (size_t r416 = 0; r416 < 2; r416++) {
      for (size_t k415 = 0; k415 < 0; k415++) {
        val412[r416 * 0 + k415 + 2 * 1 + 1 * 2 + 0 * 1] = val235[1 + k415] + 0;
      }
    }
    r.map_cont_degree4[val412] = cnt391 + cnt417;
    r.rev_cont_degree4[cnt391 + cnt417] = val412;
    cnt417++;
  }
}
;
;

cnt391 += (CONT_SZ * (CONT_SZ - 1) / 2) * (CONT_SZ2);
;
;
std::array<size_t, 4 + 0> val418;
;
;
;

size_t cnt423 = 0;
for (size_t i419 = 0; i419 < CONT_SZ; i419++) {
  val242 = rev_cont_sum2.find(i419)->second;
  for (size_t j420 = 0; j420 < CONT_SZ2 * (CONT_SZ2 - 1) / 2; j420++) {
    val69 = other.rev_cont_degree2.find(j420)->second;
    for (size_t r422 = 0; r422 < 2; r422++) {
      for (size_t k421 = 0; k421 < 1; k421++) {
        val418[r422 * 1 + k421] = val242[k421] + 0;
      }
    }
    for (size_t r422 = 0; r422 < 1; r422++) {
      for (size_t k421 = 0; k421 < 2; k421++) {
        val418[r422 * 2 + k421 + 1 * 2] = val69[k421] + CONT_SZ;
      }
    }
    for (size_t r422 = 0; r422 < 2; r422++) {
      for (size_t k421 = 0; k421 < 0; k421++) {
        val418[r422 * 0 + k421 + 1 * 2 + 2 * 1] = val242[1 + k421] + 0;
      }
    }
    for (size_t r422 = 0; r422 < 1; r422++) {
      for (size_t k421 = 0; k421 < 0; k421++) {
        val418[r422 * 0 + k421 + 1 * 2 + 2 * 1 + 0 * 2] = val69[2 + k421] + 0;
      }
    }
    r.map_cont_degree4[val418] = cnt391 + cnt423;
    r.rev_cont_degree4[cnt391 + cnt423] = val418;
    cnt423++;
  }
}
;
;

cnt391 += (CONT_SZ) * (CONT_SZ2 * (CONT_SZ2 - 1) / 2);
;
;
std::array<size_t, 4 + 0> val424;
;
;
;

size_t cnt429 = 0;
for (size_t i425 = 0; i425 < CONT_SZ * (CONT_SZ - 1) * (CONT_SZ - 2) / 6 + CONT_SZ * (CONT_SZ - 1); i425++) {
  val209 = rev_cont_degree3.find(i425)->second;
  for (size_t j426 = 0; j426 < CONT_SZ2; j426++) {
    val18 = other.rev_cont_sum1.find(j426)->second;
    for (size_t r428 = 0; r428 < 1; r428++) {
      for (size_t k427 = 0; k427 < 3; k427++) {
        val424[r428 * 3 + k427] = val209[k427] + 0;
      }
    }
    for (size_t r428 = 0; r428 < 1; r428++) {
      for (size_t k427 = 0; k427 < 1; k427++) {
        val424[r428 * 1 + k427 + 3 * 1] = val18[k427] + CONT_SZ;
      }
    }
    for (size_t r428 = 0; r428 < 1; r428++) {
      for (size_t k427 = 0; k427 < 0; k427++) {
        val424[r428 * 0 + k427 + 3 * 1 + 1 * 1] = val209[3 + k427] + 0;
      }
    }
    for (size_t r428 = 0; r428 < 1; r428++) {
      for (size_t k427 = 0; k427 < 0; k427++) {
        val424[r428 * 0 + k427 + 3 * 1 + 1 * 1 + 0 * 1] = val18[1 + k427] + 0;
      }
    }
    r.map_cont_degree4[val424] = cnt391 + cnt429;
    r.rev_cont_degree4[cnt391 + cnt429] = val424;
    cnt429++;
  }
}
;
;

cnt391 += (CONT_SZ * (CONT_SZ - 1) * (CONT_SZ - 2) / 6 + CONT_SZ * (CONT_SZ - 1)) * (CONT_SZ2);
;
;
std::array<size_t, 4 + 0> val430;
;
;
;

size_t cnt435 = 0;
for (size_t i431 = 0; i431 < CONT_SZ; i431++) {
  val11 = rev_cont_sum1.find(i431)->second;
  for (size_t j432 = 0; j432 < CONT_SZ2 * (CONT_SZ2 - 1) * (CONT_SZ2 - 2) / 6 + CONT_SZ2 * (CONT_SZ2 - 1); j432++) {
    val216 = other.rev_cont_degree3.find(j432)->second;
    for (size_t r434 = 0; r434 < 1; r434++) {
      for (size_t k433 = 0; k433 < 1; k433++) {
        val430[r434 * 1 + k433] = val11[k433] + 0;
      }
    }
    for (size_t r434 = 0; r434 < 1; r434++) {
      for (size_t k433 = 0; k433 < 3; k433++) {
        val430[r434 * 3 + k433 + 1 * 1] = val216[k433] + CONT_SZ;
      }
    }
    for (size_t r434 = 0; r434 < 1; r434++) {
      for (size_t k433 = 0; k433 < 0; k433++) {
        val430[r434 * 0 + k433 + 1 * 1 + 3 * 1] = val11[1 + k433] + 0;
      }
    }
    for (size_t r434 = 0; r434 < 1; r434++) {
      for (size_t k433 = 0; k433 < 0; k433++) {
        val430[r434 * 0 + k433 + 1 * 1 + 3 * 1 + 0 * 1] = val216[3 + k433] + 0;
      }
    }
    r.map_cont_degree4[val430] = cnt391 + cnt435;
    r.rev_cont_degree4[cnt391 + cnt435] = val430;
    cnt435++;
  }
}
;
;

cnt391 += (CONT_SZ) * (CONT_SZ2 * (CONT_SZ2 - 1) * (CONT_SZ2 - 2) / 6 + CONT_SZ2 * (CONT_SZ2 - 1));
;
;
;
size_t cnt436 = 0;
;
std::array<size_t, 3 + 1> val437;
;
std::array<size_t, 3 + 1> val438;
;
;

size_t cnt443 = 0;
for (size_t i439 = 0; i439 < (CONT_SZ * (CONT_SZ - 1) * (CONT_SZ - 2) / 6 + CONT_SZ * (CONT_SZ - 1)) * CAT_SZ; i439++) {
  val438 = rev_cont3_cat_degree4.find(i439)->second;
  for (size_t j440 = 0; j440 < 1; j440++) {
    val3 = other.rev_count.find(j440)->second;
    for (size_t r442 = 0; r442 < 1; r442++) {
      for (size_t k441 = 0; k441 < 3; k441++) {
        val437[r442 * 3 + k441] = val438[k441] + 0;
      }
    }
    for (size_t r442 = 0; r442 < 1; r442++) {
      for (size_t k441 = 0; k441 < 0; k441++) {
        val437[r442 * 0 + k441 + 3 * 1] = val3[k441] + 0;
      }
    }
    for (size_t r442 = 0; r442 < 1; r442++) {
      for (size_t k441 = 0; k441 < 1; k441++) {
        val437[r442 * 1 + k441 + 3 * 1 + 0 * 1] = val438[3 + k441] + 0;
      }
    }
    for (size_t r442 = 0; r442 < 1; r442++) {
      for (size_t k441 = 0; k441 < 0; k441++) {
        val437[r442 * 0 + k441 + 3 * 1 + 0 * 1 + 1 * 1] = val3[0 + k441] + 0;
      }
    }
    r.map_cont3_cat_degree4[val437] = cnt436 + cnt443;
    r.rev_cont3_cat_degree4[cnt436 + cnt443] = val437;
    cnt443++;
  }
}
;
;

cnt436 += ((CONT_SZ * (CONT_SZ - 1) * (CONT_SZ - 2) / 6 + CONT_SZ * (CONT_SZ - 1)) * CAT_SZ) * (1);
;
;
std::array<size_t, 3 + 1> val444;
;
;
std::array<size_t, 3 + 1> val445;
;

size_t cnt450 = 0;
for (size_t i446 = 0; i446 < 1; i446++) {
  val2 = rev_count.find(i446)->second;
  for (size_t j447 = 0; j447 < (CONT_SZ2 * (CONT_SZ2 - 1) * (CONT_SZ2 - 2) / 6 + CONT_SZ2 * (CONT_SZ2 - 1)) * CAT_SZ2; j447++) {
    val445 = other.rev_cont3_cat_degree4.find(j447)->second;
    for (size_t r449 = 0; r449 < 1; r449++) {
      for (size_t k448 = 0; k448 < 0; k448++) {
        val444[r449 * 0 + k448] = val2[k448] + 0;
      }
    }
    for (size_t r449 = 0; r449 < 1; r449++) {
      for (size_t k448 = 0; k448 < 3; k448++) {
        val444[r449 * 3 + k448 + 0 * 1] = val445[k448] + CONT_SZ;
      }
    }
    for (size_t r449 = 0; r449 < 1; r449++) {
      for (size_t k448 = 0; k448 < 0; k448++) {
        val444[r449 * 0 + k448 + 0 * 1 + 3 * 1] = val2[0 + k448] + 0;
      }
    }
    for (size_t r449 = 0; r449 < 1; r449++) {
      for (size_t k448 = 0; k448 < 1; k448++) {
        val444[r449 * 1 + k448 + 0 * 1 + 3 * 1 + 0 * 1] = val445[3 + k448] + CAT_SZ;
      }
    }
    r.map_cont3_cat_degree4[val444] = cnt436 + cnt450;
    r.rev_cont3_cat_degree4[cnt436 + cnt450] = val444;
    cnt450++;
  }
}
;
;

cnt436 += (1) * ((CONT_SZ2 * (CONT_SZ2 - 1) * (CONT_SZ2 - 2) / 6 + CONT_SZ2 * (CONT_SZ2 - 1)) * CAT_SZ2);
;
;
std::array<size_t, 3 + 1> val451;
;
;
;

size_t cnt456 = 0;
for (size_t i452 = 0; i452 < CONT_SZ * (CONT_SZ - 1) * (CONT_SZ - 2) / 6 + CONT_SZ * (CONT_SZ - 1); i452++) {
  val209 = rev_cont_degree3.find(i452)->second;
  for (size_t j453 = 0; j453 < CAT_SZ2; j453++) {
    val90 = other.rev_cat_sum1.find(j453)->second;
    for (size_t r455 = 0; r455 < 1; r455++) {
      for (size_t k454 = 0; k454 < 3; k454++) {
        val451[r455 * 3 + k454] = val209[k454] + 0;
      }
    }
    for (size_t r455 = 0; r455 < 1; r455++) {
      for (size_t k454 = 0; k454 < 0; k454++) {
        val451[r455 * 0 + k454 + 3 * 1] = val90[k454] + CONT_SZ;
      }
    }
    for (size_t r455 = 0; r455 < 1; r455++) {
      for (size_t k454 = 0; k454 < 0; k454++) {
        val451[r455 * 0 + k454 + 3 * 1 + 0 * 1] = val209[3 + k454] + 0;
      }
    }
    for (size_t r455 = 0; r455 < 1; r455++) {
      for (size_t k454 = 0; k454 < 1; k454++) {
        val451[r455 * 1 + k454 + 3 * 1 + 0 * 1 + 0 * 1] = val90[0 + k454] + CAT_SZ;
      }
    }
    r.map_cont3_cat_degree4[val451] = cnt436 + cnt456;
    r.rev_cont3_cat_degree4[cnt436 + cnt456] = val451;
    cnt456++;
  }
}
;
;

cnt436 += (CONT_SZ * (CONT_SZ - 1) * (CONT_SZ - 2) / 6 + CONT_SZ * (CONT_SZ - 1)) * (CAT_SZ2);
;
;
std::array<size_t, 3 + 1> val457;
;
;
;

size_t cnt462 = 0;
for (size_t i458 = 0; i458 < CAT_SZ; i458++) {
  val83 = rev_cat_sum1.find(i458)->second;
  for (size_t j459 = 0; j459 < CONT_SZ2 * (CONT_SZ2 - 1) * (CONT_SZ2 - 2) / 6 + CONT_SZ2 * (CONT_SZ2 - 1); j459++) {
    val216 = other.rev_cont_degree3.find(j459)->second;
    for (size_t r461 = 0; r461 < 1; r461++) {
      for (size_t k460 = 0; k460 < 0; k460++) {
        val457[r461 * 0 + k460] = val83[k460] + 0;
      }
    }
    for (size_t r461 = 0; r461 < 1; r461++) {
      for (size_t k460 = 0; k460 < 3; k460++) {
        val457[r461 * 3 + k460 + 0 * 1] = val216[k460] + CONT_SZ;
      }
    }
    for (size_t r461 = 0; r461 < 1; r461++) {
      for (size_t k460 = 0; k460 < 1; k460++) {
        val457[r461 * 1 + k460 + 0 * 1 + 3 * 1] = val83[0 + k460] + 0;
      }
    }
    for (size_t r461 = 0; r461 < 1; r461++) {
      for (size_t k460 = 0; k460 < 0; k460++) {
        val457[r461 * 0 + k460 + 0 * 1 + 3 * 1 + 1 * 1] = val216[3 + k460] + 0;
      }
    }
    r.map_cont3_cat_degree4[val457] = cnt436 + cnt462;
    r.rev_cont3_cat_degree4[cnt436 + cnt462] = val457;
    cnt462++;
  }
}
;
;

cnt436 += (CAT_SZ) * (CONT_SZ2 * (CONT_SZ2 - 1) * (CONT_SZ2 - 2) / 6 + CONT_SZ2 * (CONT_SZ2 - 1));
;
;
std::array<size_t, 3 + 1> val463;
;
;
;

size_t cnt468 = 0;
for (size_t i464 = 0; i464 < CONT_SZ * (CONT_SZ + 1) / 2 * CAT_SZ; i464++) {
  val250 = rev_cont2_cat_degree3.find(i464)->second;
  for (size_t j465 = 0; j465 < CONT_SZ2; j465++) {
    val18 = other.rev_cont_sum1.find(j465)->second;
    for (size_t r467 = 0; r467 < 1; r467++) {
      for (size_t k466 = 0; k466 < 2; k466++) {
        val463[r467 * 2 + k466] = val250[k466] + 0;
      }
    }
    for (size_t r467 = 0; r467 < 1; r467++) {
      for (size_t k466 = 0; k466 < 1; k466++) {
        val463[r467 * 1 + k466 + 2 * 1] = val18[k466] + CONT_SZ;
      }
    }
    for (size_t r467 = 0; r467 < 1; r467++) {
      for (size_t k466 = 0; k466 < 1; k466++) {
        val463[r467 * 1 + k466 + 2 * 1 + 1 * 1] = val250[2 + k466] + 0;
      }
    }
    for (size_t r467 = 0; r467 < 1; r467++) {
      for (size_t k466 = 0; k466 < 0; k466++) {
        val463[r467 * 0 + k466 + 2 * 1 + 1 * 1 + 1 * 1] = val18[1 + k466] + 0;
      }
    }
    r.map_cont3_cat_degree4[val463] = cnt436 + cnt468;
    r.rev_cont3_cat_degree4[cnt436 + cnt468] = val463;
    cnt468++;
  }
}
;
;

cnt436 += (CONT_SZ * (CONT_SZ + 1) / 2 * CAT_SZ) * (CONT_SZ2);
;
;
std::array<size_t, 3 + 1> val469;
;
;
;

size_t cnt474 = 0;
for (size_t i470 = 0; i470 < CONT_SZ; i470++) {
  val11 = rev_cont_sum1.find(i470)->second;
  for (size_t j471 = 0; j471 < CONT_SZ2 * (CONT_SZ2 + 1) / 2 * CAT_SZ2; j471++) {
    val257 = other.rev_cont2_cat_degree3.find(j471)->second;
    for (size_t r473 = 0; r473 < 1; r473++) {
      for (size_t k472 = 0; k472 < 1; k472++) {
        val469[r473 * 1 + k472] = val11[k472] + 0;
      }
    }
    for (size_t r473 = 0; r473 < 1; r473++) {
      for (size_t k472 = 0; k472 < 2; k472++) {
        val469[r473 * 2 + k472 + 1 * 1] = val257[k472] + CONT_SZ;
      }
    }
    for (size_t r473 = 0; r473 < 1; r473++) {
      for (size_t k472 = 0; k472 < 0; k472++) {
        val469[r473 * 0 + k472 + 1 * 1 + 2 * 1] = val11[1 + k472] + 0;
      }
    }
    for (size_t r473 = 0; r473 < 1; r473++) {
      for (size_t k472 = 0; k472 < 1; k472++) {
        val469[r473 * 1 + k472 + 1 * 1 + 2 * 1 + 0 * 1] = val257[2 + k472] + CAT_SZ;
      }
    }
    r.map_cont3_cat_degree4[val469] = cnt436 + cnt474;
    r.rev_cont3_cat_degree4[cnt436 + cnt474] = val469;
    cnt474++;
  }
}
;
;

cnt436 += (CONT_SZ) * (CONT_SZ2 * (CONT_SZ2 + 1) / 2 * CAT_SZ2);
;
;
std::array<size_t, 3 + 1> val475;
;
;
;

size_t cnt480 = 0;
for (size_t i476 = 0; i476 < CONT_SZ * CAT_SZ; i476++) {
  val182 = rev_cont_cat_degree2.find(i476)->second;
  for (size_t j477 = 0; j477 < CONT_SZ2 * (CONT_SZ2 - 1) / 2; j477++) {
    val69 = other.rev_cont_degree2.find(j477)->second;
    for (size_t r479 = 0; r479 < 1; r479++) {
      for (size_t k478 = 0; k478 < 1; k478++) {
        val475[r479 * 1 + k478] = val182[k478] + 0;
      }
    }
    for (size_t r479 = 0; r479 < 1; r479++) {
      for (size_t k478 = 0; k478 < 2; k478++) {
        val475[r479 * 2 + k478 + 1 * 1] = val69[k478] + CONT_SZ;
      }
    }
    for (size_t r479 = 0; r479 < 1; r479++) {
      for (size_t k478 = 0; k478 < 1; k478++) {
        val475[r479 * 1 + k478 + 1 * 1 + 2 * 1] = val182[1 + k478] + 0;
      }
    }
    for (size_t r479 = 0; r479 < 1; r479++) {
      for (size_t k478 = 0; k478 < 0; k478++) {
        val475[r479 * 0 + k478 + 1 * 1 + 2 * 1 + 1 * 1] = val69[2 + k478] + 0;
      }
    }
    r.map_cont3_cat_degree4[val475] = cnt436 + cnt480;
    r.rev_cont3_cat_degree4[cnt436 + cnt480] = val475;
    cnt480++;
  }
}
;
;

cnt436 += (CONT_SZ * CAT_SZ) * (CONT_SZ2 * (CONT_SZ2 - 1) / 2);
;
;
std::array<size_t, 3 + 1> val481;
;
;
;

size_t cnt486 = 0;
for (size_t i482 = 0; i482 < CONT_SZ * (CONT_SZ - 1) / 2; i482++) {
  val62 = rev_cont_degree2.find(i482)->second;
  for (size_t j483 = 0; j483 < CONT_SZ2 * CAT_SZ2; j483++) {
    val189 = other.rev_cont_cat_degree2.find(j483)->second;
    for (size_t r485 = 0; r485 < 1; r485++) {
      for (size_t k484 = 0; k484 < 2; k484++) {
        val481[r485 * 2 + k484] = val62[k484] + 0;
      }
    }
    for (size_t r485 = 0; r485 < 1; r485++) {
      for (size_t k484 = 0; k484 < 1; k484++) {
        val481[r485 * 1 + k484 + 2 * 1] = val189[k484] + CONT_SZ;
      }
    }
    for (size_t r485 = 0; r485 < 1; r485++) {
      for (size_t k484 = 0; k484 < 0; k484++) {
        val481[r485 * 0 + k484 + 2 * 1 + 1 * 1] = val62[2 + k484] + 0;
      }
    }
    for (size_t r485 = 0; r485 < 1; r485++) {
      for (size_t k484 = 0; k484 < 1; k484++) {
        val481[r485 * 1 + k484 + 2 * 1 + 1 * 1 + 0 * 1] = val189[1 + k484] + CAT_SZ;
      }
    }
    r.map_cont3_cat_degree4[val481] = cnt436 + cnt486;
    r.rev_cont3_cat_degree4[cnt436 + cnt486] = val481;
    cnt486++;
  }
}
;
;

cnt436 += (CONT_SZ * (CONT_SZ - 1) / 2) * (CONT_SZ2 * CAT_SZ2);
;
;
std::array<size_t, 3 + 1> val487;
;
;
;

size_t cnt492 = 0;
for (size_t i488 = 0; i488 < CONT_SZ * CAT_SZ; i488++) {
  val182 = rev_cont_cat_degree2.find(i488)->second;
  for (size_t j489 = 0; j489 < CONT_SZ2; j489++) {
    val235 = other.rev_cont_sum2.find(j489)->second;
    for (size_t r491 = 0; r491 < 1; r491++) {
      for (size_t k490 = 0; k490 < 1; k490++) {
        val487[r491 * 1 + k490] = val182[k490] + 0;
      }
    }
    for (size_t r491 = 0; r491 < 2; r491++) {
      for (size_t k490 = 0; k490 < 1; k490++) {
        val487[r491 * 1 + k490 + 1 * 1] = val235[k490] + CONT_SZ;
      }
    }
    for (size_t r491 = 0; r491 < 1; r491++) {
      for (size_t k490 = 0; k490 < 1; k490++) {
        val487[r491 * 1 + k490 + 1 * 1 + 1 * 2] = val182[1 + k490] + 0;
      }
    }
    for (size_t r491 = 0; r491 < 2; r491++) {
      for (size_t k490 = 0; k490 < 0; k490++) {
        val487[r491 * 0 + k490 + 1 * 1 + 1 * 2 + 1 * 1] = val235[1 + k490] + 0;
      }
    }
    r.map_cont3_cat_degree4[val487] = cnt436 + cnt492;
    r.rev_cont3_cat_degree4[cnt436 + cnt492] = val487;
    cnt492++;
  }
}
;
;

cnt436 += (CONT_SZ * CAT_SZ) * (CONT_SZ2);
;
;
std::array<size_t, 3 + 1> val493;
;
;
;

size_t cnt498 = 0;
for (size_t i494 = 0; i494 < CONT_SZ; i494++) {
  val242 = rev_cont_sum2.find(i494)->second;
  for (size_t j495 = 0; j495 < CONT_SZ2 * CAT_SZ2; j495++) {
    val189 = other.rev_cont_cat_degree2.find(j495)->second;
    for (size_t r497 = 0; r497 < 2; r497++) {
      for (size_t k496 = 0; k496 < 1; k496++) {
        val493[r497 * 1 + k496] = val242[k496] + 0;
      }
    }
    for (size_t r497 = 0; r497 < 1; r497++) {
      for (size_t k496 = 0; k496 < 1; k496++) {
        val493[r497 * 1 + k496 + 1 * 2] = val189[k496] + CONT_SZ;
      }
    }
    for (size_t r497 = 0; r497 < 2; r497++) {
      for (size_t k496 = 0; k496 < 0; k496++) {
        val493[r497 * 0 + k496 + 1 * 2 + 1 * 1] = val242[1 + k496] + 0;
      }
    }
    for (size_t r497 = 0; r497 < 1; r497++) {
      for (size_t k496 = 0; k496 < 1; k496++) {
        val493[r497 * 1 + k496 + 1 * 2 + 1 * 1 + 0 * 2] = val189[1 + k496] + CAT_SZ;
      }
    }
    r.map_cont3_cat_degree4[val493] = cnt436 + cnt498;
    r.rev_cont3_cat_degree4[cnt436 + cnt498] = val493;
    cnt498++;
  }
}
;
;

cnt436 += (CONT_SZ) * (CONT_SZ2 * CAT_SZ2);
;
;
;
size_t cnt499 = 0;
;
std::array<size_t, 2 + 2> val500;
;
std::array<size_t, 2 + 2> val501;
;
;

size_t cnt506 = 0;
for (size_t i502 = 0; i502 < CONT_SZ * (CONT_SZ - 1) / 2 * CAT_SZ * (CAT_SZ - 1) / 2 + CONT_SZ * (CONT_SZ - 1) / 2 * CAT_SZ + CONT_SZ * CAT_SZ * (CAT_SZ - 1) / 2; i502++) {
  val501 = rev_cont2_cat2_degree4.find(i502)->second;
  for (size_t j503 = 0; j503 < 1; j503++) {
    val3 = other.rev_count.find(j503)->second;
    for (size_t r505 = 0; r505 < 1; r505++) {
      for (size_t k504 = 0; k504 < 2; k504++) {
        val500[r505 * 2 + k504] = val501[k504] + 0;
      }
    }
    for (size_t r505 = 0; r505 < 1; r505++) {
      for (size_t k504 = 0; k504 < 0; k504++) {
        val500[r505 * 0 + k504 + 2 * 1] = val3[k504] + 0;
      }
    }
    for (size_t r505 = 0; r505 < 1; r505++) {
      for (size_t k504 = 0; k504 < 2; k504++) {
        val500[r505 * 2 + k504 + 2 * 1 + 0 * 1] = val501[2 + k504] + 0;
      }
    }
    for (size_t r505 = 0; r505 < 1; r505++) {
      for (size_t k504 = 0; k504 < 0; k504++) {
        val500[r505 * 0 + k504 + 2 * 1 + 0 * 1 + 2 * 1] = val3[0 + k504] + 0;
      }
    }
    r.map_cont2_cat2_degree4[val500] = cnt499 + cnt506;
    r.rev_cont2_cat2_degree4[cnt499 + cnt506] = val500;
    cnt506++;
  }
}
;
;

cnt499 += (CONT_SZ * (CONT_SZ - 1) / 2 * CAT_SZ * (CAT_SZ - 1) / 2 + CONT_SZ * (CONT_SZ - 1) / 2 * CAT_SZ + CONT_SZ * CAT_SZ * (CAT_SZ - 1) / 2) * (1);
;
;
std::array<size_t, 2 + 2> val507;
;
;
std::array<size_t, 2 + 2> val508;
;

size_t cnt513 = 0;
for (size_t i509 = 0; i509 < 1; i509++) {
  val2 = rev_count.find(i509)->second;
  for (size_t j510 = 0; j510 < CONT_SZ2 * (CONT_SZ2 - 1) / 2 * CAT_SZ2 * (CAT_SZ2 - 1) / 2 + CONT_SZ2 * (CONT_SZ2 - 1) / 2 * CAT_SZ2 + CONT_SZ2 * CAT_SZ2 * (CAT_SZ2 - 1) / 2; j510++) {
    val508 = other.rev_cont2_cat2_degree4.find(j510)->second;
    for (size_t r512 = 0; r512 < 1; r512++) {
      for (size_t k511 = 0; k511 < 0; k511++) {
        val507[r512 * 0 + k511] = val2[k511] + 0;
      }
    }
    for (size_t r512 = 0; r512 < 1; r512++) {
      for (size_t k511 = 0; k511 < 2; k511++) {
        val507[r512 * 2 + k511 + 0 * 1] = val508[k511] + CONT_SZ;
      }
    }
    for (size_t r512 = 0; r512 < 1; r512++) {
      for (size_t k511 = 0; k511 < 0; k511++) {
        val507[r512 * 0 + k511 + 0 * 1 + 2 * 1] = val2[0 + k511] + 0;
      }
    }
    for (size_t r512 = 0; r512 < 1; r512++) {
      for (size_t k511 = 0; k511 < 2; k511++) {
        val507[r512 * 2 + k511 + 0 * 1 + 2 * 1 + 0 * 1] = val508[2 + k511] + CAT_SZ;
      }
    }
    r.map_cont2_cat2_degree4[val507] = cnt499 + cnt513;
    r.rev_cont2_cat2_degree4[cnt499 + cnt513] = val507;
    cnt513++;
  }
}
;
;

cnt499 += (1) * (CONT_SZ2 * (CONT_SZ2 - 1) / 2 * CAT_SZ2 * (CAT_SZ2 - 1) / 2 + CONT_SZ2 * (CONT_SZ2 - 1) / 2 * CAT_SZ2 + CONT_SZ2 * CAT_SZ2 * (CAT_SZ2 - 1) / 2);
;
;
std::array<size_t, 2 + 2> val514;
;
;
;

size_t cnt519 = 0;
for (size_t i515 = 0; i515 < CONT_SZ * (CONT_SZ + 1) / 2 * CAT_SZ; i515++) {
  val250 = rev_cont2_cat_degree3.find(i515)->second;
  for (size_t j516 = 0; j516 < CAT_SZ2; j516++) {
    val90 = other.rev_cat_sum1.find(j516)->second;
    for (size_t r518 = 0; r518 < 1; r518++) {
      for (size_t k517 = 0; k517 < 2; k517++) {
        val514[r518 * 2 + k517] = val250[k517] + 0;
      }
    }
    for (size_t r518 = 0; r518 < 1; r518++) {
      for (size_t k517 = 0; k517 < 0; k517++) {
        val514[r518 * 0 + k517 + 2 * 1] = val90[k517] + CONT_SZ;
      }
    }
    for (size_t r518 = 0; r518 < 1; r518++) {
      for (size_t k517 = 0; k517 < 1; k517++) {
        val514[r518 * 1 + k517 + 2 * 1 + 0 * 1] = val250[2 + k517] + 0;
      }
    }
    for (size_t r518 = 0; r518 < 1; r518++) {
      for (size_t k517 = 0; k517 < 1; k517++) {
        val514[r518 * 1 + k517 + 2 * 1 + 0 * 1 + 1 * 1] = val90[0 + k517] + CAT_SZ;
      }
    }
    r.map_cont2_cat2_degree4[val514] = cnt499 + cnt519;
    r.rev_cont2_cat2_degree4[cnt499 + cnt519] = val514;
    cnt519++;
  }
}
;
;

cnt499 += (CONT_SZ * (CONT_SZ + 1) / 2 * CAT_SZ) * (CAT_SZ2);
;
;
std::array<size_t, 2 + 2> val520;
;
;
;

size_t cnt525 = 0;
for (size_t i521 = 0; i521 < CAT_SZ; i521++) {
  val83 = rev_cat_sum1.find(i521)->second;
  for (size_t j522 = 0; j522 < CONT_SZ2 * (CONT_SZ2 + 1) / 2 * CAT_SZ2; j522++) {
    val257 = other.rev_cont2_cat_degree3.find(j522)->second;
    for (size_t r524 = 0; r524 < 1; r524++) {
      for (size_t k523 = 0; k523 < 0; k523++) {
        val520[r524 * 0 + k523] = val83[k523] + 0;
      }
    }
    for (size_t r524 = 0; r524 < 1; r524++) {
      for (size_t k523 = 0; k523 < 2; k523++) {
        val520[r524 * 2 + k523 + 0 * 1] = val257[k523] + CONT_SZ;
      }
    }
    for (size_t r524 = 0; r524 < 1; r524++) {
      for (size_t k523 = 0; k523 < 1; k523++) {
        val520[r524 * 1 + k523 + 0 * 1 + 2 * 1] = val83[0 + k523] + 0;
      }
    }
    for (size_t r524 = 0; r524 < 1; r524++) {
      for (size_t k523 = 0; k523 < 1; k523++) {
        val520[r524 * 1 + k523 + 0 * 1 + 2 * 1 + 1 * 1] = val257[2 + k523] + CAT_SZ;
      }
    }
    r.map_cont2_cat2_degree4[val520] = cnt499 + cnt525;
    r.rev_cont2_cat2_degree4[cnt499 + cnt525] = val520;
    cnt525++;
  }
}
;
;

cnt499 += (CAT_SZ) * (CONT_SZ2 * (CONT_SZ2 + 1) / 2 * CAT_SZ2);
;
;
std::array<size_t, 2 + 2> val526;
;
;
;

size_t cnt531 = 0;
for (size_t i527 = 0; i527 < CONT_SZ * CAT_SZ * (CAT_SZ + 1) / 2; i527++) {
  val301 = rev_cont_cat2_degree3.find(i527)->second;
  for (size_t j528 = 0; j528 < CONT_SZ2; j528++) {
    val18 = other.rev_cont_sum1.find(j528)->second;
    for (size_t r530 = 0; r530 < 1; r530++) {
      for (size_t k529 = 0; k529 < 1; k529++) {
        val526[r530 * 1 + k529] = val301[k529] + 0;
      }
    }
    for (size_t r530 = 0; r530 < 1; r530++) {
      for (size_t k529 = 0; k529 < 1; k529++) {
        val526[r530 * 1 + k529 + 1 * 1] = val18[k529] + CONT_SZ;
      }
    }
    for (size_t r530 = 0; r530 < 1; r530++) {
      for (size_t k529 = 0; k529 < 2; k529++) {
        val526[r530 * 2 + k529 + 1 * 1 + 1 * 1] = val301[1 + k529] + 0;
      }
    }
    for (size_t r530 = 0; r530 < 1; r530++) {
      for (size_t k529 = 0; k529 < 0; k529++) {
        val526[r530 * 0 + k529 + 1 * 1 + 1 * 1 + 2 * 1] = val18[1 + k529] + 0;
      }
    }
    r.map_cont2_cat2_degree4[val526] = cnt499 + cnt531;
    r.rev_cont2_cat2_degree4[cnt499 + cnt531] = val526;
    cnt531++;
  }
}
;
;

cnt499 += (CONT_SZ * CAT_SZ * (CAT_SZ + 1) / 2) * (CONT_SZ2);
;
;
std::array<size_t, 2 + 2> val532;
;
;
;

size_t cnt537 = 0;
for (size_t i533 = 0; i533 < CONT_SZ; i533++) {
  val11 = rev_cont_sum1.find(i533)->second;
  for (size_t j534 = 0; j534 < CONT_SZ2 * CAT_SZ2 * (CAT_SZ2 + 1) / 2; j534++) {
    val308 = other.rev_cont_cat2_degree3.find(j534)->second;
    for (size_t r536 = 0; r536 < 1; r536++) {
      for (size_t k535 = 0; k535 < 1; k535++) {
        val532[r536 * 1 + k535] = val11[k535] + 0;
      }
    }
    for (size_t r536 = 0; r536 < 1; r536++) {
      for (size_t k535 = 0; k535 < 1; k535++) {
        val532[r536 * 1 + k535 + 1 * 1] = val308[k535] + CONT_SZ;
      }
    }
    for (size_t r536 = 0; r536 < 1; r536++) {
      for (size_t k535 = 0; k535 < 0; k535++) {
        val532[r536 * 0 + k535 + 1 * 1 + 1 * 1] = val11[1 + k535] + 0;
      }
    }
    for (size_t r536 = 0; r536 < 1; r536++) {
      for (size_t k535 = 0; k535 < 2; k535++) {
        val532[r536 * 2 + k535 + 1 * 1 + 1 * 1 + 0 * 1] = val308[1 + k535] + CAT_SZ;
      }
    }
    r.map_cont2_cat2_degree4[val532] = cnt499 + cnt537;
    r.rev_cont2_cat2_degree4[cnt499 + cnt537] = val532;
    cnt537++;
  }
}
;
;

cnt499 += (CONT_SZ) * (CONT_SZ2 * CAT_SZ2 * (CAT_SZ2 + 1) / 2);
;
;
std::array<size_t, 2 + 2> val538;
;
;
;

size_t cnt543 = 0;
for (size_t i539 = 0; i539 < CONT_SZ * (CONT_SZ - 1) / 2; i539++) {
  val62 = rev_cont_degree2.find(i539)->second;
  for (size_t j540 = 0; j540 < CAT_SZ2 * (CAT_SZ2 - 1) / 2; j540++) {
    val141 = other.rev_cat_degree2.find(j540)->second;
    for (size_t r542 = 0; r542 < 1; r542++) {
      for (size_t k541 = 0; k541 < 2; k541++) {
        val538[r542 * 2 + k541] = val62[k541] + 0;
      }
    }
    for (size_t r542 = 0; r542 < 1; r542++) {
      for (size_t k541 = 0; k541 < 0; k541++) {
        val538[r542 * 0 + k541 + 2 * 1] = val141[k541] + CONT_SZ;
      }
    }
    for (size_t r542 = 0; r542 < 1; r542++) {
      for (size_t k541 = 0; k541 < 0; k541++) {
        val538[r542 * 0 + k541 + 2 * 1 + 0 * 1] = val62[2 + k541] + 0;
      }
    }
    for (size_t r542 = 0; r542 < 1; r542++) {
      for (size_t k541 = 0; k541 < 2; k541++) {
        val538[r542 * 2 + k541 + 2 * 1 + 0 * 1 + 0 * 1] = val141[0 + k541] + CAT_SZ;
      }
    }
    r.map_cont2_cat2_degree4[val538] = cnt499 + cnt543;
    r.rev_cont2_cat2_degree4[cnt499 + cnt543] = val538;
    cnt543++;
  }
}
;
;

cnt499 += (CONT_SZ * (CONT_SZ - 1) / 2) * (CAT_SZ2 * (CAT_SZ2 - 1) / 2);
;
;
std::array<size_t, 2 + 2> val544;
;
;
;

size_t cnt549 = 0;
for (size_t i545 = 0; i545 < CAT_SZ * (CAT_SZ - 1) / 2; i545++) {
  val134 = rev_cat_degree2.find(i545)->second;
  for (size_t j546 = 0; j546 < CONT_SZ2 * (CONT_SZ2 - 1) / 2; j546++) {
    val69 = other.rev_cont_degree2.find(j546)->second;
    for (size_t r548 = 0; r548 < 1; r548++) {
      for (size_t k547 = 0; k547 < 0; k547++) {
        val544[r548 * 0 + k547] = val134[k547] + 0;
      }
    }
    for (size_t r548 = 0; r548 < 1; r548++) {
      for (size_t k547 = 0; k547 < 2; k547++) {
        val544[r548 * 2 + k547 + 0 * 1] = val69[k547] + CONT_SZ;
      }
    }
    for (size_t r548 = 0; r548 < 1; r548++) {
      for (size_t k547 = 0; k547 < 2; k547++) {
        val544[r548 * 2 + k547 + 0 * 1 + 2 * 1] = val134[0 + k547] + 0;
      }
    }
    for (size_t r548 = 0; r548 < 1; r548++) {
      for (size_t k547 = 0; k547 < 0; k547++) {
        val544[r548 * 0 + k547 + 0 * 1 + 2 * 1 + 2 * 1] = val69[2 + k547] + 0;
      }
    }
    r.map_cont2_cat2_degree4[val544] = cnt499 + cnt549;
    r.rev_cont2_cat2_degree4[cnt499 + cnt549] = val544;
    cnt549++;
  }
}
;
;

cnt499 += (CAT_SZ * (CAT_SZ - 1) / 2) * (CONT_SZ2 * (CONT_SZ2 - 1) / 2);
;
;
std::array<size_t, 2 + 2> val550;
;
;
;

size_t cnt555 = 0;
for (size_t i551 = 0; i551 < CONT_SZ; i551++) {
  val242 = rev_cont_sum2.find(i551)->second;
  for (size_t j552 = 0; j552 < CAT_SZ2 * (CAT_SZ2 - 1) / 2; j552++) {
    val141 = other.rev_cat_degree2.find(j552)->second;
    for (size_t r554 = 0; r554 < 2; r554++) {
      for (size_t k553 = 0; k553 < 1; k553++) {
        val550[r554 * 1 + k553] = val242[k553] + 0;
      }
    }
    for (size_t r554 = 0; r554 < 1; r554++) {
      for (size_t k553 = 0; k553 < 0; k553++) {
        val550[r554 * 0 + k553 + 1 * 2] = val141[k553] + CONT_SZ;
      }
    }
    for (size_t r554 = 0; r554 < 2; r554++) {
      for (size_t k553 = 0; k553 < 0; k553++) {
        val550[r554 * 0 + k553 + 1 * 2 + 0 * 1] = val242[1 + k553] + 0;
      }
    }
    for (size_t r554 = 0; r554 < 1; r554++) {
      for (size_t k553 = 0; k553 < 2; k553++) {
        val550[r554 * 2 + k553 + 1 * 2 + 0 * 1 + 0 * 2] = val141[0 + k553] + CAT_SZ;
      }
    }
    r.map_cont2_cat2_degree4[val550] = cnt499 + cnt555;
    r.rev_cont2_cat2_degree4[cnt499 + cnt555] = val550;
    cnt555++;
  }
}
;
;

cnt499 += (CONT_SZ) * (CAT_SZ2 * (CAT_SZ2 - 1) / 2);
;
;
std::array<size_t, 2 + 2> val556;
;
;
;

size_t cnt561 = 0;
for (size_t i557 = 0; i557 < CAT_SZ * (CAT_SZ - 1) / 2; i557++) {
  val134 = rev_cat_degree2.find(i557)->second;
  for (size_t j558 = 0; j558 < CONT_SZ2; j558++) {
    val235 = other.rev_cont_sum2.find(j558)->second;
    for (size_t r560 = 0; r560 < 1; r560++) {
      for (size_t k559 = 0; k559 < 0; k559++) {
        val556[r560 * 0 + k559] = val134[k559] + 0;
      }
    }
    for (size_t r560 = 0; r560 < 2; r560++) {
      for (size_t k559 = 0; k559 < 1; k559++) {
        val556[r560 * 1 + k559 + 0 * 1] = val235[k559] + CONT_SZ;
      }
    }
    for (size_t r560 = 0; r560 < 1; r560++) {
      for (size_t k559 = 0; k559 < 2; k559++) {
        val556[r560 * 2 + k559 + 0 * 1 + 1 * 2] = val134[0 + k559] + 0;
      }
    }
    for (size_t r560 = 0; r560 < 2; r560++) {
      for (size_t k559 = 0; k559 < 0; k559++) {
        val556[r560 * 0 + k559 + 0 * 1 + 1 * 2 + 2 * 1] = val235[1 + k559] + 0;
      }
    }
    r.map_cont2_cat2_degree4[val556] = cnt499 + cnt561;
    r.rev_cont2_cat2_degree4[cnt499 + cnt561] = val556;
    cnt561++;
  }
}
;
;

cnt499 += (CAT_SZ * (CAT_SZ - 1) / 2) * (CONT_SZ2);
;
;
std::array<size_t, 2 + 2> val562;
;
;
;

size_t cnt567 = 0;
for (size_t i563 = 0; i563 < CONT_SZ * (CONT_SZ - 1) / 2; i563++) {
  val62 = rev_cont_degree2.find(i563)->second;
  for (size_t j564 = 0; j564 < CAT_SZ2; j564++) {
    val322 = other.rev_cat_sum2.find(j564)->second;
    for (size_t r566 = 0; r566 < 1; r566++) {
      for (size_t k565 = 0; k565 < 2; k565++) {
        val562[r566 * 2 + k565] = val62[k565] + 0;
      }
    }
    for (size_t r566 = 0; r566 < 2; r566++) {
      for (size_t k565 = 0; k565 < 0; k565++) {
        val562[r566 * 0 + k565 + 2 * 1] = val322[k565] + CONT_SZ;
      }
    }
    for (size_t r566 = 0; r566 < 1; r566++) {
      for (size_t k565 = 0; k565 < 0; k565++) {
        val562[r566 * 0 + k565 + 2 * 1 + 0 * 2] = val62[2 + k565] + 0;
      }
    }
    for (size_t r566 = 0; r566 < 2; r566++) {
      for (size_t k565 = 0; k565 < 1; k565++) {
        val562[r566 * 1 + k565 + 2 * 1 + 0 * 2 + 0 * 1] = val322[0 + k565] + CAT_SZ;
      }
    }
    r.map_cont2_cat2_degree4[val562] = cnt499 + cnt567;
    r.rev_cont2_cat2_degree4[cnt499 + cnt567] = val562;
    cnt567++;
  }
}
;
;

cnt499 += (CONT_SZ * (CONT_SZ - 1) / 2) * (CAT_SZ2);
;
;
std::array<size_t, 2 + 2> val568;
;
;
;

size_t cnt573 = 0;
for (size_t i569 = 0; i569 < CAT_SZ; i569++) {
  val315 = rev_cat_sum2.find(i569)->second;
  for (size_t j570 = 0; j570 < CONT_SZ2 * (CONT_SZ2 - 1) / 2; j570++) {
    val69 = other.rev_cont_degree2.find(j570)->second;
    for (size_t r572 = 0; r572 < 2; r572++) {
      for (size_t k571 = 0; k571 < 0; k571++) {
        val568[r572 * 0 + k571] = val315[k571] + 0;
      }
    }
    for (size_t r572 = 0; r572 < 1; r572++) {
      for (size_t k571 = 0; k571 < 2; k571++) {
        val568[r572 * 2 + k571 + 0 * 2] = val69[k571] + CONT_SZ;
      }
    }
    for (size_t r572 = 0; r572 < 2; r572++) {
      for (size_t k571 = 0; k571 < 1; k571++) {
        val568[r572 * 1 + k571 + 0 * 2 + 2 * 1] = val315[0 + k571] + 0;
      }
    }
    for (size_t r572 = 0; r572 < 1; r572++) {
      for (size_t k571 = 0; k571 < 0; k571++) {
        val568[r572 * 0 + k571 + 0 * 2 + 2 * 1 + 1 * 2] = val69[2 + k571] + 0;
      }
    }
    r.map_cont2_cat2_degree4[val568] = cnt499 + cnt573;
    r.rev_cont2_cat2_degree4[cnt499 + cnt573] = val568;
    cnt573++;
  }
}
;
;

cnt499 += (CAT_SZ) * (CONT_SZ2 * (CONT_SZ2 - 1) / 2);
;
;
std::array<size_t, 2 + 2> val574;
;
;
;

size_t cnt579 = 0;
for (size_t i575 = 0; i575 < CONT_SZ * CAT_SZ; i575++) {
  val182 = rev_cont_cat_degree2.find(i575)->second;
  for (size_t j576 = 0; j576 < CONT_SZ2 * CAT_SZ2; j576++) {
    val189 = other.rev_cont_cat_degree2.find(j576)->second;
    for (size_t r578 = 0; r578 < 1; r578++) {
      for (size_t k577 = 0; k577 < 1; k577++) {
        val574[r578 * 1 + k577] = val182[k577] + 0;
      }
    }
    for (size_t r578 = 0; r578 < 1; r578++) {
      for (size_t k577 = 0; k577 < 1; k577++) {
        val574[r578 * 1 + k577 + 1 * 1] = val189[k577] + CONT_SZ;
      }
    }
    for (size_t r578 = 0; r578 < 1; r578++) {
      for (size_t k577 = 0; k577 < 1; k577++) {
        val574[r578 * 1 + k577 + 1 * 1 + 1 * 1] = val182[1 + k577] + 0;
      }
    }
    for (size_t r578 = 0; r578 < 1; r578++) {
      for (size_t k577 = 0; k577 < 1; k577++) {
        val574[r578 * 1 + k577 + 1 * 1 + 1 * 1 + 1 * 1] = val189[1 + k577] + CAT_SZ;
      }
    }
    r.map_cont2_cat2_degree4[val574] = cnt499 + cnt579;
    r.rev_cont2_cat2_degree4[cnt499 + cnt579] = val574;
    cnt579++;
  }
}
;
;

cnt499 += (CONT_SZ * CAT_SZ) * (CONT_SZ2 * CAT_SZ2);
;
;
;
size_t cnt580 = 0;
;
std::array<size_t, 1 + 3> val581;
;
std::array<size_t, 1 + 3> val582;
;
;

size_t cnt587 = 0;
for (size_t i583 = 0; i583 < (CAT_SZ * (CAT_SZ - 1) * (CAT_SZ - 2) / 6 + CAT_SZ * (CAT_SZ - 1)) * CONT_SZ; i583++) {
  val582 = rev_cont_cat3_degree4.find(i583)->second;
  for (size_t j584 = 0; j584 < 1; j584++) {
    val3 = other.rev_count.find(j584)->second;
    for (size_t r586 = 0; r586 < 1; r586++) {
      for (size_t k585 = 0; k585 < 1; k585++) {
        val581[r586 * 1 + k585] = val582[k585] + 0;
      }
    }
    for (size_t r586 = 0; r586 < 1; r586++) {
      for (size_t k585 = 0; k585 < 0; k585++) {
        val581[r586 * 0 + k585 + 1 * 1] = val3[k585] + 0;
      }
    }
    for (size_t r586 = 0; r586 < 1; r586++) {
      for (size_t k585 = 0; k585 < 3; k585++) {
        val581[r586 * 3 + k585 + 1 * 1 + 0 * 1] = val582[1 + k585] + 0;
      }
    }
    for (size_t r586 = 0; r586 < 1; r586++) {
      for (size_t k585 = 0; k585 < 0; k585++) {
        val581[r586 * 0 + k585 + 1 * 1 + 0 * 1 + 3 * 1] = val3[0 + k585] + 0;
      }
    }
    r.map_cont_cat3_degree4[val581] = cnt580 + cnt587;
    r.rev_cont_cat3_degree4[cnt580 + cnt587] = val581;
    cnt587++;
  }
}
;
;

cnt580 += ((CAT_SZ * (CAT_SZ - 1) * (CAT_SZ - 2) / 6 + CAT_SZ * (CAT_SZ - 1)) * CONT_SZ) * (1);
;
;
std::array<size_t, 1 + 3> val588;
;
;
std::array<size_t, 1 + 3> val589;
;

size_t cnt594 = 0;
for (size_t i590 = 0; i590 < 1; i590++) {
  val2 = rev_count.find(i590)->second;
  for (size_t j591 = 0; j591 < (CAT_SZ2 * (CAT_SZ2 - 1) * (CAT_SZ2 - 2) / 6 + CAT_SZ2 * (CAT_SZ2 - 1)) * CONT_SZ2; j591++) {
    val589 = other.rev_cont_cat3_degree4.find(j591)->second;
    for (size_t r593 = 0; r593 < 1; r593++) {
      for (size_t k592 = 0; k592 < 0; k592++) {
        val588[r593 * 0 + k592] = val2[k592] + 0;
      }
    }
    for (size_t r593 = 0; r593 < 1; r593++) {
      for (size_t k592 = 0; k592 < 1; k592++) {
        val588[r593 * 1 + k592 + 0 * 1] = val589[k592] + CONT_SZ;
      }
    }
    for (size_t r593 = 0; r593 < 1; r593++) {
      for (size_t k592 = 0; k592 < 0; k592++) {
        val588[r593 * 0 + k592 + 0 * 1 + 1 * 1] = val2[0 + k592] + 0;
      }
    }
    for (size_t r593 = 0; r593 < 1; r593++) {
      for (size_t k592 = 0; k592 < 3; k592++) {
        val588[r593 * 3 + k592 + 0 * 1 + 1 * 1 + 0 * 1] = val589[1 + k592] + CAT_SZ;
      }
    }
    r.map_cont_cat3_degree4[val588] = cnt580 + cnt594;
    r.rev_cont_cat3_degree4[cnt580 + cnt594] = val588;
    cnt594++;
  }
}
;
;

cnt580 += (1) * ((CAT_SZ2 * (CAT_SZ2 - 1) * (CAT_SZ2 - 2) / 6 + CAT_SZ2 * (CAT_SZ2 - 1)) * CONT_SZ2);
;
;
std::array<size_t, 1 + 3> val595;
;
;
;

size_t cnt600 = 0;
for (size_t i596 = 0; i596 < CAT_SZ * (CAT_SZ - 1) * (CAT_SZ - 2) / 6 + CAT_SZ * (CAT_SZ - 1); i596++) {
  val354 = rev_cat_degree3.find(i596)->second;
  for (size_t j597 = 0; j597 < CONT_SZ2; j597++) {
    val18 = other.rev_cont_sum1.find(j597)->second;
    for (size_t r599 = 0; r599 < 1; r599++) {
      for (size_t k598 = 0; k598 < 0; k598++) {
        val595[r599 * 0 + k598] = val354[k598] + 0;
      }
    }
    for (size_t r599 = 0; r599 < 1; r599++) {
      for (size_t k598 = 0; k598 < 1; k598++) {
        val595[r599 * 1 + k598 + 0 * 1] = val18[k598] + CONT_SZ;
      }
    }
    for (size_t r599 = 0; r599 < 1; r599++) {
      for (size_t k598 = 0; k598 < 3; k598++) {
        val595[r599 * 3 + k598 + 0 * 1 + 1 * 1] = val354[0 + k598] + 0;
      }
    }
    for (size_t r599 = 0; r599 < 1; r599++) {
      for (size_t k598 = 0; k598 < 0; k598++) {
        val595[r599 * 0 + k598 + 0 * 1 + 1 * 1 + 3 * 1] = val18[1 + k598] + 0;
      }
    }
    r.map_cont_cat3_degree4[val595] = cnt580 + cnt600;
    r.rev_cont_cat3_degree4[cnt580 + cnt600] = val595;
    cnt600++;
  }
}
;
;

cnt580 += (CAT_SZ * (CAT_SZ - 1) * (CAT_SZ - 2) / 6 + CAT_SZ * (CAT_SZ - 1)) * (CONT_SZ2);
;
;
std::array<size_t, 1 + 3> val601;
;
;
;

size_t cnt606 = 0;
for (size_t i602 = 0; i602 < CONT_SZ; i602++) {
  val11 = rev_cont_sum1.find(i602)->second;
  for (size_t j603 = 0; j603 < CAT_SZ2 * (CAT_SZ2 - 1) * (CAT_SZ2 - 2) / 6 + CAT_SZ2 * (CAT_SZ2 - 1); j603++) {
    val361 = other.rev_cat_degree3.find(j603)->second;
    for (size_t r605 = 0; r605 < 1; r605++) {
      for (size_t k604 = 0; k604 < 1; k604++) {
        val601[r605 * 1 + k604] = val11[k604] + 0;
      }
    }
    for (size_t r605 = 0; r605 < 1; r605++) {
      for (size_t k604 = 0; k604 < 0; k604++) {
        val601[r605 * 0 + k604 + 1 * 1] = val361[k604] + CONT_SZ;
      }
    }
    for (size_t r605 = 0; r605 < 1; r605++) {
      for (size_t k604 = 0; k604 < 0; k604++) {
        val601[r605 * 0 + k604 + 1 * 1 + 0 * 1] = val11[1 + k604] + 0;
      }
    }
    for (size_t r605 = 0; r605 < 1; r605++) {
      for (size_t k604 = 0; k604 < 3; k604++) {
        val601[r605 * 3 + k604 + 1 * 1 + 0 * 1 + 0 * 1] = val361[0 + k604] + CAT_SZ;
      }
    }
    r.map_cont_cat3_degree4[val601] = cnt580 + cnt606;
    r.rev_cont_cat3_degree4[cnt580 + cnt606] = val601;
    cnt606++;
  }
}
;
;

cnt580 += (CONT_SZ) * (CAT_SZ2 * (CAT_SZ2 - 1) * (CAT_SZ2 - 2) / 6 + CAT_SZ2 * (CAT_SZ2 - 1));
;
;
std::array<size_t, 1 + 3> val607;
;
;
;

size_t cnt612 = 0;
for (size_t i608 = 0; i608 < CONT_SZ * CAT_SZ * (CAT_SZ + 1) / 2; i608++) {
  val301 = rev_cont_cat2_degree3.find(i608)->second;
  for (size_t j609 = 0; j609 < CAT_SZ2; j609++) {
    val90 = other.rev_cat_sum1.find(j609)->second;
    for (size_t r611 = 0; r611 < 1; r611++) {
      for (size_t k610 = 0; k610 < 1; k610++) {
        val607[r611 * 1 + k610] = val301[k610] + 0;
      }
    }
    for (size_t r611 = 0; r611 < 1; r611++) {
      for (size_t k610 = 0; k610 < 0; k610++) {
        val607[r611 * 0 + k610 + 1 * 1] = val90[k610] + CONT_SZ;
      }
    }
    for (size_t r611 = 0; r611 < 1; r611++) {
      for (size_t k610 = 0; k610 < 2; k610++) {
        val607[r611 * 2 + k610 + 1 * 1 + 0 * 1] = val301[1 + k610] + 0;
      }
    }
    for (size_t r611 = 0; r611 < 1; r611++) {
      for (size_t k610 = 0; k610 < 1; k610++) {
        val607[r611 * 1 + k610 + 1 * 1 + 0 * 1 + 2 * 1] = val90[0 + k610] + CAT_SZ;
      }
    }
    r.map_cont_cat3_degree4[val607] = cnt580 + cnt612;
    r.rev_cont_cat3_degree4[cnt580 + cnt612] = val607;
    cnt612++;
  }
}
;
;

cnt580 += (CONT_SZ * CAT_SZ * (CAT_SZ + 1) / 2) * (CAT_SZ2);
;
;
std::array<size_t, 1 + 3> val613;
;
;
;

size_t cnt618 = 0;
for (size_t i614 = 0; i614 < CAT_SZ; i614++) {
  val83 = rev_cat_sum1.find(i614)->second;
  for (size_t j615 = 0; j615 < CONT_SZ2 * CAT_SZ2 * (CAT_SZ2 + 1) / 2; j615++) {
    val308 = other.rev_cont_cat2_degree3.find(j615)->second;
    for (size_t r617 = 0; r617 < 1; r617++) {
      for (size_t k616 = 0; k616 < 0; k616++) {
        val613[r617 * 0 + k616] = val83[k616] + 0;
      }
    }
    for (size_t r617 = 0; r617 < 1; r617++) {
      for (size_t k616 = 0; k616 < 1; k616++) {
        val613[r617 * 1 + k616 + 0 * 1] = val308[k616] + CONT_SZ;
      }
    }
    for (size_t r617 = 0; r617 < 1; r617++) {
      for (size_t k616 = 0; k616 < 1; k616++) {
        val613[r617 * 1 + k616 + 0 * 1 + 1 * 1] = val83[0 + k616] + 0;
      }
    }
    for (size_t r617 = 0; r617 < 1; r617++) {
      for (size_t k616 = 0; k616 < 2; k616++) {
        val613[r617 * 2 + k616 + 0 * 1 + 1 * 1 + 1 * 1] = val308[1 + k616] + CAT_SZ;
      }
    }
    r.map_cont_cat3_degree4[val613] = cnt580 + cnt618;
    r.rev_cont_cat3_degree4[cnt580 + cnt618] = val613;
    cnt618++;
  }
}
;
;

cnt580 += (CAT_SZ) * (CONT_SZ2 * CAT_SZ2 * (CAT_SZ2 + 1) / 2);
;
;
std::array<size_t, 1 + 3> val619;
;
;
;

size_t cnt624 = 0;
for (size_t i620 = 0; i620 < CONT_SZ * CAT_SZ; i620++) {
  val182 = rev_cont_cat_degree2.find(i620)->second;
  for (size_t j621 = 0; j621 < CAT_SZ2 * (CAT_SZ2 - 1) / 2; j621++) {
    val141 = other.rev_cat_degree2.find(j621)->second;
    for (size_t r623 = 0; r623 < 1; r623++) {
      for (size_t k622 = 0; k622 < 1; k622++) {
        val619[r623 * 1 + k622] = val182[k622] + 0;
      }
    }
    for (size_t r623 = 0; r623 < 1; r623++) {
      for (size_t k622 = 0; k622 < 0; k622++) {
        val619[r623 * 0 + k622 + 1 * 1] = val141[k622] + CONT_SZ;
      }
    }
    for (size_t r623 = 0; r623 < 1; r623++) {
      for (size_t k622 = 0; k622 < 1; k622++) {
        val619[r623 * 1 + k622 + 1 * 1 + 0 * 1] = val182[1 + k622] + 0;
      }
    }
    for (size_t r623 = 0; r623 < 1; r623++) {
      for (size_t k622 = 0; k622 < 2; k622++) {
        val619[r623 * 2 + k622 + 1 * 1 + 0 * 1 + 1 * 1] = val141[0 + k622] + CAT_SZ;
      }
    }
    r.map_cont_cat3_degree4[val619] = cnt580 + cnt624;
    r.rev_cont_cat3_degree4[cnt580 + cnt624] = val619;
    cnt624++;
  }
}
;
;

cnt580 += (CONT_SZ * CAT_SZ) * (CAT_SZ2 * (CAT_SZ2 - 1) / 2);
;
;
std::array<size_t, 1 + 3> val625;
;
;
;

size_t cnt630 = 0;
for (size_t i626 = 0; i626 < CAT_SZ * (CAT_SZ - 1) / 2; i626++) {
  val134 = rev_cat_degree2.find(i626)->second;
  for (size_t j627 = 0; j627 < CONT_SZ2 * CAT_SZ2; j627++) {
    val189 = other.rev_cont_cat_degree2.find(j627)->second;
    for (size_t r629 = 0; r629 < 1; r629++) {
      for (size_t k628 = 0; k628 < 0; k628++) {
        val625[r629 * 0 + k628] = val134[k628] + 0;
      }
    }
    for (size_t r629 = 0; r629 < 1; r629++) {
      for (size_t k628 = 0; k628 < 1; k628++) {
        val625[r629 * 1 + k628 + 0 * 1] = val189[k628] + CONT_SZ;
      }
    }
    for (size_t r629 = 0; r629 < 1; r629++) {
      for (size_t k628 = 0; k628 < 2; k628++) {
        val625[r629 * 2 + k628 + 0 * 1 + 1 * 1] = val134[0 + k628] + 0;
      }
    }
    for (size_t r629 = 0; r629 < 1; r629++) {
      for (size_t k628 = 0; k628 < 1; k628++) {
        val625[r629 * 1 + k628 + 0 * 1 + 1 * 1 + 2 * 1] = val189[1 + k628] + CAT_SZ;
      }
    }
    r.map_cont_cat3_degree4[val625] = cnt580 + cnt630;
    r.rev_cont_cat3_degree4[cnt580 + cnt630] = val625;
    cnt630++;
  }
}
;
;

cnt580 += (CAT_SZ * (CAT_SZ - 1) / 2) * (CONT_SZ2 * CAT_SZ2);
;
;
std::array<size_t, 1 + 3> val631;
;
;
;

size_t cnt636 = 0;
for (size_t i632 = 0; i632 < CONT_SZ * CAT_SZ; i632++) {
  val182 = rev_cont_cat_degree2.find(i632)->second;
  for (size_t j633 = 0; j633 < CAT_SZ2; j633++) {
    val322 = other.rev_cat_sum2.find(j633)->second;
    for (size_t r635 = 0; r635 < 1; r635++) {
      for (size_t k634 = 0; k634 < 1; k634++) {
        val631[r635 * 1 + k634] = val182[k634] + 0;
      }
    }
    for (size_t r635 = 0; r635 < 2; r635++) {
      for (size_t k634 = 0; k634 < 0; k634++) {
        val631[r635 * 0 + k634 + 1 * 1] = val322[k634] + CONT_SZ;
      }
    }
    for (size_t r635 = 0; r635 < 1; r635++) {
      for (size_t k634 = 0; k634 < 1; k634++) {
        val631[r635 * 1 + k634 + 1 * 1 + 0 * 2] = val182[1 + k634] + 0;
      }
    }
    for (size_t r635 = 0; r635 < 2; r635++) {
      for (size_t k634 = 0; k634 < 1; k634++) {
        val631[r635 * 1 + k634 + 1 * 1 + 0 * 2 + 1 * 1] = val322[0 + k634] + CAT_SZ;
      }
    }
    r.map_cont_cat3_degree4[val631] = cnt580 + cnt636;
    r.rev_cont_cat3_degree4[cnt580 + cnt636] = val631;
    cnt636++;
  }
}
;
;

cnt580 += (CONT_SZ * CAT_SZ) * (CAT_SZ2);
;
;
std::array<size_t, 1 + 3> val637;
;
;
;

size_t cnt642 = 0;
for (size_t i638 = 0; i638 < CAT_SZ; i638++) {
  val315 = rev_cat_sum2.find(i638)->second;
  for (size_t j639 = 0; j639 < CONT_SZ2 * CAT_SZ2; j639++) {
    val189 = other.rev_cont_cat_degree2.find(j639)->second;
    for (size_t r641 = 0; r641 < 2; r641++) {
      for (size_t k640 = 0; k640 < 0; k640++) {
        val637[r641 * 0 + k640] = val315[k640] + 0;
      }
    }
    for (size_t r641 = 0; r641 < 1; r641++) {
      for (size_t k640 = 0; k640 < 1; k640++) {
        val637[r641 * 1 + k640 + 0 * 2] = val189[k640] + CONT_SZ;
      }
    }
    for (size_t r641 = 0; r641 < 2; r641++) {
      for (size_t k640 = 0; k640 < 1; k640++) {
        val637[r641 * 1 + k640 + 0 * 2 + 1 * 1] = val315[0 + k640] + 0;
      }
    }
    for (size_t r641 = 0; r641 < 1; r641++) {
      for (size_t k640 = 0; k640 < 1; k640++) {
        val637[r641 * 1 + k640 + 0 * 2 + 1 * 1 + 1 * 2] = val189[1 + k640] + CAT_SZ;
      }
    }
    r.map_cont_cat3_degree4[val637] = cnt580 + cnt642;
    r.rev_cont_cat3_degree4[cnt580 + cnt642] = val637;
    cnt642++;
  }
}
;
;

cnt580 += (CAT_SZ) * (CONT_SZ2 * CAT_SZ2);
;
;
;
size_t cnt643 = 0;
;
std::array<size_t, 0 + 4> val644;
;
std::array<size_t, 0 + 4> val645;
;
;

size_t cnt650 = 0;
for (size_t i646 = 0; i646 < CAT_SZ * (CAT_SZ - 1) * (CAT_SZ - 2) * (CAT_SZ - 3) / 24 + CAT_SZ * (CAT_SZ - 1) * (CAT_SZ - 2) / 2; i646++) {
  val645 = rev_cat_degree4.find(i646)->second;
  for (size_t j647 = 0; j647 < 1; j647++) {
    val3 = other.rev_count.find(j647)->second;
    for (size_t r649 = 0; r649 < 1; r649++) {
      for (size_t k648 = 0; k648 < 0; k648++) {
        val644[r649 * 0 + k648] = val645[k648] + 0;
      }
    }
    for (size_t r649 = 0; r649 < 1; r649++) {
      for (size_t k648 = 0; k648 < 0; k648++) {
        val644[r649 * 0 + k648 + 0 * 1] = val3[k648] + 0;
      }
    }
    for (size_t r649 = 0; r649 < 1; r649++) {
      for (size_t k648 = 0; k648 < 4; k648++) {
        val644[r649 * 4 + k648 + 0 * 1 + 0 * 1] = val645[0 + k648] + 0;
      }
    }
    for (size_t r649 = 0; r649 < 1; r649++) {
      for (size_t k648 = 0; k648 < 0; k648++) {
        val644[r649 * 0 + k648 + 0 * 1 + 0 * 1 + 4 * 1] = val3[0 + k648] + 0;
      }
    }
    r.map_cat_degree4[val644] = cnt643 + cnt650;
    r.rev_cat_degree4[cnt643 + cnt650] = val644;
    cnt650++;
  }
}
;
;

cnt643 += (CAT_SZ * (CAT_SZ - 1) * (CAT_SZ - 2) * (CAT_SZ - 3) / 24 + CAT_SZ * (CAT_SZ - 1) * (CAT_SZ - 2) / 2) * (1);
;
;
std::array<size_t, 0 + 4> val651;
;
;
std::array<size_t, 0 + 4> val652;
;

size_t cnt657 = 0;
for (size_t i653 = 0; i653 < 1; i653++) {
  val2 = rev_count.find(i653)->second;
  for (size_t j654 = 0; j654 < CAT_SZ2 * (CAT_SZ2 - 1) * (CAT_SZ2 - 2) * (CAT_SZ2 - 3) / 24 + CAT_SZ2 * (CAT_SZ2 - 1) * (CAT_SZ2 - 2) / 2; j654++) {
    val652 = other.rev_cat_degree4.find(j654)->second;
    for (size_t r656 = 0; r656 < 1; r656++) {
      for (size_t k655 = 0; k655 < 0; k655++) {
        val651[r656 * 0 + k655] = val2[k655] + 0;
      }
    }
    for (size_t r656 = 0; r656 < 1; r656++) {
      for (size_t k655 = 0; k655 < 0; k655++) {
        val651[r656 * 0 + k655 + 0 * 1] = val652[k655] + CONT_SZ;
      }
    }
    for (size_t r656 = 0; r656 < 1; r656++) {
      for (size_t k655 = 0; k655 < 0; k655++) {
        val651[r656 * 0 + k655 + 0 * 1 + 0 * 1] = val2[0 + k655] + 0;
      }
    }
    for (size_t r656 = 0; r656 < 1; r656++) {
      for (size_t k655 = 0; k655 < 4; k655++) {
        val651[r656 * 4 + k655 + 0 * 1 + 0 * 1 + 0 * 1] = val652[0 + k655] + CAT_SZ;
      }
    }
    r.map_cat_degree4[val651] = cnt643 + cnt657;
    r.rev_cat_degree4[cnt643 + cnt657] = val651;
    cnt657++;
  }
}
;
;

cnt643 += (1) * (CAT_SZ2 * (CAT_SZ2 - 1) * (CAT_SZ2 - 2) * (CAT_SZ2 - 3) / 24 + CAT_SZ2 * (CAT_SZ2 - 1) * (CAT_SZ2 - 2) / 2);
;
;
std::array<size_t, 0 + 4> val658;
;
;
;

size_t cnt663 = 0;
for (size_t i659 = 0; i659 < CAT_SZ * (CAT_SZ - 1) / 2; i659++) {
  val134 = rev_cat_degree2.find(i659)->second;
  for (size_t j660 = 0; j660 < CAT_SZ2 * (CAT_SZ2 - 1) / 2; j660++) {
    val141 = other.rev_cat_degree2.find(j660)->second;
    for (size_t r662 = 0; r662 < 1; r662++) {
      for (size_t k661 = 0; k661 < 0; k661++) {
        val658[r662 * 0 + k661] = val134[k661] + 0;
      }
    }
    for (size_t r662 = 0; r662 < 1; r662++) {
      for (size_t k661 = 0; k661 < 0; k661++) {
        val658[r662 * 0 + k661 + 0 * 1] = val141[k661] + CONT_SZ;
      }
    }
    for (size_t r662 = 0; r662 < 1; r662++) {
      for (size_t k661 = 0; k661 < 2; k661++) {
        val658[r662 * 2 + k661 + 0 * 1 + 0 * 1] = val134[0 + k661] + 0;
      }
    }
    for (size_t r662 = 0; r662 < 1; r662++) {
      for (size_t k661 = 0; k661 < 2; k661++) {
        val658[r662 * 2 + k661 + 0 * 1 + 0 * 1 + 2 * 1] = val141[0 + k661] + CAT_SZ;
      }
    }
    r.map_cat_degree4[val658] = cnt643 + cnt663;
    r.rev_cat_degree4[cnt643 + cnt663] = val658;
    cnt663++;
  }
}
;
;

cnt643 += (CAT_SZ * (CAT_SZ - 1) / 2) * (CAT_SZ2 * (CAT_SZ2 - 1) / 2);
;
;
std::array<size_t, 0 + 4> val664;
;
;
;

size_t cnt669 = 0;
for (size_t i665 = 0; i665 < CAT_SZ * (CAT_SZ - 1) / 2; i665++) {
  val134 = rev_cat_degree2.find(i665)->second;
  for (size_t j666 = 0; j666 < CAT_SZ2; j666++) {
    val322 = other.rev_cat_sum2.find(j666)->second;
    for (size_t r668 = 0; r668 < 1; r668++) {
      for (size_t k667 = 0; k667 < 0; k667++) {
        val664[r668 * 0 + k667] = val134[k667] + 0;
      }
    }
    for (size_t r668 = 0; r668 < 2; r668++) {
      for (size_t k667 = 0; k667 < 0; k667++) {
        val664[r668 * 0 + k667 + 0 * 1] = val322[k667] + CONT_SZ;
      }
    }
    for (size_t r668 = 0; r668 < 1; r668++) {
      for (size_t k667 = 0; k667 < 2; k667++) {
        val664[r668 * 2 + k667 + 0 * 1 + 0 * 2] = val134[0 + k667] + 0;
      }
    }
    for (size_t r668 = 0; r668 < 2; r668++) {
      for (size_t k667 = 0; k667 < 1; k667++) {
        val664[r668 * 1 + k667 + 0 * 1 + 0 * 2 + 2 * 1] = val322[0 + k667] + CAT_SZ;
      }
    }
    r.map_cat_degree4[val664] = cnt643 + cnt669;
    r.rev_cat_degree4[cnt643 + cnt669] = val664;
    cnt669++;
  }
}
;
;

cnt643 += (CAT_SZ * (CAT_SZ - 1) / 2) * (CAT_SZ2);
;
;
std::array<size_t, 0 + 4> val670;
;
;
;

size_t cnt675 = 0;
for (size_t i671 = 0; i671 < CAT_SZ; i671++) {
  val315 = rev_cat_sum2.find(i671)->second;
  for (size_t j672 = 0; j672 < CAT_SZ2 * (CAT_SZ2 - 1) / 2; j672++) {
    val141 = other.rev_cat_degree2.find(j672)->second;
    for (size_t r674 = 0; r674 < 2; r674++) {
      for (size_t k673 = 0; k673 < 0; k673++) {
        val670[r674 * 0 + k673] = val315[k673] + 0;
      }
    }
    for (size_t r674 = 0; r674 < 1; r674++) {
      for (size_t k673 = 0; k673 < 0; k673++) {
        val670[r674 * 0 + k673 + 0 * 2] = val141[k673] + CONT_SZ;
      }
    }
    for (size_t r674 = 0; r674 < 2; r674++) {
      for (size_t k673 = 0; k673 < 1; k673++) {
        val670[r674 * 1 + k673 + 0 * 2 + 0 * 1] = val315[0 + k673] + 0;
      }
    }
    for (size_t r674 = 0; r674 < 1; r674++) {
      for (size_t k673 = 0; k673 < 2; k673++) {
        val670[r674 * 2 + k673 + 0 * 2 + 0 * 1 + 1 * 2] = val141[0 + k673] + CAT_SZ;
      }
    }
    r.map_cat_degree4[val670] = cnt643 + cnt675;
    r.rev_cat_degree4[cnt643 + cnt675] = val670;
    cnt675++;
  }
}
;
;

cnt643 += (CAT_SZ) * (CAT_SZ2 * (CAT_SZ2 - 1) / 2);
;
;
std::array<size_t, 0 + 4> val676;
;
;
;

size_t cnt681 = 0;
for (size_t i677 = 0; i677 < CAT_SZ * (CAT_SZ - 1) * (CAT_SZ - 2) / 6 + CAT_SZ * (CAT_SZ - 1); i677++) {
  val354 = rev_cat_degree3.find(i677)->second;
  for (size_t j678 = 0; j678 < CAT_SZ2; j678++) {
    val90 = other.rev_cat_sum1.find(j678)->second;
    for (size_t r680 = 0; r680 < 1; r680++) {
      for (size_t k679 = 0; k679 < 0; k679++) {
        val676[r680 * 0 + k679] = val354[k679] + 0;
      }
    }
    for (size_t r680 = 0; r680 < 1; r680++) {
      for (size_t k679 = 0; k679 < 0; k679++) {
        val676[r680 * 0 + k679 + 0 * 1] = val90[k679] + CONT_SZ;
      }
    }
    for (size_t r680 = 0; r680 < 1; r680++) {
      for (size_t k679 = 0; k679 < 3; k679++) {
        val676[r680 * 3 + k679 + 0 * 1 + 0 * 1] = val354[0 + k679] + 0;
      }
    }
    for (size_t r680 = 0; r680 < 1; r680++) {
      for (size_t k679 = 0; k679 < 1; k679++) {
        val676[r680 * 1 + k679 + 0 * 1 + 0 * 1 + 3 * 1] = val90[0 + k679] + CAT_SZ;
      }
    }
    r.map_cat_degree4[val676] = cnt643 + cnt681;
    r.rev_cat_degree4[cnt643 + cnt681] = val676;
    cnt681++;
  }
}
;
;

cnt643 += (CAT_SZ * (CAT_SZ - 1) * (CAT_SZ - 2) / 6 + CAT_SZ * (CAT_SZ - 1)) * (CAT_SZ2);
;
;
std::array<size_t, 0 + 4> val682;
;
;
;

size_t cnt687 = 0;
for (size_t i683 = 0; i683 < CAT_SZ; i683++) {
  val83 = rev_cat_sum1.find(i683)->second;
  for (size_t j684 = 0; j684 < CAT_SZ2 * (CAT_SZ2 - 1) * (CAT_SZ2 - 2) / 6 + CAT_SZ2 * (CAT_SZ2 - 1); j684++) {
    val361 = other.rev_cat_degree3.find(j684)->second;
    for (size_t r686 = 0; r686 < 1; r686++) {
      for (size_t k685 = 0; k685 < 0; k685++) {
        val682[r686 * 0 + k685] = val83[k685] + 0;
      }
    }
    for (size_t r686 = 0; r686 < 1; r686++) {
      for (size_t k685 = 0; k685 < 0; k685++) {
        val682[r686 * 0 + k685 + 0 * 1] = val361[k685] + CONT_SZ;
      }
    }
    for (size_t r686 = 0; r686 < 1; r686++) {
      for (size_t k685 = 0; k685 < 1; k685++) {
        val682[r686 * 1 + k685 + 0 * 1 + 0 * 1] = val83[0 + k685] + 0;
      }
    }
    for (size_t r686 = 0; r686 < 1; r686++) {
      for (size_t k685 = 0; k685 < 3; k685++) {
        val682[r686 * 3 + k685 + 0 * 1 + 0 * 1 + 1 * 1] = val361[0 + k685] + CAT_SZ;
      }
    }
    r.map_cat_degree4[val682] = cnt643 + cnt687;
    r.rev_cat_degree4[cnt643 + cnt687] = val682;
    cnt687++;
  }
}
;
;



        return r;
    }
};


template <size_t CONT_SZ, size_t CAT_SZ>
IndexMap<CONT_SZ, CAT_SZ> IndexCovar() {
    return IndexMap<CONT_SZ, CAT_SZ>();
}

template <size_t CONT_SZ, size_t CAT_SZ>
std::ostream& operator<<(std::ostream& os, const IndexMap<CONT_SZ, CAT_SZ>& v) {
    
    os << "\nmap_count:\n";
    for (size_t i = 0; i < v.rev_count.size(); i++) {
        os << v.rev_count.find(i)->second << ":" << i << ", ";
    }
    os << "\nmap_cont_sum1:\n";
    for (size_t i = 0; i < v.rev_cont_sum1.size(); i++) {
        os << v.rev_cont_sum1.find(i)->second << ":" << i << ", ";
    }
    os << "\nmap_cont_sum2:\n";
    for (size_t i = 0; i < v.rev_cont_sum2.size(); i++) {
        os << v.rev_cont_sum2.find(i)->second << ":" << i << ", ";
    }
    os << "\nmap_cont_sum4:\n";
    for (size_t i = 0; i < v.rev_cont_sum4.size(); i++) {
        os << v.rev_cont_sum4.find(i)->second << ":" << i << ", ";
    }
    os << "\nmap_cont_degree2:\n";
    for (size_t i = 0; i < v.rev_cont_degree2.size(); i++) {
        os << v.rev_cont_degree2.find(i)->second << ":" << i << ", ";
    }
    os << "\nmap_cat_sum1:\n";
    for (size_t i = 0; i < v.rev_cat_sum1.size(); i++) {
        os << v.rev_cat_sum1.find(i)->second << ":" << i << ", ";
    }
    os << "\nmap_cat_sum2:\n";
    for (size_t i = 0; i < v.rev_cat_sum2.size(); i++) {
        os << v.rev_cat_sum2.find(i)->second << ":" << i << ", ";
    }
    os << "\nmap_cat_sum4:\n";
    for (size_t i = 0; i < v.rev_cat_sum4.size(); i++) {
        os << v.rev_cat_sum4.find(i)->second << ":" << i << ", ";
    }
    os << "\nmap_cat_degree2:\n";
    for (size_t i = 0; i < v.rev_cat_degree2.size(); i++) {
        os << v.rev_cat_degree2.find(i)->second << ":" << i << ", ";
    }
    os << "\nmap_cont_cat_sum4:\n";
    for (size_t i = 0; i < v.rev_cont_cat_sum4.size(); i++) {
        os << v.rev_cont_cat_sum4.find(i)->second << ":" << i << ", ";
    }
    os << "\nmap_cont_cat_degree2:\n";
    for (size_t i = 0; i < v.rev_cont_cat_degree2.size(); i++) {
        os << v.rev_cont_cat_degree2.find(i)->second << ":" << i << ", ";
    }
    os << "\nmap_cont_degree3:\n";
    for (size_t i = 0; i < v.rev_cont_degree3.size(); i++) {
        os << v.rev_cont_degree3.find(i)->second << ":" << i << ", ";
    }
    os << "\nmap_cont2_cat_degree3:\n";
    for (size_t i = 0; i < v.rev_cont2_cat_degree3.size(); i++) {
        os << v.rev_cont2_cat_degree3.find(i)->second << ":" << i << ", ";
    }
    os << "\nmap_cont_cat2_degree3:\n";
    for (size_t i = 0; i < v.rev_cont_cat2_degree3.size(); i++) {
        os << v.rev_cont_cat2_degree3.find(i)->second << ":" << i << ", ";
    }
    os << "\nmap_cat_degree3:\n";
    for (size_t i = 0; i < v.rev_cat_degree3.size(); i++) {
        os << v.rev_cat_degree3.find(i)->second << ":" << i << ", ";
    }
    os << "\nmap_cont_degree4:\n";
    for (size_t i = 0; i < v.rev_cont_degree4.size(); i++) {
        os << v.rev_cont_degree4.find(i)->second << ":" << i << ", ";
    }
    os << "\nmap_cont3_cat_degree4:\n";
    for (size_t i = 0; i < v.rev_cont3_cat_degree4.size(); i++) {
        os << v.rev_cont3_cat_degree4.find(i)->second << ":" << i << ", ";
    }
    os << "\nmap_cont2_cat2_degree4:\n";
    for (size_t i = 0; i < v.rev_cont2_cat2_degree4.size(); i++) {
        os << v.rev_cont2_cat2_degree4.find(i)->second << ":" << i << ", ";
    }
    os << "\nmap_cont_cat3_degree4:\n";
    for (size_t i = 0; i < v.rev_cont_cat3_degree4.size(); i++) {
        os << v.rev_cont_cat3_degree4.find(i)->second << ":" << i << ", ";
    }
    os << "\nmap_cat_degree4:\n";
    for (size_t i = 0; i < v.rev_cat_degree4.size(); i++) {
        os << v.rev_cat_degree4.find(i)->second << ":" << i << ", ";
    }
    os << "\n";  
    return os;
}

template <size_t SZ>
std::ostream& operator<<(std::ostream& os, const std::array<size_t, SZ> &v) {
  os << "(";
  for (size_t i = 0; i < SZ - 1; i++) {
      os << v[i] << ",";
  }
  os << v[SZ - 1] << ")";
  return os;
}
