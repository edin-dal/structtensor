


#include <algorithm>
#include <chrono>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <thread>
#include <unordered_map>
#include <map>
#include <vector>
#include <random>
#include <cmath>


#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "ifaq.hpp"
#include "E2E_R.hpp"
#include "IndexMapCategoricalFM.hpp"


namespace qi = boost::spirit::qi;
namespace phoenix = boost::phoenix;
using namespace std::chrono;
using namespace std;

template<class K, class V> using dict_type = robinhood_dict<K, V>;

typedef std::tuple<double,double> Rec363;


const Rec363 Rec363_empty = Rec363();
typedef std::tuple<double,double,double,double,double,double,double,double,double,double,double,double,double,double,double,double> Table364;
Table364 scan_Table364(const std::string& tuple) {
  double zip;
  double population;
  double white;
  double asian;
  double pacific;
  double black;
  double medianage;
  double occupiedhouseunits;
  double houseunits;
  double families;
  double households;
  double husbwife;
  double males;
  double females;
  double householdschildren;
  double hispanic;
  qi::parse(tuple.begin(),tuple.end(), 
    qi::double_[phoenix::ref(zip) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(population) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(white) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(asian) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(pacific) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(black) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(medianage) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(occupiedhouseunits) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(houseunits) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(families) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(households) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(husbwife) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(males) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(females) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(householdschildren) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(hispanic) = qi::_1]);
  
  return Table364(zip, population, white, asian, pacific, black, medianage, occupiedhouseunits, houseunits, families, households, husbwife, males, females, householdschildren, hispanic);
}


typedef std::tuple<double,double,double,double> Table365;
Table365 scan_Table365(const std::string& tuple) {
  double locn;
  double dateid;
  double ksn;
  double inventoryunits;
  qi::parse(tuple.begin(),tuple.end(), 
    qi::double_[phoenix::ref(locn) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(dateid) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(ksn) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(inventoryunits) = qi::_1]);
  
  return Table365(locn, dateid, ksn, inventoryunits);
}


typedef std::tuple<double,double,double,double,double> Table366;
Table366 scan_Table366(const std::string& tuple) {
  double ksn;
  double subcategory;
  double category;
  double categoryCluster;
  double prize;
  qi::parse(tuple.begin(),tuple.end(), 
    qi::double_[phoenix::ref(ksn) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(subcategory) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(category) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(categoryCluster) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(prize) = qi::_1]);
  
  return Table366(ksn, subcategory, category, categoryCluster, prize);
}


typedef std::tuple<Table365,double> Rec367;


const Rec367 Rec367_empty = Rec367();
typedef std::tuple<Table366,double> Rec368;


const Rec368 Rec368_empty = Rec368();
typedef std::tuple<Table364,double> Rec369;


const Rec369 Rec369_empty = Rec369();
typedef std::tuple<double,double,double,double,double,double,double,double,double,double,double,double,double,double,double> Table370;
Table370 scan_Table370(const std::string& tuple) {
  double locn;
  double zip;
  double rgn_cd;
  double clim_zn_nbr;
  double tot_area_sq_ft;
  double sell_area_sq_ft;
  double avghhi;
  double supertargetdistance;
  double supertargetdrivetime;
  double targetdistance;
  double targetdrivetime;
  double walmartdistance;
  double walmartdrivetime;
  double walmartsupercenterdistance;
  double walmartsupercenterdrivetime;
  qi::parse(tuple.begin(),tuple.end(), 
    qi::double_[phoenix::ref(locn) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(zip) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(rgn_cd) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(clim_zn_nbr) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(tot_area_sq_ft) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(sell_area_sq_ft) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(avghhi) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(supertargetdistance) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(supertargetdrivetime) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(targetdistance) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(targetdrivetime) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(walmartdistance) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(walmartdrivetime) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(walmartsupercenterdistance) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(walmartsupercenterdrivetime) = qi::_1]);
  
  return Table370(locn, zip, rgn_cd, clim_zn_nbr, tot_area_sq_ft, sell_area_sq_ft, avghhi, supertargetdistance, supertargetdrivetime, targetdistance, targetdrivetime, walmartdistance, walmartdrivetime, walmartsupercenterdistance, walmartsupercenterdrivetime);
}


typedef std::tuple<Table370,double> Rec371;


const Rec371 Rec371_empty = Rec371();
typedef std::tuple<double,double,double,double,double,double,double,double> Table372;
Table372 scan_Table372(const std::string& tuple) {
  double locn;
  double dateid;
  double rain;
  double snow;
  double maxtemp;
  double mintemp;
  double meanwind;
  double thunder;
  qi::parse(tuple.begin(),tuple.end(), 
    qi::double_[phoenix::ref(locn) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(dateid) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(rain) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(snow) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(maxtemp) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(mintemp) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(meanwind) = qi::_1]>>'|'>>
    qi::double_[phoenix::ref(thunder) = qi::_1]);
  
  return Table372(locn, dateid, rain, snow, maxtemp, mintemp, meanwind, thunder);
}


typedef std::tuple<Table372,double> Rec373;


const Rec373 Rec373_empty = Rec373();
std::vector<Table365> InventoryTrain;
std::vector<Table365> InventoryTest;
std::vector<Table370> Location;
std::vector<Table364> Census;
std::vector<Table366> Item;
std::vector<Table372> Weather;


void loadRelations() {
  std::ifstream input;
  std::string line;
  
  
  InventoryTrain.clear();
  input.open("datasets/retailer/Inventory_100k.tbl");
  if (!input)
  {
    std::cerr << "datasets/retailer/Inventory_.tbl does not exist." << std::endl;
    exit(1);
  }
  while(getline(input, line))
    InventoryTrain.push_back(scan_Table365(line));
  
    
  input.close();


  InventoryTest.clear();
  input.open("datasets/retailer/Inventory_test.tbl");
  if (!input)
  {
    std::cerr << "datasets/retailer/Inventory_test.tbl does not exist." << std::endl;
    exit(1);
  }
  while(getline(input, line))
    InventoryTest.push_back(scan_Table365(line));
  
    
  input.close();
  
  
  
  Location.clear();
  input.open("datasets/retailer/Location_norm.tbl");
  if (!input)
  {
    std::cerr << "datasets/retailer/Location_norm.tbl does not exist." << std::endl;
    exit(1);
  }
  while(getline(input, line))
    Location.push_back(scan_Table370(line));
  
    
  input.close();
  
  
  
  Census.clear();
  input.open("datasets/retailer/Census_norm.tbl");
  if (!input)
  {
    std::cerr << "datasets/retailer/Census_norm.tbl does not exist." << std::endl;
    exit(1);
  }
  while(getline(input, line))
    Census.push_back(scan_Table364(line));
  
    
  input.close();
  
  
  
  Item.clear();
  input.open("datasets/retailer/Item_norm.tbl");
  if (!input)
  {
    std::cerr << "datasets/retailer/Item_norm.tbl does not exist." << std::endl;
    exit(1);
  }
  while(getline(input, line))
    Item.push_back(scan_Table366(line));
  
    
  input.close();
  
  
  
  Weather.clear();
  input.open("datasets/retailer/Weather_norm.tbl");
  if (!input)
  {
    std::cerr << "datasets/retailer/Weather_norm.tbl does not exist." << std::endl;
    exit(1);
  }
  while(getline(input, line))
    Weather.push_back(scan_Table372(line));
  
    
  input.close();
   
  
}


void indexRelations() {
  
  
}


int64_t endProcess;
int64_t processTime, updateTime, multTime, indexMapTime;
int64_t startMult, endMult;
int64_t startIndexMap, endIndexMap;
void computeGroups(RingCofactor<double,13,0>& res1, IndexMap<13, 0>& res2) { ////
  multTime = 0;
  dict_type<Rec363, RingCofactor<double,3,0>> x353;
  for(auto const& x309 : Weather) {
    const Table372& x310 = x309;
    const double x311 = std::get<0>(x310) /* ...locn */;
    const double x312 = std::get<1>(x310) /* ...dateid */;
    const Rec363& x313 = (Rec363){ x311, x312 };
    const double x314 = std::get<2>(x310) /* ...rain */;
    const double x3143 = std::get<3>(x310);
    const double x3144 = std::get<4>(x310);
    // const double x3145 = std::get<5>(x310);
    // const double x3146 = std::get<6>(x310);
    // const double x3147 = std::get<7>(x310);
    startMult = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    const RingCofactor<double,3,0>& x315 = Uliftcont(x314, x3143, x3144);//, x3145, x3146, x3147);
    endMult = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    multTime += endMult - startMult;
    update( x353, x313, (x315) );;; 
  }
  ;

  const dict_type<Rec363, RingCofactor<double,3,0>>& x316 = /* read_ref */ x353;
  dict_type<double, RingCofactor<double,1,0>> x355; ////
  RingCofactor<double,1,0> x321;
  for(auto const& x317 : Item) {
    const Table366& x318 = x317;
    const double x319 = std::get<0>(x318) /* ...ksn */;
    // const long xx319 = std::get<1>(x318) /* ...subcat */;
    // const long xx320 = std::get<2>(x318) /* ...cat */;
    // const long xxx320 = std::get<3>(x318) /* ...categorycluster */;
    const double x320 = std::get<4>(x318) /* ...prize */;
    startMult = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    const RingCofactor<double,1,0>& xx321 = Uliftcont(x320); ////
    // const RingCofactor<double,0,2>& xx322 = Uliftcat(subcat_map.find(xx319)->second, cat_map.find(xx320)->second); ////
    // const RingCofactor<double,0,3>& xx322 = Uliftcat(xx319, xx320, xxx320); ////
    // x321.clean();
    // xx321.multiplyDPS(xx322, x321);
    endMult = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    multTime += endMult - startMult;
    update( x355, x319, (xx321) );;; 
  }
  ;
  const dict_type<double, RingCofactor<double,1,0>>& x322 = /* read_ref */ x355; ////
  dict_type<double, RingCofactor<double,5,0>> x357;
  for(auto const& x323 : Census) {
    const Table364& x324 = x323;
    const double x325 = std::get<0>(x324) /* ...zip */;
    const double x326 = std::get<1>(x324) /* ...population */;
    const double x3262 = std::get<2>(x324);
    const double x3263 = std::get<3>(x324);
    const double x3264 = std::get<4>(x324);
    const double x3265 = std::get<5>(x324);
    // const double x3266 = std::get<6>(x324);
    // const double x3267 = std::get<7>(x324);
    // const double x3268 = std::get<8>(x324);
    // const double x3269 = std::get<9>(x324);
    // const double x32610 = std::get<10>(x324);
    // const double x32611 = std::get<11>(x324);
    // const double x32612 = std::get<12>(x324);
    // const double x32613 = std::get<13>(x324);
    // const double x32614 = std::get<14>(x324);
    // const double x32615 = std::get<15>(x324);
    startMult = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    const RingCofactor<double,5,0>& x327 = Uliftcont(x326, x3262, x3263, x3264, x3265);//, x3266, x3267, x3268);//, x3269, x32610, x32611, x32612, x32613, x32614, x32615);
    // std::cout << x327 << std::endl;
    endMult = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    multTime += endMult - startMult;
    update( x357, x325, (x327) );;; 
  }
  ;
  int cc = 0;
  const dict_type<double, RingCofactor<double,5,0>>& x328 = /* read_ref */ x357;
  dict_type<double, RingCofactor<double,9,0>> x359;
  RingCofactor<double,9,0> xx336;
  // std::cout << xx336 << std::endl;
  RingCofactor<double,9,0> x336;
  for(auto const& x329 : Location) {
    const Table370& x330 = x329;
    const double x331 = std::get<0>(x330) /* ...locn */;
    const double x332 = std::get<4>(x330) /* ...tot_area_sq_ft */;
    const double x334 = std::get<1>(x330) /* ...zip */;
    // const double xx3321 = std::get<2>(x330) /* ...regioncode */;
    // const double xx3322 = std::get<3>(x330) /* ...climate_zone */;
    const double xx3325 = std::get<5>(x330);
    const double xx3326 = std::get<6>(x330);
    const double xx3327 = std::get<7>(x330);
    // const double xx3328 = std::get<8>(x330);
    // const double xx3329 = std::get<9>(x330);
    // const double xx33210 = std::get<10>(x330);
    // const double xx33211 = std::get<11>(x330);
    // const double xx33212 = std::get<12>(x330);
    // const double xx33213 = std::get<13>(x330);
    // const double xx33214 = std::get<14>(x330);
    const RingCofactor<double,5,0>& x335 = get_or_else(x328, x334, Type<RingCofactor<double,5,0>>::Default);
    // auto it = x328.find( x334 );
    // if ( it == x328.end() ) {
    //     std::cout << "OUT: " << std::endl;
    // }
    startMult = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    const RingCofactor<double,4,0>& x333 = Uliftcont(x332, xx3325, xx3326, xx3327);//, xx3328, xx3329, xx33210);//, xx33211, xx33212, xx33213, xx33214);
    endMult = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    multTime += endMult - startMult;
    // std::cout << x335 << std::endl;
    // const RingCofactor<double,0,2>& xx333 = Uliftcat(xx3321, xx3322);
    // std::cout << ++cc << std::endl;
    xx336.clean();
    // std::cout << xx336 << std::endl;
    // std::cout << ++cc << std::endl;
    startMult = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    x333.multiplyDPS(x335, xx336);
    // std::cout << ++cc << std::endl;
    // delete &x335;
    // delete &x333;
    // x336.clean();
    // xx336.multiplyDPS(xx333, x336);
    endMult = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    multTime += endMult - startMult;
    update( x359, x331, (xx336) );;; 
  }
  ;
  const dict_type<double, RingCofactor<double,9,0>>& x337 = /* read_ref */ x359;
  int cnt = 0;
  int64_t startUpdate, endUpdate;
  updateTime = 0;
  RingCofactor<double,13,0> x361; ////
  RingCofactor<double, 13,0> x348;
  RingCofactor<double,4,0> x346;
  RingCofactor<double,13,0> x351;
  std::ofstream ofs;
  ofs.open("ifaq_output.txt");
  ofs << std::fixed << std::setprecision(2);
  for(auto const& x338 : InventoryTrain) {
    const Table365& x339 = x338;
    const double x340 = std::get<0>(x339) /* ...locn */;
    const double x341 = std::get<1>(x339) /* ...dateid */;
    const Rec363& x342 = (Rec363){ x340, x341 };
    const RingCofactor<double,3,0>& x343 = get_or_else(x316, x342, Type<RingCofactor<double,3,0>>::Default);
    // ofs << "x343: " << std::endl;
    // ofs << x343 << std::endl;
    const double x344 = std::get<2>(x339) /* ...ksn */;
    const RingCofactor<double,1,0>& x345 = get_or_else(x322, x344, Type<RingCofactor<double,1,0>>::Default); ////
    // ofs << "x345: " << std::endl;
    // ofs << x345 << std::endl;
    const RingCofactor<double,9,0>& x347 = get_or_else(x337, x340, Type<RingCofactor<double,9,0>>::Default);
    // auto it = x337.find( x340 );
    // if ( it == x337.end() ) {
    //     std::cout << "OUT: " << std::endl;
    // }
    // ofs << "x347: " << std::endl;
    // ofs << x347 << std::endl;
    const double x349 = std::get<3>(x339) /* ...inventoryunits */;
    // startMult = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    x346.clean();
    startMult = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    x343.multiplyDPS(x345, x346);
    endMult = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    multTime += endMult - startMult;
    // ofs << "x346: " << std::endl;
    // ofs << x346 << std::endl;
    x348.clean();
    startMult = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    x346.multiplyDPS(x347, x348); ////
    endMult = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    multTime += endMult - startMult;
    // ofs << "x348: " << std::endl;
    // ofs << x348 << std::endl;
    // const Target<double>& x350 = TargetCovar(x349);
    // x351.clean();
    // x348.multiplyDPS(x350, x351);
    // endMult = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    // multTime += endMult - startMult;
    // std::cout << cnt << std::endl;
    startUpdate = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    // x361 += x351; /* RingCofactor<double,5> */;;
    // x361.peqInplace(x351); 
    x361.peqInplace(x348); 
    endUpdate = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    updateTime += endUpdate - startUpdate;
    // cnt++;
    // std::cout << cnt << std::endl;
    // if (cnt == 10)
    //   break;
    // delete &x343;
    // delete &x345;
    // delete &x347;
  }
  ;
  const RingCofactor<double,13,0>& x352 = /* read_ref */ x361; ////
  // startIndexMap = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  // const IndexMap<1, 0>& indexMap1 = IndexCovar<1, 0>();
  // // const IndexMap<0, 3>& indexMap2 = IndexCovar<0, 3>();
  // // const IndexMap<1, 3>& indexMap12 = indexMap1 * indexMap2;
  // const IndexMap<6, 0>& indexMap3 = IndexCovar<6, 0>();
  // const IndexMap<7, 0>& indexMap312 = indexMap3 * indexMap1;
  // const IndexMap<11, 0>& indexMap4 = IndexCovar<11, 0>();
  // const IndexMap<15, 0>& indexMap5 = IndexCovar<15, 0>();
  // const IndexMap<26, 0>& indexMap45 = indexMap4 * indexMap5;
  // // const IndexMap<0, 2>& indexMap6 = IndexCovar<0, 2>();
  // // const IndexMap<26, 2>& indexMap456 = indexMap45 * indexMap6;
  // const IndexMap<33, 0>& indexMap = indexMap312 * indexMap45;
  // endIndexMap = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  // indexMapTime = endIndexMap - startIndexMap;
  /* x352 */;

  res1 = x352;
  // res1.finished();
  // res2 = indexMap;
  endProcess = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

  // std::cout << "writing output to `ifaq_output.txt`." << std::endl;
  // std::ofstream ofs;
  // ofs.open("ifaq_output.txt");
  // ofs << std::fixed << std::setprecision(2);
  // res1.reconstruct();
  ofs << res1 << std::endl;
  ofs.close();

  // delete &x352;
  // delete &x361;

  // std::ofstream ofs3;
  // ofs3.open("indexMap1.txt");
  // ofs3 << indexMap1 << std::endl;
  // ofs3.close();

  // std::ofstream ofs4;
  // ofs4.open("indexMap2.txt");
  // ofs4 << indexMap2 << std::endl;
  // ofs4.close();

  // std::ofstream ofs5;
  // ofs5.open("indexMap12.txt");
  // ofs5 << indexMap12 << std::endl;
  // ofs5.close();

  // std::ofstream ofs6;
  // ofs6.open("indexMap3.txt");
  // ofs6 << indexMap3 << std::endl;
  // ofs6.close();

  // std::ofstream ofs7;
  // ofs7.open("indexMap312.txt");
  // ofs7 << indexMap312 << std::endl;
  // ofs7.close();

  // std::ofstream ofs8;
  // ofs8.open("indexMap4.txt");
  // ofs8 << indexMap4 << std::endl;
  // ofs8.close();

  // std::ofstream ofs9;
  // ofs9.open("indexMap5.txt");
  // ofs9 << indexMap5 << std::endl;
  // ofs9.close();

  // std::ofstream ofs10;
  // ofs10.open("indexMap45.txt");
  // ofs10 << indexMap45 << std::endl;
  // ofs10.close();

  // std::ofstream ofs2;
  // ofs2.open("indexMap.txt");
  // ofs2 << indexMap << std::endl;
  // ofs2.close();

  // size_t SZ = 4;
  // std::cout << std::fixed;
  // std::cout << std::setprecision(2);
  // for (size_t i = 0; i < SZ; i++) {
  //   std::cout << "C[" << i << "] = " << x352.C(i) << "\n";
  // }
  // for (size_t i = 0; i < SZ; i++) {
  //   for (size_t j = 0; j < SZ; j++) {
  //     if (i == j) continue;
  //     std::cout << "D[" << i << "," << j << "] = " << x352.D(indexMap.degree2Indices(), i, j) << "\n";
  //   }
  // }
  // for (size_t i = 0; i < SZ; i++) {
  //   for (size_t j = 0; j < SZ; j++) {
  //     std::cout << "M[" << i << "," << j << "] = " << x352.M(indexMap.degree2Indices(), i, j) << "\n";
  //   }
  // }
  // for (size_t i = 0; i < SZ; i++) {
  //   for (size_t j = 0; j < SZ; j++) {
  //     for (size_t k = 0; k < SZ; k++) {
  //       if (j == k) continue;
  //       std::cout << "N[" << i << "," << j << "," << k << "] = " << x352.N(indexMap.degree3Indices(), i, j, k) << "\n";
  //     }
  //   }
  // }
  // for (size_t i = 0; i < SZ; i++) {
  //   for (size_t j = 0; j < SZ; j++) {
  //     for (size_t k = 0; k < SZ; k++) {
  //       for (size_t l = 0; l < SZ; l++) {
  //         if ((i == j && i == k) || (i == j && i == l) || (j == k && j == l) || (i == k && i == l)) continue;
  //         std::cout << "O[" << i << "," << j << "," << k << "," << l << "] = " << x352.O(indexMap.degree4Indices(), indexMap.degree2Indices(), i, j, k, l) << "\n";
  //       }
  //     }
  //   }
  // }

  // std::get<0>(res) = x352;
  // std::get<1>(res) = indexMap;
  // *res = std::make_tuple(x352, indexMap);
}

int64_t processPredict;

template <size_t CONT_SZ, size_t CAT_SZ, size_t VEC_LEN>
void predict(double cont_theta[CONT_SZ], std::vector<double> cat_theta[CAT_SZ], double cont_omega[CONT_SZ][VEC_LEN], std::vector<double> cat_omega[CAT_SZ][VEC_LEN], const RingCofactor<double, CONT_SZ, CAT_SZ>& cofactor, const std::map<std::array<size_t, 2>, size_t>& indexMap) { 
  std::ofstream ofs("predictions_CONT_SZ=" + std::to_string(CONT_SZ) + "_CAT_SZ=" + std::to_string(CAT_SZ) + "_VEC_LEN=" + std::to_string(VEC_LEN) + ".txt");
  processPredict = 0;
  int64_t endPredict;
  int64_t startPredict = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  double cont_vee[CONT_SZ][CONT_SZ], tmp;
  std::map<size_t, double> cont_cat_vee[CONT_SZ][CAT_SZ];
  std::map<std::pair<size_t, size_t>, double> cat_vee[CAT_SZ][CAT_SZ];
  for (size_t i = 0; i < CONT_SZ; i++) {
    for (size_t j = i + 1; j < CONT_SZ; j++) {
      cont_vee[i][j] = 0;
      for (size_t f = 0; f < VEC_LEN; f++) {
        cont_vee[i][j] += cont_omega[i][f] * cont_omega[j][f];
      }
    }
  }

  for (size_t i = 0; i < CONT_SZ; i++) {
    for (size_t j = 0; j < CAT_SZ; j++) {
      size_t cat_omega_j_size = cat_omega[j][0].size(); // cat_omega[j][f].size(); is the same for all f values
      for (size_t s = 0; s < cat_omega_j_size; s++) {
        tmp = 0;
        for (size_t f = 0; f < VEC_LEN; f++) {
          tmp += cont_omega[i][f] * cat_omega[j][f][s];
        }
        cont_cat_vee[i][j][s] = tmp;
      }
    }
  }

  for (size_t i = 0; i < CAT_SZ; i++) {
    size_t cat_omega_i_size = cat_omega[i][0].size();
    for (size_t j = i + 1; j < CAT_SZ; j++) {
      size_t cat_omega_j_size = cat_omega[j][0].size();
      for (size_t s = 0; s < cat_omega_i_size; s++) {
        for (size_t t = 0; t < cat_omega_j_size; t++) {
          tmp = 0;
          for (size_t f = 0; f < VEC_LEN; f++) {
            tmp += cat_omega[i][f][s] * cat_omega[j][f][t];
          }
          cat_vee[i][j][std::make_pair(s, t)] = tmp;
        }
      }
    }
  }
  

  dict_type<Rec363, std::array<double, 6>> x353;
  for(auto const& x309 : Weather) {
    const Table372& x310 = x309;
    const double x311 = std::get<0>(x310) /* ...locn */;
    const double x312 = std::get<1>(x310) /* ...dateid */;
    const Rec363& x313 = (Rec363){ x311, x312 };
    const double x3142 = std::get<2>(x310) /* ...rain */;
    const double x3143 = std::get<3>(x310);
    const double x3144 = std::get<4>(x310);
    const double x3145 = std::get<5>(x310);
    const double x3146 = std::get<6>(x310);
    const double x3147 = std::get<7>(x310);
    const std::array<double, 6> x314 = {x3142, x3143, x3144, x3145, x3146, x3147};
    update( x353, x313, (x314) );;; 
  }
  ;
  const dict_type<Rec363, std::array<double, 6>>& x316 = /* read_ref */ x353;
  dict_type<double, double> x355;
  dict_type<double, std::array<long, 3>> xx355;
  for(auto const& x317 : Item) {
    const Table366& x318 = x317;
    const double x319 = std::get<0>(x318) /* ...ksn */;
    const long xx319 = std::get<1>(x318) /* ...subcat */;
    const long xx320 = std::get<2>(x318) /* ...cat */;
    const long xxx320 = std::get<3>(x318) /* ...categorycluster */;
    const double x320 = std::get<4>(x318) /* ...prize */;
    update( x355, x319, x320 );;; 
    const std::array<long, 3> xx336 = {xx319, xx320, xxx320};
    update( xx355, x319, (xx336));
  }
  ;
  const dict_type<double, double>& x322 = /* read_ref */ x355;
  const dict_type<double, std::array<long, 3>>& xx322 = /* read_ref */ xx355;
  dict_type<double, std::array<double, 15>> x357;
  for(auto const& x323 : Census) {
    const Table364& x324 = x323;
    const double x325 = std::get<0>(x324) /* ...zip */;
    const double x3261 = std::get<1>(x324) /* ...population */;
    const double x3262 = std::get<2>(x324);
    const double x3263 = std::get<3>(x324);
    const double x3264 = std::get<4>(x324);
    const double x3265 = std::get<5>(x324);
    const double x3266 = std::get<6>(x324);
    const double x3267 = std::get<7>(x324);
    const double x3268 = std::get<8>(x324);
    const double x3269 = std::get<9>(x324);
    const double x32610 = std::get<10>(x324);
    const double x32611 = std::get<11>(x324);
    const double x32612 = std::get<12>(x324);
    const double x32613 = std::get<13>(x324);
    const double x32614 = std::get<14>(x324);
    const double x32615 = std::get<15>(x324);
    const std::array<double, 15> x326 = {x3261, x3262, x3263, x3264, x3265, x3266, x3267, x3268, x3269, x32610, x32611, x32612, x32613, x32614, x32615};
    update( x357, x325, (x326) );;; 
  }
  ;
  std::array<double, 15> zero15 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  const dict_type<double, std::array<double, 15>>& x328 = /* read_ref */ x357;
  dict_type<double, std::array<double, 26>> x359;
  dict_type<double, std::array<long, 2>> xx359;
  for(auto const& x329 : Location) {
    const Table370& x330 = x329;
    const double x331 = std::get<0>(x330) /* ...locn */;
    const double x332 = std::get<4>(x330) /* ...tot_area_sq_ft */;
    const double x334 = std::get<1>(x330) /* ...zip */;
    const long xx3321 = std::get<2>(x330) /* ...regioncode */;
    const long xx3322 = std::get<3>(x330) /* ...climate_zone */;
    const double xx3325 = std::get<5>(x330);
    const double xx3326 = std::get<6>(x330);
    const double xx3327 = std::get<7>(x330);
    const double xx3328 = std::get<8>(x330);
    const double xx3329 = std::get<9>(x330);
    const double xx33210 = std::get<10>(x330);
    const double xx33211 = std::get<11>(x330);
    const double xx33212 = std::get<12>(x330);
    const double xx33213 = std::get<13>(x330);
    const double xx33214 = std::get<14>(x330);
    const std::array<double, 15> x335 = get_or_else(x328, x334, zero15);
    const std::array<double, 11> x336 = {x332, xx3325, xx3326, xx3327, xx3328, xx3329, xx33210, xx33211, xx33212, xx33213, xx33214};
    std::array<double, 26> x3356;
    for (size_t i = 0; i < 11; i++)
      x3356[i] = x336[i];
    for (size_t i = 0; i < 15; i++)
      x3356[i + 11] = x335[i];
    const std::array<long, 2> xx336 = {xx3321, xx3322};
    update( x359, x331, (x3356) );;; 
    update( xx359, x331, (xx336) );;; 
  }
  ;
  const dict_type<double, std::array<double, 26>>& x337 = /* read_ref */ x359;
  const dict_type<double, std::array<long, 2>>& xx337 = /* read_ref */ xx359;

  const std::array<double, 2> default_value = {0.0, 0.0};
  const std::array<double, 6> zero6 = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const std::array<double, 26> zero26 = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const std::array<long, 2> default_value2 = {-1, -1};
  const std::array<long, 3> default_value3 = {-1, -1, -1};

  // const std::array<double, 3> default_value3 = {0.0, 0, 0};
  endPredict = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
  processPredict += endPredict - startPredict;
  double pred;
  for(auto const& x338 : InventoryTest) {
    startPredict = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    pred = 0.0;
    const Table365& x339 = x338;
    const double x340 = std::get<0>(x339) /* ...locn */;
    const double x341 = std::get<1>(x339) /* ...dateid */;
    const Rec363& x342 = (Rec363){ x340, x341 };
    const std::array<double, 6> x343 = get_or_else(x316, x342, zero6);
    const double x344 = std::get<2>(x339) /* ...ksn */;
    const double x345 = get_or_else(x322, x344, 0.0);
    const std::array<long, 3> xx345 = get_or_else(xx322, x344, default_value3);
    // const std::array<double, 3> x345 = get_or_else(x322, x344, default_value3);
    // const std::array<double, 2> x346 = {x343, x345};
    const std::array<double, 26> x347 = get_or_else(x337, x340, zero26);
    const std::array<long, 2> xx347 = get_or_else(xx337, x340, default_value2);
    std::array<double, 38> x348;
    for (size_t i = 0; i < x343.size(); i++)
      x348[i] = x343[i];
    x348[x343.size()] = x345;
    for (size_t i = 0; i < x347.size(); i++)
      x348[i + x343.size() + 1] = x347[i];
    for (size_t i = 0; i < xx345.size(); i++)
      x348[i + x343.size() + x347.size() + 1] = xx345[i];
    for (size_t i = 0; i < xx347.size(); i++)
      x348[i + x343.size() + x347.size() + xx345.size() + 1] = xx347[i];
    //const double x349 = std::get<3>(x339) /* ...inventoryunits */;
    //const Target<double>& x350 = TargetCovar(x349);/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/
    //const RingCofactor<double,4>& x351 = x348 * x350;
    //x361 += x351; /* RingCofactor<double,5> */;; 
    for (size_t i = 0; i < CONT_SZ; i++) {
      pred += cont_theta[i] * x348[i];
      for (size_t j = i + 1; j < CONT_SZ; j++) {
        pred += cont_vee[i][j] * x348[i] * x348[j];
      }
    }
    for (size_t i = 0; i < CAT_SZ; i++) {
      auto ret = cofactor.cat_mapping[i].find(x348[i + CONT_SZ]);
      if (ret != cofactor.cat_mapping[i].end()) {
        pred += cat_theta[i][ret->second];
        for (size_t j = 0; j < CONT_SZ; j++) {
          pred += cont_cat_vee[j][i][x348[i + CONT_SZ]] * x348[j];
        }
        for (size_t j = i + 1; j < CAT_SZ; j++) {
          pred += cat_vee[i][j][std::make_pair(x348[i + CONT_SZ], x348[j + CONT_SZ])];
        }
      }
    }
    endPredict = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    processPredict += endPredict - startPredict;
    ofs << pred << "\n";
  }
  ;
  ofs.close();
}

// std::vector<size_t> get_indices(const std::vector<size_t> &array) {
//     std::vector<size_t> indices(array.size());
//     std::iota(indices.begin(), indices.end(), 0);
//     std::sort(indices.begin(), indices.end(),
//               [&array](int left, int right) -> bool {
//                   // sort indices according to corresponding array element
//                   return array[left] < array[right];
//               });

//     return indices;
// }

int64_t startBGD;
int64_t endBGD;
int64_t processBGD;

double calcMSE(std::string path) { 
  std::ifstream fin(path, std::ios::in);
  double pred = 0.0, y = 0.0, res = 0.0, size = 0;
  for(auto const& elem : InventoryTest) {
    y = std::get<3>(elem);
    fin >> pred;
    size += 1;
    res += (y - pred) * (y - pred);
  }
  res /= size;
  fin.close();
  return res;
}

double calcRMSE(std::string path, double mse = -1) { 
  if (mse >= 0) return std::sqrt(mse);
  return std::sqrt(calcMSE(path));
}

double calcMAE(std::string path) { 
  std::ifstream fin(path, std::ios::in);
  double pred = 0.0, y = 0.0, res = 0.0, size = 0;
  for(auto const& elem : InventoryTest) {
    y = std::get<3>(elem);
    fin >> pred;
    size += 1;
    res += std::abs(y - pred);
  }
  res /= size;
  fin.close();
  return res;
}

std::string toScientific(double x) {
    int e = floor(log10(x));
    double tenPow = pow(10, e);
    double base = x / tenPow;
    return std::to_string(base) + "e" + std::to_string(e);
}

template<size_t CONT_SZ, size_t CAT_SZ, size_t VEC_LEN>
void prepareStatsFromFile(size_t iter_num) {
  std::string path = "predictions_CONT_SZ=" + std::to_string(CONT_SZ) + "_CAT_SZ=" + std::to_string(CAT_SZ) + "_VEC_LEN=" + std::to_string(VEC_LEN) + ".txt";
  double mse = calcMSE(path);
  double rmse = calcRMSE(path, mse);
  double mae = calcMAE(path);
  std::cout << "iter#: " << iter_num << "\tMSE: " << mse << "\tRMSE: " << rmse << "\tMAE: " << mae << "\tBGD time until now: " << processBGD << "us." << std::endl;
}

template <size_t CONT_SZ, size_t CAT_SZ, size_t VEC_LEN>
void prepareStats(double cont_theta[CONT_SZ], std::vector<double> cat_theta[CAT_SZ], double cont_omega[CONT_SZ][VEC_LEN], std::vector<double> cat_omega[CAT_SZ][VEC_LEN], const RingCofactor<double, CONT_SZ, CAT_SZ>& cofactor, const std::map<std::array<size_t, 2>, size_t>& indexMap, size_t iter_num, std::string mode, double learning_rate) {
  std::string path = "stats/CatFM_" + mode + "_stats_CONT_SZ=" + std::to_string(CONT_SZ) + "_CAT_SZ=" + std::to_string(CAT_SZ) + "_VEC_LEN=" + std::to_string(VEC_LEN) + "_lr=" + toScientific(learning_rate) + ".csv";
  double mse = 0.0, rmse = 0.0, mae = 0.0, size = 0, y = 0;
  double cont_vee[CONT_SZ][CONT_SZ], tmp;
  std::map<size_t, double> cont_cat_vee[CONT_SZ][CAT_SZ];
  std::map<std::pair<size_t, size_t>, double> cat_vee[CAT_SZ][CAT_SZ];
  for (size_t i = 0; i < CONT_SZ; i++) {
    for (size_t j = i + 1; j < CONT_SZ; j++) {
      cont_vee[i][j] = 0;
      for (size_t f = 0; f < VEC_LEN; f++) {
        cont_vee[i][j] += cont_omega[i][f] * cont_omega[j][f];
      }
    }
  }

  for (size_t i = 0; i < CONT_SZ; i++) {
    for (size_t j = 0; j < CAT_SZ; j++) {
      size_t cat_omega_j_size = cat_omega[j][0].size(); // cat_omega[j][f].size(); is the same for all f values
      for (size_t s = 0; s < cat_omega_j_size; s++) {
        tmp = 0;
        for (size_t f = 0; f < VEC_LEN; f++) {
          tmp += cont_omega[i][f] * cat_omega[j][f][s];
        }
        cont_cat_vee[i][j][s] = tmp;
      }
    }
  }

  for (size_t i = 0; i < CAT_SZ; i++) {
    size_t cat_omega_i_size = cat_omega[i][0].size();
    for (size_t j = i + 1; j < CAT_SZ; j++) {
      size_t cat_omega_j_size = cat_omega[j][0].size();
      for (size_t s = 0; s < cat_omega_i_size; s++) {
        for (size_t t = 0; t < cat_omega_j_size; t++) {
          tmp = 0;
          for (size_t f = 0; f < VEC_LEN; f++) {
            tmp += cat_omega[i][f][s] * cat_omega[j][f][t];
          }
          cat_vee[i][j][std::make_pair(s, t)] = tmp;
        }
      }
    }
  }

  dict_type<Rec363, std::array<double, 6>> x353;
  for(auto const& x309 : Weather) {
    const Table372& x310 = x309;
    const double x311 = std::get<0>(x310) /* ...locn */;
    const double x312 = std::get<1>(x310) /* ...dateid */;
    const Rec363& x313 = (Rec363){ x311, x312 };
    const double x3142 = std::get<2>(x310) /* ...rain */;
    const double x3143 = std::get<3>(x310);
    const double x3144 = std::get<4>(x310);
    const double x3145 = std::get<5>(x310);
    const double x3146 = std::get<6>(x310);
    const double x3147 = std::get<7>(x310);
    const std::array<double, 6> x314 = {x3142, x3143, x3144, x3145, x3146, x3147};
    update( x353, x313, (x314) );;; 
  }
  ;
  const dict_type<Rec363, std::array<double, 6>>& x316 = /* read_ref */ x353;
  dict_type<double, double> x355;
  dict_type<double, std::array<long, 3>> xx355;
  for(auto const& x317 : Item) {
    const Table366& x318 = x317;
    const double x319 = std::get<0>(x318) /* ...ksn */;
    const long xx319 = std::get<1>(x318) /* ...subcat */;
    const long xx320 = std::get<2>(x318) /* ...cat */;
    const long xxx320 = std::get<3>(x318) /* ...categorycluster */;
    const double x320 = std::get<4>(x318) /* ...prize */;
    update( x355, x319, x320 );;; 
    const std::array<long, 3> xx336 = {xx319, xx320, xxx320};
    update( xx355, x319, (xx336));
  }
  ;
  const dict_type<double, double>& x322 = /* read_ref */ x355;
  const dict_type<double, std::array<long, 3>>& xx322 = /* read_ref */ xx355;
  dict_type<double, std::array<double, 15>> x357;
  for(auto const& x323 : Census) {
    const Table364& x324 = x323;
    const double x325 = std::get<0>(x324) /* ...zip */;
    const double x3261 = std::get<1>(x324) /* ...population */;
    const double x3262 = std::get<2>(x324);
    const double x3263 = std::get<3>(x324);
    const double x3264 = std::get<4>(x324);
    const double x3265 = std::get<5>(x324);
    const double x3266 = std::get<6>(x324);
    const double x3267 = std::get<7>(x324);
    const double x3268 = std::get<8>(x324);
    const double x3269 = std::get<9>(x324);
    const double x32610 = std::get<10>(x324);
    const double x32611 = std::get<11>(x324);
    const double x32612 = std::get<12>(x324);
    const double x32613 = std::get<13>(x324);
    const double x32614 = std::get<14>(x324);
    const double x32615 = std::get<15>(x324);
    const std::array<double, 15> x326 = {x3261, x3262, x3263, x3264, x3265, x3266, x3267, x3268, x3269, x32610, x32611, x32612, x32613, x32614, x32615};
    update( x357, x325, (x326) );;; 
  }
  ;
  std::array<double, 15> zero15 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  const dict_type<double, std::array<double, 15>>& x328 = /* read_ref */ x357;
  dict_type<double, std::array<double, 26>> x359;
  dict_type<double, std::array<long, 2>> xx359;
  for(auto const& x329 : Location) {
    const Table370& x330 = x329;
    const double x331 = std::get<0>(x330) /* ...locn */;
    const double x332 = std::get<4>(x330) /* ...tot_area_sq_ft */;
    const double x334 = std::get<1>(x330) /* ...zip */;
    const long xx3321 = std::get<2>(x330) /* ...regioncode */;
    const long xx3322 = std::get<3>(x330) /* ...climate_zone */;
    const double xx3325 = std::get<5>(x330);
    const double xx3326 = std::get<6>(x330);
    const double xx3327 = std::get<7>(x330);
    const double xx3328 = std::get<8>(x330);
    const double xx3329 = std::get<9>(x330);
    const double xx33210 = std::get<10>(x330);
    const double xx33211 = std::get<11>(x330);
    const double xx33212 = std::get<12>(x330);
    const double xx33213 = std::get<13>(x330);
    const double xx33214 = std::get<14>(x330);
    const std::array<double, 15> x335 = get_or_else(x328, x334, zero15);
    const std::array<double, 11> x336 = {x332, xx3325, xx3326, xx3327, xx3328, xx3329, xx33210, xx33211, xx33212, xx33213, xx33214};
    std::array<double, 26> x3356;
    for (size_t i = 0; i < 11; i++)
      x3356[i] = x336[i];
    for (size_t i = 0; i < 15; i++)
      x3356[i + 11] = x335[i];
    const std::array<long, 2> xx336 = {xx3321, xx3322};
    update( x359, x331, (x3356) );;; 
    update( xx359, x331, (xx336) );;; 
  }
  ;
  const dict_type<double, std::array<double, 26>>& x337 = /* read_ref */ x359;
  const dict_type<double, std::array<long, 2>>& xx337 = /* read_ref */ xx359;

  const std::array<double, 2> default_value = {0.0, 0.0};
  const std::array<double, 6> zero6 = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const std::array<double, 26> zero26 = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  const std::array<long, 2> default_value2 = {-1, -1};
  const std::array<long, 3> default_value3 = {-1, -1, -1};

  double pred;
  std::vector<Table365> Inventory = mode == "train" ? InventoryTrain : InventoryTest;
  for(auto const& x338 : Inventory) {
    pred = 0.0;
    const Table365& x339 = x338;
    const double x340 = std::get<0>(x339) /* ...locn */;
    const double x341 = std::get<1>(x339) /* ...dateid */;
    const Rec363& x342 = (Rec363){ x340, x341 };
    const std::array<double, 6> x343 = get_or_else(x316, x342, zero6);
    const double x344 = std::get<2>(x339) /* ...ksn */;
    const double x345 = get_or_else(x322, x344, 0.0);
    const std::array<long, 3> xx345 = get_or_else(xx322, x344, default_value3);
    // const std::array<double, 3> x345 = get_or_else(x322, x344, default_value3);
    // const std::array<double, 2> x346 = {x343, x345};
    const std::array<double, 26> x347 = get_or_else(x337, x340, zero26);
    const std::array<long, 2> xx347 = get_or_else(xx337, x340, default_value2);
    std::array<double, 38> x348;
    for (size_t i = 0; i < x343.size(); i++)
      x348[i] = x343[i];
    x348[x343.size()] = x345;
    for (size_t i = 0; i < x347.size(); i++)
      x348[i + x343.size() + 1] = x347[i];
    for (size_t i = 0; i < xx345.size(); i++)
      x348[i + x343.size() + x347.size() + 1] = xx345[i];
    for (size_t i = 0; i < xx347.size(); i++)
      x348[i + x343.size() + x347.size() + xx345.size() + 1] = xx347[i];
    //const double x349 = std::get<3>(x339) /* ...inventoryunits */;
    //const Target<double>& x350 = TargetCovar(x349);/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/
    //const RingCofactor<double,4>& x351 = x348 * x350;
    //x361 += x351; /* RingCofactor<double,5> */;; 
    for (size_t i = 0; i < CONT_SZ; i++) {
      pred += cont_theta[i] * x348[i];
      for (size_t j = i + 1; j < CONT_SZ; j++) {
        pred += cont_vee[i][j] * x348[i] * x348[j];
      }
    }
    for (size_t i = 0; i < CAT_SZ; i++) {
      auto ret = cofactor.cat_mapping[i].find(x348[i + CONT_SZ]);
      if (ret != cofactor.cat_mapping[i].end()) {
        pred += cat_theta[i][ret->second];
        for (size_t j = 0; j < CONT_SZ; j++) {
          pred += cont_cat_vee[j][i][x348[i + CONT_SZ]] * x348[j];
        }
        for (size_t j = i + 1; j < CAT_SZ; j++) {
          pred += cat_vee[i][j][std::make_pair(x348[i + CONT_SZ], x348[j + CONT_SZ])];
        }
      }
    }

    size += 1;
    y = std::get<3>(x338);
    mse += (y - pred) * (y - pred);
    mae += std::abs(y - pred);
  }
  mae /= size;
  mse /= size;
  rmse = std::sqrt(mse);

  auto flags = iter_num == 0 ? std::ofstream::out : std::ofstream::out | std::ofstream::app;
  std::ofstream ofs(path, flags);
  if (iter_num == 0)
    ofs << "iter,bgd_total_time,MSE,RMSE,MAE\n";
  ofs << iter_num + 1 << "," << processBGD << "," << mse << "," << rmse << "," << mae << "\n";
  ofs.close();
}

std::vector<size_t> get_indices(std::vector<size_t> data) {
  std::vector<size_t> index(data.size(), 0);
  for (size_t i = 0 ; i != index.size() ; i++) {
    index[i] = i;
  }
  sort(index.begin(), index.end(),
    [&](const int& a, const int& b) {
      return (data[a] < data[b]);
    }
  );
  std::vector<size_t> res(index.size());
  for (size_t i = 0; i < index.size(); i++) {
    res[index[i]] = i;
  }
  return res;
}


// template <size_t CONT_SZ, size_t CAT_SZ, size_t VEC_LEN>
// void bgd(const RingCofactor<double, CONT_SZ, CAT_SZ>& cofactor, const IndexMap<CONT_SZ, CAT_SZ>& indexMap, size_t max_iter) {
//   std::default_random_engine generator;
//   std::normal_distribution<double> distribution(0.0, 1.0);
//   generator.seed(0);
//   double cont_theta[CONT_SZ], tmp_cont_theta[CONT_SZ], learning_rate = 5e-3, tmp_a;
//   double cont_omega[CONT_SZ][VEC_LEN], tmp_cont_omega[CONT_SZ][VEC_LEN], val_cont_omega[VEC_LEN];
//   std::vector<double> cat_theta[CAT_SZ], tmp_cat_theta[CAT_SZ];
//   std::vector<double> cat_omega[CAT_SZ][VEC_LEN], tmp_cat_omega[CAT_SZ][VEC_LEN], val_cat_omega[VEC_LEN];
//   size_t cat_sizes[CAT_SZ];
//   for (size_t i = 0; i < CAT_SZ; i++) {
//     cat_sizes[i] = cofactor.cat_sum1[i].size();
//   }
//   for (size_t i = 0; i < CONT_SZ; i++) {
//     cont_theta[i] = distribution(generator);
//     tmp_cont_theta[i] = cont_theta[i];
//     for (size_t j = 0; j < VEC_LEN; j++) {
//       cont_omega[i][j] = distribution(generator);
//       tmp_cont_omega[i][j] = cont_omega[i][j];
//       val_cont_omega[j] = 0;
//     }
//   }
//   for (size_t i = 0; i < CAT_SZ; i++) {
//     for (size_t j = 0; j < cat_sizes[i]; j++) {
//       tmp_a = distribution(generator);
//       cat_theta[i].push_back(tmp_a);
//       tmp_cat_theta[i].push_back(tmp_a);
//     }
//     for (size_t j = 0; j < VEC_LEN; j++) {
//       for (size_t k = 0; k < cat_sizes[i]; k++) {
//         tmp_a = distribution(generator);
//         cat_omega[i][j].push_back(tmp_a);
//         tmp_cat_omega[i][j].push_back(tmp_a);
//       }
//     }
//   }
//   // std::cout << "cont_theta:" << std::endl;
//   // for (size_t i = 0; i < CONT_SZ; i++) {
//   //   std::cout << cont_theta[i] << ", ";
//   // }
//   // std::cout << std::endl;
//   // std::cout << "cont_omega:" << std::endl;
//   // for (size_t i = 0; i < CONT_SZ; i++) {
//   //   for (size_t j = 0; j < VEC_LEN; j++) {
//   //     std::cout << cont_omega[i][j] << ", ";
//   //   }
//   //   std::cout << std::endl;
//   // }
//   // std::cout << "cat_theta:" << std::endl;
//   // for (size_t i = 0; i < CAT_SZ; i++) {
//   //   for (size_t j = 0; j < cat_sizes[i]; j++) {
//   //     std::cout << cat_theta[i][j] << ", ";
//   //   }
//   //   std::cout << std::endl;
//   // }
//   // std::cout << "cat_omega:" << std::endl;
//   // for (size_t i = 0; i < CAT_SZ; i++) {
//   //   for (size_t j = 0; j < cat_sizes[i]; j++) {
//   //     for (size_t k = 0; k < VEC_LEN; k++) {
//   //       std::cout << cat_omega[i][k][j] << ", ";
//   //     }
//   //     std::cout << std::endl;
//   //   }
//   //   std::cout << std::endl;
//   // }
//   double val, val2, val3, val_, div_val = 1;
//   std::vector<tuple_t<1>> t_val;
//   std::vector<tuple_t<2>> t2_val;
//   size_t t_val_size, tvtmp_size, t2_val_size, t3_val_size, t4_val_size, tv2tmp_size, tv3tmp_size, tv4tmp_size;
  
//   processBGD = 0;
//   std::ofstream ofs("parameters_CONT_SZ=" + std::to_string(CONT_SZ) + "_CAT_SZ=" + std::to_string(CAT_SZ) + "_VEC_LEN=" + std::to_string(VEC_LEN) + ".txt");
//   // startBGD = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
//   for (size_t iter = 0; iter < max_iter; iter++) {
//     startBGD = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
//     for (size_t i = 0; i < CONT_SZ; i++) { 
//       val = cofactor.cont_C[i] / div_val;
//       for (size_t j = 0; j < CONT_SZ; j++) {
//         val -= cofactor.M_cont(indexMap.map_cont_degree2, i, j) / div_val * cont_theta[j];

//         for (size_t k = j + 1; k < CONT_SZ; k++) {
//           val2 = 0;
//           for (size_t f = 0; f < VEC_LEN; f++) {
//             val2 += cont_omega[j][f] * cont_omega[k][f];
//           }
//           val -= cofactor.N_cont(indexMap.map_cont_degree3, {i, j, k}) / div_val * val2;
//         }

//         for (size_t k = 0; k < CAT_SZ; k++) {
//           const std::vector<tuple_t<1>> &tvtmp = cofactor.N_cont2_cat(indexMap.map_cont2_cat_degree3, i, j, k);
//           for (size_t s = 0; s < cat_sizes[k]; s++) {
//             val2 = 0;
//             for (size_t f = 0; f < VEC_LEN; f++) {
//               val2 += cont_omega[j][f] * cat_omega[k][f][s];
//             }
//             val -= tvtmp[s].val / div_val * val2;
//           }
//         }

//       }
//       for (size_t j = 0; j < CAT_SZ; j++) {
//         const std::vector<tuple_t<1>> &tvtmp = cofactor.M_cont_cat(indexMap.map_cont_cat_degree2, i, j);
//         for (size_t k = 0; k < tvtmp.size(); k++) { // to make it faster, I can store all (i, j) mapped sizes so no need to call .size() here
//           val -= tvtmp[k].val / div_val * cat_theta[j][k];
//         }

//         for (size_t k = j + 1; k < CAT_SZ; k++) {
//           const std::vector<tuple_t<2>> &tvtmp2 = cofactor.N_cont_cat2(indexMap.map_cont_cat2_degree3, i, j, k);
//           std::vector<size_t> ind = get_indices({j, k});
//           for (size_t l = 0; l < tvtmp2.size(); l++) {
//             val2 = 0;
//             for (size_t f = 0; f < VEC_LEN; f++) {
//               val2 += cat_omega[j][f][cofactor.cat_mapping[j].find(tvtmp2[l].key[ind[0]])->second] * cat_omega[k][f][cofactor.cat_mapping[k].find(tvtmp2[l].key[ind[1]])->second];
//             }
//             val -= tvtmp2[l].val / div_val * val2;
//           }
//         }

//       }
//       tmp_cont_theta[i] += val * learning_rate;
//     }

//     for (size_t i = 0; i < CAT_SZ; i++) { 
//       t_val = cofactor.cat_C[i];
//       t_val_size = t_val.size();
//       for (size_t j = 0; j < t_val_size; j++) {
//         t_val[j].val /= div_val;
//       }
//       for (size_t j = 0; j < CONT_SZ; j++) {
//         const std::vector<tuple_t<1>> &tvtmp = cofactor.M_cont_cat(indexMap.map_cont_cat_degree2, j, i);
//         for (size_t k = 0; k < t_val_size; k++) {
//           t_val[k].val -= tvtmp[k].val / div_val * cont_theta[j];
//         }

//         for (size_t k = j + 1; k < CONT_SZ; k++) {
//           const std::vector<tuple_t<1>> &tvtmp = cofactor.N_cont2_cat(indexMap.map_cont2_cat_degree3, j, k, i);
//           val2 = 0;
//           for (size_t f = 0; f < VEC_LEN; f++) {
//             val2 += cont_omega[j][f] * cont_omega[k][f];
//           }
//           for (size_t s = 0; s < cat_sizes[i]; s++) {
//             t_val[s].val -= tvtmp[s].val / div_val * val2;
//           }
//         } // can be optimized by just doing half of the BGD for (j0, k0) and (k0, j0) pairs and reduce double the value from val

//         for(size_t k = 0; k < CAT_SZ; k++) {
//           const std::vector<tuple_t<2>> &tvtmp2 = cofactor.N_cont_cat2(indexMap.map_cont_cat2_degree3, j, i, k);
//           std::vector<size_t> ind = get_indices({i, k});
//           for (size_t l = 0; l < tvtmp2.size(); l++) {
//             val2 = 0;
//             for (size_t f = 0; f < VEC_LEN; f++) {
//               val2 += cont_omega[j][f] * cat_omega[k][f][cofactor.cat_mapping[k].find(tvtmp2[l].key[ind[1]])->second];
//             }
//             t_val[cofactor.cat_mapping[i].find(tvtmp2[l].key[ind[0]])->second].val -= tvtmp2[l].val / div_val * val2;
//           }
//         }

//       }
//       for (size_t j = 0; j < CAT_SZ; j++) {
//         if (i == j) {
//           const std::vector<tuple_t<1>> &tvtmp = cofactor.M_cat_sum2(indexMap.map_cat_degree2, i, j);
//           for (size_t k = 0; k < t_val_size; k++) {
//             t_val[k].val -= tvtmp[k].val / div_val * cat_theta[j][k];
//           } 
//         }
//         else {
//           std::vector<size_t> ind = get_indices({i, j});
//           const std::vector<tuple_t<2>> &tvtmp = cofactor.M_cat(indexMap.map_cat_degree2, i, j);
//           for (size_t k = 0; k < tvtmp.size(); k++) {
//             t_val[cofactor.cat_mapping[i].find(tvtmp[k].key[ind[0]])->second].val -= tvtmp[k].val / div_val * cat_theta[j][cofactor.cat_mapping[j].find(tvtmp[k].key[ind[1]])->second];
//           }
//         }

//         for (size_t k = j + 1; k < CAT_SZ; k++) {
//           const std::vector<tuple_t<3>> &tvtmp3 = cofactor.N_cat(indexMap.map_cat_degree3, {i, j, k});
//           std::vector<size_t> ind = get_indices({i, j, k});
//           for (size_t l = 0; l < tvtmp3.size(); l++) {
//             val2 = 0;
//             for (size_t f = 0; f < VEC_LEN; f++) {
//               val2 += cat_omega[j][f][cofactor.cat_mapping[j].find(tvtmp3[l].key[ind[1]])->second] * cat_omega[k][f][cofactor.cat_mapping[k].find(tvtmp3[l].key[ind[2]])->second];
//             }
//             t_val[cofactor.cat_mapping[i].find(tvtmp3[l].key[ind[0]])->second].val -= tvtmp3[l].val / div_val * val2;
//           }
//         }

//       }
//       for (size_t k = 0; k < t_val_size; k++) {
//         tmp_cat_theta[i][k] += t_val[k].val * learning_rate;
//       }
//     }

//     for (size_t i = 0; i < CONT_SZ; i++) {
//       for (size_t f = 0; f < VEC_LEN; f++) {
//         val_cont_omega[f] = 0;
//       }
//       for (size_t j = 0; j < CONT_SZ; j++) {
//         if (i == j) continue;
//         val_ = cofactor.D_cont(indexMap.map_cont_degree2, i, j) / div_val;
//         for (size_t k = 0; k < CONT_SZ; k++) {
//           val_ -= cofactor.N_cont(indexMap.map_cont_degree3, {i, j, k}) / div_val * cont_theta[k];
//           for (size_t l = k + 1; l < CONT_SZ; l++) {
//             val2 = 0;
//             for (size_t f = 0; f < VEC_LEN; f++) {
//               val2 += cont_omega[k][f] * cont_omega[l][f];
//             }
//             val_ -= cofactor.O_cont(indexMap.map_cont_degree4, indexMap.map_cont_degree2, {i, j, k, l}) / div_val * val2;
//           }

//           for (size_t l = 0; l < CAT_SZ; l++) {
//             const std::vector<tuple_t<1>> &tvtmp = cofactor.O_cont3_cat(indexMap.map_cont3_cat_degree4, {i, j, k}, l);
//             for (size_t m = 0; m < tvtmp.size(); m++) {
//               val2 = 0;
//               for (size_t f = 0; f < VEC_LEN; f++) {
//                 val2 += cont_omega[k][f] * cat_omega[l][f][m];
//               }
//               val_ -= tvtmp[m].val / div_val * val2;
//             }
//           }
//         }

//         for (size_t k = 0; k < CAT_SZ; k++) {
//           const std::vector<tuple_t<1>> &tvtmp = cofactor.N_cont2_cat(indexMap.map_cont2_cat_degree3, i, j, k);
//           for (size_t l = 0; l < tvtmp.size(); l++) {
//             val_ -= tvtmp[l].val / div_val * cat_theta[k][l];
//           }

//           for (size_t l = k + 1; l < CAT_SZ; l++) {
//             const std::vector<tuple_t<2>> &tvtmp2 = cofactor.O_cont2_cat2(indexMap.map_cont2_cat2_degree4, {i, j}, {k, l});
//             std::vector<size_t> ind = get_indices({k, l});
//             for (size_t m = 0; m < tvtmp2.size(); m++) {
//               val2 = 0;
//               for (size_t f = 0; f < VEC_LEN; f++) {
//                 val2 += cat_omega[k][f][cofactor.cat_mapping[k].find(tvtmp2[m].key[ind[0]])->second] * cat_omega[l][f][cofactor.cat_mapping[l].find(tvtmp2[m].key[ind[1]])->second];
//               }
//               val_ -= tvtmp2[m].val / div_val * val2;
//             }
//           }
//         }

//         for (size_t f = 0; f < VEC_LEN; f++) {
//           val_cont_omega[f] += val_ * cont_omega[j][f];
//         }
//       }

//       for (size_t j = 0; j < CAT_SZ; j++) {
//         std::vector<tuple_t<1>> val__ = cofactor.D_cont_cat(indexMap.map_cont_cat_degree2, i, j);
//         for (size_t k = 0; k < cat_sizes[j]; k++) {
//           val__[k].val /= div_val;
//         }

//         for (size_t k = 0; k < CONT_SZ; k++) {
//           const std::vector<tuple_t<1>> &tvtmp = cofactor.N_cont2_cat(indexMap.map_cont2_cat_degree3, i, k, j);
//           for (size_t l = 0; l < tvtmp.size(); l++) {
//             val__[l].val -= tvtmp[l].val / div_val * cont_theta[k];
//           }

//           for (size_t l = k + 1; l < CONT_SZ; l++) {
//             const std::vector<tuple_t<1>> &tvtmp = cofactor.O_cont3_cat(indexMap.map_cont3_cat_degree4, {i, k, l}, j);
//             val2 = 0;
//             for (size_t f = 0; f < VEC_LEN; f++) {
//               val2 += cont_omega[k][f] * cont_omega[l][f];
//             }
//             for (size_t m = 0; m < tvtmp.size(); m++) {
//               val__[m].val -= tvtmp[m].val / div_val * val2;
//             }
//           }

//           for (size_t l = 0; l < CAT_SZ; l++) {
//             if (i == k && j == l) {
//               const std::vector<tuple_t<1>> &tvtmp1 = cofactor.O_cont2_cat2_sum4(indexMap.map_cont_cat_degree2, i, k, j, l);
//               for (size_t m = 0; m < tvtmp1.size(); m++) {
//                 val2 = 0;
//                 for (size_t f = 0; f < VEC_LEN; f++) {
//                   val2 += cont_omega[k][f] * cat_omega[l][f][m];
//                 }
//                 val__[m].val -= tvtmp1[m].val / div_val * val2;
//               }
//             }
//             else {
//               const std::vector<tuple_t<2>> &tvtmp2 = cofactor.O_cont2_cat2(indexMap.map_cont2_cat2_degree4, {i, k}, {j, l});
//               std::vector<size_t> ind = get_indices({j, l});
//               for (size_t m = 0; m < tvtmp2.size(); m++) {
//                 val2 = 0;
//                 for (size_t f = 0; f < VEC_LEN; f++) {
//                   val2 += cont_omega[k][f] * cat_omega[l][f][cofactor.cat_mapping[l].find(tvtmp2[m].key[ind[1]])->second];
//                 }
//                 val__[cofactor.cat_mapping[j].find(tvtmp2[m].key[ind[0]])->second].val -= tvtmp2[m].val / div_val * val2;
//               }
//             }
//           }
//         }

//         for (size_t k = 0; k < CAT_SZ; k++) {
//           const std::vector<tuple_t<2>> &tvtmp2 = cofactor.N_cont_cat2(indexMap.map_cont_cat2_degree3, i, j, k);
//           std::vector<size_t> ind = get_indices({j, k});
//           for (size_t l = 0; l < tvtmp2.size(); l++) {
//             val__[cofactor.cat_mapping[j].find(tvtmp2[l].key[ind[0]])->second].val -= tvtmp2[l].val / div_val * cat_theta[k][cofactor.cat_mapping[k].find(tvtmp2[l].key[ind[1]])->second];
//           }

//           for(size_t l = k + 1; l < CAT_SZ; l++) {
//             const std::vector<tuple_t<3>> &tvtmp3 = cofactor.O_cont_cat3(indexMap.map_cont_cat3_degree4, i, {j, k, l});
//             std::vector<size_t> ind = get_indices({j, k, l});
//             for (size_t m = 0; m < tvtmp3.size(); m++) {
//               val2 = 0;
//               for (size_t f = 0; f < VEC_LEN; f++) {
//                 val2 += cat_omega[k][f][cofactor.cat_mapping[k].find(tvtmp3[m].key[ind[1]])->second] * cat_omega[l][f][cofactor.cat_mapping[l].find(tvtmp3[m].key[ind[2]])->second];
//               }
//               val__[cofactor.cat_mapping[j].find(tvtmp3[m].key[ind[0]])->second].val -= tvtmp3[m].val / div_val * val2;
//             }
//           }
//         }

//         for (size_t f = 0; f < VEC_LEN; f++) {
//           for (size_t g = 0; g < cat_sizes[j]; g++) {
//             val_cont_omega[f] += val__[g].val * cat_omega[j][f][g];
//           }
//         }
//       }
//       for (size_t f = 0; f < VEC_LEN; f++) {
//         tmp_cont_omega[i][f] += val_cont_omega[f] * learning_rate;
//       }
//     }

//     for (size_t i = 0; i < CAT_SZ; i++) {
//       for (size_t f = 0; f < VEC_LEN; f++) {
//         val_cat_omega[f].clear();
//         for (size_t g = 0; g < cat_sizes[i]; g++) {
//           val_cat_omega[f].push_back(0);
//         }

//       }
//       for (size_t j = 0; j < CONT_SZ; j++) {
//         std::vector<tuple_t<1>> val__ = cofactor.D_cont_cat(indexMap.map_cont_cat_degree2, j, i);
//         for (size_t k = 0; k < cat_sizes[i]; k++) {
//           val__[k].val /= div_val;
//         }
//         for (size_t k = 0; k < CONT_SZ; k++) {
//           const std::vector<tuple_t<1>> &tvtmp = cofactor.N_cont2_cat(indexMap.map_cont2_cat_degree3, j, k, i);
//           for (size_t l = 0; l < tvtmp.size(); l++) {
//             val__[cofactor.cat_mapping[i].find(tvtmp[l].key[0])->second].val -= tvtmp[l].val / div_val * cont_theta[k];
//           }

//           for (size_t l = k + 1; l < CONT_SZ; l++) {
//             const std::vector<tuple_t<1>> &tvtmp_ = cofactor.O_cont3_cat(indexMap.map_cont3_cat_degree4, {j, k, l}, i);
//             val2 = 0;
//             for (size_t f = 0; f < VEC_LEN; f++) {
//               val2 += cont_omega[k][f] * cont_omega[l][f];
//             }
//             for (size_t m = 0; m < tvtmp_.size(); m++) {
//               val__[cofactor.cat_mapping[i].find(tvtmp_[m].key[0])->second].val -= tvtmp_[m].val / div_val * val2;
//             }
//           }

//           for (size_t l = 0; l < CAT_SZ; l++) {
//             if (j == k && i == l) {
//               const std::vector<tuple_t<1>> &tvtmp1 = cofactor.O_cont2_cat2_sum4(indexMap.map_cont_cat_degree2, j, k, i, l);
//               for (size_t m = 0; m < tvtmp1.size(); m++) {
//                 val2 = 0;
//                 for (size_t f = 0; f < VEC_LEN; f++) {
//                   val2 += cont_omega[k][f] * cat_omega[l][f][m];
//                 }
//                 val__[m].val -= tvtmp1[m].val / div_val * val2;
//               }
//             } 
//             else {
//               const std::vector<tuple_t<2>> &tvtmp2_ = cofactor.O_cont2_cat2(indexMap.map_cont2_cat2_degree4, {j, k}, {i, l});
//               std::vector<size_t> ind = get_indices({i, l});
//               for (size_t m = 0; m < tvtmp2_.size(); m++) {
//                 val2 = 0;
//                 for (size_t f = 0; f < VEC_LEN; f++) {
//                   val2 += cont_omega[k][f] * cat_omega[l][f][cofactor.cat_mapping[l].find(tvtmp2_[m].key[ind[1]])->second];
//                 }
//                 val__[cofactor.cat_mapping[i].find(tvtmp2_[m].key[ind[0]])->second].val -= tvtmp2_[m].val / div_val * val2;
//               }
//             }
//           }
//         }

//         for (size_t k = 0; k < CAT_SZ; k++) {
//           const std::vector<tuple_t<2>> &tvtmp2 = cofactor.N_cont_cat2(indexMap.map_cont_cat2_degree3, j, i, k);
//           std::vector<size_t> ind = get_indices({i, k});
//           for (size_t l = 0; l < tvtmp2.size(); l++) {
//             val__[cofactor.cat_mapping[i].find(tvtmp2[l].key[ind[0]])->second].val -= tvtmp2[l].val / div_val * cat_theta[k][cofactor.cat_mapping[k].find(tvtmp2[l].key[ind[1]])->second]; 
//           }

//           for (size_t l = k + 1; l < CAT_SZ; l++) {
//             const std::vector<tuple_t<3>> &tvtmp3_ = cofactor.O_cont_cat3(indexMap.map_cont_cat3_degree4, j, {i, k, l});
//             std::vector<size_t> ind = get_indices({i, k, l});
//             for (size_t m = 0; m < tvtmp3_.size(); m++) {
//               val2 = 0;
//               for (size_t f = 0; f < VEC_LEN; f++) {
//                 val2 += cat_omega[k][f][cofactor.cat_mapping[k].find(tvtmp3_[m].key[ind[1]])->second] * cat_omega[l][f][cofactor.cat_mapping[l].find(tvtmp3_[m].key[ind[2]])->second];
//               }
//               val__[cofactor.cat_mapping[i].find(tvtmp3_[m].key[ind[0]])->second].val -= tvtmp3_[m].val / div_val * val2;
//             }
//           }
//         }

//         for (size_t f = 0; f < VEC_LEN; f++) {
//           for (size_t g = 0; g < cat_sizes[i]; g++) {
//             val_cat_omega[f][g] += val__[g].val * cont_omega[j][f];
//           }
//         }
//       }

//       for (size_t j = 0; j < CAT_SZ; j++) {
//         if (i == j) continue;
//         size_t a = std::min(i, j), b = std::max(i, j);
//         size_t cat_mapping2_index = indexMap.map_cat_degree2.find({a, b})->second;
//         std::vector<size_t> ij_ind = get_indices({i, j});
//         std::vector<tuple_t<2>> val__ = cofactor.D_cat(indexMap.map_cat_degree2, i, j);
//         for (size_t k = 0; k < val__.size(); k++) {
//           val__[k].val /= div_val;
//         }
//         for (size_t k = 0; k < CONT_SZ; k++) {
//           const std::vector<tuple_t<2>> &tvtmp2 = cofactor.N_cont_cat2(indexMap.map_cont_cat2_degree3, k, i, j);
//           for (size_t l = 0; l < tvtmp2.size(); l++) {
//             val__[l].val -= tvtmp2[l].val / div_val * cont_theta[k]; // will be solved with next comment: assuming that categorical attributes are aligned the same way in both val__ (cat_D) and tvtmp2 (N_cont_cat2). If it's not, then should be fixed; It actually is and I had the same assumption about other stuff previously as well
//           }

//           for (size_t l = k + 1; l < CONT_SZ; l++) {
//             const std::vector<tuple_t<2>> &tvtmp2_ = cofactor.O_cont2_cat2(indexMap.map_cont2_cat2_degree4, {k, l}, {i, j});
//             val2 = 0;
//             for (size_t f = 0; f < VEC_LEN; f++) {
//               val2 += cont_omega[k][f] * cont_omega[l][f];
//             }
//             for (size_t m = 0; m < tvtmp2_.size(); m++) {
//               val__[m].val -= tvtmp2_[m].val / div_val * val2; // same here
//             }
//           }

//           for (size_t l = 0; l < CAT_SZ; l++) {
//             const std::vector<tuple_t<3>> &tvtmp3_ = cofactor.O_cont_cat3(indexMap.map_cont_cat3_degree4, k, {i, j, l});
//             std::vector<size_t> ind = get_indices({i, j, l});
//             for (size_t m = 0; m < tvtmp3_.size(); m++) {
//               val2 = 0;
//               for (size_t f = 0; f < VEC_LEN; f++) {
//                 val2 += cont_omega[k][f] * cat_omega[l][f][cofactor.cat_mapping[l].find(tvtmp3_[m].key[ind[2]])->second];
//               }
//               val__[cofactor.cat_mapping2[cat_mapping2_index].find(std::make_pair(tvtmp3_[m].key[ind[ij_ind[0]]], tvtmp3_[m].key[ind[ij_ind[1]]]))->second].val -= tvtmp3_[m].val / div_val * val2;
//             }
//           }
//         }

//         for (size_t k = 0; k < CAT_SZ; k++) {
//           const std::vector<tuple_t<3>> &tvtmp3 = cofactor.N_cat(indexMap.map_cat_degree3, {i, j, k});
//           std::vector<size_t> ind = get_indices({i, j, k});
//           for (size_t l = 0; l < tvtmp3.size(); l++) {
//             val__[cofactor.cat_mapping2[cat_mapping2_index].find(std::make_pair(tvtmp3[l].key[ind[ij_ind[0]]], tvtmp3[l].key[ind[ij_ind[1]]]))->second].val -= tvtmp3[l].val / div_val * cat_theta[k][cofactor.cat_mapping[k].find(tvtmp3[l].key[ind[2]])->second];
//           }

//           for (size_t l = k + 1; l < CAT_SZ; l++) {
//             if ((i == k && j == l) || (i == l && j == k)) {
//               const std::vector<tuple_t<2>> &tvtmp4 = cofactor.O_cat_sum4(indexMap.map_cat_degree2, {i, j, k, l});
//               for (size_t m = 0; m < tvtmp4.size(); m++) {
//                 val2 = 0;
//                 for (size_t f = 0; f < VEC_LEN; f++) {
//                   val2 += cat_omega[k][f][cofactor.cat_mapping[k].find(tvtmp4[m].key[0])->second] * cat_omega[l][f][cofactor.cat_mapping[l].find(tvtmp4[m].key[1])->second];
//                 }
//                 val__[m].val -= tvtmp4[m].val / div_val * val2;
//               }
//             } else {
//               const std::vector<tuple_t<4>> &tvtmp4 = cofactor.O_cat(indexMap.map_cat_degree4, {i, j, k, l});
//               std::vector<size_t> ind = get_indices({i, j, k, l});
//               for (size_t m = 0; m < tvtmp4.size(); m++) {
//                 val2 = 0;
//                 for (size_t f = 0; f < VEC_LEN; f++) {
//                   val2 += cat_omega[k][f][cofactor.cat_mapping[k].find(tvtmp4[m].key[ind[2]])->second] * cat_omega[l][f][cofactor.cat_mapping[l].find(tvtmp4[m].key[ind[3]])->second];
//                 }
//                 val__[cofactor.cat_mapping2[cat_mapping2_index].find(std::make_pair(tvtmp4[m].key[ind[ij_ind[0]]], tvtmp4[m].key[ind[ij_ind[1]]]))->second].val -= tvtmp4[m].val / div_val * val2;
//               }
//             }
//           }
//         }
//         for (size_t f = 0; f < VEC_LEN; f++) {
//           for (size_t g = 0; g < val__.size(); g++) {
//             val_cat_omega[f][cofactor.cat_mapping[i].find(val__[g].key[ij_ind[0]])->second] += val__[g].val * cat_omega[j][f][cofactor.cat_mapping[j].find(val__[g].key[ij_ind[1]])->second];
//           }
//         }
//       }
//       for (size_t f = 0; f < VEC_LEN; f++) {
//         for (size_t g = 0; g < cat_sizes[i]; g++) {
//           tmp_cat_omega[i][f][g] += val_cat_omega[f][g] * learning_rate;
//         }
//       }
//     }

//     for (size_t i = 0; i < CONT_SZ; i++) {
//       cont_theta[i] = tmp_cont_theta[i];
//       for (size_t f = 0; f < VEC_LEN; f++) {
//         cont_omega[i][f] = tmp_cont_omega[i][f];
//       }
//     }
//     for (size_t i = 0; i < CAT_SZ; i++) {
//       for (size_t k = 0; k < cat_sizes[i]; k++) {
//         cat_theta[i][k] = tmp_cat_theta[i][k];
//         for (size_t f = 0; f < VEC_LEN; f++) {
//           cat_omega[i][f][k] = tmp_cat_omega[i][f][k];
//         }
//       }
//     }


//     endBGD = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
//     processBGD += endBGD - startBGD;

//     ofs << "iter#: " << iter << std::endl;
//     ofs << "cont_theta:" << std::endl;
//     for (size_t i = 0; i < CONT_SZ; i++) {
//       ofs << cont_theta[i] << ", ";
//     }
//     ofs << std::endl;
//     ofs << "cont_omega:" << std::endl;
//     for (size_t i = 0; i < CONT_SZ; i++) {
//       for (size_t j = 0; j < VEC_LEN; j++) {
//         ofs << cont_omega[i][j] << ", ";
//       }
//       ofs << std::endl;
//     }
//     ofs << "cat_theta:" << std::endl;
//     for (size_t i = 0; i < CAT_SZ; i++) {
//       for (size_t j = 0; j < cat_sizes[i]; j++) {
//         ofs << cat_theta[i][j] << ", ";
//       }
//       ofs << std::endl;
//     }
//     ofs << "cat_omega:" << std::endl;
//     for (size_t i = 0; i < CAT_SZ; i++) {
//       for (size_t j = 0; j < cat_sizes[i]; j++) {
//         for (size_t k = 0; k < VEC_LEN; k++) {
//           ofs << cat_omega[i][k][j] << ", ";
//         }
//         ofs << std::endl;
//       }
//       ofs << std::endl;
//     }
//     ofs << "=======================================" << std::endl;
//     ofs << "=======================================" << std::endl;

//     prepareStats<CONT_SZ, CAT_SZ, VEC_LEN>(cont_theta, cat_theta, cont_omega, cat_omega, cofactor, indexMap.map_cat_degree2, iter, "train", learning_rate);
//     prepareStats<CONT_SZ, CAT_SZ, VEC_LEN>(cont_theta, cat_theta, cont_omega, cat_omega, cofactor, indexMap.map_cat_degree2, iter, "test", learning_rate);
//   }
//   ofs.close();
//   // endBGD = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
//   // processBGD += endBGD - startBGD;
//   predict<CONT_SZ, CAT_SZ, VEC_LEN>(cont_theta, cat_theta, cont_omega, cat_omega, cofactor, indexMap.map_cat_degree2);
//   prepareStatsFromFile<CONT_SZ, CAT_SZ, VEC_LEN>(max_iter);
// }

void run()
{
   int64_t startLoading = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

   loadRelations();

   int64_t loadTime = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count()-startLoading;
  //  std::cout << "Data loading: "+std::to_string(loadTime)+"us." << std::endl;
   std::ofstream ofs("times.txt",std::ofstream::out | std::ofstream::app);
   ofs << loadTime;
   ofs.close();

   int64_t startSorting = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();

   indexRelations();

   int64_t indexingTime = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count()-startSorting;
  //  std::cout << "Data indexing: " + std::to_string(indexingTime)+"us." << std::endl;

   ofs.open("times.txt",std::ofstream::out | std::ofstream::app);
   ofs << "\t" << indexingTime;
   ofs.close();
   std::vector<int64_t> times;
   std::vector<int64_t> timesBGD;
   std::vector<int64_t> timesPredict;
   std::vector<int64_t> timesUpdate;
   std::vector<int64_t> timesMult;
   std::vector<int64_t> timesIndexMap;
   double avgTime = 0;
   double avgAllBGD = 0;
   double avgBGD = 0;
   double avgPredict = 0;
   double avgUpdate = 0;
   double avgMult = 0;
   double avgIndexMap = 0;
   size_t max_iter = 2e2;
   int64_t reconstTime = 0;
   for(int i = 0; i<1; i++) {
     int64_t startProcess = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();


     RingCofactor<double,13,0> res1; ////
     IndexMap<13, 0> res2;
     computeGroups(res1, res2);

     processTime = endProcess - startProcess;

    //  bgd<33, 5, 8>(res1, res2, max_iter);

    // Beta -- TODO: fix it like other timings.
    int64_t reconstStart = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    res1.reconstruct();
    int64_t reconstEnd = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    // std::cerr << res1.cont_degree2[1][0];
    // std::cerr << res1.cont_degree3[2][1][0];
    // std::cerr << res1.cont_degree4[3][2][1][0];
    reconstTime = reconstEnd - reconstStart;
    std::ofstream ofs2;
    ofs2.open("ifaq_output_reconstructed.txt");
    ofs2 << std::fixed << std::setprecision(2);
    ofs2 << res1 << endl;
    ofs2.close();

     if(true) {
       avgTime += processTime;
       avgBGD += processBGD;
       avgPredict += processPredict;
       avgUpdate += updateTime;
       avgMult += multTime;
       avgIndexMap += indexMapTime;
       times.push_back(processTime);
       timesBGD.push_back(processBGD);
       timesPredict.push_back(processPredict);
       timesUpdate.push_back(updateTime);
       timesMult.push_back(multTime);
       timesIndexMap.push_back(indexMapTime);
     }
    //  std::cout << "Data process: "+std::to_string(processTime)+"us." << std::endl;
    //  std::cout << "BGD process: "+std::to_string(processBGD)+"us." << std::endl;
    //  std::cout << "Predict process: "+std::to_string(processPredict)+"us." << std::endl;
    //  std::cout << "Update time: "+std::to_string(updateTime)+"us." << std::endl;
    //  std::cout << "Mult time: "+std::to_string(multTime)+"us." << std::endl;
    //  std::cout << "IndexMap time: "+std::to_string(indexMapTime)+"us." << std::endl;
     ofs.open("times.txt",std::ofstream::out | std::ofstream::app);
     ofs << "\t Data:" << processTime;
     ofs << "\t BGD :" << processBGD;
     ofs << "\t Predict :" << processPredict;
     ofs.close();
   }
   avgTime = avgTime / times.size();
   avgAllBGD = avgBGD / timesBGD.size();
   avgBGD = avgAllBGD / max_iter;
   avgPredict = avgPredict / timesPredict.size();
   avgUpdate = avgUpdate / timesUpdate.size();
   avgMult = avgMult / timesMult.size();
   avgIndexMap = avgIndexMap / timesIndexMap.size();
  //  std::cout << "Avg data process: "+std::to_string(avgTime)+"us." << std::endl;
  //  std::cout << "Avg all of BGD iters: "+std::to_string(avgAllBGD)+"us." << std::endl;
  //  std::cout << "Avg single BGD iter: "+std::to_string(avgBGD)+"us." << std::endl;
  //  std::cout << "Avg prediction time: "+std::to_string(avgPredict)+"us." << std::endl;
  //  std::cout << "Avg update time: "+std::to_string(avgUpdate)+"us." << std::endl;
  //  std::cout << "Avg mult time: "+std::to_string(avgMult)+"us." << std::endl;
  //  std::cout << "Avg indexMap time: "+std::to_string(avgIndexMap)+"us." << std::endl;

  std::cout << std::to_string(processTime) << std::endl;
  std::cout << std::to_string(updateTime) << std::endl;
  std::cout << std::to_string(multTime) << std::endl;
  std::cout << std::to_string(reconstTime) << std::endl;
}


int main(int argc, char *argv[])
{
  //  std::cout << "run IFAQ" << std::endl;
   run();
   return 0;
};
