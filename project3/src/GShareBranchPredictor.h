#ifndef GSHARE_PREDICTOR_H
#define GSHARE_PREDICTOR_H

#include <vector>
#include <stdint.h>

#include "simulator.h"
#include "branch_predictor.h"
#include "branch_predictor_return_value.h"
#include "saturating_predictor.h"

class GShareBranchPredictor : public BranchPredictor {

public:
    GShareBranchPredictor(String name, core_id_t core_id, UInt32 entries, UInt32 b_history);
    ~GShareBranchPredictor();

    bool predict(IntPtr ip, IntPtr target);
    BranchPredictorReturnValue lookup(IntPtr ip, IntPtr target);
    void update(bool predicted, bool actual, IntPtr ip, IntPtr target);

private:
   
    std::vector<SaturatingPredictor<2> > m_predictors;
    UInt32 m_num_entries;
    UInt32 g_history;
    UInt32 h_mask;
};

#endif /* GSHARE_PREDICTOR_H */
