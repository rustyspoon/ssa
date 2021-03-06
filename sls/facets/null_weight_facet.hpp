#ifndef _SLS_FACETS_NULL_WEIGHT_FACET_HPP_
#define _SLS_FACETS_NULL_WEIGHT_FACET_HPP_


#include "facet.hpp"
#include "facet_base.hpp"


namespace sls { namespace facets {


begin_facet(null_weight)
    typedef int weight_type;

    inline weight_type weight(clause_type clause) const
    {
        return weight_type(1);
    }

    inline void inc_weight(clause_type clause) {}
    inline void dec_weight(clause_type clause) {}
    inline void inc_weight(clause_type clause, weight_type increment) {}
    inline void dec_weight(clause_type clause, weight_type decrement) {}
end_facet


} /* facets */ } /* sls */


#endif