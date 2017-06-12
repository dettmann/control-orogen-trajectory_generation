/* Generated from orogen/lib/orogen/templates/tasks/Task.hpp */

#ifndef TRAJECTORY_GENERATION_RMLCARTESIANVELOCITYTASK_TASK_HPP
#define TRAJECTORY_GENERATION_RMLCARTESIANVELOCITYTASK_TASK_HPP

#include "trajectory_generation/RMLCartesianVelocityTaskBase.hpp"

namespace trajectory_generation{

/** Velocity based implementation of a Cartesian RML task. The given target has to have valid velocity entries. */
class RMLCartesianVelocityTask : public RMLCartesianVelocityTaskBase
{
    friend class RMLCartesianVelocityTaskBase;
protected:
    double no_reference_timeout;
    base::Time time_of_last_reference;
    bool convert_to_position;

    /** Perform one step of online trajectory generation (call the RML algorithm with the given parameters). Return the RML result value*/
    virtual ReflexxesResultValue performOTG(RMLInputParameters* new_input_parameters,
                                            RMLOutputParameters* new_output_parameters,
                                            RMLFlags *rml_flag);

    /** Write the generated trajectory to port*/
    virtual void writeCommand(const RMLOutputParameters& new_output_parameters);

    /** Call echo() method for rml input and output parameters*/
    virtual void printParams();

    /** Update the target of a particular joint*/
    virtual void updateTarget(const base::samples::RigidBodyState& cmd,
                              RMLInputParameters* new_input_parameters);

    /** Convert from RMLOutputParameters to orogen type*/
    virtual const ReflexxesOutputParameters& fromRMLTypes(const RMLOutputParameters &in, ReflexxesOutputParameters& out);

public:
    RMLCartesianVelocityTask(std::string const& name = "trajectory_generation::RMLCartesianVelocityTask");
    RMLCartesianVelocityTask(std::string const& name, RTT::ExecutionEngine* engine);
    ~RMLCartesianVelocityTask();
    bool configureHook();
    bool startHook();
    void updateHook();
    void errorHook();
    void stopHook();
    void cleanupHook();
};
}

#endif

