// Class for holding the result of the CRUMBS slice ID

#ifndef sbncode_CRUMBSResult_H
#define sbncode_CRUMBSResult_H

namespace sbn {
  class CRUMBSResult {
  public:

    CRUMBSResult() 
      : score(-5.f)
    {
    }
    
    CRUMBSResult(const float score)
      : score(score)
    {
    }

    float score;
  };
}

#endif
