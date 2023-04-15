#include "sbnobj/SBND/FRAMSObj/FRAMSObj.h"

sbnd::FRAMSObj::FRAMSObj(
  float Delta_U, float Eta_U, float FitScore_U, float Alpha_U, float Omega_U, float Tau_U, float Iota_U,
  float Delta_V, float Eta_V, float FitScore_V, float Alpha_V, float Omega_V, float Tau_V, float Iota_V,
  float Delta_C, float Eta_C, float FitScore_C, float Alpha_C, float Omega_C, float Tau_C, float Iota_C,
  float Gap, float ProtonKE, float PionKE, float ScoreBDT_U, float ScoreBDT_V, float ScoreBDT_C, int IsSignal)
  : Delta_U(Delta_U), Eta_U(Eta_U), FitScore_U(FitScore_U), Alpha_U(Alpha_U), Omega_U(Omega_U), Tau_U(Tau_U), Iota_U(Iota_U),
  Delta_V(Delta_V), Eta_V(Eta_V), FitScore_V(FitScore_V), Alpha_V(Alpha_V), Omega_V(Omega_V), Tau_V(Tau_V), Iota_V(Iota_V),
  Delta_C(Delta_C), Eta_C(Eta_C), FitScore_C(FitScore_C), Alpha_C(Alpha_C), Omega_C(Omega_C), Tau_C(Tau_C), Iota_C(Iota_C),
  Gap(Gap), ProtonKE(ProtonKE), PionKE(PionKE), ScoreBDT_U(ScoreBDT_U), ScoreBDT_V(ScoreBDT_V), ScoreBDT_C(ScoreBDT_C), IsSignal(IsSignal)
  {
  }
