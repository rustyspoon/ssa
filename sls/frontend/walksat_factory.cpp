#include "walksat_factory.hpp"


namespace sls { namespace frontend {


//namespace wsat {

typedef sls::sat::standard::sat sat;

struct walksat_variable : 
            public sls::properties::truth, 
            public sls::properties::score {};
struct walksat_literal {};
struct walksat_clause : 
            public sls::properties::watcher2<typename sat::variable_type>, 
            public sls::properties::num_true_literals {};
struct walksat_properties
{
    typedef walksat_variable variable_properties_type;
    typedef walksat_literal literal_properties_type;
    typedef walksat_clause clause_properties_type;
};

//}

template<typename State, typename InnerState>
using walksat_facets = sls::facets::facet_compositor<
    State, InnerState,
    sls::facets::truth_facet<State, InnerState>,
    sls::facets::breakcount_facet<State, InnerState>,
    sls::facets::watcher_facet<State, InnerState>,
    sls::facets::unsat_facet<State, InnerState>,
    sls::facets::null_weight_facet<State, InnerState>
>;


DECL_STATE(walksat, sat, walksat_properties, sls::frontend::walksat_facets)


//} /* unnamed */


::sls::solvers::solver_base* const create_walksat_sat_solver(
                                            sls::frontend::problem const& problem,
                                            sls::util::commandline const& cmd)
{
    std::cerr << "c create walksat sat solver" << std::endl;

    return new sls::solvers::gensat<walksat_state>(
                    problem,
                    *(new sls::transitions::default_initializer<walksat_state>()),
                    *(new sls::transitions::default_transitor<walksat_state>()),
                    new sls::selectors::wsat<walksat_state>());
}


} /* frontend */ } /* sls */