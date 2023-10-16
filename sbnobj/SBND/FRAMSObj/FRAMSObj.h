#ifndef sbnobj_FRAMSObj_HH
#define sbnobj_FRAMSObj_HH

namespace sbnd {


  constexpr float  defVal = 1.;
  constexpr float  defVal2 = 0.5;
  constexpr float  defVal3 = 10000;
  constexpr float  defVal4 = 0;
  constexpr float  defVal5 = -100000;

  class FRAMSObj {
  public:

    FRAMSObj(
      float Delta_U=defVal2,  float Eta_U=defVal,  float FitScore_U=defVal,  float Alpha_U=defVal3,  float Omega_U=defVal,  float Tau_U=defVal4,  float Iota_U=defVal, float ScoreBDT_U=defVal5,
      float Delta_V=defVal2,  float Eta_V=defVal,  float FitScore_V=defVal,  float Alpha_V=defVal3,  float Omega_V=defVal,  float Tau_V=defVal4,  float Iota_V=defVal, float ScoreBDT_V=defVal5,
      float Delta_C=defVal2,  float Eta_C=defVal,  float FitScore_C=defVal,  float Alpha_C=defVal3,  float Omega_C=defVal,  float Tau_C=defVal4,  float Iota_C=defVal,
      float ScoreBDT_C=defVal5,
      int IsSignal=-1, float Gap=-1, float ProtonKE=-1, float PionKE=-1, float LambdaKE=-1
    );

    float Delta_U;
    float Eta_U;
    float FitScore_U;
    float Alpha_U;
    float Omega_U;
    float Tau_U;
    float Iota_U;
    float ScoreBDT_U;
    float Delta_V;
    float Eta_V;
    float FitScore_V;
    float Alpha_V;
    float Omega_V;
    float Tau_V;
    float Iota_V;
    float ScoreBDT_V;
    float Delta_C;
    float Eta_C;
    float FitScore_C;
    float Alpha_C;
    float Omega_C;
    float Tau_C;
    float Iota_C;
    float ScoreBDT_C;
    int IsSignal;
    float Gap;
    float ProtonKE;
    float PionKE;
    float LambdaKE;

    void FillDataMC(double gap, int issignal, double keproton, double kepion, double kelambda);

    void FillData(int view, double delta, double eta, double fitScore,
                double alpha, double omega, double tau, double iota, double score);

  };

}
#endif
