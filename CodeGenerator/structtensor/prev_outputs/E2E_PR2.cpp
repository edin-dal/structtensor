
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
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
cont_degree2[x0][x1] = ((cont_sum1[x0] * cont_sum1[x1]));
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = x1; x2 < CONT_SZ; ++x2) {
cont_degree3[x0][x1][x2] = ((cont_sum1[x0] * cont_sum1[x1] * cont_sum1[x2]));
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = x1; x2 < CONT_SZ; ++x2) {
for (int x3 = x2; x3 < CONT_SZ; ++x3) {
cont_degree4[x0][x1][x2][x3] = ((cont_sum1[x0] * cont_sum1[x1] * cont_sum1[x2] * cont_sum1[x3]));
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
cont_sum1[x0] += ((other.cont_sum1[x0]));
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
cont_degree2[x0][x1] += ((other.cont_degree2[x0][x1]));
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = x1; x2 < CONT_SZ; ++x2) {
cont_degree3[x0][x1][x2] += ((other.cont_degree3[x0][x1][x2]));
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = x1; x2 < CONT_SZ; ++x2) {
for (int x3 = x2; x3 < CONT_SZ; ++x3) {
cont_degree4[x0][x1][x2][x3] += ((other.cont_degree4[x0][x1][x2][x3]));
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


r.cont_sum1[x0] += (cont_sum1[x0] * other.count);

}


for (int x0 = CONT_SZ; x0 < (CONT_SZ2 + CONT_SZ); ++x0) {


r.cont_sum1[x0] += (count * other.cont_sum1[(x0 - CONT_SZ)]);

}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {



r.cont_degree2[x0][x1] += (cont_degree2[x0][x1] * other.count);

}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = CONT_SZ; x1 < (CONT_SZ2 + CONT_SZ); ++x1) {



r.cont_degree2[x0][x1] += (cont_sum1[x0] * other.cont_sum1[(x1 - CONT_SZ)]);

}
}


for (int x0 = CONT_SZ; x0 < (CONT_SZ2 + CONT_SZ); ++x0) {
for (int x1 = std::max({x0, CONT_SZ}); x1 < (CONT_SZ2 + CONT_SZ); ++x1) {



r.cont_degree2[x0][x1] += (count * other.cont_degree2[(x0 - CONT_SZ)][(x1 - CONT_SZ)]);

}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = x1; x2 < CONT_SZ; ++x2) {




r.cont_degree3[x0][x1][x2] += (cont_degree3[x0][x1][x2] * other.count);

}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = CONT_SZ; x2 < (CONT_SZ2 + CONT_SZ); ++x2) {




r.cont_degree3[x0][x1][x2] += (cont_degree2[x0][x1] * other.cont_sum1[(x2 - CONT_SZ)]);

}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = CONT_SZ; x1 < (CONT_SZ2 + CONT_SZ); ++x1) {
for (int x2 = std::max({x1, CONT_SZ}); x2 < (CONT_SZ2 + CONT_SZ); ++x2) {




r.cont_degree3[x0][x1][x2] += (cont_sum1[x0] * other.cont_degree2[(x1 - CONT_SZ)][(x2 - CONT_SZ)]);

}
}
}


for (int x0 = CONT_SZ; x0 < (CONT_SZ2 + CONT_SZ); ++x0) {
for (int x1 = std::max({x0, CONT_SZ}); x1 < (CONT_SZ2 + CONT_SZ); ++x1) {
for (int x2 = std::max({x1, CONT_SZ}); x2 < (CONT_SZ2 + CONT_SZ); ++x2) {




r.cont_degree3[x0][x1][x2] += (count * other.cont_degree3[(x0 - CONT_SZ)][(x1 - CONT_SZ)][(x2 - CONT_SZ)]);

}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = CONT_SZ; x1 < (CONT_SZ2 + CONT_SZ); ++x1) {
for (int x2 = std::max({x1, CONT_SZ}); x2 < (CONT_SZ2 + CONT_SZ); ++x2) {
for (int x3 = std::max({x2, CONT_SZ}); x3 < (CONT_SZ2 + CONT_SZ); ++x3) {





r.cont_degree4[x0][x1][x2][x3] += (cont_sum1[x0] * other.cont_degree3[(x1 - CONT_SZ)][(x2 - CONT_SZ)][(x3 - CONT_SZ)]);

}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = x1; x2 < CONT_SZ; ++x2) {
for (int x3 = x2; x3 < CONT_SZ; ++x3) {





r.cont_degree4[x0][x1][x2][x3] += (cont_degree4[x0][x1][x2][x3] * other.count);

}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = CONT_SZ; x2 < (CONT_SZ2 + CONT_SZ); ++x2) {
for (int x3 = std::max({x2, CONT_SZ}); x3 < (CONT_SZ2 + CONT_SZ); ++x3) {





r.cont_degree4[x0][x1][x2][x3] += (cont_degree2[x0][x1] * other.cont_degree2[(x2 - CONT_SZ)][(x3 - CONT_SZ)]);

}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = x1; x2 < CONT_SZ; ++x2) {
for (int x3 = CONT_SZ; x3 < (CONT_SZ2 + CONT_SZ); ++x3) {





r.cont_degree4[x0][x1][x2][x3] += (cont_degree3[x0][x1][x2] * other.cont_sum1[(x3 - CONT_SZ)]);

}
}
}
}


for (int x0 = CONT_SZ; x0 < (CONT_SZ2 + CONT_SZ); ++x0) {
for (int x1 = std::max({x0, CONT_SZ}); x1 < (CONT_SZ2 + CONT_SZ); ++x1) {
for (int x2 = std::max({x1, CONT_SZ}); x2 < (CONT_SZ2 + CONT_SZ); ++x2) {
for (int x3 = std::max({x2, CONT_SZ}); x3 < (CONT_SZ2 + CONT_SZ); ++x3) {





r.cont_degree4[x0][x1][x2][x3] += (count * other.cont_degree4[(x0 - CONT_SZ)][(x1 - CONT_SZ)][(x2 - CONT_SZ)][(x3 - CONT_SZ)]);

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
for (int x1 = 0; x1 < std::min({x0, CONT_SZ}); ++x1) {


cont_degree2[x0][x1] = cont_degree2[x1][x0];
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = 0; x2 < std::min({CONT_SZ, (x0 + 1)}); ++x2) {



cont_degree3[x0][x1][x2] = cont_degree3[x2][x0][x1];
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < std::min({CONT_SZ, (x0 + 1)}); ++x1) {
for (int x2 = x0; x2 < CONT_SZ; ++x2) {



cont_degree3[x0][x1][x2] = cont_degree3[x1][x0][x2];
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < std::min({CONT_SZ, (x0 + 1)}); ++x1) {
for (int x2 = 0; x2 < std::min({CONT_SZ, (x1 + 1)}); ++x2) {



cont_degree3[x0][x1][x2] = cont_degree3[x2][x1][x0];
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < CONT_SZ; ++x1) {
for (int x2 = x1; x2 < std::min({CONT_SZ, (x0 + 1)}); ++x2) {



cont_degree3[x0][x1][x2] = cont_degree3[x1][x2][x0];
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < CONT_SZ; ++x1) {
for (int x2 = x0; x2 < std::min({CONT_SZ, (x1 + 1)}); ++x2) {



cont_degree3[x0][x1][x2] = cont_degree3[x0][x2][x1];
}
}
}



for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < CONT_SZ; ++x1) {
for (int x2 = x1; x2 < std::min({CONT_SZ, (x0 + 1)}); ++x2) {
for (int x3 = 0; x3 < std::min({CONT_SZ, (x1 + 1)}); ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x3][x1][x2][x0];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < std::min({CONT_SZ, (x0 + 1)}); ++x1) {
for (int x2 = 0; x2 < std::min({CONT_SZ, (x1 + 1)}); ++x2) {
for (int x3 = 0; x3 < std::min({CONT_SZ, (x2 + 1)}); ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x3][x2][x1][x0];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < CONT_SZ; ++x1) {
for (int x2 = x0; x2 < std::min({CONT_SZ, (x1 + 1)}); ++x2) {
for (int x3 = 0; x3 < std::min({CONT_SZ, (x0 + 1)}); ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x3][x0][x2][x1];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < CONT_SZ; ++x1) {
for (int x2 = x1; x2 < CONT_SZ; ++x2) {
for (int x3 = x2; x3 < std::min({CONT_SZ, (x0 + 1)}); ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x1][x2][x3][x0];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = x1; x2 < CONT_SZ; ++x2) {
for (int x3 = 0; x3 < std::min({CONT_SZ, (x0 + 1)}); ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x3][x0][x1][x2];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < CONT_SZ; ++x1) {
for (int x2 = x0; x2 < CONT_SZ; ++x2) {
for (int x3 = x1; x3 < std::min({CONT_SZ, (x0 + 1)}); ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x1][x3][x0][x2];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < CONT_SZ; ++x1) {
for (int x2 = 0; x2 < std::min({CONT_SZ, (x0 + 1)}); ++x2) {
for (int x3 = x0; x3 < std::min({CONT_SZ, (x1 + 1)}); ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x2][x0][x3][x1];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < CONT_SZ; ++x1) {
for (int x2 = x1; x2 < std::min({CONT_SZ, (x0 + 1)}); ++x2) {
for (int x3 = x0; x3 < CONT_SZ; ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x1][x2][x0][x3];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < std::min({CONT_SZ, (x0 + 1)}); ++x1) {
for (int x2 = 0; x2 < std::min({CONT_SZ, (x1 + 1)}); ++x2) {
for (int x3 = x0; x3 < CONT_SZ; ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x2][x1][x0][x3];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < CONT_SZ; ++x1) {
for (int x2 = 0; x2 < std::min({CONT_SZ, (x1 + 1)}); ++x2) {
for (int x3 = x1; x3 < std::min({CONT_SZ, (x0 + 1)}); ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x2][x1][x3][x0];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < std::min({CONT_SZ, (x0 + 1)}); ++x1) {
for (int x2 = 0; x2 < CONT_SZ; ++x2) {
for (int x3 = x0; x3 < std::min({CONT_SZ, (x2 + 1)}); ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x1][x0][x3][x2];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < CONT_SZ; ++x1) {
for (int x2 = x0; x2 < std::min({CONT_SZ, (x1 + 1)}); ++x2) {
for (int x3 = x1; x3 < CONT_SZ; ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x0][x2][x1][x3];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = 0; x2 < CONT_SZ; ++x2) {
for (int x3 = x2; x3 < std::min({CONT_SZ, (x0 + 1)}); ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x2][x3][x0][x1];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < std::min({CONT_SZ, (x0 + 1)}); ++x1) {
for (int x2 = x0; x2 < CONT_SZ; ++x2) {
for (int x3 = x2; x3 < CONT_SZ; ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x1][x0][x2][x3];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < CONT_SZ; ++x1) {
for (int x2 = x0; x2 < CONT_SZ; ++x2) {
for (int x3 = x2; x3 < std::min({CONT_SZ, (x1 + 1)}); ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x0][x2][x3][x1];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < CONT_SZ; ++x1) {
for (int x2 = 0; x2 < std::min({CONT_SZ, (x1 + 1)}); ++x2) {
for (int x3 = x0; x3 < std::min({CONT_SZ, (x2 + 1)}); ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x0][x3][x2][x1];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < CONT_SZ; ++x1) {
for (int x2 = x1; x2 < CONT_SZ; ++x2) {
for (int x3 = x0; x3 < std::min({CONT_SZ, (x1 + 1)}); ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x0][x3][x1][x2];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = 0; x2 < std::min({CONT_SZ, (x0 + 1)}); ++x2) {
for (int x3 = 0; x3 < std::min({CONT_SZ, (x2 + 1)}); ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x3][x2][x0][x1];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = 0; x2 < std::min({CONT_SZ, (x0 + 1)}); ++x2) {
for (int x3 = x1; x3 < CONT_SZ; ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x2][x0][x1][x3];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < std::min({CONT_SZ, (x0 + 1)}); ++x1) {
for (int x2 = x0; x2 < CONT_SZ; ++x2) {
for (int x3 = 0; x3 < std::min({CONT_SZ, (x1 + 1)}); ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x3][x1][x0][x2];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < CONT_SZ; ++x1) {
for (int x2 = 0; x2 < std::min({CONT_SZ, (x0 + 1)}); ++x2) {
for (int x3 = x1; x3 < std::min({CONT_SZ, (x2 + 1)}); ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x1][x3][x2][x0];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = 0; x1 < std::min({CONT_SZ, (x0 + 1)}); ++x1) {
for (int x2 = 0; x2 < CONT_SZ; ++x2) {
for (int x3 = x2; x3 < std::min({CONT_SZ, (x1 + 1)}); ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x2][x3][x1][x0];
}
}
}
}


for (int x0 = 0; x0 < CONT_SZ; ++x0) {
for (int x1 = x0; x1 < CONT_SZ; ++x1) {
for (int x2 = 0; x2 < CONT_SZ; ++x2) {
for (int x3 = x1; x3 < std::min({CONT_SZ, (x2 + 1)}); ++x3) {




cont_degree4[x0][x1][x2][x3] = cont_degree4[x0][x1][x3][x2];
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
