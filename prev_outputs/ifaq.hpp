#pragma once

#include <vector>
#include <map>
#include <unordered_map>
#include <boost/unordered_map.hpp>
#include <boost/container/flat_map.hpp>
#include "robin_hood.h"

using namespace std;

/** Dictionary definitions */

template<class K, class V> using boost_unordered_map = 
  boost::unordered_map<K, V, std::hash<K>>;
template<class K, class V> using boost_flat_map = 
  boost::container::flat_map<K, V>;
template<class K, class V> using robinhood_dict = 
  robin_hood::unordered_map<K, V>;

#define DEFINE_FOR_MAPS(MACRO)                                                 \
MACRO(boost_flat_map);                                  \
MACRO(std::map);                                        \
MACRO(std::unordered_map);                                        \
MACRO(boost_unordered_map);                                        \
MACRO(robinhood_dict);

/** Tuple helpers */
template <class F, class... Ts, std::size_t... Is>
void for_each_in_2tuple(std::tuple<Ts...>& tuple1, const std::tuple<Ts...>& tuple2, F func,
                       std::index_sequence<Is...>) {
   using expander = int[];
   (void)expander{0, ((void)func(std::get<Is>(tuple1), std::get<Is>(tuple2)), 0)...};
}

template <class F, class... Ts>
void for_each_in_2tuple(std::tuple<Ts...>& tuple1, const std::tuple<Ts...>& tuple2, F func) {
   for_each_in_2tuple(tuple1, tuple2, func, std::make_index_sequence<sizeof...(Ts)>());
}

/* Memory management */
  

#define BUMP
#define INIT_HEAP_SIZE (1 << 20)
#define ALLIGN_BY_16(x) (((((x) + 15) >> 4) << 4))
#define MAX_HEAP_SIZE ((memory_size_t)(1) << 31)

typedef void *storage_t;
typedef unsigned long long int memory_size_t;
typedef string field_t;

typedef struct heap_t
{
  storage_t storage;
  memory_size_t free_index;
  memory_size_t size;
} heap_t;

storage_t try_allocate(memory_size_t size)
{
  storage_t storage = malloc(size);
  if (storage == NULL)
  {
    fprintf(stderr, "Cannot allocate buffer of size %llu\n", size);
    exit(1);
  }
  return storage;
}

heap_t initHeap(memory_size_t size)
{
  heap_t heap;
  heap.storage = try_allocate(size);
  heap.free_index = 0;
  heap.size = size;
  return heap;
}

heap_t heapObject;
memory_size_t increase_rate;

storage_t bulk_alloc(memory_size_t size)
{
  memory_size_t aligned_size = ALLIGN_BY_16(size);
  memory_size_t new_free_index = heapObject.free_index + aligned_size;
  if (new_free_index >= heapObject.size)
  {
    increase_rate = heapObject.size < INIT_HEAP_SIZE ? INIT_HEAP_SIZE : increase_rate * 2;
    memory_size_t new_size = heapObject.size + increase_rate;
    new_size = new_size < new_free_index ? heapObject.size + aligned_size : new_size;
    // printf("%lld < %lld\n", new_size + heapObject.size * 2, MAX_HEAP_SIZE);
    new_size = (new_size + heapObject.size * 2) < MAX_HEAP_SIZE ? new_size : new_size * 5 / 8;

    heap_t oldHeapObject = heapObject;
    // fprintf(stderr, "Increased the size of heap into %llu, old size: %llu, asked size: %llu, last given index: %llu!\n", new_size, oldHeapObject.size, size, oldHeapObject.free_index);
    heapObject = initHeap(new_size);
    // heapObject.free_index = oldHeapObject.free_index;
    // memcpy(heapObject.storage, oldHeapObject.storage, heapObject.free_index);
    // free(oldHeapObject.storage);
  }
  storage_t allocatedStorage = (void *)((memory_size_t)heapObject.storage + heapObject.free_index);
  heapObject.free_index = heapObject.free_index + aligned_size;
  return allocatedStorage;
}

void bulk_free(storage_t storage, memory_size_t size)
{
  memory_size_t aligned_size = ALLIGN_BY_16(size);
  heapObject.free_index -= aligned_size;
  assert(heapObject.free_index >= 0);
  // if(heapObject.free_index < 0)
  //  heapObject.free_index = 0;
}

storage_t storage_alloc(memory_size_t size)
{
#ifdef BUMP
  return bulk_alloc(size);
#else
#ifdef GC
  return GC_malloc(size);
#else
  return malloc(size);
#endif
#endif
}

void storage_free(storage_t storage, memory_size_t size)
{
#ifdef BUMP
  bulk_free(storage, size);
#else
  free(storage);
#endif
}

// struct my_iterator {
//   int index;
// };

template <typename K, typename V>
class MyMap
{
  typedef pair<K, V> pair_type;
  typedef vector<pair_type> vector_type;
  // typedef my_iterator iterator;
  // typedef my_iterator const_iterator;
  // my_iterator cur_iterator;
  vector_type underlying;

public:
  typedef typename vector_type::iterator iterator;
  typedef typename vector_type::const_iterator const_iterator;
  void insert(const pair_type &p)
  {
    underlying.push_back(p);
  }
  inline void emplace(const K& key, const V& value) {
    underlying.emplace_back(key, value);
  }
  inline iterator emplace_hint(iterator&& hint, const K& key, const V& value) {
    underlying.emplace_back(key, value);
    return hint;
  }
  inline iterator emplace_hint(iterator& hint, const K& key, const V& value) {
    underlying.emplace_back(key, value);
    return hint;
  }
  const V& at(const K& k) const {
  	// for(auto const& e : underlying) {
  	//   if(e.first == k) return e.second;
  	// }
    int low = 0, high = underlying.size();
    while(low <= high) {
      int i = (low + high) / 2;
      auto& e = underlying[i];
      auto& ck = e.first;
      if(k == ck) {
        return e.second;
      } else if (k < ck) {
        high = i - 1;
      } else {
        low = i + 1;
      }
    }
  	__throw_out_of_range(("MyMap::at"));
  }
  V& at(const K& k) {
  	// for(auto & e : underlying) {
  	//   if(e.first == k) return e.second;
  	// }
    int low = 0, high = underlying.size();
    while(low <= high) {
      int i = (low + high) / 2;
      auto& e = underlying[i];
      auto& ck = e.first;
      if(k == ck) {
        return e.second;
      } else if (k < ck) {
        high = i - 1;
      } else {
        low = i + 1;
      }
    }
  	__throw_out_of_range(("MyMap::at"));
  }
  const int count(const K& k) const {
  	for(auto const& e : underlying) {
  	  if(e.first == k) return 1;
  	}
  	return 0;
  }
  const_iterator find(const K& k) const {
    const_iterator cur = begin();
    const_iterator endIter = end(); 
    while(cur != endIter) {
      if(cur->first == k)
        return cur;
      cur++;
    }
    __throw_out_of_range(("MyMap::find"));
  }
  iterator begin() { return underlying.begin(); }
  const_iterator begin() const { return underlying.begin(); }
  iterator end() { return underlying.end(); }
  const_iterator end() const { return underlying.end(); }
  bool operator==(const MyMap<K, V> &other) const
  {
    return underlying == other.underlying;
  }
};

template <class M, class K, class V>
inline const V& get_or_else_hint(const M& m, typename M::iterator& iter, const K&k, const V & defval ) {
  // auto& end = reinterpret_cast<decltype(iter)>(m.end()); 
  auto end = m.end(); 
  // typename M::iterator& end = reinterpret_cast<typename M::iterator>(m.end());
  while(end != iter && iter->first < k) {
    iter++;
  }
  if(end != iter && iter->first == k)
    return iter->second;
  return defval;
}

template <class M, class K, class V>
inline const V& sortedmap_at(const M& m, const K&k, typename M::iterator& iter, const V & defval ) {
  return get_or_else_hint(m, iter, k, defval);
}

template <class M, class K>
inline int count_hint(const M& m, typename M::iterator& iter, const K&k) {
  // auto& end = reinterpret_cast<decltype(iter)>(m.end()); 
  auto end = m.end(); 
  // typename M::iterator& end = reinterpret_cast<typename M::iterator>(m.end());
  while(end != iter && iter->first < k) {
    iter++;
  }
  if(end != iter && iter->first == k)
    return 1;
  return 0;
}

template <class M, class K, class V>
inline const V& get_or_else(const  M & m, const K & key, const V & defval ) {
   auto it = m.find( key );
   if ( it == m.end() ) {
      return defval;
   }
   else {
      return it->second;
   }
}

template<class T>
struct Type
{
    static const T& Default ;
private:
    static const char temp[sizeof(T)];
};

template<class T> const char Type<T>::temp[] = {};
template<class T> const T& Type<T>::Default =  *(T*)temp;

template <class V>
inline const bool is_default_value(const V& v) {
  return v == (Type<V>::Default);
}

template<template<class ...> class M, class K, class V>
const M<K, V> TopN(const M<K, V> &m, int limit) {
  const M<K, V> res(m.begin(), std::next(m.begin(), limit));
  return res;
}

bool StrContains(const string &s1, const string &s2)
{
  return s1.find(s2) != string::npos;
}
int Year(int date)
{
  return date / 10000;
}

template<typename T>
inline void ensure_size(std::vector<T>& vec, size_t size) {
  if(vec.size() <= size)
    vec.resize((size + 1) * 2 + 1);
}

template<typename M, typename K, typename V>
inline void print_map(std::ostream &os, const M &m) ;

template<typename... Types>
inline void print_tuple(std::ostream &os, const std::tuple<Types...>& value) ;

#define PRINT_MAP(DICT_TYPE)                                                   \
template <typename K, typename V>                                              \
std::ostream &operator<<(std::ostream &os,                                     \
                const DICT_TYPE<K, V> &m)                                      \
{                                                                              \
  print_map<DICT_TYPE<K, V>, K, V>(os, m);                                        \
  return os;                                                                   \
}

DEFINE_FOR_MAPS(PRINT_MAP);

template<typename... Types>
std::ostream& operator<<(std::ostream& out, const std::tuple<Types...>& value) {
    print_tuple(out, value);
    return out;
}

template<typename K>
std::ostream& operator<<(std::ostream& os,
                        const std::vector<K> &v) {
  os << "[[";
  for (auto& p : v)
  {
    os << " " << p << "\n";
  }
  os << "]]";
  return os;
}

template<typename M, typename K, typename V>
inline void print_map(std::ostream &os, const M &m)
{
  std::vector<K> keys;

  keys.reserve (m.size());
  for (auto& it : m) {
      keys.push_back(it.first);
  }
  std::sort (keys.begin(), keys.end());
  os << "{{";
  for (auto& it : keys) {
      auto p = *m.find(it);
      if(!is_default_value(p.second))
        os << "\t" << p.first << " -> " << p.second << "\n";
  }
  os << "}}";
}

template <typename K>
const std::map<K, double> &mult_dps(const double &d,
                                    const std::map<K, double> &m2, std::map<K, double> *resAddress)
{
  std::map<K, double> &res = *resAddress;
  for (const std::pair<K, double> &p : m2)
  {
    res[p.first] = d * p.second;
  }
  return *resAddress;
}

template <typename K, typename V>
const std::map<K, V> &mult_dps(const double &d,
                               const std::map<K, V> &m2, std::map<K, V> *resAddress)
{
  std::map<K, V> &res = *resAddress;
  for (const std::pair<K, V> &p : m2)
  {
    // res[p.first] = d * p.second;
    mult_dps(d, p.second, &res[p.first]);
  }
  return *resAddress;
}

template <typename K, typename V>
const std::map<K, V> &mult_dps(const std::map<K, V> &m1,
                               const double &d, std::map<K, V> *resAddress)
{
  return mult_dps(d, m1, resAddress);
}

template <typename K, typename V>
const std::map<K, V> &operator*(const double &d,
                                const std::map<K, V> &m2)
{
  std::map<K, V> *resAddress = new std::map<K, V>();
  std::map<K, V> &res = *resAddress;
  for (const std::pair<K, V> &p : m2)
  {
    res[p.first] = d * p.second;
  }
  return *resAddress;
}

template <typename K, typename V>
const std::unordered_map<K, V> &operator*(const double &d,
                                          const std::unordered_map<K, V> &m2)
{
  std::unordered_map<K, V> *resAddress = new std::unordered_map<K, V>();
  std::unordered_map<K, V> &res = *resAddress;
  for (const std::pair<K, V> &p : m2)
  {
    res[p.first] = d * p.second;
  }
  return *resAddress;
}

template <typename K, size_t V>
const std::array<K, V> &operator*(const double &d,
                                  const std::array<K, V> &m2)
{
  std::array<K, V> *resAddress = new std::array<K, V>();
  std::array<K, V> &res = *resAddress;
  for (int i = 0; i < V; i++)
  {
    res[i] = d * m2[i];
  }
  return *resAddress;
}

template <typename K, size_t s1, size_t s2>
inline void copy_subarray(std::array<K, s1> &arr1, const std::array<K, s2> &arr2, const int &pos)
{
  for (int i = 0; i < s2; i++)
  {
    arr1[pos * s2 + i] = arr2[i];
  }
}

template <typename K, typename V>
const std::map<K, V> &operator*(const std::map<K, V> &m1,
                                const double &d)
{
  return d * m1;
}

template <typename K, typename V>
const std::unordered_map<K, V> &operator*(const std::unordered_map<K, V> &m1,
                                          const double &d)
{
  return d * m1;
}

template <typename K, size_t V>
const std::array<K, V> &operator*(const std::array<K, V> &m1,
                                  const double &d)
{
  return d * m1;
}

template <typename K, typename V>
const std::map<K, V> &operator*(const std::map<K, V> &m1,
                                const std::map<K, V> &m2)
{
  std::map<K, V> *resAddress = new std::map<K, V>();
  std::map<K, V> &res = *resAddress;
  for (const std::pair<K, V> &p : m1)
  {
    res[p.first] = p.second * m2.at(p.first);
  }
  return *resAddress;
}

template <typename K, typename V>
const std::unordered_map<K, V> &operator*(const std::unordered_map<K, V> &m1,
                                          const std::unordered_map<K, V> &m2)
{
  std::unordered_map<K, V> *resAddress = new std::unordered_map<K, V>();
  std::unordered_map<K, V> &res = *resAddress;
  for (const std::pair<K, V> &p : m1)
  {
    res[p.first] = p.second * m2.at(p.first);
  }
  return *resAddress;
}

template <typename K, size_t V>
const std::array<K, V> &operator*(const std::array<K, V> &m1,
                                  const std::array<K, V> &m2)
{
  std::array<K, V> *resAddress = new std::array<K, V>();
  std::array<K, V> &res = *resAddress;
  for (int i = 0; i < V; i++)
  {
    res[i] = m1[i] * m2[i];
  }
  return *resAddress;
}

template<typename M>
inline void update_map(M &m1, const M &m2) ;

template <typename... T>
inline void operator+=(std::tuple<T...>& x, const std::tuple<T...>& y);

#define UPDATE_MAP(DICT_TYPE)                                                  \
template <typename K, typename V>                                              \
void operator+=(DICT_TYPE<K, V> &m1,                                           \
                const DICT_TYPE<K, V> &m2)                                     \
{                                                                              \
  update_map(m1, m2);                                                          \
}

DEFINE_FOR_MAPS(UPDATE_MAP);

template <typename... T>
inline void operator+=(std::tuple<T...>& x, const std::tuple<T...>& y) {
  auto f = [&](auto& a, auto& b) { a += b; };
  for_each_in_2tuple(x, y, f);
}

template <typename K, size_t N>
void operator+=(std::array<K, N> &m1,
                const std::array<K, N> &m2)
{
  for (int i = 0; i < N; i++)
  {
    m1[i] += m2[i];
  }
}

template <typename K>
void operator+=(std::vector<K> &m1,
                const std::vector<K> &m2)
{
  for (int i = 0; i < m2.size(); i++)
  {
    m1[i] += m2[i];
  }
}

template<typename M>
inline void update_map(M &m1, const M &m2)
{
  for (auto &p : m2)
  {
    m1[p.first] += p.second;
  }
}

template <class M, class K, class V>
inline void update(M& m, const K&k, const V & dv ) {
  // auto it = m.find( k );
  // typename M::iterator iter = it;
  auto iter = m.find( k );
  if ( iter == m.end() ) {
    m.emplace(k, dv);
  }
  else {
    const_cast<V&>(iter->second) += dv;
  }
}

template <class M, class K, class V>
inline typename M::iterator& update_hint(M& m, typename M::iterator& iter, const K&k, const V & dv ) {
  auto oldIter = iter;
  auto end = m.end(); 
  while(end != iter && iter->first < k) {
    iter++;
  }
  if(end != iter && iter->first == k) {
    iter->second += dv;
  } else {
    iter = m.emplace_hint(iter, k, dv);
  }
  return iter;
}

template <class M, class K, class V>
inline typename M::iterator& update_hint_vec(M& m, typename M::iterator& iter, const K&k, const V& dv ) {
  auto oldIter = iter;
  auto end = m.end(); 
  while(end != iter && iter->first < k) {
    iter++;
  }
  if(end != iter && iter->first == k) {
    iter->second.push_back(dv);
  } else {
    iter = m.emplace_hint(iter, k, (std::vector<V>){dv});
  }
  return iter;
}

template <typename V>
// using field_dict = std::map<field_t, V>;
// using field_dict = std::map<int, V>;
using field_dict = std::vector<V>;

template <typename V>
using field_dict2 = field_dict<field_dict<V>>;

typedef std::map<field_t, int> field_dict_ind;

template <typename K, typename V>
class MyBag
{
  typedef MyMap<K, V> map_type;

  map_type underlying;

  bool operator==(const MyBag<K, V> &other) const
  {
    return underlying == other.underlying;
  }

  MyBag<K, V> &operator+(const MyBag<K, V> &other) const
  {
    return *this;
  }
};

template <typename K>
class hot_type;

// vector<hot_type<int>*> pool;
hot_type<int> *pool;
int pool_ind;
int all_aloc;

template <typename K>
hot_type<K> *alloc_hot()
{
  const int N = 100000;
  if (pool_ind == 0 || pool_ind == N)
  {
    pool_ind = 0;
    // pool.clear();
    hot_type<K> *tmp_pool = new hot_type<K>[N];
    // for(int i = 0; i < N; i++) {
    //   // pool.push_back((hot_type<int>*)new hot_type<K>());
    //   pool.push_back((hot_type<int>*)&tmp_pool[i]);
    // }
    pool = tmp_pool;
  }
  hot_type<K> *tmp_pool = pool;
  all_aloc++;
  return (hot_type<K> *)&tmp_pool[pool_ind++];
  // return new hot_type<K>();
}

template <typename K>
class hot_type
{
  typedef pair<K, double> pair_type;
  typedef map<K, double> und_type;
  // typedef unordered_map<K, double>  und_type;

public:
  bool isSingleton;
  pair_type undPair;
  und_type underlying;
  hot_type(const K &v)
  {
    // underlying = v;
    isSingleton = true;
    undPair = {v, 1};
    // underlying[v] = 1;
  }
  hot_type()
  {
    isSingleton = true;
  }
  void copyFrom(const hot_type<K> &other)
  {
    // underlying = other.underlying;
    isSingleton = other.isSingleton;
    if (isSingleton)
      undPair = other.undPair;
    else
      underlying = other.underlying;
  }
  bool operator==(const hot_type<K> &other) const
  {
    return underlying == other.underlying;
  }
  bool operator!=(const hot_type<K> &other) const
  {
    return !(*this == other);
  }
  bool operator<(const hot_type<K> &other) const
  {
    // return underlying < other.underlying;
    if (isSingleton)
    {
      return undPair < other.undPair;
    }
    return false;
  }
  hot_type<K> &operator*(const int &a) const
  {
    // hot_type<K>* res = new hot_type<K>(underlying * a);
    // return *res;
    return (*this) * ((double)a);
  }
  hot_type<K> &operator*(const double &a) const
  {
    // hot_type<K>* res = new hot_type<K>(underlying * a);
    // ---
    hot_type<K> *res = alloc_hot<K>();
    // hot_type<K>* res = (hot_type<K>*)bulk_alloc(sizeof(hot_type<K>));
    // hot_type<K>* res = new hot_type<K>();
    // hot_type<K>* res = const_cast<hot_type<K>*>(this);
    res->copyFrom(*this);
    // for (const std::pair<K,double>& p: res->underlying) {
    //   res->underlying[p.first] = p.second * a;
    // }
    if (res->isSingleton)
    {
      res->undPair.second *= a;
    }
    else
    {
      for (const std::pair<K, double> &p : res->underlying)
      {
        res->underlying[p.first] = p.second * a;
      }
    }
    return *res;
    // return const_cast<hot_type<K>&>(*this);
  }
  hot_type<K> &operator*(const hot_type<K> &a) const
  {
    assert(isSingleton || a.isSingleton);

    if (isSingleton && a.isSingleton)
    {
      hot_type<K> *res = alloc_hot<K>();
      if (undPair.first == a.undPair.first)
      {
        res->undPair = {undPair.first, undPair.second * a.undPair.second};
      }
      else
      {
        // empty
      }
      return *res;
    }
    else if (isSingleton && !a.isSingleton)
    {
      hot_type<K> *res = alloc_hot<K>();
      if (a.underlying.count(undPair.first) != 0)
      {
        res->undPair = undPair;
        res->undPair.second *= a.underlying.at(undPair.first);
      }
      else
      {
        // empty
      }
      return *res;
    }
    else
    { // if a.isSingleton
      return a * (*this);
    }
    // hot_type<K>* res = new hot_type<K>(underlying * a);
    // ---
    // hot_type<K>* res = alloc_hot<K>();
    // hot_type<K>* res = (hot_type<K>*)bulk_alloc(sizeof(hot_type<K>));
    // hot_type<K>* res = new hot_type<K>();
    // hot_type<K>* res = const_cast<hot_type<K>*>(this);
    // res->copyFrom(*this);
    // // for (const std::pair<K,double>& p: a.underlying) {
    // //   if(underlying.count(p.first) != 0)
    // //     res->underlying[p.first] = underlying.at(p.first) * p.second;
    // // }
    // if(res->isSingleton && a.isSingleton) {
    //   res->undPair.second *= a.undPair.second;
    // } else {
    //   // for (const std::pair<K,double>& p: a.underlying) {
    //   //   if(underlying.count(p.first) != 0)
    //   //     res->underlying[p.first] = underlying.at(p.first) * p.second;
    //   // }
    //   cout << "err" << endl;
    // }

    // return *res;
    // return const_cast<hot_type<K>&>(*this);
  }
  void operator+=(const hot_type<K> &a)
  { //underlying += a.underlying;
    // for (const std::pair<K,double>& p: a.underlying) {
    //   underlying[p.first] += p.second;
    // }
    if (isSingleton && a.isSingleton)
    {
      if (undPair.first == a.undPair.first)
      {
        undPair.second += a.undPair.second;
      }
      else
      {
        isSingleton = false;
        underlying[undPair.first] = undPair.second;
        underlying[a.undPair.first] = a.undPair.second;
      }
    }
    else if (isSingleton && !a.isSingleton)
    {
      copyFrom(a);
      (*this) += undPair;
    }
    else if (!isSingleton && a.isSingleton)
    {
      (*this) += a.undPair;
    }
    else
    {
      assert(!isSingleton && !a.isSingleton);
      for (const std::pair<K, double> &p : a.underlying)
      {
        underlying[p.first] += p.second;
      }
    }
  }

  void operator+=(const pair_type &a)
  {
    assert(!isSingleton);
    // if(underlying.count(a.first) == 0) {
    //   underlying[a.first] = a.second;
    // } else {
    underlying[a.first] += a.second;
    // }
  }
};

template <typename K>
std::ostream &operator<<(std::ostream &os,
                         const hot_type<K> &m)
{
  // os << "{{" << m.underlying << "}}";
  if (m.isSingleton)
  {
    const std::pair<K, double> &p = m.undPair;
    os << "{" << p.first << ": " << p.second << "}";
  }
  else
  {
    for (const std::pair<K, double> &p : m.underlying)
    {
      os << "{" << p.first << ": " << p.second << "}";
    }
  }
  return os;
}

template <typename K>
hot_type<K> &operator*(const int a,
                       const hot_type<K> &b)
{
  return b * a;
}

template <typename K>
hot_type<K> &operator*(const double a,
                       const hot_type<K> &b)
{
  return b * a;
}

template <typename K, size_t size>
std::ostream &operator<<(std::ostream &os,
                         const std::array<K, size> &arr)
{
  for (auto const &ele : arr)
    os << ele << ", ";
  return os;
}

template <typename T, size_t A, size_t B, size_t D>
inline void mult_array(const std::array<T, A> &a,
                       const std::array<T, B> &b,
                       std::array<T, D> &c,
                       const std::array<int, D> &posA,
                       const std::array<int, D> &posB)
{
  int pos = 0;
  for (int i = 0; i <D; i++)
  {
    c[pos++] = a[posA[i]] * b[posB[i]];
  }
}

template <std::size_t N>
std::bitset<N> operator+(const std::bitset<N> &b1,
                const std::bitset<N> &b2)
{
  return b1 | b2;
}

template <std::size_t N>
void operator+=(std::bitset<N> &b1,
                const std::bitset<N> &b2)
{
  b1 |= b2;
}

template<typename T, std::size_t N, std::size_t M>
std::array<T, N> construct_arr(
  const std::array<std::size_t, M>& idxs,
  const std::array<T, M>& vs
  ){
  std::array<T,N> arr = {};
  for(size_t i=0; i<M; ++i)
  {
    arr[idxs[i]] = vs[i];
  }
  return arr;
}


/** Tuple Handling */
template<typename Type, unsigned N, unsigned Last>
struct tuple_printer {

    static void print(std::ostream& out, const Type& value) {
        out << std::get<N>(value) << ", ";
        tuple_printer<Type, N + 1, Last>::print(out, value);
    }
};

template<typename Type, unsigned N>
struct tuple_printer<Type, N, N> {

    static void print(std::ostream& out, const Type& value) {
        out << std::get<N>(value);
    }

};

template<typename... Types>
inline void print_tuple(std::ostream &out, const std::tuple<Types...>& value) {
  out << "{";
  tuple_printer<std::tuple<Types...>, 0, sizeof...(Types) - 1>::print(out, value);
  out << "}";
}

namespace std{
    namespace
    {

        // Code from boost
        // Reciprocal of the golden ratio helps spread entropy
        //     and handles duplicates.
        // See Mike Seymour in magic-numbers-in-boosthash-combine:
        //     http://stackoverflow.com/questions/4948780

        template <class T>
        inline void hash_combine(std::size_t& seed, T const& v)
        {
            seed ^= std::hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }

        // Recursive template code derived from Matthieu M.
        template <class Tuple, size_t Index = std::tuple_size<Tuple>::value - 1>
        struct HashValueImpl
        {
          static void apply(size_t& seed, Tuple const& tuple)
          {
            HashValueImpl<Tuple, Index-1>::apply(seed, tuple);
            hash_combine(seed, std::get<Index>(tuple));
          }
        };

        template <class Tuple>
        struct HashValueImpl<Tuple,0>
        {
          static void apply(size_t& seed, Tuple const& tuple)
          {
            hash_combine(seed, std::get<0>(tuple));
          }
        };
    }

    template <typename ... TT>
    struct hash<std::tuple<TT...>> 
    {
        size_t
        operator()(std::tuple<TT...> const& tt) const
        {                                              
            size_t seed = 0;                             
            HashValueImpl<std::tuple<TT...> >::apply(seed, tt);    
            return seed;                                 
        }                                              

    };
}