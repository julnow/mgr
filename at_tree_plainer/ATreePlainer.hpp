#ifndef ATREEPLAINER_HPP
#define ATREEPLAINER_HPP

#include "AnalysisTree/Cuts.hpp"
#include "AnalysisTree/Detector.hpp"
#include "AnalysisTree/Task.hpp"

class ATreePlainer : public AnalysisTree::Task {
 public:
  explicit ATreePlainer() = default;
  ~ATreePlainer() override = default;

  void Init() override;
  void Exec() override;
  void Finish() override {};

  void InitIndices();

  // void SetCuts(AnalysisTree::Cuts* cuts) { cuts_ = cuts; }


protected:

  // input branches
  AnalysisTree::Particles* simulated_{nullptr};
  AnalysisTree::Detector<AnalysisTree::Hit>* tofhits_{nullptr};
  AnalysisTree::Detector<AnalysisTree::Track>*  vtxtracks_{nullptr};
  AnalysisTree::Detector<AnalysisTree::Track>*  trdtracks_{nullptr};
  // AnalysisTree::Detector<AnalysisTree::Hit>*  richrings_{nullptr};
  AnalysisTree::Matching* tof2sim_match_{nullptr};
  AnalysisTree::Matching* vtx2tof_match_{nullptr};
  AnalysisTree::Matching* vtx2trd_match_{nullptr};

  // output branch
  AnalysisTree::Particles* plain_branch_{nullptr};

  // AnalysisTree::Cuts* cuts_{nullptr};

  // static constexpr float lambda_mass = 1.115683;
  // static constexpr float lambda_mass_sigma = 1.5e-3;

  //**** input fields ***********
  //tof variables
  int mass2_id_tof_{AnalysisTree::UndefValueInt};
  int m_id_sim_{AnalysisTree::UndefValueInt};
  //vtx variables
  int q_id_vtx_{AnalysisTree::UndefValueInt};
  int chi2_id_vtx_{AnalysisTree::UndefValueInt};

  //trd variables
  int pe_id_trd_{AnalysisTree::UndefValueInt}; //probablilites
  int ppi_id_trd_{AnalysisTree::UndefValueInt};
  int pk_id_trd_{AnalysisTree::UndefValueInt};
  int pp_id_trd_{AnalysisTree::UndefValueInt};
  int nhits_id_trd_{AnalysisTree::UndefValueInt};
  //

  //*****************************

  //***** output fields *********
  // int l_id_w1_{AnalysisTree::UndefValueInt};
  int mass2_id_w1_{AnalysisTree::UndefValueInt};
  // int t_id_w1_{AnalysisTree::UndefValueInt};
  int q_id_w1_{AnalysisTree::UndefValueInt};
  int chi2_vtx_id_w1_{AnalysisTree::UndefValueInt};
  int pe_id_w1_{AnalysisTree::UndefValueInt}; 
  int ppi_id_w1_{AnalysisTree::UndefValueInt};
  int pk_id_w1_{AnalysisTree::UndefValueInt};
  int pp_id_w1_{AnalysisTree::UndefValueInt};
  int nhits_trd_id_w1_{AnalysisTree::UndefValueInt};



  //******************************

};
#endif // ATREEPLAINER_HPP
