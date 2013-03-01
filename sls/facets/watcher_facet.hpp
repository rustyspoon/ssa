#ifndef _SLS_FACETS_WATCHER_FACET_HPP_
#define _SLS_FACETS_WATCHER_FACET_HPP_


#include <vector>
#include <algorithm>
#include "facet.hpp"
#include "facet_base.hpp"


namespace sls { namespace facets {


facet_begin(watcher)
    facet_constr(watcher)

    void reset(std::vector<clause_type> const& clauses, size_t variable_count)
    {
        std::for_each(inner_state_.clause_properties_begin(), inner_state_.clause_properties_end(), 
        	[](clause_properties_type& prop){ 
        		prop.watcher1 = sat_type::variable_type::null();
        		prop.watcher2 = sat_type::variable_type::null(); });
    }

    inline variable_type watcher1(clause_type clause) const
    {
        return inner_state_[clause].watcher1;
    }

    inline void watcher1(clause_type clause, variable_type variable)
    {
        inner_state_[clause].watcher1 = variable;
    }

    inline variable_type watcher2(clause_type clause) const
    {
        return inner_state_[clause].watcher2;
    }

    inline void watcher2(clause_type clause, variable_type variable)
    {
        inner_state_[clause].watcher2 = variable;
    }
};


} /* facets */ } /* sls */


#endif