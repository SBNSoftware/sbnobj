#include "sbnobj/SBND/FRAMSObj/FRAMSObj.h"

sbnd::FRAMSObj::FRAMSObj(
  float Delta_U, float Eta_U, float FitScore_U, float Alpha_U, float Omega_U, float Tau_U, float Iota_U, float ScoreBDT_U,
  float Delta_V, float Eta_V, float FitScore_V, float Alpha_V, float Omega_V, float Tau_V, float Iota_V, float ScoreBDT_V,
  float Delta_C, float Eta_C, float FitScore_C, float Alpha_C, float Omega_C, float Tau_C, float Iota_C, float ScoreBDT_C,
  int IsSignal, float Gap, float ProtonKE, float PionKE, float LambdaKE)
  :Delta_U(Delta_U),Eta_U(Eta_U),FitScore_U(FitScore_U),Alpha_U(Alpha_U),Omega_U(Omega_U),Tau_U(Tau_U),Iota_U(Iota_U),ScoreBDT_U(ScoreBDT_U),
 Delta_V(Delta_V),Eta_V(Eta_V),FitScore_V(FitScore_V),Alpha_V(Alpha_V),Omega_V(Omega_V),Tau_V(Tau_V),Iota_V(Iota_V),ScoreBDT_V(ScoreBDT_V),
 Delta_C(Delta_C),Eta_C(Eta_C),FitScore_C(FitScore_C),Alpha_C(Alpha_C),Omega_C(Omega_C),Tau_C(Tau_C),Iota_C(Iota_C),ScoreBDT_C(ScoreBDT_C),
 IsSignal(IsSignal),Gap(Gap),ProtonKE(ProtonKE),PionKE(PionKE),LambdaKE(LambdaKE)
  {
  }



void sbnd::FRAMSObj::FillDataMC(double gap, int issignal, double keproton, double kepion, double kelambda){
 Gap = gap;
 IsSignal = issignal;
 ProtonKE=keproton;
 PionKE=kepion;
 LambdaKE=kelambda;
}

void sbnd::FRAMSObj::FillData(int view, double delta, double eta, double fitScore,
                              double alpha, double omega, double tau, double iota, double score){ 
  if(view==0){
     Delta_U = delta;
     Eta_U = eta;
     FitScore_U = fitScore;
     Alpha_U = alpha;
     Omega_U = omega;
     Tau_U = tau;
     Iota_U = iota;
     ScoreBDT_U = score;
  }
  else if(view==1){
     Delta_V = delta;
     Eta_V = eta;
     FitScore_V = fitScore;
     Alpha_V = alpha;
     Omega_V = omega;
     Tau_V = tau;
     Iota_V = iota;
     ScoreBDT_V = score;
  }
  else if(view==2){
     Delta_C = delta;
     Eta_C = eta;
     FitScore_C = fitScore;
     Alpha_C = alpha;
     Omega_C = omega;
     Tau_C = tau;
     Iota_C = iota;
     ScoreBDT_C = score;
  }
}