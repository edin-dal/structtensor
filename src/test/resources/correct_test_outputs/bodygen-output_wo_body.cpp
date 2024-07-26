
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

extern "C"
void fn(double *** covar, int M) {


long time_computation = 0, start_computation, end_computation;
start_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
for (int i = 0; i < M; ++i) {

for (int j = 0; j < M; ++j) {

for (int k = max({j, 0}); k < min({(i) + 1, M}); ++k) {

covar[i][j][k] += (1 * 1 * 1);
}
}
}
}
end_computation = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_computation = end_computation - start_computation;
cout << time_computation << endl;
long time_reconstruction = 0, start_reconstruction, end_reconstruction;
start_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
{
for (int i = 0; i < M; ++i) {

int jp = i;
for (int j = max({(i) + 1, 0}); j < M; ++j) {

int kp = j;
for (int k = max({j, 0}); k < M; ++k) {

int ip = k;
covar[i][j][k] = covar[ip][jp][kp];
}
}
}
}
{
for (int i = 0; i < M; ++i) {

int kp = i;
for (int j = 0; j < min({(i) + 1, M}); ++j) {

for (int k = max({(i) + 1, 0}); k < M; ++k) {

int jp = j;
int ip = k;
covar[i][j][k] = covar[ip][jp][kp];
}
}
}
}
{
for (int i = 0; i < M; ++i) {

int kp = i;
for (int j = max({(i) + 1, 0}); j < M; ++j) {

for (int k = 0; k < min({(i) + 1, M}); ++k) {

int ip = j;
int jp = k;
covar[i][j][k] = covar[ip][jp][kp];
}
}
}
}
{
for (int i = 0; i < M; ++i) {

int jp = i;
for (int j = 0; j < M; ++j) {

int ip = j;
for (int k = max({(i) + 1, 0}); k < min({j, M}); ++k) {

int kp = k;
covar[i][j][k] = covar[ip][jp][kp];
}
}
}
}
{
for (int i = 0; i < M; ++i) {

int ip = i;
for (int j = 0; j < min({(i) + 1, M}); ++j) {

int kp = j;
for (int k = 0; k < min({j, M}); ++k) {

int jp = k;
covar[i][j][k] = covar[ip][jp][kp];
}
}
}
}
end_reconstruction = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
time_reconstruction = end_reconstruction - start_reconstruction;
cout << time_reconstruction << endl;

}