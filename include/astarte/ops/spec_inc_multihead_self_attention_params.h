#ifndef _ASTARTE_SPEC_INC_MULTIHEAD_SELF_ATTENTION_PARAMS_H
#define _ASTARTE_SPEC_INC_MULTIHEAD_SELF_ATTENTION_PARAMS_H

#include "astarte/caconst.h"
#include "astarte/catype.h"
#include "astarte/parallel_tensor.h"

namespace astarte {

struct SpecIncMultiHeadSelfAttentionParams {
    LayerID layer_guid;
    int embed_dim, num_q_heads, num_kv_heads, kdim, vdim;
    float dropout, scaling_factor;
    bool qkv_bias, final_bias, add_zero_attn, apply_rotary_embedding,
        scaling_query, qk_prod_scaling, position_bias;

    bool is_valid(ParallelTensorShape const &) const;
};

bool operator==(SpecIncMultiHeadSelfAttentionParams const &
                SpecIncMultiHeadSelfAttentionParams const &);
} // namespace astarte

namespace std {
template <>
struct hash<astarte::SpecIncMultiHeadSelfAttentionParams> {
    size_t
        operator()(astarte::SpecIncMultiHeadSelfAttentionParams const &) const;
};
} // namespace std

#endif // _ASTARTE_SPEC_INC_MULTIHEAD_SELF_ATTENTION_PARAMS_H