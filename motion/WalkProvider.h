
#ifndef _WalkProvider_h_DEFINED
#define _WalkProvider_h_DEFINED

/**
 * The walk provider is the central connection point between all the parts
 * of the walking system. It ties together the controller, and inverse
 * kinematics.
 *
 * The walk provider should be asked to calculateNextJoints each timestep
 * It in turn asks for a new CoM target from the controller, and supervises
 * the left and right `WalkingLegs` in reaching that target.
 *
 * At the end, it updates the super class' joints for each leg chain
 * which are read by the switchboard.
 */

#include <vector>
using namespace std;

#include <boost/tuple/tuple.hpp>


#include "MotionProvider.h"
#include "WalkingConstants.h"
#include "StepGenerator.h"

typedef boost::tuple<const vector<float>,const vector<float> > WalkLegsTuple;

//NOTE: we need to get passed a reference to the switchboard so we can
//know the length of a motion frame!!
class WalkProvider : public MotionProvider {
public:
    WalkProvider(Sensors *s);
    virtual ~WalkProvider();

    void requestStop();
    void calculateNextJoints();
    void setMotion(const float x, const float y, const float theta);

    vector<float> getWalkStance();

private:
    virtual void setActive();

    Sensors *sensors;

    WalkingParameters walkParameters;
    StepGenerator stepGenerator;

    //Temp solution to arms
    vector<float> rarm_angles, larm_angles;
};

#endif

