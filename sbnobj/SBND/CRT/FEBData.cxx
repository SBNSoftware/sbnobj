#ifndef SBND_FEBDATA_CXX
#define SBND_FEBDATA_CXX

#include "cetlib_except/exception.h"

#include "sbnobj/SBND/CRT/FEBData.hh"

namespace sbnd{
namespace crt{

  FEBData::FEBData():
    fMac5(0)
  , fTs0(0)
  , fTs1(0)
  , fADC()
  , fCoinc(0)
  {}

  FEBData::FEBData(uint16_t mac5, uint32_t ts0, uint32_t ts1, adc_array_t ADC, uint32_t coinc):
    fMac5(mac5)
  , fTs0(ts0)
  , fTs1(ts1)
  , fADC(ADC)
  , fCoinc(coinc)
  {}

  FEBData::~FEBData() {}

  uint16_t FEBData::Mac5() const
  {
    return fMac5;
  }

  uint32_t FEBData::Ts0() const
  {
    return fTs0;
  }

  uint32_t FEBData::Ts1() const
  {
    return fTs1;
  }

  adc_array_t FEBData::ADC() const
  {
    return fADC;
  }

  uint16_t FEBData::ADC(size_t sipmID) const
  {
    if (sipmID >= N_CH) {
      throw cet::exception("sbnd::crt::FEBData") << "sipmID is out of limits.\n";
    }

    return fADC[sipmID];
  }

  uint32_t FEBData::Coinc() const
  {
    return fCoinc;
  }

  void FEBData::SetMac5(uint16_t mac5)
  {
    fMac5 = mac5;
  }

  void FEBData::SetTs0(uint32_t ts0)
  {
    fTs0 = ts0;
  }

  void FEBData::SetTs1(uint32_t ts1)
  {
    fTs1 = ts1;
  }

  void FEBData::SetADC(size_t sipmID, uint16_t adc)
  {
    if (sipmID >= N_CH) {
      throw cet::exception("sbnd::crt::FEBData") << "sipmID is out of limits.\n";
    }

    fADC[sipmID] = adc;
  }

  void FEBData::SetCoinc(uint32_t coinc)
  {
    fCoinc = coinc;
  }

} // namespace crt
} // namespace sbnd

#endif

